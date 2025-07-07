from pls.pldoc_comment_visitor import PlDocComment
from pls.utils import RangedAction, add_paths, node_to_range
from lsprotocol import types
from pls.my_logging import logging
from pls.model import OperatorDeclaration, OperatorRepresentation, Term, Predicate,string_from_atom

from .analyser import Analyser, PrologAnalyseable


class OperatorDisambiguationAnalysis(Analyser):

    def __init__(self):
        super().__init__()
        self.table = None
        self.uri = None

        self.changes = {}

    def get_action(self):

        return types.CodeAction(
            title=f"Mark pldoc comment as an operator",
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(
                changes= self.changes
            ),
        )
    def add_change(self,comment:PlDocComment,op_repr):

        def just_after(r : types.Range)-> types.Range:
            return types.Range(start = r.end, end= r.end)

        changes = self.changes.get(comment.location.uri,[])
        changes.append( types.TextEdit(
                            range= just_after(comment.location.range),
                            new_text= f"%    @op {op_repr.fixity} {op_repr.precedence}\n"
                        ))

        self.changes[comment.location.uri] = changes

    def analyse(self, content: PrologAnalyseable):
        # To enable _file api
        self.uri = content.uri
        self.table = content.tables[self.uri]
        for op_decl, op_repr in self.table.operators:
            self.analyse_operator(op_decl, op_repr, content)
        self.add_file_action(RangedAction(self.get_action(), node_to_range(content.trees[self.uri][1].root_node)))


    def is_undefined(self, predicate: Predicate) -> tuple[bool, Predicate]:
        if len(predicate.definitions) > 0:
            return False, predicate
        if self.table is None or self.table.builtins is None:
            return True, None

        if imported := self.table.find_predicate_not_in_builtins(predicate.key()):
            return False, imported

        if builtin_predicate := self.table.builtins.predicate_index.get(
            predicate.key()
        ):
            return False, builtin_predicate

        return True, None


    def desambiguate(self,predicate):
        if predicate is None or type(predicate) is not Predicate:
            return
        undefined, new_predicate = self.is_undefined(predicate)
        # logging.debug("%s Is Undefined: %s",predicate.key(),undefined)
        if undefined:
            return None
        else:
            if predicate is not new_predicate:
                new_predicate.references.extend(predicate.references)
                new_predicate.name_references.extend(predicate.name_references)
                self.table.predicate_index[predicate.key()] = new_predicate
        return new_predicate


            

    def analyse_operator(self, decl: OperatorDeclaration, op_repr :OperatorRepresentation , content: PrologAnalyseable):
        predicate  = self.table.predicate_index[op_repr.key()]
        predicate = self.desambiguate(predicate)
        if predicate is None:
            return
        for comment in predicate.comments:
            if type(comment) is PlDocComment and comment.operator_representation() is None:
                # logging.error(f"Operator {op_repr.key()} pldoc's comment has no op decl")
                self.add_change(comment,op_repr)
        
      