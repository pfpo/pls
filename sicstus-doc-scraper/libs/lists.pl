%!    select(?Element, ?Set, ?Residue)
%
%     is true when Set is a list, Element occurs in Set, and Residue is
%     everything in Set except Element (things stay in the same order).
%
%     @param Element term
%     @param Set list
%     @param Residue list

%!    selectchk(+Element, +Set, ?Residue)
%
%     is to `select/3` what `memberchk/2` is to `member/2`. That is, it locates
%     the first occurrence of Element in Set, and deletes it, giving Residue.
%     It is steadfast in Residue.
%
%     @param Element term
%     @param Set list
%     @param Residue list

%!    append(+ListOfLists, -List)
%
%     is true when ListOfLists is a list \[L1,...,Ln] of lists, List is
%     a list, and appending L1, ..., Ln together yields List.
%     ListOfLists *must* be a proper list.
%     Additionally, either List should be a proper list, or
%     each of L1, ..., Ln should be a proper list. The behavior on
%     non-lists is undefined. ListOfLists must be proper because for
%     any given solution, infinitely many more can be obtained by
%     inserting nils ([]) into ListOfList.
%     Could be defined as:
%
%     ```
%     append(Lists, Appended) :-
%         (   foreach(List,Lists),
%             fromto(Appended,S0,S,[])
%         do  append(List, S, S0)
%         ).
%     ```
%
%     @param ListOfLists +list_of_lists
%     @param List -list



%!    append(?Prefix, ?Tail1, ?List1, ?Tail2, ?List2)
%
%     is true when `append(Prefix, Tail1, List1)` and `append(Prefix, Tail2, List2)`
%     are both true. You could call `append/3` twice, but that is order-
%     dependent. This will terminate if Prefix is a proper list or if
%     either List1 or List2 is a proper list.
%
%     @param Prefix list
%     @param Tail1 list
%     @param List1 list
%     @param Tail2 list
%     @param List2 list



%!    correspond(?X, ?Xlist, ?Ylist, ?Y)
%
%     is true when Xlist and Ylist are lists, X is an element of Xlist, Y is
%     an element of Ylist, and X and Y are in similar places in their lists.
%     No relation is implied between other elements of Xlist and Ylist.
%     For a similar predicate without the cut, see `select/4`.
%
%     @param X term
%     @param Xlist list
%     @param Ylist list
%     @param Y term



%!    delete(+List, +Kill, -Residue)
%
%     is true when List is a list, in which Kill may or may not occur, and
%     Residue is a copy of List with all elements equal to Kill deleted.
%     To extract a single copy of Kill, use `select(Kill, List, Residue)`.
%     Kill and the elements of
%     List should be sufficiently instantiated for `\=` to be sound.
%     Could be defined as:
%
%     ```
%     delete(List, Kill, Residue) :-
%         (   foreach(X,List),
%             fromto(Residue,S0,S,[]),
%             param(Kill)
%         do  (X = Kill -> S0 = S ; S0 = [X|S])
%         ).
%     ```
%
%     @param List +list
%     @param Kill +term
%     @param Residue -list



%!    delete(+List, +Kill, +Count, -Residue)
%
%     is true when List is a list, in which Kill may or may not occur,
%     and Count is a non-negative integer, and Residue is a copy of
%     List with the first Count elements equal to Kill deleted. If
%     List has fewer than Count elements equal to Count, all of them
%     are deleted.
%     Kill and the elements of List should be sufficiently instantiated for `\=` to be sound.
%
%     @param List +list
%     @param Kill +term
%     @param Count +integer
%     @param Residue -list



%!    is_list(+List)
%
%     succeeds when List is a proper list. That is, List is nil ([]) or
%     a cons cell ([Head|Tail]) whose Tail is a proper list.
%     A variable, or a list whose final tail is a variable, or a cyclic list, will fail this
%     test.
%
%     @param List +list



%!    keys_and_values(?[K1-V1,...,Kn-Vn], ?[K1,...,Kn], ?[V1,...,Vn])
%
%     is true when its arguments look like the picture above. It is meant
%     for splitting a list of Key-Value pairs (such as `keysort/2` wants and
%     produces) into separate lists of Keys and of Values. It may just as
%     well be used for building a list of pairs from a pair of lists. In
%     fact one usually wants just the keys or just the values, but you can
%     supply `_` as the other argument. For example, suppose you wanted to
%     sort a list without having duplicates removed. You could do
%
%     ```
%         keys_and_values(RawPairs, RawKeys, _),
%         keysort(RawPairs, OrdPairs),
%         keys_and_values(OrdPairs, OrdKeys, _).
%     ```
%     Could be defined as:
%
%     ```
%     keys_and_values([], [], []).
%     keys_and_values([Key-Value|Pairs], [Key|Keys], [Value|Values]) :-
%         keys_and_values(Pairs, Keys, Values).
%     ```
%
%     @param K1-V1...Kn-Vn list
%     @param K1...Kn list
%     @param V1...Vn list



%!    last(+List, -Last)
%
%     is true when List is a List and Last is its last element.
%     There is also a `last(?Fore, ?Last, ?List)`
%     whose argument order matches append/3.
%     This could be defined as
%
%     ```
%         last(L, X) :- append(_, [X], L).
%     ```
%
%     @param List +list
%     @param Last -term



%!    nextto(?X, ?Y, ?List)
%
%     is true when X and Y appear side-by-side in List.
%     It could be written as
%
%     ```
%         nextto(X, Y, List) :- append(_, [X,Y|_], List).
%     ```
%     It may be used to enumerate successive pairs from the list.
%     List should be proper, otherwise `nextto/3` will generate it.
%
%     @param X term
%     @param Y term
%     @param List list



%!    nth0(?N, ?List, ?Elem)
%
%     is true when Elem is the Nth member of List, counting the first as
%     element 0. That is, throw away the first N elements and unify Elem
%     with the next. E.g. `nth0(0, [H|T], H)`.
%     Either N should be an integer, or List should be proper.
%
%     @param N integer
%     @param List list
%     @param Elem term



%!    nth1(?N, ?List, ?Element)
%
%     is true when Elem is the Nth member of List, counting the first as
%     element 1. That is, throw away the first N-1 elements and unify Elem
%     with the next element (the Nth). E.g. `nth1(1, [H|T], H)`.
%     This is just like `nth0/3` except that it counts from 1 instead of 0.
%     Either N should be an integer, or List should be proper.
%
%     @param N integer
%     @param List list
%     @param Element term



%!    nth0(?N, ?List, ?Elem, ?Rest)
%
%     unifies Elem with the Nth element of List, counting from 0, and Rest
%     with the other elements. It can be used to select the Nth element
%     of List (yielding Elem and Rest), or to insert Elem *before* the Nth
%     (counting from 0) element of Rest, when it yields List, e.g.
%     `nth0(2, List, c, [a,b,d,e])` unifies List with `[a,b,c,d,e]`.
%     This can be seen as inserting Elem *after* the Nth element of Rest
%     if you count from 1 rather than 0.
%     Either N should be an integer, or List or Rest should be proper.
%
%     @param N integer
%     @param List list
%     @param Elem term
%     @param Rest list



%!    nth1(?N, ?List, ?Elem, ?Rest)
%
%     unifies Elem with the Nth element of List, counting from 1, and Rest
%     with the other elements. It can be used to select the Nth element
%     of List (yielding Elem and Rest), or to insert Elem *before* the Nth
%     (counting from 1) element of Rest, when it yields List, e.g.
%     `nth1(2, List, b, [a,c,d,e])` unifies List with `[a,b,c,d,e]`.
%     Either N should be an integer, or List or Rest should be proper.
%
%     @param N integer
%     @param List list
%     @param Elem term
%     @param Rest list



%!    one_longer(?Longer, ?Shorter)
%
%     is true when
%
%     ```
%         length(Longer,N), length(Shorter,M), succ(M,N)
%     ```
%     for some integers M, N. It was
%     written to make `{nth0,nth1}/4` able to find the index, just as
%     `same_length/2` is useful for making things invertible.
%
%     @param Longer list
%     @param Shorter list



%!    perm(+List, ?Perm)
%
%     is true when List and Perm are permutations of each other. The main
%     use of `perm/2` is to generate permutations. You should not use this
%     predicate in new programs; use `permutation/2` instead. List must be
%     a proper list. Perm may be partly instantiated.
%
%     @param List +list
%     @param Perm list



%!    permutation(?List, ?Perm)
%
%     is true when List and Perm are permutations of each other.
%     Unlike `perm/2`, it will work even when List is not a proper list.
%     Any way, it works by generating permutations of List and unifying them with Perm.
%     Be careful: this is quite efficient, but the number of permutations of an
%     N-element list is N!, and even for a 7-element list that is 5040.
%
%     @param List list
%     @param Perm list



%!    perm2(?A,?B, ?C,?D)
%
%     is true when {A,B} = {C,D}. It is very useful for writing pattern
%     matchers over commutative operators.
%
%     @param A term
%     @param B term
%     @param C term
%     @param D term



%!    proper_length(+List, ?Length)
%
%     succeeds when List is a proper list, binding Length to its length.
%     That is, `is_list(List), length(List, Length)`.
%     Will fail for cyclic lists.
%
%     @param List +list
%     @param Length integer



%!    remove_dups(+List, ?Pruned)
%
%     removes duplicated elements from List, which should be a proper list.
%     If List has non-ground elements, Pruned may contain elements which
%     unify; two elements will remain separate iff there is a substitution
%     which makes them different. E.g. [X,X] -> [X] but [X,Y] -> [X,Y].
%     The surviving elements, by ascending standard order, is unified with Pruned.
%
%     @param List +list
%     @param Pruned list



%!    reverse(?List, ?Reversed)
%
%     is true when List and Reversed are lists with the same elements
%     but in opposite orders. Either List or Reversed should be a
%     proper list: given either argument the other can be found. If
%     both are incomplete `reverse/2` can backtrack forever trying ever
%     longer lists.
%
%     @param List list
%     @param Reversed list



%!    rev(+List, ?Reversed)
%
%     is a version of `reverse/2` which only works one way around.
%     Its List argument must be a proper list whatever Reversed is.
%     You should use `reverse/2` in new programs, though `rev/2` is
%     faster when it is safe to use it.
%
%     @param List +list
%     @param Reversed list



%!    same_length(?List1, ?List2)
%
%     is true when List1 and List2 are both lists and have the same number
%     of elements. No relation between the values of their elements is
%     implied. It may be used to generate either list given the other,
%     or indeed to generate two lists of the same length, in which case
%     the arguments will be bound to lists of length 0, 1, 2, ...
%     If either List1 or List2 is bound to a proper
%     list, same_length is determinate and terminating.
%
%     @param List1 list
%     @param List2 list



%!    same_length(?List1, ?List2, ?Length)
%
%     is true when List1 and List2 are both lists, Length is a non-negative
%     integer, and both List1 and List2 have exactly Length elements. No
%     relation between the elements of the lists is implied. If Length
%     is instantiated, or if either List1 or List2 is bound to a proper
%     list, same_length is determinate and terminating.
%
%     @param List1 list
%     @param List2 list
%     @param Length integer



%!    select(?X, ?Xlist, ?Y, ?Ylist)
%
%     is true when X is the Kth member of Xlist and Y the Kth element of Ylist
%     for some K, and apart from that Xlist and Ylist are the same. You can
%     use it to replace X by Y or vice versa. Either Xlist or Ylist should
%     be a proper list.
%
%     @param X term
%     @param Xlist list
%     @param Y term
%     @param Ylist list



%!    selectchk(?X, +Xlist, ?Y, +Ylist)
%
%     is to `select/4` as `memberhck/2` is to `member/2`. That is, it finds the
%     first K such that X unifies with the Kth element of Xlist and Y with
%     the Kth element of Ylist, and it commits to the bindings thus found.
%     If you have Keys and Values in "parallel" lists, you can use this to
%     find the Value associated with a particular Key (much better methods
%     exist). Except for argument order, this is identical to `correspond/4`,
%     but `selectchk/4` is a member of a coherent family. Note that the
%     arguments are like the arguments of `memberchk/2`, twice.
%
%     @param X term
%     @param Xlist +list
%     @param Y term
%     @param Ylist +list



%!    shorter_list(?Short, ?Long)
%
%     is true when Short is a list is strictly shorter than Long. Long
%     doesn’t have to be a proper list provided it is long enough. This
%     can be used to generate lists shorter than Long, lengths 0, 1, 2...
%     will be tried, but backtracking will terminate with a list that is
%     one element shorter than Long. It cannot be used to generate lists
%     longer than Short, because it doesn’t look at all the elements of the
%     longer list.
%
%     @param Short list
%     @param Long list



%!    subseq(?Sequence, ?SubSequence, ?Complement)
%
%     is true when SubSequence and Complement are both subsequences of the
%     list Sequence (the order of corresponding elements being preserved)
%     and every element of Sequence which is not in SubSequence is in the
%     Complement and vice versa. That is,
%     `length(Sequence) = length(SubSequence)+length(Complement)`,
%     e.g. `subseq([1,2,3,4], [1,3,4], [2])`. This was written to generate subsets
%     and their complements together, but can also be used to interleave two
%     lists in all possible ways.
%
%     @param Sequence list
%     @param SubSequence list
%     @param Complement list



%!    subseq0(+Sequence, ?SubSequence)
%
%     is true when SubSequence is a subsequence of Sequence, but may
%     be Sequence itself. Thus `subseq0([a,b], [a,b])` is true as well
%     as `subseq0([a,b], [a])`. Sequence must be a proper list, since
%     there are infinitely many lists with a given SubSequence.
%
%     ```
%     ?- setof(X, subseq0([a,b,c],X), Xs).
%     Xs = [[],[a],[a,b],[a,b,c],[a,c],[b],[b,c],[c]]
%     ?- bagof(X, subseq0([a,b,c,d],X), Xs).
%     Xs = [[a,b,c,d],[b,c,d],[c,d],[d],[],[c],[b,d],[b],[b,c],[a,c,d],
%           [a,d],[a],[a,c],[a,b,d],[a,b],[a,b,c]]
%     ```
%
%     @param Sequence +list
%     @param SubSequence list



%!    subseq1(+Sequence, ?SubSequence)
%
%     is true when SubSequence is a proper subsequence of Sequence,
%     that is it contains at least one element less. Sequence must
%     be a proper list, as SubSequence does not determine Sequence.
%
%     @param Sequence +list
%     @param SubSequence list



%!    sumlist(+Numbers, ?Total)
%
%     is true when Numbers is a list of integers, and Total is their sum.
%     Numbers should be a proper list.
%     Could be defined as:
%
%     ```
%     sumlist(Numbers, Total) :-
%         (   foreach(X,Numbers),
%             fromto(0,S0,S,Total)
%         do  S is S0+X
%         ).
%     ```
%
%     @param Numbers +list_of_integers
%     @param Total integer



%!    transpose(?X, ?Y)
%
%     is true when X is a list of the form [[X11,...,X1m],...,[Xn1,...,Xnm]]
%     and Y is its transpose, that is, Y = [[X11,...,Xn1],...,[X1m,...,Xnm]]
%     We insist that both lists should have this rectangular form, so that
%     the predicate can be invertible. For the same reason, we reject empty
%     arrays with m = 0 or n = 0.
%
%     @param X list_of_lists
%     @param Y list_of_lists



%!    append_length(?Prefix, ?Suffix, ?List, ?Length)
%
%     is true when
%
%     ```
%         append(Prefix, Suffix, List), length(Prefix, Length).
%     ```
%     The normal use of this is to split a List into a Prefix of
%     a given Length and the corresponding Suffix, but it can be
%     used any way around provided that
%      Length is instantiated, or
%      Prefix is a proper list, or
%      List is a proper list.
%
%     @param Prefix list
%     @param Suffix list
%     @param List list
%     @param Length integer



%!    append_length(?Suffix, ?List, ?Length)
%
%     is true when there exists a list Prefix such that
%     `append_length(Prefix, Suffix, List, Length)` is true.
%     When you don’t want to know the Prefix, you should call this
%     predicate, because it doesn’t construct the Prefix argument,
%     which `append_length/4` would do.
%
%     @param Suffix list
%     @param List list
%     @param Length integer



%!    prefix_length(?List, ?Prefix, ?Length)
%
%     is true when
%     ```
%         prefix(List, Prefix) &
%         length(Prefix, Length).
%     ```
%     The normal use of this is to find the first Length elements of
%     a given List, but it can be used any way around provided that
%      Length is instantiated, or
%      Prefix is a proper list, or
%      List is a proper list.
%     It is identical in effect to `append_length(Prefix, _, List, Length)`.
%
%     @param List list
%     @param Prefix list
%     @param Length integer



%!    proper_prefix_length(?List, ?Prefix, ?Length)
%
%     is true when
%
%     ```
%         proper_prefix(List, Prefix) &
%         length(Prefix, Length).
%     ```
%     The normal use of this is to find the first Length elements of
%     a given List, but it can be used any way around provided that
%      Length is instantiated, or
%      Prefix is a proper list, or
%      List is a proper list.
%     It is logically equivalent to `prefix(Prefix, List, Length), Length > 0`.
%
%     @param List list
%     @param Prefix list
%     @param Length integer



%!    suffix_length(+List, ?Suffix, ?Length)
%
%     is true when
%
%     ```
%         suffix(List, Suffix) &
%         length(Suffix, Length).
%     ```
%     The normal use of this is to return the last Length elements of
%     a given List. For this to be sure of termination,
%      List must be a proper list.
%     The predicate suffix/2 has the same requirement.
%     If Length is instantiated or Suffix is a proper list, this predicate
%     is determinate.
%
%     @param List +list
%     @param Suffix list
%     @param Length integer



%!    proper_suffix_length(+List, ?Suffix, ?Length)
%
%     is true when
%
%     ```
%         proper_suffix(List, Suffix) &
%         length(Suffix, Length).
%     ```
%     The normal use of this is to return the last Length elements of
%     a given List. For this to be sure of termination,
%      List must be a proper list.
%     The predicate proper_suffix/2 has the same requirement.
%     If Length is instantiated or Suffix is a proper list, this predicate
%     is determinate.
%
%     @param List +list
%     @param Suffix list
%     @param Length integer



%!    rotate_list(+Amount, ?List, ?Rotated)
%
%     is true when List and Rotated are lists of the same length, and
%
%     ```
%         append(Prefix, Suffix, List) &
%         append(Suffix, Prefix, Rotated) &
%         (   Amount >= 0 & length(Prefix, Amount)
%         |   Amount =< 0 & length(Suffix, Amount)
%         ).
%     ```
%     That is to say, List rotated LEFT by Amount is Rotated.
%     If either List or Rotated is bound to a proper
%     list, rotate_list is determinate.
%
%     @param Amount +integer
%     @param List list
%     @param Rotated list



%!    rotate_list(?List, ?Rotated)
%
%     is true when `rotate_list(1, List, Rotated)`, but is a bit less
%     heavy-handed.
%     `rotate_list(X, Y)` rotates X left one place yielding Y.
%     `rotate_list(Y, X)` rotates X right one place yielding Y.
%     Either List or Rotated should be a proper list,
%     in which case rotate_list is determinate and terminating.
%
%     @param List list
%     @param Rotated list



%!    sublist(+Whole, ?Part, ?Before, ?Length, ?After)
%
%     is true when
%
%     * Whole is a list – it must be proper already
%     * Part is a list
%     * Whole = Alpha || Part || Omega
%     * `length(Alpha, Before)`
%     * `length(Part, Length)`
%     * `length(Omega, After)`
%
%     @param Whole +list
%     @param Part list
%     @param Before integer
%     @param Length integer
%     @param After integer



%!    sublist(+Whole, ?Part, ?Before, ?Length)
%
%     is true when
%
%     * Whole is a list – it must be proper already
%     * Part is a list
%     * Whole = Alpha || Part || Omega
%     * `length(Alpha, Before)`
%     * `length(Part, Length)`
%
%     @param Whole +list
%     @param Part list
%     @param Before integer
%     @param Length integer



%!    sublist(+Whole, ?Part, ?Before)
%
%     is true when
%
%     * Whole is a list – it must be proper already
%     * Part is a list
%     * Whole = Alpha || Part || Omega
%     * `length(Alpha, Before)`
%
%     @param Whole +list
%     @param Part list
%     @param Before integer



%!    cons(?Head, ?Tail, ?List)
%
%     is true when Head is the head of List and Tail is its tail.
%     i.e. `append([Head], Tail, List)`. No restrictions.
%
%     @param Head term
%     @param Tail list
%     @param List list



%!    last(?Fore, ?Last, ?List)
%
%     is true when Last is the last element of List and Fore is the
%     list of preceding elements, e.g. `append(Fore, [Last], List)`.
%     Fore or Last should be proper. It is expected that List will
%     be proper and Fore unbound, but it will work in reverse too.
%
%     @param Fore list
%     @param Last term
%     @param List list



%!    head(?List, ?Head)
%
%     is true when List is a non-empty list and Head is its head.
%     A list has only one head. No restrictions.
%
%     @param List list
%     @param Head term



%!    tail(?List, ?Tail)
%
%     is true when List is a non-empty list and Tail is its tail.
%     A list has only one tail. No restrictions.
%
%     @param List list
%     @param Tail list



%!    prefix(?List, ?Prefix)
%
%     is true when List and Prefix are lists and Prefix is a prefix of List.
%     It terminates if either argument is proper, and has at most N+1 solutions.
%     Prefixes are enumerated in ascending order of length.
%
%     @param List list
%     @param Prefix list



%!    proper_prefix(?List, ?Prefix)
%
%     is true when List and Prefix are lists and Prefix is a proper prefix
%     of List. That is, Prefix is a prefix of List but is not List itself.
%     It terminates if either argument is proper, and has at most N solutions.
%     Prefixes are enumerated in ascending order of length.
%
%     @param List list
%     @param Prefix list



%!    suffix(?List, ?Suffix)
%
%     is true when List and Suffix are lists and Suffix is a suffix of List.
%     It terminates only if List is proper, and has at most N+1 solutions.
%     Suffixes are enumerated in descending order of length.
%
%     @param List list
%     @param Suffix list



%!    proper_suffix(?List, ?Suffix)
%
%     is true when List and Suffix are lists and Suffix is a proper suffix
%     of List. That is, Suffix is a suffix of List but is not List itself.
%     It terminates only if List is proper, and has at most N solutions.
%     Suffixes are enumerated in descending order of length.
%
%     @param List list
%     @param Suffix list



%!    segment(?List, ?Segment)
%
%     is true when List and Segment are lists and Segment is a segment
%     of List. That is, List = _ <> Segment <> _ .
%     Terminates only if List is proper. If Segment is proper
%     it enumerates all solutions. If neither argument is proper, it
%     would have to diagonalize to find all solutions, but it doesn’t, so
%     it is then incomplete. If Segment is proper, it has at most N+1
%     solutions. Otherwise, it has at most (1/2)(N+1)(N+2) solutions.
%
%     @param List list
%     @param Segment list



%!    proper_segment(?List, ?Segment)
%
%     is true when List and Segment are lists and Segment is a proper
%     segment of List. It terminates only if List is proper. The only
%     solution of `segment/2` which is not a solution of `proper_segment/2`
%     is `segment(List,List)`. So `proper_segment/2` has one solution fewer.
%
%     @param List list
%     @param Segment list



%!    cumlist(:Pred, +[X1,...,Xn], ?V0, ?[V1,...,Vn])
%
%     `cumlist/4` maps a ternary predicate Pred down the list [X1,...,Xn] just as
%     `scanlist/4` does, and returns a list of the results. It terminates
%     when the lists runs out. If Pred is bidirectional, it may be
%     used to derive [X1...Xn] from V0 and [V1...Vn], e.g.
%     `cumlist(plus, [1,2,3,4], 0, /* -> */ [1,3,6,10])` and
%     `cumlist(plus, [1,1,1,1], /* <- */ 0, [1,2,3,4])`.
%     Could be defined as:
%
%     ```
%     cumlist(Pred, Xs, V0, Cum) :-
%         (   foreach(X,Xs),
%             foreach(V,Cum),
%             fromto(V0,V1,V,_),
%             param(Pred)
%         do  call(Pred,X,V1,V)
%         ).
%     cumlist(Pred, Xs, Ys, V0, Cum) :-
%         (   foreach(X,Xs),
%             foreach(Y,Ys),
%             foreach(V,Cum),
%             fromto(V0,V1,V,_),
%             param(Pred)
%         do  call(Pred,X,Y,V1,V)
%         ).
%     cumlist(Pred, Xs, Ys, Zs, V0, Cum) :-
%         (   foreach(X,Xs),
%             foreach(Y,Ys),
%             foreach(Z,Zs),
%             foreach(V,Cum),
%             fromto(V0,V1,V,_),
%             param(Pred)
%         do  call(Pred,X,Y,Z,V1,V)
%         ).
%     ```
%
%     @param Pred callable
%     @param X1...Xn list
%     @param V0 term
%     @param V1...Vn list



%!    cumlist(:Pred, +[X1,...,Xn], +[Y1,...,Yn], ?V0, ?[V1,...,Vn])
%
%     @param Pred callable
%     @param X1...Xn list
%     @param Y1...Yn list
%     @param V0 term
%     @param V1...Vn list



%!    cumlist(:Pred, +[X1,...,Xn], +[Y1,...,Yn], +[Z1,...,Zn], ?V0, ?[V1,...,Vn])
%
%     @param Pred callable
%     @param X1...Xn list
%     @param Y1...Yn list
%     @param Z1...Zn list
%     @param V0 term
%     @param V1...Vn list



%!    maplist(:Pred, +List)
%
%     succeeds when Pred(X) succeeds for each element X of List.
%     List should be a proper list.
%     Could be defined as:
%
%     ```
%     maplist(Pred, Xs) :-
%         (   foreach(X,Xs),
%             param(Pred)
%         do  call(Pred, X)
%         ).
%     ```
%
%     @param Pred callable
%     @param List +list



%!    maplist(:Pred, +OldList, ?NewList)
%
%     succeeds when Pred(Old,New) succeeds for each corresponding
%     Old in OldList, New in NewList.
%     Either OldList or NewList should be a proper list.
%     Could be defined as:
%
%     ```
%     maplist(Pred, Xs, Ys) :-
%         (   foreach(X,Xs),
%             foreach(Y,Ys),
%             param(Pred)
%         do  call(Pred, X, Y)
%         ).
%     ```
%
%     @param Pred callable
%     @param OldList +list
%     @param NewList list



%!    maplist(:Pred, +Xs, ?Ys, ?Zs)
%
%     is true when Xs, Ys, and Zs are lists of equal length, and
%     Pred(X, Y, Z) is true for corresponding elements X of Xs,
%     Y of Ys, and Z of Zs.
%     At least one of Xs, Ys, and Zs should be a proper list.
%     Could be defined as:
%
%     ```
%     maplist(Pred, Xs, Ys, Zs) :-
%         (   foreach(X,Xs),
%             foreach(Y,Ys),
%             foreach(Z,Zs),
%             param(Pred)
%         do  call(Pred, X, Y, Z)
%         ).
%     ```
%
%     @param Pred callable
%     @param Xs +list
%     @param Ys list
%     @param Zs list



%!    map_product(Pred, Xs, Ys, PredOfProduct)
%
%     Just as `maplist(P, Xs, L)` is the analogue of Miranda’s
%
%     ```
%         let L = [ P x | x <- Xs ]
%     ```
%     so `map_product(P, Xs, Ys, L)` is the analogue of Miranda’s
%
%     ```
%         let L = [ P x y | x <- Xs; y <- Ys ]
%     ```
%     That is, if Xs = [X1,...,Xm], Ys = [Y1,...,Yn], and P(Xi,Yj,Zij),
%     L = [Z11,...,Z1n,Z21,...,Z2n,...,Zm1,...,Zmn].
%     It is as if we formed the Cartesian product of Xs and Ys and
%     applied P to the (Xi,Yj) pairs.
%     Xs and Ys should be proper lists.
%     Could be defined as:
%
%     ```
%     map_product(Pred, Xs, Ys, Zs) :-
%         (   foreach(X,Xs),
%             fromto(Zs,S0,S,[]),
%             param([Ys,Pred])
%         do  (   foreach(Y,Ys),
%                 fromto(S0,[Z|S1],S1,S),
%                 param([X,Pred])
%             do  call(Pred, X, Y, Z)
%             )
%         ).
%     ```
%
%     @param Pred callable
%     @param Xs list
%     @param Ys list
%     @param PredOfProduct list



%!    scanlist(:Pred, [X1,...,Xn], ?V1, ?V)
%
%     `scanlist/4` maps a ternary relation Pred down a list. The computation is
%     Pred(X1,V1,V2), Pred(X2,V2,V3), ..., Pred(Xn,Vn,V)
%     So if Pred is `plus/3`, `scanlist(plus, [X1,...,Xn], 0, V)` puts the
%     sum of the list elements in V.
%     Note that the order of the arguments passed to Pred is the same
%     as the order of the arguments following Pred. This also holds
%     for scanlist/5 and scanlist/6, e.g.
%     scanlist(Pred, Xs, Ys, Zs, V1, V) calls Pred(X3,Y3,Z3,V3,V4).
%     Could be defined as:
%
%     ```
%     scanlist(Pred, Xs, V0, V) :-
%         (   foreach(X,Xs),
%             fromto(V0,V1,V2,V),
%             param(Pred)
%         do  call(Pred, X, V1, V2)
%         ).
%     scanlist(Pred, Xs, Ys, V0, V) :-
%         (   foreach(X,Xs),
%             foreach(Y,Ys),
%             fromto(V0,V1,V2,V),
%             param(Pred)
%         do  call(Pred, X, Y, V1, V2)
%         ).
%     scanlist(Pred, Xs, Ys, Zs, V0, V) :-
%         (   foreach(X,Xs),
%             foreach(Y,Ys),
%             foreach(Z,Zs),
%             fromto(V0,V1,V2,V),
%             param(Pred)
%         do  call(Pred, X, Y, Z, V1, V2)
%         ).
%     ```
%
%     @param Pred callable
%     @param X1...Xn list
%     @param V1 term
%     @param V term



%!    scanlist(:Pred, +[X1,...,Xn], +[Y1,...,Yn], ?V1, ?V)
%
%     @param Pred callable
%     @param X1...Xn list
%     @param Y1...Yn list
%     @param V1 term
%     @param V term



%!    scanlist(:Pred, +[X1,...,Xn], +[Y1,...,Yn], +[Z1,...,Zn], ?V1, ?V)
%
%     @param Pred callable
%     @param X1...Xn list
%     @param Y1...Yn list
%     @param Z1...Zn list
%     @param V1 term
%     @param V term



%!    some(:Pred, +List)
%
%     succeeds when Pred(Elem) succeeds for some Elem in List. It will
%     try all ways of proving Pred for each Elem, and will try each Elem
%     in the List. `somechk/2` is to `some/2` as `memberchk/2` is to `member/2`.
%
%     ```
%         member(X,L)     <-> some(=(X), L).
%         memberchk(X, L) <-> somechk(=(X), L).
%         some(Pred,L)    <-> member(X, L), call(Pred,X).
%     ```
%     This acts on backtracking like member/2; List should be a proper list.
%
%     @param Pred callable
%     @param List +list



%!    some(:Pred, +[X1,...,Xn], ?[Y1,...,Yn])
%
%     is true when Pred(Xi, Yi) is true for some i.
%
%     @param Pred callable
%     @param X1...Xn +list
%     @param Y1...Yn list



%!    some(:Pred, +[X1,...,Xn], ?[Y1,...,Yn], ?[Z1,...,Zn])
%
%     is true when Pred(Xi, Yi, Zi) is true for some i.
%
%     @param Pred callable
%     @param X1...Xn +list
%     @param Y1...Yn list
%     @param Z1...Zn list



%!    somechk(:Pred, +[X1,...,Xn])
%
%     is true when Pred(Xi) is true for some i, and it commits to
%     the first solution it finds (like `memberchk/2`).
%
%     @param Pred callable
%     @param X1...Xn +list



%!    somechk(:Pred, +[X1,...,Xn], ?[Y1,...,Yn])
%
%     is true when Pred(Xi, Yi) is true for some i, and it commits to
%     the first solution it finds (like `memberchk/2`).
%
%     @param Pred callable
%     @param X1...Xn +list
%     @param Y1...Yn list



%!    somechk(:Pred, +[X1,...,Xn], ?[Y1,...,Yn], ?[Z1,...,Zn])
%
%     is true when Pred(Xi, Yi, Zn) is true for some i, and it commits to
%     the first solution it finds (like `memberchk/2`).
%
%     @param Pred callable
%     @param X1...Xn +list
%     @param Y1...Yn list
%     @param Z1...Zn list



%!    convlist(:Rewrite, +OldList, ?NewList)
%
%     is a sort of hybrid of `maplist/3` and `include/3`.
%     Each element of NewList is the image under Rewrite of some
%     element of OldList, and order is preserved, but elements of
%     OldList on which Rewrite is undefined (fails) are not represented.
%     Thus if `foo(K,X,Y) :- integer(X), Y is X+K.`
%     then `convlist(foo(1), [1,a,0,joe(99),101], [2,1,102]).`
%     OldList should be a proper list.
%     Could be defined as:
%
%     ```
%     convlist(Pred, Xs, News) :-
%         (   foreach(X,Xs),
%             fromto(News,S0,S,[]),
%             param(Pred)
%         do  (call(Pred,X,N) -> S0 = [N|S] ; S0 = S)
%         ).
%     ```
%
%     @param Rewrite callable
%     @param OldList +list
%     @param NewList list



%!    exclude(:Pred, +Xs, ?SubList)
%
%     succeeds when SubList is the sublist of Xs containing all the
%     elements Xi[,Yi[,Zi]] for which Pred(Xi[,Yi[,Zi]]) is *false*. That is, it removes
%     all the elements satisfying Pred.
%     Xs, Ys or Zs should be a proper list.
%     Could be defined as:
%
%     ```
%     exclude(Pred, Xs, News) :-
%         (   foreach(X,Xs),
%             fromto(News,S0,S,[]),
%             param(Pred)
%         do  (call(Pred,X) -> S0 = S ; S0 = [X|S])
%         ).
%     exclude(Pred, Xs, Ys, News) :-
%         (   foreach(X,Xs),
%             foreach(Y,Ys),
%             fromto(News,S0,S,[]),
%             param(Pred)
%         do  (call(Pred,X,Y) -> S0 = S ; S0 = [X|S])
%         ).
%     exclude(Pred, Xs, Ys, Zs, News) :-
%         (   foreach(X,Xs),
%             foreach(Y,Ys),
%             foreach(Z,Zs),
%             fromto(News,S0,S,[]),
%             param(Pred)
%         do  (call(Pred,X,Y,Z) -> S0 = S ; S0 = [X|S])
%         ).
%     ```
%
%     @param Pred callable
%     @param Xs +list
%     @param SubList list



%!    exclude(:Pred, +Xs, +Ys, ?SubList)
%
%     @param Pred callable
%     @param Xs +list
%     @param Ys +list
%     @param SubList list



%!    exclude(:Pred, +Xs, +Ys, +Zs, ?SubList)
%
%     @param Pred callable
%     @param Xs +list
%     @param Ys +list
%     @param Zs +list
%     @param SubList list



%!    include(:Pred, +Xs, ?SubList)
%
%     succeeds when SubList is the sublist of Xs containing all the
%     elements Xi[,Yi[,Zi]] for which Pred(Xi[,Yi[,Zi]]) is *true*. That is, it retains
%     all the elements satisfying Pred.
%     Xs, Ys or Zs should be a proper list.
%     Could be defined as:
%
%     ```
%     include(Pred, Xs, News) :-
%        (   foreach(X,Xs),
%            fromto(News,S0,S,[]),
%             param(Pred)
%         do  (call(Pred,X) -> S0 = [X|S] ; S0 = S)
%         ).
%     include(Pred, Xs, News) :-
%         (   foreach(X,Xs),
%             fromto(News,S0,S,[]),
%             param(Pred)
%         do  (call(Pred,X) -> S0 = [X|S] ; S0 = S)
%         ).
%     include(Pred, Xs, Ys, News) :-
%         (   foreach(X,Xs),
%             foreach(Y,Ys),
%             fromto(News,S0,S,[]),
%             param(Pred)
%         do  (call(Pred,X,Y) -> S0 = [X|S] ; S0 = S)
%         ).
%     include(Pred, Xs, Ys, Zs, News) :-
%         (   foreach(X,Xs),
%             foreach(Y,Ys),
%             foreach(Z,Zs),
%             fromto(News,S0,S,[]),
%             param(Pred)
%         do  (call(Pred,X,Y,Z) -> S0 = [X|S] ; S0 = S)
%         ).
%     ```
%
%     @param Pred callable
%     @param Xs +list
%     @param SubList list



%!    include(:Pred, +Xs, +Ys, ?SubList)
%
%     @param Pred callable
%     @param Xs +list
%     @param Ys +list
%     @param SubList list



%!    include(:Pred, +Xs, +Ys, +Zs, ?SubList)
%
%     @param Pred callable
%     @param Xs +list
%     @param Ys +list
%     @param Zs +list
%     @param SubList list



%!    partition(:Pred, +List, ?Less, ?Equal, ?Greater)
%
%     is a relative of `include/3` and `exclude/3` which has some pretensions
%     to being logical. For each X in List, we call Pred(X,R), and route
%     X to Less, Equal, or Greater according as R is `<`, `=`, or `>` .
%
%     @param Pred callable
%     @param List +list
%     @param Less list
%     @param Equal list
%     @param Greater list



%!    group(:Pred, +List, ?Front, ?Back)
%
%     is true when `append(Front, Back, List), maplist(Pred, Front)`,
%     and Front is as long as possible.
%
%     @param Pred callable
%     @param List +list
%     @param Front list
%     @param Back list



%!    group(:Pred, +Key, +List, ?Front, ?Back)
%
%     is true when `append(Front, Back, List), maplist(call(Pred,Key), Front)`,
%     and Front is as long as possible. Strictly speaking we don’t need it;
%     `group(call(Pred,Key), List, Front, Back)` would do just as well.
%
%     @param Pred callable
%     @param Key +term
%     @param List +list
%     @param Front list
%     @param Back list



%!    group(:Pred, +List, ?ListOfLists)
%
%     is true when `append(ListOfLists, List)`, each element of ListOfLists
%     has the form [Head|Tail] such that `group(Pred, Head, Tail, Tail, [])`,
%     and each element of ListOfLists is as long as possible. For example,
%     if you have a keysorted list, and define `same_key(K-_, K-_)`, then
%     `group(same_key, List, Buckets)` will divide List up into Buckets of
%     pairs having the same key.
%
%     @param Pred callable
%     @param List +list
%     @param ListOfLists list



%!    ordered(+List)
%
%     is true when List is a list of terms [T1,T2,...,Tn] such that
%     for all k in 2..n Tk-1 `@=<` Tk, i.e. T1 `@=<` T2 `@=<` T3 ...
%     The output of `keysort/2` is always ordered, and so is that of
%     `sort/2`. Beware: just because a list is ordered does not mean
%     that it is the representation of an ordered set; it might contain
%     duplicates.
%
%     @param List +list



%!    ordered(+P, +[T1,T2,...,Tn])
%
%     is true when P(T1,T2) & P(T2,T3) & ... That is, if you take
%     P as a "comparison" predicate like `@=<`, the list is ordered.
%     This is good for generating prefixes of sequences,
%     e.g. `L = [1,_,_,_,_], ordered(times(2), L)` yields `L = [1,2,4,8,16]`.
%
%     @param P callable
%     @param T1-Tn +list



%!    max_member(?Xmax, +[X1,...,Xn])
%
%     unifies Xmax with the maximum (in the sense of `@=<`) of X1,...,Xn.
%     The list should be proper. If it is empty, the predicate fails quietly.
%     Could be defined as:
%
%     ```
%     max_member(Maximum, [Head|Tail]) :-
%         (   foreach(X,Tail),
%             fromto(Head,M0,M,Maximum)
%         do  (X@=<M0 -> M = M0 ; M = X)
%         ).
%     ```
%
%     @param Xmax term
%     @param X1-Xn +list



%!    min_member(?Xmin, +[X1,...,Xn])
%
%     unifies Xmin with the minimum (in the sense of `@=<`) of X1,...,Xn.
%     The list should be proper. If it is empty, the predicate fails quietly.
%     Could be defined as:
%
%     ```
%     min_member(Minimum, [Head|Tail]) :-
%         (   foreach(X,Tail),
%             fromto(Head,M0,M,Minimum)
%         do  (M0@=<X -> M = M0 ; M = X)
%         ).
%     ```
%
%     @param Xmin term
%     @param X1-Xn +list



%!    max_member(:P, ?Xmax, +[X1,...,Xn])
%
%     unifies Xmax with the maximum element of [X1,...,Xn], as defined
%     by the comparison predicate P, which should act like `@=<` .
%     The list should be proper. If it is empty, the predicate fails quietly.
%     Could be defined as:
%
%     ```
%     max_member(Pred, Maximum, [Head|Tail]) :-
%         (   foreach(X,Tail),
%             fromto(Head,M0,M,Maximum),
%             param(Pred)
%         do  (call(Pred,X,M0) -> M = M0 ; M = X)
%        ).
%     ```
%
%     @param P callable
%     @param Xmax term
%     @param X1-Xn +list



%!    min_member(:P, ?Xmin, +[X1,...,Xn])
%
%     unifies Xmin with the minimum element of [X1,...,Xn], as defined
%     by the comparison predicate P, which should act like `@=<` .
%     The list should be proper. If it is empty, the predicate fails quietly.
%     Could be defined as:
%
%     ```
%     min_member(Pred, Minimum, [Head|Tail]) :-
%         (   foreach(X,Tail),
%             fromto(Head,M0,M,Minimum),
%             param(Pred)
%         do  (call(Pred,M0,X) -> M = M0 ; M = X)
%         ).
%     ```
%
%     @param P callable
%     @param Xmin term
%     @param X1-Xn +list



%!    select_min(?Element, +Set, ?Residue)
%
%     unifies Element with the smallest (in the sense of `@=<`) element
%     of Set, and Residue with a list of all the other elements.
%
%     @param Element term
%     @param Set +list
%     @param Residue list



%!    select_min(:Pred, ?Element, +Set, ?Residue)
%
%     find the least Element of Set, i.e. Pred(Element,X) for all X in Set.
%
%     @param Pred callable
%     @param Element term
%     @param Set +list
%     @param Residue list



%!    select_max(?Element, +Set, ?Residue)
%
%     unifies Element with the (leftmost) maximum element of the Set,
%     and Residue to the other elements in the same order.
%
%     @param Element term
%     @param Set +list
%     @param Residue list



%!    select_max(:Pred, ?Element, +Set, ?Residue)
%
%     find the greatest Element of Set, i.e. Pred(X,Element) for all X in Set.
%
%     @param Pred callable
%     @param Element term
%     @param Set +list
%     @param Residue list



%!    increasing_prefix(?Sequence, ?Prefix, ?Suffix)
%
%     is true when `append(Prefix, Suffix, Sequence)`
%     and Prefix, together with the first element of Suffix,
%     forms a monotone non-decreasing sequence, and
%     no longer Prefix will do. Pictorially,
%
%     ```
%     Sequence = [x1,...,xm,xm+1,...,xn]
%     Prefix   = [x1,...,xm]
%     Suffix     = [xm+1,...,xn]
%     x1 @=< x2 @=< ... @=< xm @=< xm+1
%     not xm+1 @=< xm+2
%     ```
%     This is perhaps a surprising definition; you might expect
%     that the first element of Suffix would be included in Prefix.
%     However, this way, it means that if Sequence is a strictly
%     decreasing sequence, the Prefix will come out empty.
%
%     @param Sequence list
%     @param Prefix list
%     @param Suffix list



%!    increasing_prefix(:Order, ?Sequence, ?Prefix, ?Suffix)
%
%     is the same as `increasing_prefix/3`, except that it uses the
%     binary relation Order in place of `@=<`.
%
%     @param Order callable
%     @param Sequence list
%     @param Prefix list
%     @param Suffix list



%!    decreasing_prefix(?Sequence, ?Prefix, ?Suffix)
%
%     is the same, except it looks for a decreasing prefix.
%     The order is the converse of the given order. That
%     is, where `increasing_prefix/[3,4]` check X(R)Y, these
%     routines check Y(R)X.
%
%     @param Sequence list
%     @param Prefix list
%     @param Suffix list



%!    decreasing_prefix(:Order, ?Sequence, ?Prefix, ?Suffix)
%
%     is the same, except it looks for a decreasing prefix.
%     The order is the converse of the given order. That
%     is, where `increasing_prefix/[3,4]` check X(R)Y, these
%     routines check Y(R)X.
%
%     @param Order callable
%     @param Sequence list
%     @param Prefix list
%     @param Suffix list



%!    clumps(+Items, -Clumps)
%
%     is true when Clumps is a list of lists such that
%
%     * `append(Clumps, Items)`
%     * for each Clump in Clumps, all the elements of Clump are identical (`==`)
%
%     Items must be a proper list of terms for which sorting would have been
%     sound. In fact, it usually is the result of sorting.
%
%     @param Items +list
%     @param Clumps -list_of_lists



%!    keyclumps(+Pairs, ?Clumps)
%
%     is true when Pairs is a list of pairs and Clumps a list of lists such that
%
%     * `append(Clumps, Pairs)`
%     * for each Clump in Clumps, all of the Key-Value pairs in Clump have
%     identical (`==`) Keys.
%
%     Pairs must be a proper list of pairs for which keysorting would have
%     been sound. In fact, it usually is the result of keysorting.
%
%     @param Pairs +list_of_pairs
%     @param Clumps list_of_lists



%!    clumped(+Items, ?Counts)
%
%     is true when Counts is a list of Item-Count pairs such that
%     if `clumps(Items, Clumps)`, then each Item-Count pair in Counts corresponds
%     to an element [Item/*1*/,...,Item/*Count*/] of Clumps.
%     Items must be a proper list of terms for which sorting would have been
%     sound. In fact, it usually is the result of sorting.
%
%     @param Items +list
%     @param Counts list_of_pairs



%!    keyclumped(+Pairs, ?Groups)
%
%     is true when Pairs is a list of Key-Item pairs and
%     Groups is a list of Key-Items pairs such that
%     if `keyclumps(Pairs, Clumps)`, then for each K-[I1,...,In] pair in Groups
%     there is a [K-I1,...,K-In] clump in Clumps.
%     Pairs must be a proper list of pairs for which keysorting would have
%     been sound. In fact, it usually is the result of keysorting.
%
%     @param Pairs +list_of_pairs
%     @param Groups list_of_pairs
