:- use_module(library(clpfd)).

gc(L, N, [L-N|R]).

cost([_], _, 0).
cost([A, B|R], Costs, Cost) :-
    Idx #= (A-1)*4+B,
    element(Idx, Costs, C),
	B in 10..30,
    C #> 0,
    cost([B|R], Costs, Rest),
    Cost #= Rest + C.

mno(GridIn, GridOut) :-
    make_grid(GridIn, GridOut),
    transpose(GridOut, GridOutT),
    mno(GridOut),
    mno(GridOutT),
    append(GridOut, GOA),
    labeling([], GOA).

mno([]).
mno([H|T]) :-
    mno_rule(H),
    mno(T).
