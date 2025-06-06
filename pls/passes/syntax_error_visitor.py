from tree_sitter import Node
from lsprotocol import types

from pls.utils import node_to_range
from .analyser import TreeAnalyser


class SyntaxErrorVisitor(TreeAnalyser):
    def build_visitors(self):
        self.set_default_visitor(self.visit_errors)


    def handle_error_node(self, node: Node):
        severity = types.DiagnosticSeverity.Error
        message = "Syntax Error "
        self.add_file_diagnostic(types.Diagnostic(
            message=message + str(node),
            severity=severity,
            range=node_to_range(node),
        ))

    def handle_missing_node(self, node: Node):
        severity = types.DiagnosticSeverity.Error
        message = "Syntax Error "
        self.add_file_diagnostic(types.Diagnostic(
            message=message + str(node),
            severity=severity,
            range=node_to_range(node),
        ))

    def visit_errors(self, node: Node):
        may_contain_errors: list[Node] = [node]
        while len(may_contain_errors) > 0:
            node = may_contain_errors.pop()
            if node.is_error:
                self.handle_error_node(node)
            elif node.is_missing:
                self.handle_missing_node(node)
            elif node.has_error:
                for child in node.children:
                    may_contain_errors.append(child)
