
#### 4\.7\.5 Arithmetic Expressions




Arithmetic evaluation and testing is performed by predicates that take
arithmetic expressions as arguments. An *arithmetic expression*
is a term built from numbers, variables, and functors that represent
arithmetic functions. These expressions are evaluated to yield an
arithmetic result, which may be either an integer or a float; the type
is determined by the rules described below.



At the time of evaluation, each variable in an arithmetic expression
must be bound to a number or another arithmetic expression. If the
expression is not sufficiently bound or if it is bound to terms of the
wrong type, then Prolog raises exceptions of the appropriate type (see
[ref\-ere\-hex](ref_002dere_002dhex.html)). Some arithmetic operations can also detect
overflows. They also raise exceptions, e.g. division by zero
results in an evaluation error being raised.





Only certain functors are permitted in arithmetic expressions. These
are listed below, together with a description of their arithmetic
meanings. For the rest of the section, X and Y are
considered to be arithmetic expressions. Unless stated otherwise, the arguments of an
expression may be any numbers and its value is a float if any of its
arguments is a float; otherwise, the value is an integer. Any
implicit coercions are performed with the `integer/1` and
`float/1` functions. All trigonometric and
transcendental functions take float arguments and deliver float
values. The trigonometric functions take arguments or deliver
values in radians.



Integers can for all practical purposes be considered to be of infinite size.
Negative integers can be considered to be infinitely sign extended.



The arithmetic functors are annotated with *ISO*, with the same
meaning as for the built\-in predicates; see [ISO Compliance](ISO-Compliance.html).




`+X   ISO`

The value is X.




`-X   ISO`

The value is the negative of X.




`X+Y   ISO`

The value is the sum of X and Y.




`X-Y   ISO`

The value is the difference between X and Y.




`X*Y   ISO`

The value is the product of X and Y.




`X/Y   ISO`

The value is the *float* quotient of X and Y.




`X//Y   ISO`

The value is the *integer* quotient of X and Y,
 truncated towards zero.
 X and Y have to be integers.




`X div Y   since release 4.3, ISO`

The value is the *integer* quotient of X and Y,
 rounded downwards to the nearest integer.
 X and Y have to be integers.




`X rem Y   ISO`

The value is the *integer* remainder after truncated division
 of X by Y, i.e.
 `X-Y*(X//Y)`. 
 The sign of a nonzero remainder will thus be the same as that of the
 dividend. X and Y have to be integers.




`X mod Y   ISO`

The value is the *integer* remainder after floored division
 of X by Y, i.e. `X-Y*(X div
 Y)`.
 The sign of a nonzero remainder will thus be the same as that of
 the divisor. X and Y have to be integers.




`integer(X)`

The value is the closest integer between X and 0,
 if X is a float; otherwise, X itself.




`float_integer_part(X)   ISO`

The same as `float(integer(X))`. 
 X has to be a float.




`float_fractional_part(X)   ISO`

The value is the fractional part of X, i.e.
 `X - float_integer_part(X)`.



X has to be a float.



`float(X)   ISO`

The value is the float equivalent of X, if X is an
 integer; otherwise, X itself.




`X/\Y   ISO`

The value is the bitwise conjunction of the integers X and Y.
 X and Y have to be integers, treating negative integers as
 infinitely sign extended.




`X\/Y   ISO`

The value is the bitwise disjunction of the integers X and Y.
 X and Y have to be integers, treating negative integers as
 infinitely sign extended.




`xor(X,Y)   since release 4.3, ISO`

The value is the bitwise exclusive or of the integers X and Y.
 X and Y have to be integers, treating negative integers as
 infinitely sign extended.




`X\Y`

The same as `xor(X,Y)`.



`\(X)   ISO`

The value is the bitwise negation of the integer X. X has
 to be an integer, treating negative integers as infinitely sign
 extended.




`X<<Y   ISO`

The value is the integer X shifted arithmetically left by Y places.
 i.e. filling with a copy of the sign bit.
 X and Y have to be integers, and Y can be negative, in
 which case the shift is right.




`X>>Y   ISO`

The value is the integer X shifted arithmetically right by Y places,
 i.e. filling with a copy of the sign bit.
 X and Y have to be integers, and Y can be negative, in
 which case the shift is left.




`[X]`

A list of just one number X evaluates to X. Since a
 quoted string is just a list of integers, this allows a
 quoted character to be used in place of its character code; e.g.
 `"A"` behaves within arithmetic expressions as the integer 65\.




`abs(X)   ISO`

The value is the absolute value of X.




`sign(X)   ISO`

The value is the sign of X, i.e. \-1, if X is negative, 0, if
 X is zero, and 1, if X is positive, coerced into the same
 type as X (i.e. the result is an integer, if and only if X is an
 integer).




`gcd(X,Y)`

The value is the greatest common divisor of the two integers X
 and Y.
 X and Y have to be integers.



`min(X,Y)   ISO`

The value is the lesser value of X and Y.




`max(X,Y)   ISO`

The value is the greater value of X and Y.




`msb(X)`

The value is the position of the most significant nonzero bit of the integer X,
 counting bit positions from zero.
 It is equivalent to, but more efficient than, `integer(log(2,X))`.
 X must be greater than zero, and
 X has to be an integer.




`round(X)   ISO`

The value is the closest integer to X. If X is exactly
 half\-way between two integers, then it is rounded up (i.e. the value is the
 least integer greater than X).




`truncate(X)   ISO`

The value is the closest integer between X and 0\.




`floor(X)   ISO`

The value is the greatest integer less or equal to
 X.




`ceiling(X)   ISO`

The value is the least integer greater or equal to
 X.




`sin(X)   ISO`

The value is the sine of X.




`cos(X)   ISO`

The value is the cosine of X.




`tan(X)   ISO`

The value is the tangent of X.




`cot(X)`

The value is the cotangent of X.




`sinh(X)`

The value is the hyperbolic sine of X.




`cosh(X)`

The value is the hyperbolic cosine of X.




`tanh(X)`

The value is the hyperbolic tangent of X.




`coth(X)`

The value is the hyperbolic cotangent of X.




`asin(X)   ISO`

The value is the arc sine of X.



`acos(X)   ISO`

The value is the arc cosine of X.




`atan(X)   ISO`

The value is the arc tangent of X.




`atan2(X,Y)   ISO`

The value is the four\-quadrant arc tangent of X and Y.




`acot(X)`

The value is the arc cotangent of X.




`acot2(X,Y)`

The value is atan2(Y,X).




`asinh(X)`

The value is the hyperbolic arc sine of X.




`acosh(X)`

The value is the hyperbolic arc cosine of X.




`atanh(X)`

The value is the hyperbolic arc tangent of X.




`acoth(X)`

The value is the hyperbolic arc cotangent of X.




`sqrt(X)   ISO`

The value is the square root of X.




`log(X)   ISO`

The value is the natural logarithm of X.




`log(Base,X)`

The value is the logarithm of X in the base Base.




`exp(X)   ISO`

The value is the natural exponent of X.




`X ** Y   ISO`

The value is X raised to the power of Y, represented as a float.
 In particular, the value of `0.0 ** 0.0` is `1.0`.




`exp(X,Y)`

The same as `X ** Y`.




`X ^ Y   since release 4.3, ISO`

The value is X raised to the power of Y, represented as a float
 if any of X and Y is a float; otherwise, as an integer.
 In particular, the value of `0^0` is `1`.




`pi   since release 4.3, ISO`

The value is approximately 3\.14159\.






The following operation is included in order to allow integer arithmetic on
character codes.








`[X]`
Evaluates to X for numeric X. This is
relevant because character strings in Prolog are lists of character
codes, that is, integers. Thus, for those integers that correspond
to character codes, the user can write a string of one character in
place of that integer in an arithmetic expression. For example, the
expression (A) is equivalent to (B), which in turn becomes (C) in
which case X is unified with 2:





```
X is "c" - "a"  (A)

```



```
X is [99] - [97]  (B)

```



```
X is 99 - 97  (C)

```

A cleaner way to do the same thing is 




```
X is 0'c - 0'a

```
