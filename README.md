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


