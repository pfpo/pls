p.

p(X,Y,Z).

p(a,b).


main:- p(a,b,x),p(x,y),p.

list(1,2).

list(X):- X.

test(X):- list( [   p,
					p(1,2,3),
					
					p(1,2),
			] ),
          list([
            list([p,p(1,2,3),p(1,2)]),
                  list([main])
               ]), list(1,X),Z,
			   a,a,a,a,aa,a,a,a,a,Z.

hello:- list(1),list(1,2),test(X).
