# Prolog Language Server Feature Report
=====================================

Based on the commit history and server implementation, this report details the comprehensive set of features, diagnostics, and code actions implemented in the Prolog Language Server (PLS). The PLS aims to significantly enhance the developer experience for Prolog programmers by providing intelligent code assistance, navigation, and refactoring capabilities.

## Core Language Server Architecture & Infrastructure
---------------------------------------------------

1.  **Multi-file Support & Project Management:**
    * **Dependency Graph Management:** Manages a dependency graph for cross-file analysis, understanding `consult/1` and `use_module` relationships.
    * **Topological Sorting:** Ensures correct analysis order for interdependent files.
    * **Cyclic Dependency Handling:** Detects and reports cyclic dependencies with appropriate warnings.
    * **Automatic Reanalysis:** Triggers reanalysis when dependencies change, maintaining up-to-date information.
2.  **Document Parsing & Analysis:**
    * **Tree-sitter Based Parsing:** Utilizes the highly efficient `Tree-sitter` library for robust and incremental parsing of Prolog source code into an Abstract Syntax Tree (AST).
    * **Symbol Table Generation:** Builds and maintains symbol tables for comprehensive semantic understanding of predicates, variables, and atoms within each file and across modules.
    * **Shallow Parsing:** Employs shallow parsing for rapid dependency analysis and structural understanding.
    * **Full Semantic Analysis Pipeline:** Implements a pipeline for in-depth semantic analysis to support advanced language features.
3.  **Project Indexing:**
    * **Automatic File Discovery:** Automatically discovers and indexes Prolog files (`.pl`).
    * **Built-in Predicate Indexing:** Indexes common built-in Prolog predicates for comprehensive language support.
    * **Progress Reporting:** Provides feedback during initial project indexing for large codebases.

## Language Features
-----------------

### Navigation Features

* **Go-to-Definition (`textDocument/definition`):**
    * Works accurately for variables, predicates (including 0-arity), and atoms, navigating to their definitions even across different files and modules.
* **Find References (`textDocument/references`):**
    * Locates all occurrences of variables, atoms, and predicates across multiple files within the workspace.
* **Document Links (`textDocument/documentLink`):**
    * Provides clickable links for `consult` paths and `use_module` declarations, allowing quick navigation to linked files.

### Code Intelligence

* **Hover Information (`textDocument/hover`):**
    * Displays documentation for predicates (including `PLDoc` comments).
    * Shows information for variables and built-in predicate documentation.
    * Supports Markdown formatting for rich display of documentation.
* **Completion (`textDocument/completion`):**
    * Offers intelligent suggestions for variable names.
    * Provides predicate name completion (including arity).
    * Includes template snippets for common predicate structures.
    * Sources completions from consulted files, imported modules, and built-in predicates.
* **Signature Help (`textDocument/signatureHelp`):**
    * Shows parameter information and predicate signatures as users type.
    * Highlights the currently active parameter.
    * Designed to work robustly even in the presence of minor syntax errors.

### Refactoring

* **Rename (`textDocument/rename`):**
    * Supports renaming of variables (within the same file/scope) and predicates (across multiple files).
    * Includes checks to prevent renaming built-in or library-imported predicates, providing informative feedback to the user.
    * Automatically updates associated `PLDoc` templates when predicates are renamed.

### Diagnostics

1.  **Syntax Errors:**
    * Reports parsing errors directly from the `Tree-sitter` parser, providing immediate feedback on malformed Prolog code.
2.  **Semantic Warnings:**
    * **Undefined Predicate:** Warns when calling predicates that are not defined within the current scope, built-ins, or consulted/imported modules.
    * **Unused Variables:** Identifies and warns about variables that are declared but not used (ignoring anonymous variables like `_` and `_var` patterns).
    * **Cyclic Consults:** Detects and reports circular file dependencies, which can indicate structural issues.
    * **Invalid Consult Paths:** Warns when `consult` directives point to non-existent files.
    * **Predicate Definition Checks:** Includes additional checks related to predicate definitions (specifics depend on implementation, but typically cover arity mismatches, multiple definitions of a non-multifile predicate etc.).

### Code Actions

1.  **Quick Fixes:**
    * **Unused Variable Fixes:** Offers suggested fixes for identified unused variables.
    * **Undefined Predicate Actions:** Provides actions to help address undefined predicates (e.g., generating a stub).
    * **Export Predicate:** An action to easily add a predicate to a module's export list.
    * **Generate Module Declaration:** Creates a module declaration for a file, optionally exporting all defined predicates.
    * **Generate Comment Template:** Automatically creates a `PLDoc` template for predicates, promoting documentation.
2.  **Context-Filtered Actions:**
    * Code actions are intelligently filtered by range, ensuring that only relevant fixes and suggestions are presented to the user at any given cursor position.

### Module System Support

* **`use_module/1` and `use_module/2` Support:** Full parsing and understanding of these directives for correct module resolution.
* **Module Declaration Parsing:** Accurately parses module declarations to identify exported predicates and their arities.
* **Cross-Module Predicate Resolution:** Resolves predicate calls and references across different modules.
* **Library Module Detection:** Automatically detects and indexes common Prolog standard libraries (e.g., `clpfd`, `between`, `lists`).
* **Exportable Predicates Tracking:** Each file tracks the set of predicates it can export, essential for cross-module features.
* **Duplicate Module Detection:** Warns about duplicate module declarations.

### Editor Integration

* **Semantic Highlighting:** Provides advanced syntax highlighting beyond basic regex, distinguishing:
    * Variables
    * Predicates
    * Operators
    * Strings
    * Integers
    * Comments (including `PLDoc`)
* **Neovim Configuration:** Includes support and configurations for integration with the Neovim editor.
* **VS Code Extension:**
    * Properly packaged using `esbuild` for easy installation and distribution.
    * Includes a dedicated log output channel for debugging and operational insights.
    * Automated GitHub Releases via GitHub Actions, streamlining deployment.

### Performance & Robustness

* **Caching:** Implements caching of parsed documents and analysis results to avoid redundant work.
* **Version Tracking:** Tracks document versions to ensure analysis is performed only when necessary.
* **Progress Reporting:** Provides visual feedback to the user during long-running operations like initial project indexing.
* **Error Resilience:** Designed with fallback behaviors to maintain stability even when encountering unexpected code structures or partial input.
* **Debugging Support:** Comprehensive logging facilities aid in diagnosing issues during development and operation.

---

## Implementation Details
----------------------

The server's robust functionality relies on several key architectural components and chosen technologies:

1.  **Tree-sitter Prolog:** The fundamental parsing engine, providing an accurate and performant AST.
2.  **Visitor Pattern:** Extensively used for traversing the AST and performing various analysis passes (e.g., symbol gathering, definition lookup).
3.  **Dependency Graph:** Manages file relationships and ensures correct analysis order.
4.  **Symbol Table:** A core data structure for storing and retrieving semantic information about code entities.
5.  **PLDoc Integration:** Specific logic for parsing and utilizing `PLDoc` comments for documentation features.

The overall architecture is modular, separating concerns into distinct layers:
* Parsing
* Dependency Analysis
* Semantic Analysis
* Feature Providers (e.g., Completion Provider, Diagnostics Provider)

---

## Roadmap Items Completed
--------------------------

Based on the project's commit history, the following significant roadmap items have been successfully implemented:

* Multi-file support (including `consult/1` handling).
* Go-to-definition across files.
* Find references.
* Semantic highlighting.
* Signature help.
* Autocomplete (comprehensive).
* `PLDoc` integration.
* Custom operator support.
* List pipe operator handling.
* Server restart capability.
* Undefined predicate warnings.
* Unused variable warnings.
* Rename refactoring.
* Code actions for common issues.
* Module system support.

The server has evolved into an advanced state, offering comprehensive support for Prolog development, with a particular focus on intelligent code assistance, navigation, and refactoring capabilities that significantly enhance the developer's experience.