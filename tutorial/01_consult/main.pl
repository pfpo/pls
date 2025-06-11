
% :- consult('shapes.pl').


main:- 
	Shapes = [rectangle(1,2), circle(2), square(3)],
	log_all_shapes(Shapes)
	.