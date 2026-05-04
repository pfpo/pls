from tree_sitter import Node
from lsprotocol import types
from pls.model import Predicate
from pls.pldoc_comment_visitor import PlDocComment
from pls.utils import node_to_range, RangedAction
from .analyser import Analyser, PrologAnalyseable

class ArgumentPlDocAnalysis(Analyser):
    def __init__(self):
        super().__init__()
        self.table = None
        self.matches = None
    
    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        self.tree = content.trees[self.uri][1]

        for key, predicate in self.table.predicate_index.items():
            for comment in predicate.comments:
                if type(comment) is PlDocComment:
                    self.analyse_pldoc_comment(predicate, comment)
                    pass

    # checks if the arguments of the predicate match in name and order with the arguments in the pldoc comment, if not, a warning is added
    def analyse_pldoc_comment(self, predicate: Predicate, comment: PlDocComment):
        for template in comment.templates:
            if template.arity == predicate.arity:
                for i in range(template.arity):
                    if len(predicate.heads) == 0:
                        return
                    if template.args[i].name != predicate.heads[0].args[i].name:
                        self.add_argument_mismatch_warning(predicate, template)
        return
    
    def add_argument_mismatch_warning(self, predicate: Predicate, template: PlDocComment):
        range = types.Range(
            start=predicate.definitions[0].range.start,
            end=predicate.definitions[0].range.end,
        )
        severity = types.DiagnosticSeverity.Warning
        message = f"The argument names in the PlDoc comment do not match the argument names in the predicate {predicate.name}"
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)
