from pls.model import  SymbolTable
from pls.utils import  add_paths
from pls.dependency_graph import  DependencyGraph
from lsprotocol import types
from pls.my_logging import logging
from collections import defaultdict


class ConsultPaths():
    def __init__(self,uri:str,table: SymbolTable,all_tables:dict[str,SymbolTable],dg:DependencyGraph):
        self.uri = uri
        self.table = table
        self.reports : dict[str,list[types.Diagnostic]] = defaultdict(list)
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
        self.reports[self.uri].append(report)

    def build_cyclic_consult_reports(self,cycle: list[str]):
        logging.debug(f"Cycle detected : {cycle}")
        for i in range(0,len(cycle)-1):
            origin = cycle[i]
            destiny = cycle[i+1]
            if origin not in self.all_tables:
                continue
            if origin == self.uri:
                table = self.table
            else:
                table = self.all_tables[origin]

            for relative_path, locations in table.consult_paths.items():
                consult_uri = add_paths(self.uri,relative_path)
                if consult_uri != destiny:
                    continue
                for l in locations:
                    self.add_cyclic_consult_report(origin,relative_path,l,i,cycle)


    def add_cyclic_consult_report(self,uri:str,consult_path,l:types.Location,i:int,cycle: list[str]):
        message = f"Cyclic **Imports**: {consult_path}\nHere is the Cycle:\n"
        def file_link(uri)->str:
            return uri
        for i in range(i,i+len(cycle)-1):
            s = cycle[i%len(cycle)]
            d = cycle[(i+1)%len(cycle)]
            message+=f"{file_link(s)} -> {file_link(d)}\n"
        logging.debug(f"{cycle}")
        report = types.Diagnostic(
            message=message,
            severity = types.DiagnosticSeverity.Error,
            range=l.range,
        )
        self.reports[uri].append(report)
    def analyse(self):
        for relative_path, locations in self.table.consult_paths.items():
            consult_uri = add_paths(self.uri,relative_path)
            if not self.dg.file_exists(consult_uri):
                for l in locations:
                    self.add_missing_file_report(relative_path,l)
            elif (result:= self.dg.would_create_cycle(self.uri,consult_uri))[0]:
                for l in locations:
                    self.build_cyclic_consult_reports(result[1])
            else: 
                self.dg.file_includes_other(self.uri,consult_uri)
        return self.reports
                