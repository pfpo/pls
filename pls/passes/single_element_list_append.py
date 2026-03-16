from tree_sitter import Node
from lsprotocol import types
from pls.utils import node_to_range
from .analyser import TreeAnalyser, PrologAnalyseable

class SingleElementListAppendAnalysis(TreeAnalyser):
    def __init__(self):
        super().__init__()
        self.table = None

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        self.start(content.trees[self.uri][1].root_node)       

    def build_visitors(self):
        # self.add_visit("functional_notation", self.visit_functional_notation)
        self.set_default_visitor(self.visit_all_children)

    def visit_functional_notation(self, node: Node):
        if node.children[0].text.decode("utf-8") == "append":
            arg_list = node.children[2]
            arg_list = [child for child in arg_list.children if child.type not in ("comment", "arg_list_separator")]
            if len(arg_list.children) == 3:
                first_arg = arg_list[0]
                second_arg = arg_list[1]
                third_arg = arg_list[2]
                if first_arg.type == "list":
                    self.add_single_element_list_append_warning(node)

    def add_single_element_list_append_warning(self, node: Node):
        range = node_to_range(node)
        severity = types.DiagnosticSeverity.Warning
        message = "Appending a single element to a list can be more efficiently done using [Element|List] syntax."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)
