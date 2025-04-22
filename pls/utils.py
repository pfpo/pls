from tree_sitter import Node
from lsprotocol import types


def node_to_range(node: Node):
    return types.Range(
        start=types.Position(
            line=node.start_point.row, character=node.start_point.column
        ),
        end=types.Position(line=node.end_point.row, character=node.end_point.column),
    )


def position_inside_node(node: Node, p: types.Position):
    in_row_between = node.start_point.row < p.line and node.end_point.row > p.line
    in_first_line = (
        node.start_point.row == p.line and node.start_point.column <= p.character
    )
    in_last_line = node.end_point.row == p.line and node.end_point.column >= p.character
    if (
        node.start_point.row == node.end_point.row and node.start_point.row == p.line
    ) and not (
        node.start_point.column <= p.character and node.end_point.column >= p.character
    ):
        return False

    return in_row_between or in_first_line or in_last_line


def node_at_position(node: Node, p: types.Position):
    in_row_between = node.start_point.row < p.line and node.end_point.row > p.line
    in_first_line = (
        node.start_point.row == p.line and node.start_point.column <= p.character
    )
    in_last_line = node.end_point.row == p.line and node.end_point.column >= p.character
    if (
        node.start_point.row == node.end_point.row and node.start_point.row == p.line
    ) and not (
        node.start_point.column <= p.character and node.end_point.column >= p.character
    ):
        return None
    contained = in_row_between or in_first_line or in_last_line
    if not contained:
        return None
    current = node
    for child in node.children:
        possible = node_at_position(child, p)
        if possible:
            current = possible
    return current


def node_and_parent_with_text(node:Node):
    log = lambda n : f"{n}\n{bytes.decode(n.text,'utf-8')}"
    s = f"Node:{log(node)}"
    if node.parent:
        s+=f"\nParent:{log(node.parent)}"
    return s
