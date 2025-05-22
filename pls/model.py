from lsprotocol import types
from .utils import node_to_range
from tree_sitter import Node
from dataclasses import dataclass
from .annotations import Annotations


class Term:
    def __init__(self, name):
        self.name: str = name
        self.arity = 0
        self.data = {}

    def key(self) -> str:
        return f"{self.name}/{self.arity}"


@dataclass
class SymbolTable:
    scopes: map
    predicate_index: map
    path: str
    notes: Annotations
    builtins: "SymbolTable"
    imports: list["SymbolTable"]
    consults: list["SymbolTable"]
    consult_paths : dict[str,list[types.Range]]


class Predicate(Term):
    def __init__(self, name, arity):
        super().__init__(name)
        self.arity: int = arity
        self.definitions: list[types.Range] = []
        self.clauses: list[Clause] = []
        self.uri = ""
        self.references = []
        self.comments = []
        self.scopes: list["Scope"] = []

    def add_reference(self, node: Node):
        self.references.append(node_to_range(node))

    def add_definition(self, node: Node):
        r = node_to_range(node)
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
        self.node = None
        self.predicate: None | "Predicate"
