#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 143
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 82
#define ALIAS_COUNT 1
#define TOKEN_COUNT 47
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 9

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
  aux_sym_functor_token1 = 25,
  aux_sym_pldoc_prolog_directive_token1 = 26,
  aux_sym_prolog_style_description_token1 = 27,
  aux_sym_prolog_style_description_token2 = 28,
  anon_sym_SLASH_STAR_STAR = 29,
  anon_sym_STAR = 30,
  anon_sym_STAR_SLASH = 31,
  aux_sym_c_style_description_token1 = 32,
  aux_sym_c_style_description_token2 = 33,
  aux_sym_pl_tag_text_token1 = 34,
  anon_sym_ATarg = 35,
  anon_sym_ATparam = 36,
  anon_sym_ATerror = 37,
  anon_sym_ATauthor = 38,
  anon_sym_ATversion = 39,
  anon_sym_ATsee = 40,
  anon_sym_ATdeprecated = 41,
  anon_sym_ATcompat = 42,
  anon_sym_ATcopyright = 43,
  anon_sym_ATlicense = 44,
  anon_sym_ATbug = 45,
  anon_sym_ATtbd = 46,
  sym_source_file = 47,
  sym_comment = 48,
  sym_normal_comment = 49,
  sym_normal_single_line_comment = 50,
  sym__template = 51,
  sym_operator_template = 52,
  sym_functor_template = 53,
  sym_directive_template = 54,
  sym__head = 55,
  sym_arg_spec = 56,
  sym_functor = 57,
  sym_type = 58,
  sym_arg_name = 59,
  sym_pldoc_comment = 60,
  sym_pldoc_prolog_directive = 61,
  sym_pldoc_prolog_style = 62,
  sym_prolog_style_body = 63,
  sym_prolog_style_description = 64,
  sym_pldoc_c_style = 65,
  sym_c_style_body = 66,
  sym_c_style_description = 67,
  sym_tag_name = 68,
  sym_pl_tag_text = 69,
  sym_pl_tag = 70,
  sym_c_tag = 71,
  aux_sym_source_file_repeat1 = 72,
  aux_sym__head_repeat1 = 73,
  aux_sym_pldoc_prolog_style_repeat1 = 74,
  aux_sym_pldoc_prolog_style_repeat2 = 75,
  aux_sym_prolog_style_body_repeat1 = 76,
  aux_sym_prolog_style_description_repeat1 = 77,
  aux_sym_pldoc_c_style_repeat1 = 78,
  aux_sym_pldoc_c_style_repeat2 = 79,
  aux_sym_c_style_body_repeat1 = 80,
  aux_sym_c_style_description_repeat1 = 81,
  anon_alias_sym_name = 82,
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
  [aux_sym_functor_token1] = "functor_token1",
  [aux_sym_pldoc_prolog_directive_token1] = "comment_token",
  [aux_sym_prolog_style_description_token1] = "prolog_style_description_token1",
  [aux_sym_prolog_style_description_token2] = "prolog_style_description_token2",
  [anon_sym_SLASH_STAR_STAR] = "comment_token",
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
  [aux_sym_functor_token1] = aux_sym_functor_token1,
  [aux_sym_pldoc_prolog_directive_token1] = aux_sym_pldoc_prolog_directive_token1,
  [aux_sym_prolog_style_description_token1] = aux_sym_prolog_style_description_token1,
  [aux_sym_prolog_style_description_token2] = aux_sym_prolog_style_description_token2,
  [anon_sym_SLASH_STAR_STAR] = aux_sym_pldoc_prolog_directive_token1,
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
  [aux_sym_functor_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_pldoc_prolog_directive_token1] = {
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
  [4] = 3,
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
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 23,
  [27] = 13,
  [28] = 24,
  [29] = 29,
  [30] = 29,
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
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 50,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 33,
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
  [80] = 80,
  [81] = 81,
  [82] = 45,
  [83] = 46,
  [84] = 84,
  [85] = 9,
  [86] = 11,
  [87] = 87,
  [88] = 88,
  [89] = 42,
  [90] = 90,
  [91] = 87,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 52,
  [96] = 96,
  [97] = 37,
  [98] = 41,
  [99] = 53,
  [100] = 14,
  [101] = 101,
  [102] = 102,
  [103] = 56,
  [104] = 41,
  [105] = 37,
  [106] = 42,
  [107] = 101,
  [108] = 108,
  [109] = 92,
  [110] = 96,
  [111] = 88,
  [112] = 101,
  [113] = 92,
  [114] = 87,
  [115] = 115,
  [116] = 116,
  [117] = 48,
  [118] = 94,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 80,
  [123] = 49,
  [124] = 124,
  [125] = 48,
  [126] = 49,
  [127] = 47,
  [128] = 128,
  [129] = 129,
  [130] = 75,
  [131] = 131,
  [132] = 132,
  [133] = 131,
  [134] = 77,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 67,
  [139] = 47,
  [140] = 135,
  [141] = 141,
  [142] = 142,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(110);
      ADVANCE_MAP(
        0, 121,
        '!', 156,
        '%', 111,
        '(', 138,
        ')', 141,
        '*', 165,
        '+', 144,
        ',', 140,
        '-', 146,
        '/', 15,
        ':', 152,
        '?', 150,
        '@', 154,
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
      ADVANCE_MAP(
        0, 121,
        '\n', 119,
        '!', 156,
        '*', 165,
        '+', 144,
        '-', 146,
        ':', 152,
        '?', 150,
        '@', 154,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(158);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(161);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(161);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead == ' ') ADVANCE(159);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(160);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(118);
      if (lookahead == '@') ADVANCE(20);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(119);
      if (lookahead == '(') ADVANCE(138);
      if (lookahead == 'i') ADVANCE(89);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(119);
      if (lookahead == '(') ADVANCE(139);
      if (lookahead == ':') ADVANCE(153);
      if (lookahead == 'i') ADVANCE(126);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (lookahead != 0) ADVANCE(128);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(119);
      if (lookahead == ':') ADVANCE(16);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(158);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(159);
      END_STATE();
    case 11:
      if (lookahead == ' ') ADVANCE(162);
      END_STATE();
    case 12:
      if (lookahead == '!') ADVANCE(157);
      if (lookahead == '+') ADVANCE(145);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == ':') ADVANCE(153);
      if (lookahead == '?') ADVANCE(151);
      if (lookahead == '@') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(127);
      if (lookahead != 0) ADVANCE(128);
      END_STATE();
    case 13:
      if (lookahead == '%') ADVANCE(112);
      if (lookahead == ':') ADVANCE(16);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(13);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(158);
      END_STATE();
    case 14:
      if (lookahead == '*') ADVANCE(11);
      END_STATE();
    case 15:
      if (lookahead == '*') ADVANCE(14);
      END_STATE();
    case 16:
      if (lookahead == '-') ADVANCE(137);
      END_STATE();
    case 17:
      if (lookahead == '/') ADVANCE(172);
      END_STATE();
    case 18:
      if (lookahead == ':') ADVANCE(153);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (lookahead != 0) ADVANCE(128);
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
      if (lookahead == 'd') ADVANCE(136);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(243);
      END_STATE();
    case 30:
      if (lookahead == 'd') ADVANCE(238);
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
      if (lookahead == 'e') ADVANCE(133);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(237);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(241);
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
      if (lookahead == 'g') ADVANCE(232);
      END_STATE();
    case 51:
      if (lookahead == 'g') ADVANCE(242);
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
      if (lookahead == 'i') ADVANCE(135);
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
      if (lookahead == 'm') ADVANCE(233);
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
      if (lookahead == 'n') ADVANCE(236);
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
      if (lookahead == 'r') ADVANCE(234);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(235);
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
      if (lookahead == 's') ADVANCE(129);
      END_STATE();
    case 90:
      if (lookahead == 's') ADVANCE(60);
      END_STATE();
    case 91:
      if (lookahead == 's') ADVANCE(40);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(131);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(134);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(132);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(54);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(239);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(240);
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
      if (lookahead != 0) ADVANCE(128);
      END_STATE();
    case 105:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(230);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(231);
      END_STATE();
    case 106:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(105);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(231);
      END_STATE();
    case 107:
      if (eof) ADVANCE(110);
      ADVANCE_MAP(
        '!', 156,
        '%', 114,
        '+', 144,
        '-', 146,
        '/', 15,
        ':', 152,
        '?', 150,
        '@', 154,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(107);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(158);
      END_STATE();
    case 108:
      if (eof) ADVANCE(110);
      ADVANCE_MAP(
        '%', 114,
        '(', 138,
        ')', 141,
        '*', 165,
        ',', 140,
        '/', 15,
        ':', 152,
        '@', 20,
        'i', 89,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(108);
      END_STATE();
    case 109:
      if (eof) ADVANCE(110);
      if (lookahead == '%') ADVANCE(113);
      if (lookahead == '(') ADVANCE(139);
      if (lookahead == '/') ADVANCE(124);
      if (lookahead == ':') ADVANCE(153);
      if (lookahead == 'i') ADVANCE(126);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(109);
      if (lookahead != 0) ADVANCE(128);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(161);
      if (lookahead == '!') ADVANCE(4);
      if (lookahead == '%') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(161);
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
          lookahead != '!') ADVANCE(128);
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
      if (lookahead == '@') ADVANCE(173);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(169);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(118);
      if (lookahead == '@') ADVANCE(20);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(119);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(120);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(171);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == ' ') ADVANCE(159);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(128);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == ' ') ADVANCE(162);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(128);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == '*') ADVANCE(125);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(128);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == '*') ADVANCE(123);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(128);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == 's') ADVANCE(130);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(128);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(127);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(128);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(aux_sym_operator_template_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(128);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_is);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_is);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(128);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_det);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_semidet);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_failure);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_nondet);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_multi);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_undefined);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_COLON_DASH);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(128);
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
          lookahead != ' ') ADVANCE(128);
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
          lookahead != ' ') ADVANCE(128);
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
          lookahead != ' ') ADVANCE(128);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(128);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_QMARK);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(128);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(128);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(anon_sym_AT);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(128);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(128);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_functor_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(158);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_pldoc_prolog_directive_token1);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token1);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token2);
      if (lookahead == '\n') ADVANCE(161);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR_STAR);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == '/') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '/') ADVANCE(166);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      if (lookahead == '/') ADVANCE(172);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(117);
      if (lookahead == '*') ADVANCE(163);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '@') ADVANCE(173);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(169);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(117);
      if (lookahead == '*') ADVANCE(163);
      if (lookahead == '@') ADVANCE(173);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(169);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(120);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == '/') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(171);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(120);
      if (lookahead == '*') ADVANCE(172);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(171);
      if (lookahead != 0) ADVANCE(226);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      ADVANCE_MAP(
        '*', 172,
        'a', 211,
        'b', 224,
        'c', 203,
        'd', 185,
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
      if (lookahead == 'a') ADVANCE(220);
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
      if (lookahead == 'c') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'd') ADVANCE(243);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'd') ADVANCE(238);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(237);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(241);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(202);
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
      if (lookahead == 'e') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'e') ADVANCE(212);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'g') ADVANCE(232);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'g') ADVANCE(242);
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
      if (lookahead == 'h') ADVANCE(221);
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
      if (lookahead == 'm') ADVANCE(233);
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
      if (lookahead == 'n') ADVANCE(236);
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
      if (lookahead == 'o') ADVANCE(209);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'o') ADVANCE(210);
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
      if (lookahead == 'r') ADVANCE(234);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'r') ADVANCE(235);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'r') ADVANCE(191);
      if (lookahead == 'u') ADVANCE(222);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 'r') ADVANCE(218);
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
      if (lookahead == 's') ADVANCE(184);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 't') ADVANCE(239);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 't') ADVANCE(240);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(226);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(172);
      if (lookahead == 't') ADVANCE(195);
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
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(164);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '@') ADVANCE(173);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(228);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(226);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(164);
      if (lookahead == '@') ADVANCE(173);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(228);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(226);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(aux_sym_c_style_description_token2);
      if (lookahead == '\n') ADVANCE(229);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(aux_sym_pl_tag_text_token1);
      if (lookahead == '\n') ADVANCE(230);
      if (lookahead == '@') ADVANCE(231);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(230);
      if (lookahead != 0) ADVANCE(231);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(aux_sym_pl_tag_text_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(231);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(anon_sym_ATarg);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(anon_sym_ATparam);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(anon_sym_ATerror);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(anon_sym_ATauthor);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(anon_sym_ATversion);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(anon_sym_ATsee);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(anon_sym_ATdeprecated);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(anon_sym_ATcompat);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(anon_sym_ATcopyright);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(anon_sym_ATlicense);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(anon_sym_ATbug);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(anon_sym_ATtbd);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 108},
  [2] = {.lex_state = 168},
  [3] = {.lex_state = 12},
  [4] = {.lex_state = 12},
  [5] = {.lex_state = 108},
  [6] = {.lex_state = 108},
  [7] = {.lex_state = 108},
  [8] = {.lex_state = 168},
  [9] = {.lex_state = 227},
  [10] = {.lex_state = 108},
  [11] = {.lex_state = 227},
  [12] = {.lex_state = 168},
  [13] = {.lex_state = 107},
  [14] = {.lex_state = 227},
  [15] = {.lex_state = 6},
  [16] = {.lex_state = 6},
  [17] = {.lex_state = 108},
  [18] = {.lex_state = 108},
  [19] = {.lex_state = 108},
  [20] = {.lex_state = 108},
  [21] = {.lex_state = 108},
  [22] = {.lex_state = 108},
  [23] = {.lex_state = 107},
  [24] = {.lex_state = 107},
  [25] = {.lex_state = 107},
  [26] = {.lex_state = 107},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 107},
  [29] = {.lex_state = 107},
  [30] = {.lex_state = 107},
  [31] = {.lex_state = 107},
  [32] = {.lex_state = 9},
  [33] = {.lex_state = 109},
  [34] = {.lex_state = 13},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 108},
  [38] = {.lex_state = 13},
  [39] = {.lex_state = 108},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 108},
  [42] = {.lex_state = 108},
  [43] = {.lex_state = 13},
  [44] = {.lex_state = 108},
  [45] = {.lex_state = 108},
  [46] = {.lex_state = 108},
  [47] = {.lex_state = 108},
  [48] = {.lex_state = 108},
  [49] = {.lex_state = 108},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 108},
  [53] = {.lex_state = 108},
  [54] = {.lex_state = 108},
  [55] = {.lex_state = 1},
  [56] = {.lex_state = 108},
  [57] = {.lex_state = 108},
  [58] = {.lex_state = 8},
  [59] = {.lex_state = 108},
  [60] = {.lex_state = 108},
  [61] = {.lex_state = 108},
  [62] = {.lex_state = 170},
  [63] = {.lex_state = 108},
  [64] = {.lex_state = 108},
  [65] = {.lex_state = 1},
  [66] = {.lex_state = 108},
  [67] = {.lex_state = 108},
  [68] = {.lex_state = 108},
  [69] = {.lex_state = 108},
  [70] = {.lex_state = 13},
  [71] = {.lex_state = 170},
  [72] = {.lex_state = 108},
  [73] = {.lex_state = 108},
  [74] = {.lex_state = 108},
  [75] = {.lex_state = 108},
  [76] = {.lex_state = 108},
  [77] = {.lex_state = 108},
  [78] = {.lex_state = 108},
  [79] = {.lex_state = 108},
  [80] = {.lex_state = 108},
  [81] = {.lex_state = 13},
  [82] = {.lex_state = 7},
  [83] = {.lex_state = 7},
  [84] = {.lex_state = 1},
  [85] = {.lex_state = 170},
  [86] = {.lex_state = 170},
  [87] = {.lex_state = 104},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 18},
  [90] = {.lex_state = 106},
  [91] = {.lex_state = 104},
  [92] = {.lex_state = 104},
  [93] = {.lex_state = 104},
  [94] = {.lex_state = 170},
  [95] = {.lex_state = 7},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 18},
  [98] = {.lex_state = 18},
  [99] = {.lex_state = 7},
  [100] = {.lex_state = 170},
  [101] = {.lex_state = 107},
  [102] = {.lex_state = 104},
  [103] = {.lex_state = 7},
  [104] = {.lex_state = 1},
  [105] = {.lex_state = 1},
  [106] = {.lex_state = 1},
  [107] = {.lex_state = 107},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 104},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 107},
  [113] = {.lex_state = 104},
  [114] = {.lex_state = 104},
  [115] = {.lex_state = 1},
  [116] = {.lex_state = 106},
  [117] = {.lex_state = 104},
  [118] = {.lex_state = 106},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 1},
  [121] = {.lex_state = 1},
  [122] = {.lex_state = 1},
  [123] = {.lex_state = 104},
  [124] = {.lex_state = 1},
  [125] = {.lex_state = 1},
  [126] = {.lex_state = 1},
  [127] = {.lex_state = 1},
  [128] = {.lex_state = 1},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 1},
  [131] = {.lex_state = 104},
  [132] = {.lex_state = 1},
  [133] = {.lex_state = 104},
  [134] = {.lex_state = 1},
  [135] = {.lex_state = 229},
  [136] = {.lex_state = 1},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 1},
  [139] = {.lex_state = 104},
  [140] = {.lex_state = 229},
  [141] = {.lex_state = 1},
  [142] = {.lex_state = 115},
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
    [sym_source_file] = STATE(137),
    [sym_comment] = STATE(20),
    [sym_normal_comment] = STATE(68),
    [sym_normal_single_line_comment] = STATE(66),
    [sym_pldoc_comment] = STATE(68),
    [sym_pldoc_prolog_directive] = STATE(39),
    [sym_pldoc_prolog_style] = STATE(74),
    [sym_pldoc_c_style] = STATE(74),
    [aux_sym_source_file_repeat1] = STATE(20),
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
    STATE(5), 1,
      aux_sym_c_style_body_repeat1,
    STATE(7), 1,
      sym_c_style_description,
    STATE(8), 1,
      aux_sym_pldoc_c_style_repeat2,
    STATE(9), 1,
      aux_sym_c_style_description_repeat1,
    STATE(129), 1,
      sym_c_style_body,
    STATE(141), 1,
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
  [44] = 8,
    ACTIONS(21), 1,
      aux_sym_operator_template_token1,
    ACTIONS(25), 1,
      aux_sym_functor_token1,
    STATE(82), 1,
      sym_functor,
    STATE(95), 1,
      sym__head,
    STATE(98), 1,
      sym_arg_name,
    STATE(131), 1,
      sym_arg_spec,
    STATE(122), 2,
      sym_operator_template,
      sym_functor_template,
    ACTIONS(23), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [77] = 8,
    ACTIONS(27), 1,
      aux_sym_operator_template_token1,
    ACTIONS(29), 1,
      aux_sym_functor_token1,
    STATE(45), 1,
      sym_functor,
    STATE(52), 1,
      sym__head,
    STATE(98), 1,
      sym_arg_name,
    STATE(133), 1,
      sym_arg_spec,
    STATE(80), 2,
      sym_operator_template,
      sym_functor_template,
    ACTIONS(23), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [110] = 6,
    ACTIONS(31), 1,
      anon_sym_STAR,
    ACTIONS(33), 1,
      anon_sym_STAR_SLASH,
    STATE(10), 1,
      aux_sym_c_style_body_repeat1,
    STATE(141), 1,
      sym_c_tag,
    ACTIONS(35), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(37), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [139] = 6,
    ACTIONS(31), 1,
      anon_sym_STAR,
    ACTIONS(39), 1,
      anon_sym_STAR_SLASH,
    STATE(10), 1,
      aux_sym_c_style_body_repeat1,
    STATE(141), 1,
      sym_c_tag,
    ACTIONS(35), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(37), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [168] = 6,
    ACTIONS(31), 1,
      anon_sym_STAR,
    ACTIONS(33), 1,
      anon_sym_STAR_SLASH,
    STATE(6), 1,
      aux_sym_c_style_body_repeat1,
    STATE(141), 1,
      sym_c_tag,
    ACTIONS(35), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(37), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [197] = 4,
    ACTIONS(41), 1,
      anon_sym_LF,
    ACTIONS(44), 1,
      anon_sym_STAR,
    STATE(8), 1,
      aux_sym_pldoc_c_style_repeat2,
    ACTIONS(47), 13,
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
  [222] = 3,
    ACTIONS(15), 1,
      aux_sym_c_style_description_token1,
    STATE(11), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(49), 14,
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
  [245] = 6,
    ACTIONS(51), 1,
      anon_sym_STAR,
    ACTIONS(54), 1,
      anon_sym_STAR_SLASH,
    STATE(10), 1,
      aux_sym_c_style_body_repeat1,
    STATE(141), 1,
      sym_c_tag,
    ACTIONS(56), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(59), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [274] = 3,
    ACTIONS(64), 1,
      aux_sym_c_style_description_token1,
    STATE(11), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(62), 14,
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
  [297] = 1,
    ACTIONS(47), 15,
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
  [315] = 7,
    ACTIONS(69), 1,
      anon_sym_PERCENT,
    ACTIONS(75), 1,
      aux_sym_functor_token1,
    STATE(41), 1,
      sym_arg_name,
    STATE(67), 1,
      sym_arg_spec,
    ACTIONS(73), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(67), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(71), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [345] = 1,
    ACTIONS(62), 15,
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
  [363] = 4,
    ACTIONS(77), 1,
      anon_sym_LF,
    STATE(121), 1,
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
  [386] = 4,
    ACTIONS(79), 1,
      anon_sym_LF,
    STATE(63), 1,
      sym_pl_tag,
    ACTIONS(81), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(83), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [409] = 2,
    ACTIONS(85), 1,
      anon_sym_STAR,
    ACTIONS(87), 13,
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
  [428] = 2,
    ACTIONS(89), 1,
      anon_sym_STAR,
    ACTIONS(54), 13,
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
  [447] = 9,
    ACTIONS(91), 1,
      ts_builtin_sym_end,
    ACTIONS(93), 1,
      anon_sym_PERCENT,
    ACTIONS(96), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(99), 1,
      anon_sym_SLASH_STAR_STAR,
    STATE(66), 1,
      sym_normal_single_line_comment,
    STATE(19), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(39), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(68), 2,
      sym_normal_comment,
      sym_pldoc_comment,
    STATE(74), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
  [479] = 9,
    ACTIONS(5), 1,
      anon_sym_PERCENT,
    ACTIONS(7), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(9), 1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(102), 1,
      ts_builtin_sym_end,
    STATE(66), 1,
      sym_normal_single_line_comment,
    STATE(19), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(39), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(68), 2,
      sym_normal_comment,
      sym_pldoc_comment,
    STATE(74), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
  [511] = 3,
    STATE(63), 1,
      sym_pl_tag,
    ACTIONS(104), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(106), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [531] = 3,
    STATE(121), 1,
      sym_c_tag,
    ACTIONS(35), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(37), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [551] = 6,
    ACTIONS(75), 1,
      aux_sym_functor_token1,
    STATE(24), 1,
      aux_sym__head_repeat1,
    STATE(41), 1,
      sym_arg_name,
    STATE(96), 1,
      sym_arg_spec,
    ACTIONS(73), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(71), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [576] = 6,
    ACTIONS(75), 1,
      aux_sym_functor_token1,
    STATE(25), 1,
      aux_sym__head_repeat1,
    STATE(41), 1,
      sym_arg_name,
    STATE(88), 1,
      sym_arg_spec,
    ACTIONS(73), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(71), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [601] = 6,
    ACTIONS(114), 1,
      aux_sym_functor_token1,
    STATE(25), 1,
      aux_sym__head_repeat1,
    STATE(41), 1,
      sym_arg_name,
    STATE(119), 1,
      sym_arg_spec,
    ACTIONS(111), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(108), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [626] = 6,
    ACTIONS(75), 1,
      aux_sym_functor_token1,
    STATE(28), 1,
      aux_sym__head_repeat1,
    STATE(41), 1,
      sym_arg_name,
    STATE(110), 1,
      sym_arg_spec,
    ACTIONS(73), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(71), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [651] = 5,
    ACTIONS(67), 1,
      anon_sym_LF,
    ACTIONS(119), 1,
      aux_sym_functor_token1,
    STATE(104), 1,
      sym_arg_name,
    STATE(138), 1,
      sym_arg_spec,
    ACTIONS(117), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [674] = 6,
    ACTIONS(75), 1,
      aux_sym_functor_token1,
    STATE(25), 1,
      aux_sym__head_repeat1,
    STATE(41), 1,
      sym_arg_name,
    STATE(111), 1,
      sym_arg_spec,
    ACTIONS(73), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(71), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [699] = 5,
    ACTIONS(123), 1,
      aux_sym_functor_token1,
    STATE(104), 1,
      sym_arg_name,
    STATE(130), 1,
      sym_arg_spec,
    ACTIONS(117), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(121), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [721] = 5,
    ACTIONS(75), 1,
      aux_sym_functor_token1,
    STATE(41), 1,
      sym_arg_name,
    STATE(75), 1,
      sym_arg_spec,
    ACTIONS(73), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(71), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [743] = 2,
    ACTIONS(127), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(125), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
      aux_sym_functor_token1,
  [757] = 6,
    ACTIONS(129), 1,
      anon_sym_LF,
    ACTIONS(131), 1,
      anon_sym_COLON_DASH,
    ACTIONS(133), 1,
      aux_sym_functor_token1,
    STATE(82), 1,
      sym_functor,
    STATE(95), 1,
      sym__head,
    STATE(136), 3,
      sym__template,
      sym_functor_template,
      sym_directive_template,
  [778] = 3,
    ACTIONS(139), 2,
      aux_sym_operator_template_token1,
      anon_sym_COLON,
    ACTIONS(135), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(137), 3,
      anon_sym_PERCENT,
      anon_sym_is,
      anon_sym_LPAREN,
  [793] = 7,
    ACTIONS(141), 1,
      anon_sym_PERCENT,
    STATE(40), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(54), 1,
      sym_prolog_style_description,
    STATE(57), 1,
      aux_sym_prolog_style_body_repeat1,
    STATE(69), 1,
      sym_prolog_style_body,
    STATE(70), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(143), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [816] = 6,
    ACTIONS(143), 1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(147), 1,
      anon_sym_PERCENT,
    ACTIONS(149), 1,
      aux_sym_prolog_style_description_token1,
    STATE(40), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(79), 1,
      sym_prolog_style_description,
    ACTIONS(145), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [837] = 5,
    ACTIONS(153), 1,
      anon_sym_PERCENT,
    ACTIONS(155), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(158), 1,
      aux_sym_prolog_style_description_token2,
    STATE(36), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(151), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [855] = 2,
    ACTIONS(139), 1,
      anon_sym_PERCENT,
    ACTIONS(161), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [867] = 5,
    ACTIONS(163), 1,
      anon_sym_COLON_DASH,
    ACTIONS(165), 1,
      aux_sym_functor_token1,
    STATE(82), 1,
      sym_functor,
    STATE(95), 1,
      sym__head,
    STATE(136), 3,
      sym__template,
      sym_functor_template,
      sym_directive_template,
  [885] = 5,
    ACTIONS(169), 1,
      anon_sym_PERCENT,
    ACTIONS(172), 1,
      aux_sym_pldoc_prolog_directive_token1,
    STATE(34), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(167), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(44), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [903] = 5,
    ACTIONS(177), 1,
      anon_sym_PERCENT,
    ACTIONS(179), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(181), 1,
      aux_sym_prolog_style_description_token2,
    STATE(36), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(175), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [921] = 3,
    ACTIONS(185), 1,
      anon_sym_PERCENT,
    ACTIONS(187), 1,
      anon_sym_COLON,
    ACTIONS(183), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [935] = 3,
    ACTIONS(191), 1,
      anon_sym_PERCENT,
    ACTIONS(193), 1,
      anon_sym_COLON,
    ACTIONS(189), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [949] = 5,
    ACTIONS(195), 1,
      anon_sym_COLON_DASH,
    ACTIONS(197), 1,
      aux_sym_functor_token1,
    STATE(45), 1,
      sym_functor,
    STATE(52), 1,
      sym__head,
    STATE(61), 3,
      sym__template,
      sym_functor_template,
      sym_directive_template,
  [967] = 4,
    ACTIONS(201), 1,
      anon_sym_PERCENT,
    ACTIONS(203), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(199), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(44), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [982] = 3,
    ACTIONS(208), 1,
      anon_sym_PERCENT,
    ACTIONS(210), 1,
      anon_sym_LPAREN,
    ACTIONS(206), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [995] = 2,
    ACTIONS(137), 1,
      anon_sym_PERCENT,
    ACTIONS(135), 5,
      ts_builtin_sym_end,
      anon_sym_is,
      anon_sym_LPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1006] = 2,
    ACTIONS(214), 1,
      anon_sym_PERCENT,
    ACTIONS(212), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1017] = 2,
    ACTIONS(218), 1,
      anon_sym_PERCENT,
    ACTIONS(216), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1028] = 2,
    ACTIONS(222), 1,
      anon_sym_PERCENT,
    ACTIONS(220), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1039] = 1,
    ACTIONS(224), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [1048] = 1,
    ACTIONS(226), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [1057] = 3,
    ACTIONS(230), 1,
      anon_sym_PERCENT,
    ACTIONS(232), 1,
      anon_sym_is,
    ACTIONS(228), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1069] = 2,
    ACTIONS(236), 1,
      anon_sym_PERCENT,
    ACTIONS(234), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1079] = 3,
    ACTIONS(240), 1,
      anon_sym_PERCENT,
    STATE(59), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(238), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1091] = 5,
    ACTIONS(243), 1,
      anon_sym_LF,
    ACTIONS(245), 1,
      anon_sym_STAR,
    ACTIONS(247), 1,
      anon_sym_STAR_SLASH,
    STATE(2), 1,
      aux_sym_pldoc_c_style_repeat2,
    STATE(65), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1107] = 2,
    ACTIONS(251), 1,
      anon_sym_PERCENT,
    ACTIONS(249), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1117] = 3,
    ACTIONS(240), 1,
      anon_sym_PERCENT,
    STATE(60), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(238), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1129] = 3,
    ACTIONS(135), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      anon_sym_is,
      anon_sym_LPAREN,
    ACTIONS(139), 2,
      aux_sym_operator_template_token1,
      anon_sym_COLON,
  [1141] = 3,
    ACTIONS(255), 1,
      anon_sym_PERCENT,
    STATE(60), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(253), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1153] = 3,
    ACTIONS(260), 1,
      anon_sym_PERCENT,
    STATE(60), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(258), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1165] = 2,
    ACTIONS(265), 1,
      anon_sym_PERCENT,
    ACTIONS(263), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1174] = 4,
    ACTIONS(267), 1,
      anon_sym_LF,
    ACTIONS(269), 1,
      aux_sym_c_style_description_token1,
    STATE(85), 1,
      aux_sym_c_style_description_repeat1,
    STATE(120), 1,
      sym_c_style_description,
  [1187] = 2,
    ACTIONS(271), 1,
      anon_sym_PERCENT,
    ACTIONS(258), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1196] = 2,
    ACTIONS(275), 1,
      anon_sym_PERCENT,
    ACTIONS(273), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1205] = 4,
    ACTIONS(277), 1,
      anon_sym_LF,
    ACTIONS(279), 1,
      anon_sym_STAR,
    ACTIONS(282), 1,
      anon_sym_STAR_SLASH,
    STATE(65), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1218] = 2,
    ACTIONS(286), 1,
      anon_sym_PERCENT,
    ACTIONS(284), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1227] = 2,
    ACTIONS(290), 1,
      anon_sym_PERCENT,
    ACTIONS(288), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1236] = 2,
    ACTIONS(294), 1,
      anon_sym_PERCENT,
    ACTIONS(292), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1245] = 2,
    ACTIONS(298), 1,
      anon_sym_PERCENT,
    ACTIONS(296), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1254] = 3,
    ACTIONS(300), 1,
      anon_sym_PERCENT,
    STATE(70), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(303), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [1265] = 4,
    ACTIONS(269), 1,
      aux_sym_c_style_description_token1,
    ACTIONS(305), 1,
      anon_sym_LF,
    STATE(85), 1,
      aux_sym_c_style_description_repeat1,
    STATE(124), 1,
      sym_c_style_description,
  [1278] = 2,
    ACTIONS(309), 1,
      anon_sym_PERCENT,
    ACTIONS(307), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1287] = 2,
    ACTIONS(313), 1,
      anon_sym_PERCENT,
    ACTIONS(311), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1296] = 2,
    ACTIONS(317), 1,
      anon_sym_PERCENT,
    ACTIONS(315), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1305] = 2,
    ACTIONS(69), 1,
      anon_sym_PERCENT,
    ACTIONS(67), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1314] = 2,
    ACTIONS(321), 1,
      anon_sym_PERCENT,
    ACTIONS(319), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1323] = 2,
    ACTIONS(325), 1,
      anon_sym_PERCENT,
    ACTIONS(323), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1332] = 2,
    ACTIONS(329), 1,
      anon_sym_PERCENT,
    ACTIONS(327), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1341] = 2,
    ACTIONS(333), 1,
      anon_sym_PERCENT,
    ACTIONS(331), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1350] = 2,
    ACTIONS(337), 1,
      anon_sym_PERCENT,
    ACTIONS(335), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1359] = 2,
    ACTIONS(339), 1,
      anon_sym_PERCENT,
    ACTIONS(303), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [1367] = 3,
    ACTIONS(206), 1,
      anon_sym_LF,
    ACTIONS(208), 1,
      anon_sym_is,
    ACTIONS(341), 1,
      anon_sym_LPAREN,
  [1377] = 2,
    ACTIONS(135), 1,
      anon_sym_LF,
    ACTIONS(137), 2,
      anon_sym_is,
      anon_sym_LPAREN,
  [1385] = 2,
    ACTIONS(343), 1,
      anon_sym_LF,
    ACTIONS(345), 2,
      anon_sym_STAR,
      anon_sym_STAR_SLASH,
  [1393] = 3,
    ACTIONS(49), 1,
      anon_sym_LF,
    ACTIONS(269), 1,
      aux_sym_c_style_description_token1,
    STATE(86), 1,
      aux_sym_c_style_description_repeat1,
  [1403] = 3,
    ACTIONS(62), 1,
      anon_sym_LF,
    ACTIONS(347), 1,
      aux_sym_c_style_description_token1,
    STATE(86), 1,
      aux_sym_c_style_description_repeat1,
  [1413] = 2,
    ACTIONS(350), 1,
      aux_sym_operator_template_token1,
    STATE(47), 1,
      sym_type,
  [1420] = 2,
    ACTIONS(352), 1,
      anon_sym_COMMA,
    ACTIONS(354), 1,
      anon_sym_RPAREN,
  [1427] = 2,
    ACTIONS(191), 1,
      aux_sym_operator_template_token1,
    ACTIONS(356), 1,
      anon_sym_COLON,
  [1434] = 2,
    ACTIONS(358), 1,
      aux_sym_pl_tag_text_token1,
    STATE(78), 1,
      sym_pl_tag_text,
  [1441] = 2,
    ACTIONS(360), 1,
      aux_sym_operator_template_token1,
    STATE(139), 1,
      sym_type,
  [1448] = 2,
    ACTIONS(360), 1,
      aux_sym_operator_template_token1,
    STATE(123), 1,
      sym_type,
  [1455] = 2,
    ACTIONS(362), 1,
      aux_sym_operator_template_token1,
    STATE(90), 1,
      sym_tag_name,
  [1462] = 1,
    ACTIONS(364), 2,
      anon_sym_LF,
      aux_sym_c_style_description_token1,
  [1467] = 2,
    ACTIONS(228), 1,
      anon_sym_LF,
    ACTIONS(366), 1,
      anon_sym_is,
  [1474] = 2,
    ACTIONS(352), 1,
      anon_sym_COMMA,
    ACTIONS(368), 1,
      anon_sym_RPAREN,
  [1481] = 1,
    ACTIONS(139), 2,
      aux_sym_operator_template_token1,
      anon_sym_COLON,
  [1486] = 2,
    ACTIONS(185), 1,
      aux_sym_operator_template_token1,
    ACTIONS(370), 1,
      anon_sym_COLON,
  [1493] = 2,
    ACTIONS(234), 1,
      anon_sym_LF,
    ACTIONS(236), 1,
      anon_sym_is,
  [1500] = 1,
    ACTIONS(62), 2,
      anon_sym_LF,
      aux_sym_c_style_description_token1,
  [1505] = 2,
    ACTIONS(372), 1,
      aux_sym_functor_token1,
    STATE(89), 1,
      sym_arg_name,
  [1512] = 2,
    ACTIONS(374), 1,
      aux_sym_operator_template_token1,
    STATE(71), 1,
      sym_tag_name,
  [1519] = 2,
    ACTIONS(249), 1,
      anon_sym_LF,
    ACTIONS(251), 1,
      anon_sym_is,
  [1526] = 2,
    ACTIONS(183), 1,
      anon_sym_LF,
    ACTIONS(376), 1,
      anon_sym_COLON,
  [1533] = 2,
    ACTIONS(139), 1,
      anon_sym_COLON,
    ACTIONS(161), 1,
      anon_sym_LF,
  [1540] = 2,
    ACTIONS(189), 1,
      anon_sym_LF,
    ACTIONS(378), 1,
      anon_sym_COLON,
  [1547] = 2,
    ACTIONS(75), 1,
      aux_sym_functor_token1,
    STATE(42), 1,
      sym_arg_name,
  [1554] = 2,
    ACTIONS(380), 1,
      anon_sym_STAR,
    STATE(55), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1561] = 2,
    ACTIONS(350), 1,
      aux_sym_operator_template_token1,
    STATE(49), 1,
      sym_type,
  [1568] = 2,
    ACTIONS(352), 1,
      anon_sym_COMMA,
    ACTIONS(382), 1,
      anon_sym_RPAREN,
  [1575] = 2,
    ACTIONS(352), 1,
      anon_sym_COMMA,
    ACTIONS(384), 1,
      anon_sym_RPAREN,
  [1582] = 2,
    ACTIONS(123), 1,
      aux_sym_functor_token1,
    STATE(106), 1,
      sym_arg_name,
  [1589] = 2,
    ACTIONS(386), 1,
      aux_sym_operator_template_token1,
    STATE(126), 1,
      sym_type,
  [1596] = 2,
    ACTIONS(386), 1,
      aux_sym_operator_template_token1,
    STATE(127), 1,
      sym_type,
  [1603] = 2,
    ACTIONS(388), 1,
      anon_sym_LF,
    ACTIONS(390), 1,
      anon_sym_NULL,
  [1610] = 2,
    ACTIONS(358), 1,
      aux_sym_pl_tag_text_token1,
    STATE(76), 1,
      sym_pl_tag_text,
  [1617] = 1,
    ACTIONS(216), 1,
      aux_sym_operator_template_token1,
  [1621] = 1,
    ACTIONS(392), 1,
      aux_sym_pl_tag_text_token1,
  [1625] = 1,
    ACTIONS(352), 1,
      anon_sym_COMMA,
  [1629] = 1,
    ACTIONS(394), 1,
      anon_sym_LF,
  [1633] = 1,
    ACTIONS(396), 1,
      anon_sym_LF,
  [1637] = 1,
    ACTIONS(335), 1,
      anon_sym_LF,
  [1641] = 1,
    ACTIONS(220), 1,
      aux_sym_operator_template_token1,
  [1645] = 1,
    ACTIONS(398), 1,
      anon_sym_LF,
  [1649] = 1,
    ACTIONS(216), 1,
      anon_sym_LF,
  [1653] = 1,
    ACTIONS(220), 1,
      anon_sym_LF,
  [1657] = 1,
    ACTIONS(212), 1,
      anon_sym_LF,
  [1661] = 1,
    ACTIONS(129), 1,
      anon_sym_LF,
  [1665] = 1,
    ACTIONS(400), 1,
      anon_sym_STAR_SLASH,
  [1669] = 1,
    ACTIONS(67), 1,
      anon_sym_LF,
  [1673] = 1,
    ACTIONS(402), 1,
      aux_sym_operator_template_token1,
  [1677] = 1,
    ACTIONS(404), 1,
      anon_sym_LF,
  [1681] = 1,
    ACTIONS(406), 1,
      aux_sym_operator_template_token1,
  [1685] = 1,
    ACTIONS(323), 1,
      anon_sym_LF,
  [1689] = 1,
    ACTIONS(408), 1,
      aux_sym_c_style_description_token2,
  [1693] = 1,
    ACTIONS(410), 1,
      anon_sym_LF,
  [1697] = 1,
    ACTIONS(412), 1,
      ts_builtin_sym_end,
  [1701] = 1,
    ACTIONS(288), 1,
      anon_sym_LF,
  [1705] = 1,
    ACTIONS(212), 1,
      aux_sym_operator_template_token1,
  [1709] = 1,
    ACTIONS(414), 1,
      aux_sym_c_style_description_token2,
  [1713] = 1,
    ACTIONS(416), 1,
      anon_sym_LF,
  [1717] = 1,
    ACTIONS(418), 1,
      aux_sym_normal_single_line_comment_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 44,
  [SMALL_STATE(4)] = 77,
  [SMALL_STATE(5)] = 110,
  [SMALL_STATE(6)] = 139,
  [SMALL_STATE(7)] = 168,
  [SMALL_STATE(8)] = 197,
  [SMALL_STATE(9)] = 222,
  [SMALL_STATE(10)] = 245,
  [SMALL_STATE(11)] = 274,
  [SMALL_STATE(12)] = 297,
  [SMALL_STATE(13)] = 315,
  [SMALL_STATE(14)] = 345,
  [SMALL_STATE(15)] = 363,
  [SMALL_STATE(16)] = 386,
  [SMALL_STATE(17)] = 409,
  [SMALL_STATE(18)] = 428,
  [SMALL_STATE(19)] = 447,
  [SMALL_STATE(20)] = 479,
  [SMALL_STATE(21)] = 511,
  [SMALL_STATE(22)] = 531,
  [SMALL_STATE(23)] = 551,
  [SMALL_STATE(24)] = 576,
  [SMALL_STATE(25)] = 601,
  [SMALL_STATE(26)] = 626,
  [SMALL_STATE(27)] = 651,
  [SMALL_STATE(28)] = 674,
  [SMALL_STATE(29)] = 699,
  [SMALL_STATE(30)] = 721,
  [SMALL_STATE(31)] = 743,
  [SMALL_STATE(32)] = 757,
  [SMALL_STATE(33)] = 778,
  [SMALL_STATE(34)] = 793,
  [SMALL_STATE(35)] = 816,
  [SMALL_STATE(36)] = 837,
  [SMALL_STATE(37)] = 855,
  [SMALL_STATE(38)] = 867,
  [SMALL_STATE(39)] = 885,
  [SMALL_STATE(40)] = 903,
  [SMALL_STATE(41)] = 921,
  [SMALL_STATE(42)] = 935,
  [SMALL_STATE(43)] = 949,
  [SMALL_STATE(44)] = 967,
  [SMALL_STATE(45)] = 982,
  [SMALL_STATE(46)] = 995,
  [SMALL_STATE(47)] = 1006,
  [SMALL_STATE(48)] = 1017,
  [SMALL_STATE(49)] = 1028,
  [SMALL_STATE(50)] = 1039,
  [SMALL_STATE(51)] = 1048,
  [SMALL_STATE(52)] = 1057,
  [SMALL_STATE(53)] = 1069,
  [SMALL_STATE(54)] = 1079,
  [SMALL_STATE(55)] = 1091,
  [SMALL_STATE(56)] = 1107,
  [SMALL_STATE(57)] = 1117,
  [SMALL_STATE(58)] = 1129,
  [SMALL_STATE(59)] = 1141,
  [SMALL_STATE(60)] = 1153,
  [SMALL_STATE(61)] = 1165,
  [SMALL_STATE(62)] = 1174,
  [SMALL_STATE(63)] = 1187,
  [SMALL_STATE(64)] = 1196,
  [SMALL_STATE(65)] = 1205,
  [SMALL_STATE(66)] = 1218,
  [SMALL_STATE(67)] = 1227,
  [SMALL_STATE(68)] = 1236,
  [SMALL_STATE(69)] = 1245,
  [SMALL_STATE(70)] = 1254,
  [SMALL_STATE(71)] = 1265,
  [SMALL_STATE(72)] = 1278,
  [SMALL_STATE(73)] = 1287,
  [SMALL_STATE(74)] = 1296,
  [SMALL_STATE(75)] = 1305,
  [SMALL_STATE(76)] = 1314,
  [SMALL_STATE(77)] = 1323,
  [SMALL_STATE(78)] = 1332,
  [SMALL_STATE(79)] = 1341,
  [SMALL_STATE(80)] = 1350,
  [SMALL_STATE(81)] = 1359,
  [SMALL_STATE(82)] = 1367,
  [SMALL_STATE(83)] = 1377,
  [SMALL_STATE(84)] = 1385,
  [SMALL_STATE(85)] = 1393,
  [SMALL_STATE(86)] = 1403,
  [SMALL_STATE(87)] = 1413,
  [SMALL_STATE(88)] = 1420,
  [SMALL_STATE(89)] = 1427,
  [SMALL_STATE(90)] = 1434,
  [SMALL_STATE(91)] = 1441,
  [SMALL_STATE(92)] = 1448,
  [SMALL_STATE(93)] = 1455,
  [SMALL_STATE(94)] = 1462,
  [SMALL_STATE(95)] = 1467,
  [SMALL_STATE(96)] = 1474,
  [SMALL_STATE(97)] = 1481,
  [SMALL_STATE(98)] = 1486,
  [SMALL_STATE(99)] = 1493,
  [SMALL_STATE(100)] = 1500,
  [SMALL_STATE(101)] = 1505,
  [SMALL_STATE(102)] = 1512,
  [SMALL_STATE(103)] = 1519,
  [SMALL_STATE(104)] = 1526,
  [SMALL_STATE(105)] = 1533,
  [SMALL_STATE(106)] = 1540,
  [SMALL_STATE(107)] = 1547,
  [SMALL_STATE(108)] = 1554,
  [SMALL_STATE(109)] = 1561,
  [SMALL_STATE(110)] = 1568,
  [SMALL_STATE(111)] = 1575,
  [SMALL_STATE(112)] = 1582,
  [SMALL_STATE(113)] = 1589,
  [SMALL_STATE(114)] = 1596,
  [SMALL_STATE(115)] = 1603,
  [SMALL_STATE(116)] = 1610,
  [SMALL_STATE(117)] = 1617,
  [SMALL_STATE(118)] = 1621,
  [SMALL_STATE(119)] = 1625,
  [SMALL_STATE(120)] = 1629,
  [SMALL_STATE(121)] = 1633,
  [SMALL_STATE(122)] = 1637,
  [SMALL_STATE(123)] = 1641,
  [SMALL_STATE(124)] = 1645,
  [SMALL_STATE(125)] = 1649,
  [SMALL_STATE(126)] = 1653,
  [SMALL_STATE(127)] = 1657,
  [SMALL_STATE(128)] = 1661,
  [SMALL_STATE(129)] = 1665,
  [SMALL_STATE(130)] = 1669,
  [SMALL_STATE(131)] = 1673,
  [SMALL_STATE(132)] = 1677,
  [SMALL_STATE(133)] = 1681,
  [SMALL_STATE(134)] = 1685,
  [SMALL_STATE(135)] = 1689,
  [SMALL_STATE(136)] = 1693,
  [SMALL_STATE(137)] = 1697,
  [SMALL_STATE(138)] = 1701,
  [SMALL_STATE(139)] = 1705,
  [SMALL_STATE(140)] = 1709,
  [SMALL_STATE(141)] = 1713,
  [SMALL_STATE(142)] = 1717,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(142),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 1, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 2, 0, 0),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0), SHIFT_REPEAT(8),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0), SHIFT_REPEAT(128),
  [47] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_style_description, 1, 0, 0),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(102),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(62),
  [62] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(140),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 2, 0, 0),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 2, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(116),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(142),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(108),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [108] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0), SHIFT_REPEAT(107),
  [111] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0), SHIFT_REPEAT(107),
  [114] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0), SHIFT_REPEAT(37),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor, 1, 0, 0),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor, 1, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_name, 1, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag_text, 1, 0, 0),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag_text, 1, 0, 0),
  [149] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [155] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [158] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(36),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_name, 1, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0),
  [169] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(132),
  [172] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(43),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [179] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 1, 0, 1),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 1, 0, 1),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 2, 0, 2),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 2, 0, 2),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [197] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [203] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 1, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 1, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 4, 0, 7),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 4, 0, 7),
  [216] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 3, 0, 3),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 3, 0, 3),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 1, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 1, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 4, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 4, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 1, 0, 0),
  [240] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 1, 0, 0), SHIFT(21),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [245] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [247] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 5, 0, 0),
  [251] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 5, 0, 0),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 2, 0, 0),
  [255] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 2, 0, 0), SHIFT(21),
  [258] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [260] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [265] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [267] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 1, 0, 0),
  [269] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [271] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [275] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [279] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 3, 0, 0),
  [290] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 3, 0, 0),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [294] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 1, 0, 0),
  [296] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [298] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [300] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0), SHIFT_REPEAT(132),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [305] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 2, 0, 5),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [309] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [313] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [317] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [319] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 2, 0, 6),
  [321] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 2, 0, 6),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 3, 0, 0),
  [325] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 3, 0, 0),
  [327] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 3, 0, 8),
  [329] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 3, 0, 8),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag_text, 2, 0, 0),
  [333] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag_text, 2, 0, 0),
  [335] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive_template, 2, 0, 0),
  [337] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive_template, 2, 0, 0),
  [339] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [341] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [345] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [347] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(135),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [356] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [364] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag_name, 1, 0, 4),
  [366] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [370] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [376] = {.entry = {.count = 1, .reusable = false}}, SHIFT(113),
  [378] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [382] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [384] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [386] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [388] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [390] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [392] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag_name, 1, 0, 4),
  [394] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 2, 0, 6),
  [396] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [398] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 3, 0, 8),
  [400] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [402] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [412] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [414] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [416] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [418] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
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
