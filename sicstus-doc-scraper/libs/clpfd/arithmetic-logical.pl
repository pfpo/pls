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
