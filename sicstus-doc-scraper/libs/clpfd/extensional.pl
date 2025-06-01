%! element(?X,+List,?Y)
%
% True if the X-th element of List equals Y.
% List and Y should be of the same numeric type, i.e., integer or real.
% Elements are counted from 1.
% Maintains domain consistency in X, bounds consistency in List, and domain consistency in Y.
% Corresponds to `nth1/3` in `library(lists)` and to `element` in MiniZinc.
%
% @param X *integer*
% @param List *list of numeric*
% @param Y *numeric*

%! element(+List,?Y)
%
% True if some element of List equals Y, which can be integer or real.
% Maintains domain consistency in Y and bounds consistency in List.
% Corresponds to the built-in `member/2` and to `member` in MiniZinc (but note the different order of arguments).
%
% @param List *list of domain*
% @param Y *numeric*

%! relation(?X,+MapList,?Y)
%
% True if MapList contains a pair `X-R` and Y is in the range denoted by R.
% Maintains domain consistency.
% An arbitrary binary constraint can be defined with `relation/3`.
% `relation/3` is implemented by straightforward transformation to the more general `table/[2,3]` constraint.
%
% @param X *integer*
% @param MapList *list of integer-IntegerRange pairs*
% @param Y *integer*

%! table(+Tuples,+Extension)
%! table(+Tuples,+Extension,+Options)
%
% Defines an n-ary constraint by extension.
% The constraint holds if every Tuple in Tuples occurs in the Extension.
% The constraint maintains domain consistency, even if it is used reified.
% Corresponds to `table` in MiniZinc.
% For convenience, Extension may contain IntegerRange expressions in addition to integers.
%
% @param Tuples *list of lists of integers*
% @param Extension *list of lists of integers*
% @param Options *list of options*

%! case(+Template, +Tuples, +Dag)
%! case(+Template, +Tuples, +Dag, +Options)
%
% This constraint encodes an n-ary constraint, defined by extension and/or linear inequalities.
% It uses a DAG-shaped data structure where nodes correspond to variables and every arc is labeled
% by an admissible interval for the node above it and optionally by linear inequalities.
% The variable order is fixed: every path from the root node to a leaf node should visit every variable exactly once,
% in the order in which they occur lexically in Template.
% The constraint is true for a single ground tuple if there is a path from the root node to a leaf node such that
% (a) each tuple element is contained in the corresponding Min..Max interval on the path,
% and (b) any encountered linear inequalities along the path are true.
% The `case` constraint is true for a set of ground tuples if it is true for each tuple of the set.
% Variables in Tuples for which their template variable counterparts are constrained by side constraints,
% must have bounded domains. In the absence of side constraint, the constraint maintains domain consistency.
% The use of side constraint is deprecated.
%
% Here's an example:
% ```
% elts(X, Y, Z) :-
%     case(f(A,B,C), [f(X,Y,Z)],
%          [node(0, A,[(1..2)-1,(3..4)-2,(5..6)-3,(7..8)-4]),
%           node(1, B,[(1..1)-5]),
%           node(2, B,[(1..1)-6]),
%           node(3, B,[(2..2)-5]),
%           node(4, B,[(2..2)-7]),
%           node(5, C,[(10..10)]),
%           node(6, C,[(20..20)]),
%           node(7, C,[(30..30)])]).
% ```
% Sample queries for `elts/3`:
% ```
% | ?- elts(X, Y, Z).
% X in 1..8,
% Y in 1..2,
% Z in {10}\/{20}\/{30}
%
% | ?- elts(X, Y, Z), Z #>= 15.
% X in(3..4)\/(7..8),
% Y in 1..2,
% Z in {20}\/{30}
%
% | ?- elts(X, Y, Z), Y = 1.
% Y = 1,
% X in 1..4,
% Z in {10}\/{20}
% ```
%
% Here's an example with side constraints:
% ```
% calendar(M, V, R) :-
%         M in 1..3,
%         V in 1..8,
%         R in 1..8,
%         smt((M#=1 #/\ V in 1..3 #/\ R#=V+2) #\/
%             (M#=1 #/\ V in 4..5 #/\ R#=V+3) #\/
%             (M#=2 #/\ V in 1..2 #/\ R#=V) #\/
%             (M#=2 #/\ V in 3..4 #/\ R#=V+2) #\/
%             (M#=2 #/\ V in 5..5 #/\ R#=V+3) #\/
%             (M#=3               #/\ R#=V)).
% ```
% or equivalently as:
% ```
% calendar(M, V, R) :-
%     case(f(A,B,C),
%          [f(M,V,R)],
%          [node(0, A, [(1..1)-1, (2..2)-2, (3..3)-3]),
%           node(1, B, [(1..3)-[scalar_product([1,-1],[B,C],#=<,-2),
%                               scalar_product([1,-1],[C,B],#=<, 2)]-4,
%                       (4..5)-[scalar_product([1,-1],[B,C],#=<,-3),
%                               scalar_product([1,-1],[C,B],#=<, 3)]-4]),
%           node(2, B, [(1..2)-[scalar_product([1,-1],[B,C],#=<, 0),
%                               scalar_product([1,-1],[C,B],#=<, 0)]-4,
%                       (3..4)-[scalar_product([1,-1],[B,C],#=<,-2),
%                               scalar_product([1,-1],[C,B],#=<, 2)]-4,
%                       (5..5)-[scalar_product([1,-1],[B,C],#=<,-3),
%                               scalar_product([1,-1],[C,B],#=<, 3)]-4]),
%           node(3, B, [(1..8)-[scalar_product([1,-1],[B,C],#=<, 0),
%                               scalar_product([1,-1],[C,B],#=<, 0)]-4]),
%           node(4, C, [(1..8)])]).
% ```
% Sample queries for `calendar/3`:
% ```
% | ?- M in 1..3, V in 1..8, R in 1..8,
%      calendar(M, V, R).
% M in 1..3,
% V in 1..8,
% R in 1..8
%
% | ?- M in 1..3, V in 1..8, R in 1..8,
%      calendar(M, V, R), M #= 1.
% M = 1,
% V in 1..5,
% R in 1..8
%
% | ?- M in 1..3, V in 1..8, R in 1..8,
%      calendar(M, V, R), M #= 2, V #> 4.
% M = 2,
% V = 5,
% R = 8
% ```
%
% @param Template *nonground Prolog term*
% @param Tuples *list of terms*
% @param Dag *list of nodes*
% @param Options *list of options*
