:- use_module(library(clpfd)).

object([piano, chair, bed, table]).
men_required([3, 1, 3, 2]).
time_required([30, 10, 15, 15]).
men(4).
max_time(60).

move(Starts):-
    time_required(Times),
    men_required(Res),
    build_tasks(Starts, Times, Ends, Res, Tasks, 1),

    max_time(MaxTime),
    domain(Starts, 0, MaxTime),        % domain        13% (0.4)
    men(MaxMen),
    cumulative(Tasks, [limit(MaxMen)]), % tasks/men     48% (1.4)

    maximum(Max, Ends),                % ends don't
    Max #=< MaxTime,                   % exceed 60m     26% (0.8)
    labeling([], Starts).             % labeling       13% (0.4)

build_tasks([], [], [], [], [], _).
