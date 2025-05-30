
`domain(+Variables, +Range)   polymorphic,since release 4.10.0`



where Variables is a list of variables. True if the variables
all are elements of Range.



`domain/2` can be used for integer variables as well as for real
variables.
For integer variables, Range should be an IntegerRange;
For real variables, Range should be a RealRange.
See [Syntax of Range Expressions](Syntax-of-Range-Expressions.html).




`domain(+Variables, +Min, +Max)   polymorphic`



where Variables is a list of variables. True if the variables
all are elements of the range `Min..Max`.
`domain/3` can be used for integer variables as well as for real
variables. For integer variables, Min is an integer or the atom
`inf` (minus infinity), and Max is an integer or the atom
`sup` (plus infinity). For real variables, Min is a real
or the atom `finf` (minus infinity), and Max is a real or
the atom `fsup` (plus infinity).




`?X in +Range   reifiable,polymorphic`



where X is a domain variable.
`in/2` can be used for integer variables as well as for real
variables.
True if X is an element of the range.
For integer variables, Range should be an IntegerRange;
For real variables, Range should be a RealRange.
See [Syntax of Range Expressions](Syntax-of-Range-Expressions.html).




`?X in_set +FDSet   reifiable`



where X is an integer variable and
FDSet is an FD set (see [FD Set Operations](FD-Set-Operations.html)). True if X
is an element of the FD set.




`in/2` and `in_set/2` constraints maintain domain consistency
and their reified versions detect domain entailment and disentailment.


10.9.7.3
Predicate 10.9.7.3, not stored



Next: [Arithmetic\-Logical Constraints](Arithmetic_002dLogical-Constraints.html), Previous: [Membership Constraints](Membership-Constraints.html), Up: [Available Constraints](Available-Constraints.html)   \[[Contents](index.html#SEC_Contents "Table of contents")]\[[Index](Predicate-Index.html "Index")]





---


#### 10\.9\.7\.3 Propositional Constraints


Propositional combinators can be used to combine reifiable constraints
into propositional formulae over such constraints. Such formulae are
goal expanded by the system into sequences of reified constraints and
arithmetic constraints. For example,





```
X #= 4 #\/ Y #= 6

```

expresses the disjunction of two equality constraints.



The leaves of propositional formulae can be reifiable constraints or
Boolean arguments. New reifiable constraints can be
defined with indexicals as described in [Defining Indexical Constraints](Defining-Indexical-Constraints.html). The following propositional combinators are available:




`#\ :Q   reifiable`



True if the constraint Q is false.




`:P #/\ :Q   reifiable`



True if the constraints P and Q are both true.




`:P #\ :Q   reifiable`



True if exactly one of the constraints P and Q is true.




`:P #\/ :Q   reifiable`



True if at least one of the constraints P and Q is true.




`:P #=> :Q   reifiable`
`:Q #<= :P   reifiable`





True if the constraint Q is true or the constraint P is false.




`:P #<=> :Q   reifiable`



True if the constraints P and Q are both true or both false.
