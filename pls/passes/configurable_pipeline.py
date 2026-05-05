from .pipeline import Pipeline
from .naming_conventions import NamingConventionsAnalysis
from .single_element_list_append import SingleElementListAppendAnalysis
from .empy_list_append import EmptyListAppendAnalysis
from .nested_list_constructs import NestedListConstructsAnalysis
from .explicit_unification import ExplicitUnificationAnalysis
from .wrapper_predicates import WrapperPredicatesAppendsAnalysis
from .is_use import IsUseAnalysis
from .line_length import LineLengthAnalysis
from .indentation import IndentationConsistencyAnalysis
from .arg_list import ArgumentListAnalysis
from .too_many_arguments import TooManyArgumentsAnalysis
from .arg_pldoc import ArgumentPlDocAnalysis
from .clause_length import ClauseLengthAnalysis

class ConfigurablePipeline(Pipeline):
    def __init__(self, settings: dict = None):
        super().__init__()
        self.settings = settings or {}

    def passes(self) -> list[Pipeline]:
        passes = super().passes()

        config_passes = [
            ("naming_conventions", NamingConventionsAnalysis),
            ("single_element_list_append", SingleElementListAppendAnalysis),
            ("empty_list_append", EmptyListAppendAnalysis),
            ("nested_list_constructs", NestedListConstructsAnalysis),
            ("explicit_unification", ExplicitUnificationAnalysis),
            ("wrapper_predicates", WrapperPredicatesAppendsAnalysis),
            ("is_use", IsUseAnalysis),
            ("line_length", LineLengthAnalysis),
            ("indentation_consistency", IndentationConsistencyAnalysis),
            ("argument_list", ArgumentListAnalysis),
            ("too_many_arguments", TooManyArgumentsAnalysis),
            ("arg_pldoc", ArgumentPlDocAnalysis),
            ("clause_length", ClauseLengthAnalysis),
        ]

        for setting_key, pass_class in config_passes:
            if self.settings.get(setting_key, True):
                passes.append(pass_class())
        
        return passes