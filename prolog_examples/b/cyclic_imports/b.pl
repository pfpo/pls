
:- consult('c.pl').


%!   renamed_func(+T)
%
%     Prints T This Predicate was defined in `b.pl`
%
%     @param T  The term to be printed
renamed_func(T):- loggi(T) , 

.