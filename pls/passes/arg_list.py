from tree_sitter import Node, QueryCursor
from lsprotocol import types
from pls.utils import node_to_range, RangedAction
from .analyser import Analyser, PrologAnalyseable

class ArgumentListAnalysis(Analyser):
    def __init__(self):
        super().__init__()
        self.table = None
        self.matches = None

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        root_node = content.trees[self.uri][1].root_node
        argument_list_query = content.queries["arg_list_space"]
        query_cursor = QueryCursor(argument_list_query)
        self.matches = query_cursor.matches(root_node)
        self.lines = content.source.splitlines()

        for m in self.matches:
            (_, match) = m
            argument_list = match["arg_list"][0]
            self.analyse_argument_list(argument_list)
    
    def analyse_argument_list(self, node: Node):
        text = node.text.decode("utf-8")
        refactored_text = self.refactor_argument_list(text)
        if text != refactored_text:
            self.add_argument_list_warning(node)
            self.add_argument_list_code_action(node, refactored_text)

    def add_argument_list_warning(self, node: Node):
        range = node_to_range(node)
        severity = types.DiagnosticSeverity.Warning
        message = "Use a consistent formatting for argument lists. Ensure there is one space after a commas."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)

    def add_argument_list_code_action(self, node: Node, refactored_text: str):
        range = node_to_range(node)
        title = "Refactor argument list formatting"
        new_text = refactored_text
        changes = {self.uri: [types.TextEdit(range=range, new_text=new_text)]}
        code_action = types.CodeAction(
            title=title,
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(changes=changes),
        )
        self.add_file_action(RangedAction(code_action, range))

    def refactor_argument_list(self, text: str) -> str:
        parts = text.split(",")
        stripped_parts = [part.strip() for part in parts]
        return ", ".join(stripped_parts)