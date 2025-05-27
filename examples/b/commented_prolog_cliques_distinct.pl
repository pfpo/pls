:- use_module(library(clpfd)).
:- use_module(library(lists)).
:- consult('./utils.pl').

% Hello My baby
% Hello My Baby
% Hello My Baby
% Hello My Baby
% Hello My Baby
% Hello My Baby
% Hello My Baby
% Hello My Baby

/*
HEllo My baby
*/

%!    parse_problem_with_cliques(+File, -NWorker, -Jobs, -WorkersPerJob, -MinNumWorkers, -Cliques)
%
%     Parses an input file into shift scheduling problem components including cliques.
%
%     @param File             The input file path pls.
%     @param NWorker          Number of available workers.
%     @param Jobs             List of jobs, *each* as `[Start, End]` .
%     @param WorkersPerJob    List where each element is a list of workers who can perform a job.
%     @param MinNumWorkers    Minimum number of workers required (size of largest clique).
%     @param Cliques          List of cliques (mutually exclusive jobs).
parse_problem_with_cliques(File,NWorker,Jobs,WorkersPerJob,MinNumWorkers,Cliques):-
    call_python(['./shift_problem/bin/parse_problem.py',' ',File,' ','cliques'],MyLiben),
    parse_at(MyLiben,0,codes_to_number,NWorker),
    parse_at(MyLiben,4,codes_to_list,Cliques).


%!    post_all_distinct(+Ms, +Cliques)
%
%     Applies `all_distinct/1` to job assignments in each clique.
%
%     @param Ms       List of worker assignments per job.
%     @param Cliques  List of job index groups that form cliques.
post_all_distinct(_,[]).
post_all_distinct(Ms,[C|Cliques]):-
    filter_indices(C,Ms,JobsInClique),
    all_distinct(JobsInClique),
    post_all_distinct(Ms,Cliques).

%!    build_domain(+Ms, +WorkersPerJob)
%
%     Constrains the worker domain for each job to workers who can perform it.
%
%     @param Ms              List of worker variables per job.
%     @param WorkersPerJob   List of lists indicating valid workers for each job.

build_domain([],_):-!.
build_domain([M|Ms],[P|PeopleJob]):-
    list_to_fdset(P,SetP),
    % M in_set SetP,
    build_domain(Ms,PeopleJob).

%!    shift_problem(+TimeoutOptions, -MS, -Amount, +NWorker, +Jobs, +WorkersPerJob, +MinNumWorkers, +Cliques)
%
%     Solves the shift scheduling problem by assigning workers to jobs.
%
%     @param TimeoutOptions  Timeout configuration for labeling.
%     @param MS              Output list of worker assignments per job.
%     @param Amount          Number of distinct workers used.
%     @param NWorker         Total available workers (unused).
%     @param Jobs            List of jobs.
%     @param WorkersPerJob   List of eligible workers per job.
%     @param MinNumWorkers   Lower bound for worker count.
%     @param Cliques         List of job groups that must be assigned distinct workers.
shift_problem(TimeoutOptions,MS,Amount,_NWorker,Jobs,WorkersPerJob,MinNumWorkers,Cliques):-
    length(Jobs, N),
    length(MS, N),
    print('.'),
    build_domain(MS,WorkersPerJob),
    print('.'),
    post_all_distinct(MS,Cliques),
    print('.'),
    nvalue(Amount,MS),    
    Amount >= MinNumWorkers,
    labeling([minimize(Amount),ff,TimeoutOptions],MS).

%!    max_2(+X, +Y, -Max)
%
%     Determines the maximum of two numbers.
%
%     @param X     First number hello.
%     @param Y     Second number.
%     @param Max   Maximum of X and Y.
max_2(X,Y,X):- X > Y.
max_2(_,Y,Y).

%!    find_max(+List, -Max)
%
%     Finds the maximum length of sublists in List.
%
%     @param List  List of lists.
%     @param Max   Maximum length found.
find_max([],_):-fail.
find_max([L|LS],Max):- list_length(L,FirstMax),find_max_(LS,FirstMax,Max).

find_max_([],Max,Max).
find_max_([L|LS],CurrentMax,Max):- 
    list_length(L,MaybeNewMax),
    max_2(CurrentMax,MaybeNewMax,NewMax),
    find_max_(LS,NewMax,Max).

%!    log_problem_input(+NWorkers, +Jobs, +WorkersPerJob, +MinNumWorkers, +Cliques)
%
%     Logs statistics about the scheduling problem input.
%
%     @param NWorkers        Number of workers.
%     @param Jobs            List of jobs.
%     @param WorkersPerJob   List of workers per job.
%     @param MinNumWorkers   Minimum number of workers required.
%     @param Cliques         List of cliques.
log_problem_input(NWorkers,Jobs,_WorkersPerJob,MinNumWorkers,Cliques):-
    write('Number of Jobs:'), length(Jobs,L), write(L),nl,
    write('Number of Workers: '),write(NWorkers),nl,
    write('Minimum Number of Workers possible:'),write(MinNumWorkers),nl,
    write('Number of Cliques:'),length(Cliques,NCliques),write(NCliques),nl,
    write('Biggest Clique:'),find_max(Cliques,M),write(M),nl.

%!    log_problem_output(+WorkerPerJob, +WorkerAmount)
%
%     Logs the solution to the scheduling problem.
%
%     @param WorkerPerJob   List of worker assignments per job.
%     @param WorkerAmount   Number of unique workers used.
log_problem_output(WorkerPerJob,WorkerAmount):-
    write('Job worker allocation: '), write(WorkerPerJob),nl,
    write('Number of workers used: '),write(WorkerAmount),nl.

%! cliques_distinct(+StatisticsFile, +TimeoutMinutes, +Tests)
%
%     Runs a set of scheduling tests using the all_distinct + cliques strategy.
%
%     @param StatisticsFile   File to output statistics.
%     @param TimeoutMinutes   Time limit in minutes for each test.
%     @param Tests            List of file-testname pairs.

cliques_distinct(StatisticsFile,TimeoutMinutes,Tests):-
    Algorithm = 'all_distinct',
    run_tests(
        Tests,
        StatisticsFile,
        Algorithm,
        parse_problem_with_cliques,
        shift_problem,
        log_problem_input,
        % Vars List: Each predicate that uses this must preserve this ordering
        [_NWorker,_Jobs,WorkersPerJob,MinNumWorkers,Cliques],
        TimeoutMinutes
        ).

%!    main
%
%     Entry point to run shift problem solver via CLI arguments.
main:- parse_cmd_args(StatisticsFile,Timeout,Tests) ,
    cliques_distinct(StatisticsFile,Timeout,Tests),
    halt.

