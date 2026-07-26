
%!  is_even(+X)
%
% Fails if X is not even.
%
% @param +X A number to check for evenness.
is_even(X) :-
    0 is X mod 2.



%!  are_even(+Z, +Y)
% 
% Fails if either Z or Y is not even.
%
% @param +Z A number to check for evenness.
% @param +Y A number to check for evenness.
are_even(X, Y) :-
   is_even(X),
   is_even(Y).

