
%!  is_even(+X)
%
% Fails if X is not even.
%
% @param +X A number to check for evenness.
is_even(X) :-
    0 is X mod 2.

%!  is_even(+X, +Y)
% 
% Fails if either X or Y is not even.
%
% @param +X A number to check for evenness.
% @param +Y A number to check for evenness.
is_even(X, Y) :-
   is_even(X),
   is_even(Y).
