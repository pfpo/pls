from pygls.server import LanguageServer
from lsprotocol import types
# from pygls.cli import start_server
from pygls.workspace import TextDocument

import logging
import re

from lsprotocol import types

from tree_sitter import Language, Parser,Node,Tree
from tree_sitter_prolog import prolog

PROLOG = Language(prolog())

parser = Parser(PROLOG)

def node_to_range(node:Node):

    return types.Range(
                            start=types.Position(line=node.start_point.row,character=node.start_point.column),
                            end=types.Position(line=node.end_point.row,character=node.end_point.column),
                        )
class Term:
    def __init__(self,name):
        self.name : str = name
        self.arity = 0
    def key(self)-> str:
        return f"{self.name}/{self.arity}"

class Predicate(Term):
    def __init__(self,name,arity):
        super().__init__(name)
        self.arity : int = arity
        self.definitions: list[types.Range] = []
        self.uri = ""


class Functor(Term):
    def __init__(self,name,args):
        super().__init__(name)
        self.args: list= args
        self.arity = len(args)


class Operator(Term):
    def __init__(self,operator:str,operands:list[Term]):
        super().__init__(operator)
        self.operands = operands
        self.arity = len(operands)


class PLS(LanguageServer):
    """Language server demonstrating "push-model" diagnostics."""

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.diagnostics = {}
        self.predicate_index = {}
        self.trees = {}
        self.visit_map  = {}
        self.current_uri = ""
        self.build_visitors()

    def add_visit(self,node_type:str,f):
        self.visit_map[node_type] = f
    
    def visit(self,node:Node):
        if node.type in self.visit_map:
            return self.visit_map[node.type](node)
        raise TypeError(f"There is no registered visitor for: {node.type}\n{node}")

    def build_visitors(self):

        self.add_visit('clause_term',self.visit_clause_term)
        self.add_visit('directive_term',self.visit_directive)
        self.add_visit('atom',self.visit_atom)
        self.add_visit('functional_notation',self.visit_functional_notation)
        self.add_visit('operator_notation',self.visit_operator_notation)
        self.add_visit('integer',self.text_visit)
        self.add_visit('variable_term',self.visit_variable_term)
    
    def parse(self, document: TextDocument):

        self.predicate_index = {}
        self.current_uri = document.uri
        tree = self._parse(document.source)

        diagnostics = self.visit_errors(tree)
        self.diagnostics[document.uri] = (document.version, diagnostics)
        self.trees[document.uri] = tree
        logging.info("%s", self.diagnostics)

    def visit_errors(self,tree:Tree):
        severity = types.DiagnosticSeverity.Error
        diagnostics = []
        may_contain_errors :list[Node] = [tree.root_node]
        while len(may_contain_errors) > 0:
            node = may_contain_errors.pop()
            if node.is_error:
                message = "Syntax Error"
                diagnostics.append(
                    types.Diagnostic(
                        message=message,
                        severity=severity,
                        range= node_to_range(node))
                )
            elif node.is_missing:
                message = "Syntax Error"
                diagnostics.append(
                    types.Diagnostic(
                        message=message,
                        severity=severity,
                        range= node_to_range(node))
                )
            elif node.has_error:
                for child in node.children:
                    may_contain_errors.append(child)
        return diagnostics

    def visit_atom(self,node:Node)-> str:
        assert node.type == 'atom'
        return Term(bytes.decode(node.text,"utf-8"))

    def text_visit(self,node:Node)-> str:
        return Term(bytes.decode(node.text,"utf-8"))
    def visit_arg_list(self,node:Node):
        assert node.type == 'arg_list'
        args= []
        for i in range(len(node.children)):
            if i % 2 == 0:
                args.append(node.children[i])
            else:
                assert node.children[i].type =='arg_list_separator'
        parsed_args = []
        for arg in args:
            parsed_args.append(self.visit(arg))
        return parsed_args

    def visit_functional_notation(self,node:Node):
        assert node.type =='functional_notation'
        match node.children:
            case [atom,_,arg_list,_]:
                name = self.visit_atom(atom)
                args = self.visit_arg_list(arg_list)
                return Functor(name.name,args)
            case x:
                raise TypeError(f"Invalid shape of argument list: {x}")
        return

    def visit_variable_term(self,node:Node):
        assert node.type == 'variable_term'
        return self.text_visit(node)

    def visit_operator_notation(self,node:Node):
        assert node.type == 'operator_notation'
        match node.children:
            case [head,op,body]:
                head = self.visit(head)
                body = self.visit(body)
                return head
            case x:
                raise TypeError(f"Unhandeled operator notation:{x}")
    def visit_clause_term(self,parent:Node):
        node= parent.children[0]

        f = self.visit(node)
        arity = 0
        if type(f) == Functor:
            arity = len(f.args)
        predicate = Predicate(f.name,arity)
        predicate.definitions.append(node_to_range(parent))
        predicate.uri = self.current_uri
        key = predicate.key()
        if key in self.predicate_index:
            # TODO: check definition location
            self.predicate_index[key].append(predicate)
        else:
            self.predicate_index[key] = [predicate]
        return
    def visit_directive(self,node:Node):
        return
    def _parse(self, doc:str):

        tree = parser.parse(bytes(doc,"utf-8"))

        self.add_visit('clause_term',self.visit_clause_term)
        self.add_visit('directive_term',self.visit_directive)
        self.add_visit('atom',self.visit_atom)
        self.add_visit('functional_notation',self.visit_functional_notation)
        self.add_visit('operator_notation',self.visit_operator_notation)
        self.add_visit('integer',self.text_visit)
        self.add_visit('variable_term',self.visit_variable_term)

        for child in tree.root_node.children:
            self.visit(child)

        return tree
    def go_to_definition(self,tree,position:types.Position):
        logging.debug(position)
        node = node_at_position(tree.root_node,position) 
        if node is None:
            logging.debug("Didn't found any node")
            return None
        print(position)
        print("Node: ",node)
        print("Node: ",node.text)
        print(node.start_point,node.end_point)
        if node.parent.type == "functional_notation" and node.parent.children[0] == node:
            functor = self.visit(node.parent)
            predicates = self.search(functor)
            if predicates is None:
                return None

            return types.Location(uri=predicates[0].uri,range=predicates[0].definitions[0])
    def search(self,functor:Functor):
        return self.predicate_index.get(functor.key())


server = PLS("diagnostic-server", "v1")

print = logging.debug

@server.feature(types.TEXT_DOCUMENT_DID_OPEN)
def did_open(ls: PLS, params: types.DidOpenTextDocumentParams):
    """Parse each document when it is opened"""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    ls.parse(doc)

    for uri, (version, diagnostics) in ls.diagnostics.items():
        ls.publish_diagnostics(uri,diagnostics)
        # ls.text_document_publish_diagnostics(
        #     types.PublishDiagnosticsParams(
        #         uri=uri,
        #         version=version,
        #         diagnostics=diagnostics,
        #     )
        # )


@server.feature(types.TEXT_DOCUMENT_DID_CHANGE)
def did_change(ls: PLS, params: types.DidOpenTextDocumentParams):
    """Parse each document when it is changed"""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    ls.parse(doc)

    for uri, (version, diagnostics) in ls.diagnostics.items():
        ls.publish_diagnostics(uri,diagnostics)
        # ls.text_document_publish_diagnostics(
        #     types.PublishDiagnosticsParams(
        #         uri=uri,
        #         version=version,
        #         diagnostics=diagnostics,
        #     )
        # )


@server.feature('textDocument/definition')
def goto_definition(ls:PLS, params: types.DefinitionParams):
    """Jump to an object's definition."""
    logging.log(logging.DEBUG,"Hellooooo\n\n\n")
    doc = ls.workspace.get_text_document(params.text_document.uri)
    tree = ls.trees.get(doc.uri)
    logging.log(logging.DEBUG,str(params.position))
    if tree is None:
        return []
    result = ls.go_to_definition(tree,params.position)
    logging.log(logging.DEBUG,result)
    return result



def node_at_position(node:Node,p : types.Position):
    in_row_between = node.start_point.row < p.line and node.end_point.row > p.line
    in_first_line = node.start_point.row == p.line and node.start_point.column <= p.character
    in_last_line = node.end_point.row == p.line and node.end_point.column >= p.character
    if (node.start_point.row == node.end_point.row and node.start_point.row== p.line) and not (node.start_point.column <= p.character and node.end_point.column >= p.character):
        return None
    contained = in_row_between or in_first_line or in_last_line
    if not contained:
        return None
    current = node
    for child in node.children:
        possible = node_at_position(child,p)
        if possible:
            current = possible
    return current
    



@server.feature(
    types.TEXT_DOCUMENT_COMPLETION,
    types.CompletionOptions(trigger_characters=["."]),
)
def completions(params: types.CompletionParams):
    document = server.workspace.get_document(params.text_document.uri)
    current_line = document.lines[params.position.line].strip()

    if not current_line.endswith("wario."):
        return []

    return [
        types.CompletionItem(label="prolog"),
        types.CompletionItem(label="world"),
        types.CompletionItem(label="friend"),
        types.CompletionItem(label="Elsa"),
    ]

def main():
    logging.basicConfig(filename='/home/martim/Desktop/pls/pygls.log', filemode='w', level=logging.DEBUG)
    server.start_io()
def debug():
    s = open("teste.pl").read()
    t : Tree = parser.parse(bytes(s,"utf-8"))
    print(t.root_node)
    server._parse(s)
    server.go_to_definition(t,types.Position(character=19,line=3))

if __name__ == "__main__":
    if True:
        main()
    else:
        debug()