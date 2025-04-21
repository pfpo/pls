from tree_sitter import Node
from .model import Predicate, Variable
from .annotations import Annotations


class Markup:

    def variable_description(self,element:Variable):
        return ["## Variable",element.name]
    def predicate_description(self,element:Predicate):
        res = [f"## Predicate:{element.name}"]
        res.extend(element.comments)
        return res
    def node_description(self,node:Node):
        return [f"## {node.type}",bytes.decode(node.text,"utf-8")]






descriptions = Markup()