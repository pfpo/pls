import re

from tree_sitter import Node
from pls.utils import node_to_range, RangedAction
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
                        end = types.Position(definition.range.start.line, definition.range.start.character + len(predicate.name))
                    )
                    self.add_naming_convention_warning(predicate.name, None, "Predicate should be in snake_case", range)
                    self.add_naming_convention_code_action(predicate.name, None, "Predicate should be in snake_case", range, predicate=predicate)

    def build_visitors(self):
        self.add_visit("variable_term", self.visit_variable_term)
        self.set_default_visitor(self.visit_all_children)

    def visit_variable_term(self, node: Node):
        name = node.text.decode("utf-8")
        if name and not self.is_camel_case(name):
                variable = self.table.notes[node]
                self.add_naming_convention_warning(name, node, "Variable should be in camelCase")
                self.add_naming_convention_code_action(name, node, "Variable should be in camelCase", variable=variable)

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

    def add_naming_convention_code_action(self, name: str, node: Node, reason: str, range: types.Range = None, predicate=None, variable=None):
        range = range if range else node_to_range(node)

        title = f"Rename to follow naming convention"
        new_text = self.suggest_name(name, reason)
        changes = {}
        
        locations = []
        if predicate:
            locations = predicate.name_references
        elif variable:
            locations = variable.references
        else:
            locations = [types.Location(uri=self.uri, range=range)]

        for loc in locations:
            if loc.uri not in changes:
                changes[loc.uri] = []
            changes[loc.uri].append(types.TextEdit(range=loc.range, new_text=new_text))

        action = types.CodeAction(
            title=title,
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(changes=changes),
        )
        self.add_file_action(RangedAction(action, range))
    
    def suggest_name(self, name: str, reason: str) -> str:
        if "snake_case" in reason:
            name = re.sub(r'(?<!^)(?=[A-Z])', '_', name).lower()
            return re.sub(r'_{2,}', '_', name)
        elif "camelCase" in reason:
            components = name.split('_')
            return ''.join(x.title() for x in components[0:])
        else:
            return name

    def is_snake_case(self, name: str) -> bool:
        return re.match(r'^[a-z0-9]+(_[a-z0-9]+)*$', name) is not None

    def is_camel_case(self, name: str) -> bool:
        if name == "_":
            return True
        return re.match(r'^_?[A-Z][a-zA-Z0-9]*$', name) is not None