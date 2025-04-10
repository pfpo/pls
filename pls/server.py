from pygls.server import LanguageServer
from lsprotocol import types
from pygls.workspace import TextDocument
# from pygls.cli import start_server

from tree_sitter import Language, Parser,Node,Tree
from tree_sitter_prolog import prolog

from .model import Functor,Operator,Predicate,Term
from .utils import node_at_position, node_to_range

from .prolog_visitor import PrologVisitor
from .syntax_error_visitor import SyntaxErrorVisitor

import logging

PROLOG = Language(prolog())

parser = Parser(PROLOG)



class PLS(LanguageServer):
    """Language server demonstrating "push-model" diagnostics."""

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.diagnostics = {}
        self.predicate_index = {}
        self.trees = {}
        self.current_uri = ""

    
    def parse(self, document: TextDocument):

        self.predicate_index = {}
        self.current_uri = document.uri
        tree = self._parse(document.source)

        syntax_error_visitor = SyntaxErrorVisitor()
        diagnostics = syntax_error_visitor.visit(tree.root_node)

        self.diagnostics[document.uri] = (document.version, diagnostics)
        self.trees[document.uri] = tree
        logging.info("%s", self.diagnostics)


    def _parse(self, doc:str):

        tree = parser.parse(bytes(doc,"utf-8"))

        prolog_visitor  = PrologVisitor(self.current_uri)
        prolog_visitor.visit(tree.root_node)
        self.predicate_index = prolog_visitor.predicate_index


        return tree
    def go_to_definition(self,tree,position:types.Position):
        print(position)
        node = node_at_position(tree.root_node,position) 
        if node is None:
            print("Didn't found any node")
            return None
        print(position)
        print(f"Node: {node}")
        print("Node: {node.text}")
        print(f"{node.start_point,node.end_point}")
        if node.parent.type == "functional_notation" and node.parent.children[0] == node:
            functor = PrologVisitor("").visit(node.parent)
            predicates = self.search(functor)
            if predicates is None:
                return None
            return types.Location(uri=predicates[0].uri,range=predicates[0].definitions[0])
        else:
            functor = Functor(bytes.decode(node.text),[])
            predicates = self.search(functor)
            if predicates is None:
                return None
            return types.Location(uri=predicates[0].uri,range=predicates[0].definitions[0])
    def search(self,functor:Functor):
        return self.predicate_index.get(functor.key())


server = PLS("prolog-server", "v0.0.1")


@server.feature(types.TEXT_DOCUMENT_DID_OPEN)
def did_open(ls: PLS, params: types.DidOpenTextDocumentParams):
    """Parse each document when it is opened"""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    ls.parse(doc)

    for uri, (version, diagnostics) in ls.diagnostics.items():
        ls.publish_diagnostics(uri,diagnostics)


@server.feature(types.TEXT_DOCUMENT_DID_CHANGE)
def did_change(ls: PLS, params: types.DidOpenTextDocumentParams):
    """Parse each document when it is changed"""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    ls.parse(doc)

    for uri, (version, diagnostics) in ls.diagnostics.items():
        ls.publish_diagnostics(uri,diagnostics)


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
    s = open("./examples/go_to_definition.pl").read()
    t : Tree = parser.parse(bytes(s,"utf-8"))
    print(f"{t.root_node}")
    server._parse(s)
    print(server.go_to_definition(t,types.Position(character=23,line=6)))
    

if __name__ == "__main__":
    if True:
        print = logging.debug
        main()
    else:
        debug()