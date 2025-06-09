import { ExtensionContext, workspace, window, commands} from "vscode";
import {
  Executable,
  LanguageClient,
  LanguageClientOptions,
} from "vscode-languageclient/node";

let client: LanguageClient;
let log = window.createOutputChannel("pls");

export function activate(context: ExtensionContext) {
  log.appendLine("PLS Activation Event");

  workspace.onDidChangeConfiguration((event) => {
    let langServerAffected = event.affectsConfiguration("pls.executablePath");
    if (langServerAffected) {
      restartLanguageClient();
    }
  });

   const command = 'pls.restartServer';
  const commandHandler = restartLanguageClient;

  context.subscriptions.push(commands.registerCommand(command, commandHandler))

  restartLanguageClient();
}

async function restartLanguageClient(): Promise<void> {
  log.appendLine("Restarting language client");

  // Deactivate previously launched client.
  deactivate();

  // Get the editor configuration
  const config = workspace.getConfiguration("pls");
  log.appendLine(`PLS configuration ${config}`);


  let execString: string =
    process.env.PLS_EXECUTABLE_PATH|| config.get("executablePath") || "pls";

  
  log.appendLine(`Exec path: ${execString}`);
  const parts = execString.trim().split(/\s+/);
  let execPath = parts[0];
  let execArgs: Array<string> = parts.slice(1);

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