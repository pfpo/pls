import enum
import attrs
from .tree_visitor import TreeVisitor
from tree_sitter import Node

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


# TokenTypes = ["keyword", "variable", "function", "operator", "parameter", "type"]
TokenTypes = ["number"]


class HighlightVisitor(TreeVisitor):
    def __init__(self):
        super().__init__()
        self.token_list = []
        self.current_token = Token(0,0,"")

    
    def build_visitors(self):
        self.add_visit("integer",self.visit_integer)
        self.set_default_visitor(self.visit_all_children)

    def visit_integer(self,node: Node):
        print(f"\n\n\nFound an integer token:{node},{node.text}")
        self.create_token(node,0,0)

    
    def create_token(self,node: Node,index: int,modifiers:int):

        line_offset = node.start_point.row - self.current_token.line
        col_offset = node.start_point.column 
        if not node.start_point.row > self.current_token.line:
            col_offset -= self.current_token.offset

        self.current_token = Token(node.start_point.row,node.start_point.column,"")
        self.token_list.extend([
                line_offset,
                col_offset,
                len(node.text),
                index,
                modifiers
        ])