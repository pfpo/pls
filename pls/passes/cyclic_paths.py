from lsprotocol import types
from .analyser import Analyser, PrologAnalyseable


class CyclicPaths(Analyser):
    def __init__(self):
        super().__init__()

    def analyse(self, content: PrologAnalyseable):
        self.all_tables = content.tables
        self.dg = content.dg

        cycles = content.dg.get_cycles()
        # logging.error(f"CYCLES: {cycles}")

        for cycle in cycles:
            self.build_cyclic_consult_reports(cycle)

    def build_cyclic_consult_reports(self, cycle: list[str]):
        for i in range(0, len(cycle)):
            origin = cycle[i]
            destiny = cycle[(i + 1) % len(cycle)]
            if origin not in self.all_tables:
                continue
            table = self.all_tables[origin]
            for consult_uri, locations in table.consult_paths.items():
                if consult_uri != destiny:
                    continue
                for location in locations:
                    self.add_cyclic_consult_report(
                        origin, consult_uri, location, i, cycle
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
