%! circuit(+Succ)
%
% Corresponds to `circuit` in MiniZinc.
%
% @param Succ *list of integer*
% Succ is a list of length n of integer arguments. The
% value of the i-th element of Succ (Pred) is the
% successor (predecessor) of node i in the graph. True if the
% nodes form exactly one Hamiltonian circuit.

%! circuit(+Succ, +Pred)
%
% Corresponds to `circuit` in MiniZinc.
%
% @param Succ *list of integer*
% Succ is a list of length n of integer arguments. The
% value of the i-th element of Succ (Pred) is the
% successor (predecessor) of node i in the graph. True if the
% nodes form exactly one Hamiltonian circuit.

%! subcircuit(+Succ)
%
% Corresponds to `subcircuit` in MiniZinc.
%
% @param Succ *list of integer*
% Succ is a list of length n of integer arguments. If
% the value of the i-th element of Succ (Pred) is
% i, then that corresponds to a node not in the graph. Otherwise,
% the value is the successor (predecessor) of node i in the graph.
% True if the nodes that are included form at most one Hamiltonian subcircuit.

%! subcircuit(+Succ, +Pred)
%
% Corresponds to `subcircuit` in MiniZinc.
%
% @param Succ *list of integer*
% Succ is a list of length n of integer arguments. If
% the value of the i-th element of Succ (Pred) is
% i, then that corresponds to a node not in the graph. Otherwise,
% the value is the successor (predecessor) of node i in the graph.
% True if the nodes that are included form at most one Hamiltonian subcircuit.

%! network_flow(+Nodes, +Arcs)
%
% Corresponds to `network_flow` and `network_flow_cost` in MiniZinc.
%
% @param Nodes *list of node(Id,Balance)*
% Nodes should be a list of terms `node(Id,Balance)`. Id can be any term, but the ids of Nodes should be all distinct. Balance should be a non-negative integer, the difference between output and input flow for a node.
% @param Arcs *list of arc(From,To,Weight,Flow)*
% Arcs should be a list of terms `node(From,To,Weight,Flow)`. From and To identify the two nodes that the arc connects, and should occur as ids. They are looked up with `==/2`. Flow should be an integer argument with finite, non-negative bounds, the flow going through an arc. Weight should be a non-negative integer, the unit cost of the flow through an arc.

%! network_flow(+Nodes, +Arcs, +Options)
%
% Corresponds to `network_flow` and `network_flow_cost` in MiniZinc.
% The following figure:
% An example of `network_flow/3`.
%
% depicts the query:
%
% ```
% | ?- F0 in 1..3,
%      F1 in 2..4,
%      F2 in 0..3,
%      F3 in 0..1,
%      F4 in 2..10,
%      network_flow([node(0,3), node(1,2), node(2,-3), node(3,-2)],
%                   [arc(0,1,1,F0), arc(0,2,1,F1), arc(1,2,1,F2),
%                    arc(1,3,1,F3), arc(2,3,1,F4)],
%                   [cost(Cost)]
%      ).
% ```
%
% The query has a unique solution, with cost 8. The arcs of the figure have been annotated
% with the value of the flow, e.g., '`sol: 1`' stands for a flow equal to 1 in the solution.
%
% @param Nodes *list of node(Id,Balance)*
% Nodes should be a list of terms `node(Id,Balance)`. Id can be any term, but the ids of Nodes should be all distinct. Balance should be a non-negative integer, the difference between output and input flow for a node.
% @param Arcs *list of arc(From,To,Weight,Flow)*
% Arcs should be a list of terms `node(From,To,Weight,Flow)`. From and To identify the two nodes that the arc connects, and should occur as ids. They are looked up with `==/2`. Flow should be an integer argument with finite, non-negative bounds, the flow going through an arc. Weight should be a non-negative integer, the unit cost of the flow through an arc.
% @param Options *list of cost(Cost)*
% Options should be a list of at most one term of the form `cost(Cost)`. Cost, if given, should be an integer argument, the overall cost of the flow.
