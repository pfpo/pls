import re

from tree_sitter import Node
from pls.utils import node_to_range
from lsprotocol import types

from .analyser import TreeAnalyser, PrologAnalyseable


class NamingConventionsAnalysis(TreeAnalyser):
    def __init__(self):
        super().__init__()
        self.table = None

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        self.start(content.trees[self.uri][1].root_node)       
        for predicate in self.table.predicate_index.values():
            definition = predicate.definitions[0] if len(predicate.definitions) > 0 else None
            if definition and not self.is_snake_case(predicate.name):
                    range = types.Range(
                        start = definition.range.start,
                        end = definition.range.start
                    )
                    self.add_naming_convention_warning(predicate.name, None, "Predicate should be in snake_case", range)

    def build_visitors(self):
        self.add_visit("variable_term", self.visit_variable_term)
        self.set_default_visitor(self.visit_all_children)

    def visit_variable_term(self, node: Node):
        name = node.text.decode("utf-8")
        if name and not self.is_camel_case(name):
                self.add_naming_convention_warning(name, node, "Variable should be in camelCase")

    def add_naming_convention_warning(self, name: str, node: Node, reason: str, range: types.Range = None):
        range = range if range else node_to_range(node)
        severity = types.DiagnosticSeverity.Warning
        message = f"Naming convention violation: '{name}' - {reason}"
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)

    def is_snake_case(self, name: str) -> bool:
        return re.match(r'^[a-z]+(_[a-z]+)*$', name) is not None

    def is_camel_case(self, name: str) -> bool:
        if name == "_":
            return True
        return re.match(r'^_?[A-Z][a-zA-Z0-9]*$', name) is not None
        