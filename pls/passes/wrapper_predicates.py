from tree_sitter import Node, QueryCursor
from lsprotocol import types
from pls.utils import node_to_range, RangedAction
from .analyser import Analyser, PrologAnalyseable

class WrapperPredicatesAppendsAnalysis(Analyser):
    def __init__(self):
        super().__init__()
        self.table = None
        self.matches = None

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        root_node = content.trees[self.uri][1].root_node
        wrapper_predicate_query = content.queries["wrapper_predicate"]
        query_cursor = QueryCursor(wrapper_predicate_query)
        self.matches = query_cursor

        for index, m in enumerate(self.matches):
            (_, match) = m
            wrapper_predicate = match["wrapper"][0]
            self.add_wrapper_predicate_warning(self, wrapper_predicate)
            self.add_wrapper_predicate_code_action(self, wrapper_predicate, index)

    def add_wrapper_predicate_warning(self, node):
        range = node_to_range(node)
        severity = types.DiagnosticSeverity.Warning
        message = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)

    def add_wrapper_predicate_code_action(self, wrapper_predicate, index):
        return