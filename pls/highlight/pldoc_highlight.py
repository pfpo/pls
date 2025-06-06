from pls.tree_visitor import TreeVisitor
from tree_sitter import Node
from .highlight import Token
from dataclasses import dataclass
from pls.my_logging import logging


@dataclass
class Point:
    row: int
    column: int


@dataclass
class TsPoint:
    line: int
    character: int


@dataclass
class NodeLike:
    text: str
    start_point: None
    end_point: None


def node_with_offset(
    node: Node, text: str, where: bool = False, offset=None
) -> NodeLike:
    s = node.start_point
    e = node.end_point
    start = Point(s.row, s.column)
    end = Point(e.row, e.column)
    if not where:
        end = Point(s.row, s.column + len(text))
    else:
        start = Point(s.row, s.column + len(offset))
    return NodeLike(text, start, end)


@dataclass
class Range:
    start_point: Point
    end_point: Point


class PlDocHighlightVisitor(TreeVisitor):
    def __init__(self, current_token, current_node):
        super().__init__()
        self.token_list = []
        self.current_token = current_token
        self.start_token = Token(current_node.start_point.row, 0, "")
        self.ended = False

    def start(self, node: Node):
        self.default_visit(node)

    def build_visitors(self):
        self.add_visit("ERROR", self.end)
        self.add_visit("normal_comment", self.end)

        # Tags
        self.add_visit("pl_tag", self.visit_tag)

        self.set_default_visitor(self.default_visit)

        self.add_visit("pl_tag_text", self.visit_normal_comment)
        self.add_visit("prolog_style_description", self.visit_normal_comment)
        self.add_visit("%", self.visit_normal_comment)
        self.add_visit("comment_token", self.visit_normal_comment)
        self.add_visit("arg_spec", self.arg_spec)

        # Templates
        self.add_visit("functor_template", self.visit_functor)
        self.add_visit("operator_template", self.visit_functor)

    def end(self, node: Node):
        self.ended = True
        self.token_list = []
        return

    def default_visit(self, node: Node):
        for child in node.children:
            if self.ended:
                self.token_list = []
                break
            self.visit(child)

    def arg_name_isntantiation(self, node: Node):
        text = bytes.decode(node.text, "utf-8").strip()
        final = 0
        for i, c in enumerate(text):
            if c.isupper():
                final = i
                break

        operator = text[:final]
        op_node = node_with_offset(node, operator)
        self.create_token(op_node, 4, 0)

        parameter = text[final:]
        name_node = node_with_offset(node, parameter, True, operator)
        self.create_token(name_node, 1, 0)

    def arg_spec(self, node: Node):
        logging.error(f"{node.children}")
        fields = {"instantiation": (4, 0), "name": (1, 0), "type": (7, 0)}
        for child in node.children:
            if child.type == "arg_name_instantiation":
                self.arg_name_isntantiation(child)
        for name in fields.keys():
            if field := node.child_by_field_name(name):
                self.create_token(field, *fields[name])

    def visit_functor(self, node: Node):
        for child in node.named_children:
            if child.type == "functor":
                self.create_token(child, 3, 0)
            elif child.type == "arg_spec":
                self.visit(child)

    def pl_tag_text(self, node: Node) -> str:
        text = self.get_text(node)
        lines = text.split("\n")
        result = ""
        for line in lines:
            i = 1 if len(line) > 0 and line[0] == "%" else 0
            result += line[i:] + "\n"
        return result

    def get_text(self, node: Node) -> str:
        return bytes.decode(node.text, "utf-8")

    def visit_tag(self, node: Node):
        tag_node = node.children[0]
        self.create_token(tag_node, 8, 0)

        if n := node.child_by_field_name("name"):
            self.create_token(n, 1, 0)

        if n := node.child_by_field_name("description"):
            self.visit(n)

    def visit_normal_comment(self, original_node: Node):
        # TODO Find a better solution
        lines = max(original_node.end_point.row - original_node.start_point.row - 1, 0)
        if lines == 0:
            self.create_token(original_node, 6, 0)
            return

        # Multiline Comment
        node = self.relative_node_range(original_node)
        start_line = node.start_point.row
        col = node.start_point.column
        text_per_lines = bytes.decode(original_node.text, "utf-8").split("\n")
        for i in range(lines + 2):
            current_row = start_line + i
            current_line_len = len(text_per_lines[i])

            line_offset = current_row - self.current_token.line
            col_offset = col
            if not current_row > self.current_token.line:
                col_offset -= self.current_token.offset

            self.current_token = Token(current_row, col, "")
            col = 0
            self.token_list.extend([line_offset, col_offset, current_line_len, 6, 0])

    def visit_normal_and_consume_one_line(self, original_node: Node):
        self.visit_normal_comment(original_node)
        self.current_token.line -= 1

    def relative_node_range(self, node: Node):
        return Range(
            Point(
                node.start_point.row + self.start_token.line, node.start_point.column
            ),
            Point(node.end_point.row + self.start_token.line, node.end_point.column),
        )

    def create_token(self, original_node: Node, index: int, modifiers: int):
        node = self.relative_node_range(original_node)

        line_offset = node.start_point.row - self.current_token.line
        col_offset = node.start_point.column
        if not node.start_point.row > self.current_token.line:
            col_offset -= self.current_token.offset

        self.current_token = Token(node.start_point.row, node.start_point.column, "")
        self.token_list.extend(
            [line_offset, col_offset, len(original_node.text), index, modifiers]
        )
