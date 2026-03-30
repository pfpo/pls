predicate_a(1, 2, 3, 4).

predicate_b(X, Y, Z, A) :-
	predicate_a(X, Y, Z, A).

test :-
	predicate_b(1, 2, 3, 4).