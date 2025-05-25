:- module(maths, [
    square/2,
    cube/2,
    factorial/2,
    sum_list/2
]).


%!  square(+X:number, -Result:number) is det
%
%   Computes the square of X.
%
%   @param X       A number.
%   @param Result  The result of X * X.
square(X, Result) :-
    Result is X * X.

%!  cube(+X:number, -Result:number) is det
%
%   Computes the cube of X.
%
%   @param X       A number.
%   @param Result  The result of X * X * X.
cube(X, Result) :-
    Result is X * X * X.

%!  factorial(+N:nonneg, -Result:number) is det
%
%   Computes the factorial of a non-negative integer N.
%
%   @param N       A non-negative integer.
%   @param Result  The result of N! (N factorial).
factorial(0, 1) :- !.
factorial(N, Result) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, R1),
    Result is N * R1.

%!  sum_list(+List:list(number), -Sum:number) is det
%
%   Computes the sum of all elements in List.
%
%   @param List  A list of numbers.
%   @param Sum   The total sum of the list elements.
sum_list([], 0).
sum_list([H|T], Sum) :-
    sum_list(T, Rest),
    Sum is H + Rest.
