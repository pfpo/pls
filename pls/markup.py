from tree_sitter import Node
from .model import Predicate, Variable

class Markup:
    def variable_description(self, element: Variable):
        return ["## Variable", element.name]

    def predicate_description(self, element: Predicate):

        string_comments = []
        other_comments = []
        for c in element.comments:
            if type(c) is str:
                string_comments.append(c)
            else:
                other_comments.append(c)
    
        res = [f"### Predicate: {element.key()}"]
        for c in element.comments:
            res.append(c.to_markdown())
        res.extend(string_comments)
        return res

    def node_description(self, node: Node):
        return [f"## {node.type}", bytes.decode(node.text, "utf-8")]


descriptions = Markup()
