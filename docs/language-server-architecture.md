# Language Server Architecture

This document explains how the Prolog Language Server is structured so new contributors can trace a request from startup to diagnostics, completions, and refactoring features.

## What the server does

The server analyzes Prolog source files, builds an internal symbol table for each document, tracks file dependencies, and answers Language Server Protocol requests such as hover, definition, references, completion, signature help, folding, selection ranges, document links, semantic tokens, rename, and code actions.

The main implementation lives in [pls/server.py](../pls/server.py). The executable entry point is [pls/main.py](../pls/main.py).

## High-level flow

1. The editor launches the Python process through the VS Code extension or another LSP client.
2. `pls/main.py` starts the shared `server` instance.
3. `pls/server.py` registers LSP feature handlers on a `pygls` `LanguageServer`.
4. On initialization, the server scans the workspace for `.pl` files and indexes them.
5. Each file is parsed with Tree-sitter, converted into a symbol table, and then analyzed by the configured rule pipeline.
6. Results are stored per URI and published back to the client as diagnostics, code actions, tokens, and navigation data.

## Main runtime objects

The central class is `PLS` in [pls/server.py](../pls/server.py). It owns most of the server state:

- `trees`: parsed Tree-sitter trees per file
- `tables`: the active `SymbolTable` for each file
- `original_tables`: a pristine copy used when reusing cached parses
- `comment_trees`: PlDoc annotations collected during parsing
- `diagnostics`: buffered diagnostics per file and version
- `actions`: buffered code actions per file and version
- `tokens`: semantic-token payloads per file and version
- `dg`: the dependency graph manager
- `settings`: configured analysis options coming from `pls.passes.*`
- `queries`: Tree-sitter queries loaded from [pls/queries](../pls/queries)

The most important data model is defined in [pls/model.py](../pls/model.py). In practice, `SymbolTable` is the shared snapshot that later passes and LSP features read from.

## Parse and analysis pipeline

The document pipeline is split into two stages.

### 1. Parse stage

`PLS._parse()` in [pls/server.py](../pls/server.py) runs Tree-sitter over the document source, then uses `PrologVisitor` to extract:

- scopes and variables
- predicate definitions and references
- consult paths
- module declarations and `use_module/1` data
- operator declarations
- PlDoc comments

The result is stored as a `SymbolTable` and copied into `tables` so later passes can mutate the working copy without destroying the original parse snapshot.

### 2. Analysis stage

`PLS.run_analysis()` and `PLS.run_passes()` perform the semantic checks and editor features.

`run_passes()` builds a `ConfigurablePipeline`, passing the current file and workspace state through the enabled passes. Those passes add diagnostics and code actions into the shared buffers.

Some passes are always part of the file graph workflow:

- `MissingPaths` checks unresolved consults and module paths
- `CyclicPaths` reports cyclic dependency chains
- `MooduleAnalyser` validates module imports and exported signatures

The exact diagnostic set depends on workspace settings under `pls.passes.*`.

## Dependency handling

Prolog files can depend on one another through consults and modules, so the server maintains a dependency graph in [pls/dependency_graph.py](../pls/dependency_graph.py).

The graph is used to:

- discover which files need to be re-analyzed together
- keep consult/module relationships in sync
- identify cycles
- ensure imported module data is available before later passes run

When a file is opened or changed, the server calls `parse_with_dependencies()`, which builds the relevant dependency chain and reprocesses the affected files in topological order.

## LSP request handling

`pls/server.py` defines one handler per LSP feature near the bottom of the file. Each handler is thin and delegates to a method on `PLS`.

Common request paths:

- `textDocument/definition` -> `PLS.go_to_definition()`
- `textDocument/references` -> `PLS.find_references()`
- `textDocument/hover` -> `PLS.hover()`
- `textDocument/completion` -> `PLS.send_completions()`
- `textDocument/signatureHelp` -> `PLS.signature_help_proposals()`
- `textDocument/rename` -> `PLS.rename_edits()`
- `textDocument/codeAction` -> `PLS.get_code_actions()`
- `textDocument/documentLink` -> `PLS.document_links()`
- `textDocument/semanticTokens/full` -> `PLS.semantic_tokens()`

The helper methods mostly read from the parsed tree and the symbol table, so the server stays responsive once indexing has populated the caches.

## Startup sequence

The startup flow is worth understanding because it determines when diagnostics become available.

1. The client sends `initialized`.
2. `on_initialized()` schedules `PLS.start_up()`.
3. `start_up()` parses builtin predicates first, then discovers workspace `.pl` files, then indexes them with progress reporting.
4. Until indexing finishes, early analyses are tracked in `analysed_without_index_being_created` so they can be re-run once the graph is complete.

This is why a fresh workspace may show a brief indexing phase before all cross-file features settle.

## Editor integration

The VS Code extension is separate from the Python language server. Its only job is to start and restart the Python process with the configured executable path.

The extension code is in [editors/vscode/src/extension.ts](../editors/vscode/src/extension.ts). It wires the `pls.restartServer` command and passes workspace configuration to the server through `pls.*` settings.

## Where to look when changing behavior

- Startup or client/server lifecycle: [pls/main.py](../pls/main.py), [pls/server.py](../pls/server.py)
- Parse tree extraction: [pls/prolog_visitor.py](../pls/prolog_visitor.py)
- Symbol model and lookup logic: [pls/model.py](../pls/model.py)
- Dependency graph behavior: [pls/dependency_graph.py](../pls/dependency_graph.py)
- Shared tree and URI helpers: [pls/utils.py](../pls/utils.py)
- Analysis passes: [pls/passes](../pls/passes)
- Semantic tokens and highlighting: [pls/highlight](../pls/highlight)
- PlDoc parsing: [pls/pldoc_comment_visitor.py](../pls/pldoc_comment_visitor.py)

## Adding a new feature

If you want to add a new language-server capability, the usual path is:

1. Extract the needed information during parsing or by extending a visitor.
2. Store the result on the relevant `SymbolTable` or supporting model.
3. Add a method on `PLS` that computes the LSP response from the cached state.
4. Register a `@server.feature(...)` handler near the bottom of [pls/server.py](../pls/server.py).
5. If the feature depends on workspace-wide analysis, add or extend a pass in [pls/passes](../pls/passes).

Keeping feature logic in the cached model and request-specific logic in the handler makes the server easier to reason about.
