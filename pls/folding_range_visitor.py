from dataclasses import dataclass

from lsprotocol import types

from tree_sitter import Node

from .utils import (
    node_and_parent_with_text,
    node_to_range,
    node_with_text,
)
from .tree_visitor import TreeVisitor

from .my_logging import logging


@dataclass
class Opts:
    predicate_definition: bool = False
    started_predicate_definition: bool = False
    parameter_definition: bool = False


class FoldingRangeVisitor(TreeVisitor):
    def __init__(self, node: Node):
        super().__init__()
        self.node: Node = node
        self.result = []

    def start(self):
        self.visit_all_children(self.node)
        return self.result

    def build_visitors(self):
        self.add_visit("comment", self.visit_comment)

        self.add_visit("clause_term", self.fold_node)
        self.add_visit("directive_term", self.fold_node)

        self.set_default_visitor(self.visit_all_children)



    def add_folding_start_end(self, start: Node, end: Node, text=None):
        s = node_to_range(start)
        e = node_to_range(end)

        f = types.FoldingRange(
            s.start.line,
            e.end.line,
            s.start.character,
            e.end.character,
            collapsed_text="Lara",
        )
        self.result.append(f)

    def add_folding_range(self, node: Node, sub=False):
        r = node_to_range(node)

        end_line = r.end.line
        if sub and end_line > r.start.line:
            end_line -= 1
        f = types.FoldingRange(
            r.start.line,
            end_line,
            r.start.character,
            r.end.character,
            collapsed_text="Lara",
        )
        self.result.append(f)

    def fold_node(self, node: Node):
        self.add_folding_range(node)


    def visit_comment(self, node: Node):
        self.add_folding_range(node, sub=True)
