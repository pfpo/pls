subgoal1(1).
subgoal2(2).
subgoal3(1).

subgoal_per_line(X, Y) :-
    subgoal3(Y),
    subgoal1(X), subgoal2(Y).
