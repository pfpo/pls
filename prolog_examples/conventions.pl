% good predicate naming
hello_world :- write('Hello').
test_predicate(X) :- X > 0.

% bad predicate naming
helloWorld :- write('Hello').
test_Predicate(X) :- X > 0.

% good variable naming
check(ValidVar) :- ValidVar = 5.
check(_) :- true.

% bad variable naming
check(Bad_Name) :- Bad_Name = 10.