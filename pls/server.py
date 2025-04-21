from pygls.server import LanguageServer
from lsprotocol import types
from pygls.workspace import TextDocument
# from pygls.cli import start_server

from tree_sitter import Language, Parser, Tree
from tree_sitter_prolog import prolog

from .model import Functor, Variable, Predicate
from .utils import node_at_position, position_inside_node

from .prolog_visitor import PrologVisitor
from .syntax_error_visitor import SyntaxErrorVisitor
from .highlight import HighlightVisitor, TokenTypes, TokenModifier

import logging

PROLOG = Language(prolog())

parser = Parser(PROLOG)


class PLS(LanguageServer):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.diagnostics = {}
        self.tokens = {}
        self.predicate_index = {}
        self.scopes = {}
        self.notes = {}
        self.trees = {}
        self.current_uri = ""

    def tree_diagnostics(self, tree: Tree):
        syntax_error_visitor = SyntaxErrorVisitor()
        return syntax_error_visitor.visit(tree.root_node)

    def semantic_tokens(self, tree: Tree):
        tokens_visitor = HighlightVisitor(self.notes)
        tokens_visitor.visit(tree.root_node)
        return tokens_visitor.token_list

    def parse(self, document: TextDocument):
        self.predicate_index = {}
        self.current_uri = document.uri
        tree = self._parse(document.source)

        self.diagnostics[document.uri] = (document.version, self.tree_diagnostics(tree))
        print(tree)
        print("Calculating Semantic Tokens:")
        self.tokens[document.uri] = (document.version, self.semantic_tokens(tree))
        self.trees[document.uri] = tree

        logging.info("%s", self.diagnostics)

    def _parse(self, doc: str):
        tree = parser.parse(bytes(doc, "utf-8"))

        prolog_visitor = PrologVisitor(self.current_uri)
        prolog_visitor.visit(tree.root_node)
        self.predicate_index = prolog_visitor.predicate_index
        self.scopes = prolog_visitor.scopes
        self.notes = prolog_visitor.notes

        return tree

    def discover_node(self, tree, position: types.Position) -> Variable | Predicate:
        node = node_at_position(tree.root_node, position)
        if node is None:
            return None
        if node.type == "variable_term":
            for _key, scope in self.scopes.items():
                if position_inside_node(scope.node, position):
                    return scope.variables[bytes.decode(node.text, "utf-8")]
        else:
            functor = None
            if (
                node.parent
                and node.parent.type == "functional_notation"
                and node.parent.children[0] == node
            ):
                p = PrologVisitor("")
                p.new_scope(node.parent)
                functor = p.visit(node.parent)
            else:
                functor = Functor(bytes.decode(node.text), [])

            return self.search(functor)

    def go_to_definition(self, tree, position: types.Position):
        element: Variable | Predicate | None = self.discover_node(tree, position)

        if type(element) is Variable:
            return types.Location(uri=self.current_uri, range=element.references[0])
        elif type(element) is Predicate:
            return types.Location(uri=self.current_uri, range=element.definitions[0])
        elif element is None:
            return None
        return None

    def find_references(self, tree, position: types.Position):
        element: Variable | Predicate | None = self.discover_node(tree, position)

        locations = []
        if element is None:
            return locations

        for reference in element.references:
            locations.append(types.Location(uri=self.current_uri, range=reference))

        return locations

    def search(self, functor: Functor):
        return self.predicate_index.get(functor.key())


server = PLS("prolog-server", "v0.0.1")


@server.feature(types.TEXT_DOCUMENT_DID_OPEN)
def did_open(ls: PLS, params: types.DidOpenTextDocumentParams):
    """Parse each document when it is opened"""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    ls.parse(doc)

    for uri, (version, diagnostics) in ls.diagnostics.items():
        ls.publish_diagnostics(uri, diagnostics)


@server.feature(types.TEXT_DOCUMENT_DID_CHANGE)
def did_change(ls: PLS, params: types.DidOpenTextDocumentParams):
    """Parse each document when it is changed"""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    ls.parse(doc)

    for uri, (version, diagnostics) in ls.diagnostics.items():
        ls.publish_diagnostics(uri, diagnostics)


@server.feature("textDocument/definition")
def goto_definition(ls: PLS, params: types.DefinitionParams):
    """Jump to an object's definition."""
    logging.log(logging.DEBUG, "Hellooooo\n\n\n")
    doc = ls.workspace.get_text_document(params.text_document.uri)
    tree = ls.trees.get(doc.uri)
    logging.log(logging.DEBUG, str(params.position))
    if tree is None:
        return []
    result = ls.go_to_definition(tree, params.position)
    logging.log(logging.DEBUG, result)
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


@server.feature(types.TEXT_DOCUMENT_REFERENCES)
def find_references(ls: PLS, params: types.ReferenceParams):
    """Find references of an object."""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    tree = ls.trees.get(doc.uri)
    logging.log(logging.DEBUG, str(params.position))
    if tree is None:
        return []
    references = ls.find_references(tree, params.position)
    logging.log(logging.DEBUG, references)

    return references


@server.feature(
    types.TEXT_DOCUMENT_SEMANTIC_TOKENS_FULL,
    types.SemanticTokensLegend(
        token_types=TokenTypes,
        token_modifiers=[m.name for m in TokenModifier],
    ),
)
def semantic_tokens_full(ls: PLS, params: types.SemanticTokensParams):
    """Return the semantic tokens for the entire document"""
    ver_sion, tokens = ls.tokens.get(params.text_document.uri, (0, []))
    print(tokens)
    res = types.SemanticTokens(data=tokens)
    return res


def main():
    logging.basicConfig(
        filename="/home/martim/Desktop/pls/pygls.log", filemode="w", level=logging.DEBUG
    )
    server.start_io()


def debug():
    s = open("./examples/highlight/strings.pl").read()
    t: Tree = parser.parse(bytes(s, "utf-8"))
    print(f"{t.root_node}")
    server._parse(s)
    for key, predicate in server.predicate_index.items():
        print(key)
        print(predicate.definitions)
        print(predicate.references)
        print("========")
    print(server.predicate_index)

    print(server.go_to_definition(t, types.Position(character=10, line=9)))
    print(server.tree_diagnostics(t))
    print(server.semantic_tokens(t))


if __name__ == "__main__":
    if True:
        print = logging.debug
        main()
    else:
        debug()
