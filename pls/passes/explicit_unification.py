from tree_sitter import Node, QueryCursor
from pls.utils import node_to_range, RangedAction, contained_range, join_ranges
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
            if not self.is_inside_or(unify):
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

        (_, match) = self.matches[index]
        variable_term = match["variable_term"][0]
        variable = self.table.notes[variable_term]

        changes = None
        if len(variable.references) == 2:
            changes = self.refactor_replace_all_references(node, index)
        elif len(variable.references) > 2:
            # if both are vars replace all refs
            # if other_term.type == "variable_term":
            changes = self.refactor_replace_all_references(node, index)
            # else extract term to a fact
            # self.refactor_to_fact()
        else:
            # singleton, cant refactor
            return

        action = types.CodeAction(
            title=title,
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(changes=changes),
        )

        self.add_file_action(RangedAction(action, range))

    def refactor_replace_all_references(self, node: Node, index):
        range = node_to_range(node)

        (_, match) = self.matches[index]
        other_term_text = match["term"][0].text.decode("utf-8")
        variable_term = match["variable_term"][0]
        variable = self.table.notes[variable_term]

        operator_notation = node.parent
        # raise Exception(operator_notation, operator_notation.children)
        operator = operator_notation.child_by_field_name("operator")
        operator_range = node_to_range(operator)
        new_range = join_ranges(range, operator_range)

        locations = [loc for loc in variable.references if not contained_range(new_range, loc.range)]
        changes = {}
        changes[self.uri] = [types.TextEdit(range=new_range, new_text="")]

        for loc in locations:
            if loc.uri not in changes:
                changes[loc.uri] = []
            changes[loc.uri].append(types.TextEdit(range=loc.range, new_text=other_term_text))

        return changes

    def refactor_to_fact(self, node: Node):
        return

    def is_inside_or(self, node: Node):
        parent = node.parent
        while parent is not None:
            if parent.type == "operator_notation":
                if parent.child_by_field_name("operator").text.decode("utf-8") == ";":
                    return True
            parent = parent.parent
        return False