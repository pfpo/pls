
% Click on the log predicate and then use the code action
% `Generate pldoc tempalte
% Then try changing the documentation to reflect the predicate's functionality
% And then hover any of the predicate's usage to see its documentation

main:- 
	log('Main Function') .


log(T):- write('LOG: '), write(T), nl.


