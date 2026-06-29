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

    _builtin_cache: Dict[str, Optional[SymbolTable]] = {}
    _library_cache: Dict[str, SymbolTable] = {}

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
            cache_key = self.builtin_uri
            cached_builtin = self.__class__._builtin_cache.get(cache_key)
            if cached_builtin is None:
                cached_builtin = self._load_builtins()
                self.__class__._builtin_cache[cache_key] = cached_builtin
            self.builtin_table = cached_builtin
        else:
            self.builtin_table = builtin_table
        
        # Load libraries that should be available to all files
        self.library_tables = self._load_libraries()

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

    def _load_libraries(self) -> Dict[str, SymbolTable]:
        """Load standard libraries (lists, between) that should be available to all files."""
        libraries = {}
        
        libs_dir = Path(__file__).parent / 'data' / 'flavours' / 'sicstus' / 'libs'
        lib_files = ['lists.pl', 'between.pl']
        
        for lib_name in lib_files:
            lib_path = libs_dir / lib_name
            if not lib_path.exists():
                continue
            
            try:
                lib_uri = path_to_file_uri(lib_path)
                cached_library = self.__class__._library_cache.get(lib_uri)
                if cached_library is not None:
                    libraries[lib_uri] = cached_library
                    continue

                lib_source = lib_path.read_text(encoding='utf-8', errors='replace')
                lib_tree = PARSER.parse(bytes(lib_source, "utf-8"))
                
                lib_visitor = PrologVisitor(lib_uri)
                lib_visitor.visit(lib_tree.root_node, Opts())
                
                lib_table = SymbolTable(
                    scopes=lib_visitor.scopes,
                    notes=lib_visitor.notes,
                    predicate_index=lib_visitor.predicate_index,
                    predicate_index_by_name=lib_visitor.predicate_index_by_name,
                    builtins=self.builtin_table,
                    imports={},
                    imported_signatures={},
                    consults={},
                    consult_paths=lib_visitor.consult_paths,
                    module_paths=lib_visitor.module_paths,
                    module_declarations=lib_visitor.module_declarations,
                    use_module_declarations=lib_visitor.used_modules,
                    exported_signatures=set(),
                    libs=lib_visitor.libs,
                    exportable_predicates=lib_visitor.exportable_predicates,
                    path=lib_uri,
                    operator_declarations=lib_visitor.operator_declarations,
                    operators=[],
                )
                
                self.__class__._library_cache[lib_uri] = lib_table
                libraries[lib_uri] = lib_table
            except Exception as e:
                print(f"Warning: Failed to load library {lib_name}: {e}")
        
        return libraries

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
                - is_common_file: bool (True if file should not be included in final stats)
        """
        result = {
            'file': file_path,
            'time_ms': 0.0,
            'memory_mb': 0.0,
            'errors_by_pass': {},
            'total_errors': 0,
            'error_details': [],
            'exception': None,
            'is_common_file': False,
        }

        try:
            file_path_obj = Path(file_path)
            if not file_path_obj.exists():
                result['exception'] = f"File not found: {file_path}"
                return result

            # Mark common.pl files as excluded from final stats
            if file_path_obj.name == "common.pl":
                result['is_common_file'] = True

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
            root_symbol_table = tables[uri]
            trees = {uri: (None, tree)}
            dg = DependencyGraphManager()

            self._resolve_consulted_files(uri, root_symbol_table, tables, trees)
            
            # Add standard libraries to the analysis context
            for lib_uri, lib_table in self.library_tables.items():
                lib_table_copy = deepcopy(lib_table)
                tables[lib_uri] = lib_table_copy
                root_symbol_table.consults[lib_uri] = lib_table_copy
            
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

            diagnostics_by_pass = self._group_diagnostics_by_pass_from_pipeline(pipeline, uri)
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

    def _group_diagnostics_by_pass_from_pipeline(self, pipeline, uri: str) -> Dict[str, int]:
        """
        Get diagnostics grouped by pass from the pipeline's tracking.
        
        Args:
            pipeline: The ConfigurablePipeline that tracks diagnostics by pass
            uri: The file URI
            
        Returns:
            Dictionary mapping pass name to error count
        """
        by_pass = {}
        
        for pass_name, uris_dict in pipeline.diagnostics_by_pass.items():
            if uri in uris_dict:
                by_pass[pass_name] = len(uris_dict[uri])
        
        return by_pass
