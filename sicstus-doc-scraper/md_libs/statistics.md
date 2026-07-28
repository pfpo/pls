


Next: [lib\-avl](lib_002davl.html), Previous: [lib\-assoc](lib_002dassoc.html), Up: [The Prolog Library](The-Prolog-Library.html)   \[[Contents](index.html#SEC_Contents "Table of contents")]\[[Index](Predicate-Index.html "Index")]





---


### 10\.3 Attributed Variables—`library(atts)`




This package implements attributed variables. It provides a means
of associating with variables arbitrary attributes, i.e. named
properties that can be used as storage locations as well as to extend
the default unification algorithm when such variables are
unified with other terms or with each other. This facility
was primarily designed as a clean interface between Prolog and
constraint solvers, but has a number of other uses as well. The basic
idea is due to Christian Holzbaur and he was actively involved in the
final design. For background material, see the dissertation \[Holzbaur 90].



The package provides a means to declare and access named attributes of
variables. The attributes are compound terms whose
arguments are the actual attribute values. The attribute names
are *private* to the module in which they are defined. They
are defined with a declaration









```
:- attribute AttributeSpec, …, AttributeSpec.

```

where each AttributeSpec has the form (Name/Arity).
There must be at most one such declaration in a module
Module.
At most 255 modules can declare attributes at the same time.



Having declared some attribute names, these attributes can now be added,
updated and deleted from unbound variables. For each
declared attribute name, any variable can have at most one such
attribute (initially it has none).



The declaration causes the following two access predicates
to become defined by means of the `goal_expansion/5`
mechanism. They take a variable and an AccessSpec as
arguments where an AccessSpec is either
`+(Attribute)`, `-(Attribute)`, or a list of
such. The ‘`+`’ prefix may be dropped for convenience. 
Attribute must be nonvariable at compile time.
The meaning of the ‘`+`’/‘`-`’ prefix is documented below:








`Module:get_atts(-Var, ?AccessSpec)`
Gets the attributes of Var, which must be a variable,
according to AccessSpec. If
AccessSpec was unbound at compile time, it will be bound to a
list of all present attributes of Var, otherwise
the elements of AccessSpec have the following meaning:



`+(Attribute)`
The corresponding actual attribute must be present and is unified with
Attribute.
The ‘`+`’ prefix may be dropped for convenience.




`-(Attribute)`
The corresponding actual attribute must be absent. The arguments
of Attribute are ignored, only the name and arity are
relevant.







`Module:put_atts(-Var, +AccessSpec)`
Sets the attributes of Var, which must be a variable, according to AccessSpec.
The effects of `put_atts/2` are undone on backtracking.



`+(Attribute)`
The corresponding actual attribute is set to Attribute.
If the actual attribute was already present, it is simply replaced.
The ‘`+`’ prefix may be dropped for convenience.




`-(Attribute)`
The corresponding actual attribute is removed.
If the actual attribute was already absent, nothing happens.






A module that contains an attribute declaration has an
opportunity to extend the default unification algorithm by
defining the following predicate:








`Module:verify_attributes(-Var, +Value, -Goals)   hook`
This predicate is called whenever a variable Var that
might have attributes in Module is about to be bound to
Value (it might have none). The unification resumes after
the call to `verify_attributes/3`. Value is a
nonvariable, or another attributed variable.
Var might have no attributes present in Module; the
unification extension mechanism is not sophisticated enough to
filter out exactly the variables that are relevant for
Module.



`verify_attributes/3` is called *before* Var has
actually been bound to Value. If it fails, the
unification is deemed to have failed. It may succeed
nondeterminately, in which case the unification might
backtrack to give another answer. It is expected to return, in
Goals, a list of goals to be called *after*
Var has been bound to Value. Finally, after calling
Goals,
goals blocked on Var may have become unblocked, in which case they are called.



`verify_attributes/3` may invoke arbitrary Prolog goals, but
it should not do anything that would lead to a recursive invokation of
`verify_attributes/3` of any module. In particular, neither
Var nor any other attributed variable should be bound by it. Breaking
these rules results in undefined behavior.



Contrary to other hook predicates, any exception raised by `verify_attributes/3`
is propagated and not caught locally.



If Value is a nonvariable,
`verify_attributes/3` will typically inspect the attributes of
Var and check that they are compatible with Value and fail
otherwise. If Value is another attributed variable,
`verify_attributes/3` will typically copy the attributes of
Var over to Value, or merge them with Value’s, in
preparation for Var to be bound to Value. In either
case, `verify_attributes/3` may determine Var’s current
attributes by calling `get_atts(Var,List)` with an
unbound List.



In the case when a single unification binds multiple attributed
variables, first all such bindings are *undone*, then 
the following actions are carried out for each relevant variable:



1. For each relevant module M, `M:verify_attributes/3`
is called, collecting a list of returned Goals.
2. The variable binding is *redone*.
3. Any Goals are called.
4. Any goals blocked on the variable, that has now become unblocked, are called.




An important use for attributed variables is in implementing
coroutining facilities as an alternative or complement to the
built\-in coroutining mechanisms. In this context it might be
useful to be able to interpret some of the attributes of a
variable as a goal that is blocked on that
variable. Certain built\-in predicates (`frozen/2`,
`copy_term/3`) and the Prolog top level need to access
blocked goals, and so need a means of getting the goal
interpretation of attributed variables by calling:








`Module:attribute_goal(-Var, -Goal)   hook`
This predicate is called in each module that contains an
attribute declaration, when an interpretation of the attributes as
a goal is needed, in particular in `frozen/2`,
`copy_term/3` and the Prolog top level.
It should unify Goal with the
interpretation, or merely fail if no such interpretation is available.



Contrary to other hook predicates, any exception raised by `attribute_goal/2`
is propagated and not caught locally.




An important use for attributed variables is to provide an
interface to constraint solvers. An important function for a constraint
solver in the constraint logic programming paradigm is to be able to
perform projection of the residual constraints onto the variables
that occurred in the top\-level query. A module that
contains an attribute declaration has an opportunity to perform
such projection of its residual constraints by defining the following
predicate:








`Module:project_attributes(+QueryVars, +AttrVars)   hook`
This predicate is called by the Prolog top level in each module that
contains an attribute declaration. QueryVars is the
list of variables occurring in the query, or in
terms bound to such variables, and AttrVars is a
list of possibly attributed variables created during the
execution of the query. The two lists of variables
may or may not be disjoint.



If the attributes on AttrVars can be interpreted as constraints,
this predicate will typically “project” those constraints onto
the relevant QueryVars. Ideally, the residual constraints will be
expressed entirely in terms of the QueryVars, treating all
other variables as existentially quantified. Operationally,
`project_attributes/2` must remove all attributes from
AttrVars, and add transformed attributes representing the
projected constraints to some of the QueryVars.



Projection has the following effect on the Prolog top level. When the
top\-level query has succeeded, `project_attributes/2` is
called first. The top level then prints the answer substitution and
residual constraints. While doing so, it searches for attributed
variables created during the execution of the query. For
each such variable, it calls `attribute_goal/2` to get a
printable representation of the constraint encoded by the attribute.
Thus, `project_attributes/2` is a mechanism for controlling how the
residual constraints should be displayed at top level.



The exact definition of `project_attributes/2` is constraint system
dependent, but see [Answer Constraints](Answer-Constraints.html) and see [CLPQR Projection](CLPQR-Projection.html)
for details about projection in CLPFD and CLP(Q,R) respectively.




In the following example we sketch the implementation of a finite domain
“solver”. Note that an industrial strength solver would have to
provide a wider range of functionality and that it quite likely would
utilize a more efficient representation for the domains proper. The
module exports a single predicate
`domain(-Var,?Domain)`, which associates Domain
(a list of terms) with Var. A variable can be
queried for its domain by leaving Domain unbound.



We do not present here a 
definition for `project_attributes/2`. Projecting finite domain
constraints happens to be difficult.





```
% domain.pl

```

```
:- module(domain, [domain/2]).

:- use_module(library(atts)).
:- use_module(library(ordsets), [
        ord_intersection/3,
        ord_intersect/2,
        list_to_ord_set/2
   ]).

:- attribute dom/1.

verify_attributes(Var, Other, Goals) :-
        get_atts(Var, dom(Da)), !,          % are we involved?
        (   var(Other) ->                   % must be attributed then
            (   get_atts(Other, dom(Db)) -> %   has a domain?
                ord_intersection(Da, Db, Dc),
                Dc = [El|Els],              % at least one element
                (   Els = [] ->             % exactly one element
                    Goals = [Other=El]      % implied binding
                ;   Goals = [],
                    put_atts(Other, dom(Dc))% rescue intersection
                )
            ;   Goals = [],
                put_atts(Other, dom(Da))    % rescue the domain
            )
        ;   Goals = [],
            ord_intersect([Other], Da)      % value in domain?
        ).
verify_attributes(_, _, []).                % unification triggered
                                            % because of attributes
                                            % in other modules

attribute_goal(Var, domain(Var,Dom)) :-     % interpretation as goal
        get_atts(Var, dom(Dom)).

domain(X, Dom) :-
        var(Dom), !,
        get_atts(X, dom(Dom)).
domain(X, List) :-
        list_to_ord_set(List, Set),
        Set = [El|Els],                     % at least one element
        (   Els = [] ->                     % exactly one element
            X = El                          % implied binding
        ;   put_atts(Fresh, dom(Set)),
            X = Fresh                       % may call
                                            % verify_attributes/3
        ).

```

Note that the “implied binding” `Other=El` was deferred until
after the completion of `verify_attribute/3`. Otherwise, there
might be a danger of recursively invoke `verify_attribute/3`, which
might bind `Var`, which is not allowed inside the scope of
`verify_attribute/3`. Deferring unifications into the third
argument of `verify_attribute/3` effectively serializes the
calls to `verify_attribute/3`.



Assuming that the code resides in the file `domain.pl`, we can
load it via:





```
| ?- use_module(domain).

```

Let’s test it:





```
| ?- domain(X,[5,6,7,1]), domain(Y,[3,4,5,6]), domain(Z,[1,6,7,8]).

domain(X,[1,5,6,7]),
domain(Y,[3,4,5,6]),
domain(Z,[1,6,7,8])

| ?- domain(X,[5,6,7,1]), domain(Y,[3,4,5,6]), domain(Z,[1,6,7,8]), 
     X=Y.

Y = X,
domain(X,[5,6]),
domain(Z,[1,6,7,8])

| ?- domain(X,[5,6,7,1]), domain(Y,[3,4,5,6]), domain(Z,[1,6,7,8]),
     X=Y, Y=Z.

X = 6,
Y = 6,
Z = 6

```

To demonstrate the use of the Goals argument of
`verify_attributes/3`, we give an implementation of
`freeze/2`. We have to name it `myfreeze/2` in order to avoid
a name clash with the built\-in predicate of the same name.





```
% myfreeze.pl

```

```
 :- module(myfreeze, [myfreeze/2]).
 
 :- use_module(library(atts)).
 
 :- meta_predicate myfreeze(*, 0).
 
 :- attribute frozen/1.
 
 verify_attributes(Var, Other, Goals) :-
       get_atts(Var, frozen(Fa)), !,            % are we involved?
       (   var(Other) ->                        % must be attributed then
           (   get_atts(Other, frozen(Fb))      % has a pending goal?
           ->
               put_atts(Other, frozen((Fa,Fb))) % rescue conjunction
           ;   put_atts(Other, frozen(Fa))      % rescue the pending goal
           ),
           Goals = []
       ;   Goals = [Fa]                         % wake our frozen goal
       ).
 verify_attributes(_, _, []).
 
 attribute_goal(Var, myfreeze(Var,Goal)) :- % interpretation as goal
       get_atts(Var, frozen(Goal)).
 
 myfreeze(X, Goal) :-
       put_atts(Fresh, frozen(Goal)),
       Fresh = X.

```

Assuming that this code lives in file `myfreeze.pl`,
we would use it via:





```
| ?- use_module(myfreeze).
| ?- myfreeze(X,print(bound(x,X))), X=2.

bound(x,2)                      % side-effect
X = 2                           % bindings

```

The two solvers even work together:





```
| ?- myfreeze(X,print(bound(x,X))), domain(X,[1,2,3]),
     domain(Y,[2,10]), X=Y.

bound(x,2)                      % side-effect
X = 2,                          % bindings
Y = 2

```

The two example solvers interact via bindings to shared attributed
variables only. More complicated interactions are likely to be
found in more sophisticated solvers. The corresponding
`verify_attributes/3` predicates would typically refer to the
attributes from other known solvers/modules via the module
prefix in `Module:get_atts/2`.





---



[|  |
| --- |](https://sicstus.sics.se/)


* [User's Manual](index.html#Top)


---

* [Table of Contents](index.html#TOC)* [Next](lib_002davl.html)* [Previous](lib_002dassoc.html)* [Up](The-Prolog-Library.html)





---


[Send feedback on this subject.](mailto:sicstus-support@ri.se?subject=Documentation%20feedback%20on%20html/sicstus/lib_002datts.html&body=Feedback%20on%20documentation%20node%20html/sicstus/lib_002datts.html%20in%20User's%20Manual.)
