%! cumulative(+Tasks)
%! cumulative(+Tasks,+Options)
%
% This constraint ensures that the total resource consumption of n tasks does not exceed a given limit at any time.
% A task is represented by a term task(Oi,Di,Ei,Hi,Ti) where Oi is the start time, Di the non-negative duration, Ei the end time, Hi the non-negative resource consumption, and Ti the task identifier. All fields are integer arguments with bounded domains.
% Let n be the number of tasks and L the global resource limit (by default 1).
%
% The constraint holds if:
% 1. For every task i, Oi+Di=Ei.
% 2. For all instants j, H1j+...+Hnj <= L, where:
%    Hij = Hi, if Oi <= j < Oi+Di
%    Hij = 0 otherwise
%
% Corresponds to `cumulative` in MiniZinc.
% If all durations are 1, then it corresponds to `bin_packing` in MiniZinc.
%
% Options is a list of zero or more of the following:
% * `limit(L)`: The global resource limit.
% * `precedences(Ps)`: Ps encodes a set of precedence constraints to apply to the tasks. Ps should be a list of terms of the form `Ti-Tj #= Dij`, where Ti and Tj should be task identifiers, and Dij should be an integer argument, denoting `Oi-Oj = Dij`.
% * `global(Boolean)`: If `true`, then a more expensive algorithm will be used in order to achieve tighter pruning of the bounds of the parameters.
%
% This constraint is due to Aggoun and Beldiceanu [Aggoun & Beldiceanu 93].
%
% @param Tasks *list of task(Oi,Di,Ei,Hi,Ti)*
% @param Options *list of term*
%! cumulatives(+Tasks,+Machines)
%! cumulatives(+Tasks,+Machines,+Options)
%
% This constraint models a set of machines and a set of tasks that should be assigned to the machines.
% The machines have a resource limit and the tasks each have a resource usage that can be either positive, negative, or zero. The constraint is enforced over each point in time for a machine where there is at least one task assigned. The limit for a machine is either the maximum amount available at any given time (`bound(upper)`), or else the least amount to be used (`bound(lower)`).
%
% A task is represented by a term `task(O,D,E,H,M)` where O is the start time, D the non-negative duration, E the end time, H the resource consumption (if positive) or production (if negative), and M a machine identifier. All fields are integer arguments with bounded domains.
%
% A machine is represented by a term `machine(M,L)` where M is the identifier, an integer; and L is the resource bound of the machine, which must be an integer argument with bounded domains.
%
% Options is a list of zero or more of the following:
% * `bound(lower)`: (default) Each resource limit is treated as a lower bound.
% * `bound(upper)`: Each resource limit is treated as an upper bound.
% * `generalization(Boolean)`: If `true`, then extra reasoning based on assumptions on machine assignment will be done to infer more.
% * `task_intervals(Boolean)`: If `true`, then extra global reasoning will be performed in an attempt to infer more.
%
% This constraint is due to Beldiceanu and Carlsson [Beldiceanu and Carlsson 02].
%
% @param Tasks *list of task(O,D,E,H,M)*
% @param Machines *list of machine(M,L)*
% @param Options *list of term*
%! multi_cumulative(+Tasks,+Capacities)
%! multi_cumulative(+Tasks,+Capacities,+Options)
%
% This constraint is a generalization of `cumulative/[1,2]`. It deals with the consumption of multiple resources simultaneously. For the constraint to succeed, none of the resources can exceed its limit.
% Resources can be of two kinds:
% * `cumulative`: At no point in time can the total resource use exceed the limit.
% * `colored`: For this kind of resource, each task specifies not a resource use, but a color, encoded as an integer. At no point in time can the total number of distinct colors in use exceed the limit. The color code 0 is treated specially: it denotes that the task does not have any color.
%
% This constraint has the limitation that all fields and parameters except start and end times must be given as integers.
%
% A task is represented by a term `task(Oi,Di,Ei,Hsi,Ti)` where Oi is the start time, Di the non-negative duration, Ei the end time, Hsi the list of non-negative resource uses or colors, and Ti the task identifier. The start and end times should be integer arguments with bounded domains. The other fields should be integers.
%
% The capacities should be a list of terms of the following form, where Limit should be a non-negative integer. Capacities and all the Hsi should be of the same length:
% * `cumulative(Limit)`: denotes a cumulative resource.
% * `colored(Limit)`: denotes a colored resource.
%
% Options is a list of zero or more of the following:
% * `greedy(Flag)`: If given, then Flag is an integer argument in `0..1`. If Flag equals 1, either initially or by binding Flag during search, then the constraint switches behavior into greedy assignment mode. The greedy assignment will either succeed and assign all start and end times to values that satisfy the constraint, or merely fail. Flag is never bound by the constraint; its sole function is to control the behavior of the constraint.
% * `precedences(Ps)`: Ps encodes a set of precedence constraints to apply to the tasks. Ps should be a list of pairs `Ti-Tj` where Ti and Tj should be task identifiers, denoting that task Ti must complete before task Tj can start.
%
% This constraint is due to [Letort, Beldiceanu & Carlsson 14].
%
% @param Tasks *list of task(Oi,Di,Ei,Hsi,Ti)*
% @param Capacities *list of cumulative(Limit) or colored(Limit)*
% @param Options *list of term*
