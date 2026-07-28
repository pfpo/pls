from tree_sitter import Query

try:
    from tree_sitter import QueryCursor as _QueryCursor
except ImportError:
    _QueryCursor = None


class QueryCursor:
    """Compatibility wrapper for query execution across tree-sitter versions."""

    def __init__(self, query: Query):
        self.query = query
        self._cursor = _QueryCursor(query) if _QueryCursor is not None else None

    def matches(self, node):
        if self._cursor is not None:
            return self._cursor.matches(node)
        return self.query.matches(node)

    def captures(self, node):
        if self._cursor is not None:
            return self._cursor.captures(node)
        return self.query.captures(node)
