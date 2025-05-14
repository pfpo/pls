#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 141
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 79
#define ALIAS_COUNT 0
#define TOKEN_COUNT 46
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

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
  anon_sym_ATarg = 33,
  aux_sym_pl_tag_token1 = 34,
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
  sym_pl_tag = 67,
  sym_c_tag = 68,
  aux_sym_source_file_repeat1 = 69,
  aux_sym_head_repeat1 = 70,
  aux_sym_pldoc_prolog_style_repeat1 = 71,
  aux_sym_pldoc_prolog_style_repeat2 = 72,
  aux_sym_prolog_style_body_repeat1 = 73,
  aux_sym_prolog_style_description_repeat1 = 74,
  aux_sym_pldoc_c_style_repeat1 = 75,
  aux_sym_pldoc_c_style_repeat2 = 76,
  aux_sym_c_style_body_repeat1 = 77,
  aux_sym_c_style_description_repeat1 = 78,
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
  [anon_sym_ATarg] = "@arg",
  [aux_sym_pl_tag_token1] = "pl_tag_token1",
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
  [anon_sym_ATarg] = anon_sym_ATarg,
  [aux_sym_pl_tag_token1] = aux_sym_pl_tag_token1,
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
  [anon_sym_ATarg] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_pl_tag_token1] = {
    .visible = false,
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
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
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
  [18] = 16,
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
  [30] = 28,
  [31] = 31,
  [32] = 15,
  [33] = 29,
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
  [48] = 45,
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
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 44,
  [81] = 81,
  [82] = 8,
  [83] = 13,
  [84] = 40,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 85,
  [89] = 89,
  [90] = 90,
  [91] = 54,
  [92] = 92,
  [93] = 42,
  [94] = 94,
  [95] = 55,
  [96] = 17,
  [97] = 41,
  [98] = 51,
  [99] = 41,
  [100] = 40,
  [101] = 42,
  [102] = 94,
  [103] = 87,
  [104] = 85,
  [105] = 92,
  [106] = 90,
  [107] = 94,
  [108] = 87,
  [109] = 77,
  [110] = 110,
  [111] = 49,
  [112] = 76,
  [113] = 113,
  [114] = 47,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 49,
  [126] = 47,
  [127] = 46,
  [128] = 65,
  [129] = 122,
  [130] = 130,
  [131] = 46,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 62,
  [137] = 63,
  [138] = 138,
  [139] = 134,
  [140] = 140,
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
        '/', 18,
        ':', 153,
        '?', 150,
        '@', 156,
        'd', 36,
        'f', 21,
        'i', 91,
        'm', 102,
        'n', 78,
        's', 37,
        'u', 69,
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
      if (lookahead == 'i') ADVANCE(91);
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
      if (lookahead == '@') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(9);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(234);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(10);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(233);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == ' ') ADVANCE(160);
      END_STATE();
    case 13:
      if (lookahead == ' ') ADVANCE(163);
      END_STATE();
    case 14:
      if (lookahead == '!') ADVANCE(159);
      if (lookahead == '+') ADVANCE(145);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == ':') ADVANCE(154);
      if (lookahead == '?') ADVANCE(151);
      if (lookahead == '@') ADVANCE(157);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      if (lookahead != 0) ADVANCE(127);
      END_STATE();
    case 15:
      if (lookahead == '!') ADVANCE(159);
      if (lookahead == '+') ADVANCE(145);
      if (lookahead == '-') ADVANCE(147);
      if (lookahead == ':') ADVANCE(155);
      if (lookahead == '?') ADVANCE(151);
      if (lookahead == '@') ADVANCE(157);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(15);
      if (lookahead != 0) ADVANCE(127);
      END_STATE();
    case 16:
      if (lookahead == '%') ADVANCE(112);
      if (lookahead == '*') ADVANCE(164);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(16);
      END_STATE();
    case 17:
      if (lookahead == '*') ADVANCE(13);
      END_STATE();
    case 18:
      if (lookahead == '*') ADVANCE(17);
      END_STATE();
    case 19:
      if (lookahead == '/') ADVANCE(174);
      END_STATE();
    case 20:
      if (lookahead == ':') ADVANCE(155);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(20);
      if (lookahead != 0) ADVANCE(127);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(60);
      END_STATE();
    case 22:
      ADVANCE_MAP(
        'a', 81,
        'b', 104,
        'c', 74,
        'd', 40,
        'e', 87,
        'l', 58,
        'p', 24,
        's', 50,
        't', 27,
        'v', 49,
      );
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(66);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(85);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(98);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(101);
      END_STATE();
    case 27:
      if (lookahead == 'b') ADVANCE(31);
      END_STATE();
    case 28:
      if (lookahead == 'c') ADVANCE(44);
      END_STATE();
    case 29:
      if (lookahead == 'c') ADVANCE(26);
      END_STATE();
    case 30:
      if (lookahead == 'd') ADVANCE(135);
      END_STATE();
    case 31:
      if (lookahead == 'd') ADVANCE(245);
      END_STATE();
    case 32:
      if (lookahead == 'd') ADVANCE(240);
      END_STATE();
    case 33:
      if (lookahead == 'd') ADVANCE(38);
      END_STATE();
    case 34:
      if (lookahead == 'd') ADVANCE(45);
      END_STATE();
    case 35:
      if (lookahead == 'd') ADVANCE(47);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(94);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(51);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(132);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(80);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(239);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(243);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(29);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(72);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(95);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(30);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(96);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(32);
      END_STATE();
    case 49:
      if (lookahead == 'e') ADVANCE(84);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(41);
      END_STATE();
    case 51:
      if (lookahead == 'f') ADVANCE(59);
      END_STATE();
    case 52:
      if (lookahead == 'g') ADVANCE(232);
      END_STATE();
    case 53:
      if (lookahead == 'g') ADVANCE(244);
      END_STATE();
    case 54:
      if (lookahead == 'g') ADVANCE(55);
      END_STATE();
    case 55:
      if (lookahead == 'h') ADVANCE(99);
      END_STATE();
    case 56:
      if (lookahead == 'h') ADVANCE(77);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(134);
      END_STATE();
    case 58:
      if (lookahead == 'i') ADVANCE(28);
      END_STATE();
    case 59:
      if (lookahead == 'i') ADVANCE(73);
      END_STATE();
    case 60:
      if (lookahead == 'i') ADVANCE(64);
      END_STATE();
    case 61:
      if (lookahead == 'i') ADVANCE(54);
      END_STATE();
    case 62:
      if (lookahead == 'i') ADVANCE(75);
      END_STATE();
    case 63:
      if (lookahead == 'i') ADVANCE(35);
      END_STATE();
    case 64:
      if (lookahead == 'l') ADVANCE(103);
      END_STATE();
    case 65:
      if (lookahead == 'l') ADVANCE(100);
      END_STATE();
    case 66:
      if (lookahead == 'm') ADVANCE(235);
      END_STATE();
    case 67:
      if (lookahead == 'm') ADVANCE(63);
      END_STATE();
    case 68:
      if (lookahead == 'm') ADVANCE(79);
      if (lookahead == 'p') ADVANCE(105);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(33);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(238);
      END_STATE();
    case 71:
      if (lookahead == 'n') ADVANCE(34);
      END_STATE();
    case 72:
      if (lookahead == 'n') ADVANCE(93);
      END_STATE();
    case 73:
      if (lookahead == 'n') ADVANCE(46);
      END_STATE();
    case 74:
      if (lookahead == 'o') ADVANCE(68);
      END_STATE();
    case 75:
      if (lookahead == 'o') ADVANCE(70);
      END_STATE();
    case 76:
      if (lookahead == 'o') ADVANCE(82);
      END_STATE();
    case 77:
      if (lookahead == 'o') ADVANCE(83);
      END_STATE();
    case 78:
      if (lookahead == 'o') ADVANCE(71);
      END_STATE();
    case 79:
      if (lookahead == 'p') ADVANCE(25);
      END_STATE();
    case 80:
      if (lookahead == 'p') ADVANCE(90);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(52);
      if (lookahead == 'u') ADVANCE(97);
      END_STATE();
    case 82:
      if (lookahead == 'r') ADVANCE(236);
      END_STATE();
    case 83:
      if (lookahead == 'r') ADVANCE(237);
      END_STATE();
    case 84:
      if (lookahead == 'r') ADVANCE(92);
      END_STATE();
    case 85:
      if (lookahead == 'r') ADVANCE(23);
      END_STATE();
    case 86:
      if (lookahead == 'r') ADVANCE(76);
      END_STATE();
    case 87:
      if (lookahead == 'r') ADVANCE(86);
      END_STATE();
    case 88:
      if (lookahead == 'r') ADVANCE(39);
      END_STATE();
    case 89:
      if (lookahead == 'r') ADVANCE(61);
      END_STATE();
    case 90:
      if (lookahead == 'r') ADVANCE(43);
      END_STATE();
    case 91:
      if (lookahead == 's') ADVANCE(128);
      END_STATE();
    case 92:
      if (lookahead == 's') ADVANCE(62);
      END_STATE();
    case 93:
      if (lookahead == 's') ADVANCE(42);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(130);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(133);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(131);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(56);
      END_STATE();
    case 98:
      if (lookahead == 't') ADVANCE(241);
      END_STATE();
    case 99:
      if (lookahead == 't') ADVANCE(242);
      END_STATE();
    case 100:
      if (lookahead == 't') ADVANCE(57);
      END_STATE();
    case 101:
      if (lookahead == 't') ADVANCE(48);
      END_STATE();
    case 102:
      if (lookahead == 'u') ADVANCE(65);
      END_STATE();
    case 103:
      if (lookahead == 'u') ADVANCE(88);
      END_STATE();
    case 104:
      if (lookahead == 'u') ADVANCE(53);
      END_STATE();
    case 105:
      if (lookahead == 'y') ADVANCE(89);
      END_STATE();
    case 106:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(106);
      if (lookahead != 0) ADVANCE(127);
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
        '/', 18,
        ':', 152,
        '@', 22,
        'i', 91,
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
      if (lookahead == '!') ADVANCE(12);
      if (lookahead == '%') ADVANCE(12);
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
      if (lookahead == '@') ADVANCE(22);
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
      if (lookahead == '/') ADVANCE(19);
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
      if (lookahead == '/') ADVANCE(19);
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
      if (lookahead == '/') ADVANCE(19);
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
      if (lookahead == '/') ADVANCE(19);
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
      if (lookahead == 'g') ADVANCE(232);
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
      if (lookahead == '/') ADVANCE(19);
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
      ACCEPT_TOKEN(anon_sym_ATarg);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(aux_sym_pl_tag_token1);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(aux_sym_pl_tag_token1);
      if (lookahead == '\n') ADVANCE(234);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(10);
      if (lookahead != 0) ADVANCE(11);
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
  [4] = {.lex_state = 14},
  [5] = {.lex_state = 14},
  [6] = {.lex_state = 107},
  [7] = {.lex_state = 170},
  [8] = {.lex_state = 229},
  [9] = {.lex_state = 109},
  [10] = {.lex_state = 109},
  [11] = {.lex_state = 109},
  [12] = {.lex_state = 109},
  [13] = {.lex_state = 229},
  [14] = {.lex_state = 170},
  [15] = {.lex_state = 108},
  [16] = {.lex_state = 15},
  [17] = {.lex_state = 229},
  [18] = {.lex_state = 15},
  [19] = {.lex_state = 9},
  [20] = {.lex_state = 9},
  [21] = {.lex_state = 109},
  [22] = {.lex_state = 109},
  [23] = {.lex_state = 6},
  [24] = {.lex_state = 109},
  [25] = {.lex_state = 109},
  [26] = {.lex_state = 109},
  [27] = {.lex_state = 109},
  [28] = {.lex_state = 15},
  [29] = {.lex_state = 15},
  [30] = {.lex_state = 15},
  [31] = {.lex_state = 15},
  [32] = {.lex_state = 8},
  [33] = {.lex_state = 15},
  [34] = {.lex_state = 15},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 16},
  [38] = {.lex_state = 109},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 109},
  [41] = {.lex_state = 109},
  [42] = {.lex_state = 109},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 109},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 109},
  [47] = {.lex_state = 109},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 109},
  [50] = {.lex_state = 109},
  [51] = {.lex_state = 109},
  [52] = {.lex_state = 109},
  [53] = {.lex_state = 109},
  [54] = {.lex_state = 109},
  [55] = {.lex_state = 109},
  [56] = {.lex_state = 1},
  [57] = {.lex_state = 109},
  [58] = {.lex_state = 109},
  [59] = {.lex_state = 109},
  [60] = {.lex_state = 109},
  [61] = {.lex_state = 109},
  [62] = {.lex_state = 109},
  [63] = {.lex_state = 109},
  [64] = {.lex_state = 109},
  [65] = {.lex_state = 109},
  [66] = {.lex_state = 109},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 172},
  [69] = {.lex_state = 109},
  [70] = {.lex_state = 109},
  [71] = {.lex_state = 16},
  [72] = {.lex_state = 109},
  [73] = {.lex_state = 172},
  [74] = {.lex_state = 109},
  [75] = {.lex_state = 109},
  [76] = {.lex_state = 109},
  [77] = {.lex_state = 109},
  [78] = {.lex_state = 109},
  [79] = {.lex_state = 16},
  [80] = {.lex_state = 1},
  [81] = {.lex_state = 1},
  [82] = {.lex_state = 172},
  [83] = {.lex_state = 172},
  [84] = {.lex_state = 20},
  [85] = {.lex_state = 106},
  [86] = {.lex_state = 1},
  [87] = {.lex_state = 106},
  [88] = {.lex_state = 106},
  [89] = {.lex_state = 16},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 1},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 20},
  [94] = {.lex_state = 106},
  [95] = {.lex_state = 1},
  [96] = {.lex_state = 172},
  [97] = {.lex_state = 20},
  [98] = {.lex_state = 1},
  [99] = {.lex_state = 1},
  [100] = {.lex_state = 1},
  [101] = {.lex_state = 1},
  [102] = {.lex_state = 106},
  [103] = {.lex_state = 106},
  [104] = {.lex_state = 106},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 106},
  [108] = {.lex_state = 106},
  [109] = {.lex_state = 7},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 106},
  [112] = {.lex_state = 7},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 106},
  [115] = {.lex_state = 7},
  [116] = {.lex_state = 7},
  [117] = {.lex_state = 7},
  [118] = {.lex_state = 7},
  [119] = {.lex_state = 7},
  [120] = {.lex_state = 10},
  [121] = {.lex_state = 7},
  [122] = {.lex_state = 106},
  [123] = {.lex_state = 106},
  [124] = {.lex_state = 7},
  [125] = {.lex_state = 7},
  [126] = {.lex_state = 7},
  [127] = {.lex_state = 7},
  [128] = {.lex_state = 7},
  [129] = {.lex_state = 106},
  [130] = {.lex_state = 115},
  [131] = {.lex_state = 106},
  [132] = {.lex_state = 10},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 231},
  [135] = {.lex_state = 10},
  [136] = {.lex_state = 7},
  [137] = {.lex_state = 7},
  [138] = {.lex_state = 10},
  [139] = {.lex_state = 231},
  [140] = {.lex_state = 106},
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
    [sym_source_file] = STATE(110),
    [sym_comment] = STATE(26),
    [sym_normal_comment] = STATE(72),
    [sym_normal_single_line_comment] = STATE(78),
    [sym_pldoc_comment] = STATE(72),
    [sym_pldoc_prolog_directive] = STATE(38),
    [sym_pldoc_prolog_style] = STATE(59),
    [sym_pldoc_c_style] = STATE(59),
    [aux_sym_source_file_repeat1] = STATE(26),
    [aux_sym_pldoc_prolog_style_repeat1] = STATE(38),
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
    STATE(8), 1,
      aux_sym_c_style_description_repeat1,
    STATE(9), 1,
      aux_sym_c_style_body_repeat1,
    STATE(10), 1,
      sym_c_style_description,
    STATE(113), 1,
      sym_c_style_body,
    STATE(115), 1,
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
  [44] = 10,
    ACTIONS(21), 1,
      anon_sym_LF,
    ACTIONS(23), 1,
      aux_sym_operator_template_token1,
    ACTIONS(25), 1,
      anon_sym_COLON_DASH,
    STATE(80), 1,
      sym_functor,
    STATE(91), 1,
      sym_head,
    STATE(97), 1,
      sym_arg_name,
    STATE(117), 1,
      sym_template,
    STATE(129), 1,
      sym_arg_spec,
    STATE(128), 3,
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
    STATE(44), 1,
      sym_functor,
    STATE(54), 1,
      sym_head,
    STATE(61), 1,
      sym_template,
    STATE(97), 1,
      sym_arg_name,
    STATE(122), 1,
      sym_arg_spec,
    STATE(65), 3,
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
    STATE(80), 1,
      sym_functor,
    STATE(91), 1,
      sym_head,
    STATE(97), 1,
      sym_arg_name,
    STATE(117), 1,
      sym_template,
    STATE(129), 1,
      sym_arg_spec,
    STATE(128), 3,
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
    STATE(41), 1,
      sym_arg_name,
    STATE(62), 1,
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
  [215] = 3,
    ACTIONS(15), 1,
      aux_sym_c_style_description_token1,
    STATE(13), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(53), 14,
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
  [238] = 6,
    ACTIONS(55), 1,
      anon_sym_STAR,
    ACTIONS(57), 1,
      anon_sym_STAR_SLASH,
    STATE(12), 1,
      aux_sym_c_style_body_repeat1,
    STATE(115), 1,
      sym_c_tag,
    ACTIONS(59), 5,
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
  [267] = 6,
    ACTIONS(55), 1,
      anon_sym_STAR,
    ACTIONS(57), 1,
      anon_sym_STAR_SLASH,
    STATE(11), 1,
      aux_sym_c_style_body_repeat1,
    STATE(115), 1,
      sym_c_tag,
    ACTIONS(59), 5,
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
  [296] = 6,
    ACTIONS(55), 1,
      anon_sym_STAR,
    ACTIONS(63), 1,
      anon_sym_STAR_SLASH,
    STATE(12), 1,
      aux_sym_c_style_body_repeat1,
    STATE(115), 1,
      sym_c_tag,
    ACTIONS(59), 5,
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
  [325] = 6,
    ACTIONS(65), 1,
      anon_sym_STAR,
    ACTIONS(68), 1,
      anon_sym_STAR_SLASH,
    STATE(12), 1,
      aux_sym_c_style_body_repeat1,
    STATE(115), 1,
      sym_c_tag,
    ACTIONS(70), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(73), 7,
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
  [377] = 1,
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
  [395] = 6,
    ACTIONS(83), 1,
      anon_sym_PERCENT,
    ACTIONS(85), 1,
      aux_sym_operator_template_token1,
    STATE(41), 1,
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
  [423] = 7,
    ACTIONS(29), 1,
      aux_sym_operator_template_token1,
    STATE(44), 1,
      sym_functor,
    STATE(54), 1,
      sym_head,
    STATE(97), 1,
      sym_arg_name,
    STATE(122), 1,
      sym_arg_spec,
    STATE(63), 2,
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
    STATE(80), 1,
      sym_functor,
    STATE(91), 1,
      sym_head,
    STATE(97), 1,
      sym_arg_name,
    STATE(129), 1,
      sym_arg_spec,
    STATE(137), 2,
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
    STATE(64), 1,
      sym_pl_tag,
    ACTIONS(89), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(91), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [524] = 4,
    ACTIONS(93), 1,
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
  [547] = 2,
    ACTIONS(95), 1,
      anon_sym_STAR,
    ACTIONS(68), 13,
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
    STATE(99), 1,
      sym_arg_name,
    STATE(136), 1,
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
  [614] = 9,
    ACTIONS(109), 1,
      ts_builtin_sym_end,
    ACTIONS(111), 1,
      anon_sym_PERCENT,
    ACTIONS(114), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(117), 1,
      anon_sym_SLASH_STAR_STAR,
    STATE(78), 1,
      sym_normal_single_line_comment,
    STATE(24), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(38), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(59), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
    STATE(72), 2,
      sym_normal_comment,
      sym_pldoc_comment,
  [646] = 3,
    STATE(64), 1,
      sym_pl_tag,
    ACTIONS(120), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(122), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [666] = 9,
    ACTIONS(5), 1,
      anon_sym_PERCENT,
    ACTIONS(7), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(9), 1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(124), 1,
      ts_builtin_sym_end,
    STATE(78), 1,
      sym_normal_single_line_comment,
    STATE(24), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(38), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(59), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
    STATE(72), 2,
      sym_normal_comment,
      sym_pldoc_comment,
  [698] = 3,
    STATE(124), 1,
      sym_c_tag,
    ACTIONS(59), 5,
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
  [718] = 5,
    ACTIONS(85), 1,
      aux_sym_operator_template_token1,
    STATE(29), 1,
      aux_sym_head_repeat1,
    STATE(41), 1,
      sym_arg_name,
    STATE(92), 1,
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
    STATE(31), 1,
      aux_sym_head_repeat1,
    STATE(41), 1,
      sym_arg_name,
    STATE(90), 1,
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
    ACTIONS(85), 1,
      aux_sym_operator_template_token1,
    STATE(33), 1,
      aux_sym_head_repeat1,
    STATE(41), 1,
      sym_arg_name,
    STATE(105), 1,
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
  [787] = 5,
    ACTIONS(126), 1,
      aux_sym_operator_template_token1,
    STATE(31), 1,
      aux_sym_head_repeat1,
    STATE(41), 1,
      sym_arg_name,
    STATE(133), 1,
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
  [810] = 5,
    ACTIONS(81), 1,
      anon_sym_LF,
    ACTIONS(132), 1,
      aux_sym_operator_template_token1,
    STATE(99), 1,
      sym_arg_name,
    STATE(109), 1,
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
  [833] = 5,
    ACTIONS(85), 1,
      aux_sym_operator_template_token1,
    STATE(31), 1,
      aux_sym_head_repeat1,
    STATE(41), 1,
      sym_arg_name,
    STATE(106), 1,
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
  [868] = 6,
    ACTIONS(138), 1,
      anon_sym_PERCENT,
    ACTIONS(140), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(142), 1,
      aux_sym_prolog_style_description_token2,
    STATE(39), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(75), 1,
      sym_prolog_style_description,
    ACTIONS(136), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [889] = 6,
    ACTIONS(140), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(142), 1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(146), 1,
      anon_sym_PERCENT,
    STATE(39), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(74), 1,
      sym_prolog_style_description,
    ACTIONS(144), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [910] = 7,
    ACTIONS(148), 1,
      anon_sym_PERCENT,
    STATE(39), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(57), 1,
      sym_prolog_style_description,
    STATE(58), 1,
      aux_sym_prolog_style_body_repeat1,
    STATE(70), 1,
      sym_prolog_style_body,
    STATE(71), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(142), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [933] = 5,
    ACTIONS(152), 1,
      anon_sym_PERCENT,
    ACTIONS(155), 1,
      aux_sym_pldoc_prolog_directive_token1,
    STATE(37), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(150), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(50), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [951] = 5,
    ACTIONS(160), 1,
      anon_sym_PERCENT,
    ACTIONS(162), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(164), 1,
      aux_sym_prolog_style_description_token2,
    STATE(43), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(158), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [969] = 2,
    ACTIONS(168), 1,
      anon_sym_PERCENT,
    ACTIONS(166), 6,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [981] = 3,
    ACTIONS(172), 1,
      anon_sym_PERCENT,
    ACTIONS(174), 1,
      anon_sym_COLON,
    ACTIONS(170), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [995] = 3,
    ACTIONS(178), 1,
      anon_sym_PERCENT,
    ACTIONS(180), 1,
      anon_sym_COLON,
    ACTIONS(176), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1009] = 5,
    ACTIONS(184), 1,
      anon_sym_PERCENT,
    ACTIONS(186), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(189), 1,
      aux_sym_prolog_style_description_token2,
    STATE(43), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(182), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1027] = 3,
    ACTIONS(194), 1,
      anon_sym_PERCENT,
    ACTIONS(196), 1,
      anon_sym_LPAREN,
    ACTIONS(192), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1040] = 1,
    ACTIONS(198), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [1049] = 2,
    ACTIONS(202), 1,
      anon_sym_PERCENT,
    ACTIONS(200), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1060] = 2,
    ACTIONS(206), 1,
      anon_sym_PERCENT,
    ACTIONS(204), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1071] = 1,
    ACTIONS(208), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [1080] = 2,
    ACTIONS(212), 1,
      anon_sym_PERCENT,
    ACTIONS(210), 5,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1091] = 4,
    ACTIONS(216), 1,
      anon_sym_PERCENT,
    ACTIONS(218), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(214), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(50), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [1106] = 2,
    ACTIONS(223), 1,
      anon_sym_PERCENT,
    ACTIONS(221), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1116] = 3,
    ACTIONS(227), 1,
      anon_sym_PERCENT,
    STATE(52), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(225), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1128] = 3,
    ACTIONS(232), 1,
      anon_sym_PERCENT,
    STATE(52), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(230), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1140] = 3,
    ACTIONS(237), 1,
      anon_sym_PERCENT,
    ACTIONS(239), 1,
      anon_sym_is,
    ACTIONS(235), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1152] = 2,
    ACTIONS(243), 1,
      anon_sym_PERCENT,
    ACTIONS(241), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1162] = 5,
    ACTIONS(245), 1,
      anon_sym_LF,
    ACTIONS(247), 1,
      anon_sym_STAR,
    ACTIONS(249), 1,
      anon_sym_STAR_SLASH,
    STATE(2), 1,
      aux_sym_pldoc_c_style_repeat2,
    STATE(67), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1178] = 3,
    ACTIONS(253), 1,
      anon_sym_PERCENT,
    STATE(53), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(251), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1190] = 3,
    ACTIONS(253), 1,
      anon_sym_PERCENT,
    STATE(52), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(251), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1202] = 2,
    ACTIONS(258), 1,
      anon_sym_PERCENT,
    ACTIONS(256), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1211] = 2,
    ACTIONS(262), 1,
      anon_sym_PERCENT,
    ACTIONS(260), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1220] = 2,
    ACTIONS(266), 1,
      anon_sym_PERCENT,
    ACTIONS(264), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1229] = 2,
    ACTIONS(83), 1,
      anon_sym_PERCENT,
    ACTIONS(81), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1238] = 2,
    ACTIONS(270), 1,
      anon_sym_PERCENT,
    ACTIONS(268), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1247] = 2,
    ACTIONS(272), 1,
      anon_sym_PERCENT,
    ACTIONS(225), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1256] = 2,
    ACTIONS(276), 1,
      anon_sym_PERCENT,
    ACTIONS(274), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1265] = 2,
    ACTIONS(280), 1,
      anon_sym_PERCENT,
    ACTIONS(278), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1274] = 4,
    ACTIONS(282), 1,
      anon_sym_LF,
    ACTIONS(284), 1,
      anon_sym_STAR,
    ACTIONS(287), 1,
      anon_sym_STAR_SLASH,
    STATE(67), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1287] = 4,
    ACTIONS(289), 1,
      anon_sym_LF,
    ACTIONS(291), 1,
      aux_sym_c_style_description_token1,
    STATE(82), 1,
      aux_sym_c_style_description_repeat1,
    STATE(118), 1,
      sym_c_style_description,
  [1300] = 2,
    ACTIONS(295), 1,
      anon_sym_PERCENT,
    ACTIONS(293), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1309] = 2,
    ACTIONS(299), 1,
      anon_sym_PERCENT,
    ACTIONS(297), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1318] = 3,
    ACTIONS(301), 1,
      anon_sym_PERCENT,
    STATE(71), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(304), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [1329] = 2,
    ACTIONS(308), 1,
      anon_sym_PERCENT,
    ACTIONS(306), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1338] = 4,
    ACTIONS(291), 1,
      aux_sym_c_style_description_token1,
    ACTIONS(310), 1,
      anon_sym_LF,
    STATE(82), 1,
      aux_sym_c_style_description_repeat1,
    STATE(121), 1,
      sym_c_style_description,
  [1351] = 2,
    ACTIONS(138), 1,
      anon_sym_PERCENT,
    ACTIONS(136), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1360] = 2,
    ACTIONS(314), 1,
      anon_sym_PERCENT,
    ACTIONS(312), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1369] = 2,
    ACTIONS(318), 1,
      anon_sym_PERCENT,
    ACTIONS(316), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1378] = 2,
    ACTIONS(322), 1,
      anon_sym_PERCENT,
    ACTIONS(320), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1387] = 2,
    ACTIONS(326), 1,
      anon_sym_PERCENT,
    ACTIONS(324), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1396] = 2,
    ACTIONS(328), 1,
      anon_sym_PERCENT,
    ACTIONS(304), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [1404] = 3,
    ACTIONS(192), 1,
      anon_sym_LF,
    ACTIONS(194), 1,
      anon_sym_is,
    ACTIONS(330), 1,
      anon_sym_LPAREN,
  [1414] = 2,
    ACTIONS(332), 1,
      anon_sym_LF,
    ACTIONS(334), 2,
      anon_sym_STAR,
      anon_sym_STAR_SLASH,
  [1422] = 3,
    ACTIONS(53), 1,
      anon_sym_LF,
    ACTIONS(291), 1,
      aux_sym_c_style_description_token1,
    STATE(83), 1,
      aux_sym_c_style_description_repeat1,
  [1432] = 3,
    ACTIONS(76), 1,
      anon_sym_LF,
    ACTIONS(336), 1,
      aux_sym_c_style_description_token1,
    STATE(83), 1,
      aux_sym_c_style_description_repeat1,
  [1442] = 1,
    ACTIONS(168), 2,
      aux_sym_operator_template_token1,
      anon_sym_COLON,
  [1447] = 2,
    ACTIONS(339), 1,
      aux_sym_operator_template_token1,
    STATE(127), 1,
      sym_type,
  [1454] = 2,
    ACTIONS(341), 1,
      anon_sym_LF,
    ACTIONS(343), 1,
      anon_sym_NULL,
  [1461] = 2,
    ACTIONS(345), 1,
      aux_sym_operator_template_token1,
    STATE(114), 1,
      sym_type,
  [1468] = 2,
    ACTIONS(345), 1,
      aux_sym_operator_template_token1,
    STATE(131), 1,
      sym_type,
  [1475] = 2,
    ACTIONS(347), 1,
      anon_sym_STAR,
    STATE(56), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1482] = 2,
    ACTIONS(349), 1,
      anon_sym_COMMA,
    ACTIONS(351), 1,
      anon_sym_RPAREN,
  [1489] = 2,
    ACTIONS(235), 1,
      anon_sym_LF,
    ACTIONS(353), 1,
      anon_sym_is,
  [1496] = 2,
    ACTIONS(349), 1,
      anon_sym_COMMA,
    ACTIONS(355), 1,
      anon_sym_RPAREN,
  [1503] = 2,
    ACTIONS(178), 1,
      aux_sym_operator_template_token1,
    ACTIONS(357), 1,
      anon_sym_COLON,
  [1510] = 2,
    ACTIONS(359), 1,
      aux_sym_operator_template_token1,
    STATE(93), 1,
      sym_arg_name,
  [1517] = 2,
    ACTIONS(241), 1,
      anon_sym_LF,
    ACTIONS(243), 1,
      anon_sym_is,
  [1524] = 1,
    ACTIONS(76), 2,
      anon_sym_LF,
      aux_sym_c_style_description_token1,
  [1529] = 2,
    ACTIONS(172), 1,
      aux_sym_operator_template_token1,
    ACTIONS(361), 1,
      anon_sym_COLON,
  [1536] = 2,
    ACTIONS(221), 1,
      anon_sym_LF,
    ACTIONS(223), 1,
      anon_sym_is,
  [1543] = 2,
    ACTIONS(170), 1,
      anon_sym_LF,
    ACTIONS(363), 1,
      anon_sym_COLON,
  [1550] = 2,
    ACTIONS(166), 1,
      anon_sym_LF,
    ACTIONS(168), 1,
      anon_sym_COLON,
  [1557] = 2,
    ACTIONS(176), 1,
      anon_sym_LF,
    ACTIONS(365), 1,
      anon_sym_COLON,
  [1564] = 2,
    ACTIONS(367), 1,
      aux_sym_operator_template_token1,
    STATE(42), 1,
      sym_arg_name,
  [1571] = 2,
    ACTIONS(369), 1,
      aux_sym_operator_template_token1,
    STATE(47), 1,
      sym_type,
  [1578] = 2,
    ACTIONS(369), 1,
      aux_sym_operator_template_token1,
    STATE(46), 1,
      sym_type,
  [1585] = 2,
    ACTIONS(349), 1,
      anon_sym_COMMA,
    ACTIONS(371), 1,
      anon_sym_RPAREN,
  [1592] = 2,
    ACTIONS(349), 1,
      anon_sym_COMMA,
    ACTIONS(373), 1,
      anon_sym_RPAREN,
  [1599] = 2,
    ACTIONS(375), 1,
      aux_sym_operator_template_token1,
    STATE(101), 1,
      sym_arg_name,
  [1606] = 2,
    ACTIONS(339), 1,
      aux_sym_operator_template_token1,
    STATE(126), 1,
      sym_type,
  [1613] = 1,
    ACTIONS(320), 1,
      anon_sym_LF,
  [1617] = 1,
    ACTIONS(377), 1,
      ts_builtin_sym_end,
  [1621] = 1,
    ACTIONS(210), 1,
      aux_sym_operator_template_token1,
  [1625] = 1,
    ACTIONS(316), 1,
      anon_sym_LF,
  [1629] = 1,
    ACTIONS(379), 1,
      anon_sym_STAR_SLASH,
  [1633] = 1,
    ACTIONS(204), 1,
      aux_sym_operator_template_token1,
  [1637] = 1,
    ACTIONS(381), 1,
      anon_sym_LF,
  [1641] = 1,
    ACTIONS(383), 1,
      anon_sym_LF,
  [1645] = 1,
    ACTIONS(385), 1,
      anon_sym_LF,
  [1649] = 1,
    ACTIONS(387), 1,
      anon_sym_LF,
  [1653] = 1,
    ACTIONS(21), 1,
      anon_sym_LF,
  [1657] = 1,
    ACTIONS(389), 1,
      aux_sym_pl_tag_token1,
  [1661] = 1,
    ACTIONS(391), 1,
      anon_sym_LF,
  [1665] = 1,
    ACTIONS(393), 1,
      aux_sym_operator_template_token1,
  [1669] = 1,
    ACTIONS(395), 1,
      aux_sym_operator_template_token1,
  [1673] = 1,
    ACTIONS(397), 1,
      anon_sym_LF,
  [1677] = 1,
    ACTIONS(210), 1,
      anon_sym_LF,
  [1681] = 1,
    ACTIONS(204), 1,
      anon_sym_LF,
  [1685] = 1,
    ACTIONS(200), 1,
      anon_sym_LF,
  [1689] = 1,
    ACTIONS(274), 1,
      anon_sym_LF,
  [1693] = 1,
    ACTIONS(399), 1,
      aux_sym_operator_template_token1,
  [1697] = 1,
    ACTIONS(401), 1,
      aux_sym_normal_single_line_comment_token1,
  [1701] = 1,
    ACTIONS(200), 1,
      aux_sym_operator_template_token1,
  [1705] = 1,
    ACTIONS(403), 1,
      aux_sym_pl_tag_token1,
  [1709] = 1,
    ACTIONS(349), 1,
      anon_sym_COMMA,
  [1713] = 1,
    ACTIONS(405), 1,
      aux_sym_c_style_description_token2,
  [1717] = 1,
    ACTIONS(407), 1,
      aux_sym_pl_tag_token1,
  [1721] = 1,
    ACTIONS(81), 1,
      anon_sym_LF,
  [1725] = 1,
    ACTIONS(268), 1,
      anon_sym_LF,
  [1729] = 1,
    ACTIONS(409), 1,
      aux_sym_pl_tag_token1,
  [1733] = 1,
    ACTIONS(411), 1,
      aux_sym_c_style_description_token2,
  [1737] = 1,
    ACTIONS(413), 1,
      aux_sym_operator_template_token1,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 44,
  [SMALL_STATE(4)] = 84,
  [SMALL_STATE(5)] = 121,
  [SMALL_STATE(6)] = 158,
  [SMALL_STATE(7)] = 190,
  [SMALL_STATE(8)] = 215,
  [SMALL_STATE(9)] = 238,
  [SMALL_STATE(10)] = 267,
  [SMALL_STATE(11)] = 296,
  [SMALL_STATE(12)] = 325,
  [SMALL_STATE(13)] = 354,
  [SMALL_STATE(14)] = 377,
  [SMALL_STATE(15)] = 395,
  [SMALL_STATE(16)] = 423,
  [SMALL_STATE(17)] = 453,
  [SMALL_STATE(18)] = 471,
  [SMALL_STATE(19)] = 501,
  [SMALL_STATE(20)] = 524,
  [SMALL_STATE(21)] = 547,
  [SMALL_STATE(22)] = 566,
  [SMALL_STATE(23)] = 585,
  [SMALL_STATE(24)] = 614,
  [SMALL_STATE(25)] = 646,
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
  [SMALL_STATE(36)] = 889,
  [SMALL_STATE(37)] = 910,
  [SMALL_STATE(38)] = 933,
  [SMALL_STATE(39)] = 951,
  [SMALL_STATE(40)] = 969,
  [SMALL_STATE(41)] = 981,
  [SMALL_STATE(42)] = 995,
  [SMALL_STATE(43)] = 1009,
  [SMALL_STATE(44)] = 1027,
  [SMALL_STATE(45)] = 1040,
  [SMALL_STATE(46)] = 1049,
  [SMALL_STATE(47)] = 1060,
  [SMALL_STATE(48)] = 1071,
  [SMALL_STATE(49)] = 1080,
  [SMALL_STATE(50)] = 1091,
  [SMALL_STATE(51)] = 1106,
  [SMALL_STATE(52)] = 1116,
  [SMALL_STATE(53)] = 1128,
  [SMALL_STATE(54)] = 1140,
  [SMALL_STATE(55)] = 1152,
  [SMALL_STATE(56)] = 1162,
  [SMALL_STATE(57)] = 1178,
  [SMALL_STATE(58)] = 1190,
  [SMALL_STATE(59)] = 1202,
  [SMALL_STATE(60)] = 1211,
  [SMALL_STATE(61)] = 1220,
  [SMALL_STATE(62)] = 1229,
  [SMALL_STATE(63)] = 1238,
  [SMALL_STATE(64)] = 1247,
  [SMALL_STATE(65)] = 1256,
  [SMALL_STATE(66)] = 1265,
  [SMALL_STATE(67)] = 1274,
  [SMALL_STATE(68)] = 1287,
  [SMALL_STATE(69)] = 1300,
  [SMALL_STATE(70)] = 1309,
  [SMALL_STATE(71)] = 1318,
  [SMALL_STATE(72)] = 1329,
  [SMALL_STATE(73)] = 1338,
  [SMALL_STATE(74)] = 1351,
  [SMALL_STATE(75)] = 1360,
  [SMALL_STATE(76)] = 1369,
  [SMALL_STATE(77)] = 1378,
  [SMALL_STATE(78)] = 1387,
  [SMALL_STATE(79)] = 1396,
  [SMALL_STATE(80)] = 1404,
  [SMALL_STATE(81)] = 1414,
  [SMALL_STATE(82)] = 1422,
  [SMALL_STATE(83)] = 1432,
  [SMALL_STATE(84)] = 1442,
  [SMALL_STATE(85)] = 1447,
  [SMALL_STATE(86)] = 1454,
  [SMALL_STATE(87)] = 1461,
  [SMALL_STATE(88)] = 1468,
  [SMALL_STATE(89)] = 1475,
  [SMALL_STATE(90)] = 1482,
  [SMALL_STATE(91)] = 1489,
  [SMALL_STATE(92)] = 1496,
  [SMALL_STATE(93)] = 1503,
  [SMALL_STATE(94)] = 1510,
  [SMALL_STATE(95)] = 1517,
  [SMALL_STATE(96)] = 1524,
  [SMALL_STATE(97)] = 1529,
  [SMALL_STATE(98)] = 1536,
  [SMALL_STATE(99)] = 1543,
  [SMALL_STATE(100)] = 1550,
  [SMALL_STATE(101)] = 1557,
  [SMALL_STATE(102)] = 1564,
  [SMALL_STATE(103)] = 1571,
  [SMALL_STATE(104)] = 1578,
  [SMALL_STATE(105)] = 1585,
  [SMALL_STATE(106)] = 1592,
  [SMALL_STATE(107)] = 1599,
  [SMALL_STATE(108)] = 1606,
  [SMALL_STATE(109)] = 1613,
  [SMALL_STATE(110)] = 1617,
  [SMALL_STATE(111)] = 1621,
  [SMALL_STATE(112)] = 1625,
  [SMALL_STATE(113)] = 1629,
  [SMALL_STATE(114)] = 1633,
  [SMALL_STATE(115)] = 1637,
  [SMALL_STATE(116)] = 1641,
  [SMALL_STATE(117)] = 1645,
  [SMALL_STATE(118)] = 1649,
  [SMALL_STATE(119)] = 1653,
  [SMALL_STATE(120)] = 1657,
  [SMALL_STATE(121)] = 1661,
  [SMALL_STATE(122)] = 1665,
  [SMALL_STATE(123)] = 1669,
  [SMALL_STATE(124)] = 1673,
  [SMALL_STATE(125)] = 1677,
  [SMALL_STATE(126)] = 1681,
  [SMALL_STATE(127)] = 1685,
  [SMALL_STATE(128)] = 1689,
  [SMALL_STATE(129)] = 1693,
  [SMALL_STATE(130)] = 1697,
  [SMALL_STATE(131)] = 1701,
  [SMALL_STATE(132)] = 1705,
  [SMALL_STATE(133)] = 1709,
  [SMALL_STATE(134)] = 1713,
  [SMALL_STATE(135)] = 1717,
  [SMALL_STATE(136)] = 1721,
  [SMALL_STATE(137)] = 1725,
  [SMALL_STATE(138)] = 1729,
  [SMALL_STATE(139)] = 1733,
  [SMALL_STATE(140)] = 1737,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(139),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(140),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(135),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor, 1, 0, 0),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor, 1, 0, 0),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_arg_name, 1, 0, 0), SHIFT(40),
  [40] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_arg_name, 1, 0, 0), SHIFT(102),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0), SHIFT_REPEAT(7),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0), SHIFT_REPEAT(119),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_style_description, 1, 0, 0),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 1, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 2, 0, 0),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(27),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(140),
  [73] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(135),
  [76] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(139),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 2, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 2, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(123),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(132),
  [93] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [101] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_arg_name, 1, 0, 0), SHIFT(100),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(107),
  [106] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_arg_name, 1, 0, 0), SHIFT(107),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [111] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(130),
  [114] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [117] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [126] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(40),
  [129] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(102),
  [132] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 3, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 3, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 2, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 2, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0),
  [152] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(116),
  [155] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(4),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_name, 1, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_name, 1, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 1, 0, 0),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 1, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 2, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 2, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [186] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [189] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 1, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 1, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 4, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 4, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 3, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 3, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [218] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [221] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 5, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 5, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [227] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(25),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 2, 0, 0),
  [232] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 2, 0, 0), SHIFT(25),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 1, 0, 0),
  [237] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 1, 0, 0),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 4, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 4, 0, 0),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [247] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [249] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 1, 0, 0),
  [253] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 1, 0, 0), SHIFT(25),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [258] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [266] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive_template, 2, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive_template, 2, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1, 0, 0),
  [276] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_template, 1, 0, 0),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [280] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [282] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [284] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [287] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [289] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 2, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = false}}, SHIFT(134),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [295] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [299] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [301] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0), SHIFT_REPEAT(116),
  [304] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [308] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 1, 0, 0),
  [310] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 3, 0, 0),
  [312] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 4, 0, 0),
  [314] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 4, 0, 0),
  [316] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 3, 0, 0),
  [318] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 3, 0, 0),
  [320] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 3, 0, 0),
  [322] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 3, 0, 0),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [326] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [328] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [330] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [332] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [334] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [336] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(134),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [343] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [353] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [357] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [361] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [363] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [365] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [377] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 3, 0, 0),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [391] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 4, 0, 0),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [395] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [399] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [401] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [403] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [405] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [407] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [409] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [411] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [413] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
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
