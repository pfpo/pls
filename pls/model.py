from lsprotocol import types
from .utils import node_to_location
from tree_sitter import Node
from dataclasses import dataclass
from .annotations import Annotations
from .my_logging import logging


class Term:
    def __init__(self, name):
        self.name: str = name
        self.arity = 0
        self.data = {}

    def key(self) -> str:
        return f"{self.name}/{self.arity}"


class Predicate(Term):
    def __init__(self, name, arity):
        super().__init__(name)
        self.arity: int = arity
        self.definitions: list[types.Location] = []
        self.clauses: list[Clause] = []
        self.uri = ""
        self.references: list[types.Location] = []
        self.comments = []
        self.scopes: list["Scope"] = []

    def add_reference(self, uri: str, node: Node):
        self.references.append(node_to_location(uri, node))

    def add_definition(self, uri: str, node: Node):
        r = node_to_location(uri, node)
        self.definitions.append(r)
        # self.references.append(r)


class Clause(Term):
    def __init__(self, name, arity):
        super().__init__(name)
        self.arity: int = arity
        self.head = None
        self.body = None
        self.variables = None


class Functor(Term):
    def __init__(self, name, args):
        super().__init__(name)
        self.args: list = args
        self.arity = len(args)


class Operator(Term):
    def __init__(self, operator: str, operands: list[Term]):
        super().__init__(operator)
        self.operands = operands
        self.arity = len(operands)


class Variable(Term):
    def __init__(self, name, definition):
        super().__init__(name)
        self.arity = 0
        self.definition = definition
        self.references = []
        self.is_parameter = False
        self.scope: "Scope" = None


class Scope:
    def __init__(self):
        self.name = ""
        self.variables = {}
        self.predicate: None | "Predicate" = None
        # self.node = None


@dataclass
class SymbolTable:
    scopes: dict[str, Scope]
    predicate_index: dict[str, Predicate]
    path: str
    notes: Annotations
    builtins: "SymbolTable"
    imports: dict["str", "SymbolTable"]
    consults: dict["str", "SymbolTable"]
    consult_paths: dict[str, list[types.Location]]

    def find_predicate_not_in_builtins(self, predicate: Predicate):
        p = self.predicate_index.get(predicate.key())
        if p is not None and len(p.definitions) > 0:
            return p

        for table in self.consults.values():
            if consulted_predicate := table.find_predicate_not_in_builtins(predicate):
                return consulted_predicate
        return None


def scope_at_position(node: Node, table: SymbolTable, p: types.Position):
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
    note = table.notes[node]
    if note and (isinstance(note, Term) or type(note) is Scope):
        return note

    for child in node.children:
        possible = scope_at_position(child, table, p)
        if possible is not None:
            return possible
    return None
