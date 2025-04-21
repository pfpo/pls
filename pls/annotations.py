from tree_sitter import Node


class Annotations:
    
    def __init__(self):
        self.data = {}

    def __getitem__(self,node :Node):
        key = self.key(node)
        if key in self.data:
            return self.data[key]
        return None

    def key(self,node: Node):
        return (node.start_byte,node.end_byte,node.type)
        
    def __setitem__(self,node:Node,item):
        self.data[self.key(node)] = item