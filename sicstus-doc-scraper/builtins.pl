%!    abolish(+Predicates)
%!    abolish(+Predicates,+Options)
%
%     Removes procedures from the Prolog database.
%
%     @:Predicates   *pred\_spec* or *pred\_spec\_tree*
%     A predicate specification, or a list of such.
%     Note that the default is to only allow a single predicate
%     specification, see `tree/1` option below.
%     @Options       *list of term*, must be ground
%     A list of zero or more of the following:
%     `force(Boolean)`
%     Specifies whether SICStus Prolog is to abolish the predicate
%     even if it is static (`true`), or only if it is dynamic
%     (`false`). The latter is the default.
%     `tree(Boolean)`
%     Specifies whether the first argument should be a *pred\_spec\_tree*
%     (`true`), or a *pred\_spec* (`false`). The latter is the
%     default.

%!    abort
%
%     Abandons the current execution and returns to the beginning of the
%     current break level or terminates the enclosing query, whichever is closest.

%!    absolute_file_name(+RelFileSpec,-AbsFileName)
%!    absolute_file_name(+RelFileSpec,-AbsFileName,+Options)
%
%     Unifies AbsFileName with the absolute filename
%     that corresponds to the relative file specification RelFileSpec.
%
%     @RelFileSpec   *file\_spec*, must be ground
%     A valid file specification. See below for details.
%     @AbsFileName   *atom*
%     Corresponding absolute filename.
%     @Options       *list of term*, must be ground
%     A list of zero or more of the following.
%     The default is the empty list:
%     `extensions(Ext)`
%     Has no effect if FileSpec contains a file extension. Ext is
%     an atom or a list of atoms, each atom
%     representing an extension (e.g. `'.pl'`) that should be tried
%     when constructing the absolute file name. The extensions are tried in
%     the order they appear in the list. Default value is Ext \=
%     \[”], i.e. only the given FileSpec is tried, no extension is
%     added. To specify `extensions('')` or `extensions([])` is
%     equal to not giving any extensions option at all.
%     When case\-normalization is applied to the FileSpec, e.g. on Windows, each atom in Ext will also be case\-normalized before use.
%     That is, on Windows, specifying `extensions(['.pl'])` will typically give the same result as `extensions(['.PL'])`.
%     Prior to release 4\.3 the `extensions/1` option was always case sensitive, also on Windows.
%     `file_type(Type)`
%     Picks an adequate extension for the operating system currently running,
%     which means that programs using this option instead of
%     `extensions(Ext)` will be more portable between operating systems.
%     This extension mechanism has no effect if FileSpec contains a file
%     extension. Type must be one of the following atoms:
%     `any`
%     `text`
%     implies `extensions([''])`.
%     FileSpec is a file without any extension. (Default)
%     `source`
%     implies `extensions(['.pro','.pl',''])`.
%     FileSpec is a Prolog source file, maybe with a ‘`.pro`’ or ‘`.pl`’ extension.
%     `object`
%     implies `extensions(['.po'])`.
%     FileSpec is a Prolog object file.
%     `saved_state`
%     implies `extensions(['.sav',''])`. FileSpec is a
%     saved state, maybe with a ‘`.sav`’ extension.
%     `foreign_resource`
%     FileSpec is a foreign language shared object file,
%     maybe with a system dependent extension.
%     `executable   since release 4.0.2`
%     FileSpec is an executable file,
%     maybe with a system dependent extension.
%     `directory`
%     implies `extensions([''])`.
%     This option has two effects. First, for an access option other than
%     `access(none)` the file must exist and be a directory. Second, the
%     returned file name will end in slash (`/`).
%     Only when this option is present can `absolute_file_name/3`
%     return the name of an existing directory with an access option other
%     than `access(none)` without raising an exception.
%     `glob(Glob)`
%     Match file names against a pattern. RelFileSpec will be expanded
%     to a directory and AbsFileName will be the absolute path to each
%     child that matches both the Glob pattern and any other filtering
%     option, like `access/1`, `extensions/1`, `file_type/1`,
%     …. The special children `.` and `..` will never be
%     returned.
%     The Glob should be an atom specifying a *glob pattern*
%     consisting of characters interpreted as follows:
%     * A ‘`*`’ matches any sequence of zero or more characters.
%     * A ‘`?`’ matches exactly one character.
%     * A ‘`{`’, ‘`}`’, ‘`[`’, ‘`]`’ currently matches
%     themselves but are reserved for future expansion of the allowable
%     patterns.
%     * Any other character matches itself.
%     With the options `solutions(all)` and `file_errors(fail)`
%     this can be used to enumerate the contents of a directory.
%     `access(Mode)`
%     Mode must be an atom or a list of atoms. If a
%     list is given, then AbsFileName must obey every specified option
%     in the list. This makes it possible to combine a read and write,
%     or write and exist check, into one call. If AbsFileName
%     specifies a directory and an access option other than
%     `access(none)` is specified, then a permission error is signaled
%     unless `file_type(directory)` is also specified.
%     Each atom must be one of the following:
%     `read`
%     AbsFileName must be readable and exist.
%     `write`
%     `append`
%     If AbsFileName exists, then it must be writable. If it doesn’t exist, then
%     it must be possible to create.
%     `exist`
%     The file represented by AbsFileName must exist.
%     `execute`
%     `executable`
%     The file represented by AbsFileName must be executable and exist.
%     This is ignored if `file_type(directory)` is also specified.
%     `search`
%     `searchable`
%     The directory represented by AbsFileName must be searchable and exist.
%     This is ignored unless `file_type(directory)` is also specified.
%     `none`
%     The file system is not accessed to determine existence or access properties of AbsFileName.
%     The first absolute file name that is
%     derived from FileSpec is returned. Note that if this option is
%     specified, then no existence exceptions can be raised. (Default)
%     **Please note:** Most current file systems have complex access
%     control mechanisms, such as access control lists (ACLs). These
%     mechanisms makes it hard to determine the effective access
%     permissions, short of actually attempting the file operations in
%     question. With networked file systems it may in fact be impossible to
%     determine the effective access rights.
%     Therefore, a simplified access control model is used by
%     `absolute_file_name/3` and elsewhere in SICStus.
%     On UNIX systems only the “classical” access control information is
%     used, i.e. the read/write/execute “bits” for owner/group/other.
%     Under Windows only the “FAT” access control information is used, i.e.
%     a file may be marked as read\-only.
%     A file is deemed executable if its extension is one of `.cmd`,
%     `.bat` or if it is classified as an executable by the Win32 API
%     `GetBinaryType`.
%     This may change to more faithfully reflect the effective permissions
%     in a future release.
%     `file_errors(Val)`
%     `fileerrors(Val)`
%     Val is one of the following, where the default is determined by the
%     current value of the `fileerrors` Prolog flag:
%     `error`
%     Raise an exception if a file derived from FileSpec
%     has the wrong permissions, that is, can’t be accessed at all, or doesn’t
%     satisfy the access modes specified with the `access` option.
%     This is the default if the Prolog flag `fileerrors` is set to its default value, `on`.
%     `fail`
%     Fail if a file derived from FileSpec has the wrong
%     permissions. Normally an exception is raised, which
%     might not always be a desirable
%     behavior, since files that do obey the access options might
%     be found later on in the search. When this option is given, the search
%     space is guaranteed to be exhausted.
%     This is the default if the Prolog flag `fileerrors` is set to `off`.
%     `solutions(Val)`
%     Val is one of the following:
%     `first`
%     As soon as a file derived from FileSpec is found, commit to that
%     file. Makes `absolute_file_name/3` determinate. (Default)
%     `all`
%     Return each file derived from FileSpec that is found. The files
%     are returned through backtracking. This option is probably most
%     useful in combination with the option `file_errors(fail)`.
%     `relative_to(FileOrDirectory)`
%     FileOrDirectory should be an atom, and controls how to
%     resolve relative filenames. If it is `''`, then file names will be
%     treated as relative to the current working directory. If a regular,
%     existing file is given, then file names will be treated as relative to the
%     directory containing FileOrDirectory. Otherwise, file names will
%     be treated as relative to FileOrDirectory.
%     If `absolute_file_name/3` is called from a goal in a file
%     being loaded, then the default is the directory containing that file,
%     accessible from the load context (`prolog_load_context/2`).
%     Otherwise, the default is the current working directory.
%     You can use `file_systems:current_directory/1` to obtain the
%     current working directory from a goal in a file being loaded.
%     `if_user(Val)   since release 4.3`
%     controls how to resolve the special file name `user`.
%     Val is one of the following:
%     `file`
%     Treat the name `user` like any other name, e.g. like `open/3` does.
%     This is the default.
%     `user`
%     Unifies AbsFileName with the atom `user` and ignores the other options.
%     This corresponds to the behavior prior to SICStus Prolog 4\.3\.
%     `error`
%     Treat the name `user` as a non\-existing file, subject to the `file_errors/1` option.

%!    acyclic_term(+Term)since release 4.3
%
%     Term is currently instantiated to a finite (acyclic) term.
%
%     @Term   *term*

%!    add_breakpoint(+Conditions,-BID)
%
%     Creates a breakpoint with Conditions and with identifier
%     BID.
%
%     @:Conditions   *term*.
%     Breakpoint conditions.
%     @BID           *integer*
%     Breakpoint identifier.

%!    +P,+Q
%
%     @:P   *callable*, must be nonvar
%     @:Q   *callable*, must be nonvar

%!    append(?List1,?List2,?List3)
%
%     @List1   *list of term*
%     @List2   *list of term*
%     @List3   *list of term*
%     A list consisting of List1 followed by List2.

%!    arg(+ArgNum,+Term,-Arg)
%
%     unifies Arg with the ArgNumth argument of term
%     Term.
%
%     @ArgNum   *integer*, must be nonvar and non\-negative.
%     @Term     *compound*, must be nonvar
%     @Arg      *term*

%!    ask_query(+QueryClass,+Query,+Help,-Answer)
%
%     Prints the question Query, then reads and processes user input
%     according to QueryClass, and returns the result of the processing,
%     the abstract answer term Answer. The Help message may
%     be printed in case of invalid input.
%
%     @QueryClass   *term*, must be nonvar
%     Determines the allowed values for the atom Answer.
%     @Query        *term*
%     A message term.
%     @Help         *term*
%     A message term.
%     @Answer       *term*
%     See QueryClass

%!    These predicates add a dynamic clause,Clause, to the Prolog database.  They optionally return a database
reference inRef:
%!    assert(+Clause)
%
%     `assert(+Clause, -Ref)`
%     It is undefined whether Clause will precede or follow the
%     clauses already in the database.
%
%     @:Clause   *callable*, must be nonvar
%     A valid dynamic Prolog clause.
%     @Ref       *db\_reference*, must be var
%     A database reference, which uniquely identifies the newly asserted Clause.

%!    These predicates add a dynamic clause,Clause, to the Prolog database.  They optionally return a database
reference inRef:
%!    asserta(+Clause)
%
%     `asserta(+Clause, -Ref)`
%     Clause will precede all existing clauses in the database.
%
%     @:Clause   *callable*, must be nonvar
%     A valid dynamic Prolog clause.
%     @Ref       *db\_reference*, must be var
%     A database reference, which uniquely identifies the newly asserted Clause.

%!    These predicates add a dynamic clause,Clause, to the Prolog database.  They optionally return a database
reference inRef:
%!    assertz(+Clause)
%
%     `assertz(+Clause, -Ref)`
%     Clause will follow all existing clauses in the database.
%
%     @:Clause   *callable*, must be nonvar
%     A valid dynamic Prolog clause.
%     @Ref       *db\_reference*, must be var
%     A database reference, which uniquely identifies the newly asserted Clause.

%!    at_end_of_line
%!    at_end_of_line(+Stream)
%
%     Test whether end of line has been reached for
%     the current input stream or for the input stream Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid Prolog input stream, defaults to the current input stream.

%!    at_end_of_stream
%!    at_end_of_stream(+Stream)
%
%     Tests whether the end has been reached for
%     the current input stream or for the input stream Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid Prolog input stream, defaults to the current input stream.

%!    atom(+Term)
%
%     Succeeds if Term is currently instantiated to an atom.
%
%     @Term   *term*

%!    atom_chars(+Atom,-Chars)
%
%     `atom_chars(-Atom, +Chars)`
%     Chars is the *chars* comprising the printed
%     representation of Atom.
%
%     @Chars   *chars*
%     The *chars*
%     comprising the printed representation of Atom.
%     @Atom    *atom*
%     The atom containing
%     exactly those characters, even if the characters look like the printed
%     representation of a number.

%!    atom_codes(+Atom,-Codes)
%
%     `atom_codes(-Atom, +Codes)`
%     Codes is the *codes* comprising the printed
%     representation of Atom.
%
%     @Codes   *codes*
%     The *codes*
%     comprising the printed representation of Atom.
%     @Atom    *atom*
%     The atom containing
%     exactly those characters, even if the characters look like the printed
%     representation of a number.

%!    atom_concat(+Atom1,+Atom2,-Atom12)
%
%     `atom_concat(-Atom1,-Atom2,+Atom12)`
%     The characters of the atom Atom1 concatenated with those of
%     Atom2 are the same as the characters of atom Atom12.
%
%     @Atom1    *atom*
%     @Atom2    *atom*
%     @Atom12   *atom*

%!    atom_length(+Atom,-Length)
%
%     Length is the number of characters of the atom Atom.
%
%     @Atom     *atom*, must be nonvar
%     @Length   *integer*

%!    atomic(+Term)
%
%     Succeeds if Term is currently
%     instantiated to an atom or a number.
%
%     @Term   *term*

%!    bagof(+Template,+Generator,-Set)
%
%     Like `setof/3` except that the list (or alternative lists)
%     returned will not be ordered, and may contain duplicates. This
%     relaxation saves time and space in execution.
%
%     @Template     *term*
%     @:Generator   *callable*, must be nonvar
%     A goal to be proved as if by `call/1`.
%     @Set          *list of term*, non\-empty set

%!    bb_delete(:Key,-Term)
%
%     If a term is currently stored under Key, then the term is deleted,
%     and a copy of it is unified with Term. Otherwise,
%     `bb_delete/2` silently fails.
%
%     @:Key   *bbkey*
%     @Term   *term*

%!    bb_get(:Key,-Term)
%
%     If a term is currently stored under Key, then a copy of it is unified
%     with Term. Otherwise, `bb_get/2` silently fails.
%
%     @:Key   *bbkey*
%     @Term   *term*

%!    bb_put(:Key,+Term)
%
%     A copy of Term is stored under Key in the source module
%     blackboard. Any previous term stored under the same Key is
%     simply deleted.
%
%     @:Key   *bbkey*
%     @Term   *term*

%!    bb_update(:Key,-OldTerm,+NewTerm)
%
%     If a term is currently stored under Key and unifies with
%     OldTerm, then the term is replaced by a copy of NewTerm.
%     Otherwise, `bb_update/3` silently fails. This predicate provides
%     an atomic swap operation.
%
%     @:Key      *bbkey*
%     @OldTerm   *term*
%     @NewTerm   *term*

%!    :- block+BlockSpec
%
%     Specifies conditions
%     for blocking goals of the predicates referred to by BlockSpec.
%
%     @:BlockSpec   *callable*, must be ground
%     Goal template or list of goal templates, of the form
%     `f(Arg1, Arg2,…)`.
%     Each Argn is one of:
%     ‘`-`’
%     part of a block condition
%     ‘`?`’
%     otherwise

%!    break
%
%     causes the current execution to be
%     interrupted; enters next break level.

%!    :- multifile user:breakpoint_expansion/2.
%
%     `user:breakpoint_expansion(+Macro, -Body)`
%     Defines debugger condition macros.
%
%     @Macro   *term*
%     Breakpoint test or action.
%     @Body    *term*
%     Expanded breakpoint test or action, may be composite.

%!    byte_count(+Stream,-Count)
%
%     Obtains the total number of bytes either input from or output to
%     the open binary stream Stream and unifies it with Count.
%
%     @Stream   *stream\_object*, must be ground
%     A valid open *binary* stream.
%     @Count    *integer*
%     The resulting byte count of the stream.

%!    call(+P)
%
%     Proves (executes) P.
%     `call(+P,?Q,...)`
%     Executes the goal obtained by
%     augmenting P by the remaining arguments.
%
%     @:P   *callable*, must be nonvar
%     @Q    term
%     ...

%!    Executes the procedure callGoal.  WhenGoalsucceeds
determinately, is cut, fails, or raises an exception,Cleanupis executed.
%
%     @:Goal      *callable*, must be nonvar
%     @:Cleanup   *callable*, must be nonvar

%!    Executes the procedure callGoal, unifyingVarswith
the list of residual variables that have blocked goals or attributes
attached to them.
%
%     @:Goal   *callable*, must be nonvar
%     @Vars    *list of var*

%!    callable(+Term)
%
%     Succeeds if Term is currently
%     instantiated to an atom or a compound term.
%
%     @Term   *term*

%!    catch(+ProtectedGoal,-Exception,+Handler)
%
%     Specify an exception handler for ProtectedGoal, and call
%     ProtectedGoal, as described in [ref\-ere](ref_002dere.html).
%
%     @:ProtectedGoal   *callable*, must be nonvar
%     @Exception        *term*
%     @:Handler         *callable*, must be nonvar

%!    char_code(+Char,-Code)
%
%     `char_code(-Char, +Code)`
%     Code is the character code comprising the printed
%     representation of Char.
%
%     @Char   *char*
%     The *char* whose code is Code.
%     @Code   *code*
%     The *code* corresponding to Char.

%!    char_conversion(+InChar,+OutChar)
%
%     The mapping of InChar to OutChar is added to the
%     character\-conversion mapping.
%
%     @InChar    *char*, must be nonvar
%     @OutChar   *char*, must be nonvar

%!    character_count(+Stream,-Count)
%
%     Obtains the total number of characters either input from or output to
%     the open text stream Stream and unifies it with Count.
%
%     @Stream   *stream\_object*, must be ground
%     A valid open *text* stream
%     @Count    *integer*
%     The resulting character count of the stream

%!    clause(+Head,-Body)
%!    clause(+Head,-Body,-Ref)
%
%     `clause(-Head, -Body, +Ref)`
%     Searches the database for a clause whose head matches Head
%     and whose body matches Body.
%
%     @:Head   *callable*
%     A term whose functor names a dynamic procedure.
%     @Body    *callable*
%     @Ref     *db\_reference*

%!    close(+Stream)
%!    close(+Stream,+Options)
%
%     closes the stream corresponding to Stream.
%
%     @Stream    *stream\_object*, must be ground
%     Stream or file specification.
%     @Options   *list of term*, must be ground
%     A list of zero or more of the following:
%     `force(Boolean)`
%     Specifies whether SICStus Prolog is to close the stream
%     forcefully, even in the presence of errors (`true`), or not
%     (`false`). The latter is the default. Currently this option has no
%     effect.
%     `direction(+Direction)`
%     Direction is an atom specifying the direction or directions to
%     close.
%     One of:
%     `input`
%     Close only the input direction, if open.
%     `output`
%     Close only the output direction, if open.
%     `all`
%     Close all directions. This is the default.
%     if stream is not open in the specified direction then the call to `open/4` does nothing.
%     Closing a single direction is mainly useful when dealing with
%     bidirectional streams, such as sockets.

%!    compare(-Order,+Term1,+Term2)
%
%     succeeds if the result of comparing terms Term1 and
%     Term2 is Order
%
%     @Order   *order*
%     `=`
%     if Term1 is identical to Term2,
%     `<`
%     if Term1 is before Term2 in the standard order,
%     `>`
%     if Term1 is after Term2 in the standard order.
%     @Term1   *term*
%     @Term2   *term*

%!    compile(+Files)
%
%     Compiles the specified Prolog source file(s) into memory.
%
%     @:Files   *file\_spec* or *list of file\_spec*, must be ground
%     A file specification or a list of file specifications;
%     extensions optional.

%!    compound(+Term)
%
%     Term is currently instantiated to a compound term.
%
%     @Term   *term*

%!    consult(+Files)
%
%     Consults the specified Prolog source file(s) into memory.
%
%     @:Files   *file\_spec* or *list of file\_spec*, must be ground
%     A file specification or a list of file specifications;
%     extensions optional.

%!    copy_term(+Term,-Copy)
%!    UnifiesCopywith a copy ofTermin which all variables have been replaced by brand new variables,
and all mutables by brand new mutables.
%
%     `copy_term(+Term, -Copy, -Body)`
%     Furthermore, if Term contains variables with goals blocked on
%     them, or variables with attributes that can be interpreted as a goal
%     (see [lib\-atts](lib_002datts.html)), then Body is unified with the conjunction of
%     such goals. If no such goals are present, then Body is unified with
%     the atom `true`. The idea is that executing Body
%     will reinstate blocked goals and attributes on the variables in Copy
%     equivalent to those on the variables in Term.
%
%     @Term   *term*
%     @Copy   *term*
%     @Body   *callable*

%!    coverage_data(-Data)since release 4.2
%
%     Data is the coverage data accumulated so far.
%
%     @Data   *list of coverage\_pair*
%     where:
%     | coverage\_pair | ::\= `counter(filename,pred_spec,clauseno,lineno)-tagged_hits` |
%     | --- | --- |
%     | filename | ::\= atom {file containing coverage site} |
%     | clauseno | ::\= integer {file relative clause number containing coverage site} |
%     | lineno | ::\= integer {line of code containing coverage site} |
%     | tagged\_hits | ::\= `det(hits)` {no nondet calls made from site} |
%     |  | \| `nondet(hits)` {some nondet calls made from site} |
%     | hits | ::\= integer {number of times that coverage site was hit} |

%!    create_mutable(+Datum,-Mutable)
%
%     Mutable is a new mutable term with initial value Datum.
%
%     @Datum     *term*, must be nonvar
%     @Mutable   *mutable*

%!    current_atom(?Atom)
%
%     Atom is a currently existing atom.
%
%     @Atom   *atom*

%!    current_breakpoint(-Conditions,-BID,-Status,-Kind,-Type)
%
%     There is a breakpoint with conditions Conditions, identifier
%     BID, enabledness Status, kind Kind, and type Type.
%
%     @:Conditions   *term*
%     Breakpoint conditions.
%     @BID           *integer*
%     Breakpoint identifier.
%     @Status        *one of `[on,off]`*
%     `on` for enabled breakpoints and `off` for disabled ones
%     @Kind          *one of `[plain(MFunc),conditional(MFunc),generic]`*
%     MFunc is the module qualified functor of
%     the specific breakpoint.
%     @Type          *one of `[debugger,advice]`*

%!    current_char_conversion(?InChar,?OutChar)
%
%     InChar is currently mapped to OutChar in the
%     character\-conversion mapping, where the two are distinct.
%
%     @InChar    *char*
%     @OutChar   *char*

%!    current_input(-Stream)
%
%     unifies Stream with the current input stream.
%
%     @Stream   *stream\_object*

%!    current_key(?KeyName,?KeyTerm)
%
%     Succeeds when KeyName is the name of KeyTerm, and
%     KeyTerm is a recorded key.
%
%     @KeyName   *atomic*
%     One of:
%     * KeyTerm, if KeyTerm is atomic; or
%     * the principal functor of KeyTerm, if KeyTerm is a compound term.
%     @KeyTerm   *term*
%     The most general form of the key for a currently recorded term.

%!    current_module(?ModuleName)
%!    Queries whether a module is “current” or backtracks through all
of the current modules.
%
%     `current_module(?ModuleName, ?AbsFile)`
%     Associates modules with their module files.
%
%     @ModuleName   *atom*
%     @AbsFile      *atom*
%     Absolute filename in which the module is defined.

%!    current_op(?Precedence,?Type,?Name)
%
%     Succeeds when the atom Name is
%     currently an operator of type Type and precedence
%     Precedence.
%
%     @Precedence   *integer*, in the range 1\-1200
%     @Type         *one of `[xfx, xfy, yfx, fx, fy, xf, yf]`*
%     @Name         *atom*

%!    current_output(-Stream)
%
%     unifies Stream with the current output stream.
%
%     @Stream   *stream\_object*

%!    current_predicate(?PredSpec)
%!    UnifiesPredSpecwith
a predicate specifications of the formName/Arity.
%
%     `current_predicate(?Name, ?Term)`
%     Unifies Name with the name of a user\-defined predicate, and Term
%     with the most general term corresponding to that predicate.
%
%     @:PredSpec   *pred\_spec*
%     @Name        *atom*
%     @:Term       *callable*

%!    current_prolog_flag(?FlagName,?Value)
%
%     same as `prolog_flag(FlagName, Value)`, except that
%     `current_prolog_flag(FlagName, Value)` type checks FlagName.
%
%     @FlagName   *atom*
%     @Value      *term*

%!    current_stream(?AbsFile,?Mode,?Stream)
%
%     Stream is a stream, which is currently open on
%     file AbsFile in mode Mode.
%
%     @AbsFile   *atom*
%     Absolute filename.
%     @Mode      for streams opened with `open/[3,4]` this is
%     *one of `[read, write, append]`*.
%     For other streams Mode may have other values.
%     @Stream    *stream\_object*

%!    !
%
%     Cut.

%!    db_reference(+Term)since release 4.1
%
%     Term is currently instantiated to
%     a compound term with principal functor `'$ref'/2`
%     denoting a unique reference to a dynamic clause.
%
%     @Term   *term*

%!    debug
%
%     Turns on the debugger in debug mode.

%!    :- multifile user:debugger_command_hook/2.
%
%     `user:debugger_command_hook(+DCommand, -Actions)`
%     Allows the interactive debugger to be extended with user\-defined
%     commands. See [Debug Commands](Debug-Commands.html).
%
%     @DCommand   *term*
%     @Actions    *term*

%!    debugging
%
%     Prints out current debugging state

%!    dif(+X,+Y)
%
%     Constrains X and Y to represent different terms i.e.
%     to be non\-unifiable.
%
%     @X   *term*
%     @Y   *term*

%!    disable_breakpoints(+BIDs)
%
%     Disables the breakpoints specified by BIDs.
%
%     @BIDs   *list of integer*, must be ground
%     Breakpoint identifiers.

%!    :- discontiguous+PredSpecs
%
%     Declares the clauses of the predicates defined by PredSpecs to be
%     discontiguous in the source file (suppresses compile\-time warnings).
%
%     @:PredSpecs   *pred\_spec\_forest*, must be ground
%     A predicate specification, or a list of such,
%     or a sequence of such separated by commas.

%!    display(+Term)
%
%     Writes Term on the standard output stream, without quoting atoms,
%     in functional notation, without treating `'$VAR'/1` terms specially.
%     Since quoting is never used, even when needed for reading the term
%     back in, the standard predicate `write_canonical/1` is often preferable.
%
%     @Term   *term*

%!    (+Iteratordo+Body)
%
%     @+Iterator   *iterator*, must be nonvar
%     @:Body       *callable*, must be nonvar

%!    :- dynamic+PredSpecs
%
%     Declares the clauses of the predicates defined by PredSpecs to be
%     dynamic.
%
%     @:PredSpecs   *pred\_spec\_forest*, must be ground
%     A predicate specification, or a list of such,
%     or a sequence of such separated by commas.

%!    enable_breakpoints(+BIDs)
%
%     Enables the breakpoints specified by BIDs.
%
%     @BIDs   *list of integer*, must be ground
%     Breakpoint identifiers.

%!    ensure_loaded(+Files)
%
%     Loads the specified Prolog source and/or object file(s) into memory,
%     if not already loaded and up to date.
%
%     @:Files   *file\_spec* or *list of file\_spec*, must be ground
%     A file specification or a list of file specifications;
%     extension optional.

%!    +Expr1=:=+Expr2
%
%     Succeeds if the results of evaluating Expr1 and
%     Expr2 *are equal*.
%
%     @Expr1   *expr*, must be ground
%     @Expr2   *expr*, must be ground

%!    erase(+Ref)
%
%     Erases from the database the dynamic clause or recorded term referenced
%     by Ref.
%
%     @Ref   *db\_reference*, must be nonvar

%!    :- multifile user:error_exception/1.
%
%     `user:error_exception(+Exception)`
%     Tells the debugger to enter trace mode on exceptions
%     matching Exception.
%
%     @Exception   *term*

%!    execution_state(+Tests)
%!    Testsare satisfied in the current state of the execution.
%
%     `execution_state(+FocusConditions, +Tests)`
%     Tests are satisfied in the state of the execution pointed to by
%     FocusConditions.
%
%     @FocusConditions   *term*
%     @:Tests            *term*

%!    +X^+P
%
%     Equivalent to “there exists an X such that P is
%     true”, thus X is normally an unbound variable. The use of the
%     explicit existential quantifier outside `setof/3` and `bagof/3`
%     is superfluous.
%
%     @X    *term*
%     @:P   *callable*, must be nonvar

%!    expand_term(+Term1,-Term2)
%
%     Transforms source file terms into Prolog clauses before they are compiled.
%     Normally called by the compiler, but can be called directly. The transform
%     can be customized by defining `user:term_expansion/6`.
%     When a source file is loaded, except by `:- include`,
%     `expand_term/2` is called with the virtual clauses
%     `beginning_of_file` before and `end_of_file` after the real
%     Prolog clauses, to give `user:term_expansion/6` an opportunity to
%     perform some action at the beginning and end of a source
%     file. **Please note**: the virtual clause
%     `beginning_of_file` is “seen” *before* any module
%     declaration, i.e. before the source module has been updated.
%
%     @Term1   *term*
%     @Term2   *term*

%!    fail
%
%     Always fails.

%!    false
%
%     Always fails (same as `fail/0`).

%!    :- multifile user:file_search_path/2.
%
%     `user:file_search_path(+PathAlias, +DirSpec)`
%     Defines a symbolic name for a directory or a path. Used by
%     predicates taking *file\_spec* as input argument.
%
%     @PathAlias   *atom*
%     An atom that represents the path given by DirSpec.
%     @DirSpec     *file\_spec*
%     Either an atom giving the path to
%     a file or directory, or PathAlias(DirSpec), where PathAlias is
%     defined by another `file_search_path/2` rule.

%!    findall(+Template,+Generator,-List)
%!    findall(+Template,+Generator,-List,+Remainder)
%
%     List is the list of all the instances of Template for
%     which the goal Generator succeeds, appended to Remainder.
%     Remainder defaults to the empty list.
%
%     @Template     *term*
%     @:Generator   *callable*, must be nonvar
%     A goal to be proved as if by `call/1`.
%     @List         *list of term*
%     @Remainder    *list of term*

%!    float(+Term)
%
%     Term is currently instantiated to a float.
%
%     @Term   *term*

%!    flush_output
%!    flush_output(+Stream)
%
%     Forces the buffered output of the stream Stream (defaults to the
%     current output stream) to be sent to the associated device.
%
%     @Stream   *stream\_object*, must be ground
%     A valid Prolog stream, defaults to the current output stream.

%!    :- discontiguous foreign/2, foreign/3.
%!    foreign(+Routine,+ForeignSpec)
%
%     `foreign(+Routine, +Language, +ForeignSpec)`
%     Describes the interface between Prolog and the foreign Routine.
%     Used by `load_foreign_resource/1`.
%
%     @Routine       *atom*, must be nonvar
%     An atom that names a foreign code Routine.
%     @Language      *atom*, must be nonvar
%     An atom that names the Language
%     in which Routine is written. Can only be `c`.
%     @ForeignSpec   *foreign\_spec*, must be ground
%     A ground term of the form PredName(Argspec, …,
%     Argspec) as described in [Conversions between Prolog Arguments and C Types](Conversions-between-Prolog-Arguments-and-C-Types.html). Each Argspec should be a *foreign\_arg*.

%!    :- discontiguous foreign_resource/2.
%
%     `foreign_resource(+ResourceName, +ForeignFunctions)`
%     Describes the foreign functions in ResourceName to interface to.
%
%     @ResourceName       *atom*, must be nonvar
%     @ForeignFunctions   *list of atom*, must be ground
%     A list of foreign
%     function symbols that will be obtained from ResourceName.

%!    format(+Control,+Arguments)
%!    format(+Stream,+Control,+Arguments)
%
%     Interprets the Arguments according to the Control string and
%     prints the result on Stream.
%
%     @Stream       *stream\_object*, must be ground
%     Defaults to the current output stream.
%     @Control      *chars* or *codes* or *atom*, must be ground
%     A string, which can contain control sequences of the form
%     ‘`~N<c>`’:
%     \<c\>
%     a format control option
%     N
%     optional; if given, must be ‘`*`’ or an integer.
%     Any characters that are not part of a control sequence are written
%     to the specified output stream.
%     @:Arguments   *list of term*, must be proper list
%     List of arguments, which will be interpreted and
%     possibly printed by format control options.

%!    freeze(+Flag,+Goal)
%
%     Blocks Goal until Flag is bound.
%
%     @Flag    *term*
%     @:Goal   *callable*, must be nonvar

%!    frozen(+Term,-Goal)
%
%     Goal is unified with the conjunction of all goals blocked on some variable
%     that occurs in Term.
%
%     @Term   *term*
%     @Goal   *callable*

%!    functor(+Term, -Name, -Arity)
%
%     `functor(-Term, +Name, +Arity)`
%     Succeeds if the principal functor of term Term has name
%     Name and arity Arity.
%
%     @Term    *term*
%     @Name    *atom*
%     @Arity   *arity*

%!    garbage_collect
%
%     Invokes the garbage collector.

%!    garbage_collect_atoms
%
%     Invokes the atom garbage collector.

%!    :- multifile 'SU_messages':generate_message/3.
%
%     `'SU_messages':generate_message(+MessageTerm, -S0, -S)`
%     For a given MessageTerm, generates a list composed of
%     Control\-Arg pairs and the atom `nl`. This can be translated into a
%     nested list of Control\-Arg pairs, which can be used as input to
%     `print_message_lines/3`.
%
%     @MessageTerm   *term*
%     May be any term.
%     @S0            *list of pair*
%     The resulting list of Control\-Args pairs.
%     @S             *list of pair*
%     The remaining list.

%!    :- multifile user:generate_message_hook/3.
%
%     `user:generate_message_hook(+MessageTerm, -S0, -S)`
%     A way for the user to override the call to `'SU_messages':generate_message/3`
%     in `print_message/2`.
%
%     @MessageTerm   *term*
%     May be any term.
%     @S0            *list of pair*
%     The resulting list of Control\-Args pairs.
%     @S             *list of pair*
%     The remaining list.

%!    get_byte(-Byte)
%!    get_byte(+Stream,-Byte)
%
%     Unifies Byte with the next *byte* from
%     Stream or with \-1 if there are no more bytes.
%
%     @Stream   *stream\_object*, must be ground
%     valid input *binary* stream,
%     defaults to the current input stream.
%     @Byte     *byte* or \-1

%!    get_char(-Char)
%!    get_char(+Stream,-Char)
%
%     Unifies Char with the next *char* from Stream or
%     with `end_of_file` if there are no more characters.
%
%     @Stream   *stream\_object*, must be ground.
%     Valid input *text* stream,
%     defaults to the current input stream.
%     @Char     *char* or *one of \[`end_of_file`]*

%!    get_code(-Code)
%!    get_code(+Stream,-Code)
%
%     Unifies Code with the next *code* from
%     Stream or with \-1 if there are no more characters.
%
%     @Stream   *stream\_object*, must be ground
%     Valid input *text* stream,
%     defaults to the current input stream.
%     @Code     *code* or \-1

%!    get_mutable(-Datum,+Mutable)
%
%     Datum is the current value of the mutable term
%     Mutable.
%
%     @Datum     *term*, must be nonvar
%     @Mutable   *mutable*, must be nonvar

%!    M:goal_expansion(+Goal1,+Layout1,+Module,-Goal2,-Layout2)
%
%     Defines transformations on goals while clauses are being compiled or asserted,
%     and during meta\-calls at runtime.
%
%     @Goal1     *callable*
%     Goal to transform.
%     @Layout1   *term*
%     Layout of goal to transform.
%     @Module    *atom*
%     Source module of goal to transform.
%     @Goal2     *callable*
%     Transformed goal.
%     @Layout2   *term*
%     Layout of transformed goal.

%!    goal_source_info(+AGoal,-Goal,-SourceInfo)
%
%     Decompose the AGoal annotated goal into a Goal proper
%     and the SourceInfo descriptor term, indicating the source
%     position of the goal.
%
%     @AGoal        *callable*, must be nonvar
%     @Goal         *callable*
%     @SourceInfo   *term*

%!    +Expr1>+Expr2
%
%     Succeeds if the result of evaluating Expr1 is strictly
%     *greater than* the result of evaluating Expr2.
%
%     @Expr1   *expr*, must be ground
%     @Expr2   *expr*, must be ground

%!    ground(+Term)
%
%     Term is currently instantiated to a ground term.
%
%     @Term   *term*

%!    halt
%!    halt(+ExitCode)
%
%     Causes an exit from the running process.
%
%     @ExitCode   *integer*, must be nonvar
%     Exit status code. Only the lower 8 bits of this value is used.

%!    if(+P,+Q,+R)
%
%     *If* P *then* Q *else* R, for all solution of
%     P.
%
%     @:P   *callable*, must be nonvar
%     @:Q   *callable*, must be nonvar
%     @:R   *callable*, must be nonvar

%!    +P->+Q
%
%     When occurring other than as the first argument of a disjunction operator
%     (`;/2`), this is equivalent to:
%     ```
%     P -> Q ; fail.
%     ```
%
%     @:P   *callable*, must be nonvar
%     @:Q   *callable*, must be nonvar

%!    :- include+Files
%
%     Literally embed the Prolog clauses and
%     directives in Files into the file being loaded.
%     The file or files will be opened with default options.
%
%     @:Files   *file\_spec* or *list of file\_spec*, must be ground
%     A file specification or a list of file specifications;
%     extension optional.

%!    :- initialization+Goal
%
%     Declares that Goal is to be run when the file in which the
%     declaration appears is loaded into a running system, or when a
%     stand\-alone program or runtime system that contains the file is started
%     up.
%
%     @:Goal   *callable*, must be nonvar

%!    instance(+Ref,-Term)
%
%     Unifies Term with the
%     most general instance of the dynamic clause or recorded term indicated by
%     the database reference Ref.
%
%     @Ref    *db\_reference*, must be nonvar
%     @Term   *term*

%!    integer(+Term)
%
%     Term is currently instantiated to an integer.
%
%     @Term   *term*

%!    -Termis+Expression
%
%     Evaluates Expression as an arithmetic expression, and unifies
%     the resulting number with Term.
%
%     @Expression   *expr*, must be ground.
%     An expression made up of:
%     * functors representing arithmetic operations
%     * numbers
%     * variables bound to numbers or arithmetic expressions
%     @Term         *number*

%!    keysort(+Pairs,-Sorted)
%
%     Sorts the elements of the list Pairs into ascending
%     standard order (see [ref\-lte\-cte\-sot](ref_002dlte_002dcte_002dsot.html)) with respect to the key of
%     the pair structure.
%
%     @Pairs    *list of pair*, must be a proper list of proper pairs
%     @Sorted   *list of pair*

%!    leash(+Mode)
%
%     Starts leashing on the ports given by Mode.
%
%     @Mode   %     *list of one of
%     `[call,exit,redo,fail,exception,all,half,loose,tight,off]`*, must be ground
%     A list of the ports to be leashed.
%     A single keyword can be given without enclosing it in a list.

%!    length(?List,?Integer)
%
%     Integer is the length of List. If List is
%     instantiated to a proper *list of term*, or Integer to an integer, then
%     the predicate is determinate.
%
%     @List      *list of term*
%     @Integer   *integer*, non\-negative

%!    +Expr1<+Expr2
%
%     Evaluates Expr1 and Expr2 as arithmetic expressions.
%     The goal succeeds if the result of evaluating Expr1 is strictly
%     *less than* the result of evaluating Expr2.
%
%     @Expr1   *expr*, must be ground
%     @Expr2   *expr*, must be ground

%!    :- multifile user:library_directory/1.
%
%     `user:library_directory(+DirSpec)`
%     Defines a library directory. Used by predicates taking
%     *file\_spec* as input argument.
%
%     @DirSpec   *file\_spec*
%     Either an atom giving the path to
%     a file or directory, or PathAlias(DirSpec), where PathAlias is
%     defined by a `file_search_path/2` rule.

%!    line_count(+Stream,-Count)
%
%     Obtains the total number of lines either input from or output to
%     the open text stream Stream and unifies it with Count.
%
%     @Stream   *stream\_object*, must be ground
%     A valid open *text* stream.
%     @Count    *integer*
%     The resulting line count of the stream.

%!    line_position(+Stream,-Count)
%
%     Obtains the total number of characters either input from or output to
%     the current line of
%     the open text stream Stream and unifies it with Count.
%
%     @Stream   *stream\_object*, must be ground
%     A valid open *text* stream.
%     @Count    *integer*
%     The resulting line count of the stream.

%!    listing
%!    listing(+PredSpecs)
%
%     Prints the clauses of all the interpreted procedures currently in the
%     type\-in module of the Prolog database, or of PredSpecs, to the
%     current output stream, using `portray_clause/1`.
%
%     @:PredSpecs   *pred\_spec\_tree*
%     A predicate specification, or a list of such.

%!    load_files(+Files)
%!    load_files(+Files,+Options)
%
%     `[+Files]`
%     Loads the specified Prolog source and/or object file(s) into memory.
%     Subsumes all other load predicates.
%
%     @:Files    *file\_spec* or *list of file\_spec*, must be ground
%     A file specification or a list of file specifications;
%     extensions optional.
%     @Options   *list of term*, must be ground
%     A list of zero or more options of the form:
%     `if(X)`
%     `true` (the default) to always load, or `changed` to
%     load only if the file has not yet been loaded or if it has
%     been modified since it was last loaded. A non\-module file
%     is not considered to have been previously loaded if it was
%     loaded into a different module. The file specification `user` is
%     never considered to have been previously loaded.
%     `when(When)`
%     `always` (the default) to always load, or `compile_time`
%     to load only if the goal is not in the scope of another
%     `load_files/[1,2]` directive occurring in a PO file.
%     The latter is intended for use when the file only defines
%     predicates that are needed for proper term or goal
%     expansion during compilation of other files.
%     `load_type(LoadType)`
%     `source` to load source files only, `object` to
%     load object (PO) files only,
%     or `latest` (the default) to load any type of file, whichever is
%     newest. If the file specification is `user`, then `source` is forced.
%     `imports(Imports)`
%     `all` (the default) to import all exported
%     predicates if the file is a module file, or a list of
%     predicates to import.
%     `compilation_mode(Mode)`
%     `compile` to translate into compiled code, `consult` to
%     translate into static, interpreted code, or
%     `assert_all` to translate into dynamic, interpreted
%     code.
%     The default is the compilation mode of any ancestor
%     `load_files/[1,2]` goal, or `compile` otherwise. Note
%     that Mode has no effect when a PO file is
%     loaded, and that it is recommended to use `assert_all` in
%     conjunction with `load_type(source)`, to ensure that the source
%     file will be loaded even in the presence of a PO file.
%     In addition the `open/4` options `encoding/1`, `encoding_signature/1` and
%     `eol/1` can be specified. These will be used if the Prolog code is
%     loaded from a source file. See [mpg\-ref\-open](mpg_002dref_002dopen.html), for details.

%!    load_foreign_resource(:Resource)
%
%     Load the foreign resource Resource into Prolog. Relies on the
%     hook predicates `foreign_resource/2` and `foreign/[2,3]`.
%
%     @:Resource   *file\_spec*, must be ground
%     The foreign resource to be loaded. The file extension can be omitted.

%!    member(?Element,?List)
%
%     is true if Element occurs in the List. It may be used
%     to test for an element or to enumerate all the elements by backtracking.
%     Indeed, it may be used to generate the List!
%
%     @Element   *term*
%     @List      *list of term*

%!    memberchk(?Element,?List)
%
%     is true if the given Element occurs in the given
%     List. Its purpose is to test for membership. Normally, the two
%     arguments are ground.
%
%     @Element   *term*
%     @List      *list of term*

%!    :- multifile user:message_hook/3.
%
%     `user:message_hook(+Severity, +MessageTerm, +Lines)`
%     Overrides the call to `print_message_lines/3` in `print_message/2`.
%     A way for the user to intercept the Message of type
%     Severity, whose translations is Lines, before it is
%     actually printed.
%
%     @Severity      *one of `[informational,warning,error,help,silent]`*
%     @MessageTerm   *term*
%     @Lines         *list of list of pair*
%     Is of the form `[Line1, Line2, …]`, where each
%     Linei is of the form
%     `[Control_1-Args_1,Control_2-Args_2, …]`.

%!    :- meta_predicate+MetaSpec
%
%     Provides for module name expansion of arguments in calls to the
%     predicate given by MetaSpec. All `meta_predicate/1` declarations
%     should be at the beginning of a module.
%
%     @:MetaSpec   *callable*, must be ground
%     Goal template or list of goal templates, of the form
%     `functor(Arg1, Arg2,…)`.
%     Each Argn is one of:
%     ‘`:`’
%     requires module name expansion
%     If the argument will be treated as a goal, then it is better to
%     explicitly indicate this using an integer, see the next item.
%     nsuppressed
%     a non\-negative integer.
%     This is a special case of ‘`:`’ that means that the argument can be
%     made into a goal by adding nsuppressed additional
%     arguments. E.g., if the argument will be passed to `call/1`, then
%     `0` (zero) should be used.
%     As another example, the meta\_predicate declaration for the built\-in
%     `call/3` would be `:- meta_predicate call(2,?,?)`, since
%     `call/3` will add two arguments to its first argument in order to
%     to construct the goal to invoke.
%     An integer is treated the same as ‘`:`’ above by the SICStus
%     runtime. Other tools, such as the cross referencer (see [The Cross\-Referencer](The-Cross_002dReferencer.html)) and the SICStus Prolog IDE (see [SICStus
%     Prolog IDE](SPIDER.html)), will use this information to better follow predicate
%     references in analyzed source code.
%     ‘`*`’
%     ‘`+`’
%     ‘`-`’
%     ‘`?`’
%     ignored

%!    :- mode+Mode
%
%     Currently a dummy declaration.
%
%     @:Mode   *term*

%!    :- module(+ModuleName,+PublicPred).
%!    :- module(+ModuleName,+PublicPred,+Options).
%
%     Declares the file in which the declaration appears to be a
%     module file named ModuleName, with public predicates
%     PublicPred. Must appear as the first term in the file.
%
%     @ModuleName   *atom*, must be nonvar
%     @PublicPred   *list of simple\_pred\_spec*, must be ground
%     List of predicate specifications of the form Name/Arity.
%     @Options      *list of term*, must be ground
%     A list of zero or more options of the form:
%     `hidden(Boolean)`
%     Boolean is `false` (the default) or `true`. In the
%     latter case, tracing of the predicates of the module is
%     disabled (although spypoints can be set), and no source
%     information is generated at compile time.

%!    :- multifile+PredSpecs
%
%     Declares the clauses of the predicates defined by PredSpecs to be
%     multifile in the source file (suppresses compile\-time warnings).
%
%     @:PredSpecs   *pred\_spec\_forest*, must be ground
%     A predicate specification, or a list of such,
%     or a sequence of such separated by commas.

%!    mutable(+Term)
%
%     Succeeds if Term is currently instantiated to a mutable term.
%
%     @Term   *term*

%!    name(+Constant,-Codes)
%
%     `name(-Constant, +Codes)`
%     Codes is the list consisting of the *codes* comprising
%     the printed representation of Constant.
%
%     @Constant   *atomic*
%     @Codes      *codes*

%!    nl
%!    nl(+Stream)
%
%     Terminates the current output record on the current output stream
%     or on Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid output *text* stream, defaults to the current output stream.

%!    nodebug
%
%     Turns the debugger off.

%!    nonmember(?Element,?List)
%
%     is true if the given Element does not occur in the given
%     List. Its purpose is to test for membership. Normally, the two
%     arguments are ground.
%
%     @Element   *term*
%     @List      *list of term*

%!    nonvar(+Term)
%
%     Term is currently instantiated.
%
%     @Term   *term*

%!    nospy+PredSpecs
%
%     Any spypoints (plain and conditional) on the predicates
%     represented by PredSpecs are removed.
%
%     @:PredSpecs   *pred\_spec\_tree*
%     A predicate specification, or a list of such.

%!    nospyall
%
%     Removes all the spypoints (including the generic ones) that have
%     been set.

%!    +Expr1=\=+Expr2
%
%     Succeeds if the results of evaluating Expr1 and
%     Expr2 are *not equal*.
%
%     @Expr1   *expr*, must be ground
%     @Expr2   *expr*, must be ground

%!    +Expr1=<+Expr2
%
%     Succeeds if the result of evaluating Expr1 is *less
%     than or equal* to the result of evaluating Expr2.
%
%     @Expr1   *expr*, must be ground
%     @Expr2   *expr*, must be ground

%!    +Expr1>=+Expr2
%
%     Succeeds if the results of evaluating Expr1 and
%     Expr2 *are equal*.
%
%     @Expr1   *expr*, must be ground
%     @Expr2   *expr*, must be ground

%!    \++P
%
%     Fails if the goal P has a solution, and succeeds otherwise.
%     Equivalent to:
%     ```
%     call(P) -> fail ; true.
%     ```
%     except that the use of `call/1` often can be avoided.
%
%     @:P   *callable*, must be nonvar

%!    +Term1\=+Term2
%
%     Term1 and Term2 do not unify.
%
%     @Term1   *term*
%     @Term2   *term*

%!    notrace
%
%     Turns the debugger off.

%!    nozip
%
%     Turns the debugger off.

%!    number(+Term)
%
%     Term is currently instantiated to a number.
%
%     @Term   *term*

%!    number_chars(+Number,-Chars)
%
%     `number_chars(-Number, +Chars)`
%     Chars is the *chars* comprising the printed
%     representation of Number.
%
%     @Number   *number*
%     @Chars    *chars*

%!    number_codes(+Number,-Codes)
%
%     `number_codes(-Number, +Codes)`
%     Codes is the *codes* comprising the printed
%     representation of Number.
%
%     @Number   *number*
%     @Codes    *codes*

%!    numbervars(+Term,+FirstVar,-LastVar)
%
%     instantiates each of the variables in Term to a term of the form
%     `'$VAR'(N)`.
%
%     @Term       *term*
%     @FirstVar   *integer*, must be nonvar
%     @LastVar    *integer*

%!    on_exception(-Exception,+ProtectedGoal,+Handler)
%
%     same as:
%     `catch(ProtectedGoal, Exception, Handler)`
%     Specify an exception handler for ProtectedGoal, and call
%     ProtectedGoal, as described in [ref\-ere](ref_002dere.html).
%
%     @Exception        *term*
%     @:ProtectedGoal   *callable*, must be nonvar
%     @:Handler         *callable*, must be nonvar

%!    once(+P)
%
%     Equivalent to:
%     ```
%     call(P) -> true ; fail.
%     ```
%     except that the use of `call/1` often can be avoided.
%
%     @:P   *callable*, must be nonvar

%!    op(+Precedence,+Type,+Name)
%
%     declares Name to be an operator of the stated
%     Type and Precedence.
%
%     @Precedence   *integer*, must be nonvar and in the range 1\-1200
%     @Type         *one of `[xfx,xfy,yfx,fx,fy,xf,yf]`*, must be nonvar
%     @Name         *atom* or *list of atom*, must be ground

%!    open(+FileSpec,+Mode,-Stream)
%!    open(+FileSpec,+Mode,-Stream,+Options)
%
%     Creates a Prolog stream by opening the file FileSpec
%     in mode Mode with options Options.
%
%     @FileSpec   *file\_spec*, must be ground
%     A file specification.
%     @Mode       *one of `[read,write,append]`*, must be nonvar
%     An atom specifying the open mode of the target file.
%     One of:
%     `read`
%     open FileSpec for input.
%     `write`
%     open FileSpec for output.
%     A new file is created if FileSpec does not exist. If the file already
%     exists, then it is set to empty and its previous contents are lost.
%     `append`
%     opens FileSpec for output. If FileSpec
%     already exists, then it adds output to the end of it. If not, then a new file is created,
%     as for the `write` mode.
%     @Options    *list of term*, must be ground
%     A list of zero or more of the following.
%     `type(+T)`
%     Specifies whether the stream is a `text` or `binary`
%     stream. Default is `text`.
%     `reposition(+Boolean)`
%     Specifies whether repositioning is required for the stream
%     (`true`), or not (`false`). The latter is the default.
%     For text streams `reposition(true)` affects the default
%     `eol/1` and `encoding_signature/1` options, see below. Also, not all encodings supports this
%     option (see [ref\-iou\-sfh\-enc](ref_002diou_002dsfh_002denc.html)).
%     `alias(+A)`
%     Specifies that the atom A is to be an alias for the
%     stream.
%     `eof_action(+Action)`
%     Specifies what action is to be taken when the end of stream has
%     already been reported (by returning \-1 or `end_of_file`), and a
%     further attempt to input is made. Action can have the following
%     values:
%     `error`
%     An exception is raised. This is the default.
%     `eof_code`
%     An end of stream indicator (\-1 or `end_of_file`) is returned
%     again.
%     `reset`
%     The stream is considered not to be past end of stream and
%     another attempt is made to input from it.
%     `encoding(Encoding)`
%     Specifies the encoding to use if the stream is opened in text mode, as
%     an atom. The default is `'ISO-8859-1'`, the 8 bit subset of
%     Unicode, i.e. “ISO\-8859\-1” (Latin 1) (see [ref\-iou\-sfh\-enc](ref_002diou_002dsfh_002denc.html)).
%     Overridden by the `encoding_signature/1` option, see below.
%     `encoding_signature(+Boolean)`
%     Specifies whether an encoding signature should be used (`true`),
%     or not (`false`). An encoding signature is a special byte
%     sequence that identifies the encoding used in the file. The most
%     common case is one of the Unicode signatures, often called “byte
%     order mark” (BOM).
%     A Unicode signature is a special byte sequence that can be used to
%     distinguish between several UTF encoding variants, such as “UTF\-8”,
%     “UTF\-16\-BE” and “UTF\-16\-LE”.
%     If `reposition(true)` is specified, then
%     `encoding_signature/1` defaults to `false` for both streams
%     opened in write mode and streams opened in read mode.
%     If `reposition(true)` is not specified, and
%     if the file is opened in mode read, then `encoding_signature/1`
%     defaults to `true`.
%     When `encoding_signature/1` option is
%     `true` additional heuristics will be used if no Unicode signature
%     is detected. Only if neither a Unicode signature nor these heuristics
%     specifies a character encoding will the `encoding/1` option, if
%     any, be used.
%     The method used for selecting character encoding when a text file is
%     opened in mode `read` is the first applicable item in the
%     following list:
%     1. If the `encoding_signature/1` option is `true`:
%     If a byte order mark is detected, then it will be used to select
%     between the encodings “UTF\-8”, “UTF\-16” or “UTF\-32” with
%     suitable endianness.
%     2. If the `encoding_signature/1` option is `true`:
%     If an Emacs style ‘`-*- coding: coding-system-*-`’ is present on the first non\-empty line of the
%     file, then it will be used.
%     3. If an option `encoding(ENCODING)` Is supplied, then the specified encoding will be used.
%     4. As a final fallback, “ISO\-8859\-1” (Latin 1) will be used.
%     the character encoding selected in this way will be used if it is
%     recognized, otherwise an error exception is raised.
%     If `reposition(true)` is not specified, and
%     if the file is opened in mode write, then it depends on the character
%     encoding whether an encoding signature will be output by default or not. If you want
%     to force an encoding signature to be output for those encodings that supports it, then you
%     can specify `encoding_signature(true)`. Conversely, if you want to prevent an
%     encoding signature from being output, then you can explicitly specify `encoding_signature(false)`.
%     All UTF encodings supports an encoding signature in the form of a BOM. “UTF\-8” does not write a BOM unless
%     you explicitly specify `encoding_signature(true)`, the 16 and 32 bit UTF
%     encodings, e.g. “UTF\-16 BE”, “UTF\-32 LE” writes a BOM unless
%     explicitly requested not to with `encoding_signature(false)`.
%     If the file is opened in mode append, then `encoding_signature/1` defaults to
%     `false`.
%     `eol(Eol)`
%     Specifies how line endings in the file should be handled if the stream
%     is opened in text mode.
%     In Prolog code, end of line is always represented by the character
%     `'\n'`, which has character code 10, i.e. the same as ASCII Line
%     Feed (LFD). The representation in the file may be different, however.
%     Eol can have the following values:
%     `lf`
%     Line Feed (`LF`, character code 10\) is used to specify a end of line.
%     This can be used for both read mode and write mode streams.
%     `crlf`
%     A two character sequence Carriage Return (`CR`, character code 13\) followed
%     by Line Feed (`LF`, character code 10\) is used to specify a end of
%     line.
%     This can be used for both read mode and write mode streams.
%     `auto`
%     Translate both the two character sequence `CR` `LF` and single
%     `CR` or `LF` into an end of line character.
%     This can be used only for read mode streams.
%     `default`
%     Use a default end of line convention. This is the default.
%     If `reposition(true)` is specified, then this uses `lf` for
%     both streams opened in write mode and streams opened in read mode, on
%     all platforms.
%     If `reposition(true)` is not specified, then under
%     UNIX, this uses `lf` for streams opened in write mode and
%     `auto` for streams opened in read mode. Under Windows, this uses
%     `crlf` for streams opened in write mode and `auto` for
%     streams opened in read mode.
%     This can be used for both read mode and write mode streams.
%     `if_exists(+Action)`
%     Specifies what should happen if the file already exists. Only valid if
%     Mode is `write` or `append`. Action can have the
%     following values:
%     `default`
%     The file is overwritten or appended to, according to the Mode argument. This is the default.
%     `error`
%     An exception is raised.
%     `generate_unique_name`
%     If a file named FileSpec already exists, then FileSpec is
%     rewritten so that it refers to a non\-existing file. FileSpec is
%     rewritten by adding digits at the end of the file name (but before any
%     extension). The generated name, RealName can be obtained by using
%     `stream_property(Stream, file_name(RealName))` on the
%     resulting stream. See the example below.
%     With this option `open/4` will never open an existing file but it
%     may still fail to find a unique name. `open/4` may fail to find a
%     unique name if there are thousands of files with similar names. In
%     that case `open/4` behaves as if `if_exists(error)` had been
%     passed.

%!    open_null_stream(-Stream)
%
%     opens an output *text* stream that is not connected to any file and
%     unifies its stream object with Stream.
%
%     @Stream   *stream\_object*

%!    +Q;+R
%
%     Disjunction: Succeeds if Q succeeds *or* R succeeds.
%     \+P `->` \+Q `;` \+R
%     *If* P *then* Q *else* R, using first solution of
%     P only.
%
%     @:P   *callable*, must be nonvar
%     @:Q   *callable*, must be nonvar
%     @:R   *callable*, must be nonvar

%!    otherwise
%
%     Always succeeds (same as `true/0`).

%!    peek_byte(-Byte)
%!    peek_byte(+Stream,-Byte)
%
%     looks ahead for next input byte on the input stream Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid input *binary* stream, defaults to the current input stream.
%     @Byte     *byte* or \-1
%     The resulting next input byte available on the stream.

%!    peek_char(-Char)
%!    peek_char(+Stream,-Char)
%
%     looks ahead for next input character on the current input stream
%     or on the input stream Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid input *text* stream.
%     @Char     *char* or *one of \[`end_of_file`]*
%     The resulting next input character available on the stream.

%!    peek_code(-Code)
%!    peek_code(+Stream,-Code)
%
%     looks ahead for next input character on the input stream Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid input *text* stream, defaults to the current input stream.
%     @Code     *code* or \-1
%     The resulting next input character available on the stream.

%!    phrase(+PhraseType,+List)
%!    phrase(+PhraseType,+List,-Rest)
%
%     Used in conjunction with a grammar to parse or generate strings.
%
%     @:PhraseType   *callable*, must be nonvar
%     Name of a phrase type.
%     @List          *list of term*
%     A list of symbols — tokens or *codes*.
%     @Rest          *list of term*
%     A suffix of List; what remains of
%     List after PhraseType has been found.
%     Defaults to `[]`.

%!    :- multifile user:portray/1.
%
%     `user:portray(+Term)`
%     A way for the user to over\-ride the default behavior of `print/1`.
%
%     @Term   *term*

%!    portray_clause(+Clause)
%!    portray_clause(+Stream,+Clause)
%
%     Writes Clause to the current output stream. Used by
%     `listing/[0,1]`.
%
%     @Stream   *stream\_object*, must be ground
%     A valid open Prolog stream, defaults to the current output stream.
%     @Clause   *term*

%!    :- multifile user:portray_message/2.
%
%     `user:portray_message(+Severity, +MessageTerm)`
%     Called by `print_message/2` before processing the message. If this
%     succeeds, then it is assumed that the message has been processed and nothing
%     further is done.
%
%     @Severity      *one of `[informational,warning,error,help,silent]`*
%     @MessageTerm   *term*

%!    predicate_property(?Callable,?PredProperty)
%
%     Unifies PredProperty with a predicate property of an existing
%     predicate, and Callable with the most general term that corresponds
%     to that predicate.
%
%     @:Callable      *callable*
%     The skeletal specification of a loaded predicate.
%     @PredProperty   *term*
%     The various properties associated with
%     Callable. Each loaded predicate will have one
%     or more of the properties:
%     * one of the atoms `built_in` (for built\-in predicates)
%     or `compiled` or `interpreted` (for user defined
%     predicates) or `fd_constraint` for indexical predicates
%     see [Defining Indexical Constraints](Defining-Indexical-Constraints.html).
%     * the atom `dynamic` for predicates that have been
%     declared dynamic (see [Dynamic Declarations](Dynamic-Declarations.html)),
%     * the atom `multifile` for predicates that have been
%     declared multifile (see [Multifile Declarations](Multifile-Declarations.html)),
%     * the atom `volatile` for predicates that have been
%     declared volatile (see [Volatile Declarations](Volatile-Declarations.html)),
%     * the atom `jittable` for predicates that are amenable to JIT compilation,
%     * the atom `jitted` for predicates that have been JIT compiled,
%     * one or more terms `(block Term)` for predicates
%     that have block declarations (see [Block Declarations](Block-Declarations.html)),
%     * the atom `exported` or terms
%     `imported_from(ModuleFrom)` for predicates
%     exported or imported from modules (see [ref\-mod](ref_002dmod.html)),
%     * the term `(meta_predicate Term)` for predicates
%     that have meta\-predicate declarations (see [ref\-mod\-met](ref_002dmod_002dmet.html)).

%!    print(+Stream,+Term)
%!    print(+Term)
%
%     Writes Term on Stream, without quoting atoms,
%     calling `user:portray/1` on subterms.
%
%     @Stream   *stream\_object*, must be ground
%     A valid open Prolog stream, defaults to the current output stream.
%     @Term     *term*

%!    print_coveragesince release 4.2
%!    Prints the coverage data accumulated so far, to the current output
stream, in a hierarchical format.
%
%     `print_coverage(+Data)`   *since release 4\.2*
%     Prints the coverage data Data, to the current output stream, in
%     a hierarchical format. Data should be of type *list of
%     coverage\_pair*; see `coverage_data/1`.
%
%     @Data   *list of coverage\_pair*

%!    print_message(+Severity,+MessageTerm)
%
%     Print a Message of a given Severity. The behavior can be
%     customized using the hooks `user:portray_message/2`,
%     `user:generate_message_hook/3` and `user:message_hook/3`.
%
%     @Severity      *atom*, must be nonvar
%     Unless the default system portrayal is overridden with
%     `user:message_hook/3`, Severity must be one of:
%     **Value**
%     **Prefix**
%     `informational`
%     ‘`%` ’
%     `warning`
%     ‘`*` ’
%     `error`
%     ‘`!` ’
%     `help`
%     `query`
%     `silent`
%     no prefix
%     @MessageTerm   *term*

%!    print_message_lines(+Stream,+Severity,+Lines)
%
%     Print the Lines to Stream, preceding each line with a
%     prefix corresponding to Severity.
%
%     @Stream     *stream\_object*, must be ground
%     Any valid output stream.
%     @Severity   *one of `[query,help,informational,warning,error,silent,term]`*
%     @Lines      *list of list of pair*
%     Must be of the form `[Line1, Line2, …]`, where each
%     Linei must be of the form
%     `[Control_1-Args_1,Control_2-Args_2, …]`.

%!    print_profilesince release 4.2
%!    Prints the profiling data accumulated so far, to the current output
stream, in a format similar togprof(1).
%
%     `print_profile(+Data)`   *since release 4\.2*
%     Prints the profiling data Data, to the current output stream, in
%     a format similar to `gprof(1)`. Data should be of type
%     *list of profile\_pair*; see `profile_data/1`.
%
%     @Data   *list of profile\_pair*

%!    profile_data(-Data)since release 4.2
%
%     Data is the profiling data accumulated so far.
%
%     @Data   *list of profile\_pair*
%     where:
%     | profile\_pair | ::\= `caller-profile_info` |
%     | --- | --- |
%     | profile\_info | ::\= `counter(list of callee_pair,insns,chpts,tagged_calls)` |
%     | insns | ::\= integer {virtual instructions executed} |
%     | chpts | ::\= integer {choicepoints accessed} |
%     | callee\_pair | ::\= `callee-tagged_calls` |
%     | tagged\_calls | ::\= `det(calls)` {all calls were determinate} |
%     |  | \| `nondet(calls)` {not all calls were determinate} |
%     | calls | ::\= integer {number of calls} |
%     | caller | ::\= pred\_spec |
%     | callee | ::\= pred\_spec |

%!    profile_resetsince release 4.2
%
%     Resets all profiling data.

%!    prolog_flag(?FlagName,?Value)
%!    FlagNameis a flag, which currently is set toValue.
%
%     `prolog_flag(+FlagName, -OldValue, +NewValue)`
%     Unifies the current value of FlagName with OldValue
%     and then sets the value of the flag to NewValue.
%     The available Prolog flags are listed in [ref\-lps\-flg](ref_002dlps_002dflg.html).
%
%     @FlagName   *atom*, must be nonvar and a legal flag in `prolog_flag/3`
%     @Value      *term*
%     @OldValue   *term*
%     @NewValue   *term*, must be nonvar and belong to proper type/domain

%!    prolog_load_context(?Key,?Value)
%
%     Finds out the context of the current load.
%     The available context keys are described in [ref\-lps\-lco](ref_002dlps_002dlco.html).
%
%     @Key     *atom*
%     @Value   *term*

%!    prompt(-OldPrompt,+NewPrompt)
%
%     Queries or changes the prompt string of the current input stream or an
%     input stream Stream.
%
%     @OldPrompt   *atom*
%     The old prompt atom.
%     @NewPrompt   *atom*, must be nonvar
%     The new prompt atom.

%!    :- public+Term
%
%     Currently a dummy declaration.
%
%     @:Term   *term*

%!    put_byte(+Byte)
%!    put_byte(+Stream,+Byte)
%
%     Writes the byte Byte to Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid output *binary* stream, defaults to the current output stream.
%     @Byte     *byte*, must be nonvar

%!    put_char(+Char)
%!    put_char(+Stream,+Char)
%
%     The *char* Char is written to Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid output *text* stream, defaults to the current output stream.
%     @Char     *char*, must be nonvar

%!    put_code(+Code)
%!    put_code(+Stream,+Code)
%
%     The *code* Code is written to the stream Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid output *text* stream, defaults to the current output stream.
%     @Code     *code*, must be nonvar

%!    :- multifile 'SU_messages':query_abbreviation/3.
%
%     `'SU_messages':query_abbreviation(+QueryClass, -Prompt, -Pairs)`
%     A way to specify one letter abbreviations for responses to queries
%     from the Prolog System.
%
%     @QueryClass   *atom*
%     The query class being defined.
%     @Prompt       *atom*
%     The prompt to be used, typically indicating appropriate abbreviations.
%     @Pairs        *list of pair*
%     A list of word\-abbreviation pairs, defining the characters accepted
%     and the corresponding abstract answers.

%!    :- multifile 'SU_messages':query_class/5.
%
%     `'SU_messages':query_class(+QueryClass, -Prompt, -InputMethod, -MapMethod, -FailureMode)`
%     Access the parameters of a given QueryClass.
%
%     @QueryClass    *term*
%     Determines the allowed values for the atom Answer.
%     @Prompt        *atom*
%     The prompt to display at the terminal.
%     @InputMethod   *term*
%     A ground term, which specifies how to obtain
%     input from the user
%     @MapMethod     *term*
%     A ground term, which specifies how to process the
%     input to get the abstract answer to the query.
%     @FailureMode   *term*
%     An atom determining what to print in case of
%     an input error, before re\-querying the user. Possible values are:
%     * \- `help_query` \- print the help message and print the query text
%     again;
%     * \- `help` \- only print the help message;
%     * \- `query` \- only print the query text;
%     * \- `none` \- do not print anything.

%!    :- multifile user:query_class_hook/5.
%
%     `user:query_class_hook(+QueryClass, -Prompt, -InputMethod, -MapMethod, -FailureMode)`
%     Provides the user with a method of overriding the call to
%     `'SU_messages':query_class/5` in the preparation phase of query
%     processing. This way the default query class characteristics can be
%     changed.
%
%     @QueryClass    *term*
%     Determines the allowed values for the atom Answer.
%     @Prompt        *atom*
%     The prompt to display at the terminal.
%     @InputMethod   *term*
%     The input method to use.
%     @MapMethod     *term*
%     The map method to use.
%     @FailureMode   *term*
%     The failure mode to use.

%!    :- multifile 'SU_messages':query_hook/6.
%
%     `'SU_messages':query_hook(+QueryClass, +Prompt, +PromptLines, +Help, +HelpLines, -Answer)`
%     Provides a method of overriding Prolog’s default keyboard based
%     input requests.
%
%     @QueryClass    *term*
%     Determines the allowed values for the atom Answer.
%     @Prompt        *term*
%     A message term.
%     @PromptLines   *list of pair*
%     The message generated from the Prompt message term.
%     @Help          *term*
%     A message term.
%     @HelpLines     *list of pair*
%     The message generated from the Help message term.
%     @Answer        *term*
%     See QueryClass

%!    :- multifile 'SU_messages':query_input/3.
%
%     `'SU_messages':query_input(+InputMethod, +Prompt, -RawInput)`
%     Implements the input phase of query processing. The user is prompted
%     with Prompt, input is read according to InputMethod, and the
%     result is returned in RawInput.
%
%     @InputMethod   *term*
%     The input method to use.
%     @Prompt        *atom*
%     The prompt to display at the terminal.
%     @RawInput      *term*

%!    :- multifile user:query_input_hook/3.
%
%     `user:query_input_hook(+InputMethod, +Prompt, -RawInput)`
%     Provides the user with a method of overriding the call to
%     `'SU_messages':query_input/3` in the input phase of query
%     processing. This way the implementation of the default input methods
%     can be changed.
%
%     @InputMethod   *term*
%     The input method to use.
%     @Prompt        *atom*
%     The prompt to display at the terminal.
%     @RawInput      *term*

%!    :- multifile 'SU_messages':query_map/4.
%
%     `'SU_messages':query_map(+MapMethod, +RawInput, -Result, -Answer)`
%     Implements the mapping phase of query processing. The RawInput,
%     received from `query_input/3`, is mapped to the abstract answer
%     term Answer.
%
%     @MapMethod   *term*
%     The map method to use.
%     @RawInput    *atom*
%     As received from `query_input/3`.
%     @Result      *one of `[success,failure,failure(Warning)]`*
%     Result of conversion.
%     @Answer      *one of `[success,failure,failure(Warning)]`*
%     Abstract answer term.

%!    :- multifile user:query_map_hook/4.
%
%     `user:query_map_hook(+MapMethod, +RawInput, -Result, -Answer)`
%     Provides the user with a method of overriding the call to
%     `'SU_messages':query_map/4` in the map phase of query
%     processing. This way the implementation of the default map methods
%     can be changed.
%
%     @MapMethod   *term*
%     The map method to use.
%     @RawInput    *atom*
%     As received from `query_input/3`.
%     @Result      *one of `[success,failure,failure(Warning)]`*
%     Result of conversion.
%     @Answer      *one of `[success,failure,failure(Warning)]`*
%     Abstract answer term.

%!    raise_exception(+Exception)
%
%     @Exception   *term*, must be nonvar

%!    read(-Term)
%!    read(+Stream,-Term)
%
%     Reads the next term from Stream and unifies it with Term.
%     Same as:
%     `read_term(Term, [])`
%     `read_term(Stream, Term, [])`
%
%     @Stream   *stream\_object*, must be ground
%     A valid Prolog input stream, defaults to the current input stream.
%     @Term     *term*
%     The term to be read.

%!    read_line(-Line)
%!    read_line(+Stream,-Line)
%
%     Reads one line of input from Stream, and unifies the
%     *codes* with Line. On end of file, Line is unified with
%     `end_of_file`.
%
%     @Stream   *stream\_object*, must be ground
%     A valid input *text* stream, defaults to the current input stream.
%     @Line     *codes* or *one of \[`end_of_file`]*

%!    read_term(-Term,+Options)
%!    read_term(+Stream,-Term,+Options)
%
%     Read a term from Stream,
%     optionally returning extra information about the term.
%
%     @Stream    *stream\_object*, must be ground
%     A valid Prolog input stream, defaults to the current input stream.
%     @Term      *term*
%     The term that is read.
%     @Options   *list of term*, must be ground, except Vars, Names, and Layout
%     as described below.
%     A list of zero or more of the following:
%     `syntax_errors(Val)`
%     Controls what action to take on syntax errors. Val must be
%     one of the values allowed for the `syntax_errors` Prolog flag. The
%     default is set by that flag. See [ref\-lps\-flg](ref_002dlps_002dflg.html).
%     `variables(Vars)`
%     Vars is bound to the list of variables in the
%     term input, in left\-to\-right traversal order.
%     `variable_names(Names)`
%     Names is bound to a list of `Name=Var`
%     pairs, where each Name is an atom indicating the name of a
%     non\-anonymous variable in the term, and Var is the
%     corresponding variable.
%     The elements of the list are in the same order as in Term, i.e. in left\-to\-right traversal order.
%     `singletons(Names)`
%     Names is bound to a list of `Name=Var`
%     pairs, one for each non\-anonymous variable appearing only once in the term.
%     The elements of the list are in the same order as in Term, i.e. in left\-to\-right traversal order.
%     `cycles(Boolean)`
%     Boolean must be `true` or `false`. If selected, then any
%     occurrences of `@/2` in the term read in are replaced by the
%     potentially cyclic terms they denote as described below.
%     Otherwise (the default), Term is just unified with the
%     term read in.
%     The notation used when this option is selected is
%     `@(Template,Substitution)` where
%     Substitution is a list of Var\=Term pairs where
%     the Var occurs in Template or in one of the Terms.
%     This notation stands for the instance of Template obtained by
%     binding each Var to its corresponding Term. The
%     purpose of this notation is to provide a finite printed representation
%     of cyclic terms. This notation is not used by default, and
%     `@/2` has no special meaning except in this context.
%     Terms can be written in this notation using `write_term/[2,3]` (see [mpg\-ref\-write\_term](mpg_002dref_002dwrite_005fterm.html)).
%     `layout(Layout)`
%     Layout is bound to a *layout term* corresponding to
%     Term (see [Glossary](Glossary.html)).
%     `consume_layout(Boolean)`
%     Boolean must be `true` or `false`. If this option is
%     `true`, then `read_term/[2,3]` will consume the
%     layout\-text\-item that follows the terminating ‘`.`’ (this
%     layout\-text\-item can either be a layout\-char or a
%     comment starting with a ‘`%`’). If the option is `false`, then the
%     layout\-text\-item will remain in the input stream, so that
%     subsequent character input predicates will see it. The default of
%     the `consume_layout` option is `false`.

%!    reconsult(+Files)
%
%     same as:
%     `consult(Files)`
%
%     @:Files   *file\_spec* or *list of file\_spec*, must be ground
%     A file specification or a list of file specifications;
%     extensions optional.

%!    recorda(+Key,+Term,-Ref)
%
%     records the Term in the internal database as the first item
%     for the principal functor of Key; a database reference to the newly\-recorded
%     term is returned in Ref.
%
%     @Key    *term*, must be nonvar
%     @Term   *term*
%     @Ref    *db\_reference*, must be var

%!    recorded(-Key,-Term,+Ref)
%
%     `recorded(?Key, ?Term, ?Ref)`
%     Searches the internal database for a term recorded under the principal
%     functor of Key that unifies with Term, and whose database
%     reference unifies with Ref.
%
%     @Key    *term*
%     @Term   *term*
%     @Ref    *db\_reference*

%!    recordz(+Key,+Term,-Ref)
%
%     records the Term in the internal database as the last item
%     for the principal functor of Key; a database reference to the newly\-recorded
%     term is returned in Ref.
%
%     @Key    *term*, must be nonvar
%     @Term   *term*
%     @Ref    *db\_reference*, must be var

%!    remove_breakpoints(+BIDs)
%
%     Removes the breakpoints specified by BIDs.
%
%     @BIDs   *list of integer*, must be ground
%     Breakpoint identifiers.

%!    repeat
%
%     Succeeds immediately when called and whenever reentered by
%     backtracking.

%!    restore(+FileSpec)
%
%     Restores a saved state.
%
%     @FileSpec   *file\_spec*, must be ground
%     The name of a saved state, ‘`.sav`’ extension optional.

%!    retract(+Clause)
%
%     Removes the first occurrence of dynamic clause Clause from
%     module M.
%
%     @:Clause   *callable*, must be nonvar
%     A valid Prolog clause.

%!    retractall(+Head)
%
%     Removes every clause in module M whose head matches Head.
%
%     @:Head   *callable*, must be nonvar
%     Head of a Prolog clause.

%!    user:runtime_entry(Event)
%
%     This predicate is called upon start\-up of stand alone
%     applications. Currently, Event will be `start`, and the
%     hook is only called when the stand alone application starts (after any
%     saved state etc. has been loaded). In the future, other events may
%     be defined, e.g. when the application exits, so unknown values of
%     Event should be ignored. See [Mixing C and Prolog](Mixing-C-and-Prolog.html) for details.
%     A typical definition just calls the user\-defined code that should be
%     run on startup:
%     ```
%     user:runtime_entry(start) :-
%     start_my_program.
%     % This is the "real" program code.
%     start_my_program :-
%     write('Hello World\n').
%     ```
%     [|  |
%     | --- |](https://sicstus.sics.se/)
%     * [User's Manual](index.html#Top)
%     ---
%     * [Table of Contents](index.html#TOC)
%     Send feedback on this subject.

%!    save_files(+SourceFiles,+File)
%
%     Any code loaded from SourceFiles,
%     as well as from any file included by them,
%     is saved into File in PO format.
%
%     @SourceFiles   *file\_spec* or *list of file\_spec*, must be ground
%     A file specification or a list of file specifications;
%     extensions optional.
%     @File          *file\_spec*, must be ground
%     A file specification, ‘`.po`’ extension optional.

%!    save_modules(+Modules,+File)
%
%     Saves all predicates in Modules in PO format to File.
%
%     @Modules   *atom* or *list of atom*, must be ground
%     An atom representing a current module, or a list of such atoms
%     representing a list of modules.
%     @File      *file\_spec*, must be ground
%     A file specification, ‘`.po`’ extension optional.

%!    save_predicates(+PredSpecs,+File)
%
%     Saves all predicates in PredSpecs in PO format to File.
%
%     @:PredSpecs   *pred\_spec\_tree*
%     A predicate specification, or a list of such.
%     @File         *file\_spec*, must be ground
%     A file specification, ‘`.po`’ extension optional.

%!    save_program(+File)
%!    save_program(+File,+Goal)
%
%     Saves the state of the current execution in object format to
%     File. A goal, Goal, to be called upon
%     execution/restoring of the saved state, may be specified.
%
%     @File    *file\_spec*, must be ground
%     A file specification, ‘`.sav`’ extension optional.
%     @:Goal   *callable*, must be nonvar
%     A goal, defaults to `true`.

%!    see(+FileOrStream)Makes fileFileOrStreamthe current input stream.
%
%     @FileOrStream   *file\_spec* or *stream\_object*, must be ground

%!    seeing(-FileOrStream)
%
%     Unifies FileOrStream with the current input stream or file.
%
%     @FileOrStream   *file\_spec* or *stream\_object*

%!    seek(+Stream,+Offset,+Method,-NewLocation)
%
%     Seeks to an arbitrary position in Stream.
%
%     @Stream        *stream\_object*, must be ground
%     A valid Prolog stream.
%     @Offset        *integer*, must be nonvar
%     The offset, in *items*, to seek relative to the specified Method.
%     Items are bytes for binary streams, characters for text streams.
%     @Method        *one of `[bof,current,eof]`*, must be nonvar
%     Where start seeking, one of the following:
%     `bof`
%     Seek from beginning of the file stream.
%     `current`
%     Seek from current position of the file stream.
%     `eof`
%     Seek from end of the file stream.
%     @NewLocation   *integer*
%     The offset from beginning of the file after
%     seeking operation.

%!    seen
%
%     Closes the current input stream.

%!    set_input(+Stream)
%
%     makes Stream the current input stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid input stream.

%!    set_module(+ModuleName)
%
%     Changes the type\-in module (see [ref\-mod\-tyi](ref_002dmod_002dtyi.html)) to
%     ModuleName. Thus subsequent top\-level goals use ModuleName as
%     their source module.
%
%     @ModuleName   *atom*, must be nonvar
%     The name of a module.

%!    set_output(+Stream)
%
%     makes Stream the current output stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid output stream.

%!    set_prolog_flag(+FlagName,+Value)
%
%     same as:
%     `prolog_flag(FlagName, _, Value)`
%
%     @FlagName   *atom*, must be nonvar
%     @Value      *term*, must be nonvar and belong to proper type/domain

%!    set_stream_position(+Stream,+Position)
%
%     Sets the current position of Stream to Position.
%
%     @Stream     *stream\_object*, must be ground
%     An open stream.
%     @Position   *term*
%     Stream position object representing the
%     current position of Stream.

%!    setof(+Template,+Generator,-Set)
%
%     Returns the non\-empty set Set of all instances of Template such
%     that Generator is provable.
%
%     @Template     *term*
%     @:Generator   *callable*, must be nonvar
%     A goal to be proved as if by `call/1`.
%     @Set          *list of term*

%!    simple(+Term)
%
%     Term is currently not instantiated to a compound term.
%
%     @Term   *term*

%!    skip_byte(+Byte)
%!    skip_byte(+Stream,+Byte)
%
%     read up to and including the first occurrence of Byte on the
%     current input stream or on the input stream Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid input *binary* stream, defaults to the current input stream.
%     @Byte     *byte*

%!    skip_char(+Char)
%!    skip_char(+Stream,+Char)
%
%     Read up to and including the first occurrence of Char on the
%     current input stream or on the input stream Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid input *text* stream.
%     @Char     *char*

%!    skip_code(+Code)
%!    skip_code(+Stream,+Code)
%
%     read up to and including the first occurrence of Code on the
%     current input stream or on the input stream Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid input *text* stream, defaults to the current input stream.
%     @Code     *code*

%!    skip_line
%!    skip_line(+Stream)
%
%     Skip the remaining input characters on the current line on Stream.
%
%     @Stream   *stream\_object*, must be ground
%     A valid input *text* stream, defaults to the current input stream.

%!    sort(+List,-Sorted)
%
%     Sorts the elements of the list List into the ascending
%     standard order, and removes any multiple occurrences of an element.
%     The resulting sorted list is unified with the list Sorted.
%
%     @List     *list of term*, must be a proper list
%     @Sorted   *list of term*

%!    source_file(?AbsFile)
%!    source_file(?Pred,?AbsFile)
%
%     AbsFile is the absolute name of a loaded file, and
%     Pred is a predicate with clauses in that file.
%     AbsFile will be `user` if the special file specification `user` was loaded, and
%     Pred is a predicate with clauses from `user`.
%
%     @:Pred     *callable*
%     Selected predicate specification.
%     @AbsFile   *atom*
%     Absolute filename.

%!    spy+PredSpecs
%!    Sets plain spypoints on all the predicates represented byPredSpecs.
%
%     `spy(+PredSpecs, +Conditions)`
%     Sets conditional spypoints on all the predicates represented by PredSpecs.
%
%     @:PredSpecs    *pred\_spec\_tree*
%     A predicate specification, or a list of such.
%     @:Conditions   *term*, must be ground
%     Spypoint conditions.

%!    statistics
%!    Displays statistics relating to memory usage and
execution time.
%
%     `statistics(?Keyword, ?List)`
%     Obtains individual statistics.
%
%     @Keyword   *atom*
%     Statistics key (see [ref\-mgc\-ove\-sta](ref_002dmgc_002dove_002dsta.html)).
%     @List      *list of integer*
%     List of statistics.

%!    stream_code(-Stream,+CStream)
%
%     `stream_code(+Stream, -CStream)`
%     Converts between Prolog representation, Stream, and
%     C representation, CStream, of a stream.
%
%     @Stream    *stream\_object*
%     A valid Prolog stream.
%     @CStream   *integer*
%     Representing an `SP_stream *` pointer.

%!    stream_position(+Stream,-Position)
%
%     True when Position represents the current position of
%     Stream.
%
%     @Stream     *stream\_object*, must be ground
%     An open stream.
%     @Position   *term*
%     Stream position object representing the current position of Stream.

%!    stream_position_data(?Field,?Position,?Value)
%
%     Value is the value of the Field field of stream position
%     object Position.
%
%     @Field      *one of `[byte_count,line_count,character_count,line_position]`*
%     Note that `byte_count` is meaningful only for binary streams and
%     that the other values are meaningful only for text streams.
%     @Position   *term*
%     Stream position object representing the
%     current position of Stream.
%     @Value      *integer*

%!    stream_property(?Stream,?Property)
%
%     Stream Stream has stream property Property.
%
%     @Stream     *stream\_object*
%     @Property   *term*
%     A stream property, one of the following:
%     `file_name(F)`
%     F is the file name associated with the Stream.
%     `mode(M)`
%     Stream has been opened in mode M.
%     `id(ID)   since release 4.2`
%     Stream has the unique identity ID. The identity of a
%     stream is a positive integer that is never re\-used during the
%     life\-time of the SICStus process. This is unlike the compound term
%     Stream which is likely to be re\-used for some new stream after
%     the original stream denoted by Stream has been closed.
%     `input`
%     Stream is an input stream. Note that both `input` and
%     `output` stream properties are set for bidirectional streams.
%     `output`
%     Stream is an output stream. Note that both `input` and
%     `output` stream properties are set for bidirectional streams.
%     `alias(A)`
%     Stream has an alias A.
%     `position(P)`
%     P is a term representing the current stream position
%     of Stream.
%     Only guaranteed to be available if the stream has been opened with the
%     `open/4` option `reposition(true)`.
%     Same as `stream_position(Stream, P)` except that the latter can be
%     called on any stream, regardless of the value of the `reposition/1`
%     `open/4` option.
%     `end_of_stream(E)`
%     E describes the position of the input stream Stream,
%     with respect to the end of stream. If not all characters have been
%     read, or if peeking ahead to determine this fact would block,
%     then E is unified with `not`; otherwise, (all
%     characters read) but no end of stream indicator (\-1 or
%     `end_of_file`) was reported yet, then E is unified with
%     `at`; otherwise, E is unified with `past`.
%     `eof_action(A)`
%     A is the end\-of\-file action applicable to Stream, cf. the
%     `eof_action` option of `open/4`.
%     `type(T)`
%     Stream is of type T, one of `text`, `binary`, cf. the
%     `type` option of `open/4`.
%     `input_encoding(CS)   since release 4.3`
%     `output_encoding(CS)   since release 4.3`
%     Stream is a text stream with encoding CS in the input direction, cf. the
%     `encoding` option of `open/4`. Note that the encoding used
%     may be different from the `encoding` option passed to
%     `open/4` if a byte order mark or other information was used to
%     determine the real encoding of the file, cf. the `encoding_signature` option
%     of `open/4`.
%     `encoding(CS)`
%     Stream is a text stream open in direction input, with input encoding CS
%     or Stream is a text stream open in direction output but not in direction input,
%     with output encoding CS.
%     Note that, for bi\-directional streams, the `encoding/1` property reflects the `input_encoding/1`.
%     `eol(EOL)`
%     Stream is a text stream with end of line convention EOL, cf. the
%     `eol` option of `open/4`.
%     `encoding_signature(ES)`
%     If Stream is a text stream, then ES is determined as follows:
%     If the file contents was used to determine the character encoding, then
%     ES will be true. Typically this is the result of opening, in
%     mode `read`, a text file that contains a byte order mark or some
%     other information that lets `open/[3,4]` determine a suitable
%     encoding, cf. the `encoding_signature` option of `open/4`.
%     Otherwise, if the stream is open in direction output, then ES
%     will be as specified when the file was opened.
%     `reposition(REPOSITION)`
%     REPOSITION is true if it is possible to set the position of the
%     stream with `set_stream_position/2`, cf. the `reposition`
%     option of `open/4`.
%     `interactive   since release 4.1`
%     Stream is an interactive stream.
%     Most streams have only a subset of these properties set.
%     More properties may be added in the future.

%!    sub_atom(+Atom,-Before,-Length,-After,-SubAtom)
%
%     The characters of SubAtom form a sublist of the characters of
%     Atom, such that the number of characters preceding SubAtom
%     is Before, the number of characters after SubAtom is
%     After, and the length of SubAtom is Length.
%
%     @Atom      *atom*, must be nonvar
%     The atom from which a part is selected.
%     @Before    *integer*
%     The number of characters preceding SubAtom.
%     @Length    *integer*
%     The number of characters of SubAtom.
%     @After     *integer*
%     The number of characters following SubAtom.
%     @SubAtom   *atom*
%     The selected part of Atom.

%!    subsumes_term(+General,+Specific)
%
%     True iff there is a substitution that makes General identical to
%     Specific and that does not affect Specific. It
%     does not bind any variables.
%
%     @General    any term.
%     @Specific   any term.

%!    tell(+FileOrStream)
%
%     Makes file FileOrStream the current output stream.
%
%     @FileOrStream   *file\_spec* or *stream\_object*, must be ground

%!    telling(-FileOrStream)
%
%     Unifies FileOrStream with the current output stream or file.
%
%     @FileOrStream   *file\_spec* or *stream\_object*

%!    +Term1==+Term2
%
%     Succeeds if Term1 and Term2 are *identical terms*.
%
%     @Term1   *term*
%     @Term2   *term*

%!    :- multifile user:term_expansion/6.
%
%     `user:term_expansion(+Term1, +Layout1, +Tokens1, -Term2, -Layout2, -Tokens2)`
%     Overrides or complements the standard transformations to be done by
%     `expand_term/2`.
%
%     @Term1     *term*
%     Term to transform.
%     @Layout1   *term*
%     Layout term of Term1.
%     @Tokens1   *list of atom*
%     @Term2     *term*
%     Transformed term.
%     @Layout2   *term*
%     Layout term of Term2.
%     @Tokens2   *list of atom*

%!    +Term1@>+Term2
%
%     Succeeds if Term1 is *after* Term2 in the standard order.
%
%     @Term1   *term*
%     @Term2   *term*

%!    +Term1@<+Term2
%
%     Succeeds if Term1 is *before* Term2 in the standard order.
%
%     @Term1   *term*
%     @Term2   *term*

%!    +Term1\==+Term2
%
%     Succeeds if Term1 and Term2 are *non\-identical terms*.
%
%     @Term1   *term*
%     @Term2   *term*

%!    +Term1@=<+Term2
%
%     Succeeds if Term1 is *not after* Term2 in the standard order.
%
%     @Term1   *term*
%     @Term2   *term*

%!    +Term1@>=+Term2
%
%     Succeeds if Term1 is *not before* Term2 in the standard order.
%
%     @Term1   *term*
%     @Term2   *term*

%!    ?=(+Term1,+Term2)
%
%     Succeeds if Term1 and Term2 are *identical terms*,
%     or if they are syntactically non\-unifiable.
%
%     @Term1   *term*
%     @Term2   *term*

%!    term_variables(+Term,-Variables)since release 4.3True ifVariablesis the list of variables occurring inTerm,
without duplicates, in first occurrence order.
%
%     @Term         Any *term*, a cyclic term is also accepted.
%     @-Variables   The variables in the term. Must be a variable or a list.

%!    throw(+Exception)
%
%     Exception is thrown as an exception.
%
%     @Exception   *term*, must be nonvar

%!    told
%
%     Closes the current output stream.

%!    trace
%
%     Turns on the debugger in trace mode.

%!    trimcore
%
%     Force reclamation of memory in all of Prolog’s data areas.

%!    true
%
%     Always succeeds.

%!    +Term1=+Term2
%
%     *unifies* Term1 and Term2.
%
%     @Term1   *term*
%     @Term2   *term*

%!    unify_with_occurs_check(+Term1,+Term2)
%
%     Term1 and Term2 unify to a finite (acyclic) term.
%
%     @Term1   *term*
%     @Term2   *term*

%!    +Term=..-List
%
%     \-Term `=..` \+List
%     Unifies List with a list whose head is the atomic term corresponding
%     to the principal functor of Term and whose tail is a list of
%     the arguments of Term.
%
%     @Term   *term*
%     any term
%     @List   *list of term*
%     and not empty

%!    unknown(-OldAction,+NewAction)
%
%     Unifies OldAction with the current action on unknown procedures,
%     i.e. the current value of the `unknown` Prolog flag, sets the
%     current action to NewAction, and prints a message about the
%     change.
%
%     @OldAction   *one of `[error,fail,trace,warning]`*
%     @NewAction   *one of `[error,fail,trace,warning]`*, must be nonvar

%!    :- multifile user:unknown_predicate_handler/3.
%
%     `user:unknown_predicate_handler(+Goal, +Module, -NewGoal)`
%     User definable hook to trap calls to unknown predicates.
%
%     @Goal      *callable*
%     The goal to trap.
%     @Module    *atom*
%     Any atom that is a current module
%     @NewGoal   *callable*
%     The goal to call instead.

%!    unload_foreign_resource(:Resource)
%
%     Unload the foreign resource Resource from Prolog. Relies on the
%     hook predicates `foreign_resource/2` and `foreign/[2,3]`.
%
%     @:Resource   *file\_spec*, must be ground
%     The foreign resource to be unloaded. The file extension can be omitted.

%!    update_mutable(+Datum,+Mutable)
%
%     Updates the current value of the mutable term Mutable to
%     become Datum.
%
%     @Datum     *term*, must be nonvar
%     @Mutable   *mutable*, must be nonvar

%!    use_module(+File)
%!    Loads the module file(s)File, if not already
loaded and up-to-date. Imports all exported predicates.
%!    use_module(+File,+Imports)
%
%     Loads module file File, if not already
%     loaded and up\-to\-date. Imports according to Imports.
%     `use_module(+Module, -File, +Imports)`
%     Module is already loaded. Imports according to
%     Imports. The File argument must be a variable or a
%     legal file specification but is otherwise ignored.
%     `use_module(-Module, +File, +Imports)`
%     Module is a variable or has not been loaded. Loads module file
%     File, if not already loaded and up\-to\-date. Imports according to
%     Imports, i.e. similar to what `use_module(File, Imports)`
%     does. Finally, the Module argument is bound to the loaded
%     module.
%
%     @:File     *file\_spec* or *list of file\_spec*, must be ground
%     Any legal file specification. Only `use_module/1` accepts a list
%     of file specifications, file extensions optional.
%     @Imports   *list of simple\_pred\_spec* or the atom `all`, must be ground
%     Either a list of predicate specifications in the Name/Arity form
%     to import into the calling module, or the atom `all`, meaning all
%     predicates exported by the loaded module are to be imported.
%     @Module    *atom*
%     The module name in File, or a
%     variable, in which case the module name is returned.

%!    var(+Term)
%
%     Term is currently uninstantiated.
%
%     @Term   *term*

%!    :- volatile+PredSpecs
%
%     Declares PredSpecs to be volatile. Clauses of volatile predicates are not
%     saved by the ‘`save_*`’ predicates.
%
%     @:PredSpecs   *pred\_spec\_forest*, must be ground
%     A predicate specification, or a list of such,
%     or a sequence of such separated by commas.

%!    when(+Condition,+Goal)
%
%     Blocks Goal until the Condition is true.
%
%     @Condition   *callable*, must be nonvar and one of:
%     `nonvar(X)`
%     False until X is nonvar.
%     `ground(X)`
%     False until X is ground.
%     `?=(X,Y)`
%     False while `dif(X,Y)` would block.
%     `Condition,Condition`
%     True if both conditions are true.
%     `Condition;Condition`
%     True if at least one condition is true.
%     @:Goal       *callable*, must be nonvar

%!    write(+Stream,+Term)
%!    write(+Term)
%
%     Writes Term on Stream, without quoting atoms.
%
%     @Stream   *stream\_object*, must be ground
%     A valid open Prolog stream, defaults to the current output stream.
%     @Term     *term*

%!    write_canonical(+Stream,+Term)
%!    write_canonical(+Term)
%
%     Writes Term on Stream, quoting atoms,
%     in functional notation, without treating `'$VAR'/1` terms specially.
%
%     @Stream   *stream\_object*, must be ground
%     A valid open Prolog stream, defaults to the current output stream.
%     @Term     *term*

%!    write_term(+Stream,+Term,+Options)
%!    write_term(+Term,+Options)
%
%     Writes Term on Stream, subject to \+Options.
%
%     @Stream    *stream\_object*, must be ground
%     A valid open Prolog stream, defaults to the current output stream.
%     @Term      *term*
%     @Options   *list of term*.
%     A list of zero or more of the following,
%     where Boolean must be `true` or `false` (`false` is
%     the default).
%     `quoted(Boolean)`
%     If selected, then atoms and functors are quoted where necessary to make the
%     result acceptable as input to `read/1`. `write_canonical/1`,
%     `writeq/1`, and `portray_clause/1` select this.
%     Any output produced by `write_term/2` with the option
%     `quoted(true)` will be in Normal Form C, as defined by
%     Unicode. See [ref\-syn\-syn\-tok](ref_002dsyn_002dsyn_002dtok.html) for further details.
%     `ignore_ops(Boolean)`
%     If selected, then Term is written in standard functional notation
%     instead of using operators. `write_canonical/1` and
%     `display/1` select this.
%     `portrayed(Boolean)`
%     If selected, then `user:portray/1` is called for each non\-variable subterm.
%     `print/1` selects this.
%     `variable_names(Names)   since release 4.3`
%     Names should be a list of `Name=Var`
%     pairs, where each Name is an atom indicating the
%     name to be used if Var is a variable occurring in the written term.
%     This argument has the same form as the corresponding `read_term/[2,3]` option
%     and provides a convenient and safe way to preserve variable names
%     when writing a previously read term.
%     `numbervars(Boolean)`
%     If selected, then terms of the form `'$VAR'(N)` where
%     N is an integer \>\= 0
%     are
%     treated specially (see `numbervars/3`). `print/1`,
%     `write/1`, `writeq/1`, and `portray_clause/1` select
%     this.
%     `legacy_numbervars(Boolean)   since release 4.3`
%     If selected, then terms of the form `'$VAR'(N)` where
%     N is an integer \>\= 0, an atom, or a code list,
%     are treated specially,
%     in a way consistent with versions prior to release 4\.3,
%     as follows.
%     If N is an integer \>\= 0, then the behavior is as for the `numbervars/1` option.
%     Otherwise the characters of the atom or code list are written instead of the term.
%     The preferred way to specify variable names is with the `variable_names/1` option.
%     `cycles(Boolean)`
%     If selected, then the potentially cyclic term is printed in finite
%     `@/2` notation, as discussed for `read_term/[2,3]` (see [mpg\-ref\-read\_term](mpg_002dref_002dread_005fterm.html)).
%     `indented(Boolean)`
%     If selected, then the term is printed with the same indentation as is
%     used by `portray_clause/1` and `listing/[0,1]`.
%     `max_depth(Depth)`
%     Depth limit on printing. Depth is an integer. 0 (the default) means
%     no limit.
%     `quoted_charset(Charset)`
%     Only relevant if `quoted(true)` holds.
%     Charset should be a legal value of the `quoted_charset` Prolog
%     flag, where it takes its default value from. `write_canonical/1`
%     selects the value `portable`. See [ref\-lps\-flg](ref_002dlps_002dflg.html).
%     `float_format(Spec)`
%     How to print floats. Spec should be an atom of the form
%     ‘`~NC`’, like one of the `format/[2,3]` character
%     sequences for printing floats. The default is ‘`~H`’.
%     `priority(Prio)`
%     The term is printed as if in the context of an associative
%     operator of precedence Prio, where Prio is an
%     integer. The default is 1201, meaning that no parentheses will be printed around the term.
%     See [ref\-syn\-ops](ref_002dsyn_002dops.html).

%!    writeq(+Stream,+Term)
%!    writeq(+Term)
%
%     Writes Term on Stream, quoting atoms.
%
%     @Stream   *stream\_object*, must be ground
%     A valid open Prolog stream, defaults to the current output stream.
%     @Term     *term*

%!    zip
%
%     Turns on the debugger in zip mode.

