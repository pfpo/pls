from pls.utils import node_and_parent_with_text
from pls.tree_visitor import TreeVisitor
from tree_sitter import Node
from pls.model import Variable, SymbolTable
from collections import defaultdict
from .highlight import Token
from .pldoc_highlight import PlDocHighlightVisitor
from pls.my_logging import logging
from pls.annotations import Annotations


class HighlightVisitor(TreeVisitor):
    def __init__(self, symbol_table: SymbolTable, comment_trees: Annotations):
        super().__init__()
        self.token_list = []
        self.current_token = Token(0, 0, "")
        self.notes = (
            symbol_table.notes
            if symbol_table is not None
            else defaultdict(lambda: None)
        )
        self.comment_trees = comment_trees

    def build_visitors(self):
        self.set_default_visitor(self.visit_all_children)
        self.add_visit("integer", self.visit_integer)

        self.add_visit("variable_term", self.visit_variable_term)
        self.add_visit("atom", self.visit_atom)
        self.add_visit("operator_notation", self.visit_operator_notation)
        self.add_visit("double_quoted_list_notation", self.visit_double_quoted_list)

        self.add_visit("functional_notation", self.visit_functional_notation)
        self.add_visit("comment", self.visit_comment)

    def visit_integer(self, node: Node):
        self.create_token(node, 0, 0)

    def visit_double_quoted_list(self, node: Node):
        self.create_token(node, 5, 0)

    def visit_comment(self, node: Node):
        added_tokens = False
        comment_tree = self.comment_trees[node]
        token = None
        if comment_tree:
            v = PlDocHighlightVisitor(self.current_token, node)
            v.start(comment_tree.root_node)
            added_tokens = len(v.token_list) > 0
            token = v.current_token
            self.token_list.extend(v.token_list)
        if not added_tokens:
            self.visit_normal_comment(node)
        else:
            self.handle_normal_comment(node)
            self.current_token.line = token.line

    def visit_normal_comment(self, node: Node):
        self.token_list.extend(self.handle_normal_comment(node))

    def handle_normal_comment(self, node: Node):
        # TODO Find a better solution
        lines = max(node.end_point.row - node.start_point.row - 1, 0)
        if lines == 0:
            return self.token_values(node, 6, 0)

        # Multiline Comment
        start_line = node.start_point.row
        col = node.start_point.column
        text_per_lines = bytes.decode(node.text, "utf-8").split("\n")
        result = []
        for i in range(lines + 2):
            current_row = start_line + i
            current_line_len = len(text_per_lines[i])

            line_offset = current_row - self.current_token.line
            col_offset = col
            if not current_row > self.current_token.line:
                col_offset -= self.current_token.offset

            self.current_token = Token(current_row, col, "")
            col = 0
            result.extend([line_offset, col_offset, current_line_len, 6, 0])

        return result

    def visit_variable_term(self, node: Node):
        may_be_variable: Variable | None = self.notes[node]
        if may_be_variable is None:
            self.create_token(node, 1, 0)
            return
        variable: Variable = may_be_variable
        if variable.is_parameter:
            self.create_token(node, 2, 0)
            return
        self.create_token(node, 1, 0)
        return

    def visit_atom(self, node: Node):
        notes = self.notes[node]
        if notes is None:
            return
        text = bytes.decode(node.text, "utf-8")
        if len(text) > 1 and text[0] == text[-1] and text[0] == "'":
            self.create_token(node, 5, 0)
            return

    def visit_functional_notation(self, node: Node):
        children = self.filter_children(node)
        match children:
            case [atom, _, arg_list, _]:
                for child in node.children:
                    if child.type == "comment" or child == arg_list:
                        self.visit(child)
                    elif child == atom:
                        self.create_token(child, 3, 0)
            case _:
                self.visit_all_children(node)
                logging.debug(
                    TypeError(
                        f"Invalid shape of argument list: {node.children}"
                        + node_and_parent_with_text(node)
                    )
                )

        return


    def visit_operator_notation(self, node: Node):
        children = self.filter_children(node)
        match children:
            case [open, operand, close] if (
                open.type == "open" and close.type == "close"
            ):
                for child in node.children:
                    if child.type == "comment" or child == operand:
                        self.visit(child)
            case [_head, op, _body]:
                for child in node.children:
                    if child == op:
                        self.create_token(op, 4, 0)
                    self.visit(child)

            case [op, operand] if op.type == "prefix_operator":
                for child in node.children:
                    if child == op:
                        self.create_token(op, 4, 0)
                    self.visit(child)
                return operand
            case children:
                self.visit_all_children(node)
                logging.debug(
                    TypeError(
                        f"Unhandeled operator notation: \n{children}\n"
                        + node_and_parent_with_text(node)
                    )
                )

    def token_values(self, node: Node, index: int, modifiers: int):
        line_offset = node.start_point.row - self.current_token.line
        col_offset = node.start_point.column
        if not node.start_point.row > self.current_token.line:
            col_offset -= self.current_token.offset

        self.current_token = Token(node.start_point.row, node.start_point.column, "")
        return [line_offset, col_offset, len(node.text), index, modifiers]

    def create_token(self, node: Node, index: int, modifiers: int):
        self.token_list.extend(self.token_values(node, index, modifiers))
