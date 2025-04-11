from tree_sitter import Node
from .model import Term, Functor, Predicate, Variable
from .utils import node_to_range
from .tree_visitor import TreeVisitor


class Scope:
    def __init__(self):
        self.name = ""
        self.variables = {}
        self.node = None


class PrologVisitor(TreeVisitor):
    def __init__(self, current_uri):
        super().__init__()
        self.predicate_index = {}
        self.current_uri = current_uri

        self.current_scope = None
        self.scopes = {}
        self.directive_counter = 0

    def set_current_scope(self, scope):
        if self.current_scope is not None:
            self.save_scope()
        self.current_scope = scope

    def save_scope(self):
        self.scopes[self.current_scope.name] = self.current_scope

    def build_visitors(self):
        self.add_visit("source_file", self.visit_all_children)
        self.add_visit("clause_term", self.visit_clause_term)
        self.add_visit("directive_term", self.visit_directive)
        self.add_visit("atom", self.visit_atom)
        self.add_visit("functional_notation", self.visit_functional_notation)
        self.add_visit("operator_notation", self.visit_operator_notation)
        self.add_visit("integer", self.text_visit)
        self.add_visit("variable_term", self.visit_variable_term)
        self.add_visit("list_notation", self.visit_list_notation)

        self.add_visit("comment", self.visit_comment)

    def visit_atom(self, node: Node) -> str:
        assert node.type == "atom"
        t = Term(bytes.decode(node.text, "utf-8"))
        p = self.get_predicate(t)
        p.add_reference(node)
        return t

    def text_visit(self, node: Node) -> str:
        return Term(bytes.decode(node.text, "utf-8"))

    def visit_arg_list(self, node: Node):
        assert node.type == "arg_list"
        args = []
        for i in range(len(node.children)):
            if i % 2 == 0:
                args.append(node.children[i])
            else:
                assert node.children[i].type == "arg_list_separator"
        parsed_args = []
        for arg in args:
            parsed_args.append(self.visit(arg))
        return parsed_args

    def visit_functional_notation(self, node: Node):
        assert node.type == "functional_notation"
        match node.children:
            case [atom, _, arg_list, _]:
                name = self.visit_atom(atom)
                args = self.visit_arg_list(arg_list)
                f = Functor(name.name, args)
                p = self.get_predicate(f)
                p.add_reference(node)
                return f
            case x:
                raise TypeError(f"Invalid shape of argument list: {x}")
        return

    def visit_variable_term(self, node: Node):
        assert node.type == "variable_term"
        name = bytes.decode(node.text, "utf-8")
        if name not in self.current_scope.variables:
            v = Variable(bytes.decode(node.text, "utf-8"), self.current_scope)
            self.current_scope.variables[name] = v

        v = self.current_scope.variables[name]
        definition_range = node_to_range(node)
        v.references.append(definition_range)
        return v

    def visit_operator_notation(self, node: Node):
        assert node.type == "operator_notation"
        match node.children:
            case [head, _op, body]:
                head = self.visit(head)
                body = self.visit(body)
                return head
            case _:
                raise TypeError(f"Unhandeled operator notation:{node}")

    def visit_clause_term(self, parent: Node):
        self.new_scope(parent)

        node = parent.children[0]
        f = self.visit(node)
        predicate = self.get_predicate(f)
        predicate.add_definition(parent)
        predicate.uri = self.current_uri
        key = predicate.key()

        self.current_scope.name = f"{key}_{len(predicate.definitions)}"
        self.save_scope()
        return predicate

    def new_scope(self, node: Node):
        scope = None
        scope = Scope()
        if node.type == "directive_term":
            scope.name = f"__pls__directive_{self.directive_counter}"
            self.directive_counter += 1

        scope.node = node
        self.set_current_scope(scope)

    def visit_directive(self, node: Node):
        self.new_scope(node)
        self.save_scope()
        return

    def visit_list_notation(self, node: Node):
        if len(node.children) == 2:
            return
        list_items = node.children[1:-1]
        for item in list_items:
            if item.type != "list_notation_separator":
                self.visit(item)

    def visit_comment(self, node: Node):
        return

    def get_predicate(self, t: Term):
        key = t.key()
        if key not in self.predicate_index:
            self.predicate_index[key] = Predicate(t.name, t.arity)
        return self.predicate_index[key]
