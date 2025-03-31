import { ExtensionContext, workspace, window } from "vscode";
import {
  Executable,
  LanguageClient,
  LanguageClientOptions,
} from "vscode-languageclient/node";

let client: LanguageClient;
let log = window.createOutputChannel("pls");

export function activate(_context: ExtensionContext) {
  log.appendLine("PLS Activation Event");

  workspace.onDidChangeConfiguration((event) => {
    let langServerAffected = event.affectsConfiguration("pls.executablePath");
    if (langServerAffected) {
      restartLanguageClient();
    }
  });

  restartLanguageClient();
}

async function restartLanguageClient(): Promise<void> {
  log.appendLine("Restarting language client");

  // Deactivate previously launched client.
  deactivate();

  // Get the editor configuration
  const config = workspace.getConfiguration("pls");
  log.appendLine(`PLS configuration ${config}`);

  let execPath: string =
    process.env.PLS_EXECUTABLE_PATH|| config.get("executablePath") || "pls";
   let execArgs: Array<string> = ["-vv"];

  log.appendLine(`Exec path: ${execPath}`);
  log.appendLine(`Exec args: ${execArgs}`);

  // Configure how to start the server
  const serverExecutable: Executable = {
    command: execPath,
    args: execArgs,
  };

  // Register the server for prolog files
  let clientOptions: LanguageClientOptions = {
    documentSelector: [{ scheme: "file", language: "prolog" }],
  };

  // Create the language client and start the client
  client = new LanguageClient(
    "pls",
    "Prolog Language Server",
    serverExecutable,
    clientOptions
  );

  // Start the client. This will also launch the server
  await client.start();
}

export function deactivate(): Promise<void> | undefined {
  if (!client) {
    return undefined;
  }
  return client.stop();
}