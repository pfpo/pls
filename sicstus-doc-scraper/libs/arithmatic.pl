%! + +X
%
% The value is X.
%
% @param X The arithmetic expression.

%! - +X
%
% The value is the negative of X.
%
% @param X The arithmetic expression.

%! +X + +Y
%
% The value is the sum of X and Y.
%
% @param X The first arithmetic expression.
% @param Y The second arithmetic expression.

%! +X - +Y
%
% The value is the difference between X and Y.
%
% @param X The first arithmetic expression.
% @param Y The second arithmetic expression.

%! +X * +Y
%
% The value is the product of X and Y.
%
% @param X The first arithmetic expression.
% @param Y The second arithmetic expression.

%! +X / +Y
%
% The value is the *float* quotient of X and Y.
%
% @param X The first arithmetic expression.
% @param Y The second arithmetic expression.

%! +X // +Y
%
% The value is the *integer* quotient of X and Y, truncated towards zero.
% X and Y have to be integers.
%
% @param X The first integer arithmetic expression.
% @param Y The second integer arithmetic expression.

%! +X div +Y
%
% The value is the *integer* quotient of X and Y, rounded downwards to the nearest integer.
% X and Y have to be integers.
%
% @param X The first integer arithmetic expression.
% @param Y The second integer arithmetic expression.

%! +X rem +Y
%
% The value is the *integer* remainder after truncated division of X by Y, i.e. `X - Y * (X // Y)`.
% The sign of a nonzero remainder will thus be the same as that of the dividend. X and Y have to be integers.
%
% @param X The first integer arithmetic expression (dividend).
% @param Y The second integer arithmetic expression (divisor).

%! +X mod +Y
%
% The value is the *integer* remainder after floored division of X by Y, i.e. `X - Y * (X div Y)`.
% The sign of a nonzero remainder will thus be the same as that of the divisor. X and Y have to be integers.
%
% @param X The first integer arithmetic expression (dividend).
% @param Y The second integer arithmetic expression (divisor).

%! integer(+X)
%
% The value is the closest integer between X and 0, if X is a float; otherwise, X itself.
%
% @param X The arithmetic expression.

%! float_integer_part(+X)
%
% The same as `float(integer(X))`. X has to be a float.
%
% @param X The float arithmetic expression.

%! float_fractional_part(+X)
%
% The value is the fractional part of X, i.e. `X - float_integer_part(X)`.
% X has to be a float.
%
% @param X The float arithmetic expression.

%! float(+X)
%
% The value is the float equivalent of X, if X is an integer; otherwise, X itself.
%
% @param X The arithmetic expression.

%! +X /\ +Y
%
% The value is the bitwise conjunction of the integers X and Y.
% X and Y have to be integers, treating negative integers as infinitely sign extended.
%
% @param X The first integer.
% @param Y The second integer.

%! +X \/ +Y
%
% The value is the bitwise disjunction of the integers X and Y.
% X and Y have to be integers, treating negative integers as infinitely sign extended.
%
% @param X The first integer.
% @param Y The second integer.

%! xor(+X,+Y)
%
% The value is the bitwise exclusive or of the integers X and Y.
% X and Y have to be integers, treating negative integers as infinitely sign extended.
%
% @param X The first integer.
% @param Y The second integer.

%! +X \ +Y
%
% The same as `xor(X,Y)`.
%
% @param X The first integer.
% @param Y The second integer.

%! \(+X)
%
% The value is the bitwise negation of the integer X. X has to be an integer, treating negative integers as infinitely sign extended.
%
% @param X The integer.

%! +X << +Y
%
% The value is the integer X shifted arithmetically left by Y places, i.e. filling with a copy of the sign bit.
% X and Y have to be integers, and Y can be negative, in which case the shift is right.
%
% @param X The integer to be shifted.
% @param Y The number of places to shift.

%! +X >> +Y
%
% The value is the integer X shifted arithmetically right by Y places, i.e. filling with a copy of the sign bit.
% X and Y have to be integers, and Y can be negative, in which case the shift is left.
%
% @param X The integer to be shifted.
% @param Y The number of places to shift.


% TODO:

%! [X]
%
% A list of just one number X evaluates to X. Since a quoted string is just a list of integers, this allows a quoted character to be used in place of its character code; e.g. `"A"` behaves within arithmetic expressions as the integer 65.
% Evaluates to X for numeric X. This is relevant because character strings in Prolog are lists of character codes, that is, integers. Thus, for those integers that correspond to character codes, the user can write a string of one character in place of that integer in an arithmetic expression. For example, the expression (A) is equivalent to (B), which in turn becomes (C) in which case X is unified with 2:
%
% ```
% X is "c" - "a"  (A)
% ```
% ```
% X is [99] - [97]  (B)
% ```
% ```
% X is 99 - 97  (C)
% ```
% A cleaner way to do the same thing is
% ```
% X is 0'c - 0'a
% ```
%
% @param X A number or a single-element list containing a number or a character code.

%! abs(+X)
%
% The value is the absolute value of X.
%
% @param X The arithmetic expression.

%! sign(+X)
%
% The value is the sign of X, i.e. -1, if X is negative, 0, if X is zero, and 1, if X is positive, coerced into the same type as X (i.e. the result is an integer, if and only if X is an integer).
%
% @param X The arithmetic expression.

%! gcd(+X,+Y)
%
% The value is the greatest common divisor of the two integers X and Y.
% X and Y have to be integers.
%
% @param X The first integer.
% @param Y The second integer.

%! min(+X,+Y)
%
% The value is the lesser value of X and Y.
%
% @param X The first arithmetic expression.
% @param Y The second arithmetic expression.

%! max(+X,+Y)
%
% The value is the greater value of X and Y.
%
% @param X The first arithmetic expression.
% @param Y The second arithmetic expression.

%! msb(+X)
%
% The value is the position of the most significant nonzero bit of the integer X, counting bit positions from zero.
% It is equivalent to, but more efficient than, `integer(log(2,X))`.
% X must be greater than zero, and X has to be an integer.
%
% @param X The integer.

%! round(+X)
%
% The value is the closest integer to X. If X is exactly half-way between two integers, then it is rounded up (i.e. the value is the least integer greater than X).
%
% @param X The arithmetic expression.

%! truncate(+X)
%
% The value is the closest integer between X and 0.
%
% @param X The arithmetic expression.

%! floor(+X)
%
% The value is the greatest integer less or equal to X.
%
% @param X The arithmetic expression.

%! ceiling(+X)
%
% The value is the least integer greater or equal to X.
%
% @param X The arithmetic expression.

%! sin(+X)
%
% The value is the sine of X.
%
% @param X The arithmetic expression (in radians).

%! cos(+X)
%
% The value is the cosine of X.
%
% @param X The arithmetic expression (in radians).

%! tan(+X)
%
% The value is the tangent of X.
%
% @param X The arithmetic expression (in radians).

%! cot(+X)
%
% The value is the cotangent of X.
%
% @param X The arithmetic expression (in radians).

%! sinh(+X)
%
% The value is the hyperbolic sine of X.
%
% @param X The arithmetic expression.

%! cosh(+X)
%
% The value is the hyperbolic cosine of X.
%
% @param X The arithmetic expression.

%! tanh(+X)
%
% The value is the hyperbolic tangent of X.
%
% @param X The arithmetic expression.

%! coth(+X)
%
% The value is the hyperbolic cotangent of X.
%
% @param X The arithmetic expression.

%! asin(+X)
%
% The value is the arc sine of X.
%
% @param X The arithmetic expression.

%! acos(+X)
%
% The value is the arc cosine of X.
%
% @param X The arithmetic expression.

%! atan(+X)
%
% The value is the arc tangent of X.
%
% @param X The arithmetic expression.

%! atan2(+X,+Y)
%
% The value is the four-quadrant arc tangent of X and Y.
%
% @param X The first arithmetic expression.
% @param Y The second arithmetic expression.

%! acot(+X)
%
% The value is the arc cotangent of X.
%
% @param X The arithmetic expression.

%! acot2(+X,+Y)
%
% The value is atan2(Y,X).
%
% @param X The first arithmetic expression.
% @param Y The second arithmetic expression.

%! asinh(+X)
%
% The value is the hyperbolic arc sine of X.
%
% @param X The arithmetic expression.

%! acosh(+X)
%
% The value is the hyperbolic arc cosine of X.
%
% @param X The arithmetic expression.

%! atanh(+X)
%
% The value is the hyperbolic arc tangent of X.
%
% @param X The arithmetic expression.

%! acoth(+X)
%
% The value is the hyperbolic arc cotangent of X.
%
% @param X The arithmetic expression.

%! sqrt(+X)
%
% The value is the square root of X.
%
% @param X The arithmetic expression.

%! log(+X)
%
% The value is the natural logarithm of X.
%
% @param X The arithmetic expression.

%! log(+Base,+X)
%
% The value is the logarithm of X in the base Base.
%
% @param Base The base of the logarithm.
% @param X The value for which to calculate the logarithm.

%! exp(+X)
%
% The value is the natural exponent of X.
%
% @param X The arithmetic expression.

%! +X ** +Y
%
% The value is X raised to the power of Y, represented as a float.
% In particular, the value of `0.0 ** 0.0` is `1.0`.
%
% @param X The base arithmetic expression.
% @param Y The exponent arithmetic expression.

%! exp(+X,+Y)
%
% The same as `X ** Y`.
%
% @param X The base arithmetic expression.
% @param Y The exponent arithmetic expression.

%! +X ^ +Y
%
% The value is X raised to the power of Y, represented as a float if any of X and Y is a float; otherwise, as an integer.
% In particular, the value of `0^0` is `1`.
%
% @param X The base arithmetic expression.
% @param Y The exponent arithmetic expression.

%! pi
%
% The value is approximately 3.14159.
