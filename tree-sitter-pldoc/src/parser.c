#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 122
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 74
#define ALIAS_COUNT 1
#define TOKEN_COUNT 41
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 6

enum ts_symbol_identifiers {
  anon_sym_PERCENT = 1,
  aux_sym_normal_single_line_comment_token1 = 2,
  anon_sym_LF = 3,
  anon_sym_NULL = 4,
  anon_sym_is = 5,
  anon_sym_det = 6,
  anon_sym_semidet = 7,
  anon_sym_failure = 8,
  anon_sym_nondet = 9,
  anon_sym_multi = 10,
  anon_sym_undefined = 11,
  anon_sym_COLON_DASH = 12,
  anon_sym_LPAREN = 13,
  anon_sym_COMMA = 14,
  anon_sym_RPAREN = 15,
  aux_sym_arg_spec_token1 = 16,
  anon_sym_COLON = 17,
  sym_functor = 18,
  aux_sym_type_token1 = 19,
  aux_sym_pldoc_prolog_directive_token1 = 20,
  aux_sym_prolog_style_description_token1 = 21,
  aux_sym_prolog_style_description_token2 = 22,
  anon_sym_SLASH_STAR_STAR = 23,
  anon_sym_STAR = 24,
  anon_sym_STAR_SLASH = 25,
  aux_sym_c_style_description_token1 = 26,
  aux_sym_c_style_description_token2 = 27,
  aux_sym_pl_tag_text_token1 = 28,
  anon_sym_ATarg = 29,
  anon_sym_ATparam = 30,
  anon_sym_ATerror = 31,
  anon_sym_ATauthor = 32,
  anon_sym_ATversion = 33,
  anon_sym_ATsee = 34,
  anon_sym_ATdeprecated = 35,
  anon_sym_ATcompat = 36,
  anon_sym_ATcopyright = 37,
  anon_sym_ATlicense = 38,
  anon_sym_ATbug = 39,
  anon_sym_ATtbd = 40,
  sym_source_file = 41,
  sym_comment = 42,
  sym_normal_comment = 43,
  sym_normal_single_line_comment = 44,
  sym__template = 45,
  sym_operator_template = 46,
  sym_functor_template = 47,
  sym_directive_template = 48,
  sym__head = 49,
  sym_arg_spec = 50,
  sym_type = 51,
  sym_pldoc_comment = 52,
  sym_pldoc_prolog_directive = 53,
  sym_pldoc_prolog_style = 54,
  sym_prolog_style_body = 55,
  sym_prolog_style_description = 56,
  sym_pldoc_c_style = 57,
  sym_c_style_body = 58,
  sym_c_style_description = 59,
  sym_tag_name = 60,
  sym_pl_tag_text = 61,
  sym_pl_tag = 62,
  sym_c_tag = 63,
  aux_sym_source_file_repeat1 = 64,
  aux_sym__head_repeat1 = 65,
  aux_sym_pldoc_prolog_style_repeat1 = 66,
  aux_sym_pldoc_prolog_style_repeat2 = 67,
  aux_sym_prolog_style_body_repeat1 = 68,
  aux_sym_prolog_style_description_repeat1 = 69,
  aux_sym_pldoc_c_style_repeat1 = 70,
  aux_sym_pldoc_c_style_repeat2 = 71,
  aux_sym_c_style_body_repeat1 = 72,
  aux_sym_c_style_description_repeat1 = 73,
  anon_alias_sym_name = 74,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_PERCENT] = "%",
  [aux_sym_normal_single_line_comment_token1] = "normal_single_line_comment_token1",
  [anon_sym_LF] = "\n",
  [anon_sym_NULL] = "\0",
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
  [aux_sym_arg_spec_token1] = "arg_spec_token1",
  [anon_sym_COLON] = ":",
  [sym_functor] = "functor",
  [aux_sym_type_token1] = "type_token1",
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
  [sym_type] = "type",
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
  [aux_sym_arg_spec_token1] = aux_sym_arg_spec_token1,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_functor] = sym_functor,
  [aux_sym_type_token1] = aux_sym_type_token1,
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
  [sym_type] = sym_type,
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
  [aux_sym_arg_spec_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [sym_functor] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_type_token1] = {
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
  [sym_type] = {
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
  field_name = 2,
  field_type = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_description] = "description",
  [field_name] = "name",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [3] = {.index = 1, .length = 1},
  [4] = {.index = 2, .length = 1},
  [5] = {.index = 3, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_type, 2},
  [1] =
    {field_name, 1},
  [2] =
    {field_description, 1},
  [3] =
    {field_description, 2},
    {field_name, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [2] = {
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
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 30,
  [37] = 34,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 23,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
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
  [71] = 7,
  [72] = 3,
  [73] = 32,
  [74] = 74,
  [75] = 68,
  [76] = 74,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 46,
  [84] = 84,
  [85] = 85,
  [86] = 42,
  [87] = 11,
  [88] = 26,
  [89] = 45,
  [90] = 26,
  [91] = 91,
  [92] = 84,
  [93] = 93,
  [94] = 85,
  [95] = 82,
  [96] = 84,
  [97] = 97,
  [98] = 97,
  [99] = 33,
  [100] = 100,
  [101] = 65,
  [102] = 62,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 91,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 35,
  [111] = 33,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 35,
  [116] = 116,
  [117] = 109,
  [118] = 52,
  [119] = 55,
  [120] = 120,
  [121] = 121,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(111);
      ADVANCE_MAP(
        0, 123,
        '%', 112,
        '(', 132,
        ')', 134,
        '*', 151,
        ',', 133,
        '/', 14,
        ':', 136,
        '@', 19,
        'd', 34,
        'f', 20,
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
      if ((!eof && lookahead == 00)) ADVANCE(123);
      if (lookahead == '\n') ADVANCE(120);
      if (lookahead == '*') ADVANCE(151);
      if (lookahead == ':') ADVANCE(136);
      if (lookahead == 'i') ADVANCE(89);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(146);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(146);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(145);
      if (lookahead == ' ') ADVANCE(144);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(145);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(118);
      if (lookahead == '@') ADVANCE(19);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(119);
      if (lookahead == '!') ADVANCE(108);
      if (lookahead == '+') ADVANCE(138);
      if (lookahead == '-') ADVANCE(139);
      if (lookahead == ':') ADVANCE(140);
      if (lookahead == '?' ||
          lookahead == '@') ADVANCE(141);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '9') ||
          ('<' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(142);
      END_STATE();
    case 8:
      ADVANCE_MAP(
        '\n', 121,
        '(', 132,
        '+', 15,
        '-', 16,
        'i', 89,
        '!', 108,
        ':', 108,
        '?', 108,
        '@', 108,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      END_STATE();
    case 9:
      if (lookahead == ' ') ADVANCE(144);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(147);
      END_STATE();
    case 11:
      if (lookahead == '!') ADVANCE(108);
      if (lookahead == '%') ADVANCE(113);
      if (lookahead == '+') ADVANCE(138);
      if (lookahead == '-') ADVANCE(139);
      if (lookahead == ':') ADVANCE(140);
      if (lookahead == '?' ||
          lookahead == '@') ADVANCE(141);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('#' <= lookahead && lookahead <= '&') ||
          ('*' <= lookahead && lookahead <= '9') ||
          ('<' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(142);
      END_STATE();
    case 12:
      if (lookahead == '!') ADVANCE(108);
      if (lookahead == '+') ADVANCE(138);
      if (lookahead == '-') ADVANCE(139);
      if (lookahead == ':' ||
          lookahead == '?' ||
          lookahead == '@') ADVANCE(141);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      if (lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '9') ||
          ('<' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(142);
      END_STATE();
    case 13:
      if (lookahead == '*') ADVANCE(10);
      END_STATE();
    case 14:
      if (lookahead == '*') ADVANCE(13);
      END_STATE();
    case 15:
      if (lookahead == '+') ADVANCE(108);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(135);
      END_STATE();
    case 16:
      if (lookahead == '-') ADVANCE(108);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(135);
      END_STATE();
    case 17:
      if (lookahead == '/') ADVANCE(158);
      END_STATE();
    case 18:
      if (lookahead == ':') ADVANCE(137);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(18);
      if (lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '9') ||
          ('<' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(142);
      END_STATE();
    case 19:
      ADVANCE_MAP(
        'a', 79,
        'b', 101,
        'c', 72,
        'd', 36,
        'e', 83,
        'l', 55,
        'p', 22,
        's', 47,
        't', 25,
        'v', 43,
      );
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(64);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(84);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(95);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(99);
      END_STATE();
    case 25:
      if (lookahead == 'b') ADVANCE(28);
      END_STATE();
    case 26:
      if (lookahead == 'c') ADVANCE(41);
      END_STATE();
    case 27:
      if (lookahead == 'c') ADVANCE(24);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(229);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(130);
      END_STATE();
    case 30:
      if (lookahead == 'd') ADVANCE(224);
      END_STATE();
    case 31:
      if (lookahead == 'd') ADVANCE(38);
      END_STATE();
    case 32:
      if (lookahead == 'd') ADVANCE(44);
      END_STATE();
    case 33:
      if (lookahead == 'd') ADVANCE(48);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(223);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(49);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(127);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(227);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(69);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(82);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(94);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(29);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(30);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(37);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(96);
      END_STATE();
    case 49:
      if (lookahead == 'f') ADVANCE(58);
      END_STATE();
    case 50:
      if (lookahead == 'g') ADVANCE(218);
      END_STATE();
    case 51:
      if (lookahead == 'g') ADVANCE(228);
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
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(129);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(62);
      END_STATE();
    case 58:
      if (lookahead == 'i') ADVANCE(71);
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
      if (lookahead == 'l') ADVANCE(102);
      END_STATE();
    case 63:
      if (lookahead == 'l') ADVANCE(98);
      END_STATE();
    case 64:
      if (lookahead == 'm') ADVANCE(219);
      END_STATE();
    case 65:
      if (lookahead == 'm') ADVANCE(77);
      if (lookahead == 'p') ADVANCE(103);
      END_STATE();
    case 66:
      if (lookahead == 'm') ADVANCE(61);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(31);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(222);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(91);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(32);
      END_STATE();
    case 71:
      if (lookahead == 'n') ADVANCE(45);
      END_STATE();
    case 72:
      if (lookahead == 'o') ADVANCE(65);
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
      if (lookahead == 'o') ADVANCE(70);
      END_STATE();
    case 77:
      if (lookahead == 'p') ADVANCE(23);
      END_STATE();
    case 78:
      if (lookahead == 'p') ADVANCE(87);
      END_STATE();
    case 79:
      if (lookahead == 'r') ADVANCE(50);
      if (lookahead == 'u') ADVANCE(93);
      END_STATE();
    case 80:
      if (lookahead == 'r') ADVANCE(220);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(221);
      END_STATE();
    case 82:
      if (lookahead == 'r') ADVANCE(90);
      END_STATE();
    case 83:
      if (lookahead == 'r') ADVANCE(85);
      END_STATE();
    case 84:
      if (lookahead == 'r') ADVANCE(21);
      END_STATE();
    case 85:
      if (lookahead == 'r') ADVANCE(74);
      END_STATE();
    case 86:
      if (lookahead == 'r') ADVANCE(59);
      END_STATE();
    case 87:
      if (lookahead == 'r') ADVANCE(42);
      END_STATE();
    case 88:
      if (lookahead == 'r') ADVANCE(39);
      END_STATE();
    case 89:
      if (lookahead == 's') ADVANCE(124);
      END_STATE();
    case 90:
      if (lookahead == 's') ADVANCE(60);
      END_STATE();
    case 91:
      if (lookahead == 's') ADVANCE(40);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(125);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(54);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(128);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(225);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(126);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(226);
      END_STATE();
    case 98:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 99:
      if (lookahead == 't') ADVANCE(46);
      END_STATE();
    case 100:
      if (lookahead == 'u') ADVANCE(63);
      END_STATE();
    case 101:
      if (lookahead == 'u') ADVANCE(51);
      END_STATE();
    case 102:
      if (lookahead == 'u') ADVANCE(88);
      END_STATE();
    case 103:
      if (lookahead == 'y') ADVANCE(86);
      END_STATE();
    case 104:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(216);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(217);
      END_STATE();
    case 105:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(105);
      if (lookahead != 0) ADVANCE(143);
      END_STATE();
    case 106:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(106);
      if (lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(142);
      END_STATE();
    case 107:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(104);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(217);
      END_STATE();
    case 108:
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(135);
      END_STATE();
    case 109:
      if (eof) ADVANCE(111);
      ADVANCE_MAP(
        '%', 114,
        '(', 132,
        ')', 134,
        '*', 148,
        '+', 15,
        ',', 133,
        '-', 16,
        '/', 14,
        'i', 89,
        '!', 108,
        ':', 108,
        '?', 108,
        '@', 108,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(109);
      END_STATE();
    case 110:
      if (eof) ADVANCE(111);
      if (lookahead == '%') ADVANCE(114);
      if (lookahead == ')') ADVANCE(134);
      if (lookahead == ',') ADVANCE(133);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == ':') ADVANCE(136);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(110);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(146);
      if (lookahead == '!') ADVANCE(4);
      if (lookahead == '%') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(146);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!') ADVANCE(9);
      if (lookahead == '%') ADVANCE(9);
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
      if (lookahead == '@') ADVANCE(159);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(155);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(118);
      if (lookahead == '@') ADVANCE(19);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(119);
      if (lookahead == '!') ADVANCE(108);
      if (lookahead == '+') ADVANCE(138);
      if (lookahead == '-') ADVANCE(139);
      if (lookahead == ':') ADVANCE(140);
      if (lookahead == '?' ||
          lookahead == '@') ADVANCE(141);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(120);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(121);
      if (lookahead == '+') ADVANCE(15);
      if (lookahead == '-') ADVANCE(16);
      if (lookahead == '!' ||
          lookahead == ':' ||
          lookahead == '?' ||
          lookahead == '@') ADVANCE(108);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(122);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(157);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_is);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_det);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_semidet);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_failure);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_nondet);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_multi);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_undefined);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_COLON_DASH);
      if (lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(142);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(aux_sym_arg_spec_token1);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(135);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(142);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_functor);
      if (lookahead == '+') ADVANCE(141);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(135);
      if (lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(142);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_functor);
      if (lookahead == '-') ADVANCE(141);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(135);
      if (lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(142);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_functor);
      if (lookahead == '-') ADVANCE(131);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(135);
      if (lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(142);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_functor);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(135);
      if (lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(142);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_functor);
      if (lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(142);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_type_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(143);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_pldoc_prolog_directive_token1);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token1);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token2);
      if (lookahead == '\n') ADVANCE(146);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR_STAR);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == '/') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '/') ADVANCE(152);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      if (lookahead == '/') ADVANCE(158);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(117);
      if (lookahead == '*') ADVANCE(149);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '@') ADVANCE(159);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(155);
      if (lookahead != 0) ADVANCE(212);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(117);
      if (lookahead == '*') ADVANCE(149);
      if (lookahead == '@') ADVANCE(159);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(155);
      if (lookahead != 0) ADVANCE(212);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(122);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == '/') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(157);
      if (lookahead != 0) ADVANCE(212);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(122);
      if (lookahead == '*') ADVANCE(158);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(157);
      if (lookahead != 0) ADVANCE(212);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      ADVANCE_MAP(
        '*', 158,
        'a', 197,
        'b', 210,
        'c', 189,
        'd', 171,
        'e', 200,
        'l', 182,
        'p', 162,
        's', 175,
        't', 164,
        'v', 176,
      );
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'a') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'a') ADVANCE(206);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'a') ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'a') ADVANCE(209);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'b') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'c') ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'c') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'd') ADVANCE(229);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'd') ADVANCE(224);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'e') ADVANCE(223);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'e') ADVANCE(227);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'e') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'e') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'e') ADVANCE(165);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'e') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'e') ADVANCE(169);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'e') ADVANCE(198);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'g') ADVANCE(218);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'g') ADVANCE(228);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'g') ADVANCE(180);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'h') ADVANCE(207);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'h') ADVANCE(192);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'i') ADVANCE(166);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'i') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'i') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'm') ADVANCE(219);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'm') ADVANCE(193);
      if (lookahead == 'p') ADVANCE(211);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'n') ADVANCE(222);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'n') ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'o') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'o') ADVANCE(187);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'o') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'o') ADVANCE(196);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'p') ADVANCE(161);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'p') ADVANCE(203);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'r') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'r') ADVANCE(221);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'r') ADVANCE(177);
      if (lookahead == 'u') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'r') ADVANCE(204);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'r') ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'r') ADVANCE(199);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'r') ADVANCE(160);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'r') ADVANCE(184);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'r') ADVANCE(173);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 's') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 's') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 't') ADVANCE(225);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 't') ADVANCE(226);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 't') ADVANCE(181);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 't') ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'u') ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead == 'y') ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(158);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(212);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(150);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == '@') ADVANCE(159);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(214);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(212);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(150);
      if (lookahead == '@') ADVANCE(159);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(214);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(212);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_c_style_description_token2);
      if (lookahead == '\n') ADVANCE(215);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_pl_tag_text_token1);
      if (lookahead == '\n') ADVANCE(216);
      if (lookahead == '@') ADVANCE(217);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(216);
      if (lookahead != 0) ADVANCE(217);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(aux_sym_pl_tag_text_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(217);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(anon_sym_ATarg);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(anon_sym_ATparam);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(anon_sym_ATerror);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(anon_sym_ATauthor);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_ATversion);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_ATsee);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_ATdeprecated);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_ATcompat);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_ATcopyright);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_ATlicense);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(anon_sym_ATbug);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(anon_sym_ATtbd);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 109},
  [2] = {.lex_state = 154},
  [3] = {.lex_state = 213},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 154},
  [7] = {.lex_state = 213},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 154},
  [11] = {.lex_state = 213},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 6},
  [15] = {.lex_state = 6},
  [16] = {.lex_state = 109},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 109},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 7},
  [21] = {.lex_state = 11},
  [22] = {.lex_state = 11},
  [23] = {.lex_state = 109},
  [24] = {.lex_state = 11},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 110},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 109},
  [30] = {.lex_state = 12},
  [31] = {.lex_state = 109},
  [32] = {.lex_state = 109},
  [33] = {.lex_state = 109},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 109},
  [36] = {.lex_state = 12},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 109},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 109},
  [41] = {.lex_state = 109},
  [42] = {.lex_state = 109},
  [43] = {.lex_state = 109},
  [44] = {.lex_state = 8},
  [45] = {.lex_state = 109},
  [46] = {.lex_state = 109},
  [47] = {.lex_state = 109},
  [48] = {.lex_state = 156},
  [49] = {.lex_state = 109},
  [50] = {.lex_state = 156},
  [51] = {.lex_state = 109},
  [52] = {.lex_state = 109},
  [53] = {.lex_state = 109},
  [54] = {.lex_state = 109},
  [55] = {.lex_state = 109},
  [56] = {.lex_state = 109},
  [57] = {.lex_state = 109},
  [58] = {.lex_state = 109},
  [59] = {.lex_state = 1},
  [60] = {.lex_state = 109},
  [61] = {.lex_state = 109},
  [62] = {.lex_state = 109},
  [63] = {.lex_state = 109},
  [64] = {.lex_state = 11},
  [65] = {.lex_state = 109},
  [66] = {.lex_state = 109},
  [67] = {.lex_state = 109},
  [68] = {.lex_state = 109},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 11},
  [71] = {.lex_state = 156},
  [72] = {.lex_state = 156},
  [73] = {.lex_state = 7},
  [74] = {.lex_state = 109},
  [75] = {.lex_state = 109},
  [76] = {.lex_state = 109},
  [77] = {.lex_state = 107},
  [78] = {.lex_state = 107},
  [79] = {.lex_state = 109},
  [80] = {.lex_state = 1},
  [81] = {.lex_state = 105},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 1},
  [84] = {.lex_state = 105},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 1},
  [87] = {.lex_state = 156},
  [88] = {.lex_state = 18},
  [89] = {.lex_state = 1},
  [90] = {.lex_state = 1},
  [91] = {.lex_state = 156},
  [92] = {.lex_state = 105},
  [93] = {.lex_state = 105},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 105},
  [97] = {.lex_state = 106},
  [98] = {.lex_state = 106},
  [99] = {.lex_state = 106},
  [100] = {.lex_state = 1},
  [101] = {.lex_state = 1},
  [102] = {.lex_state = 1},
  [103] = {.lex_state = 1},
  [104] = {.lex_state = 109},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 107},
  [107] = {.lex_state = 1},
  [108] = {.lex_state = 1},
  [109] = {.lex_state = 215},
  [110] = {.lex_state = 1},
  [111] = {.lex_state = 1},
  [112] = {.lex_state = 115},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 1},
  [115] = {.lex_state = 106},
  [116] = {.lex_state = 1},
  [117] = {.lex_state = 215},
  [118] = {.lex_state = 1},
  [119] = {.lex_state = 1},
  [120] = {.lex_state = 1},
  [121] = {.lex_state = 0},
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
    [anon_sym_COLON] = ACTIONS(1),
    [aux_sym_pldoc_prolog_directive_token1] = ACTIONS(1),
    [aux_sym_prolog_style_description_token1] = ACTIONS(1),
    [aux_sym_prolog_style_description_token2] = ACTIONS(1),
    [anon_sym_SLASH_STAR_STAR] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_STAR_SLASH] = ACTIONS(1),
    [anon_sym_ATarg] = ACTIONS(1),
    [anon_sym_ATparam] = ACTIONS(1),
    [anon_sym_ATerror] = ACTIONS(1),
    [anon_sym_ATauthor] = ACTIONS(1),
    [anon_sym_ATversion] = ACTIONS(1),
    [anon_sym_ATsee] = ACTIONS(1),
    [anon_sym_ATdeprecated] = ACTIONS(1),
    [anon_sym_ATcompat] = ACTIONS(1),
    [anon_sym_ATcopyright] = ACTIONS(1),
    [anon_sym_ATlicense] = ACTIONS(1),
    [anon_sym_ATbug] = ACTIONS(1),
    [anon_sym_ATtbd] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(121),
    [sym_comment] = STATE(16),
    [sym_normal_comment] = STATE(49),
    [sym_normal_single_line_comment] = STATE(47),
    [sym_pldoc_comment] = STATE(49),
    [sym_pldoc_prolog_directive] = STATE(29),
    [sym_pldoc_prolog_style] = STATE(57),
    [sym_pldoc_c_style] = STATE(57),
    [aux_sym_source_file_repeat1] = STATE(16),
    [aux_sym_pldoc_prolog_style_repeat1] = STATE(29),
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
    STATE(4), 1,
      aux_sym_c_style_body_repeat1,
    STATE(5), 1,
      sym_c_style_description,
    STATE(6), 1,
      aux_sym_pldoc_c_style_repeat2,
    STATE(7), 1,
      aux_sym_c_style_description_repeat1,
    STATE(113), 1,
      sym_c_style_body,
    STATE(116), 1,
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
  [44] = 3,
    ACTIONS(23), 1,
      aux_sym_c_style_description_token1,
    STATE(3), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(21), 14,
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
  [67] = 6,
    ACTIONS(26), 1,
      anon_sym_STAR,
    ACTIONS(28), 1,
      anon_sym_STAR_SLASH,
    STATE(9), 1,
      aux_sym_c_style_body_repeat1,
    STATE(116), 1,
      sym_c_tag,
    ACTIONS(30), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(32), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [96] = 6,
    ACTIONS(26), 1,
      anon_sym_STAR,
    ACTIONS(28), 1,
      anon_sym_STAR_SLASH,
    STATE(8), 1,
      aux_sym_c_style_body_repeat1,
    STATE(116), 1,
      sym_c_tag,
    ACTIONS(30), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(32), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [125] = 4,
    ACTIONS(34), 1,
      anon_sym_LF,
    ACTIONS(37), 1,
      anon_sym_STAR,
    STATE(6), 1,
      aux_sym_pldoc_c_style_repeat2,
    ACTIONS(40), 13,
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
  [150] = 3,
    ACTIONS(15), 1,
      aux_sym_c_style_description_token1,
    STATE(3), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(42), 14,
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
  [173] = 6,
    ACTIONS(26), 1,
      anon_sym_STAR,
    ACTIONS(44), 1,
      anon_sym_STAR_SLASH,
    STATE(9), 1,
      aux_sym_c_style_body_repeat1,
    STATE(116), 1,
      sym_c_tag,
    ACTIONS(30), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(32), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [202] = 6,
    ACTIONS(46), 1,
      anon_sym_STAR,
    ACTIONS(49), 1,
      anon_sym_STAR_SLASH,
    STATE(9), 1,
      aux_sym_c_style_body_repeat1,
    STATE(116), 1,
      sym_c_tag,
    ACTIONS(51), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(54), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [231] = 1,
    ACTIONS(40), 15,
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
  [249] = 1,
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
  [267] = 2,
    ACTIONS(57), 1,
      anon_sym_STAR,
    ACTIONS(49), 13,
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
  [286] = 2,
    ACTIONS(59), 1,
      anon_sym_STAR,
    ACTIONS(61), 13,
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
  [305] = 4,
    ACTIONS(63), 1,
      anon_sym_LF,
    STATE(54), 1,
      sym_pl_tag,
    ACTIONS(65), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(67), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [328] = 4,
    ACTIONS(69), 1,
      anon_sym_LF,
    STATE(103), 1,
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
  [351] = 9,
    ACTIONS(5), 1,
      anon_sym_PERCENT,
    ACTIONS(7), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(9), 1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(71), 1,
      ts_builtin_sym_end,
    STATE(47), 1,
      sym_normal_single_line_comment,
    STATE(18), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(29), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(49), 2,
      sym_normal_comment,
      sym_pldoc_comment,
    STATE(57), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
  [383] = 3,
    STATE(103), 1,
      sym_c_tag,
    ACTIONS(30), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(32), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [403] = 9,
    ACTIONS(73), 1,
      ts_builtin_sym_end,
    ACTIONS(75), 1,
      anon_sym_PERCENT,
    ACTIONS(78), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(81), 1,
      anon_sym_SLASH_STAR_STAR,
    STATE(47), 1,
      sym_normal_single_line_comment,
    STATE(18), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(29), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(49), 2,
      sym_normal_comment,
      sym_pldoc_comment,
    STATE(57), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
  [435] = 3,
    STATE(54), 1,
      sym_pl_tag,
    ACTIONS(84), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(86), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [455] = 7,
    ACTIONS(69), 1,
      anon_sym_LF,
    ACTIONS(88), 1,
      anon_sym_COLON_DASH,
    ACTIONS(90), 1,
      aux_sym_arg_spec_token1,
    ACTIONS(92), 1,
      sym_functor,
    STATE(83), 1,
      sym__head,
    STATE(97), 1,
      sym_arg_spec,
    STATE(100), 4,
      sym__template,
      sym_operator_template,
      sym_functor_template,
      sym_directive_template,
  [480] = 6,
    ACTIONS(88), 1,
      anon_sym_COLON_DASH,
    ACTIONS(92), 1,
      sym_functor,
    ACTIONS(94), 1,
      aux_sym_arg_spec_token1,
    STATE(83), 1,
      sym__head,
    STATE(97), 1,
      sym_arg_spec,
    STATE(100), 4,
      sym__template,
      sym_operator_template,
      sym_functor_template,
      sym_directive_template,
  [502] = 6,
    ACTIONS(94), 1,
      aux_sym_arg_spec_token1,
    ACTIONS(96), 1,
      anon_sym_COLON_DASH,
    ACTIONS(98), 1,
      sym_functor,
    STATE(46), 1,
      sym__head,
    STATE(98), 1,
      sym_arg_spec,
    STATE(56), 4,
      sym__template,
      sym_operator_template,
      sym_functor_template,
      sym_directive_template,
  [524] = 5,
    ACTIONS(102), 1,
      anon_sym_PERCENT,
    ACTIONS(104), 1,
      anon_sym_LPAREN,
    ACTIONS(106), 1,
      aux_sym_arg_spec_token1,
    STATE(55), 1,
      sym_arg_spec,
    ACTIONS(100), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [543] = 7,
    ACTIONS(108), 1,
      anon_sym_PERCENT,
    STATE(28), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(40), 1,
      sym_prolog_style_description,
    STATE(43), 1,
      aux_sym_prolog_style_body_repeat1,
    STATE(61), 1,
      sym_prolog_style_body,
    STATE(64), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(110), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [566] = 6,
    ACTIONS(110), 1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(114), 1,
      anon_sym_PERCENT,
    ACTIONS(116), 1,
      aux_sym_prolog_style_description_token1,
    STATE(28), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(66), 1,
      sym_prolog_style_description,
    ACTIONS(112), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [587] = 3,
    ACTIONS(120), 1,
      anon_sym_PERCENT,
    ACTIONS(122), 1,
      anon_sym_COLON,
    ACTIONS(118), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [601] = 5,
    ACTIONS(126), 1,
      anon_sym_PERCENT,
    ACTIONS(128), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(131), 1,
      aux_sym_prolog_style_description_token2,
    STATE(27), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(124), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [619] = 5,
    ACTIONS(136), 1,
      anon_sym_PERCENT,
    ACTIONS(138), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(140), 1,
      aux_sym_prolog_style_description_token2,
    STATE(27), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(134), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [637] = 5,
    ACTIONS(144), 1,
      anon_sym_PERCENT,
    ACTIONS(147), 1,
      aux_sym_pldoc_prolog_directive_token1,
    STATE(24), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(142), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(31), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [655] = 5,
    ACTIONS(94), 1,
      aux_sym_arg_spec_token1,
    ACTIONS(98), 1,
      sym_functor,
    STATE(46), 1,
      sym__head,
    STATE(98), 1,
      sym_arg_spec,
    STATE(52), 2,
      sym_operator_template,
      sym_functor_template,
  [672] = 4,
    ACTIONS(152), 1,
      anon_sym_PERCENT,
    ACTIONS(154), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(150), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(31), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [687] = 4,
    ACTIONS(106), 1,
      aux_sym_arg_spec_token1,
    ACTIONS(159), 1,
      anon_sym_PERCENT,
    STATE(62), 1,
      sym_arg_spec,
    ACTIONS(157), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [702] = 2,
    ACTIONS(163), 1,
      anon_sym_PERCENT,
    ACTIONS(161), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [713] = 1,
    ACTIONS(165), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [722] = 2,
    ACTIONS(169), 1,
      anon_sym_PERCENT,
    ACTIONS(167), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [733] = 5,
    ACTIONS(92), 1,
      sym_functor,
    ACTIONS(94), 1,
      aux_sym_arg_spec_token1,
    STATE(83), 1,
      sym__head,
    STATE(97), 1,
      sym_arg_spec,
    STATE(118), 2,
      sym_operator_template,
      sym_functor_template,
  [750] = 1,
    ACTIONS(171), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [759] = 3,
    ACTIONS(175), 1,
      anon_sym_PERCENT,
    STATE(38), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(173), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [771] = 5,
    ACTIONS(178), 1,
      anon_sym_LF,
    ACTIONS(180), 1,
      anon_sym_STAR,
    ACTIONS(182), 1,
      anon_sym_STAR_SLASH,
    STATE(2), 1,
      aux_sym_pldoc_c_style_repeat2,
    STATE(59), 1,
      aux_sym_pldoc_c_style_repeat1,
  [787] = 3,
    ACTIONS(186), 1,
      anon_sym_PERCENT,
    STATE(41), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(184), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [799] = 3,
    ACTIONS(191), 1,
      anon_sym_PERCENT,
    STATE(38), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(189), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [811] = 2,
    ACTIONS(196), 1,
      anon_sym_PERCENT,
    ACTIONS(194), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [821] = 3,
    ACTIONS(186), 1,
      anon_sym_PERCENT,
    STATE(38), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(184), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [833] = 4,
    ACTIONS(198), 1,
      anon_sym_LPAREN,
    ACTIONS(200), 1,
      aux_sym_arg_spec_token1,
    STATE(119), 1,
      sym_arg_spec,
    ACTIONS(102), 2,
      anon_sym_LF,
      anon_sym_is,
  [847] = 2,
    ACTIONS(204), 1,
      anon_sym_PERCENT,
    ACTIONS(202), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [857] = 3,
    ACTIONS(208), 1,
      anon_sym_PERCENT,
    ACTIONS(210), 1,
      anon_sym_is,
    ACTIONS(206), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [869] = 2,
    ACTIONS(214), 1,
      anon_sym_PERCENT,
    ACTIONS(212), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [878] = 4,
    ACTIONS(216), 1,
      anon_sym_LF,
    ACTIONS(218), 1,
      aux_sym_c_style_description_token1,
    STATE(71), 1,
      aux_sym_c_style_description_repeat1,
    STATE(108), 1,
      sym_c_style_description,
  [891] = 2,
    ACTIONS(222), 1,
      anon_sym_PERCENT,
    ACTIONS(220), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [900] = 4,
    ACTIONS(218), 1,
      aux_sym_c_style_description_token1,
    ACTIONS(224), 1,
      anon_sym_LF,
    STATE(71), 1,
      aux_sym_c_style_description_repeat1,
    STATE(120), 1,
      sym_c_style_description,
  [913] = 2,
    ACTIONS(228), 1,
      anon_sym_PERCENT,
    ACTIONS(226), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [922] = 2,
    ACTIONS(232), 1,
      anon_sym_PERCENT,
    ACTIONS(230), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [931] = 2,
    ACTIONS(236), 1,
      anon_sym_PERCENT,
    ACTIONS(234), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [940] = 2,
    ACTIONS(238), 1,
      anon_sym_PERCENT,
    ACTIONS(173), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [949] = 2,
    ACTIONS(159), 1,
      anon_sym_PERCENT,
    ACTIONS(157), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [958] = 2,
    ACTIONS(242), 1,
      anon_sym_PERCENT,
    ACTIONS(240), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [967] = 2,
    ACTIONS(246), 1,
      anon_sym_PERCENT,
    ACTIONS(244), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [976] = 2,
    ACTIONS(250), 1,
      anon_sym_PERCENT,
    ACTIONS(248), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [985] = 4,
    ACTIONS(252), 1,
      anon_sym_LF,
    ACTIONS(254), 1,
      anon_sym_STAR,
    ACTIONS(257), 1,
      anon_sym_STAR_SLASH,
    STATE(59), 1,
      aux_sym_pldoc_c_style_repeat1,
  [998] = 2,
    ACTIONS(261), 1,
      anon_sym_PERCENT,
    ACTIONS(259), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1007] = 2,
    ACTIONS(265), 1,
      anon_sym_PERCENT,
    ACTIONS(263), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1016] = 2,
    ACTIONS(269), 1,
      anon_sym_PERCENT,
    ACTIONS(267), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1025] = 2,
    ACTIONS(273), 1,
      anon_sym_PERCENT,
    ACTIONS(271), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1034] = 3,
    ACTIONS(275), 1,
      anon_sym_PERCENT,
    STATE(64), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(278), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [1045] = 2,
    ACTIONS(282), 1,
      anon_sym_PERCENT,
    ACTIONS(280), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1054] = 2,
    ACTIONS(286), 1,
      anon_sym_PERCENT,
    ACTIONS(284), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1063] = 3,
    ACTIONS(288), 1,
      aux_sym_arg_spec_token1,
    STATE(67), 1,
      aux_sym__head_repeat1,
    STATE(105), 1,
      sym_arg_spec,
  [1073] = 3,
    ACTIONS(106), 1,
      aux_sym_arg_spec_token1,
    STATE(74), 1,
      aux_sym__head_repeat1,
    STATE(85), 1,
      sym_arg_spec,
  [1083] = 2,
    ACTIONS(291), 1,
      anon_sym_LF,
    ACTIONS(293), 2,
      anon_sym_STAR,
      anon_sym_STAR_SLASH,
  [1091] = 2,
    ACTIONS(295), 1,
      anon_sym_PERCENT,
    ACTIONS(278), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [1099] = 3,
    ACTIONS(42), 1,
      anon_sym_LF,
    ACTIONS(218), 1,
      aux_sym_c_style_description_token1,
    STATE(72), 1,
      aux_sym_c_style_description_repeat1,
  [1109] = 3,
    ACTIONS(21), 1,
      anon_sym_LF,
    ACTIONS(297), 1,
      aux_sym_c_style_description_token1,
    STATE(72), 1,
      aux_sym_c_style_description_repeat1,
  [1119] = 3,
    ACTIONS(159), 1,
      anon_sym_LF,
    ACTIONS(200), 1,
      aux_sym_arg_spec_token1,
    STATE(102), 1,
      sym_arg_spec,
  [1129] = 3,
    ACTIONS(106), 1,
      aux_sym_arg_spec_token1,
    STATE(67), 1,
      aux_sym__head_repeat1,
    STATE(82), 1,
      sym_arg_spec,
  [1139] = 3,
    ACTIONS(106), 1,
      aux_sym_arg_spec_token1,
    STATE(76), 1,
      aux_sym__head_repeat1,
    STATE(94), 1,
      sym_arg_spec,
  [1149] = 3,
    ACTIONS(106), 1,
      aux_sym_arg_spec_token1,
    STATE(67), 1,
      aux_sym__head_repeat1,
    STATE(95), 1,
      sym_arg_spec,
  [1159] = 2,
    ACTIONS(300), 1,
      aux_sym_pl_tag_text_token1,
    STATE(60), 1,
      sym_pl_tag_text,
  [1166] = 2,
    ACTIONS(300), 1,
      aux_sym_pl_tag_text_token1,
    STATE(63), 1,
      sym_pl_tag_text,
  [1173] = 2,
    ACTIONS(302), 1,
      anon_sym_STAR,
    STATE(39), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1180] = 2,
    ACTIONS(304), 1,
      anon_sym_LF,
    ACTIONS(306), 1,
      anon_sym_NULL,
  [1187] = 2,
    ACTIONS(308), 1,
      aux_sym_type_token1,
    STATE(48), 1,
      sym_tag_name,
  [1194] = 2,
    ACTIONS(310), 1,
      anon_sym_COMMA,
    ACTIONS(312), 1,
      anon_sym_RPAREN,
  [1201] = 2,
    ACTIONS(206), 1,
      anon_sym_LF,
    ACTIONS(314), 1,
      anon_sym_is,
  [1208] = 2,
    ACTIONS(316), 1,
      aux_sym_type_token1,
    STATE(99), 1,
      sym_type,
  [1215] = 2,
    ACTIONS(310), 1,
      anon_sym_COMMA,
    ACTIONS(318), 1,
      anon_sym_RPAREN,
  [1222] = 2,
    ACTIONS(194), 1,
      anon_sym_LF,
    ACTIONS(196), 1,
      anon_sym_is,
  [1229] = 1,
    ACTIONS(21), 2,
      anon_sym_LF,
      aux_sym_c_style_description_token1,
  [1234] = 2,
    ACTIONS(120), 1,
      sym_functor,
    ACTIONS(320), 1,
      anon_sym_COLON,
  [1241] = 2,
    ACTIONS(202), 1,
      anon_sym_LF,
    ACTIONS(204), 1,
      anon_sym_is,
  [1248] = 2,
    ACTIONS(118), 1,
      anon_sym_LF,
    ACTIONS(322), 1,
      anon_sym_COLON,
  [1255] = 1,
    ACTIONS(324), 2,
      anon_sym_LF,
      aux_sym_c_style_description_token1,
  [1260] = 2,
    ACTIONS(326), 1,
      aux_sym_type_token1,
    STATE(33), 1,
      sym_type,
  [1267] = 2,
    ACTIONS(328), 1,
      aux_sym_type_token1,
    STATE(77), 1,
      sym_tag_name,
  [1274] = 2,
    ACTIONS(310), 1,
      anon_sym_COMMA,
    ACTIONS(330), 1,
      anon_sym_RPAREN,
  [1281] = 2,
    ACTIONS(310), 1,
      anon_sym_COMMA,
    ACTIONS(332), 1,
      anon_sym_RPAREN,
  [1288] = 2,
    ACTIONS(334), 1,
      aux_sym_type_token1,
    STATE(111), 1,
      sym_type,
  [1295] = 1,
    ACTIONS(336), 1,
      sym_functor,
  [1299] = 1,
    ACTIONS(338), 1,
      sym_functor,
  [1303] = 1,
    ACTIONS(161), 1,
      sym_functor,
  [1307] = 1,
    ACTIONS(340), 1,
      anon_sym_LF,
  [1311] = 1,
    ACTIONS(280), 1,
      anon_sym_LF,
  [1315] = 1,
    ACTIONS(267), 1,
      anon_sym_LF,
  [1319] = 1,
    ACTIONS(342), 1,
      anon_sym_LF,
  [1323] = 1,
    ACTIONS(344), 1,
      aux_sym_arg_spec_token1,
  [1327] = 1,
    ACTIONS(310), 1,
      anon_sym_COMMA,
  [1331] = 1,
    ACTIONS(346), 1,
      aux_sym_pl_tag_text_token1,
  [1335] = 1,
    ACTIONS(348), 1,
      anon_sym_LF,
  [1339] = 1,
    ACTIONS(350), 1,
      anon_sym_LF,
  [1343] = 1,
    ACTIONS(352), 1,
      aux_sym_c_style_description_token2,
  [1347] = 1,
    ACTIONS(167), 1,
      anon_sym_LF,
  [1351] = 1,
    ACTIONS(161), 1,
      anon_sym_LF,
  [1355] = 1,
    ACTIONS(354), 1,
      aux_sym_normal_single_line_comment_token1,
  [1359] = 1,
    ACTIONS(356), 1,
      anon_sym_STAR_SLASH,
  [1363] = 1,
    ACTIONS(358), 1,
      anon_sym_LF,
  [1367] = 1,
    ACTIONS(167), 1,
      sym_functor,
  [1371] = 1,
    ACTIONS(360), 1,
      anon_sym_LF,
  [1375] = 1,
    ACTIONS(362), 1,
      aux_sym_c_style_description_token2,
  [1379] = 1,
    ACTIONS(230), 1,
      anon_sym_LF,
  [1383] = 1,
    ACTIONS(157), 1,
      anon_sym_LF,
  [1387] = 1,
    ACTIONS(364), 1,
      anon_sym_LF,
  [1391] = 1,
    ACTIONS(366), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 44,
  [SMALL_STATE(4)] = 67,
  [SMALL_STATE(5)] = 96,
  [SMALL_STATE(6)] = 125,
  [SMALL_STATE(7)] = 150,
  [SMALL_STATE(8)] = 173,
  [SMALL_STATE(9)] = 202,
  [SMALL_STATE(10)] = 231,
  [SMALL_STATE(11)] = 249,
  [SMALL_STATE(12)] = 267,
  [SMALL_STATE(13)] = 286,
  [SMALL_STATE(14)] = 305,
  [SMALL_STATE(15)] = 328,
  [SMALL_STATE(16)] = 351,
  [SMALL_STATE(17)] = 383,
  [SMALL_STATE(18)] = 403,
  [SMALL_STATE(19)] = 435,
  [SMALL_STATE(20)] = 455,
  [SMALL_STATE(21)] = 480,
  [SMALL_STATE(22)] = 502,
  [SMALL_STATE(23)] = 524,
  [SMALL_STATE(24)] = 543,
  [SMALL_STATE(25)] = 566,
  [SMALL_STATE(26)] = 587,
  [SMALL_STATE(27)] = 601,
  [SMALL_STATE(28)] = 619,
  [SMALL_STATE(29)] = 637,
  [SMALL_STATE(30)] = 655,
  [SMALL_STATE(31)] = 672,
  [SMALL_STATE(32)] = 687,
  [SMALL_STATE(33)] = 702,
  [SMALL_STATE(34)] = 713,
  [SMALL_STATE(35)] = 722,
  [SMALL_STATE(36)] = 733,
  [SMALL_STATE(37)] = 750,
  [SMALL_STATE(38)] = 759,
  [SMALL_STATE(39)] = 771,
  [SMALL_STATE(40)] = 787,
  [SMALL_STATE(41)] = 799,
  [SMALL_STATE(42)] = 811,
  [SMALL_STATE(43)] = 821,
  [SMALL_STATE(44)] = 833,
  [SMALL_STATE(45)] = 847,
  [SMALL_STATE(46)] = 857,
  [SMALL_STATE(47)] = 869,
  [SMALL_STATE(48)] = 878,
  [SMALL_STATE(49)] = 891,
  [SMALL_STATE(50)] = 900,
  [SMALL_STATE(51)] = 913,
  [SMALL_STATE(52)] = 922,
  [SMALL_STATE(53)] = 931,
  [SMALL_STATE(54)] = 940,
  [SMALL_STATE(55)] = 949,
  [SMALL_STATE(56)] = 958,
  [SMALL_STATE(57)] = 967,
  [SMALL_STATE(58)] = 976,
  [SMALL_STATE(59)] = 985,
  [SMALL_STATE(60)] = 998,
  [SMALL_STATE(61)] = 1007,
  [SMALL_STATE(62)] = 1016,
  [SMALL_STATE(63)] = 1025,
  [SMALL_STATE(64)] = 1034,
  [SMALL_STATE(65)] = 1045,
  [SMALL_STATE(66)] = 1054,
  [SMALL_STATE(67)] = 1063,
  [SMALL_STATE(68)] = 1073,
  [SMALL_STATE(69)] = 1083,
  [SMALL_STATE(70)] = 1091,
  [SMALL_STATE(71)] = 1099,
  [SMALL_STATE(72)] = 1109,
  [SMALL_STATE(73)] = 1119,
  [SMALL_STATE(74)] = 1129,
  [SMALL_STATE(75)] = 1139,
  [SMALL_STATE(76)] = 1149,
  [SMALL_STATE(77)] = 1159,
  [SMALL_STATE(78)] = 1166,
  [SMALL_STATE(79)] = 1173,
  [SMALL_STATE(80)] = 1180,
  [SMALL_STATE(81)] = 1187,
  [SMALL_STATE(82)] = 1194,
  [SMALL_STATE(83)] = 1201,
  [SMALL_STATE(84)] = 1208,
  [SMALL_STATE(85)] = 1215,
  [SMALL_STATE(86)] = 1222,
  [SMALL_STATE(87)] = 1229,
  [SMALL_STATE(88)] = 1234,
  [SMALL_STATE(89)] = 1241,
  [SMALL_STATE(90)] = 1248,
  [SMALL_STATE(91)] = 1255,
  [SMALL_STATE(92)] = 1260,
  [SMALL_STATE(93)] = 1267,
  [SMALL_STATE(94)] = 1274,
  [SMALL_STATE(95)] = 1281,
  [SMALL_STATE(96)] = 1288,
  [SMALL_STATE(97)] = 1295,
  [SMALL_STATE(98)] = 1299,
  [SMALL_STATE(99)] = 1303,
  [SMALL_STATE(100)] = 1307,
  [SMALL_STATE(101)] = 1311,
  [SMALL_STATE(102)] = 1315,
  [SMALL_STATE(103)] = 1319,
  [SMALL_STATE(104)] = 1323,
  [SMALL_STATE(105)] = 1327,
  [SMALL_STATE(106)] = 1331,
  [SMALL_STATE(107)] = 1335,
  [SMALL_STATE(108)] = 1339,
  [SMALL_STATE(109)] = 1343,
  [SMALL_STATE(110)] = 1347,
  [SMALL_STATE(111)] = 1351,
  [SMALL_STATE(112)] = 1355,
  [SMALL_STATE(113)] = 1359,
  [SMALL_STATE(114)] = 1363,
  [SMALL_STATE(115)] = 1367,
  [SMALL_STATE(116)] = 1371,
  [SMALL_STATE(117)] = 1375,
  [SMALL_STATE(118)] = 1379,
  [SMALL_STATE(119)] = 1383,
  [SMALL_STATE(120)] = 1387,
  [SMALL_STATE(121)] = 1391,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(112),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(109),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(109),
  [26] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 1, 0, 0),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0), SHIFT_REPEAT(6),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0), SHIFT_REPEAT(107),
  [40] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_style_description, 1, 0, 0),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 2, 0, 0),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(17),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(81),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(112),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [88] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [90] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [92] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [96] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [98] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 1, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 1, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [108] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [110] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag_text, 1, 0, 0),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag_text, 1, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 1, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 1, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [128] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(27),
  [131] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(27),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0),
  [144] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(114),
  [147] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(22),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [154] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0), SHIFT_REPEAT(22),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 2, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 2, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 3, 0, 1),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 3, 0, 1),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [175] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [178] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [180] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [182] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 1, 0, 0),
  [186] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 1, 0, 0), SHIFT(19),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 2, 0, 0),
  [191] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 2, 0, 0), SHIFT(19),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 4, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 4, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [200] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 5, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 5, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 1, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 1, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 2, 0, 3),
  [218] = {.entry = {.count = 1, .reusable = false}}, SHIFT(117),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 1, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 1, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [228] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive_template, 2, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive_template, 2, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [242] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [246] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [254] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0), SHIFT_REPEAT(21),
  [257] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [259] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 3, 0, 5),
  [261] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 3, 0, 5),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [265] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 3, 0, 0),
  [269] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 3, 0, 0),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 2, 0, 4),
  [273] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 2, 0, 4),
  [275] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0), SHIFT_REPEAT(114),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 3, 0, 0),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 3, 0, 0),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag_text, 2, 0, 0),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag_text, 2, 0, 0),
  [288] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0), SHIFT_REPEAT(26),
  [291] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [293] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [295] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [297] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(117),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [306] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [312] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [314] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [318] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [320] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [322] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [324] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag_name, 1, 0, 2),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [344] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag_name, 1, 0, 2),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [350] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 3, 0, 5),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [360] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [364] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 2, 0, 4),
  [366] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
