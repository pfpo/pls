from tree_sitter import Node
from .model import Term
from .tree_visitor import TreeVisitor
from dataclasses import dataclass


@dataclass
class Tag:
    type: str
    name: str = ""
    value: str  =""

    def __str__(self) -> str:
        return rf"@*{self.type}* `{self.name}`: {self.value}"


@dataclass
class Arg:
    instantiation: str = ""
    name: str = ""
    type: str = ""

    def __str__(self):
        return f"{self.instantiation}{self.name}{':' + self.type if self.type else ''}"


class Template(Term):
    def __init__(self, name, args: list[Arg], text):
        super().__init__(name)
        self.args = args
        self.arity = len(args)
        self.text = text


@dataclass
class PlDocComment:
    templates: list[Template]
    description: str
    tags: list[Tag]

    def __str__(self) -> str:
        r = ""
        if len(self.templates) > 0:
            r += "```pl\n"
            for template in self.templates:
                r += template.text + "\n"
            r += "```\n"
            r += "---\n\n"

        r += "### Description\n"
        r += f"{self.description}\n"
        for t in self.tags:
            r += f"- {t}\n"
        return r

    def parameter(self, name : str):
        args = []
        tags = []
        for t in self.templates:
            for a in t.args:
                if a.name == name:
                    args.append(a)

        for tag in self.tags:
            if tag.type == 'arg' or tag.type=='param' and tag.name == name:
                tags.append(tag)

        return args,tags
                    


    def to_markdown(self) -> str:
        return str(self)


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

    def default_visit(self, node: Node):
        self.visit_all_children(node)

    def arg_spec(self, node: Node) -> Arg:
        fields = {"instantiation": "", "name": "", "type": ""}
        for name in fields.keys():
            if field := node.child_by_field_name(name):
                fields[name] = self.get_text(field).strip()

        return Arg(
            name=fields["name"],
            type=fields["type"],
            instantiation=fields["instantiation"],
        )

    def visit_functor(self, node: Node):
        predicate_name = ""
        args = []
        for child in node.named_children:
            if child.type == "functor":
                predicate_name = self.get_text(child)
            elif child.type == "arg_spec":
                args.append(self.visit(child))
        self.templates.append(Template(predicate_name, args, text=self.get_text(node)))

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

        name = ""
        if n := node.child_by_field_name("name"):
            name = self.get_text(n).strip()

        self.tags.append(Tag(type=tag_type, name=name, value=desc))
