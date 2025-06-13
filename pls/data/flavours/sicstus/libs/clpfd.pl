:- module(clpfd,[(#<=>)/2, keysorting/3, first_bound/2, all_equal_reif/2,
 domain/2, geost/2, fd_statistics/2, scalar_product/4,
 symmetric_all_different/1, table/2, regular/2, if_then_else/4,
 global_cardinality/2, (#\)/2, sum/3, smt/1,
 subcircuit/1, diffn/2, automaton/8, assignment/2,
 (#=>)/2, inflexion/3, (#>)/2, (#<)/2,
 cumulatives/2, scalar_product_reif/6, disjoint1/2, solve/2,
 automaton/3, maximize/3, multi_cumulative/3, domain/3,
 maximum/2, (#\=)/2, maximize/2, automaton/9,
 increasing/1, all_different_except_0/1, disjoint2/1, all_different/2,
 case/4, network_flow/3, nvalue/2, cumulative/1,
 seq_precede_chain/2, bool_and/2, relation/3, (#/\)/2,
 lex_chain/2, decreasing/1, all_distinct_except_0/1, (#\/)/2,
 maximum_arg/2, value_precede_chain/3, cumulative/2, circuit/2,
 all_distinct/1, case/3, cumulatives/3, in/2,
 element/2, (#\)/1, fd_statistics/0, subcircuit/2,
 assignment/3, network_flow/2, value_precede_chain/2, seq_precede_chain/1,
 (#<=)/2, increasing/2, all_equal/1, ($=)/2,
 geost/3, keysorting/2, multi_cumulative/2, scalar_product_reif/5,
 later_bound/2, lex_chain/1, bool_xor/2, scalar_product/5,
 (#>=)/2, ($=<)/2, global_cardinality/3, decreasing/2,
 minimum/2, indomain/1, geost/4, inflexion_signature/2,
 minimum_arg/2, (#=<)/2, in_set/2, sorting/3,
 count/4, minimize/3, bin_packing/2, table/3,
 labeling/2, (#=)/2, diffn/1, all_distinct/2,
 disjoint1/1, bool_or/2, all_different/1, minimize/2,
 bool_channel/4, circuit/1, disjoint2/2, element/3,
 ($>=)/2, symmetric_all_distinct/1]).

%! #= (?IExpr, ?IExpr)
%
% defines an arithmetic relation: `?IExpr` is equal to `?IExpr`.
%
% @param IExpr *integer_expression*
% @param IExpr *integer_expression*

%! #\= (?IExpr, ?IExpr)
%
% defines an arithmetic relation: `?IExpr` is not equal to `?IExpr`.
%
% @param IExpr *integer_expression*
% @param IExpr *integer_expression*

%! #< (?IExpr, ?IExpr)
%
% defines an arithmetic relation: `?IExpr` is less than `?IExpr`.
%
% @param IExpr *integer_expression*
% @param IExpr *integer_expression*

%! #=< (?IExpr, ?IExpr)
%
% defines an arithmetic relation: `?IExpr` is less than or equal to `?IExpr`.
%
% @param IExpr *integer_expression*
% @param IExpr *integer_expression*

%! #> (?IExpr, ?IExpr)
%
% defines an arithmetic relation: `?IExpr` is greater than `?IExpr`.
%
% @param IExpr *integer_expression*
% @param IExpr *integer_expression*

%! #>= (?IExpr, ?IExpr)
%
% defines an arithmetic relation: `?IExpr` is greater than or equal to `?IExpr`.
%
% @param IExpr *integer_expression*
% @param IExpr *integer_expression*

%! $= (?RExpr, ?RExpr)
%
% defines an arithmetic relation: `?RExpr` is equal to `?RExpr`.
%
% @param RExpr *real_expression*
% @param RExpr *real_expression*

%! $=< (?RExpr, ?RExpr)
%
% defines an arithmetic relation: `?RExpr` is less than or equal to `?RExpr`.
%
% @param RExpr *real_expression*
% @param RExpr *real_expression*

%! $>= (?RExpr, ?RExpr)
%
% defines an arithmetic relation: `?RExpr` is greater than or equal to `?RExpr`.
%
% @param RExpr *real_expression*
% @param RExpr *real_expression*

%! sum(+Xs, +IRelOp, ?Value)
%
% True if sum(Xs) IRelOp Value. Corresponds roughly to sumlist/2 in library(lists).
%
% @param Xs *list of integer* a list of integer arguments
% @param IRelOp *relational_symbol* a relational symbol
% @param Value *integer* an integer argument
%
% @example
% ```
% | ?- Y in -1 .. 1, 10 div Y #= Z, indomain(Y).
% Y = -1, Z = -10 ? ;
% Y = 1, Z = 10 ? ;
% ```

%! scalar_product(+Coeffs, +Xs, +IRelOp, ?Value)
%
% True if sum(Coeffs*Xs) IRelOp Value.
%
% @param Coeffs *list of integer* a list of length n of integers
% @param Xs *list of integer* a list of length n of integer arguments
% @param IRelOp *relational_symbol* a relational symbol
% @param Value *integer* an integer argument

%! scalar_product(+Coeffs, +Xs, +IRelOp, ?Value, +Options)
%
% True if sum(Coeffs*Xs) IRelOp Value.
%
% @param Coeffs *list of integer* a list of length n of integers
% @param Xs *list of integer* a list of length n of integer arguments
% @param IRelOp *relational_symbol* a relational symbol
% @param Value *integer* an integer argument
% @param Options *list* a list that may include the following options:
%   * `among(Least,Most,Range)`: If given, then Least and Most should be integers and Range should be an IntegerRange. This option imposes the additional constraint on Xs that at least Least and at most Most elements belong to Range.
%   * `consistency(Cons)`: This can be used to control the level of consistency used by the constraint. The value is one of the following: `domain`, `bounds`, `value`.
%

%! scalar_product_reif(+Coeffs, +Xs, +IRelOp, ?Value, ?Reif)
%
% is the reified version of `scalar_product/[4,5]`, i.e., Reif is 1 if `scalar_product/[4,5]` with the same arguments holds; otherwise, Reif is 0.
%
% @param Coeffs *list of integer* a list of length n of integers
% @param Xs *list of integer* a list of length n of integer arguments
% @param IRelOp *relational_symbol* a relational symbol
% @param Value *integer* an integer argument
% @param Reif *integer* 1 if the scalar product holds, 0 otherwise

%! scalar_product_reif(+Coeffs, +Xs, +IRelOp, ?Value, ?Reif, +Options)
%
% is the reified version of `scalar_product/[4,5]`, i.e., Reif is 1 if `scalar_product/[4,5]` with the same arguments holds; otherwise, Reif is 0.
%
% @param Coeffs *list of integer* a list of length n of integers
% @param Xs *list of integer* a list of length n of integer arguments
% @param IRelOp *relational_symbol* a relational symbol
% @param Value *integer* an integer argument
% @param Reif *integer* 1 if the scalar product holds, 0 otherwise
% @param Options *list* a list of options, same as for scalar_product/5

%! minimum(?Value, +Xs)
%
% True if Value is the minimum of Xs. Corresponds to `min_member/2` in `library(lists)` and to `minimum` in MiniZinc.
%
% @param Value *numeric* a numeric argument
% @param Xs *list of numeric* a list of numeric arguments

%! maximum(?Value, +Xs)
%
% True if Value is the maximum of Xs. Corresponds to `max_member/2` in `library(lists)` and to `maximum` in MiniZinc.
%
% @param Value *numeric* a numeric argument
% @param Xs *list of numeric* a list of numeric arguments

%! minimum_arg(+Xs, ?Index)
%
% True if Index is the index of the minimum value of Xs, counting from 1. If that value occurs more than once, Index is the index of the first occurrence. Corresponds to `arg_min` and `minimum_arg` in MiniZinc.
%
% @param Xs *list of integer* a list of integer arguments
% @param Index *integer* an integer argument

%! maximum_arg(+Xs, ?Index)
%
% True if Index is the index of the maximum value of Xs, counting from 1. If that value occurs more than once, Index is the index of the first occurrence. Corresponds to `arg_max` and `maximum_arg` in MiniZinc.
%
% @param Xs *list of integer* a list of integer arguments
% @param Index *integer* an integer argument

%! if_then_else(?If, ?Then, ?Else, ?Value)
%
% True if If=1 and Value=Then, or If=0 and Value=Else.
% ```
% | ?- Y in 0..1, 10 div Y #= 10 #<=> B, indomain(Y).
% Y = 0, B = 0 ? ;
% Y = 1, B = 1 ? ;
% ```
% 
% ```
% | ?- Y in -1 .. 1, Z #= if_then_else(1, 2, 10 div Y), indomain(Y).
% Y = -1, Z = 2 ? ;
% Y = 1, Z = 2 ? ;
% ```
%
% @param If *integer* an integer argument with domain contained in `0..1`.
% @param Then *numeric* a numeric argument, either integer or real.
% @param Else *numeric* a numeric argument, either integer or real.
% @param Value *numeric* a numeric argument, either integer or real.

%! smt(:Body)
%
% The arithmetic, membership, and propositional constraints described
% earlier are transformed at compile time to conjunctions of library
% constraints. Although linear in the size of the source code, the
% expansion of a propositional formula over reifiable constraints to
% library goals can have time and memory overheads, and propagates
% disjunctions very weakly. Temporary variables holding intermediate
% values may have to be introduced, and the grain size of the constraint
% solver invocations can be rather small. As an alternative to the
% default propagation of such constraint formulas, this constraint is a
% front-end to the `case/[3,4]` propagator, which treats such a
% formula globally.
%
% Although often convenient, this constraint is deprecated, because it
% cannot guarantee better performance than a decomposition, nor any
% particular level of consistency.
%
% @param Body ConstraintBody term (see Syntax of Indexicals).

%! count(+Val,+List,+IRelOp,?Count)
%
% True if N is the number of occurrences of Val in List and N IRelOp
% Count.
%
% Corresponds to `count_*` and `exactly` in MiniZinc.
%
% If you want to count how many times multiple values occur in the same list,
% the following constraint is a better alternative.
%
% @param Val integer
% @param List list of integer arguments
% @param IRelOp relational symbol as in Arithmetic Constraints
% @param Count integer argument

%! global_cardinality(+Xs,+Vals)
%! global_cardinality(+Xs,+Vals,+Options)
%
% True if every element of Xs is equal to some key and for each pair
% Ki-Vi, exactly Vi elements of Xs are equal to Ki.
%
% If either Xs or Vals is ground, and in many other special
% cases, then `global_cardinality/[2,3]` maintains domain
% consistency, but generally, domain or bounds consistency cannot be guaranteed.
%
% Corresponds to `global_cardinality*` and `distribute` in MiniZinc.
%
% Options is a list of zero or more of the following:
%
% `consistency(Cons)`
% Which filtering algorithm to use. One of the following:
% `domain`
% `bounds`
% A domain-consistency algorithm [Regin 96] is used, roughly linear in
% the total size of the domains. Note that the same algorithm is used
% also if `Cons = bounds`.
% `value`
% The constraint will use a simple algorithm, which prevents too few or
% too many of the Xs from taking values among the Vals.
%
% `cost(Cost,Matrix)`
% Cost is constrained to equal a cost computed as a function of
% Xs and Matrix, which should be a d*n matrix of
% integers, represented as a list of d lists, each of length
% n.
% The cost of the i-th arguments Xi is computed as follows.
% Suppose that the j-th pair of Vals is the pair Kj-Vj where Kj = Xi.
% Then the cost of Xi is Matrix[i,j].
% The total cost Cost is the total cost of all arguments Xi.
% With this option, a domain-consistency algorithm [Regin 99] is used.
%
% @param Xs list of integer arguments, e.g., `[X1,...,Xd]`
% @param Vals list of pairs where keys Ki are distinct integers and each Vi is a non-negative integer argument, e.g., `[K1-V1,...,Kn-Vn]`
% @param Options list of options

%! all_equal(+Arguments)
%
% Arguments are constrained to take the same value.
%
% Corresponds to `all_equal` in MiniZinc.
%
% @param Arguments list of integer arguments

%! all_equal_reif(+Arguments, ?Reif)
%
% Reif is 1 if `all_equal/1` with the same arguments holds; otherwise, Reif is 0.
%
% @param Arguments list of integer arguments
% @param Reif integer, 0 or 1

%! all_different(+Xs)
%! all_different(+Xs, +Options)
%! all_distinct(+Xs)
%! all_distinct(+Xs, +Options)
%
% Each argument is constrained to take a value that is unique among the arguments.
% Declaratively, this is equivalent to an inequality constraint for each
% pair of arguments.
%
% Corresponds to `all_different` in MiniZinc.
%
% Options is a list of zero or more of the following:
%
% `L #= R`
% Let Y1, ..., Yj be a subset of Xs.
% R should be an integer.
% L should be an expression of one of the following forms:
% `Y1 + ... + Yj`
% `Y1*Y1 + ... + Yj*Yj`
% `Y1 * ... * Yj`
% The given equation is a side constraint for the constraint to hold.
% A special bounds-consistency algorithm is used, which considers the main
% constraint and the side constraints globally. This option is only valid
% if the domains of Y1, ..., Yj consist of integers strictly
% greater than zero.
%
% `consistency(Cons)`
% Which algorithm to use. Cons can be one of the following:
% `domain`
% The default for `all_distinct/[1,2]` and `assignment/[2,3]`.
% A domain-consistency algorithm [Regin 94] is used, roughly linear in
% the total size of the domains.
% `bounds`
% A bounds-consistency algorithm [Lopez-Ortiz 03] is used, which runs
% in O(n log n) time for n arguments.
% `value`
% The default for `all_different/[1,2]`. An algorithm achieving
% exactly the same pruning as a set of pairwise inequality constraints is
% used, roughly linear in the number of arguments.
%
% `circuit(Boolean)`
% If `true`, then `circuit(Xs)` must hold for the
% constraint to be true.
%
% `subcircuit(Boolean)`
% If `true`, then `subcircuit(Xs)` must hold for the
% constraint to be true.
%
% `cost(Cost,Matrix)`
% Cost is constrained to equal a cost computed as a function of
% Xs and Matrix, namely
% Matrix[1,X1]+...+Matrix[n,Xn]. Matrix should be an
% n*m matrix of integers, represented as a list of lists.
%
% @param Xs list of integer arguments
% @param Options list of options

%! all_different_except_0(+Arguments)
%! all_distinct_except_0(+Arguments)
%
% The arguments are constrained to be all different, except
% those elements that are assigned the value 0.
%
% In terms of consistency, `all_different_except_0/1` corresponds
% to `all_different/1`, and `all_distinct_except_0/1` to
% `all_distinct/1`.
%
% Corresponds to `alldifferent_except_0` in MiniZinc.
%
% @param Arguments list of integer arguments with finite bounds

%! nvalue(?N, +Arguments)
%
% True if N is the number of distinct values taken by Arguments. Approximates
% bounds consistency in N and domain consistency in Arguments.
% Can be thought of as a relaxed version of `all_distinct/2`.
%
% Corresponds to `nvalue` in MiniZinc.
%
% @param N integer argument
% @param Arguments list of integer arguments with finite bounds

%! assignment(+Xs, +Ys)
%! assignment(+Xs, +Ys, +Options)
%
% True if all Xi, Yi are in 1..n and Xi=j iff Yj=i.
%
% Corresponds to `inverse` in MiniZinc.
%
% Options is a list of zero or more of the following, where
% Boolean must be `true` or `false` (`false` is the default):
%
% `consistency(Cons)`
% Same meaning as for `all_different/2`.
%
% `circuit(Boolean)`
% If `true`, then `circuit(Xs,Ys)` must hold for the
% constraint to be true.
%
% `subcircuit(Boolean)`
% If `true`, then `subcircuit(Xs,Ys)` must hold for the
% constraint to be true.
%
% `cost(Cost,Matrix)`
% Cost is constrained to equal a cost computed as a function of
% Xs and Matrix, namely
% Matrix[1,X1]+...+Matrix[n,Xn]. Matrix should be an
% n*n matrix of integers, represented as a list of lists.
%
% @param Xs list of integer arguments, e.g., `[X1,...,Xn]`
% @param Ys list of integer arguments, e.g., `[Y1,...,Yn]`
% @param Options list of options

%! symmetric_all_different(+Xs)
%! symmetric_all_distinct(+Xs)
%
% True if all elements of Xs = [X1,...,Xn] are in 1..n, they
% are all different, and for all i,j in 1..n, Xi=j iff Xj=i.
%
% Corresponds to `symmetric_all_different` in MiniZinc.
% `symmetric_all_distinct/1` maintains stronger consistency.
%
% @param Xs list of integer arguments, e.g., `[X1,...,Xn]`

%! increasing(+Xs)
%! increasing(+Xs,+Options)
%
% Requires that Xs be in increasing order.
%
% Options is a list of zero or one options, where
% Boolean must be `true` or `false`:
%
% `strict(Boolean)`
% If `false` (the default), then duplicates are allowed, otherwise they are not.
%
% @param Xs list of integer arguments

%! decreasing(+Xs)
%! decreasing(+Xs,+Options)
%
% Requires that Xs be in decreasing order.
%
% Options is a list of zero or one options, where
% Boolean must be `true` or `false`:
%
% `strict(Boolean)`
% If `false` (the default), then duplicates are allowed, otherwise they are not.
%
% @param Xs list of integer arguments

%! sorting(+Xs,+Ps,+Ys)
%
% The constraint holds if the following are true:
% * Ys is in ascending order.
% * Ps is a permutation of 1..n.
% * for all i in 1..n : Xi = Y(Pi)
%
% In practice, the underlying algorithm [Mehlhorn 00] is likely to achieve
% bounds consistency, and is guaranteed to do so if Ps is ground or
% completely free.
%
% Corresponds to `sort` in MiniZinc.
%
% @param Xs list of integer arguments, e.g., `[X1,...,Xn]`
% @param Ps list of integer arguments, e.g., `[P1,...,Pn]`
% @param Ys list of integer arguments, e.g., `[Y1,...,Yn]`

%! keysorting(+Xs,+Ys)
%! keysorting(+Xs,+Ys,+Options)
%
% The constraint holds if the following are true:
% * Ps is a permutation of 1..n.
% * for all i in 1..n, j in 1..m : Ys[i,j] = Xs[Ps[i],j].
% * [[Ys[i,1],...,Ys[i,k],Ps[i]] | i in 1..n] is in lex ascending
% order.
%
% The filtering algorithm is based on [Mehlhorn 00] and endeavors to maintain
% bounds consistency, but does not guarantee it.
%
% Corresponds to Prolog's `keysort/2`. In particular, the sort is stable by definition.
% Corresponds to `arg_sort` in MiniZinc.
%
% Options is a list of zero or more of the following:
%
% `keys(Keys)`
% Keys should be a positive integer, denoting the length of
% the key prefix. The default is 1.
%
% `permutation(Ps)`
% Ps should be a list of length n of integer arguments.
% Its meaning is described above.
%
% @param Xs list of tuples of integer arguments
% @param Ys list of tuples of integer arguments
% @param Options list of options

%! lex_chain(+Vectors)
%! lex_chain(+Vectors,+Options)
%
% The constraint holds if Vectors are in ascending lexicographic order.
%
% Corresponds to `*lex2`, `lex_greater*`, `lex_less*` in MiniZinc.
%
% Options is a list of zero or more of the following:
%
% `op(Op)`
% If Op is the atom `#=<` (the default), then the constraints holds
% if Vectors are in non-descending lexicographic order. If Op
% is the atom `#<`, then the constraints holds if Vectors are in
% strictly ascending lexicographic order.
%
% `increasing`
% This option imposes the additional constraint that each vector in
% Vectors be sorted in strictly ascending order.
%
% `among(Least,Most,Values)`
% If given, then Least and Most should be integers such that 0
% <= Least <= Most and Values should be a list of distinct
% integers. This option imposes the additional constraint on each vector
% in Vectors that at least Least and at most Most
% elements belong to Values.
%
% `global(Boolean)`
% If `true`, then a more expensive algorithm [Carlsson & Beldiceanu 02],
% which guarantees domain consistency unless the `increasing/0` or
% `among/3` options are given, will be used.
%
% @param Vectors list of vectors (lists) of integer arguments with finite bounds
% @param Options list of options

%! bool_and(+Lits, +Lit)
%
% True if Lit equals the Boolean conjunction of Lits.
% Usually more efficient than the equivalent `L0#/\...#/\Lj #<=> Lit`.
%
% @param Lits list of literals, e.g., `[L0,...,Lj]`
% @param Lit literal

%! bool_or(+Lits, +Lit)
%
% True if Lit equals the Boolean disjunction of Lits.
% Usually more efficient than the equivalent `L0#\/...#\/Lj #<=> Lit`.
%
% @param Lits list of literals, e.g., `[L0,...,Lj]`
% @param Lit literal

%! bool_xor(+Lits, +Lit)
%
% True if Lit equals the Boolean exclusive or of Lits.
% Usually more efficient than the equivalent `L0#\...#\Lj #<=> Lit`.
%
% @param Lits list of literals, e.g., `[L0,...,Lj]`
% @param Lit literal

%! bool_channel(+Lits, ?Y, +Relop, +Offset)
%
% Expresses the constraint Li #<=> (Y IRelOp i+Offset)
% for `i in 0..j`. Usually more efficient than a bunch of
% reified comparisons between a given argument and a sequence of
% integers.
%
% @param Lits list of literals, e.g., `[L0,...,Lj]`
% @param Y integer argument
% @param Relop arithmetic comparison as in Syntax of Integer Expressions
% @param Offset integer

%! labeling(:Options, +Variables)
%
% where Variables is a list of numeric arguments with finite bounds and Options is
% a list of search options. True if an assignment of the arguments can be found, which
% satisfies the posted constraints.
%
% The Options argument of `labeling/2` controls the order in
% which variables are selected for assignment (variable choice heuristic),
% the way in which choices are made for the selected variable (value
% choice heuristic), whether the problem is a satisfaction one or an
% optimization one, and whether all solutions or only the optimal one
% should be returned. The options are divided into 11 groups. At most one
% option may be selected per group, and each group has a default choice.
%
% #### Option Group 1--Variable Choice
% The following mutually exclusive options control the order in which the next variable is
% selected for assignment. In all cases, ties are broken by selecting
% the leftmost variable.
%
% `leftmost`
% `input_order`
% The leftmost variable is selected. This is the default.
%
% `min`
% `smallest`
% The variable with the smallest lower bound is selected.
%
% `max`
% `largest`
% The variable with the greatest upper bound is selected.
%
% `ff`
% `first_fail`
% The first-fail principle is used: the variable with the smallest
% domain is selected.
%
% `anti_first_fail`
% The variable with the largest domain is selected.
%
% `occurrence`
% The variable that has the most constraints suspended on it is
% selected. **Please note**: the mapping from constraints to
% propagators is subject to change from release to release, and after
% entailment, it is undefined whether a propagator is
% counted. Consequently, the behavior of `occurrence` may change
% from release to release.
%
% `ffc`
% `most_constrained`
% The most constrained heuristic is used: a variable with the smallest
% domain is selected, breaking ties by selecting the variable that has
% the most propagators suspended on it.
% **Please note**: the same caveat applies as for `occurrence`.
%
% `max_regret`
% The variable with the largest difference between its first two domain elements is selected.
% Not supported for real variables.
%
% `impact`
% The variable that has been involved in the most failures is selected.
% Not supported for real variables.
%
% `dom_w_deg`
% The variable is selected that maximizes the quantity failure count
% divided by domain size.
% Not supported for real variables.
%
% `variable(Sel)`
% Sel is a predicate to select the next variable. Given Vars,
% the variables that remain to label, it will be called as
% Sel(Vars,Selected,Rest).
%
% Sel is expected to succeed determinately, unifying Selected
% and Rest with the selected variable and the remaining list,
% respectively.
%
% Sel should be a callable term, optionally with a module prefix,
% and the arguments Vars, Selected, Rest will be
% appended to it. For example, if Sel is `mod:sel(Param)`,
% then it will be called as `mod:sel(Param,Vars,Selected,Rest)`.
%
% #### Option Group 2--Value Choice
% The following mutually exclusive options control the way in which
% choices are made for the selected variable X. For real
% variables, the default is an undefined order that could change from
% release to release and only the value/1 option is supported.
%
% `step`
% Makes a binary choice between `X #= B` and
% `X #\= B`, where B is the lower or upper bound of
% X. This is the default for integer variables. Not supported for real variables.
%
% `enum`
% Makes an n-ary choice for X corresponding to the values in its
% domain. Not supported for real variables.
%
% `bisect`
% Makes a binary choice between `X #=< M` and
% `X #> M`, where M is the middle of the domain of
% X, i.e., the mean of `min(X)` and `max(X)`
% rounded down to the nearest integer. This strategy is also known as
% domain splitting. Not supported for real variables.
%
% `interval`
% Makes a binary choice between `X #=< M` and
% `X #> M`, where M is:
% * the max of the first interval, if the domain of
% X consists of multiple intervals
% * as for `bisect` otherwise.
% Not supported for real variables.
%
% `value(Enum)`
% Enum is a predicate that should prune the domain of X,
% possibly but not necessarily to a singleton. It will be called as
% Enum(X,Rest,BB0,BB) where Rest is the list of variables that
% need labeling except X, and BB0 and BB are parameters
% described below.
%
% Enum is expected to succeed nondeterminately, pruning the domain
% of X, and to backtrack one or more times, providing alternative
% prunings. To ensure that branch-and-bound search works correctly, it
% must call the auxiliary predicate `first_bound(BB0,BB)`
% in its first solution. Similarly, it must call the auxiliary predicate
% `later_bound(BB0,BB)` in any alternative solution.
%
% Enum should be a callable term, optionally with a module prefix,
% and the arguments X,Rest,BB0,BB will be appended to it. For
% example, if Enum is `mod:enum(Param)`, then it will be called as
% `mod:enum(Param,X,Rest,BB0,BB)`.
%
% #### Option Group 3--Value Order
% The following mutually exclusive options control the order in which the choices are made
% for the selected variable X. They have no effect if combined with `value/1`.
%
% `up`
% The domain is explored in ascending order. This is the default.
% Useful with `enum`, `step` `bisect`, and with real
% variables.
%
% `down`
% The domain is explored in descending order. Useful with `enum`,
% `step` `bisect`, and with real variables.
%
% `median`
% Makes a binary choice between `X #= M` and
% `X #\= M`, where M is the median of the domain
% of X. If the domain has an even number of elements, then the
% smaller middle value is used. Useful with the `step` option.
% Not supported for real variables.
%
% `middle`
% Makes a binary choice between `X #= M` and
% `X #\= M`, where M is the middle of the domain
% of X, i.e., the mean of `min(X)` and
% `max(X)` rounded down to the nearest integer. Useful with
% the `step` option. Not supported for real variables.
%
% `random`
% Makes a binary choice between `X #= R` and
% `X #\= R`, where R is a random member of the
% domain of X. Useful with the `step` option and with real
% variables. The random number generator seed can be set and obtained
% with `fd_setrand/1` and `fd_getrand/1`.
%
% #### Option Group 4--Branch Order
% The following mutually exclusive options control the order in which
% the alternatives are explored for binary and n-ary choices. They have
% no effect if combined with `value/1`.
%
% `in`
% The alternatives are explored in the order described for Groups 2 and
% 3. This is the default.
%
% `out`
% The alternatives are explored in the reverse order of that described
% for Groups 2 and 3.
%
% #### Option Group 5--Precision
% When exploring alternatives for real variables, the number of float
% values contained in the domain is typically huge. It is usually a good
% idea to explore only a sample of them. The granularity of the sample
% is problem specific. If it it too coarse, solutions can be missed. If
% it is too fine, spurious, closely clustered solutions may be reported
% due to accumulated rounding errors that prevent those spurious
% solutions from being ruled out. The following parameter controls the
% granularity:
%
% `precision(P)`
% When exploring the alternatives for X, if its domain has been
% narrowed to A..B and A+P >= B, then only one candidate
% domain element will be tried. Otherwise, the domain will be
% split and explored recursively. P should be a non-negative float.
% The default is 0.0, but the value of the `precision` FD flag
% overrides P if it is greater than P.
%
% #### Option Group 6--Objective
% The following options tell the solver whether the given problem is a
% satisfaction problem or an optimization problem. In a satisfaction
% problem, we wish to find values for the domain variables, all
% solutions being equally good. In an optimization problem, we wish to
% find values that minimize or maximize some objective function
% reflected in an integer variable. It is useful to combine the
% optimization options with the `time_out/2`, `best`, and
% `all` options (see later). If these options occur more than
% once, then the last occurrence overrides previous ones.
%
% `satisfy`
% We have a satisfication problem. Its solutions are enumerated by
% backtracking. This is the default.
%
% `minimize(X)`
% `maximize(X)`
% We have an optimization problem, seeking an assignment where the value
% of the integer variable X is minimal (maximal). The labeling
% should fix X for all assignments of Variables.
%
% `lex_minimize(Xs)`
% `lex_maximize(Xs)`
% Similar to `minimize` and `maximize`, but the objective is
% not a single integer variable, but a vector of them to minimize or
% maximize lexicographically.
%
% `pareto_minimize(Xs)`
% `pareto_maximize(Xs)`
% Similar to `lex_minimize` and `lex_maximize`, but here we
% are looking not for a single, optimal solution, but for a set of
% solutions such that no solution is dominated by another
% solution. Suppose that Xs is assigned to As resp. Bs
% in solutions 1 resp. 2. For `pareto_minimize`, solution 1 is
% dominated by solution 2 iff As[i] >= Bs[i] for every position
% i. For `pareto_maximize`, solution 1 is dominated by
% solution 2 iff As[i] =< Bs[i] for every position i. The
% non-dominated solutions are enumerated by backtracking.
%
% #### Option Group 7--Optimization Incrementality
% The following options are only meaningful for optimization problems.
% They tell the solver whether to enumerate every solution that improves
% the objective function, or only the optimal one after optimality has
% been proved:
%
% `best`
% Return the optimal solution after proving its optimality.
% This is the default.
%
% `all`
% Enumerate all improving solutions, on backtracking seek the next
% improving solution. Merely fail after proving optimality. This
% option is not very useful for `pareto_minimize` and
% `pareto_maximize`, because an improving solution may later become
% dominated during search.
%
% #### Option Group 8--Optimization Strategy
% The following options too are only meaningful for optimization problems.
% They tell the solver what search scheme to use, but have no effect on
% the semantics or on the meaning of other options:
%
% `bab`
% Use a branch-and-bound scheme, which incrementally tightens the bound on
% the objective as more and more solutions are found.
% This is the default, and is usually the more efficient scheme.
%
% `restart`
% Use a scheme that restarts the search with a tighter bound on the
% objective each time a solution is found.
%
% #### Option Group 9--Restart
% Depth-first search suffers from the problem that wrong decisions made
% at the top of the search tree can take an exponential amount of search
% to undo. One common way to mitigate this problem is to restart the
% search from scratch, thus having a chance to make better decisions.
% Of course, this only makes sense if the decisions have a chance to be
% different, e.g., using the `random` option. The following
% options are meaningful for satisfaction as well as optimization
% problems. Restarts occur when a backtrack cutoff limit is reached
% after the latest (re)start. The default is no cutoff limit:
%
% `restart_constant(Scale)`
% The cutoff limit is fixed to Scale.
%
% `restart_linear(Scale)`
% The cutoff limit is fixed to Scale*k after the k-th (re)start.
% Scale should be an integer.
%
% `restart_geometric(Base, Scale)`
% The cutoff limit is fixed to Scale*(Base^k) after the k-th (re)start.
% Scale should be an integer and Base should be a float.
%
% `restart_luby(Scale)`
% The cutoff limit is fixed to Scale*L[k] after the k-th
% (re)start, where L[k] is the k-th number in the Luby
% sequence. The Luby sequence looks like:
%
% ```
% 1 1 2 1 1 2 4 1 1 2 1 1 2 4 8, ...
% ```
%
% e.g., it repeats two copies of the sequence ending in 2^i before
% adding the number 2^(i+1). Scale should be an integer.
%
% #### Option Group 10--Large Neighborhood Search
% Restarting search can be made more effective by using a fragment of
% the latest found solution as a warm start each time. With the
% following options, upon restart, for each variable to label, it is
% fixed to the previous solution with a given
% probability. **Please note**: this strategy makes the search
% procedure unable to exhaust the search space, so the search
% effectively goes on forever, or until the execution time limit has
% been exceeded. This strategy is meningful mainly for optimization
% problems with the `all` option:
%
% `relax_and_reconstruct(Xs, P)`
% `relax_and_reconstruct(Xs, P, Ys)`
% Upon restart, for each variable to label, it is fixed to the previous
% solution with probability P/100. If Ys is given, then use
% that as an initial solution until the first solution has been found.
%
% #### Option Group 11--Time-Out
% Finally, a limit on the execution time can be imposed:
%
% `time_out(Time,Flag)`
% See [lib-timeout](lib_002dtimeout.html).
% Time should be an integer number of milliseconds.
% The default is no time limit.
% If the search space is exhausted within this time limit and no solution is found,
% then the search merely fails, as usual.
% Otherwise, Flag is bound to a value reflecting the outcome:
%
% `optimality`
% If `best` was selected in an optimization problem, then the
% search space was exhausted, having found the optimal solution. The
% variables are bound to the corresponding values. If `best` was
% not selected, this flag value is not used.
%
% `success`
% If `best` was selected in an optimization problem, then the
% search timed out before the search space was exhausted, having found
% at least one solution. If `best` was not selected, then a
% solution was simply found before the time limit. In any case, the
% variables are bound to the values corresponding to the latest solution
% found.
%
% `time_out`
% If `best` was selected in an optimization problem, then the
% search timed out before any solution was found. If
% `best` was not selected, then the search timed out while
% searching for the next solution. The variables are left unbound.
%
% For example, to enumerate solutions using a static variable
% ordering, use:
%
% ```prolog
% | ?- constraints(Variables),
%      labeling([], Variables).
%      %same as [leftmost,step,up,satisfy]
% ```
%
% To minimize a cost function using branch-and-bound search, computing the
% best solution only, with a dynamic variable ordering using the
% first-fail principle, and domain splitting exploring the upper part of
% domains first, use:
%
% ```prolog
% | ?- constraints(Variables, Cost),
%      labeling([ff,bisect,down,minimize(Cost)], Variables).
% ```
%
% To give a time budget and collect the solutions of a satisfiability problem
% up to the time limit, use:
%
% ```prolog
% | ?- constraints(Variables),
%      findall(Variables, labeling([time_out(Budget,success)|Options]), Solutions).
% ```
%
% where `Flag=success` will hold if all solutions were found, and
% `Flag=time_out` will hold if the time expired.
%
% @param Options list
% @param Variables list

%! indomain(?X)
%
% where X is a numeric argument with finite bounds. Assigns via
% backtracking a feasible value to X. For integer arguments, the
% values are assigned in increasing order.
%
% @param X numeric

%! first_bound(+BB0, -BB)
%
% Provides an auxiliary service for the `value(Enum)` option.
%
% @param BB0 numeric
% @param BB numeric
%

%! later_bound(+BB0, -BB)
%
% Provides an auxiliary service for the `value(Enum)` option.
%
% @param BB0 numeric
% @param BB numeric


%! minimize(:Goal, ?X)
%! minimize(:Goal, ?X, +Options)
%
% Uses a restart algorithm to find an assignment that minimizes
% the integer variable X. Goal should be a Prolog
% goal that constrains X to become assigned, and could be a
% `labeling/2` goal. The algorithm calls Goal repeatedly with
% a progressively tighter upper (lower) bound on X until a proof of
% optimality is obtained.
%
% Whether to enumerate every solution that improves the objective
% function, or only the optimal one after optimality has been proved, is
% controlled by Options. If given, then it whould be a list containing a
% single atomic value, one of:
%
% `best`
% Return the optimal solution after proving its optimality.
% This is the default.
%
% `all`
% Enumerate all improving solutions, on backtracking seek the next
% improving solution. Merely fail after proving optimality.
%
% @param Goal callable
% @param X integer
% @param Options list
%

%! maximize(:Goal, ?X)
%! maximize(:Goal, ?X, +Options)
%
% Uses a restart algorithm to find an assignment that maximizes
% the integer variable X. Goal should be a Prolog
% goal that constrains X to become assigned, and could be a
% `labeling/2` goal. The algorithm calls Goal repeatedly with
% a progressively tighter upper (lower) bound on X until a proof of
% optimality is obtained.
%
% Whether to enumerate every solution that improves the objective
% function, or only the optimal one after optimality has been proved, is
% controlled by Options. If given, then it whould be a list containing a
% single atomic value, one of:
%
% `best`
% Return the optimal solution after proving its optimality.
% This is the default.
%
% `all`
% Enumerate all improving solutions, on backtracking seek the next
% improving solution. Merely fail after proving optimality.
%
% @param Goal callable
% @param X integer
% @param Options list
%

%! solve(:Options, :Searches)
%
% where Options is a list of options of the same shape as taken by
% `labeling/2`, and Searches is a list of `labeling/2` and
% `indomain/1` goals, or a single such goal. The domain variables of
% Searches must all have finite bounds. True if the conjunction
% of Searches is true.
%
% The main purpose of this predicate is for optimization, allowing to
% use different heuristics in the different Searches.
% For satisfiability problems, a simple sequence of `labeling/2` and
% `indomain/1` goals does the trick.
%
% The treatment of the Options, as well as the suboption lists given
% in the `labeling/2` goals of Searches, is a bit special.
% Some options are global for the whole search, and are ignored if they
% occur in the suboption lists. Others are local to the given
% `labeling/2` goal, but provides a default value for the whole
% search if it occurs in Options. The following table defines the
% role of each option as `global` or `local`:
%
% | `all` | `global` |
% | --- | --- |
% | `anti_first_fail` | `local` |
% | `bab` | `global` |
% | `best` | `global` |
% | `bisect` | `local` |
% | `dom_w_deg` | `local` |
% | `down` | `local` |
% | `enum` | `local` |
% | `ffc` | `local` |
% | `ff` | `local` |
% | `first_fail` | `local` |
% | `impact` | `local` |
% | `in` | `local` |
% | `input_order` | `local` |
% | `interval` | `local` |
% | `largest` | `local` |
% | `leftmost` | `local` |
% | `lex_maximize/1` | `global` |
% | `lex_minimize/1` | `global` |
% | `max_regret` | `local` |
% | `maximize/1` | `global` |
% | `max` | `local` |
% | `median` | `local` |
% | `middle` | `local` |
% | `minimize/1` | `global` |
% | `min` | `local` |
% | `most_constrained` | `local` |
% | `occurrence` | `local` |
% | `out` | `local` |
% | `pareto_maximize/1` | `global` |
% | `pareto_minimize/1` | `global` |
% | `precision` | `local` |
% | `random` | `local` |
% | `relax_and_reconstruct/2` | `global` |
% | `relax_and_reconstruct/3` | `global` |
% | `restart` | `global` |
% | `restart_constant/1` | `global` |
% | `restart_geometric/2` | `global` |
% | `restart_linear/1` | `global` |
% | `restart_luby/1` | `global` |
% | `satisfy` | `global` |
% | `smallest` | `local` |
% | `step` | `local` |
% | `time_out/2` | `global` |
% | `up` | `local` |
% | `value/1` | `local` |
% | `variable/1` | `local` |
%
% For example, to enumerate solutions using a static variable
% ordering, use:
%
% ```prolog
% | ?- constraints(Variables),
%      labeling([], Variables).
%      %same as [leftmost,step,up,satisfy]
% ```
%
% To minimize a cost function using branch-and-bound search, computing the
% best solution only, with a dynamic variable ordering using the
% first-fail principle, and domain splitting exploring the upper part of
% domains first, use:
%
% ```prolog
% | ?- constraints(Variables, Cost),
%      labeling([ff,bisect,down,minimize(Cost)], Variables).
% ```
%
% To give a time budget and collect the solutions of a satisfiability problem
% up to the time limit, use:
%
% ```prolog
% | ?- constraints(Variables),
%      findall(Variables, labeling([time_out(Budget,success)|Options]), Solutions).
% ```
%
% where `Flag=success` will hold if all solutions were found, and
% `Flag=time_out` will hold if the time expired.
%
% Note that, when used for optimization, `labeling/2` has a
% limitation compared to `minimize/[2,3]` and `maximize/[2,3]`:
% the variable and value choice heuristics specified by `labeling/2`
% must apply to the whole set of variables, with no provision for
% different heuristics for different subsets. As of release 4.3, this
% limitation has been lifted by the following predicate:
%
% ```prolog
% | ?- constraints([X1,X2,X3,Y1,Y2,Y3], Cost),
%      solve([minimize(Cost),all],
%            [labeling([leftmost],[X1,X2,X3]),
%             labeling([ff,bisect],[Y1,Y2,Y3])]).
% ```
%
% @param Options list
% @param Searches list or goal

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

%! circuit(+Succ)
%
% Corresponds to `circuit` in MiniZinc.
%
% @param Succ *list of integer*
% Succ is a list of length n of integer arguments. The
% value of the i-th element of Succ (Pred) is the
% successor (predecessor) of node i in the graph. True if the
% nodes form exactly one Hamiltonian circuit.

%! circuit(+Succ, +Pred)
%
% Corresponds to `circuit` in MiniZinc.
%
% @param Succ *list of integer*
% Succ is a list of length n of integer arguments. The
% value of the i-th element of Succ (Pred) is the
% successor (predecessor) of node i in the graph. True if the
% nodes form exactly one Hamiltonian circuit.

%! subcircuit(+Succ)
%
% Corresponds to `subcircuit` in MiniZinc.
%
% @param Succ *list of integer*
% Succ is a list of length n of integer arguments. If
% the value of the i-th element of Succ (Pred) is
% i, then that corresponds to a node not in the graph. Otherwise,
% the value is the successor (predecessor) of node i in the graph.
% True if the nodes that are included form at most one Hamiltonian subcircuit.

%! subcircuit(+Succ, +Pred)
%
% Corresponds to `subcircuit` in MiniZinc.
%
% @param Succ *list of integer*
% Succ is a list of length n of integer arguments. If
% the value of the i-th element of Succ (Pred) is
% i, then that corresponds to a node not in the graph. Otherwise,
% the value is the successor (predecessor) of node i in the graph.
% True if the nodes that are included form at most one Hamiltonian subcircuit.

%! network_flow(+Nodes, +Arcs)
%
% Corresponds to `network_flow` and `network_flow_cost` in MiniZinc.
%
% @param Nodes *list of node(Id,Balance)*
% Nodes should be a list of terms `node(Id,Balance)`. Id can be any term, but the ids of Nodes should be all distinct. Balance should be a non-negative integer, the difference between output and input flow for a node.
% @param Arcs *list of arc(From,To,Weight,Flow)*
% Arcs should be a list of terms `node(From,To,Weight,Flow)`. From and To identify the two nodes that the arc connects, and should occur as ids. They are looked up with `==/2`. Flow should be an integer argument with finite, non-negative bounds, the flow going through an arc. Weight should be a non-negative integer, the unit cost of the flow through an arc.

%! network_flow(+Nodes, +Arcs, +Options)
%
% Corresponds to `network_flow` and `network_flow_cost` in MiniZinc.
% The following figure:
% An example of `network_flow/3`.
%
% depicts the query:
%
% ```
% | ?- F0 in 1..3,
%      F1 in 2..4,
%      F2 in 0..3,
%      F3 in 0..1,
%      F4 in 2..10,
%      network_flow([node(0,3), node(1,2), node(2,-3), node(3,-2)],
%                   [arc(0,1,1,F0), arc(0,2,1,F1), arc(1,2,1,F2),
%                    arc(1,3,1,F3), arc(2,3,1,F4)],
%                   [cost(Cost)]
%      ).
% ```
%
% The query has a unique solution, with cost 8. The arcs of the figure have been annotated
% with the value of the flow, e.g., '`sol: 1`' stands for a flow equal to 1 in the solution.
%
% @param Nodes *list of node(Id,Balance)*
% Nodes should be a list of terms `node(Id,Balance)`. Id can be any term, but the ids of Nodes should be all distinct. Balance should be a non-negative integer, the difference between output and input flow for a node.
% @param Arcs *list of arc(From,To,Weight,Flow)*
% Arcs should be a list of terms `node(From,To,Weight,Flow)`. From and To identify the two nodes that the arc connects, and should occur as ids. They are looked up with `==/2`. Flow should be an integer argument with finite, non-negative bounds, the flow going through an arc. Weight should be a non-negative integer, the unit cost of the flow through an arc.
% @param Options *list of cost(Cost)*
% Options should be a list of at most one term of the form `cost(Cost)`. Cost, if given, should be an integer argument, the overall cost of the flow.

%! domain(+Variables, +Range)
%
%   True if the variables all are elements of Range.
%   domain/2 can be used for integer variables as well as for real variables.
%   For integer variables, Range should be an IntegerRange;
%   For real variables, Range should be a RealRange.
%   See Syntax of Range Expressions.
%
% @param Variables list of variables
% @param Range range expression

%! domain(+Variables, +Min, +Max)
%
%   True if the variables all are elements of the range Min..Max.
%   domain/3 can be used for integer variables as well as for real variables. For integer variables, Min is an integer or the atom
%   inf (minus infinity), and Max is an integer or the atom
%   sup (plus infinity). For real variables, Min is a real
%   or the atom finf (minus infinity), and Max is a real or
%   the atom fsup (plus infinity).
%
% @param Variables list of variables
% @param Min lower bound of the range
% @param Max upper bound of the range

%! in(?X, +Range)
%
%   True if X is an element of the range.
%   in/2 can be used for integer variables as well as for real variables.
%   For integer variables, Range should be an IntegerRange;
%   For real variables, Range should be a RealRange.
%   See Syntax of Range Expressions.
%
% @param X domain variable
% @param Range range expression

%! in_set(?X, +FDSet)
%
%   True if X is an element of the FD set.
%   in/2 and in_set/2 constraints maintain domain consistency
%   and their reified versions detect domain entailment and disentailment.
%
% @param X integer variable
% @param FDSet FD set

%! #\ :Q
%
%   True if the constraint Q is false.
%
% @param Q reifiable constraint

%! :P #/\ :Q
%
%   True if the constraints P and Q are both true.
%
% @param P reifiable constraint
% @param Q reifiable constraint

%! :P #\ :Q
%
%   True if exactly one of the constraints P and Q is true.
%
% @param P reifiable constraint
% @param Q reifiable constraint

%! :P #\/ :Q
%
%   True if at least one of the constraints P and Q is true.
%   For example:
%   ```
%   X #= 4 #\/ Y #= 6
%   ```
%
% @param P reifiable constraint
% @param Q reifiable constraint

%! :P #=> :Q
%
%   True if the constraint Q is true or the constraint P is false.
%
% @param P reifiable constraint
% @param Q reifiable constraint

%! :Q #<= :P
%
%   True if the constraint Q is true or the constraint P is false.
%
% @param Q reifiable constraint
% @param P reifiable constraint

%! :P #<=> :Q
%
%   True if the constraints P and Q are both true or both false.
%
% @param P reifiable constraint
% @param Q reifiable constraint

%! disjoint1(+Lines)
%! disjoint1(+Lines,+Options)
%
% constrains a set of lines to be non-overlapping.
% This constraint is best replaced by `diffn/[1,2]` in new code.
%
% @param Lines *list of term* Lines is a list of terms F(Sj,Dj) or
% F(Sj,Dj,Tj), Sj and Dj are integer arguments with
% finite bounds denoting the origin and length of line j
% respectively, F is any functor, and the optional Tj is an
% atomic term denoting the type of the line. Tj defaults to 0
% (zero).
% @param Options *list of term* Options is a list of zero or more of the following, where
% Boolean must be `true` or `false` (`false` is the
% default):
% `global(Boolean)` if `true`, then a redundant algorithm using global reasoning is used to
% achieve more complete pruning.
% `wrap(Min,Max)` If used, then the space in which the lines are placed should be thought of as
% a circle where positions Min and Max coincide, where
% Min and Max should be integers. That is, the space wraps
% around. Furthermore, this option forces the domains of the origin
% arguments to be inside [Min,Max-1].
% `margin(T1,T2,D)` This option imposes a minimal distance D between the end point of
% any line of type T1 and the origin of any line of type T2.
% D should be a positive integer or `sup`. If `sup` is
% used, then all lines of type T2 must be placed before any line of type
% T1. This option interacts with the `wrap/2` option in the sense that
% distances are counted with possible wrap-around, and the distance
% between any end point and origin is always finite.

%! disjoint2(+Rectangles)
%! disjoint2(+Rectangles,+Options)
%
% constrains a set of rectangles to be non-overlapping.
% This constraint is best replaced by `diffn/[1,2]` in new code.
%
% @param Rectangles *list of term* Rectangles is a list of terms F(Xj,Lj,Yj,Hj) or
% F(Xj,Lj,Yj,Hj,Tj), Xj and Lj are integer arguments with
% finite bounds denoting the origin and size of rectangle j in the X
% dimension, Yj and Hj are the values for the Y dimension,
% F is any functor, and the optional Tj is an atomic term
% denoting the type of the rectangle. Tj defaults to 0 (zero).
% @param Options *list of term* Options is a list of zero or more of the following, where
% Boolean must be `true` or `false` (`false` is the
% default):
% `global(Boolean)` Disabled.
% `wrap(Min1,Max1,Min2,Max2)` Min1 and Max1 should be either integers or the atoms
% `inf` and `sup` respectively. If they are integers, then the space
% in which the rectangles are placed should be thought of as a cylinder
% wrapping around the X dimension where positions Min1 and
% Max1 coincide. Furthermore, this option forces the domains of the
% Xj arguments to be inside [Min1,Max1-1].
% Min2 and Max2 should be either integers or the atoms
% `inf` and `sup` respectively. If they are integers, then the space
% in which the rectangles are placed should be thought of as a cylinder
% wrapping around the Y dimension where positions Min2 and
% Max2 coincide. Furthermore, this option forces the domains of the
% Yj arguments to be inside [Min2,Max2-1].
% If all four are integers, then the space is a toroid wrapping around both
% dimensions.
% `margin(T1,T2,D1,D2)` This option imposes minimal distances D1 in the X dimension and
% D2 in the Y dimension between the end point of any rectangle of
% type T1 and the origin of any rectangle of type T2.
% D1 and D2 should be positive integers or `sup`. If
% `sup` is used, then all rectangles of type T2 must be placed
% before any rectangle of type T1 in the relevant dimension.
% This option interacts with the `wrap/4` option in the sense that
% distances are counted with possible wrap-around, and the distance
% between any end point and origin is always finite.
% `synchronization(Boolean)` Disabled.

%! diffn(+Boxes)
%! diffn(+Boxes,+Options)
%
% constrains a set of multidimensional boxes to be non-overlapping.
%
% @param Boxes *term* A box is represented by a term [Facet,Facet,...].
% A facet is a term of the form Origin-Length, where
% the integer arguments Origin and Length are the coordinate and length of the box in the given dimension.
% All boxes should have the same dimensionality (length of the box term).
% @param Options *list of term* Options is a list of zero or one of the following, where
% Boolean must be `true` or `false`:
% `strict(Boolean)` If `false` (the default), then the constraint is true iff, for all pairs of boxes i, j,
% there exists a dimension with respective facets Oi-Li and Oj-Lj and their overlap is zero, i.e.:
% ```
% Oi+Li <= Oj or
% Oj+Lj <= Oi or
% Li = 0 or
% Lj = 0
% ```
% If `true`, then the constraint is true iff, for all pairs of boxes i, j,
% there exists a dimension with respective facets Oi-Li and Oj-Lj and one precedes the other, i.e.:
% ```
% Oi+Li <= Oj or
% Oj+Lj <= Oi
% ```
% Corresponds to `diffn*` and `disjunctive*` in MiniZinc.

%! bin_packing(+Items,+Bins)
%
% constrains the placement of items of given size in bins of given
% capacity, so that the total load of any bin matches its capacity.
%
% @param Items *list of term* Items is a list of terms of the form
% `item(Bin,Size)` where Bin is an integer argument
% denoting the bin where the item should be placed, and Size is
% an integer >= 0 denoting its size.
% @param Bins *list of term* Bins is a list of terms of the form
% `bin(ID,Cap)` where ID is an integer
% identifying the bin, and Cap is an integer argument denoting is
% its capacity. The ID values should be all different.
% The constraint holds if every Bin equals one of the ID
% values, and for every bin `bin(ID,Cap)`, the total
% size of the items assigned to it equals Cap.
% Corresponds to `bin_packing*` in MiniZinc.

%! geost(+Objects,+Shapes)
%! geost(+Objects,+Shapes,+Options)
%! geost(+Objects,+Shapes,+Options,+Rules)
%
% constrains the location in space of non-overlapping multi-dimensional
% Objects, each of which taking a shape among a set of Shapes.
%
% Each shape is defined as a finite set of *shifted boxes*, where each
% shifted box is described by a box in a k-dimensional space at the
% given offset with the given sizes. A shifted box is described by a
% ground term `sbox(Sid,Offset,Size)` where
% Sid, an integer, is the shape id; Offset, a list of k
% integers, denotes the offset of the shifted box from the origin of the
% object; and Size, a list of k integers greater than zero,
% denotes the size of the shifted box. Then, a *shape* is a
% collection of shifted boxes all sharing the same shape id. The shifted
% boxes associated with a given shape must not overlap.
% @param Objects *list of term* Each object is described by a term
% `object(Oid,Sid,Origin` where Oid, an
% integer, is the unique object id; Sid, an integer argument, is the
% shape id; and Origin, a list of integer arguments, is the origin
% coordinate of the object. If Sid is nonground, then the object is said
% to be *polymorphic*. The possible values for Sid are the shape
% ids that occur in Shapes. Objects is thus the list of such
% `object/3` terms.
% @param Shapes *list of term* Shapes is thus the list of `sbox/3` terms.
% @param Options *list of term* If given, then Options is a list of zero or more of the following,
% where Boolean must be `true` or `false` (`false` is
% the default):
% `lex(ListOfOid)` where ListOfOid should be a list of distinct object ids, denotes
% that the origin vectors of the objects according to ListOfOid
% should be in ascending lexicographic order. Multiple `lex/1`
% options can be given, but should mention disjoint sets of objects.
% `cumulative(Boolean)` If `true`, then redundant reasoning methods are enabled, based on
% projecting the objects onto each dimension.
% `disjunctive(Boolean)` If `true`, then cliques of objects are detected that clash in one
% dimension and so must be separated in the other dimension. This method
% only applies in the 2D case.
% `longest_hole(Value,Maxbacks)` This method only applies in the 2D case and in the absence of
% polymorphic objects. Value can be `all`, `true` or
% `false`. If `true`, then the filtering algorithm computes and uses
% information about holes that can be tolerated without necessarily
% failing the constraint. If `all`,then more precise information is
% computed. If `false`, then no such information is computed.
% Maxbacks should be an integer `>= -1` and gives a bound on
% the effort spent tightening the longest hole information. Experiments
% suggest that 1000 may be a reasonable compromise value.
% `parconflict(Boolean)` If `true`, then redundant reasoning methods are enabled, based on
% computing the number of items that can be put in parallel in the
% different dimensions.
% `visavis_init(Boolean)` If `true`, then a redundant method is enabled that statically detects
% placements that would cause too large holes. This method can be quite
% effective.
% `visavis_floating(Boolean)` Disabled, because it has not been shown to pay off experimentally except in rare cases.
% `visavis(Boolean)` Disabled, because it has not been shown to pay off experimentally.
% `corners(Boolean)` Disabled, because it has not been shown to pay off experimentally.
% `task_intervals(Boolean)` Disabled, because it has not been shown to pay off experimentally.
% `dynamic_programming(Boolean)` If `true`, then a redundant reasoning method is enabled that solves a 2D
% knapsack problem for every two adjacent columns of the projection of the
% objects onto each dimension. This method has pseudo-polynomial
% complexity but can be quite powerful.
% `polymorphism(Boolean)` Disabled, because it has not been shown to pay off experimentally.
% `pallet_loading(Boolean)` If `true`, and if all objects consist of a single shifted box of
% the same shape, modulo rotations, then a redundant method is enabled that
% recognizes necessary conditions for this special case.
% `overlap(Boolean)` If `true`, then the constraint that objects be non-overlapping is
% lifted. This option is useful mainly in conjunction with the
% Rules argument, in case the placement of objects should be
% restricted by the Rules only.
% `volume(Total)` If given, then Total is constrained to be the total volume of
% Objects.
% `bounding_box(Lower,Upper)` Lower=[L1,...,Lk] and Upper=[U1,...,Uk] should be lists of
% integer arguments. The following conditions are imposed:
% * For every point P = [P1,...,Pk] occupied by an object,
% L1 <= P1 < U1, ..., Lk <= Pk < Uk.
% * For every j in 1..k,
% there exists a point P = [P1,...,Pj,...,Pk] occupied by an object
% such that Pj=Lj.
% * For every j in 1..k,
% there exists a point P = [P1,...,Pj,...,Pk] occupied by an object
% such that Pj=Uj-1.
% `fixall(Flag,Patterns)` If given, then Flag is an integer argument in `0..1`. If Flag
% equals 1, then either initially or by binding Flag during search, the
% constraint switches behavior into greedy assignment mode. The greedy
% assignment will either succeed and assign all shape ids and origin
% coordinates to values that satisfy the constraint, or merely fail.
% Flag is never bound by the constraint; its sole function is to
% control the behavior of the constraint.
% Greedy assignment is done one object at a time, in the order of
% Objects. The assignment per object is controlled by
% Patterns, which should be a list of one or more pattern terms of
% the form `object(_,SidSpec,OriginSpec)`, where SidSpec is a
% term `min(I)` or `max(I)`, OriginSpec is a
% list of k such terms, and I is a unique integer between 1
% and k+1.
% The meaning of the pattern is as follows. The argument in the position
% of `min(1)` or `max(1)` is fixed first; the argument in the
% position of `min(2)` or `max(2)` is fixed second; and so on.
% `min(I)` means trying values in ascending order;
% `max(I)` means descending order.
% If Patterns contains m pattern, then object 1 is fixed
% according to pattern 1, ..., object m is fixed according to
% pattern m, object m+1 is fixed according to pattern 1, and
% so on. For example, suppose that the following option is given:
% ```
% fixall(F, [object(_,min(1),[min(3),max(2)]),
%            object(_,max(1),[min(2),max(3)])])
% ```
% Then, if the program binds `F` to 1, then the constraint enters greedy
% assignment mode and endeavors to fix all objects as follows.
% * For object 1, 3, ..., (a) the shape is fixed to the smallest
% possible value, (b) the Y coordinate is fixed to the largest possible
% value, (c) the X coordinate is fixed to the smallest possible value.
% * For object 2, 4, ..., (a) the shape is fixed to the largest possible
% value, (b) the X coordinate is fixed to the smallest possible value, (c)
% the Y coordinate is fixed to the largest possible value.
% @param Rules *list of term* If given, then Rules is a list of zero or more terms of the form shown
% below, and impose extra constraints on the placement of the objects.
% For the time being, the details are described in [Carlsson, Beldiceanu &
% Martin 08]. **Please note:** the rules require that all shapes of
% a polymorphic objects consist of the same number of shifted boxes. For
% example, `Shapes =
% [sbox(1,[0,0],[3,1]),sbox(1,[0,1],[2,4]),sbox(2,[0,0],[3,1])]` will not
% work.
% Example of `geost/2` modeling three non-overlapping objects:
% ```prolog
% ?- domain([X1,X2,X3,Y1,Y2,Y3], 1, 4),
%      S1 in 1..4,
%      S2 in 5..6,
%      S3 in 7..8,
%      geost([object(1,S1,[X1,Y1]),
%             object(2,S2,[X2,Y2]),
%             object(3,S3,[X3,Y3])],
%             [sbox(1,[0,0],[2,1]),
%             sbox(1,[0,1],[1,2]),
%             sbox(1,[1,2],[3,1]),
%             sbox(2,[0,0],[3,1]),
%             sbox(2,[0,1],[1,3]),
%             sbox(2,[2,1],[1,1]),
%             sbox(3,[0,0],[2,1]),
%             sbox(3,[1,1],[1,2]),
%             sbox(3,[-2,2],[3,1]),
%             sbox(4,[0,0],[3,1]),
%             sbox(4,[0,1],[1,1]),
%             sbox(4,[2,1],[1,3]),
%             sbox(5,[0,0],[2,1]),
%             sbox(5,[1,1],[1,1]),
%             sbox(5,[0,2],[2,1]),
%             sbox(6,[0,0],[3,1]),
%             sbox(6,[0,1],[1,1]),
%             sbox(6,[2,1],[1,1]),
%             sbox(7,[0,0],[3,2]),
%             sbox(8,[0,0],[2,3])]).
% ```
% Example of encoding in Rules "objects with
% oid 1, 2 and 3 must all be at least 2 units apart from objects with oid
% 4, 5 and 6":
% ```prolog
% [ (origin(O1,S1,D) ---> O1^x(D)+S1^t(D)),
%
%   (end(O1,S1,D) ---> O1^x(D)+S1^t(D)+S1^l(D)),
%
%   (tooclose(O1,O2,S1,S2,D) --->
%       end(O1,S1,D)+2 #> origin(O2,S2,D) #/\
%       end(O2,S2,D)+2 #> origin(O1,S1,D)),
%
%   (apart(O1,O2) --->
%       forall(S1,sboxes([O1^sid]),
%           forall(S2,sboxes([O2^sid]),
%               #\ tooclose(O1,O2,S1,S2,1) #\/
%               #\ tooclose(O1,O2,S1,S2,2)))),
%
%   (forall(O1,objects([1,2,3]),
%       forall(O2,objects([4,5,6]), apart(O1,O2))))].
% ```
% Example of encoding in Rules "objects 3 and
% 7 model rooms that must be adjacent and have a common border at least 1
% unit long":
% ```prolog
% [ (origin(O1,S1,D) ---> O1^x(D)+S1^t(D)),
%
%   (end(O1,S1,D) ---> O1^x(D)+S1^t(D)+S1^l(D)),
%
%   (overlap(O1,S1,O2,S2,D) --->
%       end(O1,S1,D) #> origin(O2,S2,D) #/\
%       end(O2,S2,D) #> origin(O1,S1,D)),
%
%   (abut(O1,O2) --->
%       forall(S1,sboxes([O1^sid]),
%           forall(S2,sboxes([O2^sid]),
%               ((origin(O1,S1,1) #= end(O2,S2,1) #\/
%                 origin(O2,S2,1) #= end(O1,S1,1)) #/\
%                overlap(O1,S1,O2,S2,2)) #\/
%               ((origin(O1,S1,2) #= end(O2,S2,2) #\/
%                 origin(O2,S2,2) #= end(O1,S1,2)) #/\
%                overlap(O1,S1,O2,S2,1))))),
%
%   (forall(O1,objects([3]),
%       forall(O2,objects([7]), abut(O1,O2))))].
% ```

%! cumulative(+Tasks)
%! cumulative(+Tasks,+Options)
%
% This constraint ensures that the total resource consumption of n tasks does not exceed a given limit at any time.
% A task is represented by a term task(Oi,Di,Ei,Hi,Ti) where Oi is the start time, Di the non-negative duration, Ei the end time, Hi the non-negative resource consumption, and Ti the task identifier. All fields are integer arguments with bounded domains.
% Let n be the number of tasks and L the global resource limit (by default 1).
%
% The constraint holds if:
% 1. For every task i, Oi+Di=Ei.
% 2. For all instants j, H1j+...+Hnj <= L, where:
%    Hij = Hi, if Oi <= j < Oi+Di
%    Hij = 0 otherwise
%
% Corresponds to `cumulative` in MiniZinc.
% If all durations are 1, then it corresponds to `bin_packing` in MiniZinc.
%
% Options is a list of zero or more of the following:
% * `limit(L)`: The global resource limit.
% * `precedences(Ps)`: Ps encodes a set of precedence constraints to apply to the tasks. Ps should be a list of terms of the form `Ti-Tj #= Dij`, where Ti and Tj should be task identifiers, and Dij should be an integer argument, denoting `Oi-Oj = Dij`.
% * `global(Boolean)`: If `true`, then a more expensive algorithm will be used in order to achieve tighter pruning of the bounds of the parameters.
%
% This constraint is due to Aggoun and Beldiceanu [Aggoun & Beldiceanu 93].
%
% @param Tasks *list of task(Oi,Di,Ei,Hi,Ti)*
% @param Options *list of term*

%! cumulatives(+Tasks,+Machines)
%! cumulatives(+Tasks,+Machines,+Options)
%
% This constraint models a set of machines and a set of tasks that should be assigned to the machines.
% The machines have a resource limit and the tasks each have a resource usage that can be either positive, negative, or zero. The constraint is enforced over each point in time for a machine where there is at least one task assigned. The limit for a machine is either the maximum amount available at any given time (`bound(upper)`), or else the least amount to be used (`bound(lower)`).
%
% A task is represented by a term `task(O,D,E,H,M)` where O is the start time, D the non-negative duration, E the end time, H the resource consumption (if positive) or production (if negative), and M a machine identifier. All fields are integer arguments with bounded domains.
%
% A machine is represented by a term `machine(M,L)` where M is the identifier, an integer; and L is the resource bound of the machine, which must be an integer argument with bounded domains.
%
% Options is a list of zero or more of the following:
% * `bound(lower)`: (default) Each resource limit is treated as a lower bound.
% * `bound(upper)`: Each resource limit is treated as an upper bound.
% * `generalization(Boolean)`: If `true`, then extra reasoning based on assumptions on machine assignment will be done to infer more.
% * `task_intervals(Boolean)`: If `true`, then extra global reasoning will be performed in an attempt to infer more.
%
% This constraint is due to Beldiceanu and Carlsson [Beldiceanu and Carlsson 02].
%
% @param Tasks *list of task(O,D,E,H,M)*
% @param Machines *list of machine(M,L)*
% @param Options *list of term*

%! multi_cumulative(+Tasks,+Capacities)
%! multi_cumulative(+Tasks,+Capacities,+Options)
%
% This constraint is a generalization of `cumulative/[1,2]`. It deals with the consumption of multiple resources simultaneously. For the constraint to succeed, none of the resources can exceed its limit.
% Resources can be of two kinds:
% * `cumulative`: At no point in time can the total resource use exceed the limit.
% * `colored`: For this kind of resource, each task specifies not a resource use, but a color, encoded as an integer. At no point in time can the total number of distinct colors in use exceed the limit. The color code 0 is treated specially: it denotes that the task does not have any color.
%
% This constraint has the limitation that all fields and parameters except start and end times must be given as integers.
%
% A task is represented by a term `task(Oi,Di,Ei,Hsi,Ti)` where Oi is the start time, Di the non-negative duration, Ei the end time, Hsi the list of non-negative resource uses or colors, and Ti the task identifier. The start and end times should be integer arguments with bounded domains. The other fields should be integers.
%
% The capacities should be a list of terms of the following form, where Limit should be a non-negative integer. Capacities and all the Hsi should be of the same length:
% * `cumulative(Limit)`: denotes a cumulative resource.
% * `colored(Limit)`: denotes a colored resource.
%
% Options is a list of zero or more of the following:
% * `greedy(Flag)`: If given, then Flag is an integer argument in `0..1`. If Flag equals 1, either initially or by binding Flag during search, then the constraint switches behavior into greedy assignment mode. The greedy assignment will either succeed and assign all start and end times to values that satisfy the constraint, or merely fail. Flag is never bound by the constraint; its sole function is to control the behavior of the constraint.
% * `precedences(Ps)`: Ps encodes a set of precedence constraints to apply to the tasks. Ps should be a list of pairs `Ti-Tj` where Ti and Tj should be task identifiers, denoting that task Ti must complete before task Tj can start.
%
% This constraint is due to [Letort, Beldiceanu & Carlsson 14].
%
% @param Tasks *list of task(Oi,Di,Ei,Hsi,Ti)*
% @param Capacities *list of cumulative(Limit) or colored(Limit)*
% @param Options *list of term*

%! automaton(?Signature, ?SourcesSinks, ?Arcs)
%
% This constraint provides a general way of defining any constraint involving sequences
% whose checker can be expressed by a finite automaton, deterministic or nondeterministic,
% extended with counter operations on its arcs. In the absence of counters, it maintains domain consistency.
% Corresponds to `regular*` in MiniZinc.
%
% @param Signature *list of variable* The signature of the sequence.
% @param SourcesSinks *list of nodespec* The source and sink nodes of the automaton.
% @param Arcs *list of arc* The arcs (transitions) of the automaton.


%! automaton(?Sequence, ?Template, ?Signature, ?SourcesSinks, ?Arcs, ?Counters, ?Initial, ?Final)
%
% This constraint provides a general way of defining any constraint involving sequences
% whose checker can be expressed by a finite automaton, deterministic or nondeterministic,
% extended with counter operations on its arcs. In the absence of counters, it maintains domain consistency.
%
% @param Sequence *list of term* The sequence of terms of interest.
% @param Template *term* A template for an item of the sequence.
% @param Signature *list of variable* The signature of the sequence.
% @param SourcesSinks *list of nodespec* The source and sink nodes of the automaton.
% @param Arcs *list of arc* The arcs (transitions) of the automaton.
% @param Counters *list of variable* A list of counter variables, local to the constraint.
% @param Initial *list of intarg* A list of initial values for the counters.
% @param Final *list of intarg* A list of final values for the counters.


%! automaton(?Sequence, ?Template, ?Signature, ?SourcesSinks, ?Arcs, ?Counters, ?Initial, ?Final, ?Options)
%
% This constraint provides a general way of defining any constraint involving sequences
% whose checker can be expressed by a finite automaton, deterministic or nondeterministic,
% extended with counter operations on its arcs. In the absence of counters, it maintains domain consistency.
%
% @param Sequence *list of term* The sequence of terms of interest.
% @param Template *term* A template for an item of the sequence.
% @param Signature *list of variable* The signature of the sequence.
% @param SourcesSinks *list of nodespec* The source and sink nodes of the automaton.
% @param Arcs *list of arc* The arcs (transitions) of the automaton.
% @param Counters *list of variable* A list of counter variables, local to the constraint.
% @param Initial *list of intarg* A list of initial values for the counters.
% @param Final *list of intarg* A list of final values for the counters.
% @param Options *list of term* A list of zero or more options.

%! inflexion(?N, ?Vars, ?Opt)
%
% Holds if Vars is a list of integer arguments, and N is the number of times that
% the sequence order switches between strictly increasing and strictly decreasing.
% For example, the sequence `[1,1,4,8,8,2,7,1]` switches order three times.
%
% @param N *intarg* The number of inflexions.
% @param Vars *list of integer* The sequence of integers.
% @param Opt *list of term* Options for the automaton constraint.
%
% ``` 
% inflexion(N, Vars, Opt) :-
%         inflexion_signature(Vars, Sign),
%         automaton(Sign, _, Sign,
%                   [source(s),sink(i),sink(j),sink(s)],
%                   [arc(s,1,s      ),
%                    arc(s,2,i      ),
%                    arc(s,0,j      ),
%                    arc(i,1,i      ),
%                    arc(i,2,i      ),
%                    arc(i,0,j,[C+1]),
%                    arc(j,1,j      ),
%                    arc(j,0,j      ),
%                    arc(j,2,i,[C+1])],
%                   [C],[0],[N],Opt).
% ```

%! inflexion_signature(?L, ?Sign)
%
% Maps a sequence of integers L to a signature Sign where the consecutive element
% order is encoded over the alphabet `[0,1,2]`.
%
% @param L *list of integer* The input sequence of integers.
% @param Sign *list of integer* The signature representing the order between consecutive elements.
%
%``` 
% inflexion_signature([], []).
% inflexion_signature([_], []) :- !.
% inflexion_signature([X,Y|Ys], [S|Ss]) :-
%         S in 0..2,
%         X #> Y #<=> S #= 0,
%         X #= Y #<=> S #= 1,
%         X #< Y #<=> S #= 2,
%         inflexion_signature([Y|Ys], Ss).
%``` 

%! regular(?Signature, ?RegularExpression)
%
% Holds if Signature forms a sequence of values that is recognized by the regular expression.
% Maintains domain consistency.
%
% @param Signature *list of integer* A list of integer arguments.
% @param RegularExpression *term* A ground Prolog term describing the regular expression.
%
% Examples:
% ```prolog
% ?- length(L, 4), regular(L, [+({1,2}), +(0), +({1,2})]),
%      labeling([], L).
% L = [1,0,0,1] ? ;
% L = [1,0,0,2] ? ;
% L = [1,0,1,1] ? ;
% L = [1,0,1,2] ? ;
% L = [1,0,2,1] ? ;
% L = [1,0,2,2] ? ;
% L = [1,1,0,1] ? ;
% L = [1,1,0,2] ? ;
% L = [1,2,0,1] ? ;
% L = [1,2,0,2] ? ;
% L = [2,0,0,1] ? ;
% L = [2,0,0,2] ? ;
% L = [2,0,1,1] ? ;
% L = [2,0,1,2] ? ;
% L = [2,0,2,1] ? ;
% L = [2,0,2,2] ? ;
% L = [2,1,0,1] ? ;
% L = [2,1,0,2] ? ;
% L = [2,2,0,1] ? ;
% L = [2,2,0,2] ? ;
%
% ```

%! value_precede_chain(+Values, +Vars)
%
% Holds if for all adjacent pairs v,w in Values,
% either w does not occur in Vars, or v occurs earlier than w in Vars.
%
% @param Values *list of integer* A list of integers.
% @param Vars *list of integer* A list of integer arguments.

%! value_precede_chain(+Values, +Vars, +Options)
%
% Holds if for all adjacent pairs v,w in Values,
% either w does not occur in Vars, or v occurs earlier than w in Vars.
%
% @param Values *list of integer* A list of integers.
% @param Vars *list of integer* A list of integer arguments.
% @param Options *list of term* Options for the constraint, e.g., `global(Boolean)`.

%! seq_precede_chain(+Vars)
%
% The same as `value_precede_chain`, for Values = `[1,2,...]`.
%
% @param Vars *list of integer* A list of integer arguments.

%! seq_precede_chain(+Vars, +Options)
%
% The same as `value_precede_chain`, for Values = `[1,2,...]`.
%
% @param Vars *list of integer* A list of integer arguments.
% @param Options *list of term* Options for the constraint, e.g., `global(Boolean)`.

%! fd_statistics
%! fd_statistics(?Key, ?Value)
%
% This allows a program to access execution statistics specific to this solver.
% General statistics about CPU time and memory consumption etc. is available
% from the built-in predicate `statistics/2`.
%
% Without arguments, displays on the standard error stream a summary of the
% following statistics, and zeroes all counters. With arguments, for each of
% the possible keys Key, Value is unified with the current value of a counter,
% which is simultaneously zeroed. The following counters are maintained:
%
% * `propagations` since release 4.10.0: The number of times a constraint was resumed.
% * `entailments`: The number of times a (dis)entailment was detected by a constraint.
% * `prunings`: The number of times a domain was pruned.
% * `backtracks`: The number of times the search has backtracked to an alternative branch.
% * `restarts` since release 4.10.0: The number of times the search has restarted from scratch.
% * `solutions` since release 4.10.0: The number of times the search has found an intermediate (for optimization problems) or final (for satisfaction problems) solution.
% * `optimalities` since release 4.10.0: The number of times the search has proven optimality (for optimization problems) or found all solutions (for satisfaction problems).
% * `propagators` since release 4.10.0: The number of propagators created.
% * `variables` since release 4.10.0: The number of domain variables created.
%
% @param Key atom
% @param Value number
