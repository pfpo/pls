subgoal1(1).
subgoal2(2).
subgoal3(1).

subgoal_per_line(X, Y) :-
    subgoal3(Y),
    write("Hello world!"), nl,
    subgoal1(X), subgoal2(Y),
    subgoal3(X).

