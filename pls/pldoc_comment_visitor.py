from dataclasses import dataclass
from lsprotocol import types
from tree_sitter import Node
from .model import Term
from .tree_visitor import TreeVisitor
from .utils import node_to_range


@dataclass
class Tag:
    type: str
    name: str = ""
    value: str = ""

    def __str__(self) -> str:
        return f"@*{self.type}* `{self.name}`: {self.value}"


@dataclass
class Arg:
    instantiation: str = ""
    name: str = ""
    type: str = ""

    def __str__(self):
        return f"{self.instantiation}{self.name}{':' + self.type if self.type else ''}"


class Template(Term):
    def __init__(
        self, name, args: list[Arg], text, name_range: types.Range, _type=None
    ):
        super().__init__(name)
        self.args = args
        self.arity = len(args)
        self.text = text
        self.name_range: types.Range = name_range
        self._type: str | None = _type


@dataclass
class PlDocComment:
    templates: list[Template]
    description: str
    tags: list[Tag]
    location: types.Location = None

    def to_str(self, tags) -> str:
        r = ""
        if len(self.templates) > 0:
            r += "```pl\n"
            for template in self.templates:
                r += template.text + "\n"
            r += "```\n"
            r += "---\n\n"

        r += "### Description\n"
        r += f"{self.description}\n"
        for t in tags:
            r += f"- {t}\n"
        return r

    def operator_representation(self):
        op = None
        for tag in self.tags:
            if tag.type == "op":
                op = tag
                break
        if op is None:
            return None

        if (
            op.name not in ["xf", "yf", "xfx", "xfy", "yfx", "fy", "fx"]
            and not op.value.isnumeric()
        ):
            return None

        return (op.name, int(op.value))

    def __str__(self) -> str:
        return self.to_str(self.tags)

    def templates_with_arity(self, arity: int) -> list[Template]:
        return [t for t in self.templates if t.arity == arity]

    def parameter_description(self, name: str) -> list[Tag]:
        tags = []
        for tag in self.tags:
            # tag.name[1:] is because of the instantiation operator
            if (
                tag.type == "arg"
                or tag.type == "param"
                and (tag.name == name or tag.name[1:] == name)
            ):
                tags.append(tag)

        r = ""
        for t in tags:
            r += f"- {t}\n"
        return r

    def parameter(self, name: str):
        args = []
        tags = []
        for t in self.templates:
            for a in t.args:
                if a.name == name:
                    args.append(a)

        for tag in self.tags:
            if tag.type == "arg" or tag.type == "param" and tag.name == name:
                tags.append(tag)

        return args, tags

    def to_markdown(self) -> str:
        return str(self)

    def to_markdown_without_parameters(self) -> str:
        tags = [t for t in self.tags if t.type not in ("arg", "param")]
        r = ""
        r += "---\n\n"
        if len(self.templates) > 0:
            r += "```pl\n"
            for template in self.templates:
                r += template.text + "\n"
            r += "```\n"
            r += "---\n\n"

        r += f"{self.description}\n"
        for t in tags:
            r += f"- {t}\n"
        return r


class PlDocVisitor(TreeVisitor):
    def __init__(self):
        super().__init__()
        self.tags = []
        self.description = ""
        self.templates = []

    def get_comment(self):
        return PlDocComment(
            templates=self.templates, tags=self.tags, description=self.description
        )

    def start(self, node: Node):
        self.visit_all_children(node)

    def build_visitors(self):
        self.add_visit("ERROR", self.visit_all_children)

        # Tags
        self.add_visit("pl_tag", self.visit_tag)

        self.set_default_visitor(self.default_visit)

        self.add_visit("pl_tag_text", self.pl_tag_text)
        self.add_visit("prolog_style_description", self.visit_description)
        self.add_visit("arg_spec", self.arg_spec)

        # Templates
        self.add_visit("functor_template", self.visit_functor)
        self.add_visit("operator_template", self.visit_operator)

    def default_visit(self, node: Node):
        self.visit_all_children(node)

    def arg_spec(self, node: Node) -> Arg:
        fields = {"instantiation": "", "name": "", "type": ""}
        for name in fields.keys():
            if field := node.child_by_field_name(name):
                fields[name] = self.get_text(field).strip()

        fields["instantiation"] = fields["name"][0]
        fields["name"] = fields["name"][1:]
        return Arg(
            name=fields["name"],
            type=fields["type"],
            instantiation=fields["instantiation"],
        )

    def visit_operator(self, node: Node):
        predicate_name = ""
        name_range = None
        args = []
        arg_nodes = []
        _type = None
        op_node = None
        match node.children:
            case [left, op, right] if op.type == "functor":
                _type = "infix"
                op_node = op
                arg_nodes.extend([left, right])
            case [op, right] if op.type == "functor":
                _type = "prefix"
                op_node = op
                arg_nodes.append(right)
            case [left, op] if op.type == "functor":
                _type = "postfix"
                op_node = op
                arg_nodes.append(left)

            case _:
                for child in node.named_children:
                    if child.type == "functor":
                        predicate_name = self.get_text(child)
                        name_range = node_to_range(child)
                    elif child.type == "arg_spec":
                        args.append(self.visit(child))
        if _type is not None:
            predicate_name = self.get_text(op_node)
            name_range = node_to_range(op_node)
            for arg in arg_nodes:
                args.append(self.visit(arg))

        self.templates.append(
            Template(
                predicate_name,
                args,
                text=self.get_text(node),
                name_range=name_range,
                _type=_type,
            )
        )

    def visit_functor(self, node: Node):
        predicate_name = ""
        name_range = None
        args = []
        for child in node.named_children:
            if child.type == "functor":
                predicate_name = self.get_text(child)
                name_range = node_to_range(child)
            elif child.type == "arg_spec":
                args.append(self.visit(child))
        self.templates.append(
            Template(
                predicate_name, args, text=self.get_text(node), name_range=name_range
            )
        )

    def visit_description(self, node: Node):
        text = self.pl_tag_text(node)
        self.description = text

    def pl_tag_text(self, node: Node) -> str:
        text = self.get_text(node)
        lines = text.split("\n")
        result = ""
        for line in lines:
            i = 1 if len(line) > 0 and line[0] == "%" else 0
            result += line[i:] + "\n"
        return result

    def get_text(self, node: Node) -> str:
        return bytes.decode(node.text, "utf-8")

    def visit_tag(self, node: Node) -> Tag:
        tag_type = node.children[0].type[1:]
        desc = ""
        if n := node.child_by_field_name("description"):
            desc = self.visit(n)
            if desc is None:
                desc = self.get_text(n).strip()

        name = ""
        if n := node.child_by_field_name("name"):
            name = self.get_text(n).strip()

        self.tags.append(Tag(type=tag_type, name=name, value=desc))
