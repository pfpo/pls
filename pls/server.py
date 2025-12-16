import os
from copy import deepcopy

import asyncio
import uuid

from pygls.lsp.server import LanguageServer
from lsprotocol import types
from pygls.workspace import TextDocument
from pygls.uris import from_fs_path, to_fs_path
from tree_sitter import Language, Parser, Tree, Node
from tree_sitter_prolog import prolog

from pls.folding_range_visitor import FoldingRangeVisitor
from pls.passes.analyser import Analyser
from pls.pldoc_comment_visitor import PlDocComment

from .utils import (
    node_at_position,
    builtins_path,
    node_to_range,
    path_to_file_uri,
    Path,
    MyDoc,
    ranges_overlap,
    FileVersionedDict,
)
from .model import (
    Functor,
    PrologAnalyseable,
    Variable,
    Predicate,
    SymbolTable,
    scope_at_position,
    Scope,
)

from .matching_signature_help import in_possible_signature_help
from .annotations import Annotations
from .prolog_visitor import PrologVisitor, Opts
from .highlight.highlight_visitor import HighlightVisitor
from .highlight.highlight import TokenModifier, TokenTypes
from .markup import descriptions
from .passes.modules import MooduleAnalyser
from .passes.missing_paths import MissingPaths
from .passes.cyclic_paths import CyclicPaths
from .dependency_graph import DependencyGraphManager
from .my_logging import logging


from .passes.pipeline import Pipeline


PROLOG = Language(prolog())

parser = Parser(PROLOG)


class PLS(LanguageServer):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.actions: FileVersionedDict[list[types.CodeAction]] = FileVersionedDict()
        self.diagnostics: FileVersionedDict[list[types.Diagnostic]] = (
            FileVersionedDict()
        )
        self.tokens = {}
        self.tables: dict[str, SymbolTable] = {}
        self.original_tables: dict[str, SymbolTable] = {}
        self.comment_trees: dict[str, Annotations] = {}
        self.dg = DependencyGraphManager()
        self.trees: dict[str, Tree] = {}
        self.files = []
        self.builtin_uri = builtins_path()
        self.builtin_table: SymbolTable = None
        self.root_path = None

        self.analysed_without_index_being_created = set()
        self.index_created = False

    def get_analyseable(self, uri: str = "") -> PrologAnalyseable:
        return PrologAnalyseable(uri, self.tables, self.trees, self.dg)

    def discover_files(self):
        collected = set()
        root_path = self.root_path
        for dirpath, _, filenames in os.walk(root_path):
            for fname in filenames:
                if fname.endswith(".pl"):
                    path = os.path.join(dirpath, fname)
                    uri = path_to_file_uri(Path(path))
                    collected.add(uri)
        logging.error(f"{collected}")
        return list(collected)

    def handle_builtins(self):
        doc = MyDoc(self.builtin_uri)
        self.parse(doc)

    def start_up_lib(self, path):
        self.handle_builtins()
        # self.root_path = path
        # self.files = self.discover_files()
        # self.index_sync(self.files)

    async def start_up(self):
        self.handle_builtins()
        self.root_path = self.workspace.root_path
        self.files = self.discover_files()
        await self.index_with_progress(self.files)
        # logging.error(f"Files: {self.files}")

    def run_passes(self, document: TextDocument) -> list[types.Diagnostic]:
        content = self.get_analyseable(document.uri)
        passes = Pipeline()
        passes.analyse(content)
        self.get_analyser_results(passes)

    def get_analyser_results(self, analyser: Analyser):
        for uri, diagnostics in analyser.diagnostics.items():
            self.diagnostics.add_by_uri(uri, diagnostics)

        for uri, actions in analyser.actions.items():
            self.actions.add_by_uri(uri, actions)

    def semantic_tokens(self, document: TextDocument):
        tree = self.trees[document.uri][1]
        table = self.tables.get(document.uri)
        comment_trees = self.comment_trees.get(document.uri)
        tokens_visitor = HighlightVisitor(table, comment_trees)
        tokens_visitor.visit(tree.root_node)
        return tokens_visitor.token_list

    def parse(self, document: TextDocument):
        self.predicate_index = {}
        current_uri = document.uri
        tree, symbol_table = self._parse(document)
        logging.info(f"Parsing: {current_uri}")
        self.run_analysis(document)

    def run_analysis(self, document: TextDocument):
        table = self.tables.get(document.uri)

        if (
            table
            and document.uri != self.builtin_uri
            and self.builtin_uri in self.tables
        ):
            table.builtins = self.tables[self.builtin_uri]

        self.run_passes(document)

        self.tokens[document.uri] = (
            document.version,
            self.semantic_tokens(document),
        )

    def _parse(self, doc: TextDocument):
        tree = parser.parse(bytes(doc.source, "utf-8"))
        self.trees[doc.uri] = (doc.version, tree)

        prolog_visitor = PrologVisitor(doc.uri)
        prolog_visitor.visit(tree.root_node, Opts())
        symbol_table = SymbolTable(
            scopes=prolog_visitor.scopes,
            notes=prolog_visitor.notes,
            predicate_index=prolog_visitor.predicate_index,
            predicate_index_by_name=prolog_visitor.predicate_index_by_name,
            builtins=None,
            imports={},
            imported_signatures={},
            consults={},
            consult_paths=prolog_visitor.consult_paths,
            module_paths=prolog_visitor.module_paths,
            module_declarations=prolog_visitor.module_declarations,
            use_module_declarations=prolog_visitor.used_modules,
            exported_signatures=set(),
            libs=prolog_visitor.libs,
            exportable_predicates=prolog_visitor.exportable_predicates,
            path=doc.uri,
            operator_declarations=prolog_visitor.operator_declarations,
            operators=[],
        )
        self.comment_trees[doc.uri] = prolog_visitor.comment_trees
        self.original_tables[doc.uri] = symbol_table
        self.tables[doc.uri] = deepcopy(symbol_table)
        return tree, symbol_table

    def get_document(self, d):
        document = None
        if type(d) is str:
            document = server.workspace.get_text_document(d)
        else:
            assert type(d) is types.TextDocumentItem, (
                f"Trying to get document with parameter :{type(d)} {d} "
            )
            document = TextDocument(d.uri, d.text, d.version, d.language_id)
        document.uri = from_fs_path(to_fs_path(document.uri))
        # logging.error(f"{document.source}")
        return document

    def document_from_workspace_or_fs(self, uri):
        try:
            document = self.get_document(uri)
            return document
        except Exception as e:
            logging.error(f"Could Not get file: {uri}\n{e}")
            return MyDoc(uri)

    def should_reparse(self, document: TextDocument):
        version = document.version
        uri = document.uri

        if uri not in self.trees:
            return True, f"{document.filename} not already parsed"

        current_version, _ = self.trees[uri]

        if current_version is None or version is None:
            return True, f"{document.filename} new version or current version is None"

        if current_version != version:
            return True, f"{document.filename} version changed"

        return (
            False,
            f"{document.filename} cached no need to reparse version hasn't changed",
        )

    def shallow_parse(self, document: TextDocument):
        reparse, reason = self.should_reparse(document)
        # logging.error(f"{reason}")
        if reparse:
            self._parse(document)
        else:
            self.tables[document.uri] = deepcopy(self.original_tables[document.uri])
        self.dg.add_file(document.uri)
        c = MissingPaths(self.dg)
        c.analyse(self.get_analyseable(document.uri))
        self.get_analyser_results(c)
        return c.available_paths

    def build_dependency_graph_sync(self, uris: list[str]):
        visited = set()
        received_uris = set(uris)
        total_uris = set(uris)
        queue = uris
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
                if uri not in visited and uri not in received_uris:
                    queue.append(uri)
                    total_uris.add(uri)

    async def build_dependency_graph(self, uris: list[str], progress_report=None):
        visited = set()
        received_uris = set(uris)
        total_uris = set(uris)
        queue = uris
        while len(queue) > 0:
            next = queue.pop(0)
            if next in visited:
                continue
            visited.add(next)
            next_document = self.document_from_workspace_or_fs(next)
            consult_paths = self.shallow_parse(next_document)
            # time.sleep(2)
            to_graph_paths = []
            to_graph_paths.extend(consult_paths)
            to_graph_paths.extend(self.dg.get_file(next).is_included)

            for uri in to_graph_paths:
                if uri not in visited and uri not in received_uris:
                    queue.append(uri)
                    total_uris.add(uri)
            if progress_report:
                await progress_report(len(visited), len(received_uris))

    def clear_diagnostics(self, document: TextDocument):
        self.diagnostics[document.uri] = (document.version, [])

    def clear_code_actions(self, document: TextDocument):
        self.actions[document.uri] = (document.version, [])

    def start_parse_chain(self, document: TextDocument):
        # logging.error(
        #     f"Parse Chain triggered by: {document.filename}:v{document.version}"
        # )
        self.build_dependency_graph_sync([document.uri])
        cp = CyclicPaths()
        cp.analyse(self.get_analyseable(document.uri))

        chain = self.dg.get_files_to_analyse(document.uri)
        logging.error(f"Parse Chain of {document.filename}: {chain}")
        # logging.error(f"{self.dg.dg}")
        for uri in chain:
            next_document = self.document_from_workspace_or_fs(uri)
            if uri == document.uri:
                # Ir buscar o documento que Inicia a cadeia, trouxe uma versão diferente do doc
                # No windows tem este problema
                #if document.source != next_document.source:
                #    logging.error(
                #        "\n\n\n\n DOCUMENTO Com conteudo diferente do esperado"
                #    )
                next_document = document

            logging.error(f"Going to Parse {next_document.filename}")
            self.clear_diagnostics(next_document)
            self.clear_code_actions(next_document)
            self.parse_assuming_dependencies_are_handled(next_document)

        # logging.error(f"{cp.diagnostics}")
        self.get_analyser_results(cp)

    async def index_with_progress(self, files: list[str]):
        """Create and start the progress on the client."""
        token = str(uuid.uuid4())
        # Create
        logging.error("\n\nStart Indexing Project\n\n")
        await self.progress.create_async(token)
        # Begin
        self.progress.begin(
            token,
            types.WorkDoneProgressBegin(
                title="Indexing", percentage=0, cancellable=True
            ),
        )

        async def report_hook(i, total):
            if total == 0:
                total = 1
            logging.error(f"Parsed {i}/{total}")
            if i % 5 == 0 or i == total - 1:
                percent = int((i + 1) / total * 100)
                self.progress.report(
                    token,
                    types.WorkDoneProgressReport(
                        message=f"Parsed {i}/{total}", percentage=percent
                    ),
                )

        # Report
        for i in range(1, 10):
            # Check for cancellation from client
            if self.progress.tokens[token].cancelled():
                # ... and stop the computation if client cancelled
                return
            await self.build_dependency_graph(files, report_hook)
            self.progress.report(
                token,
                types.WorkDoneProgressReport(message=f"{i * 10}%", percentage=i * 10),
            )
            await asyncio.sleep(0)
        # End
        self.finish_indexing()
        self.progress.end(token, types.WorkDoneProgressEnd(message="Finished"))

    def finish_indexing(self):
        self.index_created = True
        logging.error(f"{self.dg.dg}")
        logging.error(f"Analysed {len(self.dg.dg.files.keys())} files")
        logging.error("Finished Indexing")
        for uri in self.analysed_without_index_being_created:
            logging.error(f"Will have to reanalyse: {uri}")
            doc = self.get_document(uri)
            self.parse_with_dependencies(doc)
            version, diagnostics = self.diagnostics[uri]
            self.text_document_publish_diagnostics(types.PublishDiagnosticsParams(
                uri=uri,
                version=version,
                diagnostics=diagnostics,
            ))

    def parse_assuming_dependencies_are_handled(self, document: TextDocument):
        if not self.index_created:
            self.analysed_without_index_being_created.add(document.uri)
        self.shallow_parse(document)
        symbol_table = self.tables[document.uri]

        file_deps = self.dg.get_file(document.uri)

        modules_to_include = set()
        for dep in file_deps.includes.values():
            file = dep.file
            logging.error(f"File: {document.filename} depends on {file.name}")
            if file.uri not in self.tables:
                logging.error(
                    f"File: {document.filename} depends on {file.name} but it hasn't been parsed yet, in  parse_assuming_dependencies_are_handled"
                )
                self.analysed_without_index_being_created.add(document.uri)
            elif dep.is_module:
                modules_to_include.add(file.uri)
            else:
                consult_table = self.tables[file.uri]
                symbol_table.consults[file.uri] = consult_table

        m = MooduleAnalyser(modules_to_include)
        m.analyse(self.get_analyseable(document.uri))

        self.run_analysis(document)
        self.get_analyser_results(m)

    def parse_with_dependencies(self, document: TextDocument):
        self.start_parse_chain(document)

    def transform_in_variable_or_predicate(
        self, node: Node, position: types.Position, uri: str
    ) -> Variable | Predicate | None:
        if node is None:
            return None
        table = self.tables[uri]
        if (
            node.parent
            and node.parent.type == "operator_notation"
            and node.parent.child_by_field_name("operator") == node
        ):
            return table.notes[node]
        if node.type in ("variable_term"):
            return table.notes[node]

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

    # TODO: Substitute By table get_predicate
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

    def go_to_definition(self, doc: TextDocument, position: types.Position):
        uri = doc.uri
        tree = self.trees.get(uri, (0, None))[1]
        if tree is None:
            return None

        node: Node | None = node_at_position(tree.root_node, position)
        element: Variable | Predicate | None = self.transform_in_variable_or_predicate(
            node, position, uri
        )

        if type(element) is Variable and len(element.references) > 0:
            return element.references[0]
        elif type(element) is Predicate:
            if len(element.definitions) > 0:
                return element.definitions[0]
            for comment in element.comments:
                if type(comment) is PlDocComment:
                    if comment.location:
                        return comment.location
        elif element is None:
            return None
        return None

    def document_highlight(self, doc: TextDocument, position: types.Position)-> list[types.DocumentHighlight]:
        uri = doc.uri
        tree = self.trees.get(uri, (0, None))[1]
        locations : types.Location = []
        if tree is None:
            return locations

        element: Variable | Predicate | None = self.discover_node(tree, position, uri)
        if element is None:
            return locations
        if type(element) is Predicate:
            locations.extend(element.name_references)
        else:
            locations.extend(element.references)
        result = []
        for l in locations:
            if l.uri == doc.uri:
                h = types.DocumentHighlight(l.range)
                result.append(h)

        return result

    def find_references(self, doc: TextDocument, position: types.Position):
        uri = doc.uri
        tree = self.trees.get(uri, (0, None))[1]
        locations = []
        if tree is None:
            return locations

        element: Variable | Predicate | None = self.discover_node(tree, position, uri)
        if element is None:
            return locations
        locations.extend(element.references)
        return locations

    def selection_range_position(
        self, doc: TextDocument, position: types.Position
    ) -> types.SelectionRange:
        tree = self.trees[doc.uri][1]
        node = node_at_position(tree.root_node, position)
        if node is None:
            return None
        origin = None
        current = None
        while True:
            if current is None:
                origin = types.SelectionRange(node_to_range(node))
                current = origin
                if node.parent is None:
                    break
                node = node.parent
            if node.parent is None:
                break
            new_range = types.SelectionRange(node_to_range(node))
            current.parent = new_range
            current = new_range
            node = node.parent
        return origin

    def selection_range(
        self, doc: TextDocument, positions: list[types.Position]
    ) -> list[types.SelectionRange]:
        return [self.selection_range_position(doc, p) for p in positions]

    def folding_range(self, doc: TextDocument) -> list[types.FoldingRange]:
        tree = self.trees[doc.uri][1]
        return FoldingRangeVisitor(tree.root_node).start()

    def get_code_actions(self, doc: TextDocument, requested_range: types.Range):
        result = []
        if doc.uri not in self.actions:
            return result
        ranged_actions = self.actions[doc.uri][1]

        for ra in ranged_actions:
            a = ra.action
            r = ra.range
            if ranges_overlap(r, requested_range):
                result.append(a)

        return result

    def hover(self, doc: TextDocument, position: types.Position):
        uri = doc.uri
        tree = self.trees.get(uri, (0, None))[1]
        if tree is None:
            return None

        maybe_node = node_at_position(tree.root_node, position)
        if maybe_node is None:
            return None
        element = self.transform_in_variable_or_predicate(maybe_node, position, uri)
        if element is not None and type(element) is Variable:
            content = descriptions.variable_description(element)
        elif element is not None and type(element) is Predicate:
            content = descriptions.predicate_description(element)
        else:
            # Disabled Node Description
            # content = descriptions.node_description(maybe_node)
            return None

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

    def document_links(self, doc: TextDocument):
        uri = doc.uri
        if uri not in self.tables:
            return []

        table: SymbolTable = self.tables[uri]
        result = []
        location_items = []
        location_items.extend(table.consult_paths.items())
        location_items.extend(table.module_paths.items())
        for path, locations in location_items:
            for location in locations:
                result.append(
                    types.DocumentLink(range=location.range, target=path),
                )
        return result

    def send_completions(self, document: TextDocument, position: types.Position):
        if document.uri not in self.tables:
            return []

        tree = self.trees[document.uri][1]
        table = self.tables[document.uri]
        n = scope_at_position(tree.root_node, table, position)
        variables = []
        if n is None:
            return []
        elif type(n) is Scope:
            variables.extend(n.variables.values())

        elif type(n) is Predicate:
            for scope in n.scopes:
                variables.extend(scope.variables.values())
        else:
            logging.error(f"Got type {type(n)}")

        result = []

        for variable in variables:
            content = descriptions.variable_description(variable)
            result.append(
                types.CompletionItem(
                    variable.name,
                    kind=types.CompletionItemKind.Variable,
                    documentation=types.MarkupContent(
                        types.MarkupKind.Markdown, "\n".join(content)
                    ),
                ),
            )

        available_predicates = list(table.predicate_index.values())
        for consulted in table.consults.values():
            available_predicates.extend(consulted.predicate_index.values())

        available_predicates = [
            p for p in available_predicates if len(p.definitions) > 0
        ]

        if table.builtins:
            available_predicates.extend(table.builtins.predicate_index.values())

        for module_path, key_set in table.imported_signatures.items():
            module = table.imports[module_path]
            for key in key_set:
                if key in module.predicate_index:
                    available_predicates.append(module.predicate_index[key])

        for predicate in available_predicates:
            # logging.error(f"{predicate}{type(predicate)}")

            content = descriptions.predicate_description(predicate)
            template = descriptions.predicate_template(predicate)
            result.append(
                types.CompletionItem(
                    predicate.name,
                    label_details=types.CompletionItemLabelDetails(
                        detail=f"/{predicate.arity}"
                    ),
                    kind=types.CompletionItemKind.Function,
                    insert_text=template,
                    insert_text_format=types.InsertTextFormat.Snippet,
                    documentation=types.MarkupContent(
                        types.MarkupKind.Markdown, "\n".join(content)
                    ),
                ),
            )

        return result

    def signature_help_proposals(
        self, document: TextDocument, position: types.Position
    ):
        if document.uri not in self.tables:
            return []

        tree = self.trees[document.uri][1]
        table = self.tables[document.uri]
        node = node_at_position(tree.root_node, position)
        # logging.error(f"{node} {node.type}")
        is_functor, predicate_name, active_parameter = in_possible_signature_help(node)

        if not is_functor:
            return []

        # logging.error(f"Signature Help for  {predicate_name} in parameter: {active_parameter}")
        with_matchin_name = table.get_predicates_that_match(predicate_name)

        signatures = []
        for predicate in with_matchin_name:
            signature = descriptions.signature_information(predicate, active_parameter)
            signatures.append(signature)

        return types.SignatureHelp(
            signatures=signatures,
            active_signature=0,
            active_parameter=active_parameter,
        )

    def rename_edits(
        self, document: TextDocument, position: types.Position, new_name: str
    ):
        tree = self.trees.get(document.uri, (0, None))[1]
        if tree is None:
            return None

        element: Variable | Predicate | None = self.discover_node(
            tree, position, document.uri
        )

        if element is None:
            return None

        changes: dict[str, list[types.TextEdit]] = {}

        def add_edit(changes, name, location: types.Location):
            if location.uri not in changes:
                changes[location.uri] = []

            changes[location.uri].append(
                types.TextEdit(new_text=name, range=location.range)
            )

        locations_to_rename = []
        if type(element) is Variable:
            locations_to_rename = element.references
        elif type(element) is Predicate:
            can_rename, reason = self.tables[document.uri].is_renameable(element.key())
            if not can_rename:
                self.show_message(
                    f"Cannot Rename Predicate: {reason}",
                    msg_type=types.MessageType.Error,
                )
                return
            locations_to_rename = element.name_references

        for location in locations_to_rename:
            add_edit(changes, new_name, location)

        return types.WorkspaceEdit(changes)

    def is_renameable(self, document: TextDocument, position: types.Position):
        tree = self.trees.get(document.uri, (0, None))[1]
        if tree is None:
            return None

        element: Variable | Predicate | None = self.discover_node(
            tree, position, document.uri
        )

        return types.PrepareRenameDefaultBehavior(default_behavior=element is not None)


server = PLS("prolog-server", "v0.0.1")


@server.feature(types.INITIALIZED)
def on_initialized(ls: PLS, params):
    logging.error("Running on Initialized")
    asyncio.create_task(ls.start_up())


@server.feature(types.TEXT_DOCUMENT_DID_OPEN)
def did_open(ls: PLS, params: types.DidOpenTextDocumentParams):
    """Parse each document when it is opened"""
    doc = ls.get_document(params.text_document)
    # ls.parse(doc)
    ls.parse_with_dependencies(doc)

    for uri, (version, diagnostics) in ls.diagnostics.items():
        ls.text_document_publish_diagnostics(types.PublishDiagnosticsParams(
                uri=uri,
                version=version,
                diagnostics=diagnostics,
            ))


@server.feature(types.TEXT_DOCUMENT_DID_CHANGE)
def did_change(ls: PLS, params: types.DidChangeTextDocumentParams):
    """Parse each document when it is changed"""
    doc = ls.get_document(params.text_document.uri)
    ls.parse_with_dependencies(doc)

    for uri, (version, diagnostics) in ls.diagnostics.items():
        ls.text_document_publish_diagnostics(types.PublishDiagnosticsParams(
                uri=uri,
                version=version,
                diagnostics=diagnostics,
            ))


@server.feature("textDocument/definition")
def goto_definition(ls: PLS, params: types.DefinitionParams):
    """Jump to an object's definition."""
    doc = ls.get_document(params.text_document.uri)
    result = ls.go_to_definition(doc, params.position)
    return result


@server.feature(types.TEXT_DOCUMENT_REFERENCES)
def find_references(ls: PLS, params: types.ReferenceParams):
    """Find references of an object."""
    doc = ls.get_document(params.text_document.uri)
    references = ls.find_references(doc, params.position)
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
    doc = ls.get_document(params.text_document.uri)
    ver_sion, tokens = ls.tokens.get(doc.uri, (0, []))
    res = types.SemanticTokens(data=tokens)
    return res


@server.feature(types.TEXT_DOCUMENT_HOVER)
def hover(ls: PLS, params: types.HoverParams):
    doc = ls.get_document(params.text_document.uri)
    result = ls.hover(doc, params.position)
    return result


@server.feature(
    types.TEXT_DOCUMENT_DOCUMENT_LINK,
)
def document_links(ls: PLS, params: types.DocumentLinkParams):
    """Return a list of links contained in the document. Currently Consult Links"""
    doc = ls.get_document(params.text_document.uri)
    return ls.document_links(doc)


@server.feature(
    types.TEXT_DOCUMENT_COMPLETION,
    types.CompletionOptions(trigger_characters=[","]),
)
def completions(ls: PLS, params: types.CompletionParams):
    document = ls.get_document(params.text_document.uri)
    r = ls.send_completions(document, params.position)
    return r


@server.feature(
    types.TEXT_DOCUMENT_SIGNATURE_HELP,
    types.SignatureHelpOptions(trigger_characters=["(", ","]),
)
def signature_help(ls: PLS, params: types.SignatureHelpParams):
    doc = ls.get_document(params.text_document.uri)
    r = ls.signature_help_proposals(doc, params.position)
    return r


@server.feature(types.TEXT_DOCUMENT_RENAME)
def rename(ls: PLS, params: types.RenameParams):
    """Rename the symbol at the given position."""
    doc = ls.get_document(params.text_document.uri)
    position = params.position
    new_name = params.new_name
    return ls.rename_edits(doc, position, new_name)


@server.feature(types.TEXT_DOCUMENT_PREPARE_RENAME)
def prepare_rename(ls: PLS, params: types.PrepareRenameParams):
    """Called by the client to determine if renaming the symbol at the given location
    is a valid operation."""
    doc = ls.get_document(params.text_document.uri)
    position = params.position
    return ls.is_renameable(doc, position)


@server.feature(
    types.TEXT_DOCUMENT_CODE_ACTION,
    types.CodeActionOptions(code_action_kinds=[types.CodeActionKind.QuickFix]),
)
def code_actions(ls: PLS, params: types.CodeActionParams):
    logging.error("Code actions Request")
    doc = ls.get_document(params.text_document.uri)
    result = ls.get_code_actions(doc, params.range)
    return result


@server.feature(types.TEXT_DOCUMENT_SELECTION_RANGE)
def selection_range(ls: PLS, params: types.SelectionRangeParams):
    logging.error("Selection Range Request")
    doc = ls.get_document(params.text_document.uri)
    result = ls.selection_range(doc, params.positions)
    return result


@server.feature(types.TEXT_DOCUMENT_FOLDING_RANGE)
def folding_range(ls: PLS, params: types.FoldingRangeParams):
    doc = ls.get_document(params.text_document.uri)
    result = ls.folding_range(doc)
    return result



@server.feature(types.TEXT_DOCUMENT_DOCUMENT_HIGHLIGHT)
def document_highlight(ls: PLS, params: types.DocumentHighlightParams):
    doc = ls.get_document(params.text_document.uri)
    result = ls.document_highlight(doc,params.position)
    return result
