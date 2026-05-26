
test(A, B, C, D, E, F, G, H, I, J, K, L) :-
    A > 0,
    B > 0,
    C > 0,
    D > 0,
    E > 0,
    F > 0,
    G > 0,
    H > 0,
    I > 0,
    J > 0,
    K > 0,
    L > 0.

test_a(A) :-
    test(A, A, A, A, A, A, A, A, A, A, A, A).

test_ab(A, B) :-
    test(A, B, A, B, A, B, A, B, A, B, A, B).