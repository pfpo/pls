from tree_sitter import Node, QueryCursor
from lsprotocol import types
from pls.utils import node_to_range, RangedAction
from .analyser import Analyser, PrologAnalyseable

class TooManyArgumentsAnalysis(Analyser):
    def __init__(self):
        super().__init__()
        self.table = None
        self.matches = None
        self.arg_limit = 8

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        root_node = content.trees[self.uri][1].root_node
        too_many_arguments_query = content.queries["too_many_arguments"]
        query_cursor = QueryCursor(too_many_arguments_query)
        self.matches = query_cursor.matches(root_node)

        for m in self.matches:
            (_, match) = m
            argument_list = match["arg_list"][0]
            arguments = [child for child in argument_list.children if child.type != "arg_list_separator"]
            if len(arguments) > self.arg_limit:
                self.add_too_many_arguments_warning(argument_list)

    def add_too_many_arguments_warning(self, node: Node):
        range = node_to_range(node)
        severity = types.DiagnosticSeverity.Warning
        message = "This predicate has too many arguments. Consider refactoring to reduce the number of arguments."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)