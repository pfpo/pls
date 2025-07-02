from pls.utils import add_paths
from lsprotocol import types
from pls.model import OperatorDeclaration, OperatorRepresentation, Term, Predicate,string_from_atom
from pls.my_logging import logging

from .analyser import Analyser, PrologAnalyseable


class OperatorDeclarationAnalysis(Analyser):
    VALID_FIXITIES = {"fx", "fy", "xf", "yf", "xfy", "yfx", "xfx"}
    MIN_PRECEDENCE = 0
    MAX_PRECEDENCE = 1200

    def __init__(self):
        super().__init__()

    def analyse(self, content: PrologAnalyseable):
        # To enable _file api
        self.uri = content.uri
        table = content.tables[self.uri]
        logging.error(f"Analysing Operator Declaration")
        for op_decl in table.operator_declarations:
            # print(op_decl)
            self.analyse_operator_decl(op_decl, content)

    def get_predicate(self, table ,t: Term) -> Predicate:
        key = t.key()
        if key not in table.predicate_index:
            table.predicate_index[key] = Predicate(t.name, t.arity)
        if t.name not in table.predicate_index_by_name:
            table.predicate_index_by_name[t.name] = set()
        table.predicate_index_by_name[t.name].add(key)

        return table.predicate_index[key]

    def analyse_operator_decl(self, decl: OperatorDeclaration, content: PrologAnalyseable):
        precedence = self.analyse_precedence(decl, content)
        fixity = self.analyse_fixity(decl, content)
        name = self.analyse_name(decl, content)
        logging.error(f"{name} {fixity} {precedence}")

        if precedence is not None and fixity is not None and name is not None:
            # Construct or register the operator here if needed
            # e.g., content.add_operator(name, fixity, precedence)
            logging.error(f"Valid operator: {name} {fixity} {precedence}")
            op = OperatorRepresentation(name,fixity,precedence)
            table = content.tables[content.uri]
            predicate = self.get_predicate(table,op)
            if predicate.operator is not None: 
                # TODO already declared predicate
                pass
            predicate.operator = op
            table.operators.append((decl,op))
            # print(content.tables[content.uri].predicate_index.keys())
                

    def analyse_precedence(self, decl: OperatorDeclaration, content: PrologAnalyseable):
        prec = string_from_atom(decl.precedence.name)
        if prec.isnumeric() and  self.MIN_PRECEDENCE <= (prec_num := int(prec)) <= self.MAX_PRECEDENCE:
            return prec_num
        self.add_file_diagnostic(types.Diagnostic(
            message=f"Invalid operator precedence '{prec}': must be an integer between {self.MIN_PRECEDENCE} and {self.MAX_PRECEDENCE}.",
            severity=types.DiagnosticSeverity.Warning,
            range=decl.range
        ))
        return None

    def analyse_fixity(self, decl: OperatorDeclaration, content: PrologAnalyseable):
        fixity = string_from_atom(decl.fixity.name)
        if isinstance(fixity, str) and fixity in self.VALID_FIXITIES:
            return fixity
        self.add_file_diagnostic(types.Diagnostic(
            message=f"Invalid operator fixity '{fixity}': must be one of {sorted(self.VALID_FIXITIES)}.",
            severity=types.DiagnosticSeverity.Error,
            range=decl.range
        ))
        return None

    def analyse_name(self, decl: OperatorDeclaration, content: PrologAnalyseable):
        logging.error(f"{decl.name.name}")
        name = decl.other_name.strip()
        if len(name) > 1 and (name[0] == '(' and name[-1] == ')') or (name[0] =="'" and name[1] == "'"):
            name = name[1:-1]
        if isinstance(name, str):
            return name
        self.add_file_diagnostic(types.Diagnostic(
            message=f"Invalid operator name '{name}': must be an atom.",
            severity=types.DiagnosticSeverity.Error,
            range=decl.range
        ))
        return None
