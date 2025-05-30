from pls.model import SymbolTable
from pls.utils import add_paths
from pls.dependency_graph import DependencyGraphManager
from lsprotocol import types
from pls.my_logging import logging
from collections import defaultdict


class ConsultPaths:
    def __init__(self, all_tables: dict[str, SymbolTable], dg: DependencyGraphManager):
        self.cycle_reports: dict[str, list[types.Diagnostic]] = defaultdict(list)
        self.dg = dg
        self.all_tables = all_tables
        self.cycles = []

    def add_missing_file_report(self, uri, consult_path, l: types.Location):
        message = f"File Not Found {consult_path}-> {add_paths(uri, consult_path)}"
        report = types.Diagnostic(
            message=message,
            severity=types.DiagnosticSeverity.Warning,
            range=l.range,
        )
        return report

    def add_missing_file_report_for_use_module(self, uri, consult_path, l: types.Location):
        message = f"Consulted Module not Found {consult_path}-> {add_paths(uri, consult_path)}"
        report = types.Diagnostic(
            message=message,
            severity=types.DiagnosticSeverity.Warning,
            range=l.range,
        )
        return report

    def build_cyclic_consult_reports(self, cycle: list[str]):
        for i in range(0, len(cycle)):
            origin = cycle[i]
            destiny = cycle[(i + 1) % len(cycle)]
            if origin not in self.all_tables:
                continue
            table = self.all_tables[origin]
            for relative_path, locations in table.consult_paths.items():
                consult_uri = add_paths(origin, relative_path)
                if consult_uri != destiny:
                    continue
                for l in locations:
                    self.add_cyclic_consult_report(origin, relative_path, l, i, cycle)

    def add_cyclic_consult_report(
        self, uri: str, consult_path, l: types.Location, i: int, cycle: list[str]
    ):
        message = f"Cyclic **Imports**: {consult_path}\nHere is the Cycle:\n"
        for i in range(i, i + len(cycle)):
            s = self.dg.get_file(cycle[i % len(cycle)]).name
            d = self.dg.get_file(cycle[(i + 1) % len(cycle)]).name
            message += f"{s} -> {d}\n"
        report = types.Diagnostic(
            message=message,
            severity=types.DiagnosticSeverity.Error,
            range=l.range,
        )
        self.cycle_reports[uri].append(report)

    def analyse(self, uri: str):
        table = self.all_tables[uri]
        self.dg.clear_file_includes(uri)
        reports = []
        available_paths = set()
        for relative_path, locations in table.consult_paths.items():
            consult_uri = add_paths(uri, relative_path)
            if not self.dg.file_exists(consult_uri):
                for l in locations:
                    reports.append(self.add_missing_file_report(uri, relative_path, l))
            else:
                available_paths.add(consult_uri)
                self.dg.file_includes_other(uri, consult_uri)
        
        for module_uri, locations in table.module_paths.items():
            if not self.dg.file_exists(module_uri):
                for l in locations:
                    reports.append(self.add_missing_file_report_for_use_module(uri,module_uri, l))
            else:
                available_paths.add(module_uri)
                self.dg.file_uses_module(uri,module_uri)
        return reports, list(available_paths)
