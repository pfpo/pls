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

class Predicate(Term):
    def __init__(self,name,arity):
        super().__init__(name)
        self.arity : int = arity
        self.definitions: list[types.Position] = []


class Functor(Term):
    def __init__(self,name,args):
        super().__init__(name)
        self.args: list= args

class Operator(Term):
    def __init__(self,operator:str,operands:list[Term]):
        super().__init__(operator)
        self.operands = operands


class PLS(LanguageServer):
    """Language server demonstrating "push-model" diagnostics."""

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.diagnostics = {}
        self.visit_map  = {}
        self.predicates = []
        self.trees = {}

    def add_visit(self,node_type:str,f):
        self.visit_map[node_type] = f
    
    def visit(self,node:Node):
        if node.type in self.visit_map:
            return self.visit_map[node.type](node)
        raise TypeError(f"There is no registered visitor for: {node.type}\n{node}")

    def parse(self, document: TextDocument):

        self.predicates = []
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
                return Functor(name,args)
            case x:
                raise TypeError(f"Invalid shape of argument list: {x}")
        return

    def visit_variable_term(self,node:Node):
        assert node.type == 'variable_term'
        return self.text_visit(node)

    def visit_operator_notation(self,node:Node):
        assert node.type == 'operator_notation'
        print(node)
        print(node.children)    
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
        predicate.definitions.append(parent.start_point)
        self.predicates.append(predicate)
        return
    def visit_directive(self,node:Node):
        print(node)
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


server = PLS("diagnostic-server", "v1")


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

@server.feature(types.TEXT_DOCUMENT_TYPE_DEFINITION)
def goto_type_definition(ls:PLS, params: types.TypeDefinitionParams):
    """Jump to an object's type definition."""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    index = ls.index.get(doc.uri)
    if index is None:
        return

    try:
        line = doc.lines[params.position.line]
    except IndexError:
        line = ""

    word = doc.word_at_position(params.position)

    # for match in ARGUMENT.finditer(line):
    #     if match.group("name") == word:
    #         if (range_ := index["types"].get(match.group("type"), None)) is not None:
    #             return types.Location(uri=doc.uri, range=range_)


@server.feature(types.TEXT_DOCUMENT_DEFINITION)
def goto_definition(ls:PLS, params: types.DefinitionParams):
    """Jump to an object's definition."""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    tree = ls.trees.get(doc.uri)
    if tree is None:
        return


    word = doc.word_at_position(params.position)

    # Is word a type?
    # if (range_ := index["types"].get(word, None)) is not None:
    #     return types.Location(uri=doc.uri, range=range_)

def node_at_position(node:Node,p : types.Position):
    after_start = (node.start_point.column <= p.character and node.start_point.row <= p.line) 
    before_end = (node.end_point.column >= p.character and node.end_point.row >= p.line)
    contained = after_start and before_end
    if not contained:
        return None
    current = node
    for child in node.children:
        possible = node_at_position(child,p)
        if possible:
            current = possible
    return current
    


@server.feature(types.TEXT_DOCUMENT_DECLARATION)
def goto_declaration(ls:PLS, params: types.DeclarationParams):
    """Jump to an object's declaration."""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    index = ls.index.get(doc.uri)
    if index is None:
        return

    try:
        line = doc.lines[params.position.line]
    except IndexError:
        line = ""

    word = doc.word_at_position(params.position)

    # for match in ARGUMENT.finditer(line):
    #     if match.group("name") == word:
    #         linum = params.position.line
    #         return types.Location(
    #             uri=doc.uri,
    #             range=types.Range(
    #                 start=types.Position(line=linum, character=match.start()),
    #                 end=types.Position(line=linum, character=match.end()),
    #             ),
    #         )


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
    ]

def main():
    logging.basicConfig(filename='pygls.log', filemode='w', level=logging.DEBUG)
    server.start_io()
if __name__ == "__main__":
    # main()
    s = open("teste.pl").read()
    t : Tree = parser.parse(bytes(s,"utf-8"))
    print(t.root_node)
    server._parse(s)
    