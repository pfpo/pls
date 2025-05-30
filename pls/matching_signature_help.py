from tree_sitter import Node
from .my_logging import logging

class MT:
    def __init__(self,data,state=True):
        self.data = data
        self.state : bool = state
    @classmethod
    def invalid(cls):
        return MT(None,False)
    def condition(function):
        def inner(self,*args,**kwargs):
            if not self.state:
                return self.invalid()
            return function(self,*args,**kwargs)
        return inner
    @condition
    def prev_sibling(self) -> "MT":
        if not self.data.prev_sibling:
            return self.invalid()
        return MT(self.data.prev_sibling)
        
    @condition
    def type(self,type:str)-> "MT":
        if not self.data.type == type:
            return self.invalid()
        return self

    @condition
    def parent(self) -> "MT":
        if not self.data.parent:
            return self.invalid()
        return MT(self.data.parent)
        



def count_arguments(arglist):
    c = arglist.children
    for i in range(len(c)-1,-1,-1):
        if c[i].type == 'arg_list_separator' or  c[i].type == 'ERROR' and c[i].child(0).type == 'arg_list_separator' :
            return (i // 2) + 1
    return 0

def is_functional_notation(node):
    case = "(functional_notation function: (atom) (open) (arg_list(variable_term)) (ERROR(arg_list_separator(comma))) (close))"
    a = MT(node).type('close').parent().type('functional_notation')
    if a.state:
        logging.error(f"{case}")
        
    case = "functional_notation function: (atom) (open) (arg_list (variable_term) (arg_list_separator (comma)) (variable_term))"
    b = MT(node).type('comma').parent().type('arg_list_separator').parent().type('arg_list').parent().type('functional_notation')
    if b.state:
        logging.error(f"{case}")

    return a.state or b.state

def in_possible_signature_help( node:Node): 
    # logging.error(f"Testing if possible signature_help:")
    case = "(atom) (open)"
    if MT(node).type('open').prev_sibling().type('atom').state:
        # logging.error(f"{case}")
        predicate_name = bytes.decode(node.prev_sibling.text,'utf-8')
        return True,predicate_name,0
    
    if is_functional_notation(node):
        children = list(node.children)
        atom = children[0]
        arg_list = children[2]
        return True, bytes.decode(atom.text,'utf-8'), count_arguments(arg_list)
    case = "(atom) (open) (arg_list (variable_term) (arg_list_separator (comma)) (atom))"
    if MT(node).type('comma').parent().type('arg_list_separator').parent().type('arg_list').state:
        # logging.error(f"{case}")
        arg_list = node.parent.parent
        paren = arg_list.prev_sibling
        atom = paren.prev_sibling
        if paren.type == 'open' and atom.type =='atom':
            return True, bytes.decode(atom.text,'utf-8'), count_arguments(arg_list)
    case = "(atom) (open) (variable_term) (arg_list_separator (comma)))"
    if MT(node).type('comma').parent().type('arg_list_separator').prev_sibling().prev_sibling().type('open').prev_sibling().type('atom').state:
        # logging.error(f"{case}")
        atom = node.parent.prev_sibling.prev_sibling.prev_sibling
        return True, bytes.decode(atom.text,'utf-8'), 1

    # logging.error(f"Could Not discover predicate name nor current arg")
    return False,None,None