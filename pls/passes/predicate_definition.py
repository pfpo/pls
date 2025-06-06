from pls.model import Predicate, SymbolTable, Functor,Variable,Term
from pls.pldoc_comment_visitor import PlDocComment
from lsprotocol import types
from pls.my_logging import logging
from pls.utils import RangedAction, add_paths,file_uri_to_path, node_to_range


class PredicateDefinition:
    def __init__(self,tree, uri,all_tables: dict[str, SymbolTable]):
        self.tree = tree 
        self.uri = uri
        self.tables = all_tables
        self.table =self.tables[uri]

        self.reports =[]

        self.fixes = []
    
    def declare_module_action(self,keys,title):
        if len(self.table.module_declarations) > 1:
            return 
        if len(self.table.module_declarations) == 0:
            substitute_range =  types.Range(start=types.Position(0,0),end=types.Position(0,0))
            name = file_uri_to_path(self.uri).name[:-3]
            substitution = False
        if len(self.table.module_declarations) == 1:
            substitute_range = self.table.module_declarations[0].loc
            name = self.table.module_declarations[0].name
            substitution = True
        action= types.CodeAction(
            title= title,
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(changes={self.table.path: [
                types.TextEdit(
            range=substitute_range,
              new_text= self.declare_module(name,keys,substitution)
        )
            ]}),
        )
        return action


    def declare_module(self,name,keys,substitution):
        m = f'module({name},[{",".join(keys)}])'
        if substitution:
            return m
        else:
            return f":- {m}.\n"

    def export_all_predicates(self):
        keys = []
        for key in self.table.exportable_predicates:
            keys.append(key)
        action = self.declare_module_action(keys,"Export All Defined Predicates")        
        self.fixes.append(RangedAction(action,node_to_range(self.tree.root_node)))

    def add_code_actions_export_predicate(self,predicate : Predicate):
        keys = set(self.table.exported_signatures)
        keys.add(predicate.key())
        action = self.declare_module_action(keys,"Export Predicate " + predicate.key())
        for definition in predicate.definitions:
            self.fixes.append(RangedAction(action,definition.range))

    def add_code_actions_comment_template(self,predicate : Predicate):
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
                
            args = ["?"+get_arg_name(a) for a in head.args]
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
        action= types.CodeAction(
            title= "Add predicate PLDoc Comment",
            kind=types.CodeActionKind.QuickFix,
            edit=types.WorkspaceEdit(changes={self.table.path: [
                types.TextEdit(
            range=position, new_text=pldoc
        )
            ]}),
        )

        for definition in predicate.definitions:
            self.fixes.append(RangedAction(action,definition.range))

    def analyse(self):
        self.export_all_predicates()
        for key, predicate  in self.table.predicate_index.items():
            if len(predicate.definitions) > 0 :
                if not any([type(p) is PlDocComment for p in predicate.comments]):
                    self.add_code_actions_comment_template(predicate)
                if predicate.key() not in self.table.exported_signatures:
                    self.add_code_actions_export_predicate(predicate)