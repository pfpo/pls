from dataclasses import dataclass
from collections import defaultdict

from lsprotocol import types

from tree_sitter import Node, Parser, Language
import tree_sitter_pldoc as pldoc

from .model import (
    Signature,
    Term,
    Functor,
    Predicate,
    Variable,
    Scope,
    string_from_atom,
    ModuleDeclaration,
    UseModule,
)
from .utils import (
    node_to_location,
    node_and_parent_with_text,
    node_to_range,
    add_paths,
    library_path,
)
from .tree_visitor import TreeVisitor
from .annotations import Annotations
from .pldoc_comment_visitor import PlDocVisitor

from .my_logging import logging


@dataclass
class Opts:
    predicate_definition: bool = False
    started_predicate_definition: bool = False
    parameter_definition: bool = False


class PrologVisitor(TreeVisitor):
    def __init__(self, uri: str):
        super().__init__()
        self.predicate_index: dict[str, Predicate] = {}
        self.predicate_index_by_name: dict[str, set[str]] = {}
        self.uri = uri

        self.notes = Annotations()
        self.comment_trees = Annotations()
        self.current_scope = None
        self.scopes = {}
        self.directive_counter = 0

        self.consult_paths: dict[str, list[types.Location]] = defaultdict(list)
        self.comment_parser = Parser(Language(pldoc.language()))

        self.used_modules: list[UseModule] = []
        self.module_paths: dict[str, list[types.Location]] = defaultdict(list)
        self.module_declarations: list[ModuleDeclaration] = []
        self.libs = set()
        self.all_comments = []
        self.comments = []

        self.exportable_predicates: set[str] = set()

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
        self.add_visit("float_number", self.text_visit)
        self.add_visit("variable_term", self.visit_variable_term)
        self.add_visit("list_notation", self.visit_list_notation)
        self.add_visit("double_quoted_list_notation", self.text_visit)
        self.add_visit("|", self.visit_list_extend)
        self.add_visit("curly_bracketed_notation", self.curly_braces_visit)
        self.add_visit("binary_operator", self.visit_binary_operator)
        self.add_visit("comma", self.visit_binary_operator)
        self.add_visit("arg_list", self.visit_arg_list)

        ignore = ["open", "end", "comma", "arg_list_separator", "close","list_notation_separator","open_curly","close_curly","open_list","close_list"]
        for t in ignore:
            self.add_visit(t, self.ignore)
        # FOR Release
        self.set_default_visitor(self.log_no_registered_visitor_for)

        self.add_visit("ERROR", self.visit_all_children)
        self.add_visit("comment", self.visit_comment)

    def ignore(self, node: Node, _opts: Opts):
        return

    def visit_list_extend(self, node: Node, _opts: Opts):
        # TODO
        return

    def curly_braces_visit(self, node: Node, opts: Opts):
        children = self.filter_children(node)

        match children:
            case [brace_left, body, brace_right] if (
                brace_left.type == "open_curly" and brace_right.type == "close_curly"
            ):
                self.visit_all_children(node,opts)
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
                p.add_name_reference(self.uri, atom)
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

    def visit_operator_notation(self, node: Node, opts: Opts):
        assert node.type == "operator_notation"
        children = self.filter_children(node)
        operator_node = node.child_by_field_name("operator")
        arity = None
        to_return = None
        match children:
            case [open, operand, close] if (
                open.type == "open" and close.type == "close"
            ):
                to_return = self.visit(operand, opts)
            case [head, op, body]:
                arity = 2
                is_parameter_definition = self.is_parameter_start_point(opts, op)
                if is_parameter_definition:
                    opts = self.set_parameter_definition(opts)
                head = self.visit(head, opts)
                if is_parameter_definition:
                    opts = self.un_set_parameter_definitions(opts)
                body = self.visit(body, opts)
                to_return = head
            case [op, operand] if op == operator_node:
                operand = self.visit(operand, opts)
                arity = 1
                to_return = operand
            case [operand, op] if op == operator_node:
                operand = self.visit(operand, opts)
                arity = 1
                to_return = operand
            case _:
                self.visit_all_children(node, opts)
                # raise TypeError(
                #     f"Unhandeled operator notation:`{node.children}`\n"
                #     + node_and_parent_with_text(node)
                # )

        if arity is not None:
            t = Term(bytes.decode(operator_node.text, "utf-8"))
            t.arity = arity
            operator = self.get_predicate(t)
            operator.add_reference(self.uri, operator_node)
            self.notes[operator_node] = operator
        return to_return

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
        predicate.heads.append(f)
        predicate.comments.extend(self.comments.copy())
        self.comments = []
        self.notes[parent] = predicate

        predicate.add_definition(self.uri, parent)
        self.exportable_predicates.add(predicate.key())
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
            return functor.name == "use_module"

        def is_module(functor: Functor) -> bool:
            return functor.name == "module"

        for child in node.children:
            if child.type == "functional_notation":
                functor = self.visit(child, opts)
                if is_consult(functor):
                    self.handle_consult(child, functor)
                elif is_use_module(functor):
                    # TODO: Handle Modules
                    self.handle_use_module(child, functor)
                    pass
                elif is_module(functor):
                    self.handle_module_declaration(child, functor)
            else:
                self.visit(child, opts)
        self.notes[node] = self.current_scope
        self.save_scope()
        return

    def handle_consult(self, node: Node, functor: Functor):
        consult_path = string_from_atom(functor.args[0].name)
        functor.args[0].data["link"] = consult_path

        path = add_paths(self.uri, consult_path)
        self.consult_paths[path].append(node_to_location(self.uri, node))

    def handle_use_module(self, node: Node, functor: Functor):
        name = ""
        imported_predicates = None
        is_library = False
        if len(functor.args) >= 1:
            arg0 = functor.args[0]
            if type(arg0) is Functor and arg0.name == "library":
                if len(arg0.args) == 1 and type(arg0.args[0]) is Term:
                    is_library = True
                    name = string_from_atom(arg0.args[0].name)
            else:
                name = string_from_atom(functor.args[0].name)

        if len(functor.args) == 2:
            imported_predicates = functor.args[1]
            module_args = node.child(2)
            list_notation = module_args.child(2)
            imported_predicates = self.visit_signature_list(list_notation)

        path = None
        if is_library:
            path = library_path(name)
            self.libs.add(path)
        else:
            path_name = name
            if not name.endswith('.pl'):
                path_name = name + '.pl'
            path = add_paths(self.uri,path_name)

        self.module_paths[path].append(node_to_location(self.uri, node))

        m = UseModule(path, name, node_to_range(node), is_library, imported_predicates)
        self.used_modules.append(m)

    def visit_signature(self, node: Node) -> Signature:
        op = node.child_by_field_name("operator")
        
        if node.type != "operator_notation" and (op is None or op.text != b"/"):
            return None, False
        if not (
            node.child(0).type == "atom"
            and node.child(1).type == "binary_operator"
            and node.child(2).type == "integer"
        ):
            return None, False


            
        name_node = node.child(0)
        name = bytes.decode(node.child(0).text) 
        arity = int(bytes.decode(node.child(2).text))

        t = Term(name)
        t.arity = arity
        p = self.get_predicate(t)
        self.notes[node] = p
        p.add_reference(self.uri, node)
        p.add_name_reference(self.uri,name_node)
        # TODO Check if integer is less than zero
        return Signature(
            name,arity,
            node_to_range(node),
        ), True

    def visit_signature_list(self, node: Node) -> list[Signature]:
        children = list(node.children)
        children = children[1:-1]
        signatures = []
        for child in children:
            if child.type == "list_notation_separator":
                continue
            if child.type == "operator_notation":
                signature, succ = self.visit_signature(child)
                if succ:
                    # TODO add a reference to the predicate
                    signatures.append(signature)
                else:
                    logging.error("Could not add signature")
                    # TODO should deal with warnings
                    pass
        return signatures

    def handle_module_declaration(self, node: Node, functor: Functor):
        name = ""
        exported_predicates = []
        if len(functor.args) >= 1:
            name = string_from_atom(functor.args[0].name)
        if len(functor.args) == 2:
            module_args = node.child(2)
            list_notation = module_args.child(2)
            exported_predicates = self.visit_signature_list(list_notation)

        path_name = name
        if not name.endswith(".pl"):
            path_name = name + ".pl"
        m = ModuleDeclaration(
            add_paths(self.uri, path_name),
            name,
            node_to_range(node),
            False,
            exported_predicates,
        )
        self.module_declarations.append(m)

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
        added_pldoc_template = False
        if node.text.startswith(b'%! '):
            result = self.comment_parser.parse(node.text)
            self.comment_trees[node] = result
            v = PlDocVisitor()
            v.start(result.root_node)
            pldoc = v.get_comment()
            if len(pldoc.templates) > 0:
                added_pldoc_template = True
                for template in pldoc.templates:
                    predicate = self.get_predicate(template)
                    predicate.defined_by_comment = True
                    self.exportable_predicates.add(predicate.key())
                    predicate.comments.append(pldoc)
                    name_range = template.name_range
                    name_range.start.line += node.start_point.row
                    name_range.end.line += node.start_point.row
                    predicate.name_references.append(
                        types.Location(uri=self.uri, range=name_range),
                    )
        if not added_pldoc_template:
            self.comments.append(bytes.decode(node.text, "utf-8"))
        return

    def get_predicate(self, t: Term) -> Predicate:
        key = t.key()
        if key not in self.predicate_index:
            self.predicate_index[key] = Predicate(t.name, t.arity)
        if t.name not in self.predicate_index_by_name:
            self.predicate_index_by_name[t.name] = set()
        self.predicate_index_by_name[t.name].add(key)

        return self.predicate_index[key]
