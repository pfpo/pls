from tree_sitter import Node, QueryCursor
from lsprotocol import types
from pls.utils import node_to_range, RangedAction
from .analyser import Analyser, PrologAnalyseable

class SubgoalPerLineAnalysis(Analyser):
    def __init__(self):
        super().__init__()
        self.table = None
        self.matches = None

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        root_node = content.trees[self.uri][1].root_node
        subgoal_per_line_query = content.queries["predicate"]
        query_cursor = QueryCursor(subgoal_per_line_query)
        self.matches = query_cursor.matches(root_node)
        self.lines = content.source.splitlines()

        for m in self.matches:
            (_, match) = m
            operator = match["operator_notation"][0]
            self.analyse_body(operator.children[2])
    
    def analyse_body(self, node: Node):
        comma = node.children[1] if len(node.children) > 1 and node.children[1].type == "comma" else None
        if comma is None:
            return

        first_subgoal = node.children[0]
        second_subgoal = node.children[2]

        if first_subgoal.start_point[0] == second_subgoal.start_point[0]:
            self.add_subgoal_per_line_warning(node)
        
        else:
            self.analyse_body(second_subgoal)


    def add_subgoal_per_line_warning(self, node: Node):
        range = node_to_range(node)
        severity = types.DiagnosticSeverity.Warning
        message = "Consider refactoring this clause to have one subgoal per line for better readability."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)
