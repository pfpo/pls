from lsprotocol import types

from pls.dependency_graph import DependencyGraphManager
from .utils import node_to_location
from tree_sitter import Node, Tree
from dataclasses import dataclass
from .annotations import Annotations


class Term:
    def __init__(self, name):
        self.name: str = name
        self.arity = 0
        self.data = {}

    def key(self) -> str:
        if len(self.name) > 0 and not self.name[0].isalpha():
            name = f"({self.name})"
        else:
            name = self.name
        return f"{name}/{self.arity}"


class Predicate(Term):
    def __init__(self, name, arity):
        super().__init__(name)
        self.arity: int = arity
        self.definitions: list[types.Location] = []
        self.heads: list[Functor] = []
        self.clauses: list[Clause] = []
        self.uri = ""
        self.references: list[types.Location] = []
        self.name_references: list[types.Location] = []
        self.comments = []
        self.scopes: list["Scope"] = []
        self.operator = None
        self.defined_by_comment = False

    def add_reference(self, uri: str, node: Node):
        self.references.append(node_to_location(uri, node))

    def add_name_reference(self, uri: str, node: Node):
        self.name_references.append(node_to_location(uri, node))

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


@dataclass
class RangedTerm:
    term : Term
    _range : types.Range

class OperatorDeclaration:
    def __init__(self,functor: Functor,_range : types.Range):
        self.functor = functor
        self.precedence =functor.args[0]
        self.fixity = functor.args[1]
        self.name = functor.args[2]
        self.range = _range

def handle_fixity(fixity : str):
   # ["xf", "yf", "xfx", "xfy", "yfx", "fy", "fx"]
    if fixity in ["xf", "yf"]:
        arity = 1
        _type = "postfix"
    elif fixity in ["xfx", "xfy", "yfx"]:
        arity = 2
        _type = "infix"
    
    elif fixity in ["fy", "fx"]:
        arity = 1
        _type = "prefix"
    
    return _type, arity , "left"




class OperatorRepresentation(Term):
    def __init__(self,name:str,fixity:str,precedence:int):
        super().__init__(name)
        self.name = name
        self.fixity = fixity
        self.precedence = precedence
        self.type , self.arity, self.associativity = handle_fixity(fixity)

class Operator(Term):
    def __init__(self, predicate: Predicate,_type:str):
        super().__init__(predicate.name)
        self.arity = predicate.arity
        self.predicate = predicate
        self.type = _type


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


class Signature(Term):
    def __init__(self, name, arity, loc):
        super().__init__(name)
        self.arity = arity
        self.loc: types.Range = loc


@dataclass
class Module:
    uri: str
    name: str
    loc: types.Range
    is_library: bool


@dataclass
class ModuleDeclaration(Module):
    exported: list[Signature]


@dataclass
class UseModule(Module):
    imported: list[Signature] | None


@dataclass
class SymbolTable:
    scopes: dict[str, Scope]
    predicate_index: dict[str, Predicate]
    predicate_index_by_name: dict[str, set[str]]
    path: str
    notes: Annotations

    builtins: "SymbolTable"

    imports: dict["str", "SymbolTable"]
    imported_signatures: dict["str", set[str]]
    module_paths: dict[str, list[types.Location]]

    libs: set["str"]
    consults: dict["str", "SymbolTable"]
    consult_paths: dict[str, list[types.Location]]

    module_declarations: list[ModuleDeclaration]
    use_module_declarations: list[UseModule]

    exported_signatures: set[str]

    exportable_predicates: set[str]

    operator_declarations : list[OperatorDeclaration]

    def find_predicate_not_in_builtins(self, key: str):
        p = self.predicate_index.get(key)
        if p is not None and (len(p.definitions) > 0 or p.defined_by_comment):
            return p

        for table in self.consults.values():
            if consulted_predicate := table.find_predicate_not_in_builtins(key):
                return consulted_predicate

        for module_path, key_set in self.imported_signatures.items():
            if key in key_set:
                if imported_predicate := self.imports[
                    module_path
                ].find_predicate_not_in_builtins(key):
                    return imported_predicate
        return None

    def is_renameable(self, key: str):
        exportable = key in self.exportable_predicates
        if exportable:
            return True, ""

        builtin = self.builtins is not None and key in self.builtins.predicate_index

        if builtin:
            return False, f"{key} is a builtin predicate"

        imported = False

        for lib in self.libs:
            if lib not in self.imported_signatures:
                continue
            if key in self.imported_signatures[lib]:
                imported = True
                break

        if imported:
            return False, f"{key} is imported from a library"

        return True, ""

    def get_predicates_that_match(self, name: str) -> list[Predicate]:
        tables = [self]
        tables.extend(self.consults.values())

        available_keys = set()

        predicates = []
        for t in tables:
            available_keys.update(t.predicate_index_by_name.get(name, []))

        for key in available_keys:
            p = self.find_predicate_not_in_builtins(key)
            if p and len(p.definitions) > 0:
                predicates.append(p)

        if self.builtins:
            builtin_keys = set()
            builtin_keys.update(self.builtins.predicate_index_by_name.get(name, []))

            for key in builtin_keys:
                p = self.builtins.predicate_index[key]
                predicates.append(p)
        return predicates


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


def string_from_atom(atom_string: str) -> str:
    if len(atom_string) >= 2 and atom_string[0] == "'" and atom_string[-1] == "'":
        return atom_string[1:-1]
    return atom_string


@dataclass
class PrologAnalyseable:
    uri: str
    tables: dict[str, SymbolTable]
    trees: dict[str, Tree]
    dg: DependencyGraphManager
