:- module(sdfskdmfskl,[yas/7,l/7]).

:- consult('utils.pl').

:- use_module(library(clpfd)).

% Solve Shift Problem Minimization using cumulatives 
% +TimeoutOptions time_out(Timeout,Flag) 
% -MS dvar with the scheduling
% -Amount the amount of workers used
% shift_problem(+TimeoutOptions,-MS,-Amount,+NWorkers,+Jobs,+WorkersPerJob,+MinNumWorkers):-


%!  l(TimeoutOptions,MS,Amount,Arg0,Arg1,WorkersPerJob,MinNumWorkers)
%
% Predicate Description 
%
% @param TimeoutOptions  Argument's TimeoutOptions description
% @param MS  Argument's MS description
% @param Amount  Argument's Amount description
% @param Arg0  Argument's Arg0 description
% @param Arg1  Argument's Arg1 description
% @param WorkersPerJob  Argument's WorkersPerJob description
% @param MinNumWorkers  Argument's MinNumWorkers description

yas(TimeoutOptions,MS,Amount,[],1,WorkersPerJob,MinNumWorkers):-
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
    labeling([minimize(Amount),ff,TimeoutOptions],MS).

