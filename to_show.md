
- [x] Multi file support an index is formed on server startup with all files
- [x] Progress update to the user while the project is being indexed
- [x] Dependency Graph of files contained in the project
- [x] Topologic sort of the dependencies to find correct order of analysis
- [x] Consults working
- [x] Document Links for consults
- [x] Warning File not found in consult
- [x] Warning of Circular imports
- [x] Undefined Predicate (accross multiple files with consults and builtins)
- [x] Go to definition working multiple files
- [x] Find references working multiple files
- [x] Autocomplete (current file,consults,builtins, scope variables)
- [x] Signature Help 
- [x] Unused Variable Warning
- [x] Quickfix for unused variable
- [x] Rename for variables
- [x] Rename for predicates (also renames the predicate name in pldoc comment)


## Final TODO


- [x] Document Link for use_module
    - [ ] Link should maybe only appear on the path not on the entire functor
- [x] Generate Comment Template
- [x] Export Predicate
- [x] Code actions to appear in the correct position (not everywhere)
- [x] The functionality of storing comments that came before a predicate was lost -> recover
- [x] Disable hover that shows node information
- [x] Ability to not rename library defined predicates
- [x] Fix hardcoded paths
- [x] Neovim Instalation script
- [ ] Fix comment parser stalling
- [ ] Comments and operators and operator autocompletion
- [ ] Ship application -> make it easily installable
- [ ] In what other editors could this be used
- [ ] Add extra libraries
- [ ] Check hover
- [ ] Check signature help
- [ ] check go to definition and references
- [ ] check rename


### Notes



- [x] Pygls (with just connection capabilities)
- [x] Vscode Extension
- [ ] CI/CD
    - [x] Automatic release of vscode extension
- [x] Treesitter Inclusion
- [x] Using Treesitter to Parse Prolog Files
- [x] Parsing Diagnostics
- [x] Go to definition
    - [x] Working on predicates
    - [x] Variables
- [x] Find References
- [ ] Call Hierarchy
- [ ] Handling Lists
- [ ] Neovim Extension
- [x] Syntax highlighting 
- [ ] Parsing Tests
- [ ] Rename
- [ ] Parsing comments
- [x] Hover information
    - With basic comment information
- [ ] Completion
- [ ] Cut operator (red/green).
- [ ] Determinism analysis.
- [x] Unused variables
- [ ] Detect and report this:
```
Warning: /home/martim/Desktop/pls/examples/go_to_definition.pl:23:
Warning:    Clauses of list/1 are not together in the source-file
Warning:    Earlier definition at /home/martim/Desktop/pls/examples/go_to_definition.pl:11
Warning:    Current predicate: hello/0
Warning:    Use :- discontiguous list/1. to suppress this message
```
- [ ] Predicate does not exist
    - Is it imported
    - Is it a typo
    - Is it dynamic
- [ ] Handle discontiguous directives
- [ ] Handle dynamic directives
- [ ] Handle operator directives

- [x] Parse Sicstus documentation
    -  [ ] Use llm to generate documentation?
- [ ] Redifining predicates
- [ ] handling is operator
    - Lhs must be a variable that is not grounded
    - rhs must not contain functors
    - X is X + Y.
    - `=:=` in place of is when comparisons are made
    - `H is '0'`
- [ ] Coding Format (covington rules)
- [ ] List notation common erros:
    - `[X]` or any list literal on the right side of `|`
    - list separator must be `,`
- [ ] Horn clause list must be a list of callables.
- Execute Command for recursion analysis
- Modules vs consult
- Less than operator -> warning for not being defined, suggestion for correct operator
- Is cut really necessary


## Cases

- Single Equals
- Double Equals
- `is` when no operations is made
- `true`
- duplicated code detection
- extract predicate
- grounded predicates should be first "input before output"
- basically "renaming" predicates
- snippets.
- warning/info where predicates clash.
- 
- Ref style Proceedings of the `<Full Name of the Conference> (<Sigla>), <Data da Conf>, <Local da Conf>\`

##  TODO

- [x] VScode Restart Server command
- [x] commandline option to start server in debug mode
- [x] understand `|` 
- [x] understand why other examples are not working
- [x] hover documentation (just for example the token type)
- [x] hover documentation using the above and in between comments
- [x] parse comments
- [x] sicstus documentation parsing
- `[X1,X1|XS]` not working error

- [ ]  Highlight Unused Variables
- [ ]  Actions for unused variables, add underscore substitute with underscore see if there is a similar variable.


## Highlighting


- [x] Predicates
    - [ ] undefined predicates
    - [ ] predicates
    - [ ] builtin
    - [ ] meta predicartes
- [ ] Atoms
    - [ ] difference between and predicates
- [x] Operators
    - Every operator being highlighted the same
- [x] Integers
- [x] Strings
- [x] Variables
- [x] Parameters
- [ ] Unused