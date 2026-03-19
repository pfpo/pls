from tree_sitter import Node, QueryCursor
from lsprotocol import types
from pls.utils import node_to_range, RangedAction
from .analyser import Analyser, PrologAnalyseable

class NestedListConstructsAnalysis(Analyser):
    def __init__(self):
        super().__init__()
        self.table = None
        self.matches = None

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        root_node = content.trees[self.uri][1].root_node
        nested_list_query = content.queries["nested_list_constructs"]
        query_cursor = QueryCursor(nested_list_query)
        self.matches = query_cursor.matches(root_node)

        for index, m in enumerate(self.matches):
            (_, match) = m
            nested_list = match["nested_list"][0]
            if not self.is_nested(nested_list):
                self.add_nested_list_warning(nested_list)
                self.add_nested_list_code_action(nested_list, index)

    def add_nested_list_warning(self, node: Node):
        range = node_to_range(node)
        severity = types.DiagnosticSeverity.Warning
        message = "Nested list constructs can be simplified to a single list construct."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)

    def add_nested_list_code_action(self, node: Node, index: int):
        range = node_to_range(node)
        title = "Refactor nested list construct"
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
        head = ""
        for h in match["head"]:
            head += h.text.decode("utf-8")
        inner_head = ""
        for ih in match["inner_head"]:
            inner_head += ih.text.decode("utf-8")
        inner_tail = match["inner_tail"][0].text.decode("utf-8")

        return f"[{head},{inner_head} | {inner_tail}]"
    
    def is_nested(self, node: Node) -> bool:
        parent = node.parent
        while parent is not None:
            if parent.type == "list_notation":
                return True
            parent = parent.parent
        return False