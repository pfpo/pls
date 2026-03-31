from tree_sitter import Node, QueryCursor
from lsprotocol import types
from pls.utils import node_to_range, contained_range, RangedAction
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
        self.matches = query_cursor.matches(root_node)


        for index, m in enumerate(self.matches):
            if self.check_wrapper_predicate(index):
                (_, match) = m
                wrapper_predicate = match["wrapper"][0]
                self.add_wrapper_predicate_warning(wrapper_predicate)
                self.add_wrapper_predicate_code_action(wrapper_predicate, index)

    def add_wrapper_predicate_warning(self, node: Node):
        range = node_to_range(node)
        severity = types.DiagnosticSeverity.Warning
        message = "Unecessary wrapper predicate."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)

    def add_wrapper_predicate_code_action(self, node: Node, index: int):
        range = node_to_range(node)
        (_, match) = self.matches[index]

        title = "Remove wrapper predicate and replace calls"
        changes = {}

        calling = match["calling"][0]    
        called = match["called"][0]

        calling_predicate = self.table.notes[calling]
        called_predicate = self.table.notes[called]

        locations = calling_predicate.name_references

        for loc in locations:
            if not contained_range(range, loc.range):
                if loc.uri not in changes:
                    changes[loc.uri] = []
                changes[loc.uri].append(types.TextEdit(
                    range=loc.range,
                    new_text=called_predicate.name
                ))
        
        changes[self.uri] = changes.get(self.uri, []) + [
            types.TextEdit(
                range=range,
                new_text=""
            )
        ]

        action = types.CodeAction(
            title=title,
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(changes=changes)
        )

        self.add_file_action(RangedAction(action, range))

    def check_wrapper_predicate(self, index: int) -> bool:
        (_, match) = self.matches[index]

        calling_arg = match["calling_arg"][0]
        calling_arg_list = [n for n in calling_arg.children if n.type != "arg_list_separator"]
        called_arg = match["called_arg"][0]
        called_arg_list = [n for n in called_arg.children if n.type != "arg_list_separator"]
        op = match["op"][0]

        if op.text.decode("utf-8") != ":-":
            return False

        if len(calling_arg_list) != len(called_arg_list):
            return False
        
        for c_arg, d_arg in zip(calling_arg_list, called_arg_list):
            if c_arg.type != d_arg.type or c_arg.text != d_arg.text:
                return False

        return True