from pygls.server import LanguageServer
from lsprotocol import types
from pygls.workspace import TextDocument
# from pygls.cli import start_server

from tree_sitter import Language, Parser, Tree, Node
from tree_sitter_prolog import prolog

from .model import Functor, Variable, Predicate, SymbolTable
from .utils import node_at_position, position_inside_node

from .prolog_visitor import PrologVisitor, Opts
from .syntax_error_visitor import SyntaxErrorVisitor
from .highlight import HighlightVisitor, TokenTypes, TokenModifier
from .markup import descriptions
import sys
from .my_logging import print,logging,old_print

PROLOG = Language(prolog())

parser = Parser(PROLOG)


class PLS(LanguageServer):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.diagnostics = {}
        self.tokens = {}
        self.tables: map[str, SymbolTable] = {}
        self.trees: map[str, Tree] = {}
        self.current_uri = ""

    def tree_diagnostics(self, tree: Tree):
        syntax_error_visitor = SyntaxErrorVisitor()
        return syntax_error_visitor.visit(tree.root_node)

    def semantic_tokens(self, tree: Tree, uri: str):
        tokens_visitor = HighlightVisitor(self.tables[uri])
        tokens_visitor.visit(tree.root_node)
        return tokens_visitor.token_list

    def parse(self, document: TextDocument):
        self.predicate_index = {}
        self.current_uri = document.uri
        tree, symbol_table = self._parse(document.source)

        self.tables[document.uri] = symbol_table
        self.diagnostics[document.uri] = (document.version, self.tree_diagnostics(tree))
        self.tokens[document.uri] = (
            document.version,
            self.semantic_tokens(tree, document.uri),
        )
        self.trees[document.uri] = tree

        logging.info("%s", self.diagnostics)

    def _parse(self, doc: str):
        tree = parser.parse(bytes(doc, "utf-8"))

        prolog_visitor = PrologVisitor(self.current_uri)
        prolog_visitor.visit(tree.root_node, Opts())
        symbol_table = SymbolTable(
            scopes=prolog_visitor.scopes,
            notes=prolog_visitor.notes,
            predicate_index=prolog_visitor.predicate_index,
        )

        return tree, symbol_table

    def transform_in_variable_or_predicate(
        self, node: Node, position: types.Position, uri: str
    ) -> Variable | Predicate | None:
        if node is None:
            return None
        table = self.tables[uri]
        if node.type == "variable_term":
            scopes = table.scopes
            for _key, scope in scopes.items():
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
                functor = p.visit(node.parent, Opts())
            else:
                functor = Functor(bytes.decode(node.text), [])

            return table.predicate_index.get(functor.key())

    def discover_node(
        self, tree, position: types.Position, uri: str
    ) -> Variable | Predicate | None:
        node = node_at_position(tree.root_node, position)
        print(node)
        return self.transform_in_variable_or_predicate(node, position, uri)

    def go_to_definition(self, tree, position: types.Position, uri: str):
        element: Variable | Predicate | None = self.discover_node(tree, position, uri)

        if type(element) is Variable:
            return types.Location(uri=uri, range=element.references[0])
        elif type(element) is Predicate:
            return types.Location(uri=uri, range=element.definitions[0])
        elif element is None:
            return None
        return None

    def find_references(self, tree, position: types.Position, uri: str):
        element: Variable | Predicate | None = self.discover_node(tree, position, uri)
        print(element)

        locations = []
        if element is None:
            return locations

        for reference in element.references:
            locations.append(types.Location(uri=uri, range=reference))

        return locations

    def hover(self, tree, position: types.Position, uri: str):
        maybe_node = node_at_position(tree.root_node, position)
        if maybe_node is None:
            return None
        element = self.transform_in_variable_or_predicate(maybe_node, position, uri)
        if element is not None and type(element) is Variable:
            content = descriptions.variable_description(element)
        elif element is not None and type(element) is Predicate:
            content = descriptions.predicate_description(element)
        else:
            content = descriptions.node_description(maybe_node)

        return types.Hover(
            contents=types.MarkupContent(
                kind=types.MarkupKind.Markdown,
                value="\n".join(content),
            ),
            range=types.Range(
                start=types.Position(line=position.line, character=0),
                end=types.Position(line=position.line + 1, character=0),
            ),
        )


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
    doc = ls.workspace.get_text_document(params.text_document.uri)
    tree = ls.trees.get(doc.uri)
    if tree is None:
        return []
    result = ls.go_to_definition(tree, params.position, doc.uri)
    return result


@server.feature(types.TEXT_DOCUMENT_REFERENCES)
def find_references(ls: PLS, params: types.ReferenceParams):
    """Find references of an object."""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    tree = ls.trees.get(doc.uri)
    logging.log(logging.DEBUG, str(params.position))
    if tree is None:
        return []
    references = ls.find_references(tree, params.position, doc.uri)
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
    res = types.SemanticTokens(data=tokens)
    return res


@server.feature(types.TEXT_DOCUMENT_HOVER)
def hover(ls: PLS, params: types.HoverParams):
    doc = ls.workspace.get_text_document(params.text_document.uri)
    tree = ls.trees.get(doc.uri)
    if tree is None:
        return []
    result = ls.hover(tree, params.position, doc.uri)
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
    logging.basicConfig(
        filename="/home/martim/Desktop/pls/pygls.log", filemode="w", level=logging.DEBUG
    )
    server.start_io()

def rec_print(node:Node,tab=0):
    log = lambda n : f"{bytes.decode(n.text,'utf-8')}"
    print(f"{'  ' * tab}{node.type} - {log(node)}")
    for child in node.children:
        rec_print(child,tab+1)

def debug():
    class MyDoc:
        def __init__(self,uri:str):
            self.uri = uri
            self.source = ""
            self.version = 0
            with open(self.uri) as f:
                self.source = f.read()

    uri = "./examples/highlight/comment.pl"
    uri = "./test/t.pl"
    doc = MyDoc(uri)
    server.parse(doc)
    t = server.trees[uri]
    for child in t.root_node.children:
        rec_print(child,0)
    print(t.root_node)
    
    for key, predicate in server.tables[uri].predicate_index.items():
        print(key)
        print(f"Defs {len(predicate.definitions)}{predicate.definitions}")
        print(f"Refs {len(predicate.references)}{predicate.references}")
        print("========")

    #print(
    #    f"Definition: {server.go_to_definition(t, types.Position(character=13, line=13),uri)}"
    #)
    print(f"Diagnostics:{server.tree_diagnostics(t)}")
    print(server.semantic_tokens(t,uri))
    


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "-d":
        print = old_print
        debug()
    else:
        print = logging.debug
        main()


#import tree_sitter_prolog as pl
#import tree_sitter as ts
#l = ts.Language(pl.prolog())
#p = ts.Parser(l)
#t = p.parse(bytes(open("test/custom_op.pl").read(),"utf-8"))
#print(t.root_node)
#t = p.parse(bytes(open("test/custom_op.pl").read(),"utf-8"))
#print(t.root_node)