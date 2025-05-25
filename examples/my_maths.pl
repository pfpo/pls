
%!  square(+X:number, -Result:number) is det
%
%   Computes the square of X.
%
%   @param X       A number.
%   @param Result  The result of X * X.
square(X, Result) :-
    Result is X * X.