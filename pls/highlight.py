import enum
import attrs
from .utils import node_and_parent_with_text
from .tree_visitor import TreeVisitor
from tree_sitter import Node
from .model import Variable, SymbolTable,Predicate,Term


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


TokenTypes = [
    "number",
    "variable",
    "parameter",
    "function",
    "operator",
    "string",
    "comment",
]


class HighlightVisitor(TreeVisitor):
    def __init__(self, symbol_table: SymbolTable):
        super().__init__()
        self.token_list = []
        self.current_token = Token(0, 0, "")
        self.notes = symbol_table.notes

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
        self.add_visit("functional_notation", self.visit_functional_notation)
        # self.add_visit("list_notation", self.visit_list_notation)

        # self.add_visit('ERROR',self.visit_all_children)
        self.add_visit("comment", self.visit_comment)

    def visit_integer(self, node: Node):
        self.create_token(node, 0, 0)

    def visit_double_quoted_list(self, node: Node):
        self.create_token(node, 5, 0)

    def visit_comment(self, node: Node):

        # TODO Find a better solution
        lines = max(node.end_point.row - node.start_point.row -1,0)
        if lines ==  0:
            self.create_token(node,6,0)    
            return 

        # Multiline Comment
        start_line = node.start_point.row
        col = node.start_point.column
        text_per_lines = bytes.decode(node.text,'utf-8').split('\n')
        for i in range(lines+2):
            current_row = start_line + i
            current_line_len = len(text_per_lines[i])

            line_offset = current_row  - self.current_token.line
            col_offset =  col
            if not current_row > self.current_token.line:
                col_offset -= self.current_token.offset

            self.current_token = Token(current_row, col, "")
            col = 0
            self.token_list.extend(
                [line_offset, col_offset,current_line_len ,6,0]
            )

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
        text = bytes.decode(node.text,'utf-8')
        # TODO: This is not totally correct because it should not be highlighted as strings
        if len(text) > 1 and text[0] == text[-1] and text[0] == '\'':
            self.create_token(node, 5, 0)
            return
            
    def visit_functional_notation(self, node: Node):

        children = [child for child in node.children if child.type != "comment"]
        match children:
            case [atom, _, arg_list, _]:
                for child in node.children:
                    if child.type == "comment" or child == arg_list:
                        self.visit(child)
                    elif child == atom:
                        self.create_token(child, 3, 0)
            case _:
                raise TypeError(
                    f"Invalid shape of argument list: {node.children}"+ node_and_parent_with_text(node)
                )

        return

    def visit_operator_notation(self, node: Node):

        children = [child for child in node.children if child.type != "comment"]
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
            case _:
                raise TypeError(f"Unhandeled operator notation:"+node_and_parent_with_text(node))

    def create_token(self, node: Node, index: int, modifiers: int):
        line_offset = node.start_point.row - self.current_token.line
        col_offset = node.start_point.column
        if not node.start_point.row > self.current_token.line:
            col_offset -= self.current_token.offset

        self.current_token = Token(node.start_point.row, node.start_point.column, "")
        self.token_list.extend(
            [line_offset, col_offset, len(node.text), index, modifiers]
        )
