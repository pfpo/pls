from tree_sitter import Node, QueryCursor
from pls.utils import node_to_range, RangedAction
from lsprotocol import types

from .analyser import Analyser, PrologAnalyseable

ARITHMETIC_OPERATORS = {"+", "-", "*", "/", "//", "div", "rem", "mod", "/\\", " \\/", "\\", "<<", ">>", "**", "^"}
ARITHMETIC_FUNCTIONS = {"integer", "float_integer_part", "float_fractional_part", "float", 
                        "xor", "abs", "sign", "gdc", "min", "max", "msb", "round", "truncate",
                        "floor", "ceiling", "sin", "cos", "tan", "cot",  "sinh", "cosh","tanh", "coth",  
                        "asin", "acos", "atan", "atan2", "acot", "acot2", "asinh", "acosh", "atanh", "acoth",
                        "sqrt", "log", "exp"}
ARITHMETIC_CONSTANTS = {"pi"}

class IsUseAnalysis(Analyser):
    def __init__(self):
        super().__init__()
        self.table = None
        self.matches = None

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        root_node = content.trees[self.uri][1].root_node
        is_use_query = content.queries["is_use"]
        query_cursor = QueryCursor(is_use_query)
        self.matches = query_cursor.matches(root_node)
        for index, m in enumerate(self.matches):
            (_, match) = m
            is_term = match["is_use"][0]
            if not self.correct_is_use(index):
                self.add_is_use_warning(is_term)

    def add_is_use_warning(self, node: Node):
        range = node_to_range(node)
        severity = types.DiagnosticSeverity.Warning
        message = "The 'is' operator should only be used for arithmetic evaluation."
        report = types.Diagnostic(
            message=message,
            severity=severity,
            range=range,
        )
        self.add_file_diagnostic(report)
    
    def correct_is_use(self, index: int) -> bool:
        (_, match) = self.matches[index]
        left = match["left"][0]
        right = match["right"][0]

        if left.type != "variable_term":
            return False

        if not self.is_arithmetic_expression(right, True):
            return False
        
        return True

    # first flag indicates if its first call
    def is_arithmetic_expression(self, node: Node, first = False) -> bool:
        if node.type == "operator_notation":
            operator = node.child_by_field_name("operator")
            if operator is None:
                return self.is_arithmetic_expression(node.children[1], first)
            operator_text = operator.text.decode("utf-8")
            if operator_text not in ARITHMETIC_OPERATORS:
                return False
            left = node.children[0]
            right = node.children[2]
            return self.is_arithmetic_expression(left) and self.is_arithmetic_expression(right)
            

        if node.type == "functional_notation":
            function = node.child_by_field_name("function")
            function_text = function.text.decode("utf-8")
            if function_text not in ARITHMETIC_FUNCTIONS:
                return False
            # could check arguments, but would fall on predicate type checks
            return True
        
        if node.type == "atom":
            atom_text = node.text.decode("utf-8")
            if atom_text in ARITHMETIC_CONSTANTS:
                return not first
        
        if node.type in {"integer", "float"} :
            return not first
        return False