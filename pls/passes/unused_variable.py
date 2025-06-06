from tree_sitter import Node
from pls.model import Variable, SymbolTable
from pls.utils import node_to_range, RangedAction
from pls.tree_visitor import TreeVisitor
from lsprotocol import types

from .analyser import  TreeAnalyser

class UnusedVariablePass(TreeAnalyser):
    def __init__(self):
        super().__init__()
        self.table = None

    def build_visitors(self):
        self.add_visit("variable_term", self.visit_variable_term)
        self.set_default_visitor(self.visit_all_children)

    def add_unused_variable_warning(self, variable: Variable, node: Node):
        severity = types.DiagnosticSeverity.Warning
        message = "Unused Variable"
        report = types.Diagnostic(
            message=message + " " + variable.name,
            severity=severity,
            range=node_to_range(node),
        )
        self.add_file_diagnostic(report)

    def add_code_actions(self, variable: Variable, node: Node):
        msg = f"Replace unused variable {variable.name} with "
        preserve_name = types.CodeAction(
            title=msg + f"_{variable.name}",
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(
                changes={
                    self.table.path: [
                        types.TextEdit(
                            range=variable.references[0].range,
                            new_text=f"_{variable.name}",
                        )
                    ]
                }
            ),
        )

        full_replace = types.CodeAction(
            title=msg + "_",
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(
                changes={
                    self.table.path: [
                        types.TextEdit(range=variable.references[0].range, new_text="_")
                    ]
                }
            ),
        )
        actions = (preserve_name, full_replace)
        r = node_to_range(node)
        ranged_actions = [RangedAction(a, r) for a in actions]
        for ranged_action in ranged_actions:
            self.add_file_action(ranged_action)

    def visit_variable_term(self, node: Node):
        if self.table is None:
            return
        variable = self.table.notes[node]
        if variable is None or type(variable) is not Variable:
            return
        if len(variable.references) == 1 and not variable.name.startswith("_"):
            self.add_unused_variable_warning(variable, node)
            self.add_code_actions(variable, node)
