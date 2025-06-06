from pls.utils import add_paths
from pls.dependency_graph import DependencyGraphManager
from lsprotocol import types

from .analyser import Analyser, PrologAnalyseable


class MissingPaths(Analyser):
    def __init__(self, dg: DependencyGraphManager):
        super().__init__()
        self.dg = dg
        self.all_tables = None

        self.available_paths = None

    def analyse(self, content: PrologAnalyseable):
        self.all_tables = content.tables

        self._analyse(content.uri)

    def add_missing_file_report(self, uri, consult_path, location: types.Location):
        message = f"File Not Found {consult_path}-> {add_paths(uri, consult_path)}"
        report = types.Diagnostic(
            message=message,
            severity=types.DiagnosticSeverity.Warning,
            range=location.range,
        )
        self.add_diagnostic(uri, report)

    def add_missing_file_report_for_use_module(
        self, uri, consult_path, location: types.Location
    ):
        message = f"Consulted Module not Found {consult_path}-> {add_paths(uri, consult_path)}"
        report = types.Diagnostic(
            message=message,
            severity=types.DiagnosticSeverity.Warning,
            range=location.range,
        )
        self.add_diagnostic(uri, report)

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
                for location in locations:
                    self.add_cyclic_consult_report(
                        origin, relative_path, location, i, cycle
                    )

    def add_cyclic_consult_report(
        self, uri: str, consult_path, location: types.Location, i: int, cycle: list[str]
    ):
        message = f"Cyclic **Imports**: {consult_path}\nHere is the Cycle:\n"
        for i in range(i, i + len(cycle)):
            s = self.dg.get_file(cycle[i % len(cycle)]).name
            d = self.dg.get_file(cycle[(i + 1) % len(cycle)]).name
            message += f"{s} -> {d}\n"
        report = types.Diagnostic(
            message=message,
            severity=types.DiagnosticSeverity.Error,
            range=location.range,
        )
        self.add_diagnostic(uri, report)

    def _analyse(self, uri: str):
        table = self.all_tables[uri]
        self.dg.clear_file_includes(uri)
        available_paths = set()
        for consult_uri, locations in table.consult_paths.items():
            if not self.dg.file_exists(consult_uri):
                for location in locations:
                    self.add_missing_file_report(uri, consult_uri, location)
            else:
                available_paths.add(consult_uri)
                self.dg.file_includes_other(uri, consult_uri)

        for module_uri, locations in table.module_paths.items():
            if not self.dg.file_exists(module_uri):
                for location in locations:
                    self.add_missing_file_report_for_use_module(
                        uri, module_uri, location
                    )
            else:
                available_paths.add(module_uri)
                self.dg.file_uses_module(uri, module_uri)
        self.available_paths = available_paths
