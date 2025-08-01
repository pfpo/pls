from tree_sitter import Node
from pls.model import Operator, OperatorRepresentation, Predicate
from pls.utils import node_to_range, node_with_text
from lsprotocol import types
from .analyser import TreeAnalyser
from pls.my_logging import logging

class UndefinedPredicate(TreeAnalyser):
    def __init__(self):
        super().__init__()
        self.table = None

    def start(self, node: Node):
        self.visit_all_children(node)

    def build_visitors(self):
        self.add_visit("functional_notation", self.visit_functional_notation)
        self.add_visit("operator_notation", self.visit_operator_notation)
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
        undefined, predicate = self.desambiguate(node)
        if undefined:
            severity = types.DiagnosticSeverity.Warning
            message = "Undefined Predicate "
            report = types.Diagnostic(
                message=message + " " + predicate.key(),
                severity=severity,
                range=node_to_range(node),
            )
            self.add_file_diagnostic(report)
        self.visit_all_children(node)

    def desambiguate(self, node: Node):
        may_be_old_predicate = self.table.notes[node]
        if may_be_old_predicate is None:
            return True, None
        predicate = self.table.predicate_index[may_be_old_predicate.key()]
        if predicate is None or type(predicate) is not Predicate:
            return True, None
        undefined, new_predicate = self.is_undefined(predicate)
        # logging.debug("%s Is Undefined: %s",predicate.key(),undefined)
        if undefined:
            return undefined, predicate
        else:
            if predicate is not new_predicate:
                new_predicate.references.extend(predicate.references)
                new_predicate.name_references.extend(predicate.name_references)
                self.table.predicate_index[predicate.key()] = new_predicate
            self.table.notes[node] = new_predicate
        return undefined, new_predicate

    def handle_annotated_node_op(self, node: Node):
        note = self.table.notes[node]
        if note is None:
            # Maybe error here?
            return
        if type(note) is not Operator:
            # TODO: Investigate why Some operators are not being annotated as Operators
            # logging.error(f"{node_with_text(node)} expected Operator Note but got: {type(note)}")
            return
        _type = note.type
        undefined, predicate = self.desambiguate(node)
        has_operator_definition = predicate and predicate.operator

        truly_undefined = not has_operator_definition and undefined
    
        
        if truly_undefined :
            # Warning There is not operator definition for predicate.name
            self.add_file_diagnostic(
                types.Diagnostic(
                    message=f"Undefined Operator: No operator definition found for '{getattr(predicate, 'name', '?')}' with type {_type}.",
                    severity=types.DiagnosticSeverity.Warning,
                    range=node_to_range(node),
                )
            )
            return
        if  not undefined and not has_operator_definition:
            # Warning There is not operator definition for predicate.name
            self.add_file_diagnostic(
                types.Diagnostic(
                    message=f"Undefined Operator: Predicate {predicate.key()} exists but there is no operator definition with type {_type}",
                    severity=types.DiagnosticSeverity.Warning,
                    range=node_to_range(node),
                )
            )
            return
        if has_operator_definition and undefined:
            severity = types.DiagnosticSeverity.Warning
            message = f"Undefined Operator: there is the respective op/3 definition but predicate {note.key()} not found"
            report = types.Diagnostic(
                message=message,
                severity=severity,
                range=node_to_range(node),
            )
            self.add_file_diagnostic(report)
            return
        if predicate is None or predicate.operator is None:
            return
        op_rep: OperatorRepresentation = predicate.operator
        if op_rep.type != _type:
            # Warning operator with op_rep.type is being used as maybe_old_predicate.type
            # print there is no operator with that fixity the operator available is
            available_fixity = op_rep.type
            expected_fixity = _type
            self.add_file_diagnostic(
                types.Diagnostic(
                    message=(
                        f"Operator fixity mismatch for {op_rep.key()} expected '{expected_fixity}' but got '{available_fixity}'. "
                        f"No operator declared with fixity '{expected_fixity}'; available is '{available_fixity}'."
                    ),
                    severity=types.DiagnosticSeverity.Warning,
                    range=node_to_range(node),
                )
            )
            return

    def visit_operator_notation(self, node: Node):
        assert node.type == "operator_notation"
        operator = node.child_by_field_name("operator")
        self.handle_annotated_node_op(node)
        for child in node.children:
            if child == operator:
                self.desambiguate(child)
            else:
                self.visit(child)
