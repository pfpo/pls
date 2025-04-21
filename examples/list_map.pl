a([],[],_F).
a([X|XS],[Y|YS],F):-
    Z =.. [F,X,Y],
    Z,
    a(XS,YS,F).

add_1(X,Y):- Y is X + 1.

main:-
	a([1,2,3],X,add_1),
	write(X).