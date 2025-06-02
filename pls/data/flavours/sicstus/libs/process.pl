:- module(process, [
	process_create/2,process_create/3,process_wait/2,
	process_wait/3,process_id/1,process_id/2,
	is_process/1,process_release/1,process_kill/1,
	process_kill/2
]).


%! process_create(+File, +Args)
%! process_create(+File, +Args, :Options)
%
% Start a new process running the program identified by File and the arguments specified in Args.
% The standard streams of the new process can be redirected to prolog streams.
% The exit status of the process can be obtained with `process_wait/[2,3]`.
%
% File, is expanded as if by `absolute_file_name/2` (with arguments `access(execute)` and `file_type(executable)`) and is used to locate the file to execute.
%
% The predefined file search path `path/1` is especially useful here since it makes it easy to look up the names of an executable in the directories mentioned by the `PATH` environment variable.
% To run the Windows command shell `cmd` you would simply specify `path('cmd.exe')` (or `path(cmd)`), to start the UNIX Bash shell you would specify `path(bash)`.
%
% Args is a list of argument specifications. Each argument specification is either a simple argument specification, or a non-empty list of simple argument specifications. The expanded value of each element of Args is concatenated to produce a single argument to the new process.
% A *simple argument specification* can be one of:
%
% * an atom: The atom name is used as the expanded value. Some operating systems only support 7-bit ASCII characters here. Even when some larger subset of Unicode is used it may not work correctly with all programs.
% * `file(File)`: File, an atom, is treated as a file name and subject to an operating system specific transformation to ensure file name syntax and character set is appropriate for the new process. This is especially important under Windows where it ensures that the full Windows Unicode character set can be used.
%   Please note: The File part of `file(File)` is not subject to syntactic rewriting, the argument specification `file/1` only adjusts for differences in file name syntax and file encoding between SICStus and the operating system. You must explicitly call `absolute_file_name/[2,3]` if you want to expand file search paths etc.
%
% Options is a list of options:
%
% * `stdin(Spec)`: Specifies how the corresponding standard stream of the new process should be created.
% * `stdout(Spec)`: Specifies how the corresponding standard stream of the new process should be created.
% * `stderr(Spec)`: Specifies how the corresponding standard stream of the new process should be created.
%   Spec can be one of:
%   * `std`: The new process shares the (OS level) standard stream with the Prolog process. This is the default. Note that, especially under Windows, the Prolog process may not have any OS level standard streams, or the OS streams may not be connected to a console or terminal. In such a case you need to use `pipe/[1,2]` spec, see below, and explicitly read (write) data from (to) the process.
%   * `null`: The stream is redirected to a null stream, i.e. a stream that discards written data and that is always at end of file when read.
%   * `pipe(Stream)`: A new Prolog stream is created and connected to the corresponding stream of the new process. This stream must be closed using `close/[1,2]`, it is not closed automatically when the new process exits.
%   * `pipe(Stream, StreamOptions)`: A new Prolog stream is created and connected to the corresponding stream of the new process. StreamOptions is a list of options affecting the created stream. The supported stream options are: `type/1`, `eol/1`, and `encoding/1`, with the same meaning as for `open/4`. The default, if no stream options are specified, is to use a text stream with the OS default character encoding.
% * `wait(-ExitStatus)`: The call will not return until the sub-process has terminated. ExitStatus will be bound to the exit status of the process, as described for `process_wait/2`.
% * `process(Proc)`: Proc will be bound to a process reference that can be used in calls to `process_wait/[2,3]` etc.. This process reference must be released, either explicitly with `process_release/1` or implicitly by `process_wait/[2,3]`. It is often easier to use the `wait/1` option if you just want to wait for the process to terminate.
% * `detached(Bool)`: Bool is either `true` or `false`. Specifies whether the new process should be “detached”, i.e. whether it should be notified of terminal events such as `^C` interrupts. By default a new process is created detached if none of the standard streams are specified, explicitly or implicitly, as `std`.
% * `cwd(CWD)`: CWD is expanded as if by `absolute_file_name/2` and is used as the working directory for the new process. By default, the working directory is the same as the Prolog working directory.
% * `window(Bool)`: Bool is either `true` or `false` (the default). Specifies whether the process should open in its own window. Specifying `window(true)` may give unexpected results if the standard stream options `stdin/1`, `stdout/1` and `stderr/1` are specified with anything but their default value `std`. Currently only implemented on Windows.
% * `environment(Env)`: Env is a list of `VAR=VALUE` for extra environment variables to pass to the sub-process in addition to the default process environment. VAR should be an atom. VALUE should be an argument specification, as described above. The VALUE is typically an atom but, especially on the Windows platform, it may be necessary to wrap file names in `file/1` to ensure file paths are converted to the native format.
%
% Examples:
% ```prolog
% % Run the `date` command in the standard shell ‘`sh`’. The output of the command is sent to the terminal:
% | ?- process_create(path(sh), ['-c', date]).
%
% % Run the `date` command in the standard shell ‘`sh`’. Wait for the command to terminate before returning to Prolog. Fail if the process gets an error. The output of the command is sent to the terminal:
% | ?- process_create(path(sh), ['-c', date], [wait(exit(0))]).
%
% % Run the `date` command in the standard shell ‘`sh`’. The output of the command is received by Prolog:
% | ?- process_create(path(sh), ['-c', date], [stdout(pipe(S))]), read_line(S,L), close(S), atom_codes(Date,L).
% % …,
% % Date = 'Fri Jan 24 12:59:26 CET 2014' ?
%
% % Pipe the output of the `date` command to a file:
% | ?- process_create(path(sh), ['-c', [date, '>', file('/tmp/foo.txt')]]).
%
% % Count the number of words in an atom, using the `wc` command:
% | ?- process_create(path(wc), ['-w'], [stdin(pipe(In)), stdout(pipe(Out))]), write(In, 'a b c\n'), close(In), read_line(Out, L), close(Out), number_codes(N, L).
% % …
% % N = 3
%
% % Count the number of unique words in a file, piping the output of the `uniq` command to the `wc` command:
% | ?- process_create(path(sh), ['-c', ['uniq ', file('/tmp/foo.txt'), ' | wc -w']], [stdout(pipe(Out))]), read_line(Out, L), close(Out), number_codes(N, L).
% % …
% % N = 6
%
% % Run the `make` command with the `-n` (dry run) option, discarding output, fail if it does not succeed:
% | ?- process_create(path(make), ['-n'], [stdout(null), wait(Exit)]), Exit = exit(0).
%
% % Run `ls` on a home directory in a subshell using the user’s preferred shell:
% | ?- process_create('$SHELL', ['-c', [ls, ' ', file('~/') ]]).
%
% % Run a command with output piped from a file and input provided by Prolog.
% % This is similar to `popen('cat > ./myscript.sh',write,S)` in SICStus 3.
% % This example also shows one way to create a shell script which is useful when more advanced shell interaction is needed.
% % (The created script outputs the most common line in its input. It is used in the next example.)
% | ?- process_create(path(sh), ['-c', 'cat > ./myscript.sh && chmod a+x ./myscript.sh'], [stdin(pipe(S))]), write(S, '#! /bin/sh\n'), write(S, 'sort | uniq -c | sort -nr | head -n 1\n'), close(S).
%
% % Run a shell script with input piped from a file and output read by Prolog.
% % This is similar to `popen('./myscript.sh < ./somefile.txt',read,S)` in SICStus 3.
% | ?- open('somefile.txt',write,OF), write(OF,'hello\nworld\nhello\nhello\n'),close(OF), process_create(path(sh), ['-c', './myscript.sh < ./somefile.txt'], [stdout(pipe(S))]), read_line(S, L), atom_codes(Line, L), close(S).
% % …,
% % Line = '   3 hello' ?
%
% % Run a goal in a SICStus subprocess (UNIX and Windows):
% | ?- process_create(application(sicstus), ['-f', '--noinfo', '--nologo', '--goal', 'read(X), call(X), halt.'], [stdin(pipe(In)), stdout(pipe(Out))]), format(In,'~q .~n', [(length([h,e,l,l,o], Len), format('~q .~n', [Len]))]), close(In), read(Out,Answer), close(Out).
% % …,
% % Answer = 5
%
% % Run `notepad.exe` on a file `C:/foo.txt` under Windows:
% | ?- process_create('$SYSTEMROOT/notepad.exe', [file('C:/foo.txt')]).
%
% % Open the default command shell under Linux or macOS:
% | ?- process_create('$SHELL', [], [wait(Result)]).
% % $ echo 'Hello World'
% % Hello World
% % $ exit 42
% % exit
% % Result = exit(42) ?
% % yes
% % | ?-
%
% % Open the default command shell under Windows, in the same command window as that used by SICStus:
% | ?- process_create('$COMSPEC',[],[wait(Result)]).
% % Microsoft Windows [Version 10.0.19043.1566]
% % (c) Microsoft Corporation. All rights reserved.
% %
% % c:\>ECHO "Hello World"
% % "Hello World"
% %
% % c:\>exit 42
% % Result = exit(42) ?
% % yes
% % | ?-
%
% % Open a command shell in a separate window under Windows, without waiting for the sub-process to exit:
% | ?- process_create('$COMSPEC',[],[window(true)]).
%
% % Example for Microsoft Windows Shell (creating a batch file):
% | ?- BatFileName='test.bat', open(BatFileName, write, S), write(S, 'date /T > "result.txt"\n'), close(S), process_create('$COMSPEC', ['/Q', '/C', file(BatFileName)], [wait(exit(0))]), open('result.txt', read, R), read_line(R,L),close(R),atom_codes(Date,L).
% % …,
% % Date = '2014-01-27 ',
% % … ?
%
% % Example for Microsoft Windows Shell (PowerShell - plain text command):
% | ?- Command = '(get-date).DayOfWeek', process_create(path(powershell), ['-Command', Command], [stdout(pipe(S))]), read_line(S,L),atom_codes(Day,L).
% % …,
% % Day = 'Monday',
% % … ?
%
% % Example for Microsoft Windows Shell (PowerShell - base64 encoded command):
% | ?- EncodedCommand = 'KABnAGUAdAAtAGQAYQB0AGUAKQAuAEQAYQB5AE8AZgBXAGUAZQBrAA==', process_create(path(powershell), ['-encodedCommand', EncodedCommand], [stdout(pipe(S))]), read_line(S,L),atom_codes(Day,L).
% % …,
% % Day = 'Monday',
% % … ?
% ```
% @param File *atom* or *compound*
% @param Args *list of term*
% @param Options *list of term*

%! process_wait(+Process, -ExitStatus)
%! process_wait(+Process, -ExitStatus, +Options)
%
% Wait for a process to exit and obtain the exit status.
%
% Process is either a process reference obtained from `process_create/3` or an OS process identifier.
% Specifying a process identifier is not reliable. The process identifier may have been re-used by the operating system.
% Under Windows, it is not possible to obtain the exit status using a process identifier if the process has already exited.
%
% ExitStatus is one of:
%
% * `exit(ExitCode)`: The process has exited with exit code ExitCode. By convention processes use exit code zero to signify success and a (positive) non-zero value to specify failure.
% * `killed(SignalNumber)`: UNIX only, the process was killed by signal SignalNumber (a positive integer).
% * `timeout`: The `timeout/1` option was specified and the process did not exit within the specified interval. In this case the process reference is not released, even if the `release/1` option is specified.
%
% Options is a list of options:
%
% * `timeout(Seconds)`: Specify a maximum time, in seconds, to wait for the process to terminate. Seconds should be an integer or floating point number or the atom `infinite` (the default) to specify infinite wait. If the specified timeout interval passes before the process exits, `process_wait/3` exits with ExitStatus set to `timeout` and the process reference is not released. Currently the UNIX implementation supports only timeout values 0 (zero) and `infinite`.
% * `release(Bool)`: Bool is either `true` (the default) or `false`. Specifies whether the process reference should be released when `process_wait/3` exits successfully.
% @param Process *atom* or *integer*
% @param ExitStatus *compound*
% @param Options *list of term*

%! process_id(-PID)
%
% Obtain the process identifier of the current (i.e. Prolog) process.
% @param PID *integer*

%! process_id(+Process, -PID)
%
% Obtain the process identifier of the process reference Process.
% @param Process *atom*
% @param PID *integer*

%! is_process(+Thing)
%
% Returns true if Thing is a process reference that has not been released.
% @param Thing *term*

%! process_release(+Process)
%
% Release a process reference Process that has previously been obtained from `process_create/3`.
% This ensures that Prolog and the operating system can reclaim any resources associated with the process reference.
% Usually you would not call this. Either do not request the process reference when calling `process_create/3` or let `process_wait/[2,3]` reclaim the process reference when the process terminates.
% @param Process *atom*

%! process_kill(+Process)
%! process_kill(+Process, +SignalSpec)
%
% Send a signal to the process designated by Process. The signal can either be a non-negative integer or a signal name as an (all uppercase) atom.
%
% The following signal names are accepted under UNIX if the platform defines them: `SIGABRT`, `SIGALRM`, `SIGBUS`, `SIGCHLD`, `SIGCONT`, `SIGFPE`, `SIGHUP`, `SIGILL`, `SIGINT`, `SIGKILL` (the default), `SIGPIPE`, `SIGPOLL`, `SIGPROF`, `SIGQUIT`, `SIGSEGV`, `SIGSTOP`, `SIGSYS`, `SIGTERM`, `SIGTRAP`, `SIGTSTP`, `SIGTTIN`, `SIGTTOU`, `SIGURG`, `SIGUSR1`, `SIGUSR2`, `SIGVTALRM`, `SIGXCPU` and `SIGXFSZ`. However, many of these do not make sense to send as signals.
%
% Under Windows, which does not have the signal concept, the signal name `SIGKILL` (the default) is treated specially and terminates the process with `TerminateProcess(Process, -1)`.
% Please note: Using `process_kill/[2,3]` on Windows is not recommended. Also, on Windows, the call may throw an error if the process has already exited.
% @param Process *atom* or *integer*
% @param SignalSpec *integer* or *atom*
