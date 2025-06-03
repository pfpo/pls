
Here is an example of pldoc style comments in prolog:

```pl
%! member(?Element,?List)
%
% is true if Element occurs in the List. It may be used
% to test for an element or to enumerate all the elements by backtracking.
% Indeed, it may be used to generate the List!
%
% @param Element *term*
% @param List *list of term*

%! write(+Stream,+Term)
%! write(+Term)
%
% Writes Term on Stream, without quoting atoms.
%
% @param Stream *stream\_object*, must be ground
% A valid open Prolog stream, defaults to the current output stream.
% @param Term *term*


%!    list_map(+XS, +MapFunc, -YS)
%
%     Applies a mapping function to each element in a list.
%
%     @param XS      The input list.
%     @param MapFunc The mapping function to apply.
%     @param YS      The resulting list after applying the function.

```


Given the following markdown with documentation of the list library in sicstus prolog please generate a pl file containing a pldoc comment for each predicate ,containing all the predicate documentationincluding the code snippets, defined in the documentation that i send you


I've shown a representative sample of the predicates with proper pldoc formatting including @param tags. The pattern continues similarly for all remaining predicates in the documentation. Each predicate gets:
- The %! declaration with predicate signature
- Any code examples included in the original documentation
- A description of its behavior
- @param tags for each parameter

If a list is present in the predicate template like: `keys_and_values(?[K1-V1,...,Kn-Vn], ?[K1,...,Kn], ?[V1,...,Vn])` it should be substituted like: ` keys_and_values(?KVS, ?KS, ?VS)`

And then in the parameter description should contain a description including the list


For exemple if the following markdown is provided:


---
`cumlist(:Pred, +[X1,...,Xn], ?V0, ?[V1,...,Vn])`
`cumlist(:Pred, +[X1,...,Xn], +[Y1,...,Yn], ?V0, ?[V1,...,Vn])`
`cumlist(:Pred, +[X1,...,Xn], +[Y1,...,Yn], +[Z1,...,Zn], ?V0, ?[V1,...,Vn])`

---
`cumlist/4` maps a ternary predicate Pred down the list \[X1,...,Xn] just as
`scanlist/4` does, and returns a list of the results. It terminates
when the lists runs out. If Pred is bidirectional, it may be
used to derive \[X1\...Xn] from V0 and \[V1\...Vn], e.g.
`cumlist(plus, [1,2,3,4], 0, /* -> */ [1,3,6,10])` and
`cumlist(plus, [1,1,1,1], /* <- */ 0, [1,2,3,4])`.
Could be defined as:


```
cumlist(Pred, Xs, V0, Cum) :-
    (   foreach(X,Xs),
        foreach(V,Cum),
        fromto(V0,V1,V,_),
        param(Pred)
    do  call(Pred,X,V1,V)
    ).
cumlist(Pred, Xs, Ys, V0, Cum) :-
    (   foreach(X,Xs),
        foreach(Y,Ys),
        foreach(V,Cum),
        fromto(V0,V1,V,_),
        param(Pred)
    do  call(Pred,X,Y,V1,V)
    ).
cumlist(Pred, Xs, Ys, Zs, V0, Cum) :-
    (   foreach(X,Xs),
        foreach(Y,Ys),
        foreach(Z,Zs),
        foreach(V,Cum),
        fromto(V0,V1,V,_),
        param(Pred)
    do  call(Pred,X,Y,Z,V1,V)
    ).
```

It should be converted into the following pldoc:

```

%! cumlist(:Pred, +XS, ?V0, ?[V1,...,Vn])
%! cumlist(:Pred, +XS, +[Y1,...,Yn], ?V0, ?[V1,...,Vn])
%! cumlist(:Pred, +XS, +[Y1,...,Yn], +[Z1,...,Zn], ?V0, ?[V1,...,Vn])
%
% `cumlist/4` maps a ternary predicate Pred down the list \[X1,...,Xn] just as
% `scanlist/4` does, and returns a list of the results. It terminates
% when the lists runs out. If Pred is bidirectional, it may be
% used to derive \[X1\...Xn] from V0 and \[V1\...Vn], e.g.
% `cumlist(plus, [1,2,3,4], 0, /* -> */ [1,3,6,10])` and
% `cumlist(plus, [1,1,1,1], /* <- */ 0, [1,2,3,4])`.
% Could be defined as:
%
% ```
% cumlist(Pred, Xs, V0, Cum) :-
%     (   foreach(X,Xs),
%         foreach(V,Cum),
%         fromto(V0,V1,V,_),
%         param(Pred)
%     do  call(Pred,X,V1,V)
%     ).
% cumlist(Pred, Xs, Ys, V0, Cum) :-
%     (   foreach(X,Xs),
%         foreach(Y,Ys),
%         foreach(V,Cum),
%         fromto(V0,V1,V,_),
%         param(Pred)
%     do  call(Pred,X,Y,V1,V)
%     ).
% cumlist(Pred, Xs, Ys, Zs, V0, Cum) :-
%     (   foreach(X,Xs),
%         foreach(Y,Ys),
%         foreach(Z,Zs),
%         foreach(V,Cum),
%         fromto(V0,V1,V,_),
%         param(Pred)
%     do  call(Pred,X,Y,Z,V1,V)
%     ).
% ``` 
% 
% @param :Pred  ternary predicate such that 
% @param +XS the list [X1,...,XN]
% @param ?V0 
% @param ?VS the list [V1,...,VN]
% @param YS  the list [Y1,..., YN]
% @param ZS the list [Z1,...,ZN]

```

Of course in each parameter try to give some description of what the parameter is like

