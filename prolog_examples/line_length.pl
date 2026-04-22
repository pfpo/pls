test_predicate(X, Y) :-
	length([1, 2, 3], X),
	length([a, b, c], Y).

test_long_predicate_one_liner(X, Y) :- length([1, 2, 3], X), length([a, b, c], Y).

