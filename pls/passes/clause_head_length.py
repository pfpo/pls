from tree_sitter import Node
from lsprotocol import types
from pls.utils import node_to_range, RangedAction
from pls.ts_query_compat import QueryCursor
from .analyser import Analyser, PrologAnalyseable

class ClauseHeadLengthAnalysis(Analyser):
    def __init__(self, settings: dict = {}):
        super().__init__()
        self.table = None
        self.matches = None
        self.max_length = settings.get("max_line_length", 80)
        self.indent_mode = settings.get("indentation", "spaces")
        self.indent = " " * settings.get("indentation_size", 4)

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        root_node = content.trees[self.uri][1].root_node
        clause_head_length_query = content.queries["clause_head_length"]
        query_cursor = QueryCursor(clause_head_length_query)
        self.matches = query_cursor.matches(root_node)

        for m in self.matches:
            (_, match) = m
            head = match["head"][0]
            arg_list = match["arg_list"][0]
            self.analyse_clause_head(head, arg_list)
        
    def analyse_clause_head(self, head: Node, arg_list: Node):
        head_text = head.text.decode("utf-8")
        lines = head_text.splitlines()

        if all(len(line) <= self.max_length for line in lines):
            return

        refactored_head = self.refactor_clause_head(head_text, arg_list)

        self.add_clause_head_length_warning(head)
        self.add_clause_head_length_code_action(head, refactored_head)
    
    def refactor_clause_head(self, head_text: str, arg_list: Node) -> str:
        args = [ arg for arg in arg_list.children if arg.type != "arg_list_separator"]
        arg_names = [ arg.text.decode("utf-8") for arg in args ]

        refactored_head = head_text.split("(")[0] + "(\n" + self.indent
        current_line_length = len(refactored_head)
        for i, arg in enumerate(arg_names):
            arg_length = len(arg) + (2 if i < len(arg_names) - 1 else 0) # account for ", " after each argument except the last one
            if current_line_length + arg_length > self.max_length:
                refactored_head += "\n" + self.indent
                current_line_length = len(self.indent)
            refactored_head += arg
            current_line_length += arg_length
            if i < len(arg_names) - 1:
                refactored_head += ", "
                current_line_length += 2
        refactored_head += "\n)" 

        return refactored_head

    def add_clause_head_length_warning(self, node: Node):
        range = node_to_range(node)
        severity = types.DiagnosticSeverity.Hint
        message = "This clause has arguments that are too long. Consider refactoring to reduce the length of the clause head."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)
    
    def add_clause_head_length_code_action(self, node: Node, refactored_head: str):
        range = node_to_range(node)

        title = "Refactor clause head to reduce length"
        changes = {
            self.uri: [
                types.TextEdit(
                    range=range,
                    new_text=refactored_head
                )
            ]
        }

        action = types.CodeAction(
            title=title,
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(changes=changes)
        )

        self.add_file_action(RangedAction(action, range))