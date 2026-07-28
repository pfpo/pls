"Prolog grammar for tree-sitter"

from ._binding import prolog, problog


def language():
    return prolog()

__all__ = ["language", "prolog", "problog"]
