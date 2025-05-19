#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 141
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 81
#define ALIAS_COUNT 1
#define TOKEN_COUNT 46
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 5

enum ts_symbol_identifiers {
  anon_sym_PERCENT = 1,
  aux_sym_normal_single_line_comment_token1 = 2,
  anon_sym_LF = 3,
  anon_sym_NULL = 4,
  aux_sym_operator_template_token1 = 5,
  anon_sym_is = 6,
  anon_sym_det = 7,
  anon_sym_semidet = 8,
  anon_sym_failure = 9,
  anon_sym_nondet = 10,
  anon_sym_multi = 11,
  anon_sym_undefined = 12,
  anon_sym_COLON_DASH = 13,
  anon_sym_LPAREN = 14,
  anon_sym_COMMA = 15,
  anon_sym_RPAREN = 16,
  anon_sym_PLUS_PLUS = 17,
  anon_sym_PLUS = 18,
  anon_sym_DASH = 19,
  anon_sym_DASH_DASH = 20,
  anon_sym_QMARK = 21,
  anon_sym_COLON = 22,
  anon_sym_AT = 23,
  anon_sym_BANG = 24,
  aux_sym_pldoc_prolog_directive_token1 = 25,
  aux_sym_prolog_style_description_token1 = 26,
  aux_sym_prolog_style_description_token2 = 27,
  anon_sym_SLASH_STAR_STAR = 28,
  anon_sym_STAR = 29,
  anon_sym_STAR_SLASH = 30,
  aux_sym_c_style_description_token1 = 31,
  aux_sym_c_style_description_token2 = 32,
  aux_sym_pl_tag_text_token1 = 33,
  anon_sym_ATarg = 34,
  anon_sym_ATparam = 35,
  anon_sym_ATerror = 36,
  anon_sym_ATauthor = 37,
  anon_sym_ATversion = 38,
  anon_sym_ATsee = 39,
  anon_sym_ATdeprecated = 40,
  anon_sym_ATcompat = 41,
  anon_sym_ATcopyright = 42,
  anon_sym_ATlicense = 43,
  anon_sym_ATbug = 44,
  anon_sym_ATtbd = 45,
  sym_source_file = 46,
  sym_comment = 47,
  sym_normal_comment = 48,
  sym_normal_single_line_comment = 49,
  sym_template = 50,
  sym_operator_template = 51,
  sym_functor_template = 52,
  sym_directive_template = 53,
  sym_head = 54,
  sym_arg_spec = 55,
  sym_functor = 56,
  sym_type = 57,
  sym_arg_name = 58,
  sym_pldoc_comment = 59,
  sym_pldoc_prolog_directive = 60,
  sym_pldoc_prolog_style = 61,
  sym_prolog_style_body = 62,
  sym_prolog_style_description = 63,
  sym_pldoc_c_style = 64,
  sym_c_style_body = 65,
  sym_c_style_description = 66,
  sym_tag_name = 67,
  sym_pl_tag_text = 68,
  sym_pl_tag = 69,
  sym_c_tag = 70,
  aux_sym_source_file_repeat1 = 71,
  aux_sym_head_repeat1 = 72,
  aux_sym_pldoc_prolog_style_repeat1 = 73,
  aux_sym_pldoc_prolog_style_repeat2 = 74,
  aux_sym_prolog_style_body_repeat1 = 75,
  aux_sym_prolog_style_description_repeat1 = 76,
  aux_sym_pldoc_c_style_repeat1 = 77,
  aux_sym_pldoc_c_style_repeat2 = 78,
  aux_sym_c_style_body_repeat1 = 79,
  aux_sym_c_style_description_repeat1 = 80,
  anon_alias_sym_name = 81,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_PERCENT] = "%",
  [aux_sym_normal_single_line_comment_token1] = "normal_single_line_comment_token1",
  [anon_sym_LF] = "\n",
  [anon_sym_NULL] = "\0",
  [aux_sym_operator_template_token1] = "operator_template_token1",
  [anon_sym_is] = "is",
  [anon_sym_det] = "det",
  [anon_sym_semidet] = "semidet",
  [anon_sym_failure] = "failure",
  [anon_sym_nondet] = "nondet",
  [anon_sym_multi] = "multi",
  [anon_sym_undefined] = "undefined",
  [anon_sym_COLON_DASH] = ":-",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_PLUS_PLUS] = "++",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_DASH_DASH] = "--",
  [anon_sym_QMARK] = "\?",
  [anon_sym_COLON] = ":",
  [anon_sym_AT] = "@",
  [anon_sym_BANG] = "!",
  [aux_sym_pldoc_prolog_directive_token1] = "pldoc_prolog_directive_token1",
  [aux_sym_prolog_style_description_token1] = "prolog_style_description_token1",
  [aux_sym_prolog_style_description_token2] = "prolog_style_description_token2",
  [anon_sym_SLASH_STAR_STAR] = "/** ",
  [anon_sym_STAR] = "*",
  [anon_sym_STAR_SLASH] = "*/",
  [aux_sym_c_style_description_token1] = "c_style_description_token1",
  [aux_sym_c_style_description_token2] = "c_style_description_token2",
  [aux_sym_pl_tag_text_token1] = "pl_tag_text_token1",
  [anon_sym_ATarg] = "@arg",
  [anon_sym_ATparam] = "@param",
  [anon_sym_ATerror] = "@error",
  [anon_sym_ATauthor] = "@author",
  [anon_sym_ATversion] = "@version",
  [anon_sym_ATsee] = "@see",
  [anon_sym_ATdeprecated] = "@deprecated",
  [anon_sym_ATcompat] = "@compat",
  [anon_sym_ATcopyright] = "@copyright",
  [anon_sym_ATlicense] = "@license",
  [anon_sym_ATbug] = "@bug",
  [anon_sym_ATtbd] = "@tbd",
  [sym_source_file] = "source_file",
  [sym_comment] = "comment",
  [sym_normal_comment] = "normal_comment",
  [sym_normal_single_line_comment] = "normal_single_line_comment",
  [sym_template] = "template",
  [sym_operator_template] = "operator_template",
  [sym_functor_template] = "functor_template",
  [sym_directive_template] = "directive_template",
  [sym_head] = "head",
  [sym_arg_spec] = "arg_spec",
  [sym_functor] = "functor",
  [sym_type] = "type",
  [sym_arg_name] = "arg_name",
  [sym_pldoc_comment] = "pldoc_comment",
  [sym_pldoc_prolog_directive] = "pldoc_prolog_directive",
  [sym_pldoc_prolog_style] = "pldoc_prolog_style",
  [sym_prolog_style_body] = "prolog_style_body",
  [sym_prolog_style_description] = "prolog_style_description",
  [sym_pldoc_c_style] = "pldoc_c_style",
  [sym_c_style_body] = "c_style_body",
  [sym_c_style_description] = "c_style_description",
  [sym_tag_name] = "tag_name",
  [sym_pl_tag_text] = "pl_tag_text",
  [sym_pl_tag] = "pl_tag",
  [sym_c_tag] = "c_tag",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_head_repeat1] = "head_repeat1",
  [aux_sym_pldoc_prolog_style_repeat1] = "pldoc_prolog_style_repeat1",
  [aux_sym_pldoc_prolog_style_repeat2] = "pldoc_prolog_style_repeat2",
  [aux_sym_prolog_style_body_repeat1] = "prolog_style_body_repeat1",
  [aux_sym_prolog_style_description_repeat1] = "prolog_style_description_repeat1",
  [aux_sym_pldoc_c_style_repeat1] = "pldoc_c_style_repeat1",
  [aux_sym_pldoc_c_style_repeat2] = "pldoc_c_style_repeat2",
  [aux_sym_c_style_body_repeat1] = "c_style_body_repeat1",
  [aux_sym_c_style_description_repeat1] = "c_style_description_repeat1",
  [anon_alias_sym_name] = "name",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [aux_sym_normal_single_line_comment_token1] = aux_sym_normal_single_line_comment_token1,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_NULL] = anon_sym_NULL,
  [aux_sym_operator_template_token1] = aux_sym_operator_template_token1,
  [anon_sym_is] = anon_sym_is,
  [anon_sym_det] = anon_sym_det,
  [anon_sym_semidet] = anon_sym_semidet,
  [anon_sym_failure] = anon_sym_failure,
  [anon_sym_nondet] = anon_sym_nondet,
  [anon_sym_multi] = anon_sym_multi,
  [anon_sym_undefined] = anon_sym_undefined,
  [anon_sym_COLON_DASH] = anon_sym_COLON_DASH,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_PLUS_PLUS] = anon_sym_PLUS_PLUS,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_DASH_DASH] = anon_sym_DASH_DASH,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_BANG] = anon_sym_BANG,
  [aux_sym_pldoc_prolog_directive_token1] = aux_sym_pldoc_prolog_directive_token1,
  [aux_sym_prolog_style_description_token1] = aux_sym_prolog_style_description_token1,
  [aux_sym_prolog_style_description_token2] = aux_sym_prolog_style_description_token2,
  [anon_sym_SLASH_STAR_STAR] = anon_sym_SLASH_STAR_STAR,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_STAR_SLASH] = anon_sym_STAR_SLASH,
  [aux_sym_c_style_description_token1] = aux_sym_c_style_description_token1,
  [aux_sym_c_style_description_token2] = aux_sym_c_style_description_token2,
  [aux_sym_pl_tag_text_token1] = aux_sym_pl_tag_text_token1,
  [anon_sym_ATarg] = anon_sym_ATarg,
  [anon_sym_ATparam] = anon_sym_ATparam,
  [anon_sym_ATerror] = anon_sym_ATerror,
  [anon_sym_ATauthor] = anon_sym_ATauthor,
  [anon_sym_ATversion] = anon_sym_ATversion,
  [anon_sym_ATsee] = anon_sym_ATsee,
  [anon_sym_ATdeprecated] = anon_sym_ATdeprecated,
  [anon_sym_ATcompat] = anon_sym_ATcompat,
  [anon_sym_ATcopyright] = anon_sym_ATcopyright,
  [anon_sym_ATlicense] = anon_sym_ATlicense,
  [anon_sym_ATbug] = anon_sym_ATbug,
  [anon_sym_ATtbd] = anon_sym_ATtbd,
  [sym_source_file] = sym_source_file,
  [sym_comment] = sym_comment,
  [sym_normal_comment] = sym_normal_comment,
  [sym_normal_single_line_comment] = sym_normal_single_line_comment,
  [sym_template] = sym_template,
  [sym_operator_template] = sym_operator_template,
  [sym_functor_template] = sym_functor_template,
  [sym_directive_template] = sym_directive_template,
  [sym_head] = sym_head,
  [sym_arg_spec] = sym_arg_spec,
  [sym_functor] = sym_functor,
  [sym_type] = sym_type,
  [sym_arg_name] = sym_arg_name,
  [sym_pldoc_comment] = sym_pldoc_comment,
  [sym_pldoc_prolog_directive] = sym_pldoc_prolog_directive,
  [sym_pldoc_prolog_style] = sym_pldoc_prolog_style,
  [sym_prolog_style_body] = sym_prolog_style_body,
  [sym_prolog_style_description] = sym_prolog_style_description,
  [sym_pldoc_c_style] = sym_pldoc_c_style,
  [sym_c_style_body] = sym_c_style_body,
  [sym_c_style_description] = sym_c_style_description,
  [sym_tag_name] = sym_tag_name,
  [sym_pl_tag_text] = sym_pl_tag_text,
  [sym_pl_tag] = sym_pl_tag,
  [sym_c_tag] = sym_c_tag,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_head_repeat1] = aux_sym_head_repeat1,
  [aux_sym_pldoc_prolog_style_repeat1] = aux_sym_pldoc_prolog_style_repeat1,
  [aux_sym_pldoc_prolog_style_repeat2] = aux_sym_pldoc_prolog_style_repeat2,
  [aux_sym_prolog_style_body_repeat1] = aux_sym_prolog_style_body_repeat1,
  [aux_sym_prolog_style_description_repeat1] = aux_sym_prolog_style_description_repeat1,
  [aux_sym_pldoc_c_style_repeat1] = aux_sym_pldoc_c_style_repeat1,
  [aux_sym_pldoc_c_style_repeat2] = aux_sym_pldoc_c_style_repeat2,
  [aux_sym_c_style_body_repeat1] = aux_sym_c_style_body_repeat1,
  [aux_sym_c_style_description_repeat1] = aux_sym_c_style_description_repeat1,
  [anon_alias_sym_name] = anon_alias_sym_name,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_normal_single_line_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NULL] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_operator_template_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_is] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_det] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_semidet] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_failure] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_nondet] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_multi] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_undefined] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_pldoc_prolog_directive_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_prolog_style_description_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_prolog_style_description_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_SLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_c_style_description_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_c_style_description_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pl_tag_text_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_ATarg] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATparam] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATerror] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATauthor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATversion] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATsee] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATdeprecated] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATcompat] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATcopyright] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATlicense] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATbug] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ATtbd] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_normal_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_normal_single_line_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_template] = {
    .visible = true,
    .named = true,
  },
  [sym_operator_template] = {
    .visible = true,
    .named = true,
  },
  [sym_functor_template] = {
    .visible = true,
    .named = true,
  },
  [sym_directive_template] = {
    .visible = true,
    .named = true,
  },
  [sym_head] = {
    .visible = true,
    .named = true,
  },
  [sym_arg_spec] = {
    .visible = true,
    .named = true,
  },
  [sym_functor] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_arg_name] = {
    .visible = true,
    .named = true,
  },
  [sym_pldoc_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_pldoc_prolog_directive] = {
    .visible = true,
    .named = true,
  },
  [sym_pldoc_prolog_style] = {
    .visible = true,
    .named = true,
  },
  [sym_prolog_style_body] = {
    .visible = true,
    .named = true,
  },
  [sym_prolog_style_description] = {
    .visible = true,
    .named = true,
  },
  [sym_pldoc_c_style] = {
    .visible = true,
    .named = true,
  },
  [sym_c_style_body] = {
    .visible = true,
    .named = true,
  },
  [sym_c_style_description] = {
    .visible = true,
    .named = true,
  },
  [sym_tag_name] = {
    .visible = true,
    .named = true,
  },
  [sym_pl_tag_text] = {
    .visible = true,
    .named = true,
  },
  [sym_pl_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_c_tag] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_head_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pldoc_prolog_style_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pldoc_prolog_style_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_prolog_style_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_prolog_style_description_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pldoc_c_style_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pldoc_c_style_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_c_style_body_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_c_style_description_repeat1] = {
    .visible = false,
    .named = false,
  },
  [anon_alias_sym_name] = {
    .visible = true,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_description = 1,
  field_name = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_description] = "description",
  [field_name] = "name",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [2] = {.index = 0, .length = 1},
  [3] = {.index = 1, .length = 1},
  [4] = {.index = 2, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_description, 1},
  [2] =
    {field_description, 2},
    {field_name, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = anon_alias_sym_name,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 15,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 6,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 29,
  [32] = 28,
  [33] = 14,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 44,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 12,
  [81] = 81,
  [82] = 43,
  [83] = 13,
  [84] = 37,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 85,
  [91] = 91,
  [92] = 50,
  [93] = 40,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 53,
  [100] = 17,
  [101] = 54,
  [102] = 42,
  [103] = 37,
  [104] = 40,
  [105] = 105,
  [106] = 105,
  [107] = 88,
  [108] = 85,
  [109] = 95,
  [110] = 42,
  [111] = 91,
  [112] = 105,
  [113] = 88,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 97,
  [120] = 120,
  [121] = 64,
  [122] = 122,
  [123] = 45,
  [124] = 124,
  [125] = 48,
  [126] = 46,
  [127] = 45,
  [128] = 128,
  [129] = 118,
  [130] = 61,
  [131] = 62,
  [132] = 132,
  [133] = 133,
  [134] = 75,
  [135] = 77,
  [136] = 48,
  [137] = 46,
  [138] = 138,
  [139] = 139,
  [140] = 114,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(110);
      ADVANCE_MAP(
        0, 121,
        '!', 158,
        '%', 111,
        '(', 138,
        ')', 141,
        '*', 167,
        '+', 144,
        ',', 140,
        '-', 146,
        '/', 16,
        ':', 153,
        '?', 150,
        '@', 156,
        'd', 34,
        'f', 19,
        'i', 89,
        'm', 100,
        'n', 76,
        's', 35,
        'u', 67,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if ((!eof && lookahead == 00)) ADVANCE(121);
      if (lookahead == '\n') ADVANCE(118);
      if (lookahead == '(') ADVANCE(138);
      if (lookahead == '*') ADVANCE(167);
      if (lookahead == ':') ADVANCE(152);
      if (lookahead == 'i') ADVANCE(89);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(162);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(162);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(161);
      if (lookahead == ' ') ADVANCE(160);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(161);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      ADVANCE_MAP(
        '\n', 118,
        '!', 159,
        '(', 139,
        '+', 145,
        '-', 147,
        ':', 155,
        '?', 151,
        '@', 157,
        'i', 126,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      if (lookahead != 0) ADVANCE(127);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(118);
      if (lookahead == '!') ADVANCE(159);
      if (lookahead == '+') ADVANCE(145);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == ':') ADVANCE(154);
      if (lookahead == '?') ADVANCE(151);
      if (lookahead == '@') ADVANCE(157);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (lookahead != 0) ADVANCE(127);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(118);
      if (lookahead == '!') ADVANCE(159);
      if (lookahead == '+') ADVANCE(145);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == ':') ADVANCE(155);
      if (lookahead == '?') ADVANCE(151);
      if (lookahead == '@') ADVANCE(157);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (lookahead != 0) ADVANCE(127);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(119);
      if (lookahead == '@') ADVANCE(20);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(160);
      END_STATE();
    case 11:
      if (lookahead == ' ') ADVANCE(163);
      END_STATE();
    case 12:
      if (lookahead == '!') ADVANCE(159);
      if (lookahead == '+') ADVANCE(145);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == ':') ADVANCE(154);
      if (lookahead == '?') ADVANCE(151);
      if (lookahead == '@') ADVANCE(157);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      if (lookahead != 0) ADVANCE(127);
      END_STATE();
    case 13:
      if (lookahead == '!') ADVANCE(159);
      if (lookahead == '+') ADVANCE(145);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == ':') ADVANCE(155);
      if (lookahead == '?') ADVANCE(151);
      if (lookahead == '@') ADVANCE(157);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(13);
      if (lookahead != 0) ADVANCE(127);
      END_STATE();
    case 14:
      if (lookahead == '%') ADVANCE(112);
      if (lookahead == '*') ADVANCE(164);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      END_STATE();
    case 15:
      if (lookahead == '*') ADVANCE(11);
      END_STATE();
    case 16:
      if (lookahead == '*') ADVANCE(15);
      END_STATE();
    case 17:
      if (lookahead == '/') ADVANCE(174);
      END_STATE();
    case 18:
      if (lookahead == ':') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (lookahead != 0) ADVANCE(127);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(58);
      END_STATE();
    case 20:
      ADVANCE_MAP(
        'a', 79,
        'b', 102,
        'c', 72,
        'd', 38,
        'e', 85,
        'l', 56,
        'p', 22,
        's', 48,
        't', 25,
        'v', 47,
      );
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(64);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(83);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(96);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(99);
      END_STATE();
    case 25:
      if (lookahead == 'b') ADVANCE(29);
      END_STATE();
    case 26:
      if (lookahead == 'c') ADVANCE(42);
      END_STATE();
    case 27:
      if (lookahead == 'c') ADVANCE(24);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(135);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(245);
      END_STATE();
    case 30:
      if (lookahead == 'd') ADVANCE(240);
      END_STATE();
    case 31:
      if (lookahead == 'd') ADVANCE(36);
      END_STATE();
    case 32:
      if (lookahead == 'd') ADVANCE(43);
      END_STATE();
    case 33:
      if (lookahead == 'd') ADVANCE(45);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(49);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(132);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(239);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(243);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(70);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(93);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(28);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(94);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(30);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(82);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(39);
      END_STATE();
    case 49:
      if (lookahead == 'f') ADVANCE(57);
      END_STATE();
    case 50:
      if (lookahead == 'g') ADVANCE(234);
      END_STATE();
    case 51:
      if (lookahead == 'g') ADVANCE(244);
      END_STATE();
    case 52:
      if (lookahead == 'g') ADVANCE(53);
      END_STATE();
    case 53:
      if (lookahead == 'h') ADVANCE(97);
      END_STATE();
    case 54:
      if (lookahead == 'h') ADVANCE(75);
      END_STATE();
    case 55:
      if (lookahead == 'i') ADVANCE(134);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(71);
      END_STATE();
    case 58:
      if (lookahead == 'i') ADVANCE(62);
      END_STATE();
    case 59:
      if (lookahead == 'i') ADVANCE(52);
      END_STATE();
    case 60:
      if (lookahead == 'i') ADVANCE(73);
      END_STATE();
    case 61:
      if (lookahead == 'i') ADVANCE(33);
      END_STATE();
    case 62:
      if (lookahead == 'l') ADVANCE(101);
      END_STATE();
    case 63:
      if (lookahead == 'l') ADVANCE(98);
      END_STATE();
    case 64:
      if (lookahead == 'm') ADVANCE(235);
      END_STATE();
    case 65:
      if (lookahead == 'm') ADVANCE(61);
      END_STATE();
    case 66:
      if (lookahead == 'm') ADVANCE(77);
      if (lookahead == 'p') ADVANCE(103);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(31);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(238);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(32);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(91);
      END_STATE();
    case 71:
      if (lookahead == 'n') ADVANCE(44);
      END_STATE();
    case 72:
      if (lookahead == 'o') ADVANCE(66);
      END_STATE();
    case 73:
      if (lookahead == 'o') ADVANCE(68);
      END_STATE();
    case 74:
      if (lookahead == 'o') ADVANCE(80);
      END_STATE();
    case 75:
      if (lookahead == 'o') ADVANCE(81);
      END_STATE();
    case 76:
      if (lookahead == 'o') ADVANCE(69);
      END_STATE();
    case 77:
      if (lookahead == 'p') ADVANCE(23);
      END_STATE();
    case 78:
      if (lookahead == 'p') ADVANCE(88);
      END_STATE();
    case 79:
      if (lookahead == 'r') ADVANCE(50);
      if (lookahead == 'u') ADVANCE(95);
      END_STATE();
    case 80:
      if (lookahead == 'r') ADVANCE(236);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(237);
      END_STATE();
    case 82:
      if (lookahead == 'r') ADVANCE(90);
      END_STATE();
    case 83:
      if (lookahead == 'r') ADVANCE(21);
      END_STATE();
    case 84:
      if (lookahead == 'r') ADVANCE(74);
      END_STATE();
    case 85:
      if (lookahead == 'r') ADVANCE(84);
      END_STATE();
    case 86:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 87:
      if (lookahead == 'r') ADVANCE(59);
      END_STATE();
    case 88:
      if (lookahead == 'r') ADVANCE(41);
      END_STATE();
    case 89:
      if (lookahead == 's') ADVANCE(128);
      END_STATE();
    case 90:
      if (lookahead == 's') ADVANCE(60);
      END_STATE();
    case 91:
      if (lookahead == 's') ADVANCE(40);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(130);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(133);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(131);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(54);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(241);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(242);
      END_STATE();
    case 98:
      if (lookahead == 't') ADVANCE(55);
      END_STATE();
    case 99:
      if (lookahead == 't') ADVANCE(46);
      END_STATE();
    case 100:
      if (lookahead == 'u') ADVANCE(63);
      END_STATE();
    case 101:
      if (lookahead == 'u') ADVANCE(86);
      END_STATE();
    case 102:
      if (lookahead == 'u') ADVANCE(51);
      END_STATE();
    case 103:
      if (lookahead == 'y') ADVANCE(87);
      END_STATE();
    case 104:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(104);
      if (lookahead != 0) ADVANCE(127);
      END_STATE();
    case 105:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(232);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(233);
      END_STATE();
    case 106:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(233);
      END_STATE();
    case 107:
      if (eof) ADVANCE(110);
      ADVANCE_MAP(
        '!', 159,
        '%', 113,
        '(', 139,
        '+', 145,
        '-', 147,
        '/', 124,
        ':', 155,
        '?', 151,
        '@', 157,
        'i', 126,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(107);
      if (lookahead != 0) ADVANCE(127);
      END_STATE();
    case 108:
      if (eof) ADVANCE(110);
      ADVANCE_MAP(
        '!', 159,
        '%', 113,
        '+', 145,
        '-', 147,
        '/', 124,
        ':', 155,
        '?', 151,
        '@', 157,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(108);
      if (lookahead != 0) ADVANCE(127);
      END_STATE();
    case 109:
      if (eof) ADVANCE(110);
      ADVANCE_MAP(
        '%', 114,
        '(', 138,
        ')', 141,
        '*', 167,
        ',', 140,
        '/', 16,
        ':', 152,
        '@', 20,
        'i', 89,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(109);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(162);
      if (lookahead == '!') ADVANCE(4);
      if (lookahead == '%') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(162);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!') ADVANCE(122);
      if (lookahead == '%') ADVANCE(122);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '!') ADVANCE(127);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '%') ADVANCE(10);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(aux_sym_normal_single_line_comment_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(115);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(116);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(aux_sym_normal_single_line_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(116);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(117);
      if (lookahead == '@') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(171);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(118);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(119);
      if (lookahead == '@') ADVANCE(20);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(120);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(173);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == ' ') ADVANCE(160);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(127);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == ' ') ADVANCE(163);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(127);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == '*') ADVANCE(125);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == '*') ADVANCE(123);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == 's') ADVANCE(129);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_is);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_is);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_det);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_semidet);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_failure);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_nondet);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_multi);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_undefined);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_COLON_DASH);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_COLON_DASH);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(142);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(143);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(148);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(149);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_QMARK);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '-') ADVANCE(136);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '-') ADVANCE(137);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_AT);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(127);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_pldoc_prolog_directive_token1);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token1);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token2);
      if (lookahead == '\n') ADVANCE(162);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR_STAR);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == '/') ADVANCE(169);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '/') ADVANCE(168);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      if (lookahead == '/') ADVANCE(174);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(117);
      if (lookahead == '*') ADVANCE(165);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '@') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(171);
      if (lookahead != 0) ADVANCE(228);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(117);
      if (lookahead == '*') ADVANCE(165);
      if (lookahead == '@') ADVANCE(175);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(171);
      if (lookahead != 0) ADVANCE(228);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(120);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == '/') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(173);
      if (lookahead != 0) ADVANCE(228);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(120);
      if (lookahead == '*') ADVANCE(174);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(173);
      if (lookahead != 0) ADVANCE(228);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      ADVANCE_MAP(
        '*', 174,
        'a', 213,
        'b', 226,
        'c', 205,
        'd', 187,
        'e', 216,
        'l', 198,
        'p', 178,
        's', 191,
        't', 180,
        'v', 192,
      );
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'a') ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'a') ADVANCE(222);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'a') ADVANCE(217);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'a') ADVANCE(225);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'b') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'c') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'c') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'd') ADVANCE(245);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'd') ADVANCE(240);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'e') ADVANCE(239);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'e') ADVANCE(243);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'e') ADVANCE(210);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'e') ADVANCE(204);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'e') ADVANCE(181);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'e') ADVANCE(184);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'e') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'e') ADVANCE(214);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'g') ADVANCE(234);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'g') ADVANCE(244);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'g') ADVANCE(196);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'h') ADVANCE(223);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'h') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'i') ADVANCE(182);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'i') ADVANCE(206);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'i') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'm') ADVANCE(235);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'm') ADVANCE(209);
      if (lookahead == 'p') ADVANCE(227);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'n') ADVANCE(238);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'n') ADVANCE(221);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'o') ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'o') ADVANCE(203);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'o') ADVANCE(211);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'o') ADVANCE(212);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'p') ADVANCE(177);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'p') ADVANCE(219);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'r') ADVANCE(236);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'r') ADVANCE(237);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'r') ADVANCE(193);
      if (lookahead == 'u') ADVANCE(224);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'r') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'r') ADVANCE(207);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'r') ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'r') ADVANCE(176);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'r') ADVANCE(200);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'r') ADVANCE(189);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 's') ADVANCE(199);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 's') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 't') ADVANCE(241);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 't') ADVANCE(242);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 't') ADVANCE(197);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 't') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'u') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead == 'y') ADVANCE(218);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(166);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '@') ADVANCE(175);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(230);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(228);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(166);
      if (lookahead == '@') ADVANCE(175);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(230);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(228);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_c_style_description_token2);
      if (lookahead == '\n') ADVANCE(231);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(aux_sym_pl_tag_text_token1);
      if (lookahead == '\n') ADVANCE(232);
      if (lookahead == '@') ADVANCE(233);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(232);
      if (lookahead != 0) ADVANCE(233);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(aux_sym_pl_tag_text_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(233);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_ATarg);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_ATparam);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_ATerror);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_ATauthor);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_ATversion);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_ATsee);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_ATdeprecated);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_ATcompat);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(anon_sym_ATcopyright);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_ATlicense);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(anon_sym_ATbug);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(anon_sym_ATtbd);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 109},
  [2] = {.lex_state = 170},
  [3] = {.lex_state = 7},
  [4] = {.lex_state = 12},
  [5] = {.lex_state = 12},
  [6] = {.lex_state = 107},
  [7] = {.lex_state = 170},
  [8] = {.lex_state = 109},
  [9] = {.lex_state = 109},
  [10] = {.lex_state = 109},
  [11] = {.lex_state = 109},
  [12] = {.lex_state = 229},
  [13] = {.lex_state = 229},
  [14] = {.lex_state = 108},
  [15] = {.lex_state = 13},
  [16] = {.lex_state = 170},
  [17] = {.lex_state = 229},
  [18] = {.lex_state = 13},
  [19] = {.lex_state = 9},
  [20] = {.lex_state = 9},
  [21] = {.lex_state = 109},
  [22] = {.lex_state = 109},
  [23] = {.lex_state = 6},
  [24] = {.lex_state = 109},
  [25] = {.lex_state = 109},
  [26] = {.lex_state = 109},
  [27] = {.lex_state = 109},
  [28] = {.lex_state = 13},
  [29] = {.lex_state = 13},
  [30] = {.lex_state = 13},
  [31] = {.lex_state = 13},
  [32] = {.lex_state = 13},
  [33] = {.lex_state = 8},
  [34] = {.lex_state = 13},
  [35] = {.lex_state = 14},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 109},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 109},
  [40] = {.lex_state = 109},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 109},
  [43] = {.lex_state = 109},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 109},
  [46] = {.lex_state = 109},
  [47] = {.lex_state = 109},
  [48] = {.lex_state = 109},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 109},
  [51] = {.lex_state = 109},
  [52] = {.lex_state = 109},
  [53] = {.lex_state = 109},
  [54] = {.lex_state = 109},
  [55] = {.lex_state = 1},
  [56] = {.lex_state = 109},
  [57] = {.lex_state = 109},
  [58] = {.lex_state = 109},
  [59] = {.lex_state = 172},
  [60] = {.lex_state = 109},
  [61] = {.lex_state = 109},
  [62] = {.lex_state = 109},
  [63] = {.lex_state = 109},
  [64] = {.lex_state = 109},
  [65] = {.lex_state = 109},
  [66] = {.lex_state = 1},
  [67] = {.lex_state = 172},
  [68] = {.lex_state = 109},
  [69] = {.lex_state = 109},
  [70] = {.lex_state = 14},
  [71] = {.lex_state = 109},
  [72] = {.lex_state = 109},
  [73] = {.lex_state = 109},
  [74] = {.lex_state = 109},
  [75] = {.lex_state = 109},
  [76] = {.lex_state = 109},
  [77] = {.lex_state = 109},
  [78] = {.lex_state = 109},
  [79] = {.lex_state = 14},
  [80] = {.lex_state = 172},
  [81] = {.lex_state = 1},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 172},
  [84] = {.lex_state = 18},
  [85] = {.lex_state = 104},
  [86] = {.lex_state = 1},
  [87] = {.lex_state = 106},
  [88] = {.lex_state = 104},
  [89] = {.lex_state = 14},
  [90] = {.lex_state = 104},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 1},
  [93] = {.lex_state = 18},
  [94] = {.lex_state = 104},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 104},
  [97] = {.lex_state = 172},
  [98] = {.lex_state = 106},
  [99] = {.lex_state = 1},
  [100] = {.lex_state = 172},
  [101] = {.lex_state = 1},
  [102] = {.lex_state = 1},
  [103] = {.lex_state = 1},
  [104] = {.lex_state = 1},
  [105] = {.lex_state = 104},
  [106] = {.lex_state = 104},
  [107] = {.lex_state = 104},
  [108] = {.lex_state = 104},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 18},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 104},
  [113] = {.lex_state = 104},
  [114] = {.lex_state = 231},
  [115] = {.lex_state = 7},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 7},
  [118] = {.lex_state = 104},
  [119] = {.lex_state = 106},
  [120] = {.lex_state = 7},
  [121] = {.lex_state = 7},
  [122] = {.lex_state = 115},
  [123] = {.lex_state = 104},
  [124] = {.lex_state = 7},
  [125] = {.lex_state = 7},
  [126] = {.lex_state = 7},
  [127] = {.lex_state = 7},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 104},
  [130] = {.lex_state = 7},
  [131] = {.lex_state = 7},
  [132] = {.lex_state = 7},
  [133] = {.lex_state = 7},
  [134] = {.lex_state = 7},
  [135] = {.lex_state = 7},
  [136] = {.lex_state = 104},
  [137] = {.lex_state = 104},
  [138] = {.lex_state = 7},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 231},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_NULL] = ACTIONS(1),
    [anon_sym_is] = ACTIONS(1),
    [anon_sym_det] = ACTIONS(1),
    [anon_sym_semidet] = ACTIONS(1),
    [anon_sym_failure] = ACTIONS(1),
    [anon_sym_nondet] = ACTIONS(1),
    [anon_sym_multi] = ACTIONS(1),
    [anon_sym_undefined] = ACTIONS(1),
    [anon_sym_COLON_DASH] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_PLUS_PLUS] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [aux_sym_pldoc_prolog_directive_token1] = ACTIONS(1),
    [aux_sym_prolog_style_description_token1] = ACTIONS(1),
    [aux_sym_prolog_style_description_token2] = ACTIONS(1),
    [anon_sym_SLASH_STAR_STAR] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_STAR_SLASH] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(116),
    [sym_comment] = STATE(26),
    [sym_normal_comment] = STATE(72),
    [sym_normal_single_line_comment] = STATE(76),
    [sym_pldoc_comment] = STATE(72),
    [sym_pldoc_prolog_directive] = STATE(39),
    [sym_pldoc_prolog_style] = STATE(58),
    [sym_pldoc_c_style] = STATE(58),
    [aux_sym_source_file_repeat1] = STATE(26),
    [aux_sym_pldoc_prolog_style_repeat1] = STATE(39),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_PERCENT] = ACTIONS(5),
    [aux_sym_pldoc_prolog_directive_token1] = ACTIONS(7),
    [anon_sym_SLASH_STAR_STAR] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(11), 1,
      anon_sym_LF,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(15), 1,
      aux_sym_c_style_description_token1,
    STATE(7), 1,
      aux_sym_pldoc_c_style_repeat2,
    STATE(10), 1,
      aux_sym_c_style_body_repeat1,
    STATE(11), 1,
      sym_c_style_description,
    STATE(12), 1,
      aux_sym_c_style_description_repeat1,
    STATE(115), 1,
      sym_c_tag,
    STATE(139), 1,
      sym_c_style_body,
    ACTIONS(17), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(19), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [44] = 10,
    ACTIONS(21), 1,
      anon_sym_LF,
    ACTIONS(23), 1,
      aux_sym_operator_template_token1,
    ACTIONS(25), 1,
      anon_sym_COLON_DASH,
    STATE(82), 1,
      sym_functor,
    STATE(92), 1,
      sym_head,
    STATE(110), 1,
      sym_arg_name,
    STATE(129), 1,
      sym_arg_spec,
    STATE(138), 1,
      sym_template,
    STATE(121), 3,
      sym_operator_template,
      sym_functor_template,
      sym_directive_template,
    ACTIONS(27), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [84] = 9,
    ACTIONS(29), 1,
      aux_sym_operator_template_token1,
    ACTIONS(31), 1,
      anon_sym_COLON_DASH,
    STATE(43), 1,
      sym_functor,
    STATE(50), 1,
      sym_head,
    STATE(60), 1,
      sym_template,
    STATE(110), 1,
      sym_arg_name,
    STATE(118), 1,
      sym_arg_spec,
    STATE(64), 3,
      sym_operator_template,
      sym_functor_template,
      sym_directive_template,
    ACTIONS(27), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [121] = 9,
    ACTIONS(23), 1,
      aux_sym_operator_template_token1,
    ACTIONS(25), 1,
      anon_sym_COLON_DASH,
    STATE(82), 1,
      sym_functor,
    STATE(92), 1,
      sym_head,
    STATE(110), 1,
      sym_arg_name,
    STATE(129), 1,
      sym_arg_spec,
    STATE(138), 1,
      sym_template,
    STATE(121), 3,
      sym_operator_template,
      sym_functor_template,
      sym_directive_template,
    ACTIONS(27), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [158] = 7,
    ACTIONS(37), 1,
      aux_sym_operator_template_token1,
    ACTIONS(42), 1,
      anon_sym_COLON,
    STATE(42), 1,
      sym_arg_name,
    STATE(61), 1,
      sym_arg_spec,
    ACTIONS(33), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(35), 3,
      anon_sym_PERCENT,
      anon_sym_is,
      anon_sym_LPAREN,
    ACTIONS(40), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_AT,
      anon_sym_BANG,
  [190] = 4,
    ACTIONS(45), 1,
      anon_sym_LF,
    ACTIONS(48), 1,
      anon_sym_STAR,
    STATE(7), 1,
      aux_sym_pldoc_c_style_repeat2,
    ACTIONS(51), 13,
      aux_sym_c_style_description_token1,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [215] = 6,
    ACTIONS(53), 1,
      anon_sym_STAR,
    ACTIONS(56), 1,
      anon_sym_STAR_SLASH,
    STATE(8), 1,
      aux_sym_c_style_body_repeat1,
    STATE(115), 1,
      sym_c_tag,
    ACTIONS(58), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(61), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [244] = 6,
    ACTIONS(64), 1,
      anon_sym_STAR,
    ACTIONS(66), 1,
      anon_sym_STAR_SLASH,
    STATE(8), 1,
      aux_sym_c_style_body_repeat1,
    STATE(115), 1,
      sym_c_tag,
    ACTIONS(68), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(70), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [273] = 6,
    ACTIONS(64), 1,
      anon_sym_STAR,
    ACTIONS(72), 1,
      anon_sym_STAR_SLASH,
    STATE(8), 1,
      aux_sym_c_style_body_repeat1,
    STATE(115), 1,
      sym_c_tag,
    ACTIONS(68), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(70), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [302] = 6,
    ACTIONS(64), 1,
      anon_sym_STAR,
    ACTIONS(72), 1,
      anon_sym_STAR_SLASH,
    STATE(9), 1,
      aux_sym_c_style_body_repeat1,
    STATE(115), 1,
      sym_c_tag,
    ACTIONS(68), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(70), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [331] = 3,
    ACTIONS(15), 1,
      aux_sym_c_style_description_token1,
    STATE(13), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(74), 14,
      anon_sym_STAR,
      anon_sym_STAR_SLASH,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [354] = 3,
    ACTIONS(78), 1,
      aux_sym_c_style_description_token1,
    STATE(13), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(76), 14,
      anon_sym_STAR,
      anon_sym_STAR_SLASH,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [377] = 6,
    ACTIONS(83), 1,
      anon_sym_PERCENT,
    ACTIONS(85), 1,
      aux_sym_operator_template_token1,
    STATE(42), 1,
      sym_arg_name,
    STATE(77), 1,
      sym_arg_spec,
    ACTIONS(81), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(40), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [405] = 7,
    ACTIONS(29), 1,
      aux_sym_operator_template_token1,
    STATE(43), 1,
      sym_functor,
    STATE(50), 1,
      sym_head,
    STATE(110), 1,
      sym_arg_name,
    STATE(118), 1,
      sym_arg_spec,
    STATE(62), 2,
      sym_operator_template,
      sym_functor_template,
    ACTIONS(27), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [435] = 1,
    ACTIONS(51), 15,
      anon_sym_LF,
      anon_sym_STAR,
      aux_sym_c_style_description_token1,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [453] = 1,
    ACTIONS(76), 15,
      anon_sym_STAR,
      anon_sym_STAR_SLASH,
      aux_sym_c_style_description_token1,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [471] = 7,
    ACTIONS(23), 1,
      aux_sym_operator_template_token1,
    STATE(82), 1,
      sym_functor,
    STATE(92), 1,
      sym_head,
    STATE(110), 1,
      sym_arg_name,
    STATE(129), 1,
      sym_arg_spec,
    STATE(131), 2,
      sym_operator_template,
      sym_functor_template,
    ACTIONS(27), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [501] = 4,
    ACTIONS(87), 1,
      anon_sym_LF,
    STATE(124), 1,
      sym_c_tag,
    ACTIONS(17), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(19), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [524] = 4,
    ACTIONS(89), 1,
      anon_sym_LF,
    STATE(63), 1,
      sym_pl_tag,
    ACTIONS(91), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(93), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [547] = 2,
    ACTIONS(95), 1,
      anon_sym_STAR,
    ACTIONS(56), 13,
      anon_sym_STAR_SLASH,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [566] = 2,
    ACTIONS(97), 1,
      anon_sym_STAR,
    ACTIONS(99), 13,
      anon_sym_STAR_SLASH,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [585] = 7,
    ACTIONS(33), 1,
      anon_sym_LF,
    ACTIONS(101), 1,
      aux_sym_operator_template_token1,
    ACTIONS(106), 1,
      anon_sym_COLON,
    STATE(102), 1,
      sym_arg_name,
    STATE(130), 1,
      sym_arg_spec,
    ACTIONS(35), 2,
      anon_sym_is,
      anon_sym_LPAREN,
    ACTIONS(104), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_AT,
      anon_sym_BANG,
  [614] = 3,
    STATE(63), 1,
      sym_pl_tag,
    ACTIONS(109), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(111), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [634] = 9,
    ACTIONS(113), 1,
      ts_builtin_sym_end,
    ACTIONS(115), 1,
      anon_sym_PERCENT,
    ACTIONS(118), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(121), 1,
      anon_sym_SLASH_STAR_STAR,
    STATE(76), 1,
      sym_normal_single_line_comment,
    STATE(25), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(39), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(58), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
    STATE(72), 2,
      sym_normal_comment,
      sym_pldoc_comment,
  [666] = 9,
    ACTIONS(5), 1,
      anon_sym_PERCENT,
    ACTIONS(7), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(9), 1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(124), 1,
      ts_builtin_sym_end,
    STATE(76), 1,
      sym_normal_single_line_comment,
    STATE(25), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(39), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(58), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
    STATE(72), 2,
      sym_normal_comment,
      sym_pldoc_comment,
  [698] = 3,
    STATE(124), 1,
      sym_c_tag,
    ACTIONS(68), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(70), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [718] = 5,
    ACTIONS(85), 1,
      aux_sym_operator_template_token1,
    STATE(29), 1,
      aux_sym_head_repeat1,
    STATE(42), 1,
      sym_arg_name,
    STATE(95), 1,
      sym_arg_spec,
    ACTIONS(40), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [741] = 5,
    ACTIONS(85), 1,
      aux_sym_operator_template_token1,
    STATE(30), 1,
      aux_sym_head_repeat1,
    STATE(42), 1,
      sym_arg_name,
    STATE(91), 1,
      sym_arg_spec,
    ACTIONS(40), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [764] = 5,
    ACTIONS(126), 1,
      aux_sym_operator_template_token1,
    STATE(30), 1,
      aux_sym_head_repeat1,
    STATE(42), 1,
      sym_arg_name,
    STATE(128), 1,
      sym_arg_spec,
    ACTIONS(129), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [787] = 5,
    ACTIONS(85), 1,
      aux_sym_operator_template_token1,
    STATE(30), 1,
      aux_sym_head_repeat1,
    STATE(42), 1,
      sym_arg_name,
    STATE(111), 1,
      sym_arg_spec,
    ACTIONS(40), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [810] = 5,
    ACTIONS(85), 1,
      aux_sym_operator_template_token1,
    STATE(31), 1,
      aux_sym_head_repeat1,
    STATE(42), 1,
      sym_arg_name,
    STATE(109), 1,
      sym_arg_spec,
    ACTIONS(40), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [833] = 5,
    ACTIONS(81), 1,
      anon_sym_LF,
    ACTIONS(132), 1,
      aux_sym_operator_template_token1,
    STATE(102), 1,
      sym_arg_name,
    STATE(135), 1,
      sym_arg_spec,
    ACTIONS(104), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [856] = 1,
    ACTIONS(134), 9,
      aux_sym_operator_template_token1,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [868] = 7,
    ACTIONS(136), 1,
      anon_sym_PERCENT,
    STATE(41), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(51), 1,
      aux_sym_prolog_style_body_repeat1,
    STATE(57), 1,
      sym_prolog_style_description,
    STATE(69), 1,
      sym_prolog_style_body,
    STATE(70), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(138), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [891] = 6,
    ACTIONS(138), 1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(142), 1,
      anon_sym_PERCENT,
    ACTIONS(144), 1,
      aux_sym_prolog_style_description_token1,
    STATE(41), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(74), 1,
      sym_prolog_style_description,
    ACTIONS(140), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [912] = 2,
    ACTIONS(148), 1,
      anon_sym_PERCENT,
    ACTIONS(146), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [924] = 5,
    ACTIONS(152), 1,
      anon_sym_PERCENT,
    ACTIONS(154), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(157), 1,
      aux_sym_prolog_style_description_token2,
    STATE(38), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(150), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [942] = 5,
    ACTIONS(162), 1,
      anon_sym_PERCENT,
    ACTIONS(165), 1,
      aux_sym_pldoc_prolog_directive_token1,
    STATE(35), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(160), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(47), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [960] = 3,
    ACTIONS(170), 1,
      anon_sym_PERCENT,
    ACTIONS(172), 1,
      anon_sym_COLON,
    ACTIONS(168), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [974] = 5,
    ACTIONS(176), 1,
      anon_sym_PERCENT,
    ACTIONS(178), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(180), 1,
      aux_sym_prolog_style_description_token2,
    STATE(38), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(174), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [992] = 3,
    ACTIONS(184), 1,
      anon_sym_PERCENT,
    ACTIONS(186), 1,
      anon_sym_COLON,
    ACTIONS(182), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1006] = 3,
    ACTIONS(190), 1,
      anon_sym_PERCENT,
    ACTIONS(192), 1,
      anon_sym_LPAREN,
    ACTIONS(188), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1019] = 1,
    ACTIONS(194), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [1028] = 2,
    ACTIONS(198), 1,
      anon_sym_PERCENT,
    ACTIONS(196), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1039] = 2,
    ACTIONS(202), 1,
      anon_sym_PERCENT,
    ACTIONS(200), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1050] = 4,
    ACTIONS(206), 1,
      anon_sym_PERCENT,
    ACTIONS(208), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(204), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(47), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [1065] = 2,
    ACTIONS(213), 1,
      anon_sym_PERCENT,
    ACTIONS(211), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1076] = 1,
    ACTIONS(215), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [1085] = 3,
    ACTIONS(219), 1,
      anon_sym_PERCENT,
    ACTIONS(221), 1,
      anon_sym_is,
    ACTIONS(217), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1097] = 3,
    ACTIONS(225), 1,
      anon_sym_PERCENT,
    STATE(56), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(223), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1109] = 3,
    ACTIONS(230), 1,
      anon_sym_PERCENT,
    STATE(56), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(228), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1121] = 2,
    ACTIONS(235), 1,
      anon_sym_PERCENT,
    ACTIONS(233), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1131] = 2,
    ACTIONS(239), 1,
      anon_sym_PERCENT,
    ACTIONS(237), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1141] = 5,
    ACTIONS(241), 1,
      anon_sym_LF,
    ACTIONS(243), 1,
      anon_sym_STAR,
    ACTIONS(245), 1,
      anon_sym_STAR_SLASH,
    STATE(2), 1,
      aux_sym_pldoc_c_style_repeat2,
    STATE(66), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1157] = 3,
    ACTIONS(249), 1,
      anon_sym_PERCENT,
    STATE(56), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(247), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1169] = 3,
    ACTIONS(225), 1,
      anon_sym_PERCENT,
    STATE(52), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(223), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1181] = 2,
    ACTIONS(254), 1,
      anon_sym_PERCENT,
    ACTIONS(252), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1190] = 4,
    ACTIONS(256), 1,
      anon_sym_LF,
    ACTIONS(258), 1,
      aux_sym_c_style_description_token1,
    STATE(80), 1,
      aux_sym_c_style_description_repeat1,
    STATE(120), 1,
      sym_c_style_description,
  [1203] = 2,
    ACTIONS(262), 1,
      anon_sym_PERCENT,
    ACTIONS(260), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1212] = 2,
    ACTIONS(83), 1,
      anon_sym_PERCENT,
    ACTIONS(81), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1221] = 2,
    ACTIONS(266), 1,
      anon_sym_PERCENT,
    ACTIONS(264), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1230] = 2,
    ACTIONS(268), 1,
      anon_sym_PERCENT,
    ACTIONS(247), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1239] = 2,
    ACTIONS(272), 1,
      anon_sym_PERCENT,
    ACTIONS(270), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1248] = 2,
    ACTIONS(276), 1,
      anon_sym_PERCENT,
    ACTIONS(274), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1257] = 4,
    ACTIONS(278), 1,
      anon_sym_LF,
    ACTIONS(280), 1,
      anon_sym_STAR,
    ACTIONS(283), 1,
      anon_sym_STAR_SLASH,
    STATE(66), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1270] = 4,
    ACTIONS(258), 1,
      aux_sym_c_style_description_token1,
    ACTIONS(285), 1,
      anon_sym_LF,
    STATE(80), 1,
      aux_sym_c_style_description_repeat1,
    STATE(133), 1,
      sym_c_style_description,
  [1283] = 2,
    ACTIONS(289), 1,
      anon_sym_PERCENT,
    ACTIONS(287), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1292] = 2,
    ACTIONS(293), 1,
      anon_sym_PERCENT,
    ACTIONS(291), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1301] = 3,
    ACTIONS(295), 1,
      anon_sym_PERCENT,
    STATE(70), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(298), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [1312] = 2,
    ACTIONS(302), 1,
      anon_sym_PERCENT,
    ACTIONS(300), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1321] = 2,
    ACTIONS(306), 1,
      anon_sym_PERCENT,
    ACTIONS(304), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1330] = 2,
    ACTIONS(310), 1,
      anon_sym_PERCENT,
    ACTIONS(308), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1339] = 2,
    ACTIONS(314), 1,
      anon_sym_PERCENT,
    ACTIONS(312), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1348] = 2,
    ACTIONS(318), 1,
      anon_sym_PERCENT,
    ACTIONS(316), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1357] = 2,
    ACTIONS(322), 1,
      anon_sym_PERCENT,
    ACTIONS(320), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1366] = 2,
    ACTIONS(326), 1,
      anon_sym_PERCENT,
    ACTIONS(324), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1375] = 2,
    ACTIONS(330), 1,
      anon_sym_PERCENT,
    ACTIONS(328), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1384] = 2,
    ACTIONS(332), 1,
      anon_sym_PERCENT,
    ACTIONS(298), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [1392] = 3,
    ACTIONS(74), 1,
      anon_sym_LF,
    ACTIONS(258), 1,
      aux_sym_c_style_description_token1,
    STATE(83), 1,
      aux_sym_c_style_description_repeat1,
  [1402] = 2,
    ACTIONS(334), 1,
      anon_sym_LF,
    ACTIONS(336), 2,
      anon_sym_STAR,
      anon_sym_STAR_SLASH,
  [1410] = 3,
    ACTIONS(188), 1,
      anon_sym_LF,
    ACTIONS(190), 1,
      anon_sym_is,
    ACTIONS(338), 1,
      anon_sym_LPAREN,
  [1420] = 3,
    ACTIONS(76), 1,
      anon_sym_LF,
    ACTIONS(340), 1,
      aux_sym_c_style_description_token1,
    STATE(83), 1,
      aux_sym_c_style_description_repeat1,
  [1430] = 1,
    ACTIONS(148), 2,
      aux_sym_operator_template_token1,
      anon_sym_COLON,
  [1435] = 2,
    ACTIONS(343), 1,
      aux_sym_operator_template_token1,
    STATE(127), 1,
      sym_type,
  [1442] = 2,
    ACTIONS(345), 1,
      anon_sym_LF,
    ACTIONS(347), 1,
      anon_sym_NULL,
  [1449] = 2,
    ACTIONS(349), 1,
      aux_sym_pl_tag_text_token1,
    STATE(73), 1,
      sym_pl_tag_text,
  [1456] = 2,
    ACTIONS(351), 1,
      aux_sym_operator_template_token1,
    STATE(137), 1,
      sym_type,
  [1463] = 2,
    ACTIONS(353), 1,
      anon_sym_STAR,
    STATE(55), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1470] = 2,
    ACTIONS(351), 1,
      aux_sym_operator_template_token1,
    STATE(123), 1,
      sym_type,
  [1477] = 2,
    ACTIONS(355), 1,
      anon_sym_COMMA,
    ACTIONS(357), 1,
      anon_sym_RPAREN,
  [1484] = 2,
    ACTIONS(217), 1,
      anon_sym_LF,
    ACTIONS(359), 1,
      anon_sym_is,
  [1491] = 2,
    ACTIONS(170), 1,
      aux_sym_operator_template_token1,
    ACTIONS(361), 1,
      anon_sym_COLON,
  [1498] = 2,
    ACTIONS(363), 1,
      aux_sym_operator_template_token1,
    STATE(67), 1,
      sym_tag_name,
  [1505] = 2,
    ACTIONS(355), 1,
      anon_sym_COMMA,
    ACTIONS(365), 1,
      anon_sym_RPAREN,
  [1512] = 2,
    ACTIONS(367), 1,
      aux_sym_operator_template_token1,
    STATE(87), 1,
      sym_tag_name,
  [1519] = 1,
    ACTIONS(369), 2,
      anon_sym_LF,
      aux_sym_c_style_description_token1,
  [1524] = 2,
    ACTIONS(349), 1,
      aux_sym_pl_tag_text_token1,
    STATE(71), 1,
      sym_pl_tag_text,
  [1531] = 2,
    ACTIONS(233), 1,
      anon_sym_LF,
    ACTIONS(235), 1,
      anon_sym_is,
  [1538] = 1,
    ACTIONS(76), 2,
      anon_sym_LF,
      aux_sym_c_style_description_token1,
  [1543] = 2,
    ACTIONS(237), 1,
      anon_sym_LF,
    ACTIONS(239), 1,
      anon_sym_is,
  [1550] = 2,
    ACTIONS(182), 1,
      anon_sym_LF,
    ACTIONS(371), 1,
      anon_sym_COLON,
  [1557] = 2,
    ACTIONS(146), 1,
      anon_sym_LF,
    ACTIONS(148), 1,
      anon_sym_COLON,
  [1564] = 2,
    ACTIONS(168), 1,
      anon_sym_LF,
    ACTIONS(373), 1,
      anon_sym_COLON,
  [1571] = 2,
    ACTIONS(375), 1,
      aux_sym_operator_template_token1,
    STATE(40), 1,
      sym_arg_name,
  [1578] = 2,
    ACTIONS(377), 1,
      aux_sym_operator_template_token1,
    STATE(93), 1,
      sym_arg_name,
  [1585] = 2,
    ACTIONS(379), 1,
      aux_sym_operator_template_token1,
    STATE(46), 1,
      sym_type,
  [1592] = 2,
    ACTIONS(379), 1,
      aux_sym_operator_template_token1,
    STATE(45), 1,
      sym_type,
  [1599] = 2,
    ACTIONS(355), 1,
      anon_sym_COMMA,
    ACTIONS(381), 1,
      anon_sym_RPAREN,
  [1606] = 2,
    ACTIONS(184), 1,
      aux_sym_operator_template_token1,
    ACTIONS(383), 1,
      anon_sym_COLON,
  [1613] = 2,
    ACTIONS(355), 1,
      anon_sym_COMMA,
    ACTIONS(385), 1,
      anon_sym_RPAREN,
  [1620] = 2,
    ACTIONS(387), 1,
      aux_sym_operator_template_token1,
    STATE(104), 1,
      sym_arg_name,
  [1627] = 2,
    ACTIONS(343), 1,
      aux_sym_operator_template_token1,
    STATE(126), 1,
      sym_type,
  [1634] = 1,
    ACTIONS(389), 1,
      aux_sym_c_style_description_token2,
  [1638] = 1,
    ACTIONS(391), 1,
      anon_sym_LF,
  [1642] = 1,
    ACTIONS(393), 1,
      ts_builtin_sym_end,
  [1646] = 1,
    ACTIONS(21), 1,
      anon_sym_LF,
  [1650] = 1,
    ACTIONS(395), 1,
      aux_sym_operator_template_token1,
  [1654] = 1,
    ACTIONS(397), 1,
      aux_sym_pl_tag_text_token1,
  [1658] = 1,
    ACTIONS(399), 1,
      anon_sym_LF,
  [1662] = 1,
    ACTIONS(270), 1,
      anon_sym_LF,
  [1666] = 1,
    ACTIONS(401), 1,
      aux_sym_normal_single_line_comment_token1,
  [1670] = 1,
    ACTIONS(196), 1,
      aux_sym_operator_template_token1,
  [1674] = 1,
    ACTIONS(403), 1,
      anon_sym_LF,
  [1678] = 1,
    ACTIONS(211), 1,
      anon_sym_LF,
  [1682] = 1,
    ACTIONS(200), 1,
      anon_sym_LF,
  [1686] = 1,
    ACTIONS(196), 1,
      anon_sym_LF,
  [1690] = 1,
    ACTIONS(355), 1,
      anon_sym_COMMA,
  [1694] = 1,
    ACTIONS(405), 1,
      aux_sym_operator_template_token1,
  [1698] = 1,
    ACTIONS(81), 1,
      anon_sym_LF,
  [1702] = 1,
    ACTIONS(264), 1,
      anon_sym_LF,
  [1706] = 1,
    ACTIONS(407), 1,
      anon_sym_LF,
  [1710] = 1,
    ACTIONS(409), 1,
      anon_sym_LF,
  [1714] = 1,
    ACTIONS(316), 1,
      anon_sym_LF,
  [1718] = 1,
    ACTIONS(324), 1,
      anon_sym_LF,
  [1722] = 1,
    ACTIONS(211), 1,
      aux_sym_operator_template_token1,
  [1726] = 1,
    ACTIONS(200), 1,
      aux_sym_operator_template_token1,
  [1730] = 1,
    ACTIONS(411), 1,
      anon_sym_LF,
  [1734] = 1,
    ACTIONS(413), 1,
      anon_sym_STAR_SLASH,
  [1738] = 1,
    ACTIONS(415), 1,
      aux_sym_c_style_description_token2,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 44,
  [SMALL_STATE(4)] = 84,
  [SMALL_STATE(5)] = 121,
  [SMALL_STATE(6)] = 158,
  [SMALL_STATE(7)] = 190,
  [SMALL_STATE(8)] = 215,
  [SMALL_STATE(9)] = 244,
  [SMALL_STATE(10)] = 273,
  [SMALL_STATE(11)] = 302,
  [SMALL_STATE(12)] = 331,
  [SMALL_STATE(13)] = 354,
  [SMALL_STATE(14)] = 377,
  [SMALL_STATE(15)] = 405,
  [SMALL_STATE(16)] = 435,
  [SMALL_STATE(17)] = 453,
  [SMALL_STATE(18)] = 471,
  [SMALL_STATE(19)] = 501,
  [SMALL_STATE(20)] = 524,
  [SMALL_STATE(21)] = 547,
  [SMALL_STATE(22)] = 566,
  [SMALL_STATE(23)] = 585,
  [SMALL_STATE(24)] = 614,
  [SMALL_STATE(25)] = 634,
  [SMALL_STATE(26)] = 666,
  [SMALL_STATE(27)] = 698,
  [SMALL_STATE(28)] = 718,
  [SMALL_STATE(29)] = 741,
  [SMALL_STATE(30)] = 764,
  [SMALL_STATE(31)] = 787,
  [SMALL_STATE(32)] = 810,
  [SMALL_STATE(33)] = 833,
  [SMALL_STATE(34)] = 856,
  [SMALL_STATE(35)] = 868,
  [SMALL_STATE(36)] = 891,
  [SMALL_STATE(37)] = 912,
  [SMALL_STATE(38)] = 924,
  [SMALL_STATE(39)] = 942,
  [SMALL_STATE(40)] = 960,
  [SMALL_STATE(41)] = 974,
  [SMALL_STATE(42)] = 992,
  [SMALL_STATE(43)] = 1006,
  [SMALL_STATE(44)] = 1019,
  [SMALL_STATE(45)] = 1028,
  [SMALL_STATE(46)] = 1039,
  [SMALL_STATE(47)] = 1050,
  [SMALL_STATE(48)] = 1065,
  [SMALL_STATE(49)] = 1076,
  [SMALL_STATE(50)] = 1085,
  [SMALL_STATE(51)] = 1097,
  [SMALL_STATE(52)] = 1109,
  [SMALL_STATE(53)] = 1121,
  [SMALL_STATE(54)] = 1131,
  [SMALL_STATE(55)] = 1141,
  [SMALL_STATE(56)] = 1157,
  [SMALL_STATE(57)] = 1169,
  [SMALL_STATE(58)] = 1181,
  [SMALL_STATE(59)] = 1190,
  [SMALL_STATE(60)] = 1203,
  [SMALL_STATE(61)] = 1212,
  [SMALL_STATE(62)] = 1221,
  [SMALL_STATE(63)] = 1230,
  [SMALL_STATE(64)] = 1239,
  [SMALL_STATE(65)] = 1248,
  [SMALL_STATE(66)] = 1257,
  [SMALL_STATE(67)] = 1270,
  [SMALL_STATE(68)] = 1283,
  [SMALL_STATE(69)] = 1292,
  [SMALL_STATE(70)] = 1301,
  [SMALL_STATE(71)] = 1312,
  [SMALL_STATE(72)] = 1321,
  [SMALL_STATE(73)] = 1330,
  [SMALL_STATE(74)] = 1339,
  [SMALL_STATE(75)] = 1348,
  [SMALL_STATE(76)] = 1357,
  [SMALL_STATE(77)] = 1366,
  [SMALL_STATE(78)] = 1375,
  [SMALL_STATE(79)] = 1384,
  [SMALL_STATE(80)] = 1392,
  [SMALL_STATE(81)] = 1402,
  [SMALL_STATE(82)] = 1410,
  [SMALL_STATE(83)] = 1420,
  [SMALL_STATE(84)] = 1430,
  [SMALL_STATE(85)] = 1435,
  [SMALL_STATE(86)] = 1442,
  [SMALL_STATE(87)] = 1449,
  [SMALL_STATE(88)] = 1456,
  [SMALL_STATE(89)] = 1463,
  [SMALL_STATE(90)] = 1470,
  [SMALL_STATE(91)] = 1477,
  [SMALL_STATE(92)] = 1484,
  [SMALL_STATE(93)] = 1491,
  [SMALL_STATE(94)] = 1498,
  [SMALL_STATE(95)] = 1505,
  [SMALL_STATE(96)] = 1512,
  [SMALL_STATE(97)] = 1519,
  [SMALL_STATE(98)] = 1524,
  [SMALL_STATE(99)] = 1531,
  [SMALL_STATE(100)] = 1538,
  [SMALL_STATE(101)] = 1543,
  [SMALL_STATE(102)] = 1550,
  [SMALL_STATE(103)] = 1557,
  [SMALL_STATE(104)] = 1564,
  [SMALL_STATE(105)] = 1571,
  [SMALL_STATE(106)] = 1578,
  [SMALL_STATE(107)] = 1585,
  [SMALL_STATE(108)] = 1592,
  [SMALL_STATE(109)] = 1599,
  [SMALL_STATE(110)] = 1606,
  [SMALL_STATE(111)] = 1613,
  [SMALL_STATE(112)] = 1620,
  [SMALL_STATE(113)] = 1627,
  [SMALL_STATE(114)] = 1634,
  [SMALL_STATE(115)] = 1638,
  [SMALL_STATE(116)] = 1642,
  [SMALL_STATE(117)] = 1646,
  [SMALL_STATE(118)] = 1650,
  [SMALL_STATE(119)] = 1654,
  [SMALL_STATE(120)] = 1658,
  [SMALL_STATE(121)] = 1662,
  [SMALL_STATE(122)] = 1666,
  [SMALL_STATE(123)] = 1670,
  [SMALL_STATE(124)] = 1674,
  [SMALL_STATE(125)] = 1678,
  [SMALL_STATE(126)] = 1682,
  [SMALL_STATE(127)] = 1686,
  [SMALL_STATE(128)] = 1690,
  [SMALL_STATE(129)] = 1694,
  [SMALL_STATE(130)] = 1698,
  [SMALL_STATE(131)] = 1702,
  [SMALL_STATE(132)] = 1706,
  [SMALL_STATE(133)] = 1710,
  [SMALL_STATE(134)] = 1714,
  [SMALL_STATE(135)] = 1718,
  [SMALL_STATE(136)] = 1722,
  [SMALL_STATE(137)] = 1726,
  [SMALL_STATE(138)] = 1730,
  [SMALL_STATE(139)] = 1734,
  [SMALL_STATE(140)] = 1738,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor, 1, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor, 1, 0, 0),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_arg_name, 1, 0, 0), SHIFT(37),
  [40] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_arg_name, 1, 0, 0), SHIFT(105),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0), SHIFT_REPEAT(7),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0), SHIFT_REPEAT(117),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(27),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(94),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 2, 0, 0),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 1, 0, 0),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_style_description, 1, 0, 0),
  [76] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(140),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 2, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 2, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [101] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_arg_name, 1, 0, 0), SHIFT(103),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [106] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_arg_name, 1, 0, 0), SHIFT(112),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [115] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(122),
  [118] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [121] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [126] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [129] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(105),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag_text, 1, 0, 0),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag_text, 1, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_name, 1, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_name, 1, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [154] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [157] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0),
  [162] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(132),
  [165] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(4),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 2, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 2, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [174] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 1, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 1, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 1, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 1, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 4, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 4, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 3, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 3, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [208] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 1, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 1, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 1, 0, 0),
  [225] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 1, 0, 0), SHIFT(24),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 2, 0, 0),
  [230] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 2, 0, 0), SHIFT(24),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 4, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 4, 0, 0),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 5, 0, 0),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 5, 0, 0),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [243] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [245] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [249] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [254] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [256] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 1, 0, 0),
  [258] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive_template, 2, 0, 0),
  [266] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive_template, 2, 0, 0),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_template, 1, 0, 0),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [280] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [283] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [285] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 2, 0, 2),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [289] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [293] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [295] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0), SHIFT_REPEAT(132),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 2, 0, 3),
  [302] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 2, 0, 3),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [306] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 1, 0, 0),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 3, 0, 4),
  [310] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 3, 0, 4),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag_text, 2, 0, 0),
  [314] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag_text, 2, 0, 0),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 3, 0, 0),
  [318] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 3, 0, 0),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [322] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 3, 0, 0),
  [326] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 3, 0, 0),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [330] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [332] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [334] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [336] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [338] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [340] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(114),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [347] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(136),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [359] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [361] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [369] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag_name, 1, 0, 1),
  [371] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [373] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [383] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [393] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [397] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag_name, 1, 0, 1),
  [399] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 2, 0, 3),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [409] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 3, 0, 4),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [415] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_pldoc(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
