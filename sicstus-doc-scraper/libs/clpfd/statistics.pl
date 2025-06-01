%! fd_statistics
%! fd_statistics(?Key, ?Value)
%
% This allows a program to access execution statistics specific to this solver.
% General statistics about CPU time and memory consumption etc. is available
% from the built-in predicate `statistics/2`.
%
% Without arguments, displays on the standard error stream a summary of the
% following statistics, and zeroes all counters. With arguments, for each of
% the possible keys Key, Value is unified with the current value of a counter,
% which is simultaneously zeroed. The following counters are maintained:
%
% * `propagations` since release 4.10.0: The number of times a constraint was resumed.
% * `entailments`: The number of times a (dis)entailment was detected by a constraint.
% * `prunings`: The number of times a domain was pruned.
% * `backtracks`: The number of times the search has backtracked to an alternative branch.
% * `restarts` since release 4.10.0: The number of times the search has restarted from scratch.
% * `solutions` since release 4.10.0: The number of times the search has found an intermediate (for optimization problems) or final (for satisfaction problems) solution.
% * `optimalities` since release 4.10.0: The number of times the search has proven optimality (for optimization problems) or found all solutions (for satisfaction problems).
% * `propagators` since release 4.10.0: The number of propagators created.
% * `variables` since release 4.10.0: The number of domain variables created.
%
% @param Key atom
% @param Value number
