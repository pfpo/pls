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
