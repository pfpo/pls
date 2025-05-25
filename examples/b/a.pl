
:- consult('b.pl').

:- consult('commented_prolog_cliques_distinct.pl').

main:- b_funci(A,B)
		,find_max(arg,arg)
.
