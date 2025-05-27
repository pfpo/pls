from tree_sitter import Node
from pls.model import Predicate, SymbolTable
from pls.utils import node_to_range
from pls.tree_visitor import TreeVisitor
from lsprotocol import types


class UndefinedPredicate(TreeVisitor):
    def __init__(self, table: SymbolTable):
        super().__init__()
        self.table = table
        self.reports = []

    def start(self, node: Node):
        self.visit_all_children(node)

    def build_visitors(self):
        self.add_visit("functional_notation", self.visit_functional_notation)
        self.set_default_visitor(self.visit_all_children)

    def is_undefined(self, predicate: Predicate) -> tuple[bool, Predicate]:
        if len(predicate.definitions) > 0:
            return False, predicate
        if self.table is None or self.table.builtins is None:
            return True, None

        if imported := self.table.find_predicate_not_in_builtins(predicate.key()):
            return False, imported

        if builtin_predicate := self.table.builtins.predicate_index.get(
            predicate.key()
        ):
            return False, builtin_predicate

        return True, None

    def visit_functional_notation(self, node: Node):
        if self.table is None:
            return
        may_be_old_predicate = self.table.notes[node]
        predicate = self.table.predicate_index[may_be_old_predicate.key()]
        if predicate is None or type(predicate) is not Predicate:
            return
        undefined, new_predicate = self.is_undefined(predicate)
        # logging.debug("%s Is Undefined: %s",predicate.key(),undefined)
        if undefined:
            severity = types.DiagnosticSeverity.Warning
            message = "Undefined Predicate "
            report = types.Diagnostic(
                message=message + " " + predicate.key(),
                severity=severity,
                range=node_to_range(node),
            )
            self.reports.append(report)
        elif predicate is not new_predicate:
            self.table.predicate_index
            new_predicate.references.extend(predicate.references)
            new_predicate.name_references.extend(predicate.name_references)
            self.table.notes[node] = new_predicate
            self.table.predicate_index[predicate.key()] = new_predicate
