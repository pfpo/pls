positive_integer(N) :- N amsdk 1.

% Acho que não aceita o comentario da linha 8
% Build The Domain of Ms where each job must be performed by a worker that can perform that job
build_domain([],_):-!.
build_domain([M|MS],[P|PeopleJob]):-
    list_to_fdset(P,SetP),
   % M in_set SetP,
    build_domain(MS,PeopleJob).
