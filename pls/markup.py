from tree_sitter import Node
from .model import Predicate, Variable
from .pldoc_comment_visitor import PlDocComment
from lsprotocol import types


class Markup:
    def variable_description(self, element: Variable):
        if element.scope and element.scope.predicate and element.is_parameter:
            predicate = element.scope.predicate
            pldocs = [c for c in predicate.comments if type(c) is PlDocComment]
            # todo: can there be more than one pldoc?
            if len(pldocs) > 0:
                pldoc = pldocs[0]
                args, tags = pldoc.parameter(element.name)

                r = [
                    f"### Parameter `{element.name}`",
                    " or ".join([f"`{a}`" for a in args]),
                ]
                for t in tags:
                    r.append(f"\n- {t.value}")

                return r

        return [f"### Variable `{element.name}`"]

    def predicate_template(self, predicate: Predicate):
        pl_comment = None
        arg_names = [str(i) for i in range(predicate.arity)]
        for c in predicate.comments:
            if type(c) is PlDocComment:
                pl_comment = c
                break
        if pl_comment:
            for t in pl_comment.templates:
                if len(t.args) == predicate.arity:
                    arg_names = [a.name for a in t.args]

        template = (
            f"{predicate.name}("
            + ",".join(
                "${" + str(i + 1) + ":" + a + "}" for i, a in enumerate(arg_names)
            )
            + ")"
        )
        return template

    def signature_information(
        self, element: Predicate, parameter: int
    ) -> types.SignatureInformation:
        other_comments = []
        for c in element.comments:
            if type(c) is not str:
                other_comments.append(c)
        if len(other_comments) > 0:
            pl_comment = other_comments[0]
            templates = pl_comment.templates_with_arity(element.arity)
            if len(templates) == 0:
                return None
            template = templates[0]
            param_info = []
            for arg in template.args:
                p = types.ParameterInformation(
                    label=arg.name,
                    documentation=types.MarkupContent(
                        types.MarkupKind.Markdown,
                        pl_comment.parameter_description(arg.name),
                    ),
                )
                param_info.append(p)

            return types.SignatureInformation(
                label=element.key(),
                active_parameter=parameter,
                documentation=types.MarkupContent(
                    types.MarkupKind.Markdown,
                    pl_comment.to_markdown_without_parameters(),
                ),
                parameters=param_info,
            )

        return None

    def predicate_description(self, element: Predicate):
        string_comments = []
        other_comments = []
        for c in element.comments:
            if type(c) is str:
                string_comments.append(c)
            else:
                other_comments.append(c)

        res = [f"### Predicate: `{element.name}`/{element.arity}"]
        for c in other_comments:
            res.append(c.to_markdown())
        for c in string_comments:
            for line in c.split("\n"):
                i = 0
                line = line.strip()
                if len(line) > 0 and line[0] == "%":
                    i = 1
                res.append(line[i:].strip() + "\n")

        return res

    def node_description(self, node: Node):
        return [f"## {node.type}", bytes.decode(node.text, "utf-8")]


descriptions = Markup()
