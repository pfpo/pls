from tree_sitter import Node
from .model import Predicate, Variable
from .pldoc_comment_visitor import PlDocComment

import logging


class Markup:
    def variable_description(self, element: Variable):
        if element.scope and element.scope.predicate and element.is_parameter:
            predicate = element.scope.predicate
            pldocs = [c for c in predicate.comments if type(c) is PlDocComment]
            # todo: can there be more than one pldoc?
            if len(pldocs) > 0:
                pldoc = pldocs[0]
                args, tags = pldoc.parameter(element.name)
                logging.debug(args)
                logging.debug(tags)

                r = [
                    f"### Parameter `{element.name}`",
                    " or ".join([f"`{a}`" for a in args]),
                ]
                for t in tags:
                    r.append(f"\n- {t.value}")

                return r

        return [f"### Variable `{element.name}`"]

    def predicate_description(self, element: Predicate):
        string_comments = []
        other_comments = []
        for c in element.comments:
            if type(c) is str:
                string_comments.append(c)
            else:
                other_comments.append(c)

        res = [f"### Predicate: {element.key()}"]
        for c in element.comments:
            res.append(c.to_markdown())
        res.extend(string_comments)
        return res

    def node_description(self, node: Node):
        return [f"## {node.type}", bytes.decode(node.text, "utf-8")]


descriptions = Markup()
