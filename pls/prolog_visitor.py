from tree_sitter import Node
from .model import Term, Functor, Predicate
from .utils import node_to_range
from .tree_visitor import TreeVisitor


class PrologVisitor(TreeVisitor):
    def __init__(self, current_uri):
        super().__init__()
        self.predicate_index = {}
        self.current_uri = current_uri

    def build_visitors(self):
        self.add_visit("source_file", self.visit_all_children)
        self.add_visit("clause_term", self.visit_clause_term)
        self.add_visit("directive_term", self.visit_directive)
        self.add_visit("atom", self.visit_atom)
        self.add_visit("functional_notation", self.visit_functional_notation)
        self.add_visit("operator_notation", self.visit_operator_notation)
        self.add_visit("integer", self.text_visit)
        self.add_visit("variable_term", self.visit_variable_term)

    def visit_atom(self, node: Node) -> str:
        assert node.type == "atom"
        return Term(bytes.decode(node.text, "utf-8"))

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
                return Functor(name.name, args)
            case x:
                raise TypeError(f"Invalid shape of argument list: {x}")
        return

    def visit_variable_term(self, node: Node):
        assert node.type == "variable_term"
        return self.text_visit(node)

    def visit_operator_notation(self, node: Node):
        assert node.type == "operator_notation"
        match node.children:
            case [head, _op, body]:
                head = self.visit(head)
                body = self.visit(body)
                return head
            case x:
                raise TypeError(f"Unhandeled operator notation:{x}")

    def visit_clause_term(self, parent: Node):
        node = parent.children[0]

        f = self.visit(node)
        arity = 0
        if type(f) is Functor:
            arity = len(f.args)
        predicate = Predicate(f.name, arity)
        predicate.definitions.append(node_to_range(parent))
        predicate.uri = self.current_uri
        key = predicate.key()
        if key in self.predicate_index:
            # TODO: check definition location
            self.predicate_index[key].append(predicate)
        else:
            self.predicate_index[key] = [predicate]
        return

    def visit_directive(self, node: Node):
        return
