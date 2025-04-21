# pls
Prolog Language Server

## Installing the Language Server

- Clone, or download this repository
- Ensure you have python and pip installed
```
cd pls
pip install .
``` 

- pls  is now installed, and you may need to add the following line to your `bashrc` in order to make pip installables visible from your `$PATH`

```
echo 'PATH=#$HOME/.local/bin/:$PATH' >> ~/.bashrc
```

## Installing VS Code Extension

- Download the extension (`.vsix`) from the github release.

From the Extensions view in VS Code:
- Go to the Extensions view.
- Select Views and More Actions...
- Select Install from VSIX...

Or from the command line:

```
# if you use VS Code
code --install-extension pls-vscode-extension.vsix

# if you use VS Code Insiders
code-insiders --install-extension pls-vscode-extension.vsix
``` 


## Roadmap


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
- [ ] Unused variables
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

- [ ] Parse Sicstus documentation
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
- [ ] parse comments
- [ ] sicstus documentation parsing
- `[X1,X1|XS]` not working error

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
