#! /bin/bash

echo "Packaging Extension Script"

mkdir -p dist
cd ./editors/vscode

npm install

vsce package --out ../../dist/pls-vscode-extension.vsix

