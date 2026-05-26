from pls.utils import RangedAction
from lsprotocol import types
from .analyser import Analyser, PrologAnalyseable

class ClauseLengthAnalysis(Analyser):
    def __init__(self):
        super().__init__()
        self.table = None
        self.max_length = 24

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.source = content.source
        self.table = content.tables[self.uri]

        for predicate in self.table.predicate_index.values():
            for clause in predicate.definitions:
                start = clause.range.start
                end = clause.range.end
                length = end.line - start.line
                if length > self.max_length:
                    self.add_clause_length_warning(clause)

    def add_clause_length_warning(self, clause):
        range = clause.range
        severity = types.DiagnosticSeverity.Warning
        message = f"Consider refactoring this clause as it has more than {self.max_length} lines."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)