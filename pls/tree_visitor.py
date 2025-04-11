from tree_sitter import Node
from abc import ABC


class TreeVisitor(ABC):
    def __init__(self):
        self.visit_map = {}
        self.default_visitor = None
        self.build_visitors()

    def build_visitors(self):
        pass

    def add_visit(self, node_type: str, f):
        self.visit_map[node_type] = f

    def set_default_visitor(self, f):
        self.default_visitor = f

    def visit_all_children(self, node: Node):
        for child in node.children:
            self.visit(child)

    def visit(self, node: Node):
        if node.type in self.visit_map:
            return self.visit_map[node.type](node)
        if self.default_visitor:
            return self.default_visitor(node)
        raise TypeError(
            f"There is no registered visitor for: {node.type}\n{node}{node.parent if node.parent else ''}"
        )
