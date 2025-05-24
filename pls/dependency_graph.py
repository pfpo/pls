from .utils import Path,add_paths,file_uri_to_path,path_to_file_uri
from dataclasses import dataclass

@dataclass
class File:
    uri : str
    name:str
    includes: dict[str,"File"]
    is_included: dict[str,"File"]


class DependencyGraph:
    def __init__(self):
        self.files : dict[str,File] = {}

    def clear_file_includes(self,file_name:str):
        file = self.get_file(file_name)
        for f in file.includes.values():
            f.is_included.pop(file.uri)
        file.includes =  {}
    def clear_file_is_included(self,file_name:str):
        file = self.get_file(file_name)
        for f in file.is_included.values():
            f.includes.pop(file.uri)
        file.includes =  {}
    
    def remove_file(self,file_name:str):
        self.clear_file_includes(file_name)
        self.clear_file_is_included(file_name)
        self.files.pop(file_name)

    def file_can_reach(self,source:str,destiny:str):
        queueu = [source]
        visited = set()
        while len(queueu) > 0:
            next = queueu.pop()
            file = self.get_file(next)

            for child in file.includes.keys():
                if child == destiny:
                    return True
                if child not in visited:
                    queueu.insert(0,child)
            
            visited.add(next)
        return False 

    def would_create_cycle(self,source:str,destiny:str):
        self.file_includes_other(source,destiny)
        creates_cycle = self.file_can_reach(source,source)
        self.remove_file(destiny)
        return creates_cycle
        
    def add_file(self,file_name:str):
        self.get_file(file_name)

    def file_includes_other(self,file_name:str,other_name: str):
        file = self.get_file(file_name)
        other = self.get_file(other_name)

        file.includes[other_name] = other
        other.is_included[file_name] = file

    def file_exists(self,uri:str):
        return file_uri_to_path(uri).exists()

    def get_files_to_analyse(self,uri:str):
        node_pool = set()
        in_degree : dict[str,int] = {}

        queue :list[File]= [self.get_file(uri)]
        while len(queue) > 0:
            next = queue.pop()
            node_pool.add(next.uri)
            in_degree[next.uri] = len(next.includes)
            neighbors :list[File] = []
            neighbors.extend(next.includes.values())
            neighbors.extend(next.is_included.values())
            for n in neighbors:
                if n.uri not in node_pool:
                    queue.append(n)

        print(node_pool)

        def next_node():
            for key,val in in_degree.items():
                if val == 0:
                    in_degree.pop(key)
                    return key
                

        result = []
        while len(node_pool) > 0:
            next = next_node()
            node_pool.remove(next)
            result.append(next)
            file = self.files[next]
            for key in file.is_included.keys():
                in_degree[key] -=1
        
        return result
            



    def get_file(self,uri:str) -> File:
        if uri not in self.files:
            self.files[uri] = File(uri=uri,name= file_uri_to_path(uri).name,includes={},is_included={})
        return self.files[uri]

    def __str__(self)->str:
        r = "Dependency Graph:\n"
        def file_dict_string(d : dict[str,File])-> str:
            return ",".join([f.name for f in d.values()])
        for _, file in self.files.items():
            r +=f"{file.name} "
            if len(file.includes) > 0:
                r += " includes: " + file_dict_string(file.includes)

            if len(file.is_included) > 0:
                r += " is included by: " + file_dict_string(file.is_included)
            r +='\n'

        return  r

