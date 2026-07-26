from .operator_disambiguation import OperatorDisambiguationAnalysis
from .unused_variable import UnusedVariablePass
from .predicate_definition import PredicateDefinition
from .undefined_predicate import UndefinedPredicate
from .analyser import Analyser, PrologAnalyseable
from .syntax_error_visitor import SyntaxErrorVisitor
from .operator_declaration import OperatorDeclarationAnalysis


class Pipeline(Analyser):
    def __init__(self):
        super().__init__()
        self.diagnostics_by_pass = {}  # Track diagnostics by pass name

    def passes(self) -> list[Analyser]:
        return [
            SyntaxErrorVisitor(),
            OperatorDeclarationAnalysis(),
            UndefinedPredicate(),
            UnusedVariablePass(),
            PredicateDefinition(),
            OperatorDisambiguationAnalysis(),
        ]

    def add_analysis_results(self, analyser: Analyser, pass_name: str = None):
        if pass_name is None:
            pass_name = analyser.__class__.__name__
        
        # Track diagnostics by pass name
        if pass_name not in self.diagnostics_by_pass:
            self.diagnostics_by_pass[pass_name] = {}
        
        for key, diagnostics in analyser.diagnostics.items():
            self.diagnostics[key].extend(diagnostics)
            
            if key not in self.diagnostics_by_pass[pass_name]:
                self.diagnostics_by_pass[pass_name][key] = []
            self.diagnostics_by_pass[pass_name][key].extend(diagnostics)

        for key, actions in analyser.actions.items():
            self.actions[key].extend(actions)

    def analyse(self, content: PrologAnalyseable):
        for analyser in self.passes():
            analyser.analyse(content)
            self.add_analysis_results(analyser)
