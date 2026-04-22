from pls.utils import RangedAction
from lsprotocol import types
from .analyser import Analyser, PrologAnalyseable

class IndentationConsistencyAnalysis(Analyser):
    def __init__(self):
        super().__init__()
        self.table = None

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.source = content.source
        self.table = content.tables[self.uri]

        self.lines = self.source.splitlines()
        index_list = []
        for index, line in enumerate(self.lines):
            if "\t" in line:
                self.add_indentation_warning(index)
                index_list.append(index)
        
        if index_list.__len__() > 0:
            self.add_indentation_code_action(index_list)


    def add_indentation_warning(self, line_index: int):
        range = types.Range(
            start=types.Position(line_index, 0),
            end=types.Position(line_index, len(self.lines[line_index])),
        )
        severity = types.DiagnosticSeverity.Warning
        message = "Consider using spaces instead of tabs for indentation."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)

    def add_indentation_code_action(self, index_list: list[int]):
        title = "Convert tabs to spaces."

        changes = {}
        for line_index in index_list:
            line = self.lines[line_index]
            new_line = line.replace("\t", "    ")
            changes[self.table.path] = changes.get(self.table.path, []) + [
                types.TextEdit(
                    range=types.Range(
                        start=types.Position(line_index, 0),
                        end=types.Position(line_index, len(line)),
                    ),
                    new_text=new_line,
                )
            ]

        action = types.CodeAction(
            title=title,
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(
                changes=changes,
            ),
        )

        self.add_file_action(RangedAction(action, types.Range(
            start=types.Position(0, 0),
            end=types.Position(len(self.source.splitlines()), 0)
        )))