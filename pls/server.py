from pygls.server import LanguageServer
from lsprotocol import types
# from pygls.cli import start_server
from pygls.workspace import TextDocument

import logging
import re

from lsprotocol import types

from tree_sitter import Language, Parser,Node
from tree_sitter_prolog import prolog

PROLOG = Language(prolog())

parser = Parser(PROLOG)

def node_to_range(node:Node):

    return types.Range(
                            start=types.Position(line=node.start_point.row,character=node.start_point.column),
                            end=types.Position(line=node.end_point.row,character=node.end_point.column),
                        )


class PLS(LanguageServer):
    """Language server demonstrating "push-model" diagnostics."""

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.diagnostics = {}

    def parse(self, document: TextDocument):
        diagnostics = self._parse(document.source)

        self.diagnostics[document.uri] = (document.version, diagnostics)
        logging.info("%s", self.diagnostics)

    def _parse(self, doc:str):
        diagnostics = []

        tree = parser.parse(bytes(doc,"utf-8"))

        severity = types.DiagnosticSeverity.Error

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


if __name__ == "__main__":
    logging.basicConfig(filename='pygls.log', filemode='w', level=logging.DEBUG)
    server.start_io()