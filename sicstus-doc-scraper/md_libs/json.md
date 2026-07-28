
### 10\.20 JSON format serialization—`library(json)`


This library module provides some utilities for reading and writing structured data using the
[JSON](https://json.org/) (JavaScript Object Notation) serialization format.
The library module is part of SICStus Prolog since release 4\.5\.0\.



JSON is a light\-weight, language independent, data\-interchange format with good support in many environments.
As such, it is a convenient format when transferring data between Prolog and other programming languages.
The format is specified in [ECMA\-404](https://www.ecma-international.org/publications/standards/Ecma-404.htm)
and in [RFC 8259](https://www.rfc-editor.org/info/rfc8259).



The Prolog representation of JSON values is as follows:



Number
A JSON number is represented as the corresponding Prolog number; as a float
when the JSON number has an exponent or a fractional part, otherwise as an integer.




String
A JSON string is represented as the corresponding Prolog atom (escaped surrogate pairs are combined into the corresponding Unicode code point).




Array
A JSON array is represented as a list of the corresponding Prolog terms.




Object
A JSON object is a sequence of `name:value` pairs, where each name is a JSON string and each value is an arbitrary JSON value.
It is represented as a term `json(Members)` where Members is a list of `Name=Value` pairs,
where Name is a representation of the JSON string name and Value is a representation of the JSON value.




`null`
`true`
`false`
These special JSON literals are, by default, translated to the Prolog terms `@(null)`,
`@(true)`, and `@(false)`, respectively.




Examples:




```
123 ⇒ 123

12.3 ⇒ 12.3

12E3 ⇒ 12.0E3

"foo" ⇒ 'foo'

null ⇒ @(null)

["a", 2, "bar"] ⇒ ['a', 2, 'bar']

{"age": 42,
 "name": {"first":"Kim", "last":"Jones"},
 "children": ["Lisa","Jim","John"]
}
⇒
json(['age'=42,
      'name'=json(['first'='Kim', 'last'='Jones']),
      'children'=['Lisa','Jim','John']])


```

It is possible to specify other Prolog representations of a JSON value using the option argument. See below for details.



#### 10\.20\.1 Options


The following options are used. They are valid for all predicates that takes options, unless stated otherwise.




`compact(Boolean)`
Valid values for Boolean are `true` and `false` (default).



If `false` (default), JSON values are written with extra whitespace and end\-of\-line characters to make it easier for humans to read.
The details of the non\-compact format is subject to change without notice.



If `true`, JSON values are written with a minimum of whitespace.
Since this implies that no end\-of\-line characters will be written, it makes it possible to read the resulting JSON as a single line.



Only valid for predicates that write.




`ascii(Boolean)`
Valid values for Boolean are `true` (default) and `false`.



If `true` (default), JSON values are written using only 7\-bit ASCII characters, which makes the format less sensitive to stream encodings.



If `false`, JSON values are written using full Unicode. In this case any streams should use UTF\-8 encoding.



Only valid for predicates that write.




`end_of_file(ErrorOrTerm)`

Specifies what happens if an end of file is encountered outside any JSON value, e.g. when `json_read/3` has only seen JSON whitespace.



If ErrorOrTerm is the atom `error` (the default) then such an end of file is
treated in the same way as an end of file inside a JSON value, i.e. it throws a syntax error.



Otherwise, an end of file outside any JSON value causes ErrorOrTerm to be returned as the value.
In this case, the the recommended value of ErrorOrTerm is `@(eof)`, although any term
(except `error`, see above) is permitted.



Treating top\-level end of file specially is useful when the stream can contain several
consecutive JSON values, e.g. when the stream represents a sequence of messages, like in the JSON\-RPC server.



Only valid for predicates that read.




`null(X)`
`true(X)`
`false(X)`
The specified term X, which may be a variable, is used for representing the corresponding JSON literal.




`array_tag(Tag)`
The Tag must be an atom.



A JSON array is represented as the compound term `Tag(Elements)`, where Elements is a list of the representations of the array elements.
This may be useful if you need to be able to distinguish between an empty JSON array (`[]`), and a JSON string `"[]"`,
since these have the same Prolog representation (the atom `[]`) in the default representation.



If this option is not specified (the default), then JSON arrays are represented as a list of the representations of the array elements.




`object_tag(Tag)`
The Tag must be an atom. Tag defaults to `'json'`.



A JSON object is represented as the compound term `Tag(Members)`,
where Members is a list of `Name=Value` pairs,
where Name is a representation of the JSON string name and Value is a representation of the JSON value.




`width(Width)`
This option is present for compatibility with other systems.



If Width is `0` (zero), it is treated as a synonym for `compact(true)`. Otherwise, the option is currently ignored.



Only valid for predicates that write.




`value_string_as(Value)`
`step(Value)`
`tab(Value)`
`serialize_unknown(Value)`

These options are present for compatibility with other systems. They are currently ignored.



Only valid for predicates that write.




#### 10\.20\.2 Exported Predicates


The Options argument is described in the module documentation.




`json_read(+Stream, -Term)`
`json_read(+Stream, -Term, +Options)`



Reads a single JSON value from the text stream Stream
and unifies it with Term.



`json_write(+Stream, +Term)`
`json_write(+Stream, +Term, +Options)`



Write the JSON value Term to the text stream Stream.



`is_json_term(+Term)`
`is_json_term(+Term, +Options)`



True if the Term is a valid representation of a JSON value.



`json_to_codes(+Term, -JSONCodes)`
`json_to_codes(+Term, -JSONCodes, +Options)`



Writes Term as JSON and unifies JSONCodes with the list of resulting character codes.



`json_to_atom(+Term, -JSONAtom)`
`json_to_atom(+Term, -JSONAtom, +Options)`



Writes Term as JSON and unifies JSONAtom with an atom consisting of the resulting character codes.



`json_from_codes(+JSONCodes, -Term)`
`json_from_codes(+JSONCodes, -Term, +Options)`



Converts a JSON text, represented as the list of character codes JSONCodes, into the corresponding Prolog term Term.



`json_from_atom(+JSONAtom, -Term)`
`json_from_atom(+JSONAtom, -Term, +Options)`



Converts a JSON text, represented as the character codes of JSONAtom, into the corresponding Prolog term Term.




A small example:




```
| ?- use_module(library(json)).
…
| ?- JSONCodes = "{\"foo\": 42, \"bar\": null}",
     json_from_codes(JSONCodes, JSONTerm),
     json_to_atom(JSONTerm, JSONAtom, [compact(true)]).
JSONCodes = [123,34,102,111,111,34,58,32,52,50|...],
JSONTerm = json([foo=42,bar= @(null)]),
JSONAtom = '{"foo":42,"bar":null}' ?
yes
| ?-

```