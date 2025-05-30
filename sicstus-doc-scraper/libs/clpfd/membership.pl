
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
