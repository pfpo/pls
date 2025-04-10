hello.
main(1,2,m).

r(X):- X > 1,main(a,b,c).

X:- X.

max_2(X,Y,X):- X > Y.
max_2(_,Y,Y).

find_max(X,_):-fail.
find_max(x,Max):- list_length(L,FirstMax),find_max_(LS,FirstMax,Max).
find_max_(x,Max,Max).
find_max_(x,CurrentMax,Max):- 
    list_length(L,MaybeNewMax),
    max_2(CurrentMax,MaybeNewMax,NewMax),
    find_max_(LS,NewMax,Max).