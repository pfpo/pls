
% Pls also detects consulted files or modules that don't exist
% Fix this error and then hit `Ctrl+ Click` to navigate to the module
:- use_module('shapes.pl', [
		rectangle/2,circle/1,square/1,
		log_all_shapes/1,

		four_dimensional_shape/4
]).

main:- 
	Shapes = [rectangle(1,2), circle(2), square(3)],
	log_all_shapes(Shapes)
	.