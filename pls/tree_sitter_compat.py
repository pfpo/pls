import ctypes

import tree_sitter_prolog as ts_prolog
from tree_sitter import Language


def _capsule_from_pointer(ptr: int):
    """Convert a raw TSLanguage* address into the capsule expected by recent tree-sitter."""
    py_capsule_new = ctypes.pythonapi.PyCapsule_New
    py_capsule_new.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_void_p]
    py_capsule_new.restype = ctypes.py_object
    return py_capsule_new(ctypes.c_void_p(ptr), b"tree_sitter.Language", None)


def get_prolog_language() -> Language:
    """Load Prolog language for both old and new tree-sitter-prolog bindings."""
    if hasattr(ts_prolog, "language"):
        return Language(ts_prolog.language())

    if hasattr(ts_prolog, "prolog"):
        raw_lang = ts_prolog.prolog()
        try:
            return Language(raw_lang)
        except OverflowError:
            # Old bindings may expose the raw pointer as Python int, which overflows on Windows.
            return Language(_capsule_from_pointer(raw_lang))

    raise RuntimeError(
        "tree-sitter-prolog binding does not export a supported language loader"
    )
