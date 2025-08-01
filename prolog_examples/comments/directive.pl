%!    :- block +BlockSpec
%
%     Specifies conditions
%     for blocking goals of the predicates referred to by BlockSpec.
%
%     @param  :BlockSpec   *callable*, must be ground
%     Goal template or list of goal templates, of the form
%     `f(Arg1, Arg2,...)`.
%     Each Argn is one of:
%     '`-`'
%     part of a block condition
%     '`?`'
%     otherwise
