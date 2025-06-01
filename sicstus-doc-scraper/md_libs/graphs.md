#### 10\.9\.7\.6 Graph Constraints


The following constraints can be thought of as constraining n
nodes in a graph to form a Hamiltonian (sub\-)circuit. The nodes are
numbered from 1 to n. A full circuit visits each node exactly
once and returns to the origin. A subcircuit visits a subset of the
nodes exactly once and returns to the origin.




`circuit(+Succ)`
`circuit(+Succ, +Pred)`



where Succ is a list of length n of integer arguments. The
value of the i\-th element of Succ (Pred) is the
successor (predecessor) of node i in the graph. True if the
nodes form exactly one Hamiltonian circuit.



Corresponds to `circuit` in MiniZinc.




`subcircuit(+Succ)   since release 4.6`
`subcircuit(+Succ, +Pred)   since release 4.6`



where Succ is a list of length n of integer arguments. If
the value of the i\-th element of Succ (Pred) is
i, then that corresponds to a node not in the graph. Otherwise,
the value is the successor (predecessor) of node i in the graph.
True if the nodes that are included form at most one Hamiltonian subcircuit.



Corresponds to `subcircuit` in MiniZinc.




The following constraint defines a flow in a network made up of nodes and arcs.




`network_flow(+Nodes, +Arcs)   since release 4.10.0`
`network_flow(+Nodes, +Arcs, +Options)   since release 4.10.0`




Nodes should be a list of terms `node(Id,Balance)`.
Arcs should be a list of terms `node(From,To,Weight,Flow)`.
Options should be a list of at most one term of the form `cost(Cost)`.
Id can be any term, but the ids of Nodes should be all distinct.
From and To identify the two nodes that the arc connects, and should occur as ids.
They are looked up with `==/2`.
Flow should be an integer argument with finite, non\-negative bounds, the flow going through an arc.
Weight should be a non\-negative integer, the unit cost of the flow through an arc.
Balance should be a non\-negative integer, the difference between output and input flow for a node.
Finally, Cost, if given, should be an integer argument, the overall cost of the flow.



Corresponds to `network_flow` and `network_flow_cost` in MiniZinc.
The following figure:



  

![images/network_flow](images/network_flow.png)
An example of `network_flow/3`.

depicts the query:





```
| ?- F0 in 1..3,
     F1 in 2..4,
     F2 in 0..3,
     F3 in 0..1,
     F4 in 2..10,
     network_flow([node(0,3), node(1,2), node(2,-3), node(3,-2)],
                  [arc(0,1,1,F0), arc(0,2,1,F1), arc(1,2,1,F2),
                   arc(1,3,1,F3), arc(2,3,1,F4)],
                  [cost(Cost)]
     ).

```

The query has a unique solution, with cost 8\. The arcs of the figure have been annotated
with the value of the flow, e.g., ‘`sol: 1`’ stands for a flow equal to 1 in the solution.