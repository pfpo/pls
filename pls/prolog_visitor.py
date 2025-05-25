from tree_sitter import Node, Parser, Language
from .model import Term, Functor, Predicate, Variable, Scope
from .utils import node_to_location, node_and_parent_with_text
from .tree_visitor import TreeVisitor
from .annotations import Annotations
import tree_sitter_pldoc as pldoc
from dataclasses import dataclass
from lsprotocol import types
from collections import defaultdict
from .pldoc_comment_visitor import PlDocVisitor


@dataclass
class Opts:
    predicate_definition: bool = False
    started_predicate_definition: bool = False
    parameter_definition: bool = False


class PrologVisitor(TreeVisitor):
    def __init__(self, uri: str):
        super().__init__()
        self.predicate_index = {}
        self.uri = uri

        self.notes = Annotations()
        self.comment_trees = Annotations()
        self.current_scope = None
        self.scopes = {}
        self.directive_counter = 0

        self.consult_paths: dict[str, list[types.Location]] = defaultdict(list)
        self.comment_parser = Parser(Language(pldoc.language()))

        self.all_comments = []
        self.comments = []


    def set_current_scope(self, scope):
        if self.current_scope is not None:
            self.save_scope()
        self.current_scope = scope

    def save_scope(self):
        self.scopes[self.current_scope.name] = self.current_scope

    def start(self, node: Node, *args):
        self.visit_all_children(node, Opts())

    def build_visitors(self):
        self.add_visit("source_file", self.start)
        self.add_visit("clause_term", self.visit_clause_term)
        self.add_visit("directive_term", self.visit_directive)
        self.add_visit("directive_head", self.visit_directive)
        self.add_visit("atom", self.visit_atom)
        self.add_visit("functional_notation", self.visit_functional_notation)
        self.add_visit("operator_notation", self.visit_operator_notation)
        self.add_visit("integer", self.text_visit)
        self.add_visit("variable_term", self.visit_variable_term)
        self.add_visit("list_notation", self.visit_list_notation)
        self.add_visit("double_quoted_list_notation", self.text_visit)
        self.add_visit("|", self.visit_list_extend)
        self.add_visit("curly_bracketed_notation", self.curly_braces_visit)
        self.add_visit("binary_operator", self.visit_binary_operator)
        self.add_visit("comma", self.visit_binary_operator)
        self.add_visit("arg_list", self.visit_arg_list)

        ignore = ["open", "end"]
        for t in ignore:
            self.add_visit(t, self.ignore)

        self.add_visit("ERROR", self.visit_all_children)
        self.add_visit("comment", self.visit_comment)

    def ignore(self, node: Node, _opts: Opts):
        return

    def visit_list_extend(self, node: Node, _opts: Opts):
        # TODO
        return

    def curly_braces_visit(self, node: Node, opts: Opts):
        children = node.children
        match children:
            case [brace_left, body, brace_right] if (
                brace_left.type == "open_curly" and brace_right.type == "close_curly"
            ):
                self.visit(body, opts)
            case _:
                raise TypeError(
                    f"Invalid shape of curly brace notation: {node.children}"
                    + node_and_parent_with_text(node)
                )

    def visit_atom(self, node: Node, _opts: Opts) -> str:
        assert node.type == "atom"
        t = Term(bytes.decode(node.text, "utf-8"))
        self.notes[node] = t
        p = self.get_predicate(t)
        p.add_reference(self.uri, node)
        return t

    def visit_binary_operator(self, node: Node, _opts: Opts) -> str:
        t = Functor(bytes.decode(node.text, "utf-8"), [None, None])
        operator = self.get_predicate(t)
        self.notes[node] = operator
        p = self.get_predicate(operator)
        p.add_reference(self.uri, node)
        return operator

    def text_visit(self, node: Node, opts: Opts) -> str:
        res = Term(bytes.decode(node.text, "utf-8"))
        self.notes[node] = res
        return res

    def visit_arg_list(self, node: Node, opts: Opts):
        assert node.type == "arg_list"
        args = []
        for i in range(len(node.children)):
            if (
                node.children[i].type in ("comment", "arg_list_separator")
                or node.is_error
            ):
                continue
            else:
                args.append(node.children[i])
                # assert node.children[i].type "arg_list_separator",f"Child:\n{node.children[i].text},Parent:\n{bytes.decode(node.text,'utf-8')}"
        parsed_args = []
        for arg in args:
            parsed_args.append(self.visit(arg, opts))
        return parsed_args

    def visit_functional_notation(self, node: Node, opts: Opts):
        assert node.type == "functional_notation"
        children = self.filter_children(node)
        match children:
            case [atom, _, arg_list, _]:
                is_parameter_definition = self.functor_is_parameter_start_point(opts)
                if is_parameter_definition:
                    opts = self.set_parameter_definition(opts)
                name = self.visit_atom(atom, opts)
                args = self.visit_arg_list(arg_list, opts)
                f = Functor(name.name, args)
                p = self.get_predicate(f)
                self.notes[node] = p
                p.add_reference(self.uri, node)
                if is_parameter_definition:
                    opts = self.un_set_parameter_definitions(opts)
                return f
            case _:
                raise TypeError(
                    f"Invalid shape of argument list: {node.children}"
                    + node_and_parent_with_text(node)
                )

        return

    def visit_variable_term(self, node: Node, opts: Opts):
        assert node.type == "variable_term"
        name = bytes.decode(node.text, "utf-8")
        if name not in self.current_scope.variables:
            v = Variable(bytes.decode(node.text, "utf-8"), self.current_scope)
            v.scope = self.current_scope
            v.is_parameter = opts.parameter_definition
            self.current_scope.variables[name] = v

        v = self.current_scope.variables[name]
        self.notes[node] = v

        definition_loc = node_to_location(self.uri, node)
        v.references.append(definition_loc)
        return v

    def filter_children(self, node: Node):
        return [
            child for child in node.children if child.type not in ("comment", "ERROR")
        ]

    def visit_operator_notation(self, node: Node, opts: Opts):
        assert node.type == "operator_notation"
        children = self.filter_children(node)
        match children:
            case [open, operand, close] if (
                open.type == "open" and close.type == "close"
            ):
                operand = self.visit(operand, opts)
                return operand
            case [head, op, body]:
                is_parameter_definition = self.is_parameter_start_point(opts, op)
                if is_parameter_definition:
                    opts = self.set_parameter_definition(opts)
                head = self.visit(head, opts)
                if is_parameter_definition:
                    opts = self.un_set_parameter_definitions(opts)
                body = self.visit(body, opts)
                return head
            case [op, operand] if op.type == "prefix_operator":
                operand = self.visit(operand, opts)
                return operand
            case _:
                self.visit_all_children(node, opts)
                # raise TypeError(
                #     f"Unhandeled operator notation:`{node.children}`\n"
                #     + node_and_parent_with_text(node)
                # )

    def functor_is_parameter_start_point(self, opts: Opts):
        return opts.predicate_definition and not opts.started_predicate_definition

    def is_parameter_start_point(self, opts: Opts, op: Node):
        return (
            op.text == b":-"
            and opts.predicate_definition
            and not opts.started_predicate_definition
        )

    def set_parameter_definition(self, opts: Opts):
        opts.started_predicate_definition = True
        opts.parameter_definition = True
        return opts

    def un_set_parameter_definitions(self, opts: Opts):
        opts.parameter_definition = False
        return opts

    def visit_clause_term(self, parent: Node, opts: Opts):
        self.new_scope(parent)

        node = parent.children[0]
        opts.predicate_definition = True
        opts.started_predicate_definition = False
        f = self.visit(node, opts)

        predicate = self.get_predicate(f)
        predicate.comments.extend(self.comments.copy())
        self.comments = []
        self.notes[parent] = predicate

        predicate.add_definition(self.uri, parent)
        # TODO WHy
        predicate.uri = self.uri
        key = predicate.key()

        self.current_scope.name = f"{key}_{len(predicate.definitions)}"
        self.current_scope.predicate = predicate
        predicate.scopes.append(self.current_scope)

        self.save_scope()
        return predicate

    def new_scope(self, node: Node):
        scope = None
        scope = Scope()
        if node.type == "directive_term":
            scope.name = f"__pls__directive_{self.directive_counter}"
            self.directive_counter += 1

        # scope.node = node
        self.set_current_scope(scope)

    def visit_directive(self, node: Node, opts: Opts):
        self.new_scope(node)

        def is_consult(functor: Functor) -> bool:
            return functor.name == "consult" and len(functor.args) == 1

        def is_use_module(functor: Functor) -> bool:
            return False

        def string_from_atom(atom_string: str) -> str:
            if (
                len(atom_string) >= 2
                and atom_string[0] == "'"
                and atom_string[-1] == "'"
            ):
                return atom_string[1:-1]
            return atom_string

        for child in node.children:
            if child.type == "functional_notation":
                functor = self.visit(child, opts)
                if is_consult(functor):
                    consult_path = string_from_atom(functor.args[0].name)
                    functor.args[0].data["link"] = consult_path
                    self.consult_paths[consult_path].append(
                        node_to_location(self.uri, child)
                    )
                elif is_use_module(functor):
                    # TODO: Handle Modules
                    pass
            else:
                self.visit(child, opts)
        self.notes[node] = self.current_scope
        self.save_scope()
        return

    def visit_list_notation(self, node: Node, opts: Opts):
        if len(node.children) == 2:
            return
        list_items = node.children[1:-1]
        for item in list_items:
            # TODO If it is not list_notation_separator it may be |
            # It is weird it doesn't show up
            if item.type != "list_notation_separator":
                self.visit(item, opts)

    def visit_comment(self, node: Node, opts: Opts):
        # Detected cases where the parser hangs
        result = self.comment_parser.parse(node.text)
        self.comment_trees[node] = result
        v = PlDocVisitor()
        v.start(result.root_node)
        pldoc = v.get_comment()
        if pldoc:
            for template in pldoc.templates:
                predicate = self.get_predicate(template)
                predicate.comments.append(pldoc)
        else:
            self.comments.append(bytes.decode(node.text, "utf-8"))
        return

    def get_predicate(self, t: Term) -> Predicate:
        key = t.key()
        if key not in self.predicate_index:
            self.predicate_index[key] = Predicate(t.name, t.arity)
        return self.predicate_index[key]
