# pls

Prolog Language Server.

## Installation

### Install the Language Server

- Clone or download this repository.
- Ensure Python and pip are installed.

#### Build Prerequisites

PLS depends on local `tree-sitter-prolog` and `tree-sitter-pldoc` packages, which are compiled during installation.

- Linux: a C toolchain (`gcc` or `clang`) is required.
- macOS: Xcode Command Line Tools are required.
- Windows: **Microsoft Visual C++ 14.0 or greater** is required.
- Recommended on Windows: install **Visual Studio Build Tools** with the **Desktop development with C++** workload.

If you see an error like `Microsoft Visual C++ 14.0 or greater is required`, install the Windows build tools above and run `pip install .` again.

```bash
cd pls-0.2.0
pip install .
```

If needed, add your local pip binary path to your shell profile:

```bash
echo 'PATH=$HOME/.local/bin/:$PATH' >> ~/.bashrc
```

### Install the VS Code Extension

Download the extension (`.vsix`) from the GitHub release and install it:

```bash
# VS Code
code --install-extension pls-vscode-extension.vsix

# VS Code Insiders
code-insiders --install-extension pls-vscode-extension.vsix
```

## Documentation

- [Editor Setup (VS Code, Neovim, custom startup command)](./docs/editor-setup.md)
- [Configuration and Troubleshooting](./docs/configuration.md)
- [Known Problems](./docs/configuration.md#known-problems)
- [PlDoc Support](./docs/pldoc.md)
- [Features (overview, full list, and examples)](./docs/features.md)
- [Language Server Architecture](./docs/language-server-architecture.md)

## Issues

If you find a bug or want a feature, please [open an issue](https://github.com/MartimVideira/pls/issues).