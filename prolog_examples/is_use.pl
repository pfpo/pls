test(X, Y) :-
	X is (1+2),
	Y is 3 / 5.

test :-
	10 is 5 + 5. % ca to =:=

test(X) :-
	X is 42. % ca to unification

test(X) :-
	X is [1, 2, 3]. % ca to unification

test(X) :-
	X is ola + ola. % ca to unification
	% X = ola + ola

test(X) :-
	X is -1. % verify also unary operators
			 % ca to X = -1

test(X) :-
	X is my_mod(6,2). % can give error

test(X) :-
	X is integer(2.5).

test(X) :-
	X is 6 mod 2.

% % list of arithmetic operators 4.7.5 SICSTus
% %

test(X, Y) :-
	X is Y. % ca to unification

test(X) :-
	X is oi * 2.