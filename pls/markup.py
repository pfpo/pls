from tree_sitter import Node
from .model import Predicate, Variable
from .annotations import Annotations


class Markup:

    def variable_description(self,element:Variable):
        return ["## Variable",element.name]
    def predicate_description(self,element:Predicate):
        return ["## Predicate", element.name]
    def node_description(self,node:Node):
        return [f"## {node.type}",bytes.decode(node.text,"utf-8")]






descriptions = Markup()