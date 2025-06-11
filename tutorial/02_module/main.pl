
% Go to ../shapes.pl and trigger the code action `Export all predicates` to transform shapes.pl into a module
:- use_module(shapes).


main:- 
	Shapes = [rectangle(1,2), circle(2), square(3)],
	log_all_shapes(Shapes)
	.