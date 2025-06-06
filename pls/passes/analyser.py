from abc import ABC,abstractmethod
from collections import defaultdict
from lsprotocol.types import Diagnostic
from pls.utils import RangedAction
from pls.model import PrologAnalyseable

class Analyser(ABC):
    def __init__(self):
        super().__init__()
        self.diagnostics : dict[str,list[Diagnostic]]= defaultdict(list)
        self.actions: dict[str, list[RangedAction]] =  defaultdict(list)

    
    def add_diagnostic(self,uri:str,diagnostic : Diagnostic):
        self.diagnostics[uri].append(diagnostic)

    def add_action(self,uri:str,action:RangedAction):
        self.actions[uri].append(action)
    

    @abstractmethod
    def analyse(content : PrologAnalyseable):
        pass


class FileAnalyser(Analyser):
    def __init__(self,uri:str):
        super().__init__()
        self.uri = uri

    
    def add_file_diagnostic(self,diagnostic : Diagnostic):
        self.diagnostics[self.uri].append(diagnostic)

    def add_file_action(self,action:RangedAction):
        self.actions[self.uri].append(action)


