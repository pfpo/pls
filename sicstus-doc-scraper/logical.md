
#### 10\.9\.7\.4 Arithmetic\-Logical Constraints


`smt(:Body)   since release 4.2,deprecated`



The arithmetic, membership, and propositional constraints described
earlier are transformed at compile time to conjunctions of library
constraints. Although linear in the size of the source code, the
expansion of a propositional formula over reifiable constraints to
library goals can have time and memory overheads, and propagates
disjunctions very weakly. Temporary variables holding intermediate
values may have to be introduced, and the grain size of the constraint
solver invocations can be rather small. As an alternative to the
default propagation of such constraint formulas, this constraint is a
front\-end to the `case/[3,4]` propagator, which treats such a
formula globally.



Although often convenient, this constraint is deprecated, because it
cannot guarantee better performance than a decomposition, nor any
particular level of consistency.



Body should be a ConstraintBody term (see [Syntax of Indexicals](Syntax-of-Indexicals.html)).




`count(+Val,+List,+IRelOp,?Count)   since release 4.0.5`



where Val is an integer, List is a list of integer
arguments, Count an integer argument, and IRelOp is a
relational symbol as in [Arithmetic Constraints](Arithmetic-Constraints.html). True if N
is the number of occurrences of Val in List and N IRelOp
Count.



Corresponds to `count_*` and `exactly` in MiniZinc.



If you want to count how many times multiple values occur in the same list,
the following constraint is a better alternative.




`global_cardinality(+Xs,+Vals)`
`global_cardinality(+Xs,+Vals,+Options)`



where Xs \= \[X1,…,Xd] is a list of integer arguments,
and Vals \= \[K1\-V1,…,Kn\-Vn] is a list of pairs where
keys Ki are distinct integers and each Vi is a non\-negative integer argument.
True if every element of Xs is equal to some key and for each pair
Ki\-Vi, exactly Vi elements of Xs are equal to
Ki.



If either Xs or Vals is ground, and in many other special
cases, then `global_cardinality/[2,3]` maintains domain
consistency, but generally, domain or bounds consistency cannot be guaranteed.



Corresponds to `global_cardinality*` and `distribute` in MiniZinc.



Options is a list of zero or more of the following:




`consistency(Cons)`

Which filtering algorithm to use. One of the following:



`domain`
`bounds`


A domain\-consistency algorithm \[Regin 96] is used, roughly linear in
the total size of the domains. Note that the same algorithm is used
also if `Cons = bounds`.



`value`

The constraint will use a simple algorithm, which prevents too few or
too many of the Xs from taking values among the Vals.





`cost(Cost,Matrix)`

Cost is constrained to equal a cost computed as a function of
Xs and Matrix, which should be a d\*n matrix of
integers, represented as a list of d lists, each of length
n.
The cost of the i\-th arguments Xi is computed as follows.
Suppose that the j\-th pair of Vals is the pair Kj\-Vj where Kj \= Xi.
Then the cost of Xi is Matrix\[i,j].
The total cost Cost is the total cost of all arguments Xi.
With this option, a domain\-consistency algorithm \[Regin 99] is used.





`all_equal(+Arguments)   reifiable   since release 4.7`



where Arguments is a list of integer arguments. They are
constrained to take the same value.



Corresponds to `all_equal` in MiniZinc.




`all_equal_reif(+Arguments, ?Reif))   since release 4.7`



is the reified version of `all_equal/1`, i.e.,
Reif is 1 if `all_equal/1` with the same arguments
holds; otherwise, Reif is 0\.




`all_different(+Xs)`
`all_different(+Xs, +Options)`
`all_distinct(+Xs)`
`all_distinct(+Xs, +Options)`





where Xs is a list of integer arguments. Each argument is
constrained to take a value that is unique among the arguments.
Declaratively, this is equivalent to an inequality constraint for each
pair of arguments.



Corresponds to `all_different` in MiniZinc.



Options is a list of zero or more of the following:




`L #= R   obsolescent`


Let Y1, …, Yj be a subset of Xs.
R should be an integer.
L should be an expression of one of the following forms:



`Y1 + ... + Yj`
`Y1*Y1 + ... + Yj*Yj`
`Y1 * ... * Yj`

The given equation is a side constraint for the constraint to hold.
A special bounds\-consistency algorithm is used, which considers the main
constraint and the side constraints globally. This option is only valid
if the domains of Y1, …, Yj consist of integers strictly
greater than zero.




`consistency(Cons)`


Which algorithm to use. Cons can be one of the following:




`domain`


The default for `all_distinct/[1,2]` and `assignment/[2,3]`.
A domain\-consistency algorithm \[Regin 94] is used, roughly linear in
the total size of the domains.




`bounds`


A bounds\-consistency algorithm \[Lopez\-Ortiz 03] is used, which runs
in O(n log n) time for n arguments.




`value`


The default for `all_different/[1,2]`. An algorithm achieving
exactly the same pruning as a set of pairwise inequality constraints is
used, roughly linear in the number of arguments.





`circuit(Boolean)`


If `true`, then `circuit(Xs)` must hold for the
constraint to be true.




`subcircuit(Boolean)   since release 4.6`


If `true`, then `subcircuit(Xs)` must hold for the
constraint to be true.




`cost(Cost,Matrix)   since release 4.9.0`


Cost is constrained to equal a cost computed as a function of
Xs and Matrix, namely
Matrix\[1,X1]\+…\+Matrix\[n,Xn]. Matrix should be an
n\*m matrix of integers, represented as a list of lists.





`all_different_except_0(+Arguments)   since release 4.6`
`all_distinct_except_0(+Arguments)   since release 4.6`





where Arguments is a list of integer arguments with finite
bounds. The arguments are constrained to be all different, except
those elements that are assigned the value 0\.



In terms of consistency, `all_different_except_0/1` corresponds
to `all_different/1`, and `all_distinct_except_0/1` to
`all_distinct/1`.



Corresponds to `alldifferent_except_0` in MiniZinc.




`nvalue(?N, +Arguments)`



where Arguments is a list of integer arguments with finite bounds,
and N is an integer argument. True if N is the number of
distinct values taken by Arguments. Approximates
bounds consistency in N and domain consistency in Arguments.
Can be thought of as a relaxed version of `all_distinct/2`.



Corresponds to `nvalue` in MiniZinc.




The following is a constraint over two lists of integer arguments,
both of length n. Each argument is constrained to take a value
in 1\..n that is unique in its list. Furthermore, the lists are
dual in a sense described below.




`assignment(+Xs, +Ys)`
`assignment(+Xs, +Ys, +Options)`



where Xs \= \[X1,…,Xn] and Ys \=
\[Y1,…,Yn] are lists of integer arguments. True if all
Xi, Yi are in 1\..n and Xi\=j iff Yj\=i.



Corresponds to `inverse` in MiniZinc.



Options is a list of zero or more of the following, where
Boolean must be `true` or `false` (`false` is the
default):




`consistency(Cons)`

Same meaning as for `all_different/2`.




`circuit(Boolean)`

If `true`, then `circuit(Xs,Ys)` must hold for the
constraint to be true.




`subcircuit(Boolean)   since release 4.6`

If `true`, then `subcircuit(Xs,Ys)` must hold for the
constraint to be true.




`cost(Cost,Matrix)`

Cost is constrained to equal a cost computed as a function of
Xs and Matrix, namely
Matrix\[1,X1]\+…\+Matrix\[n,Xn]. Matrix should be an
n\*n matrix of integers, represented as a list of lists.






The following is a constraint over a list of length n of integer
arguments, all of which are constrained to 1\..n.




`symmetric_all_different(+Xs)   since release 4.6`
`symmetric_all_distinct(+Xs)   since release 4.6`





True if all elements of Xs \= \[X1,...,Xn] are in 1\..n, they
are all different, and for all i,j in 1\..n, Xi\=j iff
Xj\=i.



Corresponds to `symmetric_all_different` in MiniZinc.
`symmetric_all_distinct/1` maintains stronger consistency.




The following constraints correspond to `increasing`, `strictly_increasing`, 
`decreasing`, and `strictly_decreasing` in MiniZinc:




`increasing(+Xs)   since release 4.10.0`
`increasing(+Xs,+Options)   since release 4.10.0`



where Xs is a list of integer arguments.
Requires that Xs be in increasing order.




`decreasing(+Xs)   since release 4.10.0`
`decreasing(+Xs,+Options)   since release 4.10.0`



where Xs is a list of integer arguments.
Requires that Xs be in decreasing order.



Options is a list of zero or one options, where
Boolean must be `true` or `false`:




`strict(Boolean)`


If `false` (the default), then duplicates are allowed, otherwise they are not.






The following constraint captures the relation between a list of values,
a list of the values in ascending order, and their positions in the
original list:




`sorting(+Xs,+Ps,+Ys)`



where Xs \= \[X1,…,Xn], Ps \=
\[P1,…,Pn], and Ys \= \[Y1,…,Yn] are lists of
integer arguments. The constraint holds if the following are true:



* Ys is in ascending order.
* Ps is a permutation of 1\..n.
* for all i in 1\..n : Xi \= Y(Pi)


In practice, the underlying algorithm \[Mehlhorn 00] is likely to achieve
bounds consistency, and is guaranteed to do so if Ps is ground or
completely free.



Corresponds to `sort` in MiniZinc.




The following constraint is a generalization of `sorting/3`, namely:



* It sorts not variables, but variable tuples.
* The tuples are split into a key prefix and a value suffix. They are sorted
wrt. the key part only.
* The sort is stable: if two tuples have identical keys, then their relative
order is preserved in the output.



`keysorting(+Xs,+Ys)   since release 4.3.1`
`keysorting(+Xs,+Ys,+Options)`



where Xs and Ys are lists of tuples of integer arguments.
Both lists should be of the same length n, and each tuple,
represented by a list, should have the same length m. The first
k elements of a tuple serve as a key, where k equals
Keys as defined below in the options. Let Xs\[i,j] denote
the j\-th element of the tuple which appears as the i\-th
element of Xs (and similarly for Ys).



The constraint holds if the following are true:



* Ps is a permutation of 1\..n.
* for all i in 1\..n, j in 1\..m : Ys\[i,j] \= Xs\[Ps\[i],j].
* \[\[Ys\[i,1],...,Ys\[i,k],Ps\[i]] \| i in 1\..n] is in lex ascending
order.


The filtering algorithm is based on \[Mehlhorn 00] and endeavors to maintain
bounds consistency, but does not guarantee it.



Corresponds to Prolog’s `keysort/2`. In particular, the sort is stable by definition.
Corresponds to `arg_sort` in MiniZinc.



Options is a list of zero or more of the following:




`keys(Keys)`

where Keys should be a positive integer, denoting the length of
the key prefix. The default is 1\.




`permutation(Ps)`

where Ps should be a list of length n of integer arguments.
Its meaning is described above.






The following constraints express the fact that several vectors of
integer arguments are in ascending lexicographic order:




`lex_chain(+Vectors)`
`lex_chain(+Vectors,+Options)`



where Vectors is a list of vectors (lists) of integer arguments
with finite bounds. The constraint holds if Vectors are in
ascending lexicographic order.



Corresponds to `*lex2`, `lex_greater*`, `lex_less*` in MiniZinc.



Options is a list of zero or more of the following:




`op(Op)`

If Op is the atom `#=<` (the default), then the constraints holds
if Vectors are in non\-descending lexicographic order. If Op
is the atom `#<`, then the constraints holds if Vectors are in
strictly ascending lexicographic order.




`increasing   obsolescent`

This option imposes the additional constraint that each vector in
Vectors be sorted in strictly ascending order.




`among(Least,Most,Values)   obsolescent`

If given, then Least and Most should be integers such that 0
\<\= Least \<\= Most and Values should be a list of distinct
integers. This option imposes the additional constraint on each vector
in Vectors that at least Least and at most Most
elements belong to Values.




`global(Boolean)   since release 4.2.1`

if `true`, then a more expensive algorithm \[Carlsson \& Beldiceanu 02],
which guarantees domain consistency unless the `increasing/0` or
`among/3` options are given, will be used.






In the following constraints, a *literal* is either a term `X`
or a term `#\ X`, where `X` is a Boolean argument. They maintain
domain consistency:




`bool_and(+Lits, +Lit)   since release 4.3`



where Lits is a list of literals `[L0,...,Lj]` and Lit is a literal.
True if Lit equals the Boolean conjunction of Lits.
Usually more efficient than the equivalent `L0#/\...#/\Lj #<=> Lit`.




`bool_or(+Lits, +Lit)   since release 4.3`



where Lits is a list of literals `[L0,...,Lj]` and Lit is a literal.
True if Lit equals the Boolean disjunction of Lits.
Usually more efficient than the equivalent `L0#\/...#\/Lj #<=> Lit`.




`bool_xor(+Lits, +Lit)   since release 4.3`



where Lits is a list of literals `[L0,...,Lj]` and Lit is a literal.
True if Lit equals the Boolean exclusive or of Lits.
Usually more efficient than the equivalent `L0#\...#\Lj #<=> Lit`.




`bool_channel(+Lits, ?Y, +Relop, +Offset)   since release 4.3`



where Lits is a list of literals `[L0,...,Lj]`, Y is
an integer argument, IRelOp is an arithmetic comparison as in
[Syntax of Integer Expressions](Syntax-of-Integer-Expressions.html), and Offset is an
integer. Expresses the constraint Li \#\<\=\> (Y IRelOp i\+Offset)
for `i in 0..j`. Usually more efficient than a bunch of
reified comparisons between a given argument and a sequence of
integers.
