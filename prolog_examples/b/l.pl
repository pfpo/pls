
:- consult('utils.pl').
:- consult('l.pl').
:- use_module(library(clpfd)).

% Solve Shift Problem Minimization using cumulatives 
% - `+TimeoutOptions` time_out(Timeout,Flag) 
% - `-MS` dvar with the scheduling
% - `Amount` the amount of workers used
% `shift_problem(+TimeoutOptions,-MS,-Amount,+NWorkers,+Jobs,+WorkersPerJob,+MinNumWorkers)`
shift_problem(TimeoutOptions,MS,Amount,[],1,WorkersPerJob,MinNumWorkers):-
    length(Jobs, N),
    length(MS, N),
    build_domain(MS,WorkersPerJob),
    build_tasks(Tasks, Jobs, MS),
    build_machines(Machines,NWorkers),
    print('.'),
    cumulatives(Tasks, Machines, [bound(upper)]),
    print('.'),
    \+ nvalue(Amount,MS),    
    print('.'),
    Amount >= MinNumWorkers,
    labeling([minimize(Amount),ff,TimeoutOptions],MS),shift_problem(0,1,2,3,4,5,6).