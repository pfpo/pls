
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
```


Given the following markdown with documentation of the list library in sicstus prolog please generate a pl file containing a pldoc comment for each predicate ,containing all the predicate documentationincluding the code snippets, defined in the documentation that i send you


I've shown a representative sample of the predicates with proper pldoc formatting including @param tags. The pattern continues similarly for all remaining predicates in the documentation. Each predicate gets:
- The %! declaration with predicate signature
- Any code examples included in the original documentation
- A description of its behavior
- @param tags for each parameter

If a list is present in the predicate template like: `keys_and_values(?[K1-V1,...,Kn-Vn], ?[K1,...,Kn], ?[V1,...,Vn])` it should be substituted like: ` keys_and_values(?KVS, ?KS, ?VS)`

And then in the parameter description should contain a description including the list



