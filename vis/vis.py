import os
import graphviz
from tree_sitter import Language, Parser,Node
from tree_sitter_prolog import prolog
# from tree_sitter_pldoc import language
from lsprotocol import types
PROLOG = Language(prolog())

parser = Parser(PROLOG)

contained_set = set()
colors = {}
labels= {}
result = None
def node_at_position(node: Node, p: types.Position):
    in_row_between = node.start_point.row < p.line and node.end_point.row > p.line
    in_first_line = (
        node.start_point.row == p.line and node.start_point.column <= p.character
    )
    in_last_line = node.end_point.row == p.line and node.end_point.column >= p.character
    if (
        node.start_point.row == node.end_point.row and node.start_point.row == p.line
    ) and not (
        node.start_point.column <= p.character and node.end_point.column >= p.character
    ):
        return None
    contained = in_row_between or in_first_line or in_last_line
    if not contained:
        return None
    current = node
    contained_set.add(node.id)
    for child in node.children:
        possible = node_at_position(child, p)
        if possible:
            current = possible
    return current

def calculate_node_state(node):
    if node.is_error or node.is_missing or node.type == "MISSING":
        state = "error"
    elif node.has_error:
        state = "contains_error"
    else:
        state = "good"
    return state

def visualize_tree_sitter_ast(code: str, language_name: str, output_file_base: str):
    """
    Parses code using Tree-sitter, generates a DOT graph of the AST,
    and converts it to a PDF using Graphviz.

    Args:
        code (str): The source code to parse.
        language_name (str): The name of the Tree-sitter language (e.g., 'prolog').
        grammar_path (str): Path to the compiled Tree-sitter grammar (.so or .wasm file).
        output_file_base (str): Base name for the output DOT and PDF files.
    """
    # try:
    #     # Load the Tree-sitter language
    #     # For a .so file (shared library) which is common after building:
    #     LANGUAGE = Language(grammar_path, language_name)
    #     # If you were building directly from source folders and didn't have a pre-compiled .so:
    #     # LANGUAGE = Language.build_library(
    #     #     # path to the compiled shared library (e.g., 'build/my-language.so')
    #     #     'build/my-language.so',
    #     #     # Path to the grammar source folder (e.g., 'path/to/tree-sitter-prolog')
    #     #     [f'tree-sitter-{language_name}']
    #     # )

    # except Exception as e:
    #     print(f"Error loading Tree-sitter language from '{grammar_path}': {e}")
    #     print("\nPlease ensure:")
    #     print("1. The 'grammar_path' is correct and points to your compiled .so/.dll file.")
    #     print("2. The grammar for your language is compiled. If not, you might need to:")
    #     print(f"   - Clone the grammar repo (e.g., git clone https://github.com/tree-sitter/tree-sitter-{language_name})")
    #     print(f"   - Compile it using: python -c \"from tree_sitter import Language; Language.build_library('build/my-language.so', ['tree-sitter-{language_name}'])\"")
    #     return

    # parser = Parser()
    # parser.set_language(LANGUAGE)

    tree = parser.parse(bytes(code, "utf8"))
    root_node = tree.root_node
    print(tree.root_node)
    result = node_at_position(root_node,types.Position(2,3))
    colors[result.parent.id] = "purple"
    for child in result.parent.children:
        if child.type == "arg_list":
            labels[child.id]= f"        Calculated Arity = {len(child.children)}"
            for neto in  child.children:
                colors[neto.id] = "purple"
        
        colors[child.id] = "purple"
    print(result)
    print(contained_set)
    dot = graphviz.Digraph(comment=f'{language_name} AST')
    dot.attr(rankdir='TB') # Top-to-Bottom layout
    dot.attr('node', shape='box', style='rounded,filled', fillcolor='lightblue')
    dot.attr('edge', arrowhead='vee')

    node_counter = 0
    node_map = {} # To store unique IDs for Graphviz nodes

    def add_nodes_and_edges(node, parent_id=None):
        nonlocal node_counter
        node_id = f"node{node_counter}"
        node_counter += 1
        node_map[node] = node_id
        state = calculate_node_state(node)

        # === Label (inside the box) ===
        node_label = f"{node.type}"
        node_text = ""
        if not node.children:
            node_text = node.text.decode('utf8').replace('"', '\\"')
            if node_text and node.type != 'comment':
                node_label = f"{node.type}\\n\"{node_text}\""
            elif node_text and node.type == 'comment':
                node_label = f"{node.type}"

        if node.is_error:
            node_label = "Error\\n" + node_label
        if node.type == "MISSING" or node.is_missing:
            node_label = "Missing\\n" + node_label

        # === Fill color ===
        fill_color = {"good": "lightblue", "error": "lightcoral", "contains_error": "lightyellow"}
        if node.parent and calculate_node_state(node.parent) == "error":
            state = "error"

        if node.id in contained_set:
           color = fill_color["contains_error"] 
        else:
            color = "lightblue"
            
        if node.id in colors:
            color = colors[node.id]
        if node.id == result.id: 
            color = "green"

        # === Range label (outside the box) ===
        start = node.start_point  # (row, column)
        end = node.end_point
        range_label = f"{start[0]+1}:{start[1]+1} - {end[0]+1}:{end[1]+1}"  # 1-based
        node_text = f"<BR/>\"{node_text}\"" if node_text else ""
        node_label = f"<<B>{node.type}</B><BR/>{range_label}{node_text}>"

        if node.type not in ("close","open","source_file"):
            dot.node(
                node_id,
                label=node_label,
                xlabel = labels[node.id] if node.id in labels  else "",
                labeljust="r",   
                labelloc="r",        # place the label at the top of the node

                fillcolor=color
            )

            if parent_id:
                dot.edge(parent_id, node_id)

        for child in node.children:
            add_nodes_and_edges(child, node_id)

    # Start traversal from the root node
        
    
        
    for child in root_node.children:
        add_nodes_and_edges(child,None)

    # Render the DOT graph to PDF
    try:
        dot_path = f"{output_file_base}.dot"
        pdf_path = f"{output_file_base}.pdf"
        dot.render(output_file_base, format='pdf', cleanup=True) # cleanup=True removes the .dot file after PDF generation
        print(f"Successfully generated AST visualization to {pdf_path}")
    except Exception as e:
        print(f"Error rendering Graphviz graph to PDF: {e}")
        print("Please ensure Graphviz (the 'dot' command) is installed and accessible in your system's PATH.")
        print("You can download it from: https://graphviz.org/download/")

PROLOG_LANGUAGE_NAME = 'prolog'

# 3. Sample Prolog code to parse
PROLOG_FILE = "x.pl"
with open(PROLOG_FILE,"r") as f:
    PROLOG_CODE = f.read()

# 4. Output file base name (will create .dot and .pdf files in the current directory)
OUTPUT_BASE_NAME = 'prolog_ast_visualization'

# --- Run the visualization ---
if __name__ == "__main__":
    visualize_tree_sitter_ast(PROLOG_CODE, PROLOG_LANGUAGE_NAME, OUTPUT_BASE_NAME)
