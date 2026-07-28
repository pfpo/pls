
### 10\.6 Generating Integers—`library(between)`


This library module provides some means of generating integers.
Exported predicates:




`between(+Lower, +Upper, -Number)`



is true when Lower, Upper, and Number are integers,
and Lower \=\< Number \=\< Upper. If Lower and Upper are given,
Number can be tested or enumerated. If either Lower or Upper
is absent, there is not enough information to find it, and an
error will be reported.



`gen_nat(?N)`



is true when N is a natural number. If N is a variable, it will
enumerate the natural numbers 0,1,2,... and of course not terminate.
It is not meant to be applied to anything but integers and variables.



`gen_int(?I)`



is true when I is an integer. If I is a variable, it will
enumerate the integers in the order 0, 1, \-1, 2, \-2, 3, \-3, \&c.
Of course this sequence has no end.
It is not meant to be applied to anything but integers and variables.



`repeat(+N)`



(where N is a non\-negative integer) succeeds exactly N times.
You can only understand it procedurally, and really it is only
included for compatibility with some other Prologs.



`numlist(?Upper, ?List)`



is true when List is the list of integers \[1, ..., Upper].
For example, `numlist(3,L)` binds `L = [1,2,3]`.



`numlist(?Lower, ?Upper, ?List)`
is true when List is \[Lower, ..., Upper], Lower and Upper integers.
For example, `numlist(1, 3, L)` binds `L = [1,2,3]`.



`numlist(?Lower, ?Step, ?Upper, ?Length, ?List)`
is true when List is the list of integers \[Lower, Lower\+Step, ..., Upper] and
of length Length.
For example, `numlist(Lower,2,Upper,Length,[1,X,Y,Z])` binds
`Lower=1, Upper=7, Length=4, X=3, Y=5, Z=7`.


