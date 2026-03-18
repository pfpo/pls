% common prolog errors

% single element list on append
list([2, 3, 4]).
list_1([5, 6, 7]).


% use of single element list with append. should be transformed to [ H | T ] format.
test_append(X) :-
	list(L),
	append([1], L, X).

test_append(X) :-
	list(L),
	append([1, 2], L, X).

test_append(X, V) :-
	list(L),
	append([V], L, X).

% test_append(X) :-
% 	list(L),
%   X = [1 | L].
% test_append([1 | L]) :-
% 	list(L).

% use of empty lists on append. should be transformed to direct unification.
test_empty_append(X) :-
	list(L),
	append([], L, X).

test_empty_append(X) :-
	list(L),
	append(L, [], X).

test_empty_append(X) :-
	append([], [], X).

% test_empty_append(X) :-
% 	list(L),
% 	X = L.


% use of single element list with recursive list construction. should be transformed to [ H | T ] format.
test_recursive(X) :-
	list(L),
	X = [1, 2, 3 | [ 4, 5 | L]].

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
