# pls
Prolog Language Server

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
- [ ] Treesitter Inclusion
- [ ] Neovim Extension
- [ ] Using Treesitter to Parse Prolog Files
- [ ] Parsing Diagnostics
- [ ] Parsing Tests
- [ ] Go to definition
