import enum
import attrs
from pls.utils import node_and_parent_with_text
from pls.tree_visitor import TreeVisitor
from tree_sitter import Node
from pls.model import Variable, SymbolTable
from collections import defaultdict
from .highlight import Token




class PlDocHighlightVisitor(TreeVisitor):
    def __init__(self,current_token= None):
        super().__init__()
        self.token_list = []
        self.current_token = Token(0, 0, "") if current_token is None else current_token


    def start(self, node: Node):
        self.visit_all_children(node)

    def build_visitors(self):
        self.add_visit("ERROR", self.visit_all_children)

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

    def default_visit(self, node: Node):
        self.visit_all_children(node)


    def arg_spec(self, node: Node):
        fields = {"instantiation": (4,0), "name": (1,0), "type": (7,0)}
        for name in fields.keys():
            if field := node.child_by_field_name(name):
                self.create_token(field,*fields[name])
            


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
        self.create_token(tag_node,8,0)

        if n := node.child_by_field_name("name"):
            self.create_token(n,1,0)

        if n := node.child_by_field_name("description"):
            self.visit(n)




    def visit_normal_comment(self, node: Node):
        # TODO Find a better solution
        lines = max(node.end_point.row - node.start_point.row - 1, 0)
        if lines == 0:
            self.create_token(node, 6, 0)
            return

        # Multiline Comment
        start_line = node.start_point.row
        col = node.start_point.column
        text_per_lines = bytes.decode(node.text, "utf-8").split("\n")
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
    
    def create_token(self, node: Node, index: int, modifiers: int):
        line_offset = node.start_point.row - self.current_token.line
        col_offset = node.start_point.column
        if not node.start_point.row > self.current_token.line:
            col_offset -= self.current_token.offset

        self.current_token = Token(node.start_point.row, node.start_point.column, "")
        self.token_list.extend(
            [line_offset, col_offset, len(node.text), index, modifiers]
        )