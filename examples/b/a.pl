
:- consult('b.pl').

:- consult('commented_prolog_cliques_distinct.pl').

:- ,cliques_distinct(StatisticsFile,TimeoutMinutes,Tests).