from tree_sitter import Node
from lsprotocol import types
from pathlib import Path
from urllib.request import pathname2url, url2pathname
from urllib.parse import urlparse, unquote, urljoin
from dataclasses import dataclass
from importlib.resources import files

from collections import UserDict
from typing import TypeVar, Generic
from pygls.workspace import TextDocument

V = TypeVar("V")  # Value type


class FileVersionedDict(UserDict[str, tuple[int, V]], Generic[V]):
    def custom_method(self) -> str:
        return f"{len(self)} items in dict"

    def _add(self, uri: str, version: int, val: V):
        if uri not in self:
            self[uri] = (version, val)
        else:
            current_version, result = self[uri]
            if version != current_version:
                result = []
            result.extend(val)
            self[uri] = (version, result)

    def add_by_uri(self, uri: str, val: V):
        self._add(uri, 0, val)

    def add(self, document: TextDocument, val: V):
        self._add(document.uri, document.version, val)


@dataclass
class RangedAction:
    action: types.CodeAction
    range: types.Range


class MyDoc:
    def __init__(self, uri: str):
        self.uri = uri
        self.filename = ""
        self.source = ""
        self.version = 0
        with open(file_uri_to_path(self.uri)) as f:
            self.source = f.read()


def _left_after_right(left: types.Range, right: types.Range):
    return left.start.line > right.end.line or (
        left.start.line == right.end.line
        and left.start.character > right.end.character
        and left.start.character
    )


def ranges_overlap(left: types.Range, right: types.Range):
    left_is_after = _left_after_right(left, right)
    right_is_after = _left_after_right(right, left)

    return not (left_is_after or right_is_after)


def file_uri_to_path(uri: str) -> Path:
    parsed = urlparse(uri)
    return Path(url2pathname(unquote(parsed.path)))


def path_to_file_uri(path: Path) -> str:
    return urljoin("file:", pathname2url(str(path.resolve())))


def add_paths(file_uri: str, module_relative_path: str) -> str:
    file_path = file_uri_to_path(file_uri)
    final_path = file_path / ("../" + module_relative_path)
    return path_to_file_uri(final_path)


def builtins_path():
    file_path = files("pls.data.flavours.sicstus").joinpath("builtins.pl")
    return path_to_file_uri(file_path)


def library_path(module_name: str):
    file_path = files("pls.data.flavours.sicstus.libs").joinpath(f"{module_name}.pl")
    return path_to_file_uri(file_path)


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


def node_text(n):
    return bytes.decode(n.text, "utf-8")


def log_node(n):
    return f"{n}\n" + node_text(n)


def node_with_text(node: Node):
    s = f"Node:{log_node(node)}\n{node.start_point}\n"
    return s


def node_and_parent_with_text(node: Node):
    s = f"Node:{log_node(node)}\n{node.start_point}\n"

    if node.parent:
        s += f"\nParent:{log_node(node.parent)}"
    return s
