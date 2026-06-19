"""
Benchmark runner for analyzing Prolog files without LSP server overhead.
Measures: execution time, peak memory, and error counts per analysis pass.
"""

import time
import traceback
import tracemalloc
from pathlib import Path
from copy import deepcopy
from typing import Dict, List, Tuple, Optional

import psutil
from tree_sitter import Language, Parser, Query
from lsprotocol import types

from tree_sitter_prolog import prolog

from pls.model import SymbolTable, PrologAnalyseable
from pls.prolog_visitor import PrologVisitor, Opts
from pls.passes.configurable_pipeline import ConfigurablePipeline
from pls.dependency_graph import DependencyGraphManager
from pls.utils import path_to_file_uri, file_uri_to_path, builtins_path, MyDoc

PROLOG = Language(prolog())
PARSER = Parser(PROLOG)


class BenchmarkAnalyzer:
    """Analyzes a single Prolog file in isolation and collects metrics."""

    def __init__(self, builtin_uri: Optional[str] = None, builtin_table: Optional[SymbolTable] = None):
        """
        Initialize analyzer.
        
        Args:
            builtin_uri: URI of builtins file (default: auto-detected)
            builtin_table: Pre-parsed symbol table for builtins (will be loaded if not provided)
        """
        self.queries = self._load_queries()
        
        # Initialize builtins
        if builtin_uri is None:
            self.builtin_uri = builtins_path()
        else:
            self.builtin_uri = builtin_uri
        
        if builtin_table is None:
            self.builtin_table = self._load_builtins()
        else:
            self.builtin_table = builtin_table

    def _load_queries(self) -> Dict[str, Query]:
        """Load tree-sitter queries from disk."""
        queries = {}
        queries_path = Path(__file__).parent / 'queries'
        for scm_file in queries_path.glob('*.scm'):
            name = scm_file.stem
            try:
                content = scm_file.read_text()
                queries[name] = Query(PROLOG, content)
            except Exception as e:
                print(f"Warning: Failed to load query {name}: {e}")
        return queries

    def _load_builtins(self) -> Optional[SymbolTable]:
        """Load and parse the builtins Prolog file."""
        try:
            builtin_doc = MyDoc(self.builtin_uri)
            builtin_source = builtin_doc.source
            
            if not builtin_source:
                print(f"Warning: Builtins file is empty: {self.builtin_uri}")
                return None
            
            # Parse builtins file
            tree = PARSER.parse(bytes(builtin_source, "utf-8"))
            
            # Build symbol table for builtins
            visitor = PrologVisitor(self.builtin_uri)
            visitor.visit(tree.root_node, Opts())
            
            builtin_table = SymbolTable(
                scopes=visitor.scopes,
                notes=visitor.notes,
                predicate_index=visitor.predicate_index,
                predicate_index_by_name=visitor.predicate_index_by_name,
                builtins=None,  # Builtins don't need nested builtins
                imports={},
                imported_signatures={},
                consults={},
                consult_paths=visitor.consult_paths,
                module_paths=visitor.module_paths,
                module_declarations=visitor.module_declarations,
                use_module_declarations=visitor.used_modules,
                exported_signatures=set(),
                libs=visitor.libs,
                exportable_predicates=visitor.exportable_predicates,
                path=self.builtin_uri,
                operator_declarations=visitor.operator_declarations,
                operators=[],
            )
            
            return builtin_table
        except Exception as e:
            print(f"Warning: Failed to load builtins from {self.builtin_uri}: {e}")
            return None

    def analyze_file(self, file_path: str) -> Dict:
        """
        Analyze a single Prolog file and return metrics.
        
        Args:
            file_path: Path to the .pl file
            
        Returns:
            Dictionary with keys:
                - file: str (file path)
                - time_ms: float (total analysis time in milliseconds)
                - memory_mb: float (peak memory in MB)
                - errors_by_pass: dict (error counts per pass class name)
                - total_errors: int (total error count)
                - error_details: list (detailed diagnostic info)
        """
        result = {
            'file': file_path,
            'time_ms': 0.0,
            'memory_mb': 0.0,
            'errors_by_pass': {},
            'total_errors': 0,
            'error_details': [],
            'exception': None,
        }

        try:
            file_path_obj = Path(file_path)
            if not file_path_obj.exists():
                result['exception'] = f"File not found: {file_path}"
                return result

            source = file_path_obj.read_text(encoding='utf-8', errors='replace')
            
            start_time = time.perf_counter()
            start_memory = psutil.Process().memory_info().rss / (1024 * 1024)  # MB

            uri = path_to_file_uri(file_path_obj)
            tree = PARSER.parse(bytes(source, "utf-8"))

            prolog_visitor = PrologVisitor(uri)
            prolog_visitor.visit(tree.root_node, Opts())
            
            symbol_table = SymbolTable(
                scopes=prolog_visitor.scopes,
                notes=prolog_visitor.notes,
                predicate_index=prolog_visitor.predicate_index,
                predicate_index_by_name=prolog_visitor.predicate_index_by_name,
                builtins=self.builtin_table,
                imports={},
                imported_signatures={},
                consults={},
                consult_paths=prolog_visitor.consult_paths,
                module_paths=prolog_visitor.module_paths,
                module_declarations=prolog_visitor.module_declarations,
                use_module_declarations=prolog_visitor.used_modules,
                exported_signatures=set(),
                libs=prolog_visitor.libs,
                exportable_predicates=prolog_visitor.exportable_predicates,
                path=uri,
                operator_declarations=prolog_visitor.operator_declarations,
                operators=[],
            )

            tables = {uri: deepcopy(symbol_table)}
            trees = {uri: (None, tree)}
            dg = DependencyGraphManager()

            self._resolve_consulted_files(uri, symbol_table, tables, trees)
            
            analyseable = PrologAnalyseable(
                uri=uri,
                tables=tables,
                trees=trees,
                dg=dg,
                queries=self.queries,
                source=source,
            )

            pipeline = ConfigurablePipeline(settings={})
            pipeline.analyse(analyseable)

            diagnostics_by_pass = self._group_diagnostics_by_pass(pipeline.diagnostics.get(uri, []))
            result['errors_by_pass'] = diagnostics_by_pass
            result['total_errors'] = sum(diagnostics_by_pass.values())
            
            result['error_details'] = [
                {
                    'line': d.range.start.line,
                    'message': d.message,
                    'severity': d.severity,
                }
                for d in pipeline.diagnostics.get(uri, [])
            ]

            end_time = time.perf_counter()
            end_memory = psutil.Process().memory_info().rss / (1024 * 1024)  # MB

            result['time_ms'] = (end_time - start_time) * 1000
            result['memory_mb'] = max(0, end_memory - start_memory)

        except Exception as e:
            result['exception'] = f"{type(e).__name__}: {str(e)}"
            result['error_details'].append({
                'error': result['exception'],
                'traceback': traceback.format_exc()
            })

        return result

    def _resolve_consulted_files(
        self,
        uri: str,
        symbol_table: SymbolTable,
        tables: Dict[str, SymbolTable],
        trees: Dict[str, Tuple[Optional[int], object]],
        visited: Optional[set] = None,
    ) -> None:
        """Recursively resolve consulted files and add their tables into the analysis context."""
        if visited is None:
            visited = set()

        if uri in visited:
            return
        visited.add(uri)

        for consult_uri in symbol_table.consult_paths:
            if consult_uri in tables:
                continue

            try:
                consult_path = file_uri_to_path(consult_uri)
            except Exception:
                continue

            if not consult_path.exists():
                continue

            consult_source = consult_path.read_text(encoding='utf-8', errors='replace')
            consult_tree = PARSER.parse(bytes(consult_source, "utf-8"))
            consult_visitor = PrologVisitor(consult_uri)
            consult_visitor.visit(consult_tree.root_node, Opts())

            consult_table = SymbolTable(
                scopes=consult_visitor.scopes,
                notes=consult_visitor.notes,
                predicate_index=consult_visitor.predicate_index,
                predicate_index_by_name=consult_visitor.predicate_index_by_name,
                builtins=self.builtin_table,
                imports={},
                imported_signatures={},
                consults={},
                consult_paths=consult_visitor.consult_paths,
                module_paths=consult_visitor.module_paths,
                module_declarations=consult_visitor.module_declarations,
                use_module_declarations=consult_visitor.used_modules,
                exported_signatures=set(),
                libs=consult_visitor.libs,
                exportable_predicates=consult_visitor.exportable_predicates,
                path=consult_uri,
                operator_declarations=consult_visitor.operator_declarations,
                operators=[],
            )

            tables[consult_uri] = deepcopy(consult_table)
            trees[consult_uri] = (None, consult_tree)

            # add consult table to parent symbol table for lookup
            symbol_table.consults[consult_uri] = consult_table

            self._resolve_consulted_files(consult_uri, consult_table, tables, trees, visited)

        return

    def _group_diagnostics_by_pass(self, diagnostics: List[types.Diagnostic]) -> Dict[str, int]:
        """
        Group diagnostics by their source pass.
        
        This is a heuristic approach: we extract the pass name from the error message
        or use the diagnostic code if available.
        
        Args:
            diagnostics: List of LSP Diagnostic objects
            
        Returns:
            Dictionary mapping pass name to error count
        """
        by_pass = {}
        
        for diagnostic in diagnostics:
            # Try to extract pass name from code or message
            pass_name = self._extract_pass_name(diagnostic)
            by_pass[pass_name] = by_pass.get(pass_name, 0) + 1
        
        return by_pass

    def _extract_pass_name(self, diagnostic: types.Diagnostic) -> str:
        """
        Extract the pass name from a diagnostic.
        
        Heuristic approach using diagnostic code and message keywords.
        """
        code_to_pass = {
            'syntax_error': 'syntax_error',
            'undefined_predicate': 'undefined_predicate',
            'unused_variable': 'unused_variable',
            'operator_declaration': 'operator_declaration',
            'operator_disambiguation': 'operator_disambiguation',
            'naming_conventions': 'naming_conventions',
            'single_element_list_append': 'single_element_list_append',
            'empty_list_append': 'empty_list_append',
            'nested_list_constructs': 'nested_list_constructs',
            'explicit_unification': 'explicit_unification',
            'wrapper_predicates': 'wrapper_predicates',
            'line_length': 'line_length',
            'indentation_consistency': 'indentation_consistency',
            'argument_list': 'argument_list',
            'too_many_arguments': 'too_many_arguments',
            'arg_pldoc': 'arg_pldoc',
            'clause_length': 'clause_length',
            'subgoal_per_line': 'subgoal_per_line',
        }
        
        if diagnostic.code:
            code_lower = str(diagnostic.code).lower()
            for code_key, pass_name in code_to_pass.items():
                if code_key in code_lower:
                    return pass_name
        
        message_lower = diagnostic.message.lower() if diagnostic.message else ""
        keywords = {
            'syntax': 'syntax_error',
            'undefined': 'undefined_predicate',
            'unused': 'unused_variable',
            'operator': 'operator_declaration',
            'naming': 'naming_conventions',
            'list': 'list_operations',
            'unification': 'explicit_unification',
            'line length': 'line_length',
            'indentation': 'indentation_consistency',
            'argument': 'argument_list',
            'too many': 'too_many_arguments',
            'clause': 'clause_length',
            'subgoal': 'subgoal_per_line',
        }
        
        for keyword, pass_name in keywords.items():
            if keyword in message_lower:
                return pass_name
        
        return 'unknown'
