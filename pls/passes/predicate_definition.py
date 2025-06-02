from pls.model import Predicate, SymbolTable, Functor,Variable,Term
from pls.pldoc_comment_visitor import PlDocComment
from lsprotocol import types
from pls.my_logging import logging


class PredicateDefinition:
    def __init__(self, uri,all_tables: dict[str, SymbolTable]):
        self.uri = uri
        self.tables = all_tables
        self.table =self.tables[uri]

        self.reports =[]

        self.fixes = []

    def add_code_actions(self,predicate : Predicate):
        head = predicate.heads[0]
        if head is None:
            return
        predicate_template = "" 
        args = []
        if type(head) is Functor:
            arg_counter = {'c':0}
            def get_arg_name(arg):
                if type(arg) is Variable:
                    return arg.name
                else:
                    name = f'Arg{arg_counter["c"]}'
                    arg_counter["c"] += 1
                    return name
                
            args = [get_arg_name(a) for a in head.args]
            to_add = ""
            if len(args) > 0:
                arg_list = ",".join(args) 
                to_add = "("+ arg_list + ")"
            
            predicate_template = f"{predicate.name}{to_add}"
        elif type(head) is Term:
            predicate_template = f"{predicate.name}"
        else:
            logging.error(f"{head}")
            logging.error(f"Cannot suggest comment template for this head")
            return

        pldoc = f"\n%!  {predicate_template}\n" 
        pldoc +="%\n"
        pldoc += "% Predicate Description \n"
        if len(args) > 0:
            pldoc += "%\n"
            for arg in args:
                pldoc += f"% @param {arg}  Argument's {arg} description\n"

        position = types.Range(start=predicate.definitions[0].range.start,end = predicate.definitions[0].range.start)
        export_all= types.CodeAction(
            title= "Add predicate PLDoc Comment",
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(changes={self.table.path: [
                types.TextEdit(
            range=position, new_text=pldoc
        )
            ]}),
        )
        logging.error(f"{export_all}")
        self.fixes.append(export_all)

    def analyse(self):
        for key, predicate  in self.table.predicate_index.items():
            if len(predicate.definitions) > 0  and not any([type(p) is PlDocComment for p in predicate.comments]):
                self.add_code_actions(predicate)