from tree_sitter import Node
from .server import server
from .dependency_graph import DependencyGraphManager
from .utils import add_paths, path_to_file_uri, node_text, Path, MyDoc
from dataclasses import dataclass


def rec_print(node: Node, tab=0):
    print(f"{'  ' * tab}{node.type} - {node_text(node)}")
    for child in node.children:
        rec_print(child, tab + 1)


@dataclass
class N:
    type: str = ""
    parent: "N" = None
    prev_sibling: "N" = None


def debug():
    uri = "examples/comments/functor.pl"
    uri = "./test/nested_parameter_not_detected.pl"
    uri = "./test/simplex.pl"
    uri = "./test/functor_not_being_recognized.pl"
    uri = "sicstus-doc-scraper/builtins.pl"
    uri = "examples/consult.pl"
    uri = "./test/commented_prolog_cliques_distinct.pl"
    uri = "examples/b/l.pl"
    uri = "bad/clpfd._cannot_parse_pl"
    uri = "pls/data/flavours/sicstus/libs/clpfd.pl"
    uri = "op.pl"
    uri = path_to_file_uri(Path(uri))
    doc = MyDoc(uri)
    server.start_up_lib(".")
    server.parse_with_dependencies(doc)

    for d in server.diagnostics[uri][1]:
        print(d.message)
    # uri = "a.pl"

    # uri = path_to_file_uri(Path(uri))
    # doc = MyDoc(uri)
    # server.parse_with_dependencies(doc)


    # for child in t.root_node.children:
    #     rec_print(child,0)
    # print(t.root_node)

    if True and uri in server.tables:
        print("Symbol table of: ", uri)
        table = server.tables[uri]
        print(table.exported_signatures)
        # for key, predicate in table.predicate_index.items():
        #     print(key)
        #     print(f"Defs {len(predicate.definitions)}{predicate.definitions}")
        #     print(f"Refs {len(predicate.references)}{predicate.references}")
        #     print(f"Comments: {predicate.comments}")
        #     print("========")
        if len(table.consult_paths) > 0:
            print("Consult Paths:")
            for p in table.consult_paths:
                print(p)
                print(f"This module includes: {add_paths(uri, p)}")

    ts = server.semantic_tokens(doc)
    #print(ts)
    # print(
    #    f"Definition: {server.go_to_definition(t, types.Position(character=13, line=13),uri)}"
    # )
    # print(f"Diagnostics:{server.tree_diagnostics(t)}")
    # for i in range(0, len(ts), 5):
    #     for k in range(0, 5):
    #         print(ts[i + k], end=",")
    #     print()

    # comment_parser = Parser(Language(pldoc.language()))
    # with open(uri,"r") as f:
    #     t = comment_parser.parse(bytes(f.read(),"utf-8"))
    #     s = PlDocVisitor()
    #     s.start(t.root_node)
    #     print(s.get_comment())


# import tree_sitter_prolog as pl
# import tree_sitter as ts
# l = ts.Language(pl.prolog())
# p = ts.Parser(l)
# t = p.parse(bytes(open("test/custom_op.pl").read(),"utf-8"))
# print(t.root_node)
# t = p.parse(bytes(open("test/custom_op.pl").read(),"utf-8"))
# print(t.root_node)


def test_dg():
    dg = DependencyGraphManager()
    dg.file_includes_other("c", "a")
    dg.file_includes_other("b", "c")
    dg.file_includes_other("a", "b")
    print(dg.get_cycles())
