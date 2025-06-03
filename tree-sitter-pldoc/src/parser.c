#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 150
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 79
#define ALIAS_COUNT 1
#define TOKEN_COUNT 46
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 9

enum ts_symbol_identifiers {
  aux_sym_operator_template_token1 = 1,
  anon_sym_is = 2,
  anon_sym_det = 3,
  anon_sym_semidet = 4,
  anon_sym_failure = 5,
  anon_sym_nondet = 6,
  anon_sym_multi = 7,
  anon_sym_undefined = 8,
  anon_sym_COLON_DASH = 9,
  anon_sym_LPAREN = 10,
  anon_sym_COMMA = 11,
  anon_sym_RPAREN = 12,
  anon_sym_PLUS_PLUS = 13,
  anon_sym_PLUS = 14,
  anon_sym_DASH = 15,
  anon_sym_DASH_DASH = 16,
  anon_sym_QMARK = 17,
  anon_sym_COLON = 18,
  anon_sym_AT = 19,
  anon_sym_BANG = 20,
  aux_sym_functor_token1 = 21,
  aux_sym_pldoc_prolog_directive_token1 = 22,
  anon_sym_PERCENT = 23,
  anon_sym_LF = 24,
  anon_sym_CR = 25,
  anon_sym_CR_LF = 26,
  aux_sym_prolog_style_description_token1 = 27,
  aux_sym_prolog_style_description_token2 = 28,
  anon_sym_SLASH_STAR_STAR = 29,
  anon_sym_STAR = 30,
  anon_sym_STAR_SLASH = 31,
  aux_sym_c_style_description_token1 = 32,
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
  sym__template = 48,
  sym_operator_template = 49,
  sym_functor_template = 50,
  sym_directive_template = 51,
  sym__head = 52,
  sym_arg_spec = 53,
  sym_functor = 54,
  sym_type = 55,
  sym_arg_name = 56,
  sym_pldoc_comment = 57,
  sym_pldoc_prolog_directive = 58,
  sym_pldoc_prolog_style = 59,
  sym_prolog_style_body = 60,
  sym_prolog_style_description = 61,
  sym_pldoc_c_style = 62,
  sym_c_style_body = 63,
  sym_c_style_description = 64,
  sym_tag_name = 65,
  sym_pl_tag_text = 66,
  sym_pl_tag = 67,
  sym_c_tag = 68,
  aux_sym_source_file_repeat1 = 69,
  aux_sym__head_repeat1 = 70,
  aux_sym_pldoc_prolog_style_repeat1 = 71,
  aux_sym_pldoc_prolog_style_repeat2 = 72,
  aux_sym_prolog_style_body_repeat1 = 73,
  aux_sym_prolog_style_description_repeat1 = 74,
  aux_sym_pldoc_c_style_repeat1 = 75,
  aux_sym_pldoc_c_style_repeat2 = 76,
  aux_sym_c_style_body_repeat1 = 77,
  aux_sym_c_style_description_repeat1 = 78,
  anon_alias_sym_name = 79,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
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
  [aux_sym_functor_token1] = "functor_token1",
  [aux_sym_pldoc_prolog_directive_token1] = "comment_token",
  [anon_sym_PERCENT] = "%",
  [anon_sym_LF] = "\n",
  [anon_sym_CR] = "\r",
  [anon_sym_CR_LF] = "\r\n",
  [aux_sym_prolog_style_description_token1] = "prolog_style_description_token1",
  [aux_sym_prolog_style_description_token2] = "prolog_style_description_token2",
  [anon_sym_SLASH_STAR_STAR] = "comment_token",
  [anon_sym_STAR] = "*",
  [anon_sym_STAR_SLASH] = "*/",
  [aux_sym_c_style_description_token1] = "c_style_description_token1",
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
  [sym__template] = "_template",
  [sym_operator_template] = "operator_template",
  [sym_functor_template] = "functor_template",
  [sym_directive_template] = "directive_template",
  [sym__head] = "_head",
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
  [aux_sym__head_repeat1] = "_head_repeat1",
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
  [aux_sym_functor_token1] = aux_sym_functor_token1,
  [aux_sym_pldoc_prolog_directive_token1] = aux_sym_pldoc_prolog_directive_token1,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_CR] = anon_sym_CR,
  [anon_sym_CR_LF] = anon_sym_CR_LF,
  [aux_sym_prolog_style_description_token1] = aux_sym_prolog_style_description_token1,
  [aux_sym_prolog_style_description_token2] = aux_sym_prolog_style_description_token2,
  [anon_sym_SLASH_STAR_STAR] = aux_sym_pldoc_prolog_directive_token1,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_STAR_SLASH] = anon_sym_STAR_SLASH,
  [aux_sym_c_style_description_token1] = aux_sym_c_style_description_token1,
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
  [sym__template] = sym__template,
  [sym_operator_template] = sym_operator_template,
  [sym_functor_template] = sym_functor_template,
  [sym_directive_template] = sym_directive_template,
  [sym__head] = sym__head,
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
  [aux_sym__head_repeat1] = aux_sym__head_repeat1,
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
  [aux_sym_functor_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pldoc_prolog_directive_token1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CR_LF] = {
    .visible = true,
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
  [sym__template] = {
    .visible = false,
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
  [sym__head] = {
    .visible = false,
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
  [aux_sym__head_repeat1] = {
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
  field_instantiation = 2,
  field_name = 3,
  field_type = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_description] = "description",
  [field_instantiation] = "instantiation",
  [field_name] = "name",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
  [5] = {.index = 5, .length = 1},
  [6] = {.index = 6, .length = 1},
  [7] = {.index = 7, .length = 3},
  [8] = {.index = 10, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 0},
  [1] =
    {field_instantiation, 0},
    {field_name, 1},
  [3] =
    {field_name, 0},
    {field_type, 2},
  [5] =
    {field_name, 1},
  [6] =
    {field_description, 1},
  [7] =
    {field_instantiation, 0},
    {field_name, 1},
    {field_type, 3},
  [10] =
    {field_description, 2},
    {field_name, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [4] = {
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
  [10] = 7,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 16,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 24,
  [27] = 23,
  [28] = 28,
  [29] = 28,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 34,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 46,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 44,
  [59] = 48,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 12,
  [64] = 13,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 3,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 60,
  [78] = 17,
  [79] = 79,
  [80] = 80,
  [81] = 53,
  [82] = 61,
  [83] = 57,
  [84] = 62,
  [85] = 85,
  [86] = 86,
  [87] = 66,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 85,
  [95] = 86,
  [96] = 96,
  [97] = 72,
  [98] = 98,
  [99] = 70,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 61,
  [106] = 57,
  [107] = 62,
  [108] = 108,
  [109] = 75,
  [110] = 76,
  [111] = 80,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 57,
  [117] = 117,
  [118] = 75,
  [119] = 76,
  [120] = 80,
  [121] = 61,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 114,
  [126] = 123,
  [127] = 62,
  [128] = 122,
  [129] = 124,
  [130] = 130,
  [131] = 131,
  [132] = 123,
  [133] = 122,
  [134] = 114,
  [135] = 123,
  [136] = 122,
  [137] = 114,
  [138] = 138,
  [139] = 139,
  [140] = 131,
  [141] = 88,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 142,
  [146] = 76,
  [147] = 147,
  [148] = 75,
  [149] = 80,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(106);
      ADVANCE_MAP(
        '!', 141,
        '%', 145,
        '(', 123,
        ')', 126,
        '*', 163,
        '+', 129,
        ',', 125,
        '-', 131,
        '/', 11,
        ':', 137,
        '?', 135,
        '@', 139,
        'd', 30,
        'f', 15,
        'i', 85,
        'm', 96,
        'n', 72,
        's', 31,
        'u', 63,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(150);
      if (lookahead == '\r') ADVANCE(154);
      if (lookahead == '@') ADVANCE(16);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      ADVANCE_MAP(
        '\n', 151,
        '\r', 155,
        '!', 141,
        '*', 163,
        '+', 129,
        '-', 131,
        ':', 137,
        '?', 135,
        '@', 139,
      );
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(2);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(143);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(151);
      if (lookahead == '\r') ADVANCE(155);
      if (lookahead == '(') ADVANCE(123);
      if (lookahead == 'i') ADVANCE(85);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(3);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(151);
      if (lookahead == '\r') ADVANCE(155);
      if (lookahead == '(') ADVANCE(124);
      if (lookahead == ':') ADVANCE(138);
      if (lookahead == 'i') ADVANCE(111);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(4);
      if (lookahead != 0) ADVANCE(113);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(151);
      if (lookahead == '\r') ADVANCE(155);
      if (lookahead == ':') ADVANCE(12);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') SKIP(5);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(143);
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(144);
      END_STATE();
    case 7:
      if (lookahead == ' ') ADVANCE(161);
      END_STATE();
    case 8:
      if (lookahead == '!') ADVANCE(142);
      if (lookahead == '+') ADVANCE(130);
      if (lookahead == '-') ADVANCE(132);
      if (lookahead == ':') ADVANCE(138);
      if (lookahead == '?') ADVANCE(136);
      if (lookahead == '@') ADVANCE(140);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(112);
      if (lookahead != 0) ADVANCE(113);
      END_STATE();
    case 9:
      if (lookahead == '%') ADVANCE(146);
      if (lookahead == '*') ADVANCE(163);
      if (lookahead == ':') ADVANCE(12);
      if (lookahead == '@') ADVANCE(16);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(143);
      END_STATE();
    case 10:
      if (lookahead == '*') ADVANCE(7);
      END_STATE();
    case 11:
      if (lookahead == '*') ADVANCE(10);
      END_STATE();
    case 12:
      if (lookahead == '-') ADVANCE(122);
      END_STATE();
    case 13:
      if (lookahead == '/') ADVANCE(172);
      END_STATE();
    case 14:
      if (lookahead == ':') ADVANCE(138);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      if (lookahead != 0) ADVANCE(113);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(54);
      END_STATE();
    case 16:
      ADVANCE_MAP(
        'a', 77,
        'b', 98,
        'c', 68,
        'd', 36,
        'e', 81,
        'l', 52,
        'p', 18,
        's', 44,
        't', 21,
        'v', 43,
      );
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(60);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(79);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(91);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(95);
      END_STATE();
    case 21:
      if (lookahead == 'b') ADVANCE(25);
      END_STATE();
    case 22:
      if (lookahead == 'c') ADVANCE(38);
      END_STATE();
    case 23:
      if (lookahead == 'c') ADVANCE(20);
      END_STATE();
    case 24:
      if (lookahead == 'd') ADVANCE(121);
      END_STATE();
    case 25:
      if (lookahead == 'd') ADVANCE(240);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(235);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(32);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(39);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(41);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(88);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(61);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(45);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(118);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(234);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(238);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(74);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(89);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(90);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(26);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(34);
      END_STATE();
    case 45:
      if (lookahead == 'f') ADVANCE(53);
      END_STATE();
    case 46:
      if (lookahead == 'g') ADVANCE(229);
      END_STATE();
    case 47:
      if (lookahead == 'g') ADVANCE(239);
      END_STATE();
    case 48:
      if (lookahead == 'g') ADVANCE(49);
      END_STATE();
    case 49:
      if (lookahead == 'h') ADVANCE(92);
      END_STATE();
    case 50:
      if (lookahead == 'h') ADVANCE(71);
      END_STATE();
    case 51:
      if (lookahead == 'i') ADVANCE(120);
      END_STATE();
    case 52:
      if (lookahead == 'i') ADVANCE(22);
      END_STATE();
    case 53:
      if (lookahead == 'i') ADVANCE(67);
      END_STATE();
    case 54:
      if (lookahead == 'i') ADVANCE(58);
      END_STATE();
    case 55:
      if (lookahead == 'i') ADVANCE(48);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(69);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(29);
      END_STATE();
    case 58:
      if (lookahead == 'l') ADVANCE(97);
      END_STATE();
    case 59:
      if (lookahead == 'l') ADVANCE(94);
      END_STATE();
    case 60:
      if (lookahead == 'm') ADVANCE(230);
      END_STATE();
    case 61:
      if (lookahead == 'm') ADVANCE(57);
      END_STATE();
    case 62:
      if (lookahead == 'm') ADVANCE(73);
      if (lookahead == 'p') ADVANCE(99);
      END_STATE();
    case 63:
      if (lookahead == 'n') ADVANCE(27);
      END_STATE();
    case 64:
      if (lookahead == 'n') ADVANCE(233);
      END_STATE();
    case 65:
      if (lookahead == 'n') ADVANCE(28);
      END_STATE();
    case 66:
      if (lookahead == 'n') ADVANCE(87);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(40);
      END_STATE();
    case 68:
      if (lookahead == 'o') ADVANCE(62);
      END_STATE();
    case 69:
      if (lookahead == 'o') ADVANCE(64);
      END_STATE();
    case 70:
      if (lookahead == 'o') ADVANCE(75);
      END_STATE();
    case 71:
      if (lookahead == 'o') ADVANCE(76);
      END_STATE();
    case 72:
      if (lookahead == 'o') ADVANCE(65);
      END_STATE();
    case 73:
      if (lookahead == 'p') ADVANCE(19);
      END_STATE();
    case 74:
      if (lookahead == 'p') ADVANCE(84);
      END_STATE();
    case 75:
      if (lookahead == 'r') ADVANCE(231);
      END_STATE();
    case 76:
      if (lookahead == 'r') ADVANCE(232);
      END_STATE();
    case 77:
      if (lookahead == 'r') ADVANCE(46);
      if (lookahead == 'u') ADVANCE(93);
      END_STATE();
    case 78:
      if (lookahead == 'r') ADVANCE(86);
      END_STATE();
    case 79:
      if (lookahead == 'r') ADVANCE(17);
      END_STATE();
    case 80:
      if (lookahead == 'r') ADVANCE(70);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(80);
      END_STATE();
    case 82:
      if (lookahead == 'r') ADVANCE(33);
      END_STATE();
    case 83:
      if (lookahead == 'r') ADVANCE(55);
      END_STATE();
    case 84:
      if (lookahead == 'r') ADVANCE(37);
      END_STATE();
    case 85:
      if (lookahead == 's') ADVANCE(114);
      END_STATE();
    case 86:
      if (lookahead == 's') ADVANCE(56);
      END_STATE();
    case 87:
      if (lookahead == 's') ADVANCE(35);
      END_STATE();
    case 88:
      if (lookahead == 't') ADVANCE(116);
      END_STATE();
    case 89:
      if (lookahead == 't') ADVANCE(119);
      END_STATE();
    case 90:
      if (lookahead == 't') ADVANCE(117);
      END_STATE();
    case 91:
      if (lookahead == 't') ADVANCE(236);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(237);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(50);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(42);
      END_STATE();
    case 96:
      if (lookahead == 'u') ADVANCE(59);
      END_STATE();
    case 97:
      if (lookahead == 'u') ADVANCE(82);
      END_STATE();
    case 98:
      if (lookahead == 'u') ADVANCE(47);
      END_STATE();
    case 99:
      if (lookahead == 'y') ADVANCE(83);
      END_STATE();
    case 100:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(100);
      if (lookahead != 0) ADVANCE(113);
      END_STATE();
    case 101:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(227);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(228);
      END_STATE();
    case 102:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(101);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(228);
      END_STATE();
    case 103:
      if (eof) ADVANCE(106);
      ADVANCE_MAP(
        '!', 141,
        '%', 148,
        '+', 129,
        '-', 131,
        '/', 11,
        ':', 137,
        '?', 135,
        '@', 139,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(103);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(143);
      END_STATE();
    case 104:
      if (eof) ADVANCE(106);
      if (lookahead == '%') ADVANCE(148);
      if (lookahead == '(') ADVANCE(123);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == 'i') ADVANCE(85);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(104);
      END_STATE();
    case 105:
      if (eof) ADVANCE(106);
      if (lookahead == '%') ADVANCE(147);
      if (lookahead == '(') ADVANCE(124);
      if (lookahead == '/') ADVANCE(109);
      if (lookahead == ':') ADVANCE(138);
      if (lookahead == 'i') ADVANCE(111);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(105);
      if (lookahead != 0) ADVANCE(113);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == ' ') ADVANCE(144);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(113);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == ' ') ADVANCE(161);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(113);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == '*') ADVANCE(110);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == '*') ADVANCE(108);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == 's') ADVANCE(115);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(112);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_is);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_is);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_det);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_semidet);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_failure);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_nondet);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_multi);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_undefined);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_COLON_DASH);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(127);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(128);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(133);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(134);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_QMARK);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_AT);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(113);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_functor_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(143);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_pldoc_prolog_directive_token1);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == '!') ADVANCE(157);
      if (lookahead == '%') ADVANCE(157);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(159);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(158);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(160);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(159);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(158);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!') ADVANCE(107);
      if (lookahead == '%') ADVANCE(107);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ' &&
          lookahead != '!') ADVANCE(113);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!') ADVANCE(6);
      if (lookahead == '%') ADVANCE(6);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(149);
      if (lookahead == '\r') ADVANCE(153);
      if (lookahead == '@') ADVANCE(173);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(167);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(150);
      if (lookahead == '\r') ADVANCE(154);
      if (lookahead == '@') ADVANCE(16);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(151);
      if (lookahead == '\r') ADVANCE(155);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(152);
      if (lookahead == '\r') ADVANCE(156);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(169);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == '\n') ADVANCE(149);
      if (lookahead == '\r') ADVANCE(153);
      if (lookahead == '@') ADVANCE(173);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(167);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == '\n') ADVANCE(150);
      if (lookahead == '\r') ADVANCE(154);
      if (lookahead == '@') ADVANCE(16);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == '\n') ADVANCE(151);
      if (lookahead == '\r') ADVANCE(155);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == '\n') ADVANCE(152);
      if (lookahead == '\r') ADVANCE(156);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(169);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token1);
      if (lookahead == ' ') ADVANCE(144);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(158);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(158);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token2);
      if (lookahead == '\n') ADVANCE(160);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(159);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(158);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(160);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR_STAR);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == '/') ADVANCE(165);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '/') ADVANCE(164);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      if (lookahead == '/') ADVANCE(172);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      ADVANCE_MAP(
        '\n', 149,
        '\r', 153,
        '*', 162,
        '/', 13,
        '@', 173,
        '\t', 167,
        0x0b, 167,
        '\f', 167,
        ' ', 167,
      );
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(149);
      if (lookahead == '\r') ADVANCE(153);
      if (lookahead == '*') ADVANCE(162);
      if (lookahead == '@') ADVANCE(173);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(167);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(152);
      if (lookahead == '\r') ADVANCE(156);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == '/') ADVANCE(13);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(169);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(152);
      if (lookahead == '\r') ADVANCE(156);
      if (lookahead == '*') ADVANCE(172);
      if (('\t' <= lookahead && lookahead <= '\f') ||
          lookahead == ' ') ADVANCE(169);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(162);
      if (lookahead == '/') ADVANCE(13);
      if (lookahead == '@') ADVANCE(173);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(171);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(226);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(162);
      if (lookahead == '@') ADVANCE(173);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(171);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(226);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == '/') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      ADVANCE_MAP(
        '*', 172,
        'a', 209,
        'b', 224,
        'c', 203,
        'd', 183,
        'e', 214,
        'l', 196,
        'p', 176,
        's', 189,
        't', 178,
        'v', 190,
      );
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'a') ADVANCE(199);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'a') ADVANCE(221);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'a') ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'a') ADVANCE(223);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'b') ADVANCE(181);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'c') ADVANCE(177);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'c') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'd') ADVANCE(240);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'd') ADVANCE(235);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(234);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(238);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(182);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(184);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(210);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'g') ADVANCE(229);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'g') ADVANCE(239);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'g') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'h') ADVANCE(222);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'h') ADVANCE(206);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'i') ADVANCE(180);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'i') ADVANCE(204);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'i') ADVANCE(193);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'm') ADVANCE(230);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'm') ADVANCE(207);
      if (lookahead == 'p') ADVANCE(225);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'n') ADVANCE(233);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'n') ADVANCE(219);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'o') ADVANCE(200);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'o') ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'o') ADVANCE(211);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'o') ADVANCE(212);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'p') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'p') ADVANCE(217);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'r') ADVANCE(191);
      if (lookahead == 'u') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'r') ADVANCE(218);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'r') ADVANCE(231);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'r') ADVANCE(232);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'r') ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'r') ADVANCE(213);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'r') ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'r') ADVANCE(198);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'r') ADVANCE(187);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 's') ADVANCE(197);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 's') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 't') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 't') ADVANCE(236);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 't') ADVANCE(237);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 't') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'u') ADVANCE(192);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'y') ADVANCE(216);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(aux_sym_pl_tag_text_token1);
      if (lookahead == '\n') ADVANCE(227);
      if (lookahead == '@') ADVANCE(228);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(227);
      if (lookahead != 0) ADVANCE(228);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_pl_tag_text_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(228);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(anon_sym_ATarg);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(anon_sym_ATparam);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(anon_sym_ATerror);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_ATauthor);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_ATversion);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_ATsee);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_ATdeprecated);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_ATcompat);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_ATcopyright);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_ATlicense);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_ATbug);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_ATtbd);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 166},
  [3] = {.lex_state = 166},
  [4] = {.lex_state = 166},
  [5] = {.lex_state = 166},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 8},
  [8] = {.lex_state = 9},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 8},
  [11] = {.lex_state = 9},
  [12] = {.lex_state = 170},
  [13] = {.lex_state = 170},
  [14] = {.lex_state = 9},
  [15] = {.lex_state = 9},
  [16] = {.lex_state = 103},
  [17] = {.lex_state = 170},
  [18] = {.lex_state = 9},
  [19] = {.lex_state = 9},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 9},
  [22] = {.lex_state = 9},
  [23] = {.lex_state = 103},
  [24] = {.lex_state = 103},
  [25] = {.lex_state = 103},
  [26] = {.lex_state = 103},
  [27] = {.lex_state = 103},
  [28] = {.lex_state = 103},
  [29] = {.lex_state = 103},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 5},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 103},
  [34] = {.lex_state = 105},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 9},
  [37] = {.lex_state = 9},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 9},
  [41] = {.lex_state = 103},
  [42] = {.lex_state = 2},
  [43] = {.lex_state = 4},
  [44] = {.lex_state = 104},
  [45] = {.lex_state = 168},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 2},
  [48] = {.lex_state = 104},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 168},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 103},
  [53] = {.lex_state = 104},
  [54] = {.lex_state = 103},
  [55] = {.lex_state = 103},
  [56] = {.lex_state = 103},
  [57] = {.lex_state = 103},
  [58] = {.lex_state = 3},
  [59] = {.lex_state = 3},
  [60] = {.lex_state = 104},
  [61] = {.lex_state = 103},
  [62] = {.lex_state = 103},
  [63] = {.lex_state = 168},
  [64] = {.lex_state = 168},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 104},
  [67] = {.lex_state = 103},
  [68] = {.lex_state = 9},
  [69] = {.lex_state = 103},
  [70] = {.lex_state = 103},
  [71] = {.lex_state = 103},
  [72] = {.lex_state = 103},
  [73] = {.lex_state = 168},
  [74] = {.lex_state = 103},
  [75] = {.lex_state = 103},
  [76] = {.lex_state = 103},
  [77] = {.lex_state = 3},
  [78] = {.lex_state = 168},
  [79] = {.lex_state = 103},
  [80] = {.lex_state = 103},
  [81] = {.lex_state = 3},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 2},
  [84] = {.lex_state = 2},
  [85] = {.lex_state = 103},
  [86] = {.lex_state = 103},
  [87] = {.lex_state = 3},
  [88] = {.lex_state = 168},
  [89] = {.lex_state = 103},
  [90] = {.lex_state = 2},
  [91] = {.lex_state = 2},
  [92] = {.lex_state = 2},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 2},
  [95] = {.lex_state = 2},
  [96] = {.lex_state = 9},
  [97] = {.lex_state = 2},
  [98] = {.lex_state = 2},
  [99] = {.lex_state = 2},
  [100] = {.lex_state = 2},
  [101] = {.lex_state = 2},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 2},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 2},
  [109] = {.lex_state = 2},
  [110] = {.lex_state = 2},
  [111] = {.lex_state = 2},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 100},
  [115] = {.lex_state = 100},
  [116] = {.lex_state = 14},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 14},
  [122] = {.lex_state = 100},
  [123] = {.lex_state = 9},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 100},
  [126] = {.lex_state = 9},
  [127] = {.lex_state = 14},
  [128] = {.lex_state = 100},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 102},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 9},
  [133] = {.lex_state = 100},
  [134] = {.lex_state = 100},
  [135] = {.lex_state = 9},
  [136] = {.lex_state = 100},
  [137] = {.lex_state = 100},
  [138] = {.lex_state = 102},
  [139] = {.lex_state = 100},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 102},
  [142] = {.lex_state = 100},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 100},
  [146] = {.lex_state = 100},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 100},
  [149] = {.lex_state = 100},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_is] = ACTIONS(1),
    [anon_sym_det] = ACTIONS(1),
    [anon_sym_semidet] = ACTIONS(1),
    [anon_sym_failure] = ACTIONS(1),
    [anon_sym_nondet] = ACTIONS(1),
    [anon_sym_multi] = ACTIONS(1),
    [anon_sym_undefined] = ACTIONS(1),
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
    [anon_sym_PERCENT] = ACTIONS(1),
    [aux_sym_prolog_style_description_token1] = ACTIONS(1),
    [aux_sym_prolog_style_description_token2] = ACTIONS(1),
    [anon_sym_SLASH_STAR_STAR] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_STAR_SLASH] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(143),
    [sym_comment] = STATE(32),
    [sym_pldoc_comment] = STATE(112),
    [sym_pldoc_prolog_directive] = STATE(41),
    [sym_pldoc_prolog_style] = STATE(113),
    [sym_pldoc_c_style] = STATE(113),
    [aux_sym_source_file_repeat1] = STATE(32),
    [aux_sym_pldoc_prolog_style_repeat1] = STATE(41),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_pldoc_prolog_directive_token1] = ACTIONS(5),
    [anon_sym_SLASH_STAR_STAR] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(11), 1,
      anon_sym_STAR,
    ACTIONS(13), 1,
      aux_sym_c_style_description_token1,
    STATE(4), 1,
      aux_sym_pldoc_c_style_repeat2,
    STATE(8), 1,
      sym_c_style_description,
    STATE(11), 1,
      aux_sym_c_style_body_repeat1,
    STATE(12), 1,
      aux_sym_c_style_description_repeat1,
    STATE(108), 1,
      sym_c_tag,
    STATE(144), 1,
      sym_c_style_body,
    ACTIONS(9), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(15), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(17), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [46] = 2,
    ACTIONS(19), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(21), 15,
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
  [69] = 4,
    ACTIONS(26), 1,
      anon_sym_STAR,
    STATE(4), 1,
      aux_sym_pldoc_c_style_repeat2,
    ACTIONS(23), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(29), 13,
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
  [96] = 1,
    ACTIONS(29), 17,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
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
  [116] = 4,
    STATE(71), 1,
      sym_pl_tag,
    ACTIONS(31), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(33), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(35), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [141] = 8,
    ACTIONS(37), 1,
      aux_sym_operator_template_token1,
    ACTIONS(41), 1,
      aux_sym_functor_token1,
    STATE(59), 1,
      sym_functor,
    STATE(87), 1,
      sym__head,
    STATE(121), 1,
      sym_arg_name,
    STATE(145), 1,
      sym_arg_spec,
    STATE(94), 2,
      sym_operator_template,
      sym_functor_template,
    ACTIONS(39), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [174] = 6,
    ACTIONS(43), 1,
      anon_sym_STAR,
    ACTIONS(45), 1,
      anon_sym_STAR_SLASH,
    STATE(14), 1,
      aux_sym_c_style_body_repeat1,
    STATE(108), 1,
      sym_c_tag,
    ACTIONS(47), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(49), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [203] = 4,
    STATE(101), 1,
      sym_c_tag,
    ACTIONS(51), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(15), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(17), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [228] = 8,
    ACTIONS(53), 1,
      aux_sym_operator_template_token1,
    ACTIONS(55), 1,
      aux_sym_functor_token1,
    STATE(48), 1,
      sym_functor,
    STATE(66), 1,
      sym__head,
    STATE(121), 1,
      sym_arg_name,
    STATE(142), 1,
      sym_arg_spec,
    STATE(85), 2,
      sym_operator_template,
      sym_functor_template,
    ACTIONS(39), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [261] = 6,
    ACTIONS(43), 1,
      anon_sym_STAR,
    ACTIONS(45), 1,
      anon_sym_STAR_SLASH,
    STATE(15), 1,
      aux_sym_c_style_body_repeat1,
    STATE(108), 1,
      sym_c_tag,
    ACTIONS(47), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(49), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [290] = 3,
    ACTIONS(13), 1,
      aux_sym_c_style_description_token1,
    STATE(13), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(57), 14,
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
  [313] = 3,
    ACTIONS(61), 1,
      aux_sym_c_style_description_token1,
    STATE(13), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(59), 14,
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
  [336] = 6,
    ACTIONS(43), 1,
      anon_sym_STAR,
    ACTIONS(64), 1,
      anon_sym_STAR_SLASH,
    STATE(15), 1,
      aux_sym_c_style_body_repeat1,
    STATE(108), 1,
      sym_c_tag,
    ACTIONS(47), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(49), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [365] = 6,
    ACTIONS(66), 1,
      anon_sym_STAR,
    ACTIONS(69), 1,
      anon_sym_STAR_SLASH,
    STATE(15), 1,
      aux_sym_c_style_body_repeat1,
    STATE(108), 1,
      sym_c_tag,
    ACTIONS(71), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(74), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [394] = 7,
    ACTIONS(83), 1,
      aux_sym_functor_token1,
    ACTIONS(85), 1,
      anon_sym_PERCENT,
    STATE(61), 1,
      sym_arg_name,
    STATE(70), 1,
      sym_arg_spec,
    ACTIONS(81), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(77), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(79), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [424] = 1,
    ACTIONS(59), 15,
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
  [442] = 2,
    ACTIONS(87), 1,
      anon_sym_STAR,
    ACTIONS(89), 13,
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
  [461] = 2,
    ACTIONS(91), 1,
      anon_sym_STAR,
    ACTIONS(69), 13,
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
  [480] = 5,
    ACTIONS(95), 1,
      aux_sym_functor_token1,
    STATE(82), 1,
      sym_arg_name,
    STATE(99), 1,
      sym_arg_spec,
    ACTIONS(85), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    ACTIONS(93), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [505] = 3,
    STATE(101), 1,
      sym_c_tag,
    ACTIONS(47), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(49), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [525] = 3,
    STATE(71), 1,
      sym_pl_tag,
    ACTIONS(97), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(99), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [545] = 6,
    ACTIONS(105), 1,
      aux_sym_functor_token1,
    STATE(24), 1,
      aux_sym__head_repeat1,
    STATE(105), 1,
      sym_arg_name,
    STATE(124), 1,
      sym_arg_spec,
    ACTIONS(103), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(101), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [570] = 6,
    ACTIONS(105), 1,
      aux_sym_functor_token1,
    STATE(25), 1,
      aux_sym__head_repeat1,
    STATE(105), 1,
      sym_arg_name,
    STATE(140), 1,
      sym_arg_spec,
    ACTIONS(103), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(101), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [595] = 6,
    ACTIONS(113), 1,
      aux_sym_functor_token1,
    STATE(25), 1,
      aux_sym__head_repeat1,
    STATE(105), 1,
      sym_arg_name,
    STATE(147), 1,
      sym_arg_spec,
    ACTIONS(110), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(107), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [620] = 6,
    ACTIONS(105), 1,
      aux_sym_functor_token1,
    STATE(25), 1,
      aux_sym__head_repeat1,
    STATE(105), 1,
      sym_arg_name,
    STATE(131), 1,
      sym_arg_spec,
    ACTIONS(103), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(101), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [645] = 6,
    ACTIONS(105), 1,
      aux_sym_functor_token1,
    STATE(26), 1,
      aux_sym__head_repeat1,
    STATE(105), 1,
      sym_arg_name,
    STATE(129), 1,
      sym_arg_spec,
    ACTIONS(103), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(101), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [670] = 5,
    ACTIONS(118), 1,
      aux_sym_functor_token1,
    STATE(82), 1,
      sym_arg_name,
    STATE(95), 1,
      sym_arg_spec,
    ACTIONS(93), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(116), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [692] = 5,
    ACTIONS(83), 1,
      aux_sym_functor_token1,
    STATE(61), 1,
      sym_arg_name,
    STATE(86), 1,
      sym_arg_spec,
    ACTIONS(81), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(79), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [714] = 7,
    ACTIONS(120), 1,
      ts_builtin_sym_end,
    ACTIONS(122), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(125), 1,
      anon_sym_SLASH_STAR_STAR,
    STATE(112), 1,
      sym_pldoc_comment,
    STATE(30), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(41), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(113), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
  [739] = 6,
    ACTIONS(128), 1,
      anon_sym_COLON_DASH,
    ACTIONS(130), 1,
      aux_sym_functor_token1,
    STATE(59), 1,
      sym_functor,
    STATE(87), 1,
      sym__head,
    ACTIONS(51), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
    STATE(91), 3,
      sym__template,
      sym_functor_template,
      sym_directive_template,
  [762] = 7,
    ACTIONS(5), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(7), 1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(132), 1,
      ts_builtin_sym_end,
    STATE(112), 1,
      sym_pldoc_comment,
    STATE(30), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(41), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(113), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
  [787] = 2,
    ACTIONS(136), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(134), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
      aux_sym_functor_token1,
  [801] = 3,
    ACTIONS(140), 2,
      aux_sym_operator_template_token1,
      anon_sym_COLON,
    ACTIONS(138), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(142), 3,
      anon_sym_is,
      anon_sym_LPAREN,
      anon_sym_PERCENT,
  [816] = 5,
    ACTIONS(146), 1,
      anon_sym_PERCENT,
    STATE(39), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(79), 1,
      sym_prolog_style_description,
    ACTIONS(148), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(144), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [835] = 8,
    ACTIONS(148), 1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(150), 1,
      anon_sym_PERCENT,
    ACTIONS(152), 1,
      aux_sym_prolog_style_description_token1,
    STATE(39), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(55), 1,
      aux_sym_prolog_style_body_repeat1,
    STATE(67), 1,
      sym_prolog_style_description,
    STATE(68), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    STATE(102), 1,
      sym_prolog_style_body,
  [860] = 5,
    ACTIONS(154), 1,
      anon_sym_COLON_DASH,
    ACTIONS(156), 1,
      aux_sym_functor_token1,
    STATE(59), 1,
      sym_functor,
    STATE(87), 1,
      sym__head,
    STATE(91), 3,
      sym__template,
      sym_functor_template,
      sym_directive_template,
  [878] = 4,
    ACTIONS(160), 1,
      anon_sym_PERCENT,
    STATE(38), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(162), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(158), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [894] = 4,
    ACTIONS(167), 1,
      anon_sym_PERCENT,
    STATE(38), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(148), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(165), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [910] = 5,
    ACTIONS(169), 1,
      anon_sym_COLON_DASH,
    ACTIONS(171), 1,
      aux_sym_functor_token1,
    STATE(48), 1,
      sym_functor,
    STATE(66), 1,
      sym__head,
    STATE(89), 3,
      sym__template,
      sym_functor_template,
      sym_directive_template,
  [928] = 5,
    ACTIONS(175), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(178), 1,
      anon_sym_PERCENT,
    STATE(36), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(173), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(52), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [946] = 5,
    ACTIONS(182), 1,
      anon_sym_STAR,
    ACTIONS(184), 1,
      anon_sym_STAR_SLASH,
    STATE(2), 1,
      aux_sym_pldoc_c_style_repeat2,
    STATE(47), 1,
      aux_sym_pldoc_c_style_repeat1,
    ACTIONS(180), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [964] = 2,
    ACTIONS(140), 2,
      aux_sym_operator_template_token1,
      anon_sym_COLON,
    ACTIONS(142), 5,
      anon_sym_is,
      anon_sym_LPAREN,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [976] = 2,
    ACTIONS(142), 1,
      anon_sym_PERCENT,
    ACTIONS(138), 5,
      ts_builtin_sym_end,
      anon_sym_is,
      anon_sym_LPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [987] = 4,
    ACTIONS(188), 1,
      aux_sym_c_style_description_token1,
    STATE(63), 1,
      aux_sym_c_style_description_repeat1,
    STATE(103), 1,
      sym_c_style_description,
    ACTIONS(186), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1002] = 1,
    ACTIONS(190), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [1011] = 3,
    ACTIONS(194), 1,
      anon_sym_STAR,
    STATE(47), 1,
      aux_sym_pldoc_c_style_repeat1,
    ACTIONS(192), 4,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
      anon_sym_STAR_SLASH,
  [1024] = 3,
    ACTIONS(199), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 1,
      anon_sym_PERCENT,
    ACTIONS(197), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1037] = 2,
    ACTIONS(158), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(160), 3,
      anon_sym_PERCENT,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [1048] = 4,
    ACTIONS(188), 1,
      aux_sym_c_style_description_token1,
    STATE(63), 1,
      aux_sym_c_style_description_repeat1,
    STATE(92), 1,
      sym_c_style_description,
    ACTIONS(203), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1063] = 1,
    ACTIONS(205), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [1072] = 4,
    ACTIONS(209), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(212), 1,
      anon_sym_PERCENT,
    ACTIONS(207), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(52), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [1087] = 2,
    ACTIONS(216), 1,
      anon_sym_PERCENT,
    ACTIONS(214), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1097] = 3,
    ACTIONS(220), 1,
      anon_sym_PERCENT,
    STATE(56), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(218), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1109] = 3,
    ACTIONS(220), 1,
      anon_sym_PERCENT,
    STATE(56), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(222), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1121] = 3,
    ACTIONS(226), 1,
      anon_sym_PERCENT,
    STATE(56), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(224), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1133] = 2,
    ACTIONS(140), 1,
      anon_sym_PERCENT,
    ACTIONS(229), 4,
      ts_builtin_sym_end,
      anon_sym_COLON,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1143] = 1,
    ACTIONS(142), 5,
      anon_sym_is,
      anon_sym_LPAREN,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1151] = 2,
    ACTIONS(231), 1,
      anon_sym_LPAREN,
    ACTIONS(201), 4,
      anon_sym_is,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1161] = 2,
    ACTIONS(235), 1,
      anon_sym_PERCENT,
    ACTIONS(233), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1171] = 3,
    ACTIONS(239), 1,
      anon_sym_COLON,
    ACTIONS(241), 1,
      anon_sym_PERCENT,
    ACTIONS(237), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1183] = 3,
    ACTIONS(245), 1,
      anon_sym_COLON,
    ACTIONS(247), 1,
      anon_sym_PERCENT,
    ACTIONS(243), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1195] = 3,
    ACTIONS(188), 1,
      aux_sym_c_style_description_token1,
    STATE(64), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(57), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1207] = 3,
    ACTIONS(249), 1,
      aux_sym_c_style_description_token1,
    STATE(64), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(59), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1219] = 1,
    ACTIONS(252), 5,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
      anon_sym_STAR,
      anon_sym_STAR_SLASH,
  [1227] = 3,
    ACTIONS(256), 1,
      anon_sym_is,
    ACTIONS(258), 1,
      anon_sym_PERCENT,
    ACTIONS(254), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1239] = 3,
    ACTIONS(220), 1,
      anon_sym_PERCENT,
    STATE(54), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(222), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1251] = 4,
    ACTIONS(260), 1,
      anon_sym_PERCENT,
    ACTIONS(263), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(265), 1,
      aux_sym_prolog_style_description_token2,
    STATE(68), 1,
      aux_sym_pldoc_prolog_style_repeat2,
  [1264] = 2,
    ACTIONS(269), 1,
      anon_sym_PERCENT,
    ACTIONS(267), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1273] = 2,
    ACTIONS(273), 1,
      anon_sym_PERCENT,
    ACTIONS(271), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1282] = 2,
    ACTIONS(275), 1,
      anon_sym_PERCENT,
    ACTIONS(224), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1291] = 2,
    ACTIONS(279), 1,
      anon_sym_PERCENT,
    ACTIONS(277), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1300] = 2,
    ACTIONS(21), 1,
      aux_sym_c_style_description_token1,
    ACTIONS(281), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1309] = 2,
    ACTIONS(286), 1,
      anon_sym_PERCENT,
    ACTIONS(284), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1318] = 2,
    ACTIONS(290), 1,
      anon_sym_PERCENT,
    ACTIONS(288), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1327] = 2,
    ACTIONS(294), 1,
      anon_sym_PERCENT,
    ACTIONS(292), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1336] = 1,
    ACTIONS(235), 4,
      anon_sym_is,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1343] = 1,
    ACTIONS(59), 4,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
      aux_sym_c_style_description_token1,
  [1350] = 2,
    ACTIONS(298), 1,
      anon_sym_PERCENT,
    ACTIONS(296), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1359] = 2,
    ACTIONS(302), 1,
      anon_sym_PERCENT,
    ACTIONS(300), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1368] = 1,
    ACTIONS(216), 4,
      anon_sym_is,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1375] = 2,
    ACTIONS(304), 1,
      anon_sym_COLON,
    ACTIONS(241), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1384] = 1,
    ACTIONS(140), 4,
      anon_sym_COLON,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1391] = 2,
    ACTIONS(306), 1,
      anon_sym_COLON,
    ACTIONS(247), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1400] = 2,
    ACTIONS(310), 1,
      anon_sym_PERCENT,
    ACTIONS(308), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1409] = 2,
    ACTIONS(85), 1,
      anon_sym_PERCENT,
    ACTIONS(77), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1418] = 2,
    ACTIONS(312), 1,
      anon_sym_is,
    ACTIONS(258), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1427] = 1,
    ACTIONS(314), 4,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
      aux_sym_c_style_description_token1,
  [1434] = 2,
    ACTIONS(318), 1,
      anon_sym_PERCENT,
    ACTIONS(316), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1443] = 1,
    ACTIONS(51), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1449] = 1,
    ACTIONS(320), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1455] = 1,
    ACTIONS(322), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1461] = 1,
    ACTIONS(324), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1467] = 1,
    ACTIONS(310), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1473] = 1,
    ACTIONS(85), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1479] = 2,
    ACTIONS(263), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(265), 2,
      anon_sym_PERCENT,
      aux_sym_prolog_style_description_token2,
  [1487] = 1,
    ACTIONS(279), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1493] = 1,
    ACTIONS(31), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1499] = 1,
    ACTIONS(273), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1505] = 1,
    ACTIONS(326), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1511] = 1,
    ACTIONS(328), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1517] = 1,
    ACTIONS(330), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1523] = 1,
    ACTIONS(332), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1529] = 1,
    ACTIONS(334), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1535] = 2,
    ACTIONS(336), 1,
      anon_sym_COLON,
    ACTIONS(237), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1543] = 1,
    ACTIONS(229), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
  [1549] = 2,
    ACTIONS(338), 1,
      anon_sym_COLON,
    ACTIONS(243), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1557] = 1,
    ACTIONS(340), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1563] = 1,
    ACTIONS(290), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1569] = 1,
    ACTIONS(294), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1575] = 1,
    ACTIONS(302), 3,
      anon_sym_LF,
      anon_sym_CR,
      anon_sym_CR_LF,
  [1581] = 1,
    ACTIONS(342), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1587] = 1,
    ACTIONS(344), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1593] = 2,
    ACTIONS(346), 1,
      aux_sym_operator_template_token1,
    STATE(80), 1,
      sym_type,
  [1600] = 2,
    ACTIONS(348), 1,
      aux_sym_operator_template_token1,
    STATE(50), 1,
      sym_tag_name,
  [1607] = 1,
    ACTIONS(140), 2,
      aux_sym_operator_template_token1,
      anon_sym_COLON,
  [1612] = 2,
    ACTIONS(350), 1,
      anon_sym_STAR,
    STATE(42), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1619] = 1,
    ACTIONS(288), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1624] = 1,
    ACTIONS(292), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1629] = 1,
    ACTIONS(300), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1634] = 2,
    ACTIONS(241), 1,
      aux_sym_operator_template_token1,
    ACTIONS(352), 1,
      anon_sym_COLON,
  [1641] = 2,
    ACTIONS(354), 1,
      aux_sym_operator_template_token1,
    STATE(146), 1,
      sym_type,
  [1648] = 2,
    ACTIONS(356), 1,
      aux_sym_functor_token1,
    STATE(127), 1,
      sym_arg_name,
  [1655] = 2,
    ACTIONS(358), 1,
      anon_sym_COMMA,
    ACTIONS(360), 1,
      anon_sym_RPAREN,
  [1662] = 2,
    ACTIONS(354), 1,
      aux_sym_operator_template_token1,
    STATE(149), 1,
      sym_type,
  [1669] = 2,
    ACTIONS(83), 1,
      aux_sym_functor_token1,
    STATE(62), 1,
      sym_arg_name,
  [1676] = 2,
    ACTIONS(247), 1,
      aux_sym_operator_template_token1,
    ACTIONS(362), 1,
      anon_sym_COLON,
  [1683] = 2,
    ACTIONS(346), 1,
      aux_sym_operator_template_token1,
    STATE(76), 1,
      sym_type,
  [1690] = 2,
    ACTIONS(358), 1,
      anon_sym_COMMA,
    ACTIONS(364), 1,
      anon_sym_RPAREN,
  [1697] = 2,
    ACTIONS(366), 1,
      aux_sym_pl_tag_text_token1,
    STATE(69), 1,
      sym_pl_tag_text,
  [1704] = 2,
    ACTIONS(358), 1,
      anon_sym_COMMA,
    ACTIONS(368), 1,
      anon_sym_RPAREN,
  [1711] = 2,
    ACTIONS(105), 1,
      aux_sym_functor_token1,
    STATE(107), 1,
      sym_arg_name,
  [1718] = 2,
    ACTIONS(370), 1,
      aux_sym_operator_template_token1,
    STATE(119), 1,
      sym_type,
  [1725] = 2,
    ACTIONS(370), 1,
      aux_sym_operator_template_token1,
    STATE(120), 1,
      sym_type,
  [1732] = 2,
    ACTIONS(118), 1,
      aux_sym_functor_token1,
    STATE(84), 1,
      sym_arg_name,
  [1739] = 2,
    ACTIONS(372), 1,
      aux_sym_operator_template_token1,
    STATE(110), 1,
      sym_type,
  [1746] = 2,
    ACTIONS(372), 1,
      aux_sym_operator_template_token1,
    STATE(111), 1,
      sym_type,
  [1753] = 2,
    ACTIONS(366), 1,
      aux_sym_pl_tag_text_token1,
    STATE(74), 1,
      sym_pl_tag_text,
  [1760] = 2,
    ACTIONS(374), 1,
      aux_sym_operator_template_token1,
    STATE(138), 1,
      sym_tag_name,
  [1767] = 2,
    ACTIONS(358), 1,
      anon_sym_COMMA,
    ACTIONS(376), 1,
      anon_sym_RPAREN,
  [1774] = 1,
    ACTIONS(378), 1,
      aux_sym_pl_tag_text_token1,
  [1778] = 1,
    ACTIONS(380), 1,
      aux_sym_operator_template_token1,
  [1782] = 1,
    ACTIONS(382), 1,
      ts_builtin_sym_end,
  [1786] = 1,
    ACTIONS(384), 1,
      anon_sym_STAR_SLASH,
  [1790] = 1,
    ACTIONS(386), 1,
      aux_sym_operator_template_token1,
  [1794] = 1,
    ACTIONS(292), 1,
      aux_sym_operator_template_token1,
  [1798] = 1,
    ACTIONS(358), 1,
      anon_sym_COMMA,
  [1802] = 1,
    ACTIONS(288), 1,
      aux_sym_operator_template_token1,
  [1806] = 1,
    ACTIONS(300), 1,
      aux_sym_operator_template_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 46,
  [SMALL_STATE(4)] = 69,
  [SMALL_STATE(5)] = 96,
  [SMALL_STATE(6)] = 116,
  [SMALL_STATE(7)] = 141,
  [SMALL_STATE(8)] = 174,
  [SMALL_STATE(9)] = 203,
  [SMALL_STATE(10)] = 228,
  [SMALL_STATE(11)] = 261,
  [SMALL_STATE(12)] = 290,
  [SMALL_STATE(13)] = 313,
  [SMALL_STATE(14)] = 336,
  [SMALL_STATE(15)] = 365,
  [SMALL_STATE(16)] = 394,
  [SMALL_STATE(17)] = 424,
  [SMALL_STATE(18)] = 442,
  [SMALL_STATE(19)] = 461,
  [SMALL_STATE(20)] = 480,
  [SMALL_STATE(21)] = 505,
  [SMALL_STATE(22)] = 525,
  [SMALL_STATE(23)] = 545,
  [SMALL_STATE(24)] = 570,
  [SMALL_STATE(25)] = 595,
  [SMALL_STATE(26)] = 620,
  [SMALL_STATE(27)] = 645,
  [SMALL_STATE(28)] = 670,
  [SMALL_STATE(29)] = 692,
  [SMALL_STATE(30)] = 714,
  [SMALL_STATE(31)] = 739,
  [SMALL_STATE(32)] = 762,
  [SMALL_STATE(33)] = 787,
  [SMALL_STATE(34)] = 801,
  [SMALL_STATE(35)] = 816,
  [SMALL_STATE(36)] = 835,
  [SMALL_STATE(37)] = 860,
  [SMALL_STATE(38)] = 878,
  [SMALL_STATE(39)] = 894,
  [SMALL_STATE(40)] = 910,
  [SMALL_STATE(41)] = 928,
  [SMALL_STATE(42)] = 946,
  [SMALL_STATE(43)] = 964,
  [SMALL_STATE(44)] = 976,
  [SMALL_STATE(45)] = 987,
  [SMALL_STATE(46)] = 1002,
  [SMALL_STATE(47)] = 1011,
  [SMALL_STATE(48)] = 1024,
  [SMALL_STATE(49)] = 1037,
  [SMALL_STATE(50)] = 1048,
  [SMALL_STATE(51)] = 1063,
  [SMALL_STATE(52)] = 1072,
  [SMALL_STATE(53)] = 1087,
  [SMALL_STATE(54)] = 1097,
  [SMALL_STATE(55)] = 1109,
  [SMALL_STATE(56)] = 1121,
  [SMALL_STATE(57)] = 1133,
  [SMALL_STATE(58)] = 1143,
  [SMALL_STATE(59)] = 1151,
  [SMALL_STATE(60)] = 1161,
  [SMALL_STATE(61)] = 1171,
  [SMALL_STATE(62)] = 1183,
  [SMALL_STATE(63)] = 1195,
  [SMALL_STATE(64)] = 1207,
  [SMALL_STATE(65)] = 1219,
  [SMALL_STATE(66)] = 1227,
  [SMALL_STATE(67)] = 1239,
  [SMALL_STATE(68)] = 1251,
  [SMALL_STATE(69)] = 1264,
  [SMALL_STATE(70)] = 1273,
  [SMALL_STATE(71)] = 1282,
  [SMALL_STATE(72)] = 1291,
  [SMALL_STATE(73)] = 1300,
  [SMALL_STATE(74)] = 1309,
  [SMALL_STATE(75)] = 1318,
  [SMALL_STATE(76)] = 1327,
  [SMALL_STATE(77)] = 1336,
  [SMALL_STATE(78)] = 1343,
  [SMALL_STATE(79)] = 1350,
  [SMALL_STATE(80)] = 1359,
  [SMALL_STATE(81)] = 1368,
  [SMALL_STATE(82)] = 1375,
  [SMALL_STATE(83)] = 1384,
  [SMALL_STATE(84)] = 1391,
  [SMALL_STATE(85)] = 1400,
  [SMALL_STATE(86)] = 1409,
  [SMALL_STATE(87)] = 1418,
  [SMALL_STATE(88)] = 1427,
  [SMALL_STATE(89)] = 1434,
  [SMALL_STATE(90)] = 1443,
  [SMALL_STATE(91)] = 1449,
  [SMALL_STATE(92)] = 1455,
  [SMALL_STATE(93)] = 1461,
  [SMALL_STATE(94)] = 1467,
  [SMALL_STATE(95)] = 1473,
  [SMALL_STATE(96)] = 1479,
  [SMALL_STATE(97)] = 1487,
  [SMALL_STATE(98)] = 1493,
  [SMALL_STATE(99)] = 1499,
  [SMALL_STATE(100)] = 1505,
  [SMALL_STATE(101)] = 1511,
  [SMALL_STATE(102)] = 1517,
  [SMALL_STATE(103)] = 1523,
  [SMALL_STATE(104)] = 1529,
  [SMALL_STATE(105)] = 1535,
  [SMALL_STATE(106)] = 1543,
  [SMALL_STATE(107)] = 1549,
  [SMALL_STATE(108)] = 1557,
  [SMALL_STATE(109)] = 1563,
  [SMALL_STATE(110)] = 1569,
  [SMALL_STATE(111)] = 1575,
  [SMALL_STATE(112)] = 1581,
  [SMALL_STATE(113)] = 1587,
  [SMALL_STATE(114)] = 1593,
  [SMALL_STATE(115)] = 1600,
  [SMALL_STATE(116)] = 1607,
  [SMALL_STATE(117)] = 1612,
  [SMALL_STATE(118)] = 1619,
  [SMALL_STATE(119)] = 1624,
  [SMALL_STATE(120)] = 1629,
  [SMALL_STATE(121)] = 1634,
  [SMALL_STATE(122)] = 1641,
  [SMALL_STATE(123)] = 1648,
  [SMALL_STATE(124)] = 1655,
  [SMALL_STATE(125)] = 1662,
  [SMALL_STATE(126)] = 1669,
  [SMALL_STATE(127)] = 1676,
  [SMALL_STATE(128)] = 1683,
  [SMALL_STATE(129)] = 1690,
  [SMALL_STATE(130)] = 1697,
  [SMALL_STATE(131)] = 1704,
  [SMALL_STATE(132)] = 1711,
  [SMALL_STATE(133)] = 1718,
  [SMALL_STATE(134)] = 1725,
  [SMALL_STATE(135)] = 1732,
  [SMALL_STATE(136)] = 1739,
  [SMALL_STATE(137)] = 1746,
  [SMALL_STATE(138)] = 1753,
  [SMALL_STATE(139)] = 1760,
  [SMALL_STATE(140)] = 1767,
  [SMALL_STATE(141)] = 1774,
  [SMALL_STATE(142)] = 1778,
  [SMALL_STATE(143)] = 1782,
  [SMALL_STATE(144)] = 1786,
  [SMALL_STATE(145)] = 1790,
  [SMALL_STATE(146)] = 1794,
  [SMALL_STATE(147)] = 1798,
  [SMALL_STATE(148)] = 1802,
  [SMALL_STATE(149)] = 1806,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(115),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 1, 0, 0),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0), SHIFT_REPEAT(4),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0), SHIFT_REPEAT(90),
  [29] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 1, 0, 0),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_style_description, 1, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 2, 0, 0),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [71] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(115),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(45),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 2, 0, 0),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(126),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [107] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0), SHIFT_REPEAT(132),
  [110] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0), SHIFT_REPEAT(132),
  [113] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0), SHIFT_REPEAT(106),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [122] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [125] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(117),
  [128] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [130] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor, 1, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_name, 1, 0, 0),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor, 1, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag_text, 1, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag_text, 1, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [154] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [162] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(100),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0),
  [175] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(40),
  [178] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [180] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [182] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [184] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 1, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [194] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 1, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 1, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 2, 0, 5),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [209] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 5, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 5, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 2, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 1, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [226] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_name, 1, 0, 0),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 4, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 4, 0, 0),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 1, 0, 1),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [241] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 1, 0, 1),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 2, 0, 2),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [247] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 2, 0, 2),
  [249] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(73),
  [252] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 1, 0, 0),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [258] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 1, 0, 0),
  [260] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0), SHIFT_REPEAT(98),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [265] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 2, 0, 6),
  [269] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 2, 0, 6),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 3, 0, 0),
  [273] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 3, 0, 0),
  [275] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 3, 0, 0),
  [279] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 3, 0, 0),
  [281] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 1, 0, 0), SHIFT_REPEAT(78),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 3, 0, 8),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 3, 0, 8),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [290] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1, 0, 0),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 3, 0, 3),
  [294] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 3, 0, 3),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag_text, 2, 0, 0),
  [298] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag_text, 2, 0, 0),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 4, 0, 7),
  [302] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 4, 0, 7),
  [304] = {.entry = {.count = 1, .reusable = false}}, SHIFT(136),
  [306] = {.entry = {.count = 1, .reusable = false}}, SHIFT(137),
  [308] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive_template, 2, 0, 0),
  [310] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive_template, 2, 0, 0),
  [312] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [314] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag_name, 1, 0, 4),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [318] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [320] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [322] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 3, 0, 8),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [326] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [328] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [330] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [332] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 2, 0, 6),
  [334] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [340] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [352] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [362] = {.entry = {.count = 1, .reusable = false}}, SHIFT(125),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(141),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [378] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag_name, 1, 0, 4),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [382] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
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
