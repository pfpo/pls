from lsprotocol import types
from pls.utils import file_uri_to_path
from .analyser import Analyser, PrologAnalyseable


class LineLengthAnalysis(Analyser):
    def __init__(self, settings: dict = None):
        super().__init__()
        self.settings = settings or {}
        self.max_length = self.settings.get("max_line_length", 80)

    def analyse(self, content : PrologAnalyseable):
        self.uri = content.uri
        if content.source:
            lines = content.source.splitlines()
        else:
            # fallback for when source is empty (shouldnt happen)
            file_path = file_uri_to_path(self.uri)
            with open(file_path, "r") as f:
                lines = f.readlines()

        for i, line in enumerate(lines):
            if len(line) > self.max_length:
                report = types.Diagnostic(
                    range=types.Range(
                        start=types.Position(line=i, character=0),
                        end=types.Position(line=i, character=len(line)),
                    ),
                    message=f"Line exceeds maximum length of {self.max_length} characters.",
                    severity=types.DiagnosticSeverity.Warning,
                )
                self.add_file_diagnostic(report)