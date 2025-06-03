:- module(random,[random_member/2,maybe/2,random_select/3,
	getrand/1,setrand/1,random_perm2/4,
	random/1,maybe/0,random_permutation/2,
	random_numlist/4,random/3,maybe/1,
	random_subseq/3]).

%! getrand(-RandomState)
%
% returns the random number generator's current state
%
% @param RandomState The current state of the random number generator.

%! setrand(+RandomState)
%
% sets the random number generator's state to RandomState.
% RandomState can either be a random state previously obtained
% with `getrand/1`, or an arbitrary integer. The latter is
% useful when you want to initialize the random state to a fresh
% value.
% If RandomState is not an integer or a valid random state, it
% raises an error.
%
% The initial state of the random number generator is always the same.
% This means that subsequent runs will generate the same sequence of random numbers.
% This gives reproducible results which is good for testing but not always desirable.
% One way to get a new initial state is to set it based on the current time, e.g. by
% calling something like the following predicate early in your program:
%
% ```
%     :- use_module(library(system), [now/1]).
%     init_random_state :-
%             now(X),
%             setrand(X).
%
% ```
%
% @param RandomState The state to set the random number generator to.

%! maybe
%
% succeeds determinately with probability 1/2,
% fails with probability 1/2. We use a separate "random bit"
% generator for this test to avoid doing much arithmetic.

%! maybe(+Probability)
%
% succeeds determinately with probability Probability,
% fails with probability 1-Probability.
% Arguments =< 0 always fail, >= 1 always succeed.
%
% @param Probability The probability of success (0.0 to 1.0).

%! maybe(+P, +N)
%
% succeeds determinately with probability P/N,
% where 0 =< P =< N and P and N are integers.
% If this condition is not met, it fails.
% It is equivalent to `random(0, N, X), X < P`, but is somewhat faster.
%
% @param P The numerator of the probability.
% @param N The denominator of the probability.

%! random(-Uniform)
%
% unifies Uniform with a new random number in [0.0,1.0)
%
% @param Uniform The random floating-point number.

%! random(+L, +U, -R)
%
% unifies R with a random integer in [L,U)
% when L and U are integers (note that U will *never* be generated),
% or to a random floating number in [L,U) otherwise.
%
% @param L The lower bound (inclusive).
% @param U The upper bound (exclusive).
% @param R The generated random number.

%! random_member(-Elem, +List)
%
% unifies Elem with a random element of List, which must be proper.
% Takes O(N) time (average and best case).
%
% @param Elem The randomly selected element from the list.
% @param List The list from which to select an element.

%! random_select(?Elem, ?List, ?Rest)
%
% unifies Elem with a random element of List and Rest with all the
% other elements of List (in order). Either List or Rest should
% be proper, and List should/will have one more element than Rest.
% Takes O(N) time (average and best case).
%
% @param Elem The randomly selected element from the list.
% @param List The input list.
% @param Rest The list containing all elements of List except Elem.

%! random_subseq(+List, -Sbsq, -Cmpl)
%
% unifies Sbsq with a random sub-sequence of List, and Cmpl with its
% complement. After this, `subseq(List, Sbsq, Cmpl)` will be true.
% Each of the 2**|List| solutions is equally likely. Like its
% name-sake `subseq/3`, if you supply Sbsq and Cmpl it will interleave
% them to find List. Takes O(N) time. List should be proper.
%
% @param List The input list.
% @param Sbsq A random subsequence of List.
% @param Cmpl The complement of Sbsq (elements of List not in Sbsq).

%! random_permutation(?List, ?Perm)
%
% unifies Perm with a random permutation of List. Either List or Perm
% should be proper, and they should/will have the same length. Each of
% the N! permutations is equally likely, where `length(List, N)`.
% This takes O(N lg N) time and is bidirectional.
%
% @param List The input list.
% @param Perm A random permutation of List.

%! random_perm2(A,B, X,Y)
%
% unifies X,Y = A,B or X,Y = B,A, making the choice at random,
% each choice being equally likely. It is equivalent to
% `random_permutation([A,B], [X,Y])`.
%
% @param A The first element.
% @param B The second element.
% @param X The first element of the permuted pair.
% @param Y The second element of the permuted pair.

%! random_numlist(+P, +L, +U, -List)
%
% where P is a probability (0..1) and L=<U are integers
% unifies List with a random subsequence of the integers L..U,
% each integer being included with probability P.
%
% @param P The probability of including each integer.
% @param L The lower bound of the integer range (inclusive).
% @param U The upper bound of the integer range (inclusive).
% @param List A random subsequence of integers from L to U.
