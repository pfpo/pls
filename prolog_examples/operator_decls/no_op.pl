:- module(op,[]).
:- use_module(library(clpfd)).
:- use_module(library(file_systems)).
:- use_module(library(json)).
:- use_module(library(lists)).
:- use_module(library(random)).
:- use_module(library(statistics)).
:- use_module(library(process)).
:- use_module(library(between)).

:- op(1200,xfx,(-->)).
:- op(1200,fx,(:-)).
:- op(1200,fx,(?-)).
:- op(900,fy,(nospy)).
:- op(550,xfy,(:)).

:- op(1150,fx,(attribute)).

:- op(1200,xfx,(--->)).
:- op(1200,xfx,(+:)).
:- op(1200,xfx,(-:)).
:- op(1200,xfx,(+?)).
:- op(1200,xfx,(-?)).
:- op(900,xfx,(iff)).
:- op(490,yfx,(?)).
:- op(400,yfx,(/>)).
:- op(400,yfx,(/<)).
