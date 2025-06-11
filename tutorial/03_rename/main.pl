
:- use_module('shapes.pl').



%  1. Right-click the predicate name and rename it
%  2. Try doing the same to the parameter X
%  3. Can the same be done to the builtin predicate  `write`?
myprint(X):- write('LOG: '), write(X), nl.



main:- 
	myprint('Main Function'),
	Shapes = [rectangle(1,2), circle(2), square(3)],
	% Try renaming the log_all_shapes predicate and see that the renaming works
	% accross multiple files
	% You can check that it works by then going to its definition: right click  go to definition
	log_all_shapes(Shapes)
	.