# Prolog Language Server (PLS) - Project Documentation

## Project Overview
A language server for Prolog implementing LSP (Language Server Protocol) features to enhance Prolog development in supported editors (primarily VSCode).

## Project Log

### Recent Development (May 2025)
- **May 27**: 
  - Added code action for unused variables (#65)
  - Implemented cross-file renaming with PLDoc template support (#63)
  - Improved signature help functionality (#62)
- **May 25-26**: 
  - Added autocomplete with templates and builtins support (#58)
  - Enhanced multi-file support with dependency graph (#57)
- **May 20-24**: 
  - Implemented unused variable warnings (#46)
  - Added PLDoc comment highlighting and hover information (#41-43)
  - Improved multi-file analysis with cyclic dependency detection (#53)

### April 2025
- Implemented semantic highlighting (#23)
- Added find references functionality (#18, #22)
- Developed go-to-definition for predicates and variables (#12)
- Integrated tree-sitter for syntax parsing (#10)

### March 2025
- Initial project setup
- First release and VSCode extension packaging (#7-9)
- Pygls MVP implementation (#6)

## Implemented Features

### Core Functionality
- Syntax error reporting via tree-sitter
- Document parsing and symbol analysis
- Multi-file support with dependency management
- Cyclic dependency detection

### Editor Features
- **Navigation**:
  - Go to definition (predicates, variables)
  - Find references
- **Code Intelligence**:
  - Hover information (with PLDoc support)
  - Signature help
  - Autocomplete (with templates)
- **Refactoring**:
  - Rename across files (with PLDoc support)
  - Code actions (e.g., unused variables)
- **Diagnostics**:
  - Undefined predicate warnings
  - Unused variable warnings
  - Invalid consult path warnings
- **Syntax Highlighting**:
  - Semantic highlighting for variables, predicates, etc.
  - PLDoc comment highlighting

### Infrastructure
- VSCode extension packaging
- Debug mode support
- Server restart capability

## Missing Features / Roadmap

### Planned Features
- More advanced refactoring capabilities
- Additional code actions
- Improved handling of dynamic predicates
- Better support for Prolog modules
- Enhanced documentation generation

### Known Limitations
- Issues with tree-sitter grammars
- Complete coverage of Prolog built-ins
- Advanced template support for all predicate types
- Full support for all Prolog dialects

## Technical Details
- **Backend**: Python with pygls (Python Language Server)
- **Parsing**: Tree-sitter with custom Prolog grammar
- **Documentation**: PLDoc integration with SICStus documentation scraper
- **Dependency Analysis**: Topological sort for file analysis order

---

*Documentation generated from commit history on May 27, 2025*