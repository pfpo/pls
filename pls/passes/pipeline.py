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

    def passes(self) -> list[Analyser]:
        return [
            SyntaxErrorVisitor(),
            OperatorDeclarationAnalysis(),
            UndefinedPredicate(),
            UnusedVariablePass(),
            PredicateDefinition(),
            OperatorDisambiguationAnalysis(),
        ]

    def add_analysis_results(self, analyser: Analyser):
        for key, diagnostics in analyser.diagnostics.items():
            self.diagnostics[key].extend(diagnostics)

        for key, actions in analyser.actions.items():
            self.actions[key].extend(actions)

    def analyse(self, content: PrologAnalyseable):
        for analyser in self.passes():
            analyser.analyse(content)
            self.add_analysis_results(analyser)
