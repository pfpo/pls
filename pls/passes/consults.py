from tree_sitter import Node
from pls.model import Predicate, SymbolTable
from pls.utils import node_to_range, Path,path_to_file_uri,file_uri_to_path,add_paths
from pls.tree_visitor import TreeVisitor
from lsprotocol import types


class ConsultPaths():
    def __init__(self,uri:str,table: SymbolTable,all_tables:dict[str,SymbolTable]):
        self.uri = uri
        self.table = table
        self.reports = []
        self.all_tables = all_tables

    def add_missing_file_report(self,consult_path,r:types.Range):
        message = f"File Not Founed {consult_path}-> {add_paths(self.uri,consult_path)}"
        report = types.Diagnostic(
            message=message,
            severity = types.DiagnosticSeverity.Warning,
            range=r,
        )
        self.reports.append(report)

    def analyse(self):
        files_to_analyse = []
        for relative_path, ranges in self.table.consult_paths.items():
            uri = add_paths(self.uri,relative_path)
            if not file_uri_to_path(uri).exists():
                for r in ranges:
                    self.add_missing_file_report(relative_path,r)
            elif uri not in self.all_tables: 
                files_to_analyse.append(uri)
        return self.reports, files_to_analyse
                