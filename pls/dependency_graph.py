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

    def add_file(self,file_name:str):
        self.get_file(file_name)

    def file_includes_other(self,file_name:str,other_name: str):
        file = self.get_file(file_name)
        other = self.get_file(other_name)

        file.includes[other_name] = other
        other.is_included[file_name] = file

    def file_exists(self,uri:str):
        return file_uri_to_path(uri).exists()


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

