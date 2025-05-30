:- module('main', [main/0]).
:- module('main', [main/0]).

% Import specific predicates from math_utils.pl
:- use_module('math_utils.pl',[square/2,cube/2,yas/1]).

:- use_module('../module/math_utils.pl',[square/2,cube/2,yas/1]).

main :-
    square(4, S),
    cube(3, C),
	yas(2),
    format('4 squared is ~w~n', [S]),
    format('3 cubed is ~w~n', [C]).
