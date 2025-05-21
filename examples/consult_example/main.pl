:- use_module(maths).

%!  run_demo is det
%
%   Runs sample arithmetic operations and prints the results.
run_demo :-
    X = 4,
    square(X, S),
    format('~w squared is ~w~n', [X, S]),

    cube(X, C),
    format('~w cubed is ~w~n', [X, C]),

    factorial(X, F),
    format('Factorial of ~w is ~w~n', [X, F]),

    List = [1, 2, 3, 4],
    sum_list(List, Sum),
    format('Sum of ~w is ~w~n', [List, Sum]).
