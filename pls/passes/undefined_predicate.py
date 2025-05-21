from tree_sitter import Node, Parser, Language
from pls.model import Term, Functor, Predicate, Variable, Scope,SymbolTable
from pls.utils import node_to_range, node_and_parent_with_text
from pls.tree_visitor import TreeVisitor
from pls.annotations import Annotations
from lsprotocol import types


class UndefinedPredicate(TreeVisitor):
    def __init__(self,table: SymbolTable):
        super().__init__()
        self.table = table
        self.reports = []


    def start(self, node: Node):
        self.visit_all_children(node)

    def build_visitors(self):
        self.add_visit("functional_notation", self.visit_functional_notation)
        self.set_default_visitor(self.visit_all_children)

    def is_undefined(self, predicate:Predicate)-> bool:
        if len(predicate.definitions) > 0:
            return False
        if self.table is None or self.table.builtins is None:
            return True
        
        if self.table.builtins.predicate_index.get(predicate.key()):
            return False
        return True

    def visit_functional_notation(self, node: Node):
        if self.table is None:
            return
        predicate = self.table.notes[node]
        if  predicate is None or type(predicate) is not Predicate:
            return 
        if self.is_undefined(predicate):
            severity = types.DiagnosticSeverity.Warning
            message = "Undefined Predicate "
            report =  types.Diagnostic(
                message= message + " " +  predicate.key(),
                severity=severity,
                range=node_to_range(node),
            )
            self.reports.append(report)