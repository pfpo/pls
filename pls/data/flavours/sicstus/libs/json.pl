:- module(json,[is_json_term/1, json_to_atom/3,
 json_to_atom/2, json_read/2, json_write/3,
 json_from_atom/2, json_from_codes/2, json_to_codes/3,
 is_json_term/2, json_read/3, json_from_codes/3,
 json_from_atom/3, json_to_codes/2, json_write/2]).

%! json_read(+Stream, -Term)
%! json_read(+Stream, -Term, +Options)
%
% Reads a single JSON value from the text stream Stream and unifies it with Term.
%
% @param Stream stream_object, must be ground
% @param Term term
% @param Options list of term
% The Options argument is described in the module documentation.

%! json_write(+Stream, +Term)
%! json_write(+Stream, +Term, +Options)
%
% Write the JSON value Term to the text stream Stream.
%
% @param Stream stream_object, must be ground
% A valid open Prolog stream, defaults to the current output stream.
% @param Term term
% @param Options list of term
% The Options argument is described in the module documentation.

%! is_json_term(+Term)
%! is_json_term(+Term, +Options)
%
% True if the Term is a valid representation of a JSON value.
%
% @param Term term
% @param Options list of term
% The Options argument is described in the module documentation.

%! json_to_codes(+Term, -JSONCodes)
%! json_to_codes(+Term, -JSONCodes, +Options)
%
% Writes Term as JSON and unifies JSONCodes with the list of resulting character codes.
%
% @param Term term
% @param JSONCodes list of codes
% @param Options list of term
% The Options argument is described in the module documentation.

%! json_to_atom(+Term, -JSONAtom)
%! json_to_atom(+Term, -JSONAtom, +Options)
%
% Writes Term as JSON and unifies JSONAtom with an atom consisting of the resulting character codes.
%
% @param Term term
% @param JSONAtom atom
% @param Options list of term
% The Options argument is described in the module documentation.

%! json_from_codes(+JSONCodes, -Term)
%! json_from_codes(+JSONCodes, -Term, +Options)
%
% Converts a JSON text, represented as the list of character codes JSONCodes, into the corresponding Prolog term Term.
%
% @param JSONCodes list of codes
% @param Term term
% @param Options list of term
% The Options argument is described in the module documentation.

%! json_from_atom(+JSONAtom, -Term)
%! json_from_atom(+JSONAtom, -Term, +Options)
%
% Converts a JSON text, represented as the character codes of JSONAtom, into the corresponding Prolog term Term.
%
% A small example:
% ```
% | ?- use_module(library(json)).
% ...
% | ?- JSONCodes = "{\"foo\": 42, \"bar\": null}",
%      json_from_codes(JSONCodes, JSONTerm),
%      json_to_atom(JSONTerm, JSONAtom, [compact(true)]).
% JSONCodes = [123,34,102,111,111,34,58,32,52,50|...],
% JSONTerm = json([foo=42,bar= @(null)]),
% JSONAtom = '{"foo":42,"bar":null}' ?
% yes
% | ?-
% ```
%
% @param JSONAtom atom
% @param Term term
% @param Options list of term
% The Options argument is described in the module documentation.
