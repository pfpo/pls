%!    :- module(+ModuleName,+PublicPred)
%!    :- module(+ModuleName,+PublicPred,+Options)
%
%     Declares the file in which the declaration appears to be a
%     module file named ModuleName, with public predicates
%     PublicPred. Must appear as the first term in the file.
%
%     @param  ModuleName   *atom*, must be nonvar
%     @param  PublicPred   *list of simple\_pred\_spec*, must be ground
%     List of predicate specifications of the form Name/Arity.
%     @param  Options      *list of term*, must be ground
%     A list of zero or more options of the form:
%     `hidden(Boolean)`
%     Boolean is `false` (the default) or `true`. In the
%     latter case, tracing of the predicates of the module is
%     disabled (although spypoints can be set), and no source
%     information is generated at compile time.
