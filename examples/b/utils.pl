:- use_module(library(process)).
:- use_module(library(file_systems)).

% This is a  comment
% ============================================
%                List Utils 
% ============================================
% list_length(+List,-Length)

list_length([],0).
list_length([_|LS],L):-
    list_length(LS,LL),
    L is LL + 1.

% list_at(+List,+Index,-Element)
list_at([X|_],0,X).
list_at([_|XS],N,X):-
    N1 is N -1,
    list_at(XS,N1,X).

% list_append(+XS,+Y,-XSY)
list_append([],X,[X]).
list_append([Y|YS],X,[Y|ZS]):- list_append(YS,X,ZS).

% list_append_many(+XS,+YS,-XSYS)
list_append_many([],YS,YS).
list_append_many([X|XS],YS,[X|ZS]):- list_append_many(XS,YS,ZS).

% list_concat(+ListOfLists,-AllListsConcatenated)
list_concat([],[]).
list_concat([L|LS],Result):-
    list_concat(LS,LSConcated),
    list_append_many(L,LSConcated,Result).


% MapFunc(+X,-Y)
% list_map(+XS,+MapFunc,-YS)
list_map([],_F,[]).
list_map([X|XS],F,[Y|YS]):-
    call(F,X,Y),
    list_map(XS,F,YS).

% Call Predicate with Args unifying the results in args
% predicate_call(+Predicate,?Args)
pred_call(Predicate,Args):-
    Goal =.. [Predicate | Args],
    call(Goal).

% Command Line Arguments
% get_argv(-Argv)
get_argv(Argv):- current_prolog_flag(argv,Argv).

% ==================================================
% Utils To Parse STDOUT to Convert to Prolog types
% ==================================================

% Returns the Prolog Codes Representation of a nested list of integers
% list_to_codes(+List,-Codes)
list_to_codes(List,Codes):-
    list_to_codes(List,[91],PartialCodes),
    list_append(PartialCodes,93,Codes).

list_to_codes([],Result,Result).
list_to_codes([X|XS],Previous,Result):-
    number(X),
    number_codes(X,Y),
    list_append_many(Previous,Y,Partial),
    list_to_codes_advance([X|XS],Partial,Result).

list_to_codes([L|XS],Previous,Result):-
    \+ number(L),
    atom_codes('[',OpenParen), list_to_codes(L,OpenParen,SubList),
    atom_codes(']',CloseParen),list_append_many(SubList,CloseParen,SubListResult),
    list_append_many(Previous,SubListResult,Partial),
    list_to_codes_advance([L|XS],Partial,Result).

list_to_codes_advance([_],Previous,Result):-
    list_to_codes([],Previous,Result).
list_to_codes_advance([_,X2|XS],Previous,Result):-
    atom_codes(',',Virgula),
    list_append_many(Previous,Virgula,PartialVirgula),
    list_to_codes([X2|XS],PartialVirgula,Result).

% Converts a Prolog Nested List of Integers to a String
% list_to_string(+List,-String)
list_to_string(List,String):-
    list_to_codes(List,Codes),
    atom_codes(String,Codes).


seeing_number([93|Next],Number,Number,[93|Next]).
seeing_number([44|Next],Number,Number,[44|Next]).
seeing_number([N|Rest],PreviousNumber,Result,Next):-
    list_append(PreviousNumber,N,CurrentNumber),
    seeing_number(Rest,CurrentNumber,Result,Next).

% Given a list of Codes filter out the spaces
% codes_filter_spaces(+CodesWithSpaces,-CodesWithoutSpaces)
codes_filter_spaces([],[]).
codes_filter_spaces([32|XS],YS):- codes_filter_spaces(XS,YS).
codes_filter_spaces([X|XS],[X|YS]):- codes_filter_spaces(XS,YS).

% Codes is a Prolog List represented as codes it converts it back into a prolog list
% codes_to_list(+Codes,-List)
codes_to_list(Codes,List):-
    codes_filter_spaces(Codes,CodesWithoutSpace),
    parse_list(CodesWithoutSpace,[],Result,_Next),
    list_at(Result,0,List).

% Given a list containing codes convert it into a number
% codes_to_number(+Codes,-Number)
codes_to_number(Codes,Number):-
    atom_codes(NumberAtom,Codes),
    atom_chars(NumberAtom,Chars),
    number_chars(Number,Chars).

% Predicate to parse the list of codes to convert it into a Prolog List
parse_list([91|Rest],Partial,Result,Next):-
    parse_list(Rest,[],SubList,SubNext),
    list_append(Partial,SubList,PartialResult),
    parse_list(SubNext,PartialResult,Result,Next).
parse_list([93|Next],Result,Result,Next).
parse_list([44|PartialNext],PartialResult,Result,Next):-
    parse_list(PartialNext,PartialResult,Result,Next).
parse_list([],Result,Result,[]).
parse_list(List,Partial,Result,Next):-
    seeing_number(List,[],NumberCodes,PartialNext),
    codes_to_number(NumberCodes,Number),
    list_append(Partial,Number,PartialResult),
    parse_list(PartialNext,PartialResult,Result,Next).


% Predicate Receives a List, converts it into Codes and converts back into a prolog list
% This predicate is used to test this functioinality
test_list(L):-
    write('Got :'),write(L),
    list_to_codes(L,Codes),
    codes_to_list(Codes,NewL),
    write('\nResult:'),write(NewL),
    log_failling(L,NewL).

% Test passes when the two lists are the same
log_failling(L,L):- write('Passed').
log_failling(_L,_NL):- write('FAILED').
test_many([]).
test_many([X|XS]):- test_list(X),nl,test_many(XS).

test:-
    test_many([
        [], [1], [1,2], [1,2,3],
        [[]], [[1]], [[1,2]], [[1,2,3]],
        [[1,2,3],1], [[1,2,3],1,2],[[1,2,3],1,2,3],
        [[1,2,3],1,[]], [[1,2,3],1,2,[1]],[[1,2,3],1,2,3,[1,2,3]]
    ]).
%==========================================
%               IPC
%==========================================

% Read All Lines from a Stream where each Line is a list of Codes
% read_lines(+Stream,-Lines)
read_lines(S,[]):-
    at_end_of_line(S),!.
read_lines(S,[L|Ls]):-
    read_line(S,L),
    read_lines(S,Ls).

% Writes Lines to the console, where each Line is a List of Codes
% write_line(+Lines)
write_lines([]).
write_lines([L|Ls]):-
    write_line(L),
    write_lines(Ls).

% Write a Line to the console, Line is a List of Codes
% write_line(+Line)
write_line(L):-
    atom_codes(String,L),
    write(String),nl.


% Calls python3 with the given Args, returns the process stdout, blocking
% call_python(+Args,-Lines)
call_python(Args,Lines):-
    BaseArgs = ['python3',' '],
    list_append_many(BaseArgs,Args,FinalArgs),
    process_create(path(bash),
        ['-c',FinalArgs], 
        [stdout(pipe(Stream))]
     ),
    read_lines(Stream,Lines), close(Stream).
    
% Calls program that given a TestFile and a possible Solution checks its viability
% It prints to the terminal the offenses if any
% check_solution(+File,+Solution)
check_solution(File,Solution):-
    list_to_string(Solution,SolutionString),
    call_python(['./shift_problem/bin/check_solution.py',' ',File, ' ',SolutionString ],Lines),
    write('checker output:\n'),
    write_lines(Lines).


% Convert an element from a list of lines using ParsingPredicate and unify with Result
% parse_at(+List,+Position,+ParsingPredicate,-Result):-
parse_at(List,Position,ParsingPredicate,Result):-
    list_at(List,Position,ToParse),
    call(ParsingPredicate,ToParse,Result).



% ===================================================
% Statistics
% ===================================================

% is_file(+FilName) true if the file exists
is_fIle(FileName):-
    absolute_file_name(FileName,_AbsFileName,[access(exists),fileerrors(fail)]).


% Given a pair FileName-AbsPath, get the AbsPath.
% get_abs_path(+FileName-AbsPath,-AbsPath).
get_abs_path(FileName-AbsPath,AbsPath).

 
% list_directory_abs_paths(+Dir,-AbsolutePathOfFilesInDir)
list_directory_abs_paths(Dir,Files):-
    file_members_of_directory(Dir,Pairs),
    list_map(Pairs,get_abs_path,Files).

% Returns list of pairs FileName-AbsolutePath
% list_directory_filename_abs_path(-Dir,-FilenameAbsPathPairs):-
list_directory_filename_abs_path(Dir,FilenameAbsPathPairs):-
    file_members_of_directory(Dir,FilenameAbsPathPairs).

% Appends Suffix to Prefix and unifies with Result
% create_file_name(+Prefix,+Suffix,-Result)
create_file_name(Prefix,Suffix,Result):-
    atom_codes(Prefix,PCodes),
    atom_codes(Suffix,SCodes),
    list_append_many(PCodes,SCodes,PSCodes),
    atom_codes(Result,PSCodes).


% Line is a List of Items representing a CSV Line
% write_csv_line(+Stream,+Line) 
write_csv_line(Stream,[]):- write(Stream,'\n').
write_csv_line(Stream,[I|Items]):-
    write(Stream,I),
    write(Stream,','),
    write_csv_line(Stream,Items).


% post_csv_line(+FileName,+Line)
post_csv_line(FileName,Line):-
    open(FileName,append,Stream),
    write_csv_line(Stream,Line),
    close(Stream).
    
% PredicateToParse an item in statistics that is in time units
% Parameter is a key in statistics that represents time TS is Time in Seconds
% statistics_time_like(+Parameter,-TS):-
statistics_time_like(Parameter,TS):-
    statistics(Parameter,[_,T]),
    TS is ((T//10)*10)/1000.

% Conversions is a list of [Key,PredicateToConvert]
% These are the Metrics we will get from `statistics`
% statistics_conversions(-Conversions)
statistics_conversions([
    [runtime,statistics_time_like],
    [total_runtime,statistics_time_like],
    [memory_used,statistics]
]).

% In This Context Pair is a list of two elements
% get_first(+Pair,-Value)
get_first(Pair,Value):-
    list_at(Pair,0,Value).
% get_second(+Pair,-Value)
get_second(Pair,Value):-
    list_at(Pair,1,Value).
% Given a Pair Calls The second with the first unifying with value
%apply_second([Key,Func],Value):-
apply_second([Key,Func],Value):-
    call(Func,Key,Value).

% List Of Keys we are extracting from `statistics`
%statistics_keys(-Keys)
statistics_keys(Keys):-
    statistics_conversions(Pairs),
    list_map(Pairs,get_first,Keys).


% List of values of the keys we are extracting from `statistics`
%statistics_values(-Values)
statistics_values(Values):- 
    statistics_conversions(Pairs),
    list_map(Pairs,apply_second,Values).

% List of Keys we are extracting from `fd_statistics`
% fd_keys(-Keys)
fd_keys([prunings,constraints,backtracks,entailments,resumptions]).

% Header of the CSV we will be filling
% header(-Header)
header(Header):-
    fd_keys(FDKeys),
    statistics_keys(StatsKeys),
    list_concat([['FileName','Algorithm','Timeout','SolutionType','Amount'],StatsKeys,FDKeys],Header).

% Given the timeout inserted in labeling return information about it in a different format
% timeout_options_expand(+FDTimeout,-[TimeoutInSeconds,SolutionType])
timeout_options_expand(false,[0,optimality]).
timeout_options_expand(time_out(TimeInMs,Flag),[TimeInSecs,Flag]):-
    TimeInSecs is TimeInMs / 1000.

% **List of values of the keys** we are extracting from `fd_statistics`
% `fd_values(-Values)`
fd_values(Values):- 
    fd_keys(Keys),
    list_map(Keys,fd_statistics,Values).


reset_timer:-
        statistics(total_runtime, _).


% Create CSV file if not exists, writting the header
% init_statistics_file(+FileName)
init_statistics_file(FileName):-
    is_file(FileName),!.
init_statistics_file(FileName):-
    \+ is_file(FileName),!,
    open(FileName,write,Stream),
    header(Header),
    write_csv_line(Stream,Header),
    close(Stream).


% init_statistics(+FileName).
init_statistics(FileName):-
     reset_timer,
     init_statistics_file(FileName).


% Based on the type of the Solution unify AmountOut (if SolutionType is time_out no Amount was found)
% is_worker_amount_grounded(+SolutionType,+AmountCalculated,-AmoutOut).
is_worker_amount_grounded(time_out,_,0).
is_worker_amount_grounded(_,Amount,Amount).

% save_statistics(+StatsFile,+File,+Algorithm,+TimeoutOptions,+Amount)
% +StatsFile csv file path
% +File file path of the problem
% +Algorithm algorithm name being used
% TimeoutOptions time_out term passed to the labeling,
% +Amount variable passed to the minimize
save_statistics(StatsFile,File,Algorithm,TimeoutOptions,Amount):-
    timeout_options_expand(TimeoutOptions,[Timeout,SolutionType]),
    statistics_values(StatsValues),
    fd_values(FDValues),
    
    is_worker_amount_grounded(SolutionType,Amount,NewAmount),
    list_concat([[File,Algorithm,Timeout,SolutionType,NewAmount],StatsValues,FDValues],Line),
    post_csv_line(StatsFile,Line).
% ==================================
%   Test Logging
% ==================================


% write_seconds(+TSS)
write_seconds(TSS):-
    TSS > 1,!,
    TS is integer(TSS),
    Minutes is TS //  60,
    S is TS mod 60,
    write(Minutes),write('m '),write(S),write('s'),nl.
write_seconds(TSS):-
    write(TSS),write('s'),nl.

%print_time(+Msg)
print_time(Msg):-
    statistics(total_runtime,[_,T]),
    TS is ((T//10)*10)/1000, nl,
    write(Msg),
    write_seconds(TS).


%log_time_out(+TimeoutTerm):-
log_time_out(false):-
    write('Running without any timout...\n').
log_time_out(time_out(TimeInMs,_LabelingResult)):-
    TimeInSecs = TimeInMs / 1000,
    write('Running with timout of '), write_seconds(TimeInSecs).
log_test(Algorithm,File,TimeoutOptions):-
    write('-----> Algorithm: '),write(Algorithm),nl,
    write('File: '),write(File),nl,
    log_time_out(TimeoutOptions).


%log_problem_output(+WorkerPerJob,+WorkerAmount,+TimeoutOptions):-
log_problem_output(WorkerPerJob,WorkerAmount,TimeoutOptions):-
    write('Job worker allocation: '), write(WorkerPerJob),nl,
    write('Number of workers used: '),write(WorkerAmount),nl,
    log_time_out_results(TimeoutOptions).

% Logs the Soltuion Type Based on the Timeout Result
% log_time_out_results(+TimeoutTerm).
log_time_out_results(false).
log_time_out_results(time_out(_,optimality)):-
    write('[OPTIMAL SOLUTION] Optimal Solution was found in the given timout!\n').
log_time_out_results(time_out(_,success)):-
    write('[POSSIBLE SOLUTION] A solution was found but proof of optimality was not done in the given time\n').
log_time_out_results(time_out(_,time_out)):-
    write('[NO SOLUTION] No feasible solution was found in the given timeout\n').


%============================================================
% Helper Predicates to Handle/Log current Running Test Number
%============================================================

log_test_number_info([CurrentTest,TotalTests]):-
    write('Running Test '),write(CurrentTest),write('/'),write(TotalTests),nl.

build_test_number_info(Tests,[1,N]):-
    list_length(Tests,N).
update_test_number_info([Current,N],[Next,N]):-
    Next is Current + 1.

% ==================================
%   Test Running Definition
% ==================================

% +AbsPath              absolute path of the test file
% +FileName             filename of the test file
% +StatisticsAbsPath    absolute path of the statistics file
% +Algorithm            name of the algorithm
% +ParseFunc            predicate that will parse the problem that must receive [AbsolutePath|Vars]
% +SolveFunc            predicate that will solve the problem that must receive [TimeoutOptions,MS,Amount|Vars] parameters
% +LogInputFunc         predicate that will log the input that must receive Vars
% +Vars                 list of variables to be used by the problem
% +TimeoutOptions       timeout term to be passed to the labeling
% Note: Every predicate that uses Vars, must be used in the same order
%run_test(AbsPath,FileName,StatisticsAbsPath,Algorithm,ParseFunc,SolveFunc,LogInputFunc,Vars,TimeoutOptions)
run_test(AbsPath,FileName,StatisticsAbsPath,Algorithm,ParseFunc,SolveFunc,LogInputFunc,Vars,TimeoutOptions):-

    log_test(Algorithm,FileName,TimeoutOptions),

    write('Parsing Dat File...\n'),
    pred_call(ParseFunc,[AbsPath|Vars]),
    write('Parsing Success...\n'),

    pred_call(LogInputFunc,Vars),

    write('Calculating Solution'),
    init_statistics(StatisticsAbsPath),
    pred_call(SolveFunc,[TimeoutOptions,MS,Amount|Vars]),!,
    
    save_statistics(StatisticsAbsPath,FileName,Algorithm,TimeoutOptions,Amount),
    print_time('Finished in :'),

    log_problem_output(MS,Amount,TimeoutOptions).
    %check_solution(AbsPath,MS).
    

% minutes_to_milisecs(+Minutes,-Milisecs)
minutes_to_milisecs(Minutes,Milisecs):-
    Milisecs is Minutes * 60 * 1000.

% Tests is a list of FileName-AbsPath items.
% run_tests(+Tests,+StatisticsAbsPath,+Algorithm,+ParseFunc,+SolveFunc,+LogInputFunc,+Vars,+TimeOutInMinutes)
run_tests(Tests,StatisticsAbsPath,Algorithm,ParseFunc,SolveFunc,LogInputFunc,Vars,TimeOutInMinutes):-
	minutes_to_milisecs(TimeOutInMinutes,TimeoutInMs),
    TimeoutOptions = time_out(TimeoutInMs,LabelingResult),
    build_test_number_info(Tests,TestNumberInfo),
    run_tests(Tests,TestNumberInfo,StatisticsAbsPath,Algorithm,ParseFunc,SolveFunc,LogInputFunc,Vars,TimeoutOptions).

run_tests([],_TestNumberInfo,_StatisticsAbsPath,_Algorithm,_ParseFunc,_SolveFunc,_LogInputFunc,_Vars,TimeoutOptions).
run_tests([FileName-AbsPath|TS],TestNumberInfo,StatisticsAbsPath,Algorithm,ParseFunc,SolveFunc,LogInputFunc,OVars,OTimeoutOptions):-
    % Create New Instance of Variables to be used by next run
    copy_term(OVars,Vars), copy_term(OTimeoutOptions,TimeoutOptions),

    log_test_number_info(TestNumberInfo),
    update_test_number_info(TestNumberInfo,NextTestNumberInfo),

    run_test(AbsPath,FileName,StatisticsAbsPath,Algorithm,ParseFunc,SolveFunc,LogInputFunc,Vars,TimeoutOptions),

    run_tests(TS,NextTestNumberInfo,StatisticsAbsPath,Algorithm,ParseFunc,SolveFunc,LogInputFunc,OVars,OTimeoutOptions).


% Runs All Tests Inside ../data folder
% run_tests(+StatisticsAbsPath,+Algorithm,+ParseFunc,+SolveFunc,+LogInputFunc,+Vars,+TimeOutInMinutes)
run_all_tests(StatisticsAbsPath,Algorithm,ParseFunc,SolveFunc,LogInputFunc,Vars,TimeOutInMinutes):-
    list_directory_filename_abs_path('../data/',Tests),
    run_tests(Tests,StatisticsAbsPath,Algorithm,ParseFunc,SolveFunc,LogInputFunc,Vars,TimeOutInMinutes).



% Each Algorithm can define a main function to run tests as command line arguments
% This mechanism is used to achieve paralelism as I have a python script that divides all the tests
% In batches and then spawns multiple processing, running each batch. (See main.py)
% The command line arguments main expects are StatisticsFilePath, Timeout in Minutes and space separated list
% Of Filename AbsolutePath pairs.
% parse_cmd_args(-StatisticsFile,-Timeout,-Tests)
parse_cmd_args(StatisticsFile,Timeout,Tests):- get_argv([StatisticsFile,TimeoutDef|TestList]),
    atom_codes(TimeoutDef,TimeoutDefCodes),
    number_codes(Timeout,TimeoutDefCodes),
    parse_cmd_test_list(TestList,Tests).


% Given a list of Filename and Abs File Path  transform it into a list of pairs: FileName-AbsFilePath
% parse_cmd_test_list(+TestListFromArgv,-TestListToBeConsumedByThisAPI)
parse_cmd_test_list([],[]).
parse_cmd_test_list([FileName,AbsPath|Rest],[FileName-AbsPath|Tests]):-
    parse_cmd_test_list(Rest,Tests).

%!    filter_indices(+Indices, +OriginalList, -Result)
%
%     Extracts elements from OriginalList at the given indices.
%
%     @param Indices       List of indices to extract.
%     @param OriginalList  The source list.
%     @param Result        List of extracted elements.
filter_indices([],_,[]).
filter_indices([I|IS],List,[E|ES]):-
    list_at(List,I,E),
    filter_indices(IS,List,ES).