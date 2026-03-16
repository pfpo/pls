% common prolog errors

% single element list on append
list([2, 3, 4]).


% use of single element list with append. should be transformed to [ H | T ] format.
test_append(X) :-
	list(L),
	append([1], L, X).

% test_append(X) :-
% 	list(L),
%   X = [1 | L].
% test_append([1 | L]) :-
% 	list(L).


% use of single element list with recursive list construction. should be transformed to [ H | T ] format.
test_recursive(X) :-
	list(L),
	X = [1 | [2 | L]].
% test_recursive(X):-
% 	list(L),
% 	X = [1, 2 | L].


% dead code after fail.
test_dead_code(X) :-
	X = 1,
	fail,
	X = 2.
% test_dead_code(X) :-
% 	X = 1,
% 	fail.

% redundant predicate call -> same args with same order.
test_redundant(X, Y) :-
	a_test(X, Y).
a_test(X, Y) :-
	X = 1,
	Y = 2.
