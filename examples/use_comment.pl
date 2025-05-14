

%!    +P -> +Q
%
%     When occurring other than as the first argument of a disjunction operator
%     (`;/2`), this is equivalent to:
%     ```
%     P -> Q ; fail.
%     ```
%
%     @param  :P   *callable*, must be nonvar
%     @param  :Q   *callable*, must be nonvar

%!    :- include +Files
%
%     Literally embed the Prolog clauses and
%     directives in Files into the file being loaded.
%     The file or files will be opened with default options.
%
%     @param  :Files   *file\_spec* or *list of file\_spec*, must be ground
%     A file specification or a list of file specifications;
%     extension optional.
