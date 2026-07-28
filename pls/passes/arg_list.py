from tree_sitter import Node
from lsprotocol import types
from pls.utils import node_to_range, RangedAction
from pls.ts_query_compat import QueryCursor
from .analyser import Analyser, PrologAnalyseable

class ArgumentListAnalysis(Analyser):
    def __init__(self, settings: dict = {}):
        super().__init__()
        self.table = None
        self.matches = None
        self.indent_mode = settings.get("indentation", "spaces")
        self.indent = " " * settings.get("indentation_size", 4)

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

        # multiline -> intentional for readability
        if "\n" in text:
            return

        list_separator = [node for node in node.children if node.type == "arg_list_separator"] 
        list_separator_positions = [sep.start_byte - node.start_byte for sep in list_separator]

        if len(list_separator_positions) > 0:
            refactored_text = self.separate_argument_list(text, list_separator_positions)
            if text != refactored_text:
                self.add_argument_list_warning(node)
                self.add_argument_list_code_action(node, refactored_text)

    def add_argument_list_warning(self, node: Node):
        range = node_to_range(node)
        severity = types.DiagnosticSeverity.Warning
        message = "Use a consistent formatting for argument lists. Ensure there is one space after a comma."
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

    def flatten_argument_list(self, text: str) -> str:
        lines = text.splitlines()
        flattened_lines = [line.strip() for line in lines if line.strip()]
        return " ".join(flattened_lines)
    
    def separate_argument_list(self, text: str, positions: list) -> str:
        parts = []
        last_pos = 0
        for pos in positions:
            parts.append(text[last_pos:pos].strip())
            last_pos = pos + 1
        parts.append(text[last_pos:].strip())
        return ", ".join(parts)