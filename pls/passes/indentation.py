from pls.utils import RangedAction
from lsprotocol import types
from .analyser import Analyser, PrologAnalyseable

class IndentationConsistencyAnalysis(Analyser):
    def __init__(self):
        super().__init__()
        self.table = None
        self.mode = "spaces"  # "tabs"
        self.spaces = 4

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.source = content.source
        self.table = content.tables[self.uri]

        self.lines = self.source.splitlines()
        index_list = []
        if self.mode == "spaces":
            for index, line in enumerate(self.lines):
                if "\t" in line:
                    self.add_indentation_warning_spaces(index)
                    index_list.append(index)
            
            if index_list.__len__() > 0:
                self.add_indentation_code_action_spaces(index_list)

        elif self.mode == "tabs":
            for index, line in enumerate(self.lines):
                if line.startswith(" " * self.spaces):
                    self.add_indentation_warning_tabs(index)
                    index_list.append(index)
            
            if index_list.__len__() > 0:
                self.add_indentation_code_action_tabs(index_list)

    def add_indentation_warning_spaces(self, line_index: int):
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

    def add_indentation_code_action_spaces(self, index_list: list[int]):
        title = "Convert tabs to spaces."

        changes = {}
        for line_index in index_list:
            line = self.lines[line_index]
            new_line = line.replace("\t", " " * self.spaces)
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
    
    def add_indentation_warning_tabs(self, line_index: int):
        range = types.Range(
            start=types.Position(line_index, 0),
            end=types.Position(line_index, len(self.lines[line_index])),
        )
        severity = types.DiagnosticSeverity.Warning
        message = "Consider using tabs instead of spaces for indentation."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)

    def add_indentation_code_action_tabs(self, index_list: list[int]):
        title = "Convert spaces to tabs."

        changes = {}
        for line_index in index_list:
            line = self.lines[line_index]
            new_line = line.replace(" " * self.spaces, "\t")
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