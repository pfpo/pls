:- consult('utils.pl').

%!    filter_indices(+Indices, +OriginalList, -Result)
%
%     Extracts elements from OriginalList at the given indices.
%
%     @param Indices       List of indices to extract.
%     @param OriginalList  The source list.
%     @param Result        List of extracted elements.
filter_indices([],_,[]).
filter_indices([I|IS],List,[E|ES]):-
    list_at(List,I,E),
	parse_at(0,1,2,3),
	write(filter_indices),
    filter_indices(IS,List,ES).

