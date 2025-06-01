from tree_sitter import Node
from lsprotocol import types
from pathlib import Path
from urllib.request import pathname2url
from urllib.parse import urlparse, unquote


def file_uri_to_path(uri: str) -> Path:
    parsed = urlparse(uri)
    return Path(unquote(parsed.path))


def path_to_file_uri(path: Path) -> str:
    return "file://" + pathname2url(str(path.resolve()))


def add_paths(file_uri: str, module_relative_path: str) -> str:
    file_path = file_uri_to_path(file_uri)
    final_path = file_path / ("../" + module_relative_path)
    return path_to_file_uri(final_path)


def library_path(module_name: str):
    return path_to_file_uri(
            Path(f"/home/martim/Desktop/pls/sicstus-doc-scraper/libs/{module_name}.pl").resolve()
        )

def node_to_range(node: Node):
    return types.Range(
        start=types.Position(
            line=node.start_point.row, character=node.start_point.column
        ),
        end=types.Position(line=node.end_point.row, character=node.end_point.column),
    )


def node_to_location(uri: str, node: Node):
    return types.Location(uri=uri, range=node_to_range(node))


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


def log_node(n):
    return f"{n}\n{bytes.decode(n.text, 'utf-8')}"


def node_with_text(node: Node):
    s = f"Node:{log_node(node)}\n{node.start_point}\n"
    return s


def node_and_parent_with_text(node: Node):
    s = f"Node:{log_node(node)}\n{node.start_point}\n"

    if node.parent:
        s += f"\nParent:{log_node(node.parent)}"
    return s
