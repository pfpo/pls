
:- use_module('shapes.pl').


% We want to calculate the length of the list using the builtin predicate length
% However we have forgotten the order of the arguments....
% Type `(` after  `length` and see the signature help that shows you which parameter you are currently 
% inserting

main:- 
	Shapes = [rectangle(1,2), circle(2), square(3)],
	length
	, write('List length is : '), write(Len)
	.