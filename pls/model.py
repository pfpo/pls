from lsprotocol import types


class Term:
    def __init__(self, name):
        self.name: str = name
        self.arity = 0

    def key(self) -> str:
        return f"{self.name}/{self.arity}"


class Predicate(Term):
    def __init__(self, name, arity):
        super().__init__(name)
        self.arity: int = arity
        self.definitions: list[types.Range] = []
        self.uri = ""


class Functor(Term):
    def __init__(self, name, args):
        super().__init__(name)
        self.args: list = args
        self.arity = len(args)


class Operator(Term):
    def __init__(self, operator: str, operands: list[Term]):
        super().__init__(operator)
        self.operands = operands
        self.arity = len(operands)
