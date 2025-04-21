import enum
import attrs
from .tree_visitor import TreeVisitor
from tree_sitter import Node
from .annotations import Annotations
from .model import Variable


class TokenModifier(enum.IntFlag):
    deprecated = enum.auto()
    readonly = enum.auto()
    defaultLibrary = enum.auto()
    definition = enum.auto()


@attrs.define
class Token:
    line: int
    offset: int
    text: str

    tok_type: str = ""
    tok_modifiers: list[TokenModifier] = attrs.field(factory=list)


TokenTypes = ["number", "variable", "parameter", "function", "operator", "string","comment"]


class HighlightVisitor(TreeVisitor):
    def __init__(self, notes: Annotations):
        super().__init__()
        self.token_list = []
        self.current_token = Token(0, 0, "")
        self.notes = notes

    def build_visitors(self):
        self.set_default_visitor(self.visit_all_children)
        self.add_visit("integer", self.visit_integer)
        # self.add_visit("clause_term", self.visit_clause_term)
        # self.add_visit("directive_term", self.visit_directive)

        self.add_visit("variable_term", self.visit_variable_term)
        self.add_visit("atom", self.visit_atom)
        self.add_visit("operator_notation", self.visit_operator_notation)
        self.add_visit("double_quoted_list_notation", self.visit_double_quoted_list)

        # self.add_visit("source_file", self.visit_all_children)
        # self.add_visit("functional_notation", self.visit_functional_notation)
        # self.add_visit("list_notation", self.visit_list_notation)

        # self.add_visit('ERROR',self.visit_all_children)
        self.add_visit("comment", self.visit_comment)

    def visit_integer(self, node: Node):
        self.create_token(node, 0, 0)

    def visit_double_quoted_list(self, node: Node):
        self.create_token(node, 5, 0)

    def visit_comment(self, node: Node):
        self.create_token(node, 6, 0)

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
        self.create_token(node, 3, 0)

    def visit_operator_notation(self, node: Node):
        children = [child for child in node.children if child.type != "comment"]

        match children:
            case [open, operand, close] if (
                open.type == "open" and close.type == "close"
            ):
                for child in node.children:
                    if child.type == "comment" or child == operand:
                        self.visit(child)
            case [head, op, body]:

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
            case _:
                raise TypeError(f"Unhandeled operator notation:{node}")

    def create_token(self, node: Node, index: int, modifiers: int):
        line_offset = node.start_point.row - self.current_token.line
        col_offset = node.start_point.column
        if not node.start_point.row > self.current_token.line:
            col_offset -= self.current_token.offset

        self.current_token = Token(node.start_point.row, node.start_point.column, "")
        self.token_list.extend(
            [line_offset, col_offset, len(node.text), index, modifiers]
        )
