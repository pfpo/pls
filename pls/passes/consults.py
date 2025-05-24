from tree_sitter import Node
from pls.model import Predicate, SymbolTable
from pls.utils import node_to_range, Path,path_to_file_uri,file_uri_to_path,add_paths
from pls.dependency_graph import  DependencyGraph
from pls.tree_visitor import TreeVisitor
from lsprotocol import types


class ConsultPaths():
    def __init__(self,uri:str,table: SymbolTable,all_tables:dict[str,SymbolTable],dg:DependencyGraph):
        self.uri = uri
        self.table = table
        self.reports = []
        self.dg = dg
        self.dg.clear_file_includes(uri)
        self.all_tables = all_tables

    def add_missing_file_report(self,consult_path,l:types.Location):
        message = f"File Not Founed {consult_path}-> {add_paths(self.uri,consult_path)}"
        report = types.Diagnostic(
            message=message,
            severity = types.DiagnosticSeverity.Warning,
            range=l.range,
        )
        self.reports.append(report)

    def add_cyclic_consult_report(self,consult_path,l:types.Location):
        message = f"Cyclic Imports: {consult_path} -> {add_paths(self.uri,consult_path)}"
        report = types.Diagnostic(
            message=message,
            severity = types.DiagnosticSeverity.Warning,
            range=l.range,
        )
        self.reports.append(report)
    def analyse(self):
        for relative_path, locations in self.table.consult_paths.items():
            consult_uri = add_paths(self.uri,relative_path)
            if not self.dg.file_exists(consult_uri):
                for l in locations:
                    self.add_missing_file_report(relative_path,l)
                
            elif self.dg.would_create_cycle(self.uri,consult_uri):
                for l in locations:
                    self.add_cyclic_consult_report(relative_path,l)
            else: 
                self.dg.file_includes_other(self.uri,consult_uri)
        return self.reports
                