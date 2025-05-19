from tree_sitter import Node,Parser,Language
from .model import Term, Functor, Predicate, Variable, Scope
from .utils import node_to_range,node_and_parent_with_text,node_with_text
from .tree_visitor import TreeVisitor
from .annotations import Annotations
import tree_sitter_pldoc  as pldoc
from dataclasses import dataclass
import logging



@dataclass
class Tag:
    type: str
    name: str | None
    value: str | None

    def __str__(self)-> str:
        return rf"@{self.type} {self.name} {self.value}"

@dataclass
class PlDocComment:
    
    description: str
    tags : list[Tag]

    def __str__(self)-> str:
        r = f"Desc: {self.description}\n"
        for t in self.tags:
            r+=  str(t)
        return r 
    

class PlDocVisitor(TreeVisitor):
    def __init__(self):
        super().__init__()
        self.tags = []
        self.description = ""
    
    def get_comment(self):
        return PlDocComment(tags=self.tags,description=self.description)

    def start(self, node: Node):
        self.visit_all_children(node)

    def build_visitors(self):
        self.add_visit("ERROR", self.visit_all_children)

        # Tags
        self.add_visit("pl_tag",self.visit_tag)

        self.set_default_visitor(self.default_visit)


        self.add_visit("pl_tag_text",self.pl_tag_text)
        self.add_visit("prolog_style_description",self.visit_description)
    def default_visit(self,node:Node):
        # print(node_with_text(node))
        self.visit_all_children(node)

    def visit_description(self,node:Node):
        # print(node_with_text(node))
        text = self.pl_tag_text(node)
        self.description = text
    def pl_tag_text(self,node:Node)-> str:
        text = self.get_text(node)
        lines = text.split('\n')
        result = ""
        for l in lines:
            
            i = 1 if len(l) > 0 and l[0] == '%'  else 0
            result += l[i:] + '\n'
        return result 

    def get_text(self,node:Node)->str:
        return bytes.decode(node.text,'utf-8')
    
    def visit_tag(self,node: Node)-> Tag:
        tag_type = node.children[0].type[1:]
        #print(node.text)
        desc = self.visit(node.child_by_field_name("description"))
        name = (node.child_by_field_name("name"))
        print(node.named_children)
        #if desc:
            #print("desc:",desc)
        #if name:
            #print("Name:",self.get_text(name))
        print(tag_type)
        self.tags.append(Tag(type=tag_type,name=name,value=desc))




