from pygls.server import LanguageServer
from lsprotocol import types
from pygls.workspace import TextDocument
import traceback
# from pygls.cli import start_server

from tree_sitter import Language, Parser, Tree, Node
from tree_sitter_prolog import prolog

from .model import Functor, Variable, Predicate, SymbolTable
from .utils import (
    node_at_position,
    position_inside_node,
    path_to_file_uri,
    file_uri_to_path,
    Path,
    add_paths,
)

from .prolog_visitor import PrologVisitor, Opts
from .syntax_error_visitor import SyntaxErrorVisitor
from .highlight.highlight_visitor import HighlightVisitor
from .highlight.highlight import TokenModifier, TokenTypes
from .markup import descriptions
from .passes.unused_variable import UnusedVariablePass
from .passes.undefined_predicate import UndefinedPredicate
from .passes.consults import ConsultPaths
from .dependency_graph import DependencyGraph,DependencyGraphManager
from .my_logging import logging


PROLOG = Language(prolog())

parser = Parser(PROLOG)


class MyDoc:
    def __init__(self, uri: str):
        self.uri = uri
        self.filename = ""
        self.source = ""
        self.version = 0
        with open(file_uri_to_path(self.uri)) as f:
            self.source = f.read()


class PLS(LanguageServer):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.diagnostics = {}
        self.tokens = {}
        self.tables: map[str, SymbolTable] = {}
        self.dg = DependencyGraphManager()
        self.trees: map[str, Tree] = {}
        self.cycles = []
        self.builtin_uri = path_to_file_uri(
            Path("/home/martim/Desktop/pls/sicstus-doc-scraper/builtins.pl").resolve()
        )
        self.builtin_table: SymbolTable = None
        self.start_up()

    def start_up(self):
        doc = MyDoc(self.builtin_uri)
        self.parse(doc)

    def tree_diagnostics(self, tree: Tree):
        syntax_error_visitor = SyntaxErrorVisitor()
        return syntax_error_visitor.visit(tree.root_node)

    def unused_variables(
        self, tree: Tree, table: SymbolTable
    ) -> list[types.Diagnostic]:
        analysis = UnusedVariablePass(table)
        analysis.start(tree.root_node)
        return analysis.reports

    def undefined_predicate(
        self, tree: Tree, table: SymbolTable
    ) -> list[types.Diagnostic]:
        analysis = UndefinedPredicate(table)
        analysis.start(tree.root_node)
        return analysis.reports

    def run_passes(self, document: TextDocument) -> list[types.Diagnostic]:
        tree = self.trees[document.uri][1]
        table = self.tables[document.uri]
        result = []
        result.extend(self.tree_diagnostics(tree))
        result.extend(self.unused_variables(tree, table))
        result.extend(self.undefined_predicate(tree, table))
        return result

    def semantic_tokens(self, document:TextDocument):
        tree = self.trees[document.uri][1]
        table = self.tables.get(document.uri)
        tokens_visitor = HighlightVisitor(table)
        tokens_visitor.visit(tree.root_node)
        return tokens_visitor.token_list

    def parse(self, document: TextDocument):
        self.predicate_index = {}
        current_uri = document.uri
        # Try catch dangerous
        try:
            tree, symbol_table = self._parse(document)
        except TypeError:
            logging.log(logging.DEBUG, f"{traceback.format_exc()}")
        logging.info(f"Parsing: {current_uri}")
        self.run_analysis(document)

    def add_diagnostics_by_uri(self,uri:str,diagnostics:list):
        if  uri not in self.diagnostics:
            self.diagnostics[uri] = ( 0, diagnostics)
        else:
            version, new_diagnostics = self.diagnostics[uri]
            new_diagnostics.extend(diagnostics)
            self.diagnostics[uri] = ( version, new_diagnostics)

    def add_diagnostics(self,document:TextDocument,diagnostics:list):
        if document.uri not in self.diagnostics:
            logging.error(f"Deleting warnings")
            self.diagnostics[document.uri] = (
                document.version,
                diagnostics
            )
        else:
            version, new_diagnostics = self.diagnostics[document.uri]
            if version != document.version:
                logging.error(f"Deleting warnings")
                new_diagnostics = []
            new_diagnostics.extend(diagnostics)
            self.diagnostics[document.uri] = (
                document.version,
                new_diagnostics
            )

    def run_analysis( self, document: TextDocument):
        table = self.tables.get(document.uri)

        if table and document.uri != self.builtin_uri:
            table.builtins = self.tables[self.builtin_uri]
        
        diagnostics = self.run_passes(document)
        self.add_diagnostics(document,diagnostics)

        self.tokens[document.uri] = (
            document.version,
            self.semantic_tokens(document),
        )
        logging.info("%s", self.diagnostics)

    def _parse(self, doc: TextDocument):
        tree = parser.parse(bytes(doc.source, "utf-8"))
        self.trees[doc.uri] = (doc.version,tree)

        prolog_visitor = PrologVisitor(doc.uri)
        prolog_visitor.visit(tree.root_node, Opts())
        symbol_table = SymbolTable(
            scopes=prolog_visitor.scopes,
            notes=prolog_visitor.notes,
            predicate_index=prolog_visitor.predicate_index,
            builtins=None,
            imports={},
            consults={},
            consult_paths=prolog_visitor.consult_paths,
            path=doc.uri,
        )
        self.tables[doc.uri] = symbol_table
        return tree, symbol_table

    def document_from_workspace_or_fs(self, uri):
        try:
            document = server.workspace.get_document(uri)
            return document
        except Exception as e:
            logging.error(f"Could Not get file: {uri}\n{e}")
            return MyDoc(uri)

    
    def should_reanalyse(self, document: TextDocument,dependencies_changed:bool = False):
        if dependencies_changed:
            return True,"Dependencies Changed"
        if document.uri not in self.diagnostics:
            return True,"Not Yet Parsed"
        version, _ = self.diagnostics[document.uri]
        if version != document.version:
            return True,f"Document Has a Different Version Parsed:{version}, Received {document.version}"

        return False , ""
    
    def should_reparse(self,document:TextDocument):
        version = document.version
        uri = document.uri

        if uri not in self.trees:
            return True, f"{document.filename} not already parsed"
        
        current_version, _ = self.trees[uri]

        if current_version != version:
            return True,f"{document.filename} version changed"
        
        return False,f"{document.filename} cached no need to reparse version hasn't changed"
    



    def shallow_parse(self,document:TextDocument):
        reparse, reason = self.should_reparse(document)
        logging.error(f"{reason}")
        if reparse:
            self._parse(document)

        self.dg.add_file(document.uri)
        c = ConsultPaths(self.tables,self.dg)
        consult_warnings,available_paths = c.analyse(document.uri) 
        self.cycles.extend(c.cycles)
        logging.error(f"Consult Warnings: {consult_warnings }")
        if document.uri not in self.diagnostics:
            logging.error(f"Deleting warnings")
            self.diagnostics[document.uri] = (document.version,[])
        self.diagnostics[document.uri][1].extend(consult_warnings)

        return available_paths

    def build_dependency_graph(self,document:TextDocument):

        visited = set()
        queue = [document.uri]
        while len(queue) > 0:
            next = queue.pop(0)
            if next in visited:
                continue
            visited.add(next)
            next_document = self.document_from_workspace_or_fs(next)
            consult_paths = self.shallow_parse(next_document)

            to_graph_paths = []
            to_graph_paths.extend(consult_paths)
            to_graph_paths.extend(self.dg.get_file(next).is_included)
            
            for uri in to_graph_paths:
                if uri not in visited:
                    queue.append(uri)
            
    def clear_diagnostics(self,document: TextDocument):
        self.diagnostics[document.uri] = ( document.version, [])


    def start_parse_chain(self,document: TextDocument):

        logging.error(f"Parse Chain triggered by: {document.filename}:v{document.version}")
        self.cycles = []
        self.build_dependency_graph(document)
        cp = ConsultPaths(self.tables,self.dg)
        cycles = self.dg.get_cycles()
        logging.error(f"CYCLES: {cycles}")
        chain = self.dg.get_files_to_analyse(document.uri)

        cycle_reports : dict[str,list] = {}
        for cycle in cycles:
            cp.build_cyclic_consult_reports(cycle)


        logging.error(f"Parse Chain of {document.filename}: {chain}")
        logging.error(f"{self.dg.dg}")
        for file_name in chain:
            next_document = self.document_from_workspace_or_fs(file_name)
            self.clear_diagnostics(next_document)

            cycle_reports = cp.cycle_reports.get(file_name,[])
            self.add_diagnostics(next_document,cycle_reports)

            self.parse_assuming_dependencies_are_handled(next_document)


    def parse_assuming_dependencies_are_handled(self,document:TextDocument):
        
        self.shallow_parse(document)
        symbol_table = self.tables[document.uri]
        
        file_deps = self.dg.get_file(document.uri)

        for file in file_deps.includes.values():
            if file.uri not in self.tables:
                logging.error(f"File: {document.filename} depends on {file.name} but it hasn't been parsed yet, in  parse_assuming_dependencies_are_handled")
            else:
                consult_table = self.tables[file.uri]
                symbol_table.consults[file.uri] = consult_table

        self.run_analysis(document)
        logging.error(f"{document.filename}:has {len(self.diagnostics[document.uri][1])} warnings")


    def parse_with_dependencies(self, document: TextDocument):

        self.start_parse_chain(document)

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

            return self.get_predicate(functor.key(), uri)

    def get_predicate(self, key: str, uri: str):
        res = self.tables[uri].predicate_index.get(key)
        if res is None or len(res.definitions) == 0:
            builtin = self.tables[self.builtin_uri].predicate_index.get(key)
            if builtin:
                res = builtin
        return res

    def discover_node(
        self, tree, position: types.Position, uri: str
    ) -> Variable | Predicate | None:
        node = node_at_position(tree.root_node, position)
        return self.transform_in_variable_or_predicate(node, position, uri)

    def go_to_definition(self, tree, position: types.Position, uri: str):
        node: Node | None = node_at_position(tree.root_node, position)
        element: Variable | Predicate | None = self.transform_in_variable_or_predicate(
            node, position, uri
        )

        if type(element) is Variable and len(element.references) > 0:
            return element.references[0]
        elif type(element) is Predicate and len(element.definitions) > 0:
            return element.definitions[0]
        elif element is None:
            return None
        return None

    def find_references(self, tree, position: types.Position, uri: str):
        element: Variable | Predicate | None = self.discover_node(tree, position, uri)
        locations = []
        if element is None:
            return locations
        locations.extend(element.references)
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

    def document_links(self, uri: str):
        if uri not in self.tables:
            return []

        table: SymbolTable = self.tables[uri]
        result = []
        for consult_path, locations in table.consult_paths.items():
            for l in locations:
                result.append(
                    types.DocumentLink(
                        range=l.range,
                        target=add_paths(uri, consult_path),
                    ),
                )
        return result


server = PLS("prolog-server", "v0.0.1")


@server.feature(types.TEXT_DOCUMENT_DID_OPEN)
def did_open(ls: PLS, params: types.DidOpenTextDocumentParams):
    """Parse each document when it is opened"""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    # ls.parse(doc)
    ls.parse_with_dependencies(doc)

    for uri, (version, diagnostics) in ls.diagnostics.items():
        ls.publish_diagnostics(uri, diagnostics,version)


@server.feature(types.TEXT_DOCUMENT_DID_CHANGE)
def did_change(ls: PLS, params: types.DidOpenTextDocumentParams):
    """Parse each document when it is changed"""
    doc = ls.workspace.get_text_document(params.text_document.uri)
    ls.parse_with_dependencies(doc)

    for uri, (version, diagnostics) in ls.diagnostics.items():
        ls.publish_diagnostics(uri, diagnostics,version)


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
    types.TEXT_DOCUMENT_DOCUMENT_LINK,
)
def document_links(ls: PLS, params: types.DocumentLinkParams):
    """Return a list of links contained in the document. Currently Consult Links"""
    items = []
    document_uri = params.text_document.uri
    return ls.document_links(document_uri)


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
