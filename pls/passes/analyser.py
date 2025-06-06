from abc import ABC, abstractmethod
from collections import defaultdict
from lsprotocol.types import Diagnostic
from pls.utils import RangedAction
from pls.model import PrologAnalyseable
from pls.tree_visitor import TreeVisitor
from tree_sitter import Node


class Analyser(ABC):
    def __init__(self):
        super().__init__()
        self.diagnostics: dict[str, list[Diagnostic]] = defaultdict(list)
        self.actions: dict[str, list[RangedAction]] = defaultdict(list)
        self.uri = None

    def add_diagnostic(self, uri: str, diagnostic: Diagnostic):
        self.diagnostics[uri].append(diagnostic)

    def add_action(self, uri: str, action: RangedAction):
        self.actions[uri].append(action)

    def add_file_diagnostic(self, diagnostic: Diagnostic):
        self.diagnostics[self.uri].append(diagnostic)

    def add_file_action(self, action: RangedAction):
        self.actions[self.uri].append(action)

    @abstractmethod
    def analyse(content: PrologAnalyseable):
        pass


class TreeAnalyser(Analyser, TreeVisitor):
    def __init__(self):
        super().__init__()
        self.table = None

    def start(self, node: Node):
        self.visit_all_children(node)

    def analyse(self, content: PrologAnalyseable):
        self.uri = content.uri
        self.table = content.tables[self.uri]
        self.start(content.trees[self.uri][1].root_node)
