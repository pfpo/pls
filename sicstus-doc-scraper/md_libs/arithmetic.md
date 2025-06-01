
#### 10\.9\.7\.1 Arithmetic Constraints


#### Arithmetic Relations



`?IExpr #= ?IExpr   reifiable`
`?IExpr #\= ?IExpr   reifiable`
`?IExpr #< ?IExpr   reifiable`
`?IExpr #=< ?IExpr   reifiable`
`?IExpr #> ?IExpr   reifiable`
`?IExpr #>= ?IExpr   reifiable`
`?RExpr $= ?RExpr   reifiable`
`?RExpr $=< ?RExpr   reifiable`
`?RExpr $>= ?RExpr   reifiable`


defines an arithmetic relation. The syntax for IExpr and
RExpr is defined by a grammar (see [Syntax of Integer Expressions](Syntax-of-Integer-Expressions.html); see [Syntax of Real Expressions](Syntax-of-Real-Expressions.html)). Note that the
expressions are not restricted to being linear. Constraints over
nonlinear expressions, however, will usually yield less constraint
propagation than constraints over linear expressions.



Several examples of arithmetic relations over reals can be found at [Equation Solving](Equation-Solving.html).



Arithmetic relations can be reified as e.g.:





```
| ?- X in 1..2, Y in 3..5, X#=<Y #<=> B.
B = 1,
X in 1..2,
Y in 3..5

| ?- X in 1.0..2.0, Y in 3.0..5.0, X$=<Y #<=> B.
B = 1,
X in 1.0..2.0,
Y in 3.0..5.0

| ?- X in 1.0..3.0, X $>= 2.0 #<=> B, indomain(B).
B = 0,
X in 1.0..2.0 ? ;
B = 1,
X in 2.0..3.0 ? ;
no

```



Linear integer relations, except equalities, maintain bounds
consistency. All other relations endeavor to maintain bounds
consistency.



#### Partiality and Undefined Values


Some arithmetic functions are partial, i.e., they do not have a
defined value for all combinations of arguments. The partial integer
functions are:




`X / Y`
`X // Y`
`X div Y`
`X mod Y`
`X rem Y`
for `Y #= 0`



`X ^ Y`
for `Y #< 0` if `abs(X) #\= 1`. Note that this differs from
the MiniZinc semantics. In MiniZinc, `X ^ Y` \= `1 div (X ^
-Y)` if `Y < 0`. In SICStus, the CLPFD value is equal to the
Prolog value if the latter is defined and integer.



`if_then_else(X,Y,Z)`
for `X` not in `0..1`




The partial real functions are:




`X^Y`
for `X $=< 0.0` if `Y` is not integral.




`if_then_else(X,Y,Z)`
for `X` not in `0..1`.




`sqrt(X)`
`log(X)`
for `X $=< 0.0`.




`asin(X)`
`acos(X)`
`atanh(X)`
for `X` not in `-1.0 .. 1.0`.




`acosh(X)`
for `X $=< 1.0`.




`acoth(X)`
for `X` in `-1.0 .. 1.0`.




Like MiniZinc, SICStus implements the *relational semantics* of
partial functions. Quoting \[MiniZincHandbook], “any undefinedness
bubbles up to the closest Boolean context and becomes `false`
there”. Here, a Boolean context is simply an arithmetic relation. A
few examples illustrate how this works:





```
| ?- Y in -1 .. 1, 10 div Y #= Z, indomain(Y).
Y = -1, Z = -10 ? ;
Y = 1, Z = 10 ? ;

```

Here, the division by zero silently made the `#=` constraint fail.





```
| ?- Y in 0..1, 10 div Y #= 10 #<=> B, indomain(Y).
Y = 0, B = 0 ? ;
Y = 1, B = 1 ? ;

```

Here, the division by zero again made the `#=` constraint fail,
reflected in the answer `B = 0`.





```
| ?- Y in -1 .. 1, Z #= if_then_else(1, 2, 10 div Y), indomain(Y).
Y = -1, Z = 2 ? ;
Y = 1, Z = 2 ? ;

```

Here, the division by zero “bubbled up” through the if\-then\-else
expression, making `#=` fail for `Y = 0`, even though
`if_then_else/3` actually did not use its third argument.





```
| ?- X in 1..2, Y in -1 .. 1, X ^ Y #= Z, indomain(X), indomain(Y).
X = 1, Y = -1, Z = 1 ? ;
X = 1, Y = 0, Z = 1 ? ;
X = 1, Y = 1, Z = 1 ? ;
X = 2, Y = 0, Z = 1 ? ;
X = 2, Y = 1, Z = 2 ? ;

```

Here, `2 ^ -1 #= Z` failed, because `2 ^ -1` is undefined.



#### Other Arithmetic Constraints


The following constraints are among the library constraints that general
arithmetic constraints compile to. They express a relation between a
sum or a scalar product and a value, using a dedicated algorithm, which
avoids creating any temporary variables holding intermediate values. If
you are computing a sum or a scalar product, then it can be much more
efficient to compute lists of coefficients and variables and post a
single sum or scalar product constraint than to post a sequence of
elementary constraints.




`sum(+Xs, +IRelOp, ?Value)`



where Xs is a list of integer arguments, IRelOp is a
relational symbol as above, and Value is an integer argument.
True if `sum(Xs) IRelOp Value`. Corresponds
roughly to `sumlist/2` in `library(lists)`.




`scalar_product(+Coeffs, +Xs, +IRelOp, ?Value)   reifiable`
`scalar_product(+Coeffs, +Xs, +IRelOp, ?Value, +Options)   reifiable`



where Coeffs is a list of length n of integers, Xs is
a list of length n of integer arguments, IRelOp is
a relational symbol as above, and Value is an integer argument.
True if `sum(Coeffs*Xs) IRelOp Value`.



Options is a list that may include the following options:




`among(Least,Most,Range)   obsolescent`

If given, then Least and Most should be integers and Range
should be an IntegerRange (see [Syntax of Range Expressions](Syntax-of-Range-Expressions.html)). This
option imposes the additional constraint on Xs that at least
Least and at most Most elements belong to Range.




`consistency(Cons)`

This can be used to control the level of consistency used by the constraint.
The value is one of the following:



`domain`

The constraint maintains domain consistency.
**Please note**: This option is only meaningful if IRelOp is
`#=`, and requires that all integer arguments have finite bounds.



`bounds`
`value`


The constraint tries to maintain bounds consistency (the default).
Note that the same algorithm is used also if `Cons = value`.







`scalar_product_reif(+Coeffs, +Xs, +IRelOp, ?Value, ?Reif)   since release 4.5`
`scalar_product_reif(+Coeffs, +Xs, +IRelOp, ?Value, ?Reif, +Options)`



is the reified version of `scalar_product/[4,5]`, i.e.,
Reif is 1 if `scalar_product/[4,5]` with the same arguments
holds; otherwise, Reif is 0\.




The following constraints constrain a numeric argument to be the
minimum (maximum) value of a given list.




`minimum(?Value, +Xs)   polymorphic`



where Xs is a list of numeric arguments, and Value is a numeric argument.
True if Value is the minimum of Xs. Corresponds to
`min_member/2` in `library(lists)` and to `minimum` in
MiniZinc.




`maximum(?Value, +Xs)   polymorphic`



where Xs is a list of numeric arguments, and Value is a numeric argument.
True if Value is the maximum of Xs. Corresponds to
`max_member/2` in `library(lists)` and to `maximum` in
MiniZinc.




The following constraints constrain an integer argument to be the
index of the minimum (maximum) value of a given list. They maintain
domain consistency.




`minimum_arg(+Xs, ?Index)   since release 4.6`



where Xs is a list of integer arguments, and Index is an
integer argument. True if Index is the index of the minimum
value of Xs, counting from 1\. If that value occurs more than
once, Index is the index of the first occurrence. Corresponds
to `arg_min` and `minimum_arg` in MiniZinc.




`maximum_arg(+Xs, ?Index)   since release 4.6`



where Xs is a list of integer arguments, and Index is an
integer argument. True if Index is the index of the maximum
value of Xs, counting from 1\. If that value occurs more than
once, Index is the index of the first occurrence. Corresponds
to `arg_max` and `maximum_arg` in MiniZinc.




The following constrain restricts a numeric argument to take the value of
either of two other numeric arguments, depending on a Boolean argument. It
maintains domain consistency.




`if_then_else(If, Then, Else, Value)   polymorphic,since release 4.8.0`



True if If\=1 and Value\=Then, or If\=0 and Value\=Else.
If should be an integer argument with domain contained in `0..1`.
Then, Else, and Value should be numeric arguments, either both integer or both real.
Corresponds to if\-then\-else expressions in most programming and modeling languages.
