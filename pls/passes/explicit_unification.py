from tree_sitter import Node, QueryCursor
from pls.utils import node_to_range, RangedAction, contained_range
from lsprotocol import types

from .analyser import Analyser, PrologAnalyseable

class ExplicitUnificationAnalysis(Analyser):
    def __init__(self):
        super().__init__()
        self.table = None
        self.matches = None

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        root_node = content.trees[self.uri][1].root_node
        explicit_unification_query = content.queries["explicit_unification"]
        query_cursor = QueryCursor(explicit_unification_query)
        self.matches = query_cursor.matches(root_node)
        for index, m in enumerate(self.matches):
            (_, match) = m
            unify = match["unify"][0]
            self.add_unification_warning(unify)
            self.add_unification_code_action(unify, index)

    def add_unification_warning(self, node: Node):
        range = node_to_range(node)
        severity = types.DiagnosticSeverity.Warning
        message = "Explicit unification can be simplified to an implicit unification."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)

    def add_unification_code_action(self, node: Node, index: int):
        range = node_to_range(node)
        title = "Refactor explicit unification"

        # raise Exception(node.parent.text.decode("utf-8"))

        (_, match) = self.matches[index]
        other_term_text = match["term"][0].text.decode("utf-8")
        variable_term = match["variable_term"][0]
        variable = self.table.notes[variable_term]

        locations = [loc for loc in variable.references if not contained_range(range, loc.range)]
        changes = {}
        changes[self.uri] = [types.TextEdit(range=range, new_text="")]

        for loc in locations:
            if loc.uri not in changes:
                changes[loc.uri] = []
            #raise Exception(location.range)
            changes[loc.uri].append(types.TextEdit(range=loc.range, new_text=other_term_text))

        # raise Exception(changes)


        action = types.CodeAction(
            title=title,
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(changes=changes),
        )

        self.add_file_action(RangedAction(action, range))