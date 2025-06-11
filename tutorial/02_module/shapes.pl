
%! rectangle(?Width,?Height)
%
%  rectangle `Shape` 
%
% @param ?Width  width
% @param ?Height  height
rectangle(_Width,_Height).

%! square(?Size)
%
%  square `Shape` 
%
% @param ?Size size
square(_Size).

%! circle(?Radius)
%
%  circle `Shape` 
%
% @param ?Radius radius

circle(_Radius).

%!  area(+Shape,-Area)
%
%   Calculates the Area of a `Shape`
%
% @param +Shape A `Shape` that is either a *square*, *cicle* or *rectangle*
% @param -Area  the shape's area
area(rectangle(Width,Height),Area):- Area is Width * Height.
area(square(Size),Area):- Area is Size * Size.
area(circle(Radius),Area) :- Area is Radius * Radius * 3.14.


%!  perim(+Shape,-Perimeter)
%
%   Calculates the perimeter of a `Shape`
%
% @param +Shape A `Shape` that is either a *square*, *cicle* or *rectangle*
% @param -Area  the shape's perimeter
perim(rectangle(Width,Height),Area):- Area is 2*Width + 2*Height.
perim(square(Size),Area):- Area is 4 * Size.
perim(circle(Radius),Area) :- Area is Radius * 3.14 * 2.


%!  type(?Shape,?Type)
%
%   The type of the shape
%
% @param +Shape A `Shape` that is either a *square*, *cicle* or *rectangle*
% @param ?Type the shape's type:  rectangle  square  circle

type(rectangle(_,_),rectangle).
type(square(_),square).
type(circle(_),circle).


%!  log_shape(?Shape)
%
%   Pretty Prints the shape with information
%
% @param ?Shape  A `Shape` that is either a *square*, *cicle* or *rectangle*

log_shape(Shape):- 
		type(Shape,Type),
		area(Shape,Area),
		perim(Shape,Perim),
		write('Shape is a '),write(Type),nl,
		write('Area: '),write(Area),nl,
		write('Primeter: '),write(Perim)
		.


%!  log_all_shapes(?Shapes)
%
%  Pretty Prints a list of shapes
%
% @param ?Shapes  is a list of `Shape`
log_all_shapes([]).
log_all_shapes([Shape|Shapes]):- log_shape(Shape),nl,log_all_shapes(Shapes).


