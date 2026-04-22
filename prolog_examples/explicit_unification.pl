% explicit unification should be transformed into implicit unification in
test_unification(X, Y) :-
	X = 5.

test_unification(X) :-
	test(X),
	X = 1,
	write("hello").

% test_unification(1) :-
% 	test(1),
% 	1 = 1,
% 	write("hello").

% or

% extacted(1).
% test_unification(X) :-
% 	test(X),
% 	extracted(X),
% 	write("hello").

test_unification(X, Y, Z) :-
	X = 1,
	2 = Y,
	Z = 3.
% test_unification(1, 2, 3).

test_unification(X, Y, Z) :-
	X = 'a',
	'b' = Y,
	Z = 'c'.
% test_unification('a', 'b', 'c').

test_or_unification(X, Y) :-
	( X > 100, Y = 1
	; X =< 100, Y = 2
	).
% of course this could be written as
% test_or_unification(X, 1) :-
% 	X > 100.
% test_or_unification(X, 2) :-
% 	X =< 100.
