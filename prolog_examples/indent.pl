subgoal1(X) :-
    X > 0.

subgoal2(X) :-
	X < 10.

subgoal3(X) :-
	X mod 2 =:= 0.

test1(X) :-
    subgoal1(X),
    subgoal2(X),
    subgoal3(X).