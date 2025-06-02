from pls.model import ModuleDeclaration, Signature, SymbolTable, UseModule
from pls.pldoc_comment_visitor import PlDocComment
from pls.utils import add_paths,file_uri_to_path
from pls.dependency_graph import DependencyGraphManager
from lsprotocol import types
from pls.my_logging import logging
from collections import defaultdict


class MooduleAnalyser:
    def __init__(self, uri,all_tables: dict[str, SymbolTable]):
        self.uri = uri
        self.tables = all_tables
        self.table =self.tables[uri]

        self.reports =[]

        self.imported_signatures = {}
        self.exported_signatures= set()

        self.fixes = []


    def analyse_module_declarations(self):
        if len(self.table.module_declarations) == 0:
            return
        if len(self.table.module_declarations) > 1:
            for decl in self.table.module_declarations:
                self.add_multiple_module_declarations(decl)
            return
        
        exported_signatures = set()
        for signature in self.table.module_declarations[0].exported:
            pred = self.table.predicate_index.get(signature.key())
            if pred is None or (len(pred.definitions) == 0  and not any([type(p) is PlDocComment for p in pred.comments])):
                self.add_exported_predicate_does_not_exist(signature)
            else:
                exported_signatures.add(signature.key())
        self.exported_signatures =  exported_signatures
        self.table.exported_signatures = exported_signatures
    

    def analyse_use_module_declarations(self,modules_to_include : set[str]):
        signatures : dict[str,set[str]]= {}
        for module in self.table.use_module_declarations:
            path = module.uri
            logging.error(f"{path}")
            if path not in modules_to_include:
                logging.error(f"{path} is not to be included")
                continue
            if path in signatures:
                logging.error("Duplicated Import")
                self.add_duplicated_import(module.name,module.loc)
            else:
                module_table = self.tables[path]
                logging.error(f"{module_table}")
                logging.error(f"{self.uri} includes from Module {path} \n{module_table.exported_signatures}")
                if module.imported is None:
                    signatures[path] = module_table.exported_signatures
                else:
                    correctly_imported = set()
                    for signature in module.imported:
                        logging.error(f"{module_table.exported_signatures}")
                        if signature.key() in module_table.exported_signatures:
                            correctly_imported.add(signature.key())
                        else:
                            self.add_module_does_not_export_signature(module,signature)
                    signatures[path] = correctly_imported
        self.imported_signatures = signatures 
        for uri in modules_to_include:
            self.table.imported_signatures[uri] = self.imported_signatures[uri]
            imported_table = self.tables[uri]
            self.table.imports[uri] = imported_table
                        
        logging.error(f"Imported Signatures: {self.table.imported_signatures}")
        logging.error(f"Imported Tables: {self.table.imports}")


    def add_exported_predicate_does_not_exist(self,signature:Signature):
        message = f"Predicate Does Not Exist {signature.key()}"
        report = types.Diagnostic(
            message=message,
            severity=types.DiagnosticSeverity.Warning,
            range=signature.loc,
        )
        self.reports.append(report)
    def add_multiple_module_declarations(self,module:ModuleDeclaration):
        message = f"Duplicated module declaration"
        report = types.Diagnostic(
            message=message,
            severity=types.DiagnosticSeverity.Warning,
            range= module.loc,
        )
        self.reports.append(report)
    def add_module_does_not_export_signature(self,module:UseModule,signature:Signature):
        message = f"Module {module.name} does not export {signature.key()}"
        report = types.Diagnostic(
            message=message,
            severity=types.DiagnosticSeverity.Warning,
            range= signature.loc,
        )
        self.reports.append(report)
    def add_duplicated_import(self,name : str, loc : types.Range):
        message = f"Duplicated Use Module Declaration {name}"
        report = types.Diagnostic(
            message=message,
            severity=types.DiagnosticSeverity.Warning,
            range=loc,
        )
        self.reports.append(report)
