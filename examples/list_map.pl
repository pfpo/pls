a([],[],F).
a([X|XS],[Y|YS],F):-
    Z =.. [F,X,Y],
    Z,
    a(XS,YS,F).

add_1(X,Y):- Y is X + 1.