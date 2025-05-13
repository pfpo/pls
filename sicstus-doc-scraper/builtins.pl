%!    abolish(+Predicates)
%!    abolish(+Predicates,+Options)
%
%     Removes procedures from the Prolog database.

%!    abort
%
%     Abandons the current execution and returns to the beginning of the
%     current break level or terminates the enclosing query, whichever is closest.

%!    absolute_file_name(+RelFileSpec,-AbsFileName)
%!    absolute_file_name(+RelFileSpec,-AbsFileName,+Options)
%
%     Unifies AbsFileName with the absolute filename
%     that corresponds to the relative file specification RelFileSpec.

%!    acyclic_term(+Term)since release 4.3
%
%     Term is currently instantiated to a finite (acyclic) term.

%!    add_breakpoint(+Conditions,-BID)
%
%     Creates a breakpoint with Conditions and with identifier
%     BID.

%!    +P,+Q
%

%!    append(?List1,?List2,?List3)
%

%!    arg(+ArgNum,+Term,-Arg)
%
%     unifies Arg with the ArgNumth argument of term
%     Term.

%!    ask_query(+QueryClass,+Query,+Help,-Answer)
%
%     Prints the question Query, then reads and processes user input
%     according to QueryClass, and returns the result of the processing,
%     the abstract answer term Answer.  The Help message may
%     be printed in case of invalid input.

%!    These predicates add a dynamic clause,Clause, to the Prolog database.  They optionally return a database
reference inRef:
%!    assert(+Clause)
%
%     assert(+Clause, -Ref)
%     It is undefined whether Clause will precede or follow the
%     clauses already in the database.

%!    These predicates add a dynamic clause,Clause, to the Prolog database.  They optionally return a database
reference inRef:
%!    asserta(+Clause)
%
%     asserta(+Clause, -Ref)
%     Clause will precede all existing clauses in the database.

%!    These predicates add a dynamic clause,Clause, to the Prolog database.  They optionally return a database
reference inRef:
%!    assertz(+Clause)
%
%     assertz(+Clause, -Ref)
%     Clause will follow all existing clauses in the database.

%!    at_end_of_line
%!    at_end_of_line(+Stream)
%
%     Test whether end of line has been reached for
%     the current input stream or for the input stream Stream.

%!    at_end_of_stream
%!    at_end_of_stream(+Stream)
%
%     Tests whether the end has been reached for
%     the current input stream or for the input stream Stream.

%!    atom(+Term)
%
%     Succeeds if Term is currently instantiated to an atom.

%!    atom_chars(+Atom,-Chars)
%
%     atom_chars(-Atom, +Chars)
%     Chars is the chars comprising the printed
%     representation of Atom.

%!    atom_codes(+Atom,-Codes)
%
%     atom_codes(-Atom, +Codes)
%     Codes is the codes comprising the printed
%     representation of Atom.

%!    atom_concat(+Atom1,+Atom2,-Atom12)
%
%     atom_concat(-Atom1,-Atom2,+Atom12)
%     The characters of the atom Atom1 concatenated with those of
%     Atom2 are the same as the characters of atom Atom12.

%!    atom_length(+Atom,-Length)
%
%     Length is the number of characters of the atom Atom.

%!    atomic(+Term)
%
%     Succeeds if Term is currently
%     instantiated to an atom or a number.

%!    bagof(+Template,+Generator,-Set)
%
%     Like setof/3 except that the list (or alternative lists)
%     returned will not be ordered, and may contain duplicates.  This
%     relaxation saves time and space in execution.

%!    bb_delete(:Key,-Term)
%
%     If a term is currently stored under Key, then the term is deleted,
%     and a copy of it is unified with Term.  Otherwise,
%     bb_delete/2 silently fails.

%!    bb_get(:Key,-Term)
%
%     If a term is currently stored under Key, then a copy of it is unified
%     with Term.  Otherwise, bb_get/2 silently fails.

%!    bb_put(:Key,+Term)
%
%     A copy of Term is stored under Key in the source module
%     blackboard.  Any previous term stored under the same Key is
%     simply deleted.

%!    bb_update(:Key,-OldTerm,+NewTerm)
%
%     If a term is currently stored under Key and unifies with
%     OldTerm, then the term is replaced by a copy of NewTerm.
%     Otherwise, bb_update/3 silently fails.  This predicate provides
%     an atomic swap operation.

%!    :- block+BlockSpec
%
%     Specifies conditions
%     for blocking goals of the predicates referred to by BlockSpec.

%!    break
%
%     causes the current execution to be
%     interrupted; enters next break level.

%!    :- multifile user:breakpoint_expansion/2.
%
%     user:breakpoint_expansion(+Macro, -Body)
%     Defines debugger condition macros.

%!    byte_count(+Stream,-Count)
%
%     Obtains the total number of bytes either input from or output to
%     the open binary stream Stream and unifies it with Count.

%!    call(+P)
%
%     Proves (executes) P.
%     call(+P,?Q,...)
%     Executes the goal obtained by
%     augmenting P by the remaining arguments.

%!    Executes the procedure callGoal.  WhenGoalsucceeds
determinately, is cut, fails, or raises an exception,Cleanupis executed.
%

%!    Executes the procedure callGoal, unifyingVarswith
the list of residual variables that have blocked goals or attributes
attached to them.
%

%!    callable(+Term)
%
%     Succeeds if Term is currently
%     instantiated to an atom or a compound term.

%!    catch(+ProtectedGoal,-Exception,+Handler)
%
%     Specify an exception handler for ProtectedGoal, and call
%     ProtectedGoal, as described in ref-ere.

%!    char_code(+Char,-Code)
%
%     char_code(-Char, +Code)
%     Code is the character code comprising the printed
%     representation of Char.

%!    char_conversion(+InChar,+OutChar)
%
%     The mapping of InChar to OutChar is added to the
%     character-conversion mapping.

%!    character_count(+Stream,-Count)
%
%     Obtains the total number of characters either input from or output to
%     the open text stream Stream and unifies it with Count.

%!    clause(+Head,-Body)
%!    clause(+Head,-Body,-Ref)
%
%     clause(-Head, -Body, +Ref)
%     Searches the database for a clause whose head matches Head
%     and whose body matches Body.

%!    close(+Stream)
%!    close(+Stream,+Options)
%
%     closes the stream corresponding to Stream.

%!    compare(-Order,+Term1,+Term2)
%
%     succeeds if the result of comparing terms Term1 and
%     Term2 is Order

%!    compile(+Files)
%
%     Compiles the specified Prolog source file(s) into memory.

%!    compound(+Term)
%
%     Term is currently instantiated to a compound term.

%!    consult(+Files)
%
%     Consults the specified Prolog source file(s) into memory.

%!    copy_term(+Term,-Copy)
%!    UnifiesCopywith a copy ofTermin which all variables have been replaced by brand new variables,
and all mutables by brand new mutables.
%
%     copy_term(+Term, -Copy, -Body)
%     Furthermore, if Term contains variables with goals blocked on
%     them, or variables with attributes that can be interpreted as a goal
%     (see lib-atts), then Body is unified with the conjunction of
%     such goals.  If no such goals are present, then Body is unified with
%     the atom true.  The idea is that executing Body
%     will reinstate blocked goals and attributes on the variables in Copy
%     equivalent to those on the variables in Term.

%!    coverage_data(-Data)since release 4.2
%
%     Data is the coverage data accumulated so far.

%!    create_mutable(+Datum,-Mutable)
%
%     Mutable is a new mutable term with initial value Datum.

%!    current_atom(?Atom)
%
%     Atom is a currently existing atom.

%!    current_breakpoint(-Conditions,-BID,-Status,-Kind,-Type)
%
%     There is a breakpoint with conditions Conditions, identifier
%     BID, enabledness Status, kind Kind, and type Type.

%!    current_char_conversion(?InChar,?OutChar)
%
%     InChar is currently mapped to OutChar in the
%     character-conversion mapping, where the two are distinct.

%!    current_input(-Stream)
%
%     unifies Stream with the current input stream.

%!    current_key(?KeyName,?KeyTerm)
%
%     Succeeds when KeyName is the name of KeyTerm, and
%     KeyTerm is a recorded key.

%!    current_module(?ModuleName)
%!    Queries whether a module is “current” or backtracks through all
of the current modules.
%
%     current_module(?ModuleName, ?AbsFile)
%     Associates modules with their module files.

%!    current_op(?Precedence,?Type,?Name)
%
%     Succeeds when the atom Name is
%     currently an operator of type Type and precedence
%     Precedence.

%!    current_output(-Stream)
%
%     unifies Stream with the current output stream.

%!    current_predicate(?PredSpec)
%!    UnifiesPredSpecwith
a predicate specifications of the formName/Arity.
%
%     current_predicate(?Name, ?Term)
%     Unifies Name with the name of a user-defined predicate, and Term
%     with the most general term corresponding to that predicate.

%!    current_prolog_flag(?FlagName,?Value)
%
%     same as prolog_flag(FlagName, Value), except that
%     current_prolog_flag(FlagName, Value) type checks FlagName.

%!    current_stream(?AbsFile,?Mode,?Stream)
%
%     Stream is a stream, which is currently open on
%     file AbsFile in mode Mode.

%!    !
%
%     Cut.

%!    db_reference(+Term)since release 4.1
%
%     Term is currently instantiated to
%     a compound term with principal functor '$ref'/2
%     denoting a unique reference to a dynamic clause.

%!    debug
%
%     Turns on the debugger in debug mode.

%!    :- multifile user:debugger_command_hook/2.
%
%     user:debugger_command_hook(+DCommand, -Actions)
%     Allows the interactive debugger to be extended with user-defined
%     commands. See Debug Commands.

%!    debugging
%
%     Prints out current debugging state

%!    dif(+X,+Y)
%
%     Constrains X and Y to represent different terms i.e.
%     to be non-unifiable.

%!    disable_breakpoints(+BIDs)
%
%     Disables the breakpoints specified by BIDs.

%!    :- discontiguous+PredSpecs
%
%     Declares the clauses of the predicates defined by PredSpecs to be
%     discontiguous in the source file (suppresses compile-time warnings).

%!    display(+Term)
%
%     Writes Term on the standard output stream, without quoting atoms,
%     in functional notation, without treating '$VAR'/1 terms specially.
%     Since quoting is never used, even when needed for reading the term
%     back in, the standard predicate write_canonical/1 is often preferable.

%!    (+Iteratordo+Body)
%

%!    :- dynamic+PredSpecs
%
%     Declares the clauses of the predicates defined by PredSpecs to be
%     dynamic.

%!    enable_breakpoints(+BIDs)
%
%     Enables the breakpoints specified by BIDs.

%!    ensure_loaded(+Files)
%
%     Loads the specified Prolog source and/or object file(s) into memory,
%     if not already loaded and up to date.

%!    +Expr1=:=+Expr2
%
%     Succeeds if the results of evaluating Expr1 and
%     Expr2 are equal.

%!    erase(+Ref)
%
%     Erases from the database the dynamic clause or recorded term referenced
%     by Ref.

%!    :- multifile user:error_exception/1.
%
%     user:error_exception(+Exception)
%     Tells the debugger to enter trace mode on exceptions
%     matching Exception.

%!    execution_state(+Tests)
%!    Testsare satisfied in the current state of the execution.
%
%     execution_state(+FocusConditions, +Tests)
%     Tests are satisfied in the state of the execution pointed to by
%     FocusConditions.

%!    +X^+P
%
%     Equivalent to “there exists an X such that P is
%     true”, thus X is normally an unbound variable. The use of the
%     explicit existential quantifier outside setof/3 and bagof/3
%     is superfluous.

%!    expand_term(+Term1,-Term2)
%
%     Transforms source file terms into Prolog clauses before they are compiled.
%     Normally called by the compiler, but can be called directly. The transform
%     can be customized by defining user:term_expansion/6.
%     When a source file is loaded, except by :- include,
%     expand_term/2 is called with the virtual clauses
%     beginning_of_file before and end_of_file after the real
%     Prolog clauses, to give user:term_expansion/6 an opportunity to
%     perform some action at the beginning and end of a source
%     file. Please note: the virtual clause
%     beginning_of_file is “seen” before any module
%     declaration, i.e. before the source module has been updated.

%!    fail
%
%     Always fails.

%!    false
%
%     Always fails (same as fail/0).

%!    :- multifile user:file_search_path/2.
%
%     user:file_search_path(+PathAlias, +DirSpec)
%     Defines a symbolic name for a directory or a path.  Used by
%     predicates taking file_spec as input argument.

%!    findall(+Template,+Generator,-List)
%!    findall(+Template,+Generator,-List,+Remainder)
%
%     List is the list of all the instances of Template for
%     which the goal Generator succeeds, appended to Remainder.
%     Remainder defaults to the empty list.

%!    float(+Term)
%
%     Term is currently instantiated to a float.

%!    flush_output
%!    flush_output(+Stream)
%
%     Forces the buffered output of the stream Stream (defaults to the
%     current output stream) to be sent to the associated device.

%!    :- discontiguous foreign/2, foreign/3.
%!    foreign(+Routine,+ForeignSpec)
%
%     foreign(+Routine, +Language, +ForeignSpec)
%     Describes the interface between Prolog and the foreign Routine.
%     Used by load_foreign_resource/1.

%!    :- discontiguous foreign_resource/2.
%
%     foreign_resource(+ResourceName, +ForeignFunctions)
%     Describes the foreign functions in ResourceName to interface to.

%!    format(+Control,+Arguments)
%!    format(+Stream,+Control,+Arguments)
%
%     Interprets the Arguments according to the Control string and
%     prints the result on Stream.

%!    freeze(+Flag,+Goal)
%
%     Blocks Goal until Flag is bound.

%!    frozen(+Term,-Goal)
%
%     Goal is unified with the conjunction of all goals blocked on some variable
%     that occurs in Term.

%!    functor(+Term, -Name, -Arity)
%
%     functor(-Term, +Name, +Arity)
%     Succeeds if the principal functor of term Term has name
%     Name and arity Arity.

%!    garbage_collect
%
%     Invokes the garbage collector.

%!    garbage_collect_atoms
%
%     Invokes the atom garbage collector.

%!    :- multifile 'SU_messages':generate_message/3.
%
%     'SU_messages':generate_message(+MessageTerm, -S0, -S)
%     For a given MessageTerm, generates a list composed of
%     Control-Arg pairs and the atom nl.  This can be translated into a
%     nested list of Control-Arg pairs, which can be used as input to
%     print_message_lines/3.

%!    :- multifile user:generate_message_hook/3.
%
%     user:generate_message_hook(+MessageTerm, -S0, -S)
%     A way for the user to override the call to 'SU_messages':generate_message/3
%     in print_message/2.

%!    get_byte(-Byte)
%!    get_byte(+Stream,-Byte)
%
%     Unifies Byte with the next byte from
%     Stream or with -1 if there are no more bytes.

%!    get_char(-Char)
%!    get_char(+Stream,-Char)
%
%     Unifies Char with the next char from Stream or
%     with end_of_file if there are no more characters.

%!    get_code(-Code)
%!    get_code(+Stream,-Code)
%
%     Unifies Code with the next code from
%     Stream or with -1 if there are no more characters.

%!    get_mutable(-Datum,+Mutable)
%
%     Datum is the current value of the mutable term
%     Mutable.

%!    M:goal_expansion(+Goal1,+Layout1,+Module,-Goal2,-Layout2)
%
%     Defines transformations on goals while clauses are being compiled or asserted,
%     and during meta-calls at runtime.

%!    goal_source_info(+AGoal,-Goal,-SourceInfo)
%
%     Decompose the AGoal annotated goal into a Goal proper
%     and the SourceInfo descriptor term, indicating the source
%     position of the goal.

%!    +Expr1>+Expr2
%
%     Succeeds if the result of evaluating Expr1 is strictly
%     greater than the result of evaluating Expr2.

%!    ground(+Term)
%
%     Term is currently instantiated to a ground term.

%!    halt
%!    halt(+ExitCode)
%
%     Causes an exit from the running process.

%!    if(+P,+Q,+R)
%
%     If P then Q else R, for all solution of
%     P.

%!    +P->+Q
%
%     When occurring other than as the first argument of a disjunction operator
%     (;/2), this is equivalent to:

%!    :- include+Files
%
%     Literally embed the Prolog clauses and
%     directives in Files into the file being loaded.
%     The file or files will be opened with default options.

%!    :- initialization+Goal
%
%     Declares that Goal is to be run when the file in which the
%     declaration appears is loaded into a running system, or when a
%     stand-alone program or runtime system that contains the file is started
%     up.

%!    instance(+Ref,-Term)
%
%     Unifies Term with the
%     most general instance of the dynamic clause or recorded term indicated by
%     the database reference Ref.

%!    integer(+Term)
%
%     Term is currently instantiated to an integer.

%!    -Termis+Expression
%
%     Evaluates Expression as an arithmetic expression, and unifies
%     the resulting number with Term.

%!    keysort(+Pairs,-Sorted)
%
%     Sorts the elements of the list Pairs into ascending
%     standard order (see ref-lte-cte-sot) with respect to the key of
%     the pair structure.

%!    leash(+Mode)
%
%     Starts leashing on the ports given by Mode.

%!    length(?List,?Integer)
%
%     Integer is the length of List. If List is
%     instantiated to a proper list of term, or Integer to an integer, then
%     the predicate is determinate.

%!    +Expr1<+Expr2
%
%     Evaluates Expr1 and Expr2 as arithmetic expressions.
%     The goal succeeds if the result of evaluating Expr1 is strictly
%     less than the result of evaluating Expr2.

%!    :- multifile user:library_directory/1.
%
%     user:library_directory(+DirSpec)
%     Defines a library directory. Used by predicates taking
%     file_spec as input argument.

%!    line_count(+Stream,-Count)
%
%     Obtains the total number of lines either input from or output to
%     the open text stream Stream and unifies it with Count.

%!    line_position(+Stream,-Count)
%
%     Obtains the total number of characters either input from or output to
%     the current line of
%     the open text stream Stream and unifies it with Count.

%!    listing
%!    listing(+PredSpecs)
%
%     Prints the clauses of all the interpreted procedures currently in the
%     type-in module of the Prolog database, or of PredSpecs, to the
%     current output stream, using portray_clause/1.

%!    load_files(+Files)
%!    load_files(+Files,+Options)
%
%     [+Files]
%     Loads the specified Prolog source and/or object file(s) into memory.
%     Subsumes all other load predicates.

%!    load_foreign_resource(:Resource)
%
%     Load the foreign resource Resource into Prolog.  Relies on the
%     hook predicates foreign_resource/2 and foreign/[2,3].

%!    member(?Element,?List)
%
%     is true if Element occurs in the List.  It may be used
%     to test for an element or to enumerate all the elements by backtracking.
%     Indeed, it may be used to generate the List!

%!    memberchk(?Element,?List)
%
%     is true if the given Element occurs in the given
%     List.  Its purpose is to test for membership. Normally, the two
%     arguments are ground.

%!    :- multifile user:message_hook/3.
%
%     user:message_hook(+Severity, +MessageTerm, +Lines)
%     Overrides the call to print_message_lines/3 in print_message/2.
%     A way for the user to intercept the Message of type
%     Severity, whose translations is Lines, before it is
%     actually printed.

%!    :- meta_predicate+MetaSpec
%
%     Provides for module name expansion of arguments in calls to the
%     predicate given by MetaSpec. All meta_predicate/1 declarations
%     should be at the beginning of a module.

%!    :- mode+Mode
%
%     Currently a dummy declaration.

%!    :- module(+ModuleName,+PublicPred).
%!    :- module(+ModuleName,+PublicPred,+Options).
%
%     Declares the file in which the declaration appears to be a
%     module file named ModuleName, with public predicates
%     PublicPred. Must appear as the first term in the file.

%!    :- multifile+PredSpecs
%
%     Declares the clauses of the predicates defined by PredSpecs to be
%     multifile in the source file (suppresses compile-time warnings).

%!    mutable(+Term)
%
%     Succeeds if Term is currently instantiated to a mutable term.

%!    name(+Constant,-Codes)
%
%     name(-Constant, +Codes)
%     Codes is the list consisting of the codes comprising
%     the printed representation of Constant.

%!    nl
%!    nl(+Stream)
%
%     Terminates the current output record on the current output stream
%     or on Stream.

%!    nodebug
%
%     Turns the debugger off.

%!    nonmember(?Element,?List)
%
%     is true if the given Element does not occur in the given
%     List.  Its purpose is to test for membership. Normally, the two
%     arguments are ground.

%!    nonvar(+Term)
%
%     Term is currently instantiated.

%!    nospy+PredSpecs
%
%     Any spypoints (plain and conditional) on the predicates
%     represented by PredSpecs are removed.

%!    nospyall
%
%     Removes all the spypoints (including the generic ones) that have
%     been set.

%!    +Expr1=\=+Expr2
%
%     Succeeds if the results of evaluating Expr1 and
%     Expr2 are not equal.

%!    +Expr1=<+Expr2
%
%     Succeeds if the result of evaluating Expr1 is less
%     than or equal to the result of evaluating Expr2.

%!    +Expr1>=+Expr2
%
%     Succeeds if the results of evaluating Expr1 and
%     Expr2 are equal.

%!    \++P
%
%     Fails if the goal P has a solution, and succeeds otherwise.
%     Equivalent to:
%     except that the use of call/1 often can be avoided.

%!    +Term1\=+Term2
%
%     Term1 and Term2 do not unify.

%!    notrace
%
%     Turns the debugger off.

%!    nozip
%
%     Turns the debugger off.

%!    number(+Term)
%
%     Term is currently instantiated to a number.

%!    number_chars(+Number,-Chars)
%
%     number_chars(-Number, +Chars)
%     Chars is the chars comprising the printed
%     representation of Number.

%!    number_codes(+Number,-Codes)
%
%     number_codes(-Number, +Codes)
%     Codes is the codes comprising the printed
%     representation of Number.

%!    numbervars(+Term,+FirstVar,-LastVar)
%
%     instantiates  each of the variables in Term to a term of the form
%     '$VAR'(N).

%!    on_exception(-Exception,+ProtectedGoal,+Handler)
%
%     same as:
%     catch(ProtectedGoal, Exception, Handler)
%     Specify an exception handler for ProtectedGoal, and call
%     ProtectedGoal, as described in ref-ere.

%!    once(+P)
%
%     Equivalent to:
%     except that the use of call/1 often can be avoided.

%!    op(+Precedence,+Type,+Name)
%
%     declares Name to be an operator of the stated
%     Type and Precedence.

%!    open(+FileSpec,+Mode,-Stream)
%!    open(+FileSpec,+Mode,-Stream,+Options)
%
%     Creates a Prolog stream by opening the file FileSpec
%     in mode Mode with options Options.

%!    open_null_stream(-Stream)
%
%     opens an output text stream that is not connected to any file and
%     unifies its stream object with Stream.

%!    +Q;+R
%
%     Disjunction: Succeeds if Q succeeds or R succeeds.
%     +P -> +Q ; +R
%     If P then Q else R, using first solution of
%     P only.

%!    otherwise
%
%     Always succeeds (same as true/0).

%!    peek_byte(-Byte)
%!    peek_byte(+Stream,-Byte)
%
%     looks ahead for next input byte on the input stream Stream.

%!    peek_char(-Char)
%!    peek_char(+Stream,-Char)
%
%     looks ahead for next input character on the current input stream
%     or on the input stream Stream.

%!    peek_code(-Code)
%!    peek_code(+Stream,-Code)
%
%     looks ahead for next input character on the input stream Stream.

%!    phrase(+PhraseType,+List)
%!    phrase(+PhraseType,+List,-Rest)
%
%     Used in conjunction with a grammar to parse or generate strings.

%!    :- multifile user:portray/1.
%
%     user:portray(+Term)
%     A way for the user to over-ride the default behavior of print/1.

%!    portray_clause(+Clause)
%!    portray_clause(+Stream,+Clause)
%
%     Writes Clause to the current output stream. Used by
%     listing/[0,1].

%!    :- multifile user:portray_message/2.
%
%     user:portray_message(+Severity, +MessageTerm)
%     Called by print_message/2 before processing the message.  If this
%     succeeds, then it is assumed that the message has been processed and nothing
%     further is done.

%!    predicate_property(?Callable,?PredProperty)
%
%     Unifies PredProperty with a predicate property of an existing
%     predicate, and Callable with the most general term that corresponds
%     to that predicate.

%!    print(+Stream,+Term)
%!    print(+Term)
%
%     Writes Term on Stream, without quoting atoms,
%     calling user:portray/1 on subterms.

%!    print_coveragesince release 4.2
%!    Prints the coverage data accumulated so far, to the current output
stream, in a hierarchical format.
%
%     print_coverage(+Data)   since release 4.2
%     Prints the coverage data Data, to the current output stream, in
%     a hierarchical format.  Data should be of type list of
%     coverage_pair; see coverage_data/1.

%!    print_message(+Severity,+MessageTerm)
%
%     Print a Message of a given Severity. The behavior can be
%     customized using the hooks user:portray_message/2,
%     user:generate_message_hook/3 and user:message_hook/3.

%!    print_message_lines(+Stream,+Severity,+Lines)
%
%     Print the Lines to Stream, preceding each line with a
%     prefix corresponding to Severity.

%!    print_profilesince release 4.2
%!    Prints the profiling data accumulated so far, to the current output
stream, in a format similar togprof(1).
%
%     print_profile(+Data)   since release 4.2
%     Prints the profiling data Data, to the current output stream, in
%     a format similar to gprof(1).  Data should be of type
%     list of profile_pair; see profile_data/1.

%!    profile_data(-Data)since release 4.2
%
%     Data is the profiling data accumulated so far.

%!    profile_resetsince release 4.2
%
%     Resets all profiling data.

%!    prolog_flag(?FlagName,?Value)
%!    FlagNameis a flag, which currently is set toValue.
%
%     prolog_flag(+FlagName, -OldValue, +NewValue)
%     Unifies the current value of FlagName with OldValue
%     and then sets the value of the flag to NewValue.
%     The available Prolog flags are listed in ref-lps-flg.

%!    prolog_load_context(?Key,?Value)
%
%     Finds out the context of the current load.
%     The available context keys are described in ref-lps-lco.

%!    prompt(-OldPrompt,+NewPrompt)
%
%     Queries or changes the prompt string of the current input stream or an
%     input stream Stream.

%!    :- public+Term
%
%     Currently a dummy declaration.

%!    put_byte(+Byte)
%!    put_byte(+Stream,+Byte)
%
%     Writes the byte Byte to Stream.

%!    put_char(+Char)
%!    put_char(+Stream,+Char)
%
%     The char Char is written to Stream.

%!    put_code(+Code)
%!    put_code(+Stream,+Code)
%
%     The code Code is written to the stream Stream.

%!    :- multifile 'SU_messages':query_abbreviation/3.
%
%     'SU_messages':query_abbreviation(+QueryClass, -Prompt, -Pairs)
%     A way to specify one letter abbreviations for responses to queries
%     from the Prolog System.

%!    :- multifile 'SU_messages':query_class/5.
%
%     'SU_messages':query_class(+QueryClass, -Prompt, -InputMethod, -MapMethod, -FailureMode)
%     Access the parameters of a given QueryClass.

%!    :- multifile user:query_class_hook/5.
%
%     user:query_class_hook(+QueryClass, -Prompt, -InputMethod, -MapMethod, -FailureMode)
%     Provides the user with a method of overriding the call to
%     'SU_messages':query_class/5 in the preparation phase of query
%     processing.  This way the default query class characteristics can be
%     changed.

%!    :- multifile 'SU_messages':query_hook/6.
%
%     'SU_messages':query_hook(+QueryClass, +Prompt, +PromptLines, +Help, +HelpLines, -Answer)
%     Provides a method of overriding Prolog’s default keyboard based
%     input requests.

%!    :- multifile 'SU_messages':query_input/3.
%
%     'SU_messages':query_input(+InputMethod, +Prompt, -RawInput)
%     Implements the input phase of query processing.  The user is prompted
%     with Prompt, input is read according to InputMethod, and the
%     result is returned in RawInput.

%!    :- multifile user:query_input_hook/3.
%
%     user:query_input_hook(+InputMethod, +Prompt, -RawInput)
%     Provides the user with a method of overriding the call to
%     'SU_messages':query_input/3 in the input phase of query
%     processing.  This way the implementation of the default input methods
%     can be changed.

%!    :- multifile 'SU_messages':query_map/4.
%
%     'SU_messages':query_map(+MapMethod, +RawInput, -Result, -Answer)
%     Implements the mapping phase of query processing.  The RawInput,
%     received from query_input/3, is mapped to the abstract answer
%     term Answer.

%!    :- multifile user:query_map_hook/4.
%
%     user:query_map_hook(+MapMethod, +RawInput, -Result, -Answer)
%     Provides the user with a method of overriding the call to
%     'SU_messages':query_map/4 in the map phase of query
%     processing.  This way the implementation of the default map methods
%     can be changed.

%!    raise_exception(+Exception)
%

%!    read(-Term)
%!    read(+Stream,-Term)
%
%     Reads the next term from Stream and unifies it with Term.
%     Same as:
%     read_term(Term, [])
%     read_term(Stream, Term, [])

%!    read_line(-Line)
%!    read_line(+Stream,-Line)
%
%     Reads one line of input from Stream, and unifies the
%     codes with Line. On end of file, Line is unified with
%     end_of_file.

%!    read_term(-Term,+Options)
%!    read_term(+Stream,-Term,+Options)
%
%     Read a term from Stream,
%     optionally returning extra information about the term.

%!    reconsult(+Files)
%
%     same as:
%     consult(Files)

%!    recorda(+Key,+Term,-Ref)
%
%     records the Term in the internal database as the first item
%     for the principal functor of Key; a database reference to the newly-recorded
%     term is returned in Ref.

%!    recorded(-Key,-Term,+Ref)
%
%     recorded(?Key, ?Term, ?Ref)
%     Searches the internal database for a term recorded under the principal
%     functor of Key that unifies with Term, and whose database
%     reference unifies with Ref.

%!    recordz(+Key,+Term,-Ref)
%
%     records the Term in the internal database as the last item
%     for the principal functor of Key; a database reference to the newly-recorded
%     term is returned in Ref.

%!    remove_breakpoints(+BIDs)
%
%     Removes the breakpoints specified by BIDs.

%!    repeat
%
%     Succeeds immediately when called and whenever reentered by
%     backtracking.

%!    restore(+FileSpec)
%
%     Restores a saved state.

%!    retract(+Clause)
%
%     Removes the first occurrence of dynamic clause Clause from
%     module M.

%!    retractall(+Head)
%
%     Removes every clause in module M whose head matches Head.

%!    user:runtime_entry(Event)
%
%     This predicate is called upon start-up of stand alone
%     applications. Currently, Event will be start, and the
%     hook is only called when the stand alone application starts (after any
%     saved state etc. has been loaded). In the future, other events may
%     be defined, e.g. when the application exits, so unknown values of
%     Event should be ignored. See Mixing C and Prolog for details.
%     A typical definition just calls the user-defined code that should be
%     run on startup:

%!    save_files(+SourceFiles,+File)
%
%     Any code loaded from SourceFiles,
%     as well as from any file included by them,
%     is saved into File in PO format.

%!    save_modules(+Modules,+File)
%
%     Saves all predicates in Modules in PO format to File.

%!    save_predicates(+PredSpecs,+File)
%
%     Saves all predicates in PredSpecs in PO format to File.

%!    save_program(+File)
%!    save_program(+File,+Goal)
%
%     Saves the state of the current execution in object format to
%     File. A goal, Goal, to be called upon
%     execution/restoring of the saved state, may be specified.

%!    see(+FileOrStream)Makes fileFileOrStreamthe current input stream.
%

%!    seeing(-FileOrStream)
%
%     Unifies FileOrStream with the current input stream or file.

%!    seek(+Stream,+Offset,+Method,-NewLocation)
%
%     Seeks to an arbitrary position in Stream.

%!    seen
%
%     Closes the current input stream.

%!    set_input(+Stream)
%
%     makes Stream the current input stream.

%!    set_module(+ModuleName)
%
%     Changes the type-in module (see ref-mod-tyi) to
%     ModuleName.  Thus subsequent top-level goals use ModuleName as
%     their source module.

%!    set_output(+Stream)
%
%     makes Stream the current output stream.

%!    set_prolog_flag(+FlagName,+Value)
%
%     same as:
%     prolog_flag(FlagName, _, Value)

%!    set_stream_position(+Stream,+Position)
%
%     Sets the current position of Stream to Position.

%!    setof(+Template,+Generator,-Set)
%
%     Returns the non-empty set Set of all instances of Template such
%     that Generator is provable.

%!    simple(+Term)
%
%     Term is currently not instantiated to a compound term.

%!    skip_byte(+Byte)
%!    skip_byte(+Stream,+Byte)
%
%     read up to and including the first occurrence of Byte on the
%     current input stream or on the input stream Stream.

%!    skip_char(+Char)
%!    skip_char(+Stream,+Char)
%
%     Read up to and including the first occurrence of Char on the
%     current input stream or on the input stream Stream.

%!    skip_code(+Code)
%!    skip_code(+Stream,+Code)
%
%     read up to and including the first occurrence of Code on the
%     current input stream or on the input stream Stream.

%!    skip_line
%!    skip_line(+Stream)
%
%     Skip the remaining input characters on the current line on Stream.

%!    sort(+List,-Sorted)
%
%     Sorts the elements of the list List into the ascending
%     standard order, and removes any multiple occurrences of an element.
%     The resulting sorted list is unified with the list Sorted.

%!    source_file(?AbsFile)
%!    source_file(?Pred,?AbsFile)
%
%     AbsFile is the absolute name of a loaded file, and
%     Pred is a predicate with clauses in that file.
%     AbsFile will be user if the special file specification user was loaded, and
%     Pred is a predicate with clauses from user.

%!    spy+PredSpecs
%!    Sets plain spypoints on all the predicates represented byPredSpecs.
%
%     spy(+PredSpecs, +Conditions)
%     Sets conditional spypoints on all the predicates represented by PredSpecs.

%!    statistics
%!    Displays statistics relating to memory usage and
execution time.
%
%     statistics(?Keyword, ?List)
%     Obtains individual statistics.

%!    stream_code(-Stream,+CStream)
%
%     stream_code(+Stream, -CStream)
%     Converts between Prolog representation, Stream, and
%     C representation, CStream, of a stream.

%!    stream_position(+Stream,-Position)
%
%     True when Position represents the current position of
%     Stream.

%!    stream_position_data(?Field,?Position,?Value)
%
%     Value is the value of the Field field of stream position
%     object Position.

%!    stream_property(?Stream,?Property)
%
%     Stream Stream has stream property Property.

%!    sub_atom(+Atom,-Before,-Length,-After,-SubAtom)
%
%     The characters of SubAtom form a sublist of the characters of
%     Atom, such that the number of characters preceding SubAtom
%     is Before, the number of characters after SubAtom is
%     After, and the length of SubAtom is Length.

%!    subsumes_term(+General,+Specific)
%
%     True iff there is a substitution that makes General identical to
%     Specific and that does not affect Specific.  It
%     does not bind any variables.

%!    tell(+FileOrStream)
%
%     Makes file FileOrStream the current output stream.

%!    telling(-FileOrStream)
%
%     Unifies FileOrStream with the current output stream or file.

%!    +Term1==+Term2
%
%     Succeeds if Term1 and Term2 are identical terms.

%!    :- multifile user:term_expansion/6.
%
%     user:term_expansion(+Term1, +Layout1, +Tokens1, -Term2, -Layout2, -Tokens2)
%     Overrides or complements the standard transformations to be done by
%     expand_term/2.

%!    +Term1@>+Term2
%
%     Succeeds if Term1 is after Term2 in the standard order.

%!    +Term1@<+Term2
%
%     Succeeds if Term1 is before Term2 in the standard order.

%!    +Term1\==+Term2
%
%     Succeeds if Term1 and Term2 are non-identical terms.

%!    +Term1@=<+Term2
%
%     Succeeds if Term1 is not after Term2 in the standard order.

%!    +Term1@>=+Term2
%
%     Succeeds if Term1 is not before Term2 in the standard order.

%!    ?=(+Term1,+Term2)
%
%     Succeeds if Term1 and Term2 are identical terms,
%     or if they are syntactically non-unifiable.

%!    term_variables(+Term,-Variables)since release 4.3True ifVariablesis the list of variables occurring inTerm,
without duplicates, in first occurrence order.
%

%!    throw(+Exception)
%
%     Exception is thrown as an exception.

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
%     unifies Term1 and Term2.

%!    unify_with_occurs_check(+Term1,+Term2)
%
%     Term1 and Term2 unify to a finite (acyclic) term.

%!    +Term=..-List
%
%     -Term =.. +List
%     Unifies List with a list whose head is the atomic term corresponding
%     to the principal functor of Term and whose tail is a list of
%     the arguments of Term.

%!    unknown(-OldAction,+NewAction)
%
%     Unifies OldAction with the current action on unknown procedures,
%     i.e. the current value of the unknown Prolog flag, sets the
%     current action to NewAction, and prints a message about the
%     change.

%!    :- multifile user:unknown_predicate_handler/3.
%
%     user:unknown_predicate_handler(+Goal, +Module, -NewGoal)
%     User definable hook to trap calls to unknown predicates.

%!    unload_foreign_resource(:Resource)
%
%     Unload the foreign resource Resource from Prolog.  Relies on the
%     hook predicates foreign_resource/2 and foreign/[2,3].

%!    update_mutable(+Datum,+Mutable)
%
%     Updates the current value of the mutable term Mutable to
%     become Datum.

%!    use_module(+File)
%!    Loads the module file(s)File, if not already
loaded and up-to-date. Imports all exported predicates.
%!    use_module(+File,+Imports)
%
%     Loads module file File, if not already
%     loaded and up-to-date. Imports according to Imports.
%     use_module(+Module, -File, +Imports)
%     Module is already loaded. Imports according to
%     Imports. The File argument must be a variable or a
%     legal file specification but is otherwise ignored.
%     use_module(-Module, +File, +Imports)
%     Module is a variable or has not been loaded. Loads module file
%     File, if not already loaded and up-to-date. Imports according to
%     Imports, i.e. similar to what use_module(File, Imports)
%     does. Finally, the Module argument is bound to the loaded
%     module.

%!    var(+Term)
%
%     Term is currently uninstantiated.

%!    :- volatile+PredSpecs
%
%     Declares PredSpecs to be volatile.  Clauses of volatile predicates are not
%     saved by the ‘save_*’ predicates.

%!    when(+Condition,+Goal)
%
%     Blocks Goal until the Condition is true.

%!    write(+Stream,+Term)
%!    write(+Term)
%
%     Writes Term on Stream, without quoting atoms.

%!    write_canonical(+Stream,+Term)
%!    write_canonical(+Term)
%
%     Writes Term on Stream, quoting atoms,
%     in functional notation, without treating '$VAR'/1 terms specially.

%!    write_term(+Stream,+Term,+Options)
%!    write_term(+Term,+Options)
%
%     Writes Term on Stream, subject to +Options.

%!    writeq(+Stream,+Term)
%!    writeq(+Term)
%
%     Writes Term on Stream, quoting atoms.

%!    zip
%
%     Turns on the debugger in zip mode.

