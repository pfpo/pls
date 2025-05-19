from tree_sitter import Node
from .model import Predicate, Variable


class Markup:
    def variable_description(self, element: Variable):
        return ["## Variable", element.name]

    def predicate_description(self, element: Predicate):
        res = [f"## Predicate:{element.name}"]
        for c in element.comments:
            comment = c
            if type(c) is not str:
                comment = str(c)
            res.append(comment) 

        return res

    def node_description(self, node: Node):
        return [f"## {node.type}", bytes.decode(node.text, "utf-8")]


descriptions = Markup()
