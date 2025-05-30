%! automaton(?Signature, ?SourcesSinks, ?Arcs)
%
% This constraint provides a general way of defining any constraint involving sequences
% whose checker can be expressed by a finite automaton, deterministic or nondeterministic,
% extended with counter operations on its arcs. In the absence of counters, it maintains domain consistency.
% Corresponds to `regular*` in MiniZinc.
%
% @param Signature *list of variable* The signature of the sequence.
% @param SourcesSinks *list of nodespec* The source and sink nodes of the automaton.
% @param Arcs *list of arc* The arcs (transitions) of the automaton.
%
%! automaton(?Sequence, ?Template, ?Signature, ?SourcesSinks, ?Arcs, ?Counters, ?Initial, ?Final)
%
% This constraint provides a general way of defining any constraint involving sequences
% whose checker can be expressed by a finite automaton, deterministic or nondeterministic,
% extended with counter operations on its arcs. In the absence of counters, it maintains domain consistency.
%
% @param Sequence *list of term* The sequence of terms of interest.
% @param Template *term* A template for an item of the sequence.
% @param Signature *list of variable* The signature of the sequence.
% @param SourcesSinks *list of nodespec* The source and sink nodes of the automaton.
% @param Arcs *list of arc* The arcs (transitions) of the automaton.
% @param Counters *list of variable* A list of counter variables, local to the constraint.
% @param Initial *list of intarg* A list of initial values for the counters.
% @param Final *list of intarg* A list of final values for the counters.
%
%! automaton(?Sequence, ?Template, ?Signature, ?SourcesSinks, ?Arcs, ?Counters, ?Initial, ?Final, ?Options)
%
% This constraint provides a general way of defining any constraint involving sequences
% whose checker can be expressed by a finite automaton, deterministic or nondeterministic,
% extended with counter operations on its arcs. In the absence of counters, it maintains domain consistency.
%
% @param Sequence *list of term* The sequence of terms of interest.
% @param Template *term* A template for an item of the sequence.
% @param Signature *list of variable* The signature of the sequence.
% @param SourcesSinks *list of nodespec* The source and sink nodes of the automaton.
% @param Arcs *list of arc* The arcs (transitions) of the automaton.
% @param Counters *list of variable* A list of counter variables, local to the constraint.
% @param Initial *list of intarg* A list of initial values for the counters.
% @param Final *list of intarg* A list of final values for the counters.
% @param Options *list of term* A list of zero or more options.
%
%! inflexion(?N, ?Vars, ?Opt)
%
% Holds if Vars is a list of integer arguments, and N is the number of times that
% the sequence order switches between strictly increasing and strictly decreasing.
% For example, the sequence `[1,1,4,8,8,2,7,1]` switches order three times.
%
% @param N *intarg* The number of inflexions.
% @param Vars *list of integer* The sequence of integers.
% @param Opt *list of term* Options for the automaton constraint.
%
% ``` 
% inflexion(N, Vars, Opt) :-
%         inflexion_signature(Vars, Sign),
%         automaton(Sign, _, Sign,
%                   [source(s),sink(i),sink(j),sink(s)],
%                   [arc(s,1,s      ),
%                    arc(s,2,i      ),
%                    arc(s,0,j      ),
%                    arc(i,1,i      ),
%                    arc(i,2,i      ),
%                    arc(i,0,j,[C+1]),
%                    arc(j,1,j      ),
%                    arc(j,0,j      ),
%                    arc(j,2,i,[C+1])],
%                   [C],[0],[N],Opt).
% ```

%! inflexion_signature(?L, ?Sign)
%
% Maps a sequence of integers L to a signature Sign where the consecutive element
% order is encoded over the alphabet `[0,1,2]`.
%
% @param L *list of integer* The input sequence of integers.
% @param Sign *list of integer* The signature representing the order between consecutive elements.
%
%``` 
% inflexion_signature([], []).
% inflexion_signature([_], []) :- !.
% inflexion_signature([X,Y|Ys], [S|Ss]) :-
%         S in 0..2,
%         X #> Y #<=> S #= 0,
%         X #= Y #<=> S #= 1,
%         X #< Y #<=> S #= 2,
%         inflexion_signature([Y|Ys], Ss).
%``` 

%! regular(?Signature, ?RegularExpression)
%
% Holds if Signature forms a sequence of values that is recognized by the regular expression.
% Maintains domain consistency.
%
% @param Signature *list of integer* A list of integer arguments.
% @param RegularExpression *term* A ground Prolog term describing the regular expression.
%
% Examples:
% ```prolog
% ?- length(L, 4), regular(L, [+({1,2}), +(0), +({1,2})]),
%      labeling([], L).
% L = [1,0,0,1] ? ;
% L = [1,0,0,2] ? ;
% L = [1,0,1,1] ? ;
% L = [1,0,1,2] ? ;
% L = [1,0,2,1] ? ;
% L = [1,0,2,2] ? ;
% L = [1,1,0,1] ? ;
% L = [1,1,0,2] ? ;
% L = [1,2,0,1] ? ;
% L = [1,2,0,2] ? ;
% L = [2,0,0,1] ? ;
% L = [2,0,0,2] ? ;
% L = [2,0,1,1] ? ;
% L = [2,0,1,2] ? ;
% L = [2,0,2,1] ? ;
% L = [2,0,2,2] ? ;
% L = [2,1,0,1] ? ;
% L = [2,1,0,2] ? ;
% L = [2,2,0,1] ? ;
% L = [2,2,0,2] ? ;
%
% ```
%! value_precede_chain(+Values, +Vars)
%
% Holds if for all adjacent pairs v,w in Values,
% either w does not occur in Vars, or v occurs earlier than w in Vars.
%
% @param Values *list of integer* A list of integers.
% @param Vars *list of integer* A list of integer arguments.
%
%! value_precede_chain(+Values, +Vars, +Options)
%
% Holds if for all adjacent pairs v,w in Values,
% either w does not occur in Vars, or v occurs earlier than w in Vars.
%
% @param Values *list of integer* A list of integers.
% @param Vars *list of integer* A list of integer arguments.
% @param Options *list of term* Options for the constraint, e.g., `global(Boolean)`.
%
%! seq_precede_chain(+Vars)
%
% The same as `value_precede_chain`, for Values = `[1,2,...]`.
%
% @param Vars *list of integer* A list of integer arguments.
%
%! seq_precede_chain(+Vars, +Options)
%
% The same as `value_precede_chain`, for Values = `[1,2,...]`.
%
% @param Vars *list of integer* A list of integer arguments.
% @param Options *list of term* Options for the constraint, e.g., `global(Boolean)`.
