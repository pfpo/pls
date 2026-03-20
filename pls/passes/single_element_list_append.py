from tree_sitter import Node, QueryCursor
from lsprotocol import types
from pls.utils import node_to_range, RangedAction
from .analyser import Analyser, PrologAnalyseable

class SingleElementListAppendAnalysis(Analyser):
    def __init__(self):
        super().__init__()
        self.table = None
        self.matches = None

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        root_node = content.trees[self.uri][1].root_node
        single_append_query = content.queries["single_element_list_append"]
        query_cursor = QueryCursor(single_append_query)
        self.matches = query_cursor.matches(root_node)

        for index, m in enumerate(self.matches):
            (_, match) = m
            append_call = match["append_call"][0]
            self.add_single_element_list_append_warning(append_call)
            self.add_single_element_list_append_code_action(append_call, index)

    def add_single_element_list_append_warning(self, node: Node):
        range = node_to_range(node)
        severity = types.DiagnosticSeverity.Warning
        message = "Appending a single element to a list can be more efficiently done using [Element|List] syntax."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)

    def add_single_element_list_append_code_action(self, node: Node, index: int):
        range = node_to_range(node)
        title = "Refactor to use [Element|List] syntax"
        new_text = self.suggest_refactor(index)
        changes = {self.uri: [types.TextEdit(range=range, new_text=new_text)]}
        code_action = types.CodeAction(
            title=title,
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(changes=changes),
        )
        self.add_file_action(RangedAction(code_action, range))

    def suggest_refactor(self, index: int) -> str:
        (_, match) = self.matches[index]
        first_arg = match["first_arg"][0].text.decode("utf-8")
        element = first_arg.strip("[]")
        second_arg = match["second_arg"][0].text.decode("utf-8")
        result = match["result"][0].text.decode("utf-8")

        # TODO this should be further refactored to do implicit unification
        # could be depended on configuration (allow explicit unification)
        return f"{result} = [{element} | {second_arg}]" 