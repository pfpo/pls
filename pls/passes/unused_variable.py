from tree_sitter import Node, Parser, Language
from pls.model import Term, Functor, Predicate, Variable, Scope,SymbolTable
from pls.utils import node_to_range, node_and_parent_with_text
from pls.tree_visitor import TreeVisitor
from pls.annotations import Annotations
from lsprotocol import types


class UnusedVariablePass(TreeVisitor):
    def __init__(self,table: SymbolTable):
        super().__init__()
        self.table = table
        self.reports = []


    def start(self, node: Node):
        self.visit_all_children(node)

    def build_visitors(self):
        self.add_visit("variable_term", self.visit_variable_term)
        self.set_default_visitor(self.visit_all_children)

    def visit_variable_term(self, node: Node):
        if self.table is None:
            return
        variable = self.table.notes[node]
        if variable is None or type(variable) is not Variable:
            return 
        if len(variable.references) == 1 and not variable.name.startswith('_'): 
            severity = types.DiagnosticSeverity.Warning
            message = "Unused Variable"
            report =  types.Diagnostic(
                message=message + " " + variable.name,
                severity=severity,
                range=node_to_range(node),
            )
            self.reports.append(report)

