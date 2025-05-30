:- module(math_utils, [square/2, cube/2, yas/2]).

% square(Number, Result): Result is Number squared.
square(X, Y) :- 
    Y is X * X.

% cube(Number, Result): Result is Number cubed.
cube(X, Y) :- 
    Y is X * X * X.
