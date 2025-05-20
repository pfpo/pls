import enum
import attrs


class TokenModifier(enum.IntFlag):
    deprecated = enum.auto()
    readonly = enum.auto()
    defaultLibrary = enum.auto()
    definition = enum.auto()


@attrs.define
class Token:
    line: int
    offset: int
    text: str

    tok_type: str = ""
    tok_modifiers: list[TokenModifier] = attrs.field(factory=list)


TokenTypes = [
    "number",
    "variable",
    "parameter",
    "function",
    "operator",
    "string",
    "comment",
    "type",
    "keyword",
]

