#### 10\.9\.8 Enumeration Predicates



`indomain(?X)   polymorphic`



where X is a numeric argument with finite bounds. Assigns via
backtracking a feasible value to X. For integer arguments, the
values are assigned in increasing order.




`labeling(:Options, +Variables)   polymorphic`



where Variables is a list of numeric arguments with finite bounds and Options is
a list of search options. True if an assignment of the arguments can be found, which
satisfies the posted constraints.




`first_bound(+BB0, -BB)`
`later_bound(+BB0, -BB)`





Provides an auxiliary service for the `value(Enum)` option
(see below).




`minimize(:Goal,?X)`
`minimize(:Goal,?X,+Options)   since release 4.3`
`maximize(:Goal,?X)`
`maximize(:Goal,?X,+Options)   since release 4.3`





Uses a restart algorithm to find an assignment that minimizes
(maximizes) the integer variable X. Goal should be a Prolog
goal that constrains X to become assigned, and could be a
`labeling/2` goal. The algorithm calls Goal repeatedly with
a progressively tighter upper (lower) bound on X until a proof of
optimality is obtained.



Whether to enumerate every solution that improves the objective
function, or only the optimal one after optimality has been proved, is
controlled by Options. If given, then it whould be a list containing a
single atomic value, one of:




`best   since release 4.3`


Return the optimal solution after proving its optimality.
This is the default.




`all   since release 4.3`


Enumerate all improving solutions, on backtracking seek the next
improving solution. Merely fail after proving optimality.






The Options argument of `labeling/2` controls the order in
which variables are selected for assignment (variable choice heuristic),
the way in which choices are made for the selected variable (value
choice heuristic), whether the problem is a satisfaction one or an
optimization one, and whether all solutions or only the optimal one
should be returned. The options are divided into 11 groups. At most one
option may be selected per group, and each group has a default choice.



#### Option Group 1—Variable Choice


The following mutually exclusive options control the order in which the next variable is
selected for assignment. In all cases, ties are broken by selecting
the leftmost variable.




`leftmost`


`input_order`

The leftmost variable is selected. This is the default.




`min`


`smallest`

The variable with the smallest lower bound is selected.




`max`


`largest`

The variable with the greatest upper bound is selected.




`ff`


`first_fail`

The first\-fail principle is used: the variable with the smallest
domain is selected.




`anti_first_fail   since release 4.3`

The variable with the largest domain is selected.




`occurrence   since release 4.3`

The variable that has the most constraints suspended on it is
selected. **Please note**: the mapping from constraints to
propagators is subject to change from release to release, and after
entailment, it is undefined whether a propagator is
counted. Consequently, the behavior of `occurrence` may change
from release to release.




`ffc`


`most_constrained`

The most constrained heuristic is used: a variable with the smallest
domain is selected, breaking ties by selecting the variable that has
the most propagators suspended on it.
**Please note**: the same caveat applies as for `occurrence`.




`max_regret   since release 4.3`

The variable with the largest difference between its first two domain elements is selected.
Not supported for real variables.




`impact   since release 4.7.0`

The variable that has been involved in the most failures is selected.
Not supported for real variables.




`dom_w_deg   since release 4.7.0`

The variable is selected that maximizes the quantity failure count
divided by domain size.
Not supported for real variables.




`variable(Sel)`

Sel is a predicate to select the next variable. Given Vars,
the variables that remain to label, it will be called as
Sel(Vars,Selected,Rest).



Sel is expected to succeed determinately, unifying Selected
and Rest with the selected variable and the remaining list,
respectively.



Sel should be a callable term, optionally with a module prefix,
and the arguments Vars, Selected, Rest will be
appended to it. For example, if Sel is `mod:sel(Param)`,
then it will be called as `mod:sel(Param,Vars,Selected,Rest)`.




#### Option Group 2—Value Choice


The following mutually exclusive options control the way in which
choices are made for the selected variable X. For real
variables, the default is an undefined order that could change from
release to release and only the value/1 option is supported.




`step`

Makes a binary choice between `X #= B` and
`X #\= B`, where B is the lower or upper bound of
X. This is the default for integer variables. Not supported for real variables.




`enum`

Makes an n\-ary choice for X corresponding to the values in its
domain. Not supported for real variables.




`bisect`

Makes a binary choice between `X #=< M` and
`X #> M`, where M is the middle of the domain of
X, i.e., the mean of `min(X)` and `max(X)`
rounded down to the nearest integer. This strategy is also known as
domain splitting. Not supported for real variables.




`interval   since release 4.10.0`

Makes a binary choice between `X #=< M` and
`X #> M`, where M is:


* the max of the first interval, if the domain of
X consists of multiple intervals
* as for `bisect` otherwise.


Not supported for real variables.




`value(Enum)`

Enum is a predicate that should prune the domain of X,
possibly but not necessarily to a singleton. It will be called as
Enum(X,Rest,BB0,BB) where Rest is the list of variables that
need labeling except X, and BB0 and BB are parameters
described below.







Enum is expected to succeed nondeterminately, pruning the domain
of X, and to backtrack one or more times, providing alternative
prunings. To ensure that branch\-and\-bound search works correctly, it
must call the auxiliary predicate `first_bound(BB0,BB)`
in its first solution. Similarly, it must call the auxiliary predicate
`later_bound(BB0,BB)` in any alternative solution.



Enum should be a callable term, optionally with a module prefix,
and the arguments X,Rest,BB0,BB will be appended to it. For
example, if Enum is `mod:enum(Param)`, then it will be called as
`mod:enum(Param,X,Rest,BB0,BB)`.




#### Option Group 3—Value Order


The following mutually exclusive options control the order in which the choices are made
for the selected variable X. They have no effect if combined with `value/1`.




`up`

The domain is explored in ascending order. This is the default.
Useful with `enum`, `step` `bisect`, and with real
variables.




`down`

The domain is explored in descending order. Useful with `enum`,
`step` `bisect`, and with real variables.




`median   since release 4.3`

Makes a binary choice between `X #= M` and
`X #\= M`, where M is the median of the domain
of X. If the domain has an even number of elements, then the
smaller middle value is used. Useful with the `step` option.
Not supported for real variables.




`middle   since release 4.3`

Makes a binary choice between `X #= M` and
`X #\= M`, where M is the middle of the domain
of X, i.e., the mean of `min(X)` and
`max(X)` rounded down to the nearest integer. Useful with
the `step` option. Not supported for real variables.




`random   since release 4.10.0`

Makes a binary choice between `X #= R` and
`X #\= R`, where R is a random member of the
domain of X. Useful with the `step` option and with real
variables. The random number generator seed can be set and obtained
with `fd_setrand/1` and `fd_getrand/1`.




#### Option Group 4—Branch Order


The following mutually exclusive options control the order in which
the alternatives are explored for binary and n\-ary choices. They have
no effect if combined with `value/1`.




`in   since release 4.10.0`

The alternatives are explored in the order described for Groups 2 and
3\. This is the default.




`out   since release 4.10.0`

The alternatives are explored in the reverse order of that described
for Groups 2 and 3\.




#### Option Group 5—Precision


When exploring alternatives for real variables, the number of float
values contained in the domain is typically huge. It is usually a good
idea to explore only a sample of them. The granularity of the sample
is problem specific. If it it too coarse, solutions can be missed. If
it is too fine, spurious, closely clustered solutions may be reported
due to accumulated rounding errors that prevent those spurious
solutions from being ruled out. The following parameter controls the
granularity:




`precision(P)   since release 4.10.0`

When exploring the alternatives for X, if its domain has been
narrowed to A..B and A\+P \>\= B, then only one candidate
domain element will be tried. Otherwise, the domain will be
split and explored recursively. P should be a non\-negative float.
The default is 0\.0, but the value of the `precision` FD flag
overrides P if it is greater than P.





#### Option Group 6—Objective


The following options tell the solver whether the given problem is a
satisfaction problem or an optimization problem. In a satisfaction
problem, we wish to find values for the domain variables, all
solutions being equally good. In an optimization problem, we wish to
find values that minimize or maximize some objective function
reflected in an integer variable. It is useful to combine the
optimization options with the `time_out/2`, `best`, and
`all` options (see later). If these options occur more than
once, then the last occurrence overrides previous ones.




`satisfy   since release 4.3`

We have a satisfication problem. Its solutions are enumerated by
backtracking. This is the default.




`minimize(X)`
`maximize(X)`


We have an optimization problem, seeking an assignment where the value
of the integer variable X is minimal (maximal). The labeling
should fix X for all assignments of Variables.




`lex_minimize(Xs)   since release 4.10.0`
`lex_maximize(Xs)   since release 4.10.0`


Similar to `minimize` and `maximize`, but the objective is
not a single integer variable, but a vector of them to minimize or
maximize lexicographically.




`pareto_minimize(Xs)   since release 4.10.0`
`pareto_maximize(Xs)   since release 4.10.0`


Similar to `lex_minimize` and `lex_maximize`, but here we
are looking not for a single, optimal solution, but for a set of
solutions such that no solution is dominated by another
solution. Suppose that Xs is assigned to As resp. Bs
in solutions 1 resp. 2\. For `pareto_minimize`, solution 1 is
dominated by solution 2 iff As\[i] \>\= Bs\[i] for every position
i. For `pareto_maximize`, solution 1 is dominated by
solution 2 iff As\[i] \=\< Bs\[i] for every position i. The
non\-dominated solutions are enumerated by backtracking.




#### Option Group 7—Optimization Incrementality


The following options are only meaningful for optimization problems.
They tell the solver whether to enumerate every solution that improves
the objective function, or only the optimal one after optimality has
been proved:




`best   since release 4.3`

Return the optimal solution after proving its optimality.
This is the default.




`all   since release 4.3`

Enumerate all improving solutions, on backtracking seek the next
improving solution. Merely fail after proving optimality. This
option is not very useful for `pareto_minimize` and
`pareto_maximize`, because an improving solution may later become
dominated during search.




#### Option Group 8—Optimization Strategy


The following options too are only meaningful for optimization problems.
They tell the solver what search scheme to use, but have no effect on
the semantics or on the meaning of other options:




`bab   since release 4.3`

Use a branch\-and\-bound scheme, which incrementally tightens the bound on
the objective as more and more solutions are found.
This is the default, and is usually the more efficient scheme.




`restart   since release 4.3`

Use a scheme that restarts the search with a tighter bound on the
objective each time a solution is found.




#### Option Group 9—Restart


Depth\-first search suffers from the problem that wrong decisions made
at the top of the search tree can take an exponential amount of search
to undo. One common way to mitigate this problem is to restart the
search from scratch, thus having a chance to make better decisions.
Of course, this only makes sense if the decisions have a chance to be
different, e.g., using the `random` option. The following
options are meaningful for satisfaction as well as optimization
problems. Restarts occur when a backtrack cutoff limit is reached
after the latest (re)start. The default is no cutoff limit:




`restart_constant(Scale)   since release 4.10.0`

The cutoff limit is fixed to Scale.




`restart_linear(Scale)   since release 4.10.0`

The cutoff limit is fixed to Scale\*k after the k\-th (re)start.
Scale should be an integer.




`restart_geometric(Base, Scale)   since release 4.10.0`

The cutoff limit is fixed to Scale\*(Base^k) after the k\-th (re)start.
Scale should be an integer and Base should be a float.




`restart_luby(Scale)   since release 4.10.0`

The cutoff limit is fixed to Scale\*L\[k] after the k\-th
(re)start, where L\[k] is the k\-th number in the Luby
sequence. The Luby sequence looks like:





```
1 1 2 1 1 2 4 1 1 2 1 1 2 4 8, ...

```

e.g., it repeats two copies of the sequence ending in 2^i before
adding the number 2^(i\+1\). Scale should be an integer.




#### Option Group 10—Large Neighborhood Search


Restarting search can be made more effective by using a fragment of
the latest found solution as a warm start each time. With the
following options, upon restart, for each variable to label, it is
fixed to the previous solution with a given
probability. **Please note**: this strategy makes the search
procedure unable to exhaust the search space, so the search
effectively goes on forever, or until the execution time limit has
been exceeded. This strategy is meningful mainly for optimization
problems with the `all` option:




`relax_and_reconstruct(Xs, P)   since release 4.10.0`
`relax_and_reconstruct(Xs, P, Ys)   since release 4.10.0`


Upon restart, for each variable to label, it is fixed to the previous
solution with probability P/100. If Ys is given, then use
that as an initial solution until the first solution has been found.




#### Option Group 11—Time\-Out


Finally, a limit on the execution time can be imposed:




`time_out(Time,Flag)`

See [lib\-timeout](lib_002dtimeout.html).
Time should be an integer number of milliseconds.
The default is no time limit.
If the search space is exhausted within this time limit and no solution is found,
then the search merely fails, as usual.
Otherwise, Flag is bound to a value reflecting the outcome:




`optimality   since release 4.4`

If `best` was selected in an optimization problem, then the
search space was exhausted, having found the optimal solution. The
variables are bound to the corresponding values. If `best` was
not selected, this flag value is not used.




`success   since release 4.4`

If `best` was selected in an optimization problem, then the
search timed out before the search space was exhausted, having found
at least one solution. If `best` was not selected, then a
solution was simply found before the time limit. In any case, the
variables are bound to the values corresponding to the latest solution
found.




`time_out   since release 4.4`

If `best` was selected in an optimization problem, then the
search timed out before any solution was found. If
`best` was not selected, then the search timed out while
searching for the next solution. The variables are left unbound.






For example, to enumerate solutions using a static variable
ordering, use:





```
| ?- constraints(Variables),
     labeling([], Variables).
     %same as [leftmost,step,up,satisfy]

```

To minimize a cost function using branch\-and\-bound search, computing the
best solution only, with a dynamic variable ordering using the
first\-fail principle, and domain splitting exploring the upper part of
domains first, use:





```
| ?- constraints(Variables, Cost),
     labeling([ff,bisect,down,minimize(Cost)], Variables).

```

To give a time budget and collect the solutions of a satisfiability problem
up to the time limit, use:





```
| ?- constraints(Variables),
     findall(Variables, labeling([time_out(Budget,success)|Options]), Solutions).

```

where `Flag=success` will hold if all solutions were found, and
`Flag=time_out` will hold if the time expired.



Note that, when used for optimization, `labeling/2` has a
limitation compared to `minimize/[2,3]` and `maximize/[2,3]`:
the variable and value choice heuristics specified by `labeling/2`
must apply to the whole set of variables, with no provision for
different heuristics for different subsets. As of release 4\.3, this
limitation has been lifted by the following predicate:




`solve(:Options, :Searches)   since release 4.3,polymorphic`



where Options is a list of options of the same shape as taken by
`labeling/2`, and Searches is a list of `labeling/2` and
`indomain/1` goals, or a single such goal. The domain variables of
Searches must all have finite bounds. True if the conjunction
of Searches is true.



The main purpose of this predicate is for optimization, allowing to
use different heuristics in the different Searches.
For satisfiability problems, a simple sequence of `labeling/2` and
`indomain/1` goals does the trick.



The treatment of the Options, as well as the suboption lists given
in the `labeling/2` goals of Searches, is a bit special.
Some options are global for the whole search, and are ignored if they
occur in the suboption lists. Others are local to the given
`labeling/2` goal, but provides a default value for the whole
search if it occurs in Options. The following table defines the
role of each option as `global` or `local`:





| `all` | `global` |
| --- | --- |
| `anti_first_fail` | `local` |
| `bab` | `global` |
| `best` | `global` |
| `bisect` | `local` |
| `dom_w_deg` | `local` |
| `down` | `local` |
| `enum` | `local` |
| `ffc` | `local` |
| `ff` | `local` |
| `first_fail` | `local` |
| `impact` | `local` |
| `in` | `local` |
| `input_order` | `local` |
| `interval` | `local` |
| `largest` | `local` |
| `leftmost` | `local` |
| `lex_maximize/1` | `global` |
| `lex_minimize/1` | `global` |
| `max_regret` | `local` |
| `maximize/1` | `global` |
| `max` | `local` |
| `median` | `local` |
| `middle` | `local` |
| `minimize/1` | `global` |
| `min` | `local` |
| `most_constrained` | `local` |
| `occurrence` | `local` |
| `out` | `local` |
| `pareto_maximize/1` | `global` |
| `pareto_minimize/1` | `global` |
| `precision` | `local` |
| `random` | `local` |
| `relax_and_reconstruct/2` | `global` |
| `relax_and_reconstruct/3` | `global` |
| `restart` | `global` |
| `restart_constant/1` | `global` |
| `restart_geometric/2` | `global` |
| `restart_linear/1` | `global` |
| `restart_luby/1` | `global` |
| `satisfy` | `global` |
| `smallest` | `local` |
| `step` | `local` |
| `time_out/2` | `global` |
| `up` | `local` |
| `value/1` | `local` |
| `variable/1` | `local` |




For example, suppose that you want to minimize a cost function using
branch\-and\-bound search, enumerating every improving solution, using
left\-to\-right search on some variables followed by first\-fail domain
splitting search on some other variables. This can be expressed as:





```
| ?- constraints([X1,X2,X3,Y1,Y2,Y3], Cost),
     solve([minimize(Cost),all],
           [labeling([leftmost],[X1,X2,X3]),
            labeling([ff,bisect],[Y1,Y2,Y3])]).

```