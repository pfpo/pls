#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 109
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 75
#define ALIAS_COUNT 0
#define TOKEN_COUNT 45
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 1

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
  anon_sym_LPAREN = 12,
  anon_sym_COMMA = 13,
  anon_sym_RPAREN = 14,
  anon_sym_PLUS_PLUS = 15,
  anon_sym_PLUS = 16,
  anon_sym_DASH = 17,
  anon_sym_DASH_DASH = 18,
  anon_sym_QMARK = 19,
  anon_sym_COLON = 20,
  anon_sym_AT = 21,
  anon_sym_BANG = 22,
  aux_sym_functor_token1 = 23,
  aux_sym_pldoc_prolog_directive_token1 = 24,
  aux_sym_prolog_style_description_token1 = 25,
  aux_sym_prolog_style_description_token2 = 26,
  anon_sym_SLASH_STAR_STAR = 27,
  anon_sym_STAR = 28,
  anon_sym_STAR_SLASH = 29,
  aux_sym_c_style_description_token1 = 30,
  aux_sym_c_style_description_token2 = 31,
  anon_sym_ATarg = 32,
  aux_sym_pl_tag_token1 = 33,
  anon_sym_ATparam = 34,
  anon_sym_ATerror = 35,
  anon_sym_ATauthor = 36,
  anon_sym_ATversion = 37,
  anon_sym_ATsee = 38,
  anon_sym_ATdeprecated = 39,
  anon_sym_ATcompat = 40,
  anon_sym_ATcopyright = 41,
  anon_sym_ATlicense = 42,
  anon_sym_ATbug = 43,
  anon_sym_ATtbd = 44,
  sym_source_file = 45,
  sym_comment = 46,
  sym_normal_comment = 47,
  sym_normal_single_line_comment = 48,
  sym_template = 49,
  sym_head = 50,
  sym_arg_spec = 51,
  sym_functor = 52,
  sym_type = 53,
  sym_arg_name = 54,
  sym_pldoc_comment = 55,
  sym_pldoc_prolog_directive = 56,
  sym_pldoc_prolog_style = 57,
  sym_prolog_style_body = 58,
  sym_prolog_style_description = 59,
  sym_pldoc_c_style = 60,
  sym_c_style_body = 61,
  sym_c_style_description = 62,
  sym_pl_tag = 63,
  sym_c_tag = 64,
  aux_sym_source_file_repeat1 = 65,
  aux_sym_head_repeat1 = 66,
  aux_sym_pldoc_prolog_style_repeat1 = 67,
  aux_sym_pldoc_prolog_style_repeat2 = 68,
  aux_sym_prolog_style_body_repeat1 = 69,
  aux_sym_prolog_style_description_repeat1 = 70,
  aux_sym_pldoc_c_style_repeat1 = 71,
  aux_sym_pldoc_c_style_repeat2 = 72,
  aux_sym_c_style_body_repeat1 = 73,
  aux_sym_c_style_description_repeat1 = 74,
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
  [anon_sym_is] = anon_sym_is,
  [anon_sym_det] = anon_sym_det,
  [anon_sym_semidet] = anon_sym_semidet,
  [anon_sym_failure] = anon_sym_failure,
  [anon_sym_nondet] = anon_sym_nondet,
  [anon_sym_multi] = anon_sym_multi,
  [anon_sym_undefined] = anon_sym_undefined,
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
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 20,
  [23] = 23,
  [24] = 21,
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
  [35] = 32,
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
  [64] = 36,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 7,
  [71] = 33,
  [72] = 9,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 38,
  [82] = 40,
  [83] = 11,
  [84] = 43,
  [85] = 85,
  [86] = 78,
  [87] = 73,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 60,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 105,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(102);
      ADVANCE_MAP(
        0, 112,
        '!', 130,
        '%', 103,
        '(', 120,
        ')', 122,
        '*', 138,
        '+', 124,
        ',', 121,
        '-', 125,
        '/', 14,
        ':', 128,
        '?', 127,
        '@', 129,
        'd', 31,
        'f', 16,
        'i', 86,
        'm', 97,
        'n', 73,
        's', 32,
        'u', 64,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if ((!eof && lookahead == 00)) ADVANCE(112);
      if (lookahead == '\n') ADVANCE(110);
      if (lookahead == '*') ADVANCE(138);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(131);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(134);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(134);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(133);
      if (lookahead == ' ') ADVANCE(132);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(133);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(109);
      if (lookahead == '@') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(110);
      if (lookahead == '(') ADVANCE(120);
      if (lookahead == 'i') ADVANCE(86);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(205);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(8);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(204);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(132);
      END_STATE();
    case 11:
      if (lookahead == ' ') ADVANCE(135);
      END_STATE();
    case 12:
      if (lookahead == '!') ADVANCE(130);
      if (lookahead == '%') ADVANCE(104);
      if (lookahead == '+') ADVANCE(124);
      if (lookahead == '-') ADVANCE(125);
      if (lookahead == ':') ADVANCE(128);
      if (lookahead == '?') ADVANCE(127);
      if (lookahead == '@') ADVANCE(129);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(131);
      END_STATE();
    case 13:
      if (lookahead == '*') ADVANCE(11);
      END_STATE();
    case 14:
      if (lookahead == '*') ADVANCE(13);
      END_STATE();
    case 15:
      if (lookahead == '/') ADVANCE(145);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(55);
      END_STATE();
    case 17:
      ADVANCE_MAP(
        'a', 76,
        'b', 99,
        'c', 69,
        'd', 35,
        'e', 82,
        'l', 53,
        'p', 19,
        's', 45,
        't', 22,
        'v', 44,
      );
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(61);
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(80);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(93);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(96);
      END_STATE();
    case 22:
      if (lookahead == 'b') ADVANCE(26);
      END_STATE();
    case 23:
      if (lookahead == 'c') ADVANCE(39);
      END_STATE();
    case 24:
      if (lookahead == 'c') ADVANCE(21);
      END_STATE();
    case 25:
      if (lookahead == 'd') ADVANCE(119);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(216);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(211);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(33);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(40);
      END_STATE();
    case 30:
      if (lookahead == 'd') ADVANCE(42);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(89);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(46);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(116);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(75);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(210);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(214);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(90);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(25);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(91);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(79);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(36);
      END_STATE();
    case 46:
      if (lookahead == 'f') ADVANCE(54);
      END_STATE();
    case 47:
      if (lookahead == 'g') ADVANCE(203);
      END_STATE();
    case 48:
      if (lookahead == 'g') ADVANCE(215);
      END_STATE();
    case 49:
      if (lookahead == 'g') ADVANCE(50);
      END_STATE();
    case 50:
      if (lookahead == 'h') ADVANCE(94);
      END_STATE();
    case 51:
      if (lookahead == 'h') ADVANCE(72);
      END_STATE();
    case 52:
      if (lookahead == 'i') ADVANCE(118);
      END_STATE();
    case 53:
      if (lookahead == 'i') ADVANCE(23);
      END_STATE();
    case 54:
      if (lookahead == 'i') ADVANCE(68);
      END_STATE();
    case 55:
      if (lookahead == 'i') ADVANCE(59);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(49);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(70);
      END_STATE();
    case 58:
      if (lookahead == 'i') ADVANCE(30);
      END_STATE();
    case 59:
      if (lookahead == 'l') ADVANCE(98);
      END_STATE();
    case 60:
      if (lookahead == 'l') ADVANCE(95);
      END_STATE();
    case 61:
      if (lookahead == 'm') ADVANCE(206);
      END_STATE();
    case 62:
      if (lookahead == 'm') ADVANCE(58);
      END_STATE();
    case 63:
      if (lookahead == 'm') ADVANCE(74);
      if (lookahead == 'p') ADVANCE(100);
      END_STATE();
    case 64:
      if (lookahead == 'n') ADVANCE(28);
      END_STATE();
    case 65:
      if (lookahead == 'n') ADVANCE(209);
      END_STATE();
    case 66:
      if (lookahead == 'n') ADVANCE(29);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(88);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(41);
      END_STATE();
    case 69:
      if (lookahead == 'o') ADVANCE(63);
      END_STATE();
    case 70:
      if (lookahead == 'o') ADVANCE(65);
      END_STATE();
    case 71:
      if (lookahead == 'o') ADVANCE(77);
      END_STATE();
    case 72:
      if (lookahead == 'o') ADVANCE(78);
      END_STATE();
    case 73:
      if (lookahead == 'o') ADVANCE(66);
      END_STATE();
    case 74:
      if (lookahead == 'p') ADVANCE(20);
      END_STATE();
    case 75:
      if (lookahead == 'p') ADVANCE(85);
      END_STATE();
    case 76:
      if (lookahead == 'r') ADVANCE(47);
      if (lookahead == 'u') ADVANCE(92);
      END_STATE();
    case 77:
      if (lookahead == 'r') ADVANCE(207);
      END_STATE();
    case 78:
      if (lookahead == 'r') ADVANCE(208);
      END_STATE();
    case 79:
      if (lookahead == 'r') ADVANCE(87);
      END_STATE();
    case 80:
      if (lookahead == 'r') ADVANCE(18);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(71);
      END_STATE();
    case 82:
      if (lookahead == 'r') ADVANCE(81);
      END_STATE();
    case 83:
      if (lookahead == 'r') ADVANCE(34);
      END_STATE();
    case 84:
      if (lookahead == 'r') ADVANCE(56);
      END_STATE();
    case 85:
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 86:
      if (lookahead == 's') ADVANCE(113);
      END_STATE();
    case 87:
      if (lookahead == 's') ADVANCE(57);
      END_STATE();
    case 88:
      if (lookahead == 's') ADVANCE(37);
      END_STATE();
    case 89:
      if (lookahead == 't') ADVANCE(114);
      END_STATE();
    case 90:
      if (lookahead == 't') ADVANCE(117);
      END_STATE();
    case 91:
      if (lookahead == 't') ADVANCE(115);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(212);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(213);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(52);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(43);
      END_STATE();
    case 97:
      if (lookahead == 'u') ADVANCE(60);
      END_STATE();
    case 98:
      if (lookahead == 'u') ADVANCE(83);
      END_STATE();
    case 99:
      if (lookahead == 'u') ADVANCE(48);
      END_STATE();
    case 100:
      if (lookahead == 'y') ADVANCE(84);
      END_STATE();
    case 101:
      if (eof) ADVANCE(102);
      if (lookahead == '%') ADVANCE(105);
      if (lookahead == '(') ADVANCE(120);
      if (lookahead == '*') ADVANCE(138);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == '@') ADVANCE(17);
      if (lookahead == 'i') ADVANCE(86);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(101);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(134);
      if (lookahead == '!') ADVANCE(4);
      if (lookahead == '%') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(134);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '%') ADVANCE(10);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym_normal_single_line_comment_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(106);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(107);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym_normal_single_line_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(107);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(108);
      if (lookahead == '@') ADVANCE(146);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(142);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(109);
      if (lookahead == '@') ADVANCE(17);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(110);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(111);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(144);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_is);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_det);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_semidet);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_failure);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_nondet);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_multi);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_undefined);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(123);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(126);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_functor_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(131);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_pldoc_prolog_directive_token1);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token1);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token2);
      if (lookahead == '\n') ADVANCE(134);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR_STAR);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == '/') ADVANCE(140);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '/') ADVANCE(139);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      if (lookahead == '/') ADVANCE(145);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(108);
      if (lookahead == '*') ADVANCE(136);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == '@') ADVANCE(146);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(142);
      if (lookahead != 0) ADVANCE(199);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(108);
      if (lookahead == '*') ADVANCE(136);
      if (lookahead == '@') ADVANCE(146);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(142);
      if (lookahead != 0) ADVANCE(199);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(111);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == '/') ADVANCE(15);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(144);
      if (lookahead != 0) ADVANCE(199);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(111);
      if (lookahead == '*') ADVANCE(145);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(144);
      if (lookahead != 0) ADVANCE(199);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      ADVANCE_MAP(
        '*', 145,
        'a', 184,
        'b', 197,
        'c', 176,
        'd', 158,
        'e', 187,
        'l', 169,
        'p', 149,
        's', 162,
        't', 151,
        'v', 163,
      );
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'a') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'a') ADVANCE(193);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'a') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'a') ADVANCE(196);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'b') ADVANCE(154);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'c') ADVANCE(150);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'c') ADVANCE(159);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'd') ADVANCE(216);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'd') ADVANCE(211);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'e') ADVANCE(210);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'e') ADVANCE(214);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'e') ADVANCE(181);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'e') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'e') ADVANCE(152);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'e') ADVANCE(155);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'e') ADVANCE(156);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'e') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'g') ADVANCE(203);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'g') ADVANCE(215);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'g') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'h') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'h') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'i') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'i') ADVANCE(177);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'i') ADVANCE(166);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'm') ADVANCE(206);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'm') ADVANCE(180);
      if (lookahead == 'p') ADVANCE(198);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'n') ADVANCE(209);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'n') ADVANCE(192);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'o') ADVANCE(173);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'o') ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'o') ADVANCE(182);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'o') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'p') ADVANCE(148);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'p') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'r') ADVANCE(207);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'r') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'r') ADVANCE(164);
      if (lookahead == 'u') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'r') ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'r') ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'r') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'r') ADVANCE(147);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'r') ADVANCE(171);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'r') ADVANCE(160);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 's') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 's') ADVANCE(157);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 't') ADVANCE(212);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 't') ADVANCE(213);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 't') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 't') ADVANCE(161);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'u') ADVANCE(165);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead == 'y') ADVANCE(189);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(145);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(199);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(137);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == '@') ADVANCE(146);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(201);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(199);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(137);
      if (lookahead == '@') ADVANCE(146);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(201);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(199);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_c_style_description_token2);
      if (lookahead == '\n') ADVANCE(202);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_ATarg);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_pl_tag_token1);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_pl_tag_token1);
      if (lookahead == '\n') ADVANCE(205);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(8);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_ATparam);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_ATerror);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_ATauthor);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_ATversion);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_ATsee);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(anon_sym_ATdeprecated);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(anon_sym_ATcompat);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(anon_sym_ATcopyright);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_ATlicense);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(anon_sym_ATbug);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(anon_sym_ATtbd);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 101},
  [2] = {.lex_state = 141},
  [3] = {.lex_state = 101},
  [4] = {.lex_state = 101},
  [5] = {.lex_state = 141},
  [6] = {.lex_state = 101},
  [7] = {.lex_state = 200},
  [8] = {.lex_state = 101},
  [9] = {.lex_state = 200},
  [10] = {.lex_state = 141},
  [11] = {.lex_state = 200},
  [12] = {.lex_state = 6},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 101},
  [15] = {.lex_state = 101},
  [16] = {.lex_state = 101},
  [17] = {.lex_state = 101},
  [18] = {.lex_state = 101},
  [19] = {.lex_state = 101},
  [20] = {.lex_state = 12},
  [21] = {.lex_state = 12},
  [22] = {.lex_state = 12},
  [23] = {.lex_state = 12},
  [24] = {.lex_state = 12},
  [25] = {.lex_state = 12},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 12},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 101},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 101},
  [34] = {.lex_state = 101},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 101},
  [37] = {.lex_state = 101},
  [38] = {.lex_state = 101},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 101},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 101},
  [43] = {.lex_state = 101},
  [44] = {.lex_state = 101},
  [45] = {.lex_state = 101},
  [46] = {.lex_state = 101},
  [47] = {.lex_state = 101},
  [48] = {.lex_state = 101},
  [49] = {.lex_state = 101},
  [50] = {.lex_state = 101},
  [51] = {.lex_state = 101},
  [52] = {.lex_state = 1},
  [53] = {.lex_state = 12},
  [54] = {.lex_state = 101},
  [55] = {.lex_state = 101},
  [56] = {.lex_state = 12},
  [57] = {.lex_state = 143},
  [58] = {.lex_state = 101},
  [59] = {.lex_state = 12},
  [60] = {.lex_state = 101},
  [61] = {.lex_state = 143},
  [62] = {.lex_state = 101},
  [63] = {.lex_state = 101},
  [64] = {.lex_state = 7},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 12},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 143},
  [71] = {.lex_state = 7},
  [72] = {.lex_state = 143},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 12},
  [75] = {.lex_state = 12},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 7},
  [82] = {.lex_state = 7},
  [83] = {.lex_state = 143},
  [84] = {.lex_state = 7},
  [85] = {.lex_state = 1},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 12},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 1},
  [92] = {.lex_state = 1},
  [93] = {.lex_state = 12},
  [94] = {.lex_state = 8},
  [95] = {.lex_state = 8},
  [96] = {.lex_state = 12},
  [97] = {.lex_state = 1},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 1},
  [100] = {.lex_state = 106},
  [101] = {.lex_state = 1},
  [102] = {.lex_state = 8},
  [103] = {.lex_state = 8},
  [104] = {.lex_state = 1},
  [105] = {.lex_state = 202},
  [106] = {.lex_state = 1},
  [107] = {.lex_state = 1},
  [108] = {.lex_state = 202},
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
    [sym_source_file] = STATE(90),
    [sym_comment] = STATE(16),
    [sym_normal_comment] = STATE(49),
    [sym_normal_single_line_comment] = STATE(46),
    [sym_pldoc_comment] = STATE(49),
    [sym_pldoc_prolog_directive] = STATE(29),
    [sym_pldoc_prolog_style] = STATE(55),
    [sym_pldoc_c_style] = STATE(55),
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
      sym_c_style_description,
    STATE(5), 1,
      aux_sym_pldoc_c_style_repeat2,
    STATE(6), 1,
      aux_sym_c_style_body_repeat1,
    STATE(7), 1,
      aux_sym_c_style_description_repeat1,
    STATE(91), 1,
      sym_c_tag,
    STATE(98), 1,
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
  [44] = 6,
    ACTIONS(21), 1,
      anon_sym_STAR,
    ACTIONS(23), 1,
      anon_sym_STAR_SLASH,
    STATE(8), 1,
      aux_sym_c_style_body_repeat1,
    STATE(91), 1,
      sym_c_tag,
    ACTIONS(25), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(27), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [73] = 6,
    ACTIONS(21), 1,
      anon_sym_STAR,
    ACTIONS(29), 1,
      anon_sym_STAR_SLASH,
    STATE(3), 1,
      aux_sym_c_style_body_repeat1,
    STATE(91), 1,
      sym_c_tag,
    ACTIONS(25), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(27), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [102] = 4,
    ACTIONS(31), 1,
      anon_sym_LF,
    ACTIONS(34), 1,
      anon_sym_STAR,
    STATE(5), 1,
      aux_sym_pldoc_c_style_repeat2,
    ACTIONS(37), 13,
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
  [127] = 6,
    ACTIONS(21), 1,
      anon_sym_STAR,
    ACTIONS(29), 1,
      anon_sym_STAR_SLASH,
    STATE(8), 1,
      aux_sym_c_style_body_repeat1,
    STATE(91), 1,
      sym_c_tag,
    ACTIONS(25), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(27), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [156] = 3,
    ACTIONS(15), 1,
      aux_sym_c_style_description_token1,
    STATE(9), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(39), 14,
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
  [179] = 6,
    ACTIONS(41), 1,
      anon_sym_STAR,
    ACTIONS(44), 1,
      anon_sym_STAR_SLASH,
    STATE(8), 1,
      aux_sym_c_style_body_repeat1,
    STATE(91), 1,
      sym_c_tag,
    ACTIONS(46), 5,
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
  [208] = 3,
    ACTIONS(54), 1,
      aux_sym_c_style_description_token1,
    STATE(9), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(52), 14,
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
  [231] = 1,
    ACTIONS(37), 15,
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
    ACTIONS(52), 15,
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
  [267] = 4,
    ACTIONS(57), 1,
      anon_sym_LF,
    STATE(107), 1,
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
  [290] = 4,
    ACTIONS(59), 1,
      anon_sym_LF,
    STATE(50), 1,
      sym_pl_tag,
    ACTIONS(61), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(63), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [313] = 2,
    ACTIONS(65), 1,
      anon_sym_STAR,
    ACTIONS(44), 13,
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
  [332] = 2,
    ACTIONS(67), 1,
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
  [351] = 9,
    ACTIONS(5), 1,
      anon_sym_PERCENT,
    ACTIONS(7), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(9), 1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(71), 1,
      ts_builtin_sym_end,
    STATE(46), 1,
      sym_normal_single_line_comment,
    STATE(17), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(29), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(49), 2,
      sym_normal_comment,
      sym_pldoc_comment,
    STATE(55), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
  [383] = 9,
    ACTIONS(73), 1,
      ts_builtin_sym_end,
    ACTIONS(75), 1,
      anon_sym_PERCENT,
    ACTIONS(78), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(81), 1,
      anon_sym_SLASH_STAR_STAR,
    STATE(46), 1,
      sym_normal_single_line_comment,
    STATE(17), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(29), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(49), 2,
      sym_normal_comment,
      sym_pldoc_comment,
    STATE(55), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
  [415] = 3,
    STATE(107), 1,
      sym_c_tag,
    ACTIONS(25), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(27), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [435] = 3,
    STATE(50), 1,
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
  [455] = 6,
    ACTIONS(92), 1,
      aux_sym_functor_token1,
    STATE(23), 1,
      aux_sym_head_repeat1,
    STATE(67), 1,
      sym_arg_name,
    STATE(73), 1,
      sym_arg_spec,
    ACTIONS(90), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(88), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [480] = 6,
    ACTIONS(92), 1,
      aux_sym_functor_token1,
    STATE(20), 1,
      aux_sym_head_repeat1,
    STATE(67), 1,
      sym_arg_name,
    STATE(78), 1,
      sym_arg_spec,
    ACTIONS(90), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(88), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [505] = 6,
    ACTIONS(92), 1,
      aux_sym_functor_token1,
    STATE(23), 1,
      aux_sym_head_repeat1,
    STATE(67), 1,
      sym_arg_name,
    STATE(87), 1,
      sym_arg_spec,
    ACTIONS(90), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(88), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [530] = 6,
    ACTIONS(100), 1,
      aux_sym_functor_token1,
    STATE(23), 1,
      aux_sym_head_repeat1,
    STATE(67), 1,
      sym_arg_name,
    STATE(89), 1,
      sym_arg_spec,
    ACTIONS(97), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(94), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [555] = 6,
    ACTIONS(92), 1,
      aux_sym_functor_token1,
    STATE(22), 1,
      aux_sym_head_repeat1,
    STATE(67), 1,
      sym_arg_name,
    STATE(86), 1,
      sym_arg_spec,
    ACTIONS(90), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(88), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [580] = 2,
    ACTIONS(105), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
      aux_sym_functor_token1,
  [594] = 6,
    ACTIONS(109), 1,
      anon_sym_PERCENT,
    ACTIONS(111), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(113), 1,
      aux_sym_prolog_style_description_token2,
    STATE(30), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(62), 1,
      sym_prolog_style_description,
    ACTIONS(107), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [615] = 7,
    ACTIONS(115), 1,
      anon_sym_PERCENT,
    STATE(30), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(42), 1,
      sym_prolog_style_description,
    STATE(44), 1,
      aux_sym_prolog_style_body_repeat1,
    STATE(54), 1,
      sym_prolog_style_body,
    STATE(56), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(113), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [638] = 6,
    ACTIONS(111), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(113), 1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(119), 1,
      anon_sym_PERCENT,
    STATE(30), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(63), 1,
      sym_prolog_style_description,
    ACTIONS(117), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [659] = 5,
    ACTIONS(123), 1,
      anon_sym_PERCENT,
    ACTIONS(126), 1,
      aux_sym_pldoc_prolog_directive_token1,
    STATE(27), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(121), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(34), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [677] = 5,
    ACTIONS(131), 1,
      anon_sym_PERCENT,
    ACTIONS(133), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(135), 1,
      aux_sym_prolog_style_description_token2,
    STATE(31), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(129), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [695] = 5,
    ACTIONS(139), 1,
      anon_sym_PERCENT,
    ACTIONS(141), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(144), 1,
      aux_sym_prolog_style_description_token2,
    STATE(31), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(137), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [713] = 1,
    ACTIONS(147), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [722] = 2,
    ACTIONS(151), 1,
      anon_sym_PERCENT,
    ACTIONS(149), 5,
      ts_builtin_sym_end,
      anon_sym_is,
      anon_sym_LPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [733] = 4,
    ACTIONS(155), 1,
      anon_sym_PERCENT,
    ACTIONS(157), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(153), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(34), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [748] = 1,
    ACTIONS(160), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [757] = 3,
    ACTIONS(164), 1,
      anon_sym_PERCENT,
    ACTIONS(166), 1,
      anon_sym_LPAREN,
    ACTIONS(162), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [770] = 3,
    ACTIONS(170), 1,
      anon_sym_PERCENT,
    STATE(37), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(168), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [782] = 3,
    ACTIONS(175), 1,
      anon_sym_PERCENT,
    ACTIONS(177), 1,
      anon_sym_is,
    ACTIONS(173), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [794] = 5,
    ACTIONS(179), 1,
      anon_sym_LF,
    ACTIONS(181), 1,
      anon_sym_STAR,
    ACTIONS(183), 1,
      anon_sym_STAR_SLASH,
    STATE(2), 1,
      aux_sym_pldoc_c_style_repeat2,
    STATE(52), 1,
      aux_sym_pldoc_c_style_repeat1,
  [810] = 2,
    ACTIONS(187), 1,
      anon_sym_PERCENT,
    ACTIONS(185), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [820] = 5,
    ACTIONS(189), 1,
      anon_sym_LF,
    ACTIONS(191), 1,
      aux_sym_functor_token1,
    STATE(64), 1,
      sym_functor,
    STATE(81), 1,
      sym_head,
    STATE(99), 1,
      sym_template,
  [836] = 3,
    ACTIONS(195), 1,
      anon_sym_PERCENT,
    STATE(45), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(193), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [848] = 2,
    ACTIONS(200), 1,
      anon_sym_PERCENT,
    ACTIONS(198), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [858] = 3,
    ACTIONS(195), 1,
      anon_sym_PERCENT,
    STATE(37), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(193), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [870] = 3,
    ACTIONS(204), 1,
      anon_sym_PERCENT,
    STATE(37), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(202), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [882] = 2,
    ACTIONS(209), 1,
      anon_sym_PERCENT,
    ACTIONS(207), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [891] = 2,
    ACTIONS(213), 1,
      anon_sym_PERCENT,
    ACTIONS(211), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [900] = 2,
    ACTIONS(217), 1,
      anon_sym_PERCENT,
    ACTIONS(215), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [909] = 2,
    ACTIONS(221), 1,
      anon_sym_PERCENT,
    ACTIONS(219), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [918] = 2,
    ACTIONS(223), 1,
      anon_sym_PERCENT,
    ACTIONS(168), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [927] = 2,
    ACTIONS(227), 1,
      anon_sym_PERCENT,
    ACTIONS(225), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [936] = 4,
    ACTIONS(229), 1,
      anon_sym_LF,
    ACTIONS(231), 1,
      anon_sym_STAR,
    ACTIONS(234), 1,
      anon_sym_STAR_SLASH,
    STATE(52), 1,
      aux_sym_pldoc_c_style_repeat1,
  [949] = 4,
    ACTIONS(236), 1,
      aux_sym_functor_token1,
    STATE(64), 1,
      sym_functor,
    STATE(81), 1,
      sym_head,
    STATE(99), 1,
      sym_template,
  [962] = 2,
    ACTIONS(240), 1,
      anon_sym_PERCENT,
    ACTIONS(238), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [971] = 2,
    ACTIONS(244), 1,
      anon_sym_PERCENT,
    ACTIONS(242), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [980] = 3,
    ACTIONS(246), 1,
      anon_sym_PERCENT,
    STATE(56), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(249), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [991] = 4,
    ACTIONS(251), 1,
      anon_sym_LF,
    ACTIONS(253), 1,
      aux_sym_c_style_description_token1,
    STATE(70), 1,
      aux_sym_c_style_description_repeat1,
    STATE(106), 1,
      sym_c_style_description,
  [1004] = 2,
    ACTIONS(257), 1,
      anon_sym_PERCENT,
    ACTIONS(255), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1013] = 4,
    ACTIONS(259), 1,
      aux_sym_functor_token1,
    STATE(36), 1,
      sym_functor,
    STATE(38), 1,
      sym_head,
    STATE(48), 1,
      sym_template,
  [1026] = 2,
    ACTIONS(263), 1,
      anon_sym_PERCENT,
    ACTIONS(261), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1035] = 4,
    ACTIONS(253), 1,
      aux_sym_c_style_description_token1,
    ACTIONS(265), 1,
      anon_sym_LF,
    STATE(70), 1,
      aux_sym_c_style_description_repeat1,
    STATE(92), 1,
      sym_c_style_description,
  [1048] = 2,
    ACTIONS(119), 1,
      anon_sym_PERCENT,
    ACTIONS(117), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1057] = 2,
    ACTIONS(269), 1,
      anon_sym_PERCENT,
    ACTIONS(267), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1066] = 3,
    ACTIONS(162), 1,
      anon_sym_LF,
    ACTIONS(164), 1,
      anon_sym_is,
    ACTIONS(271), 1,
      anon_sym_LPAREN,
  [1076] = 1,
    ACTIONS(273), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
  [1082] = 2,
    ACTIONS(275), 1,
      anon_sym_PERCENT,
    ACTIONS(249), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [1090] = 2,
    ACTIONS(279), 1,
      anon_sym_COLON,
    ACTIONS(277), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1098] = 2,
    ACTIONS(283), 1,
      anon_sym_COLON,
    ACTIONS(281), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1106] = 2,
    ACTIONS(285), 1,
      anon_sym_LF,
    ACTIONS(287), 2,
      anon_sym_STAR,
      anon_sym_STAR_SLASH,
  [1114] = 3,
    ACTIONS(39), 1,
      anon_sym_LF,
    ACTIONS(253), 1,
      aux_sym_c_style_description_token1,
    STATE(72), 1,
      aux_sym_c_style_description_repeat1,
  [1124] = 2,
    ACTIONS(149), 1,
      anon_sym_LF,
    ACTIONS(151), 2,
      anon_sym_is,
      anon_sym_LPAREN,
  [1132] = 3,
    ACTIONS(52), 1,
      anon_sym_LF,
    ACTIONS(289), 1,
      aux_sym_c_style_description_token1,
    STATE(72), 1,
      aux_sym_c_style_description_repeat1,
  [1142] = 2,
    ACTIONS(292), 1,
      anon_sym_COMMA,
    ACTIONS(294), 1,
      anon_sym_RPAREN,
  [1149] = 2,
    ACTIONS(92), 1,
      aux_sym_functor_token1,
    STATE(68), 1,
      sym_arg_name,
  [1156] = 2,
    ACTIONS(296), 1,
      aux_sym_functor_token1,
    STATE(80), 1,
      sym_type,
  [1163] = 1,
    ACTIONS(298), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1168] = 1,
    ACTIONS(300), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1173] = 2,
    ACTIONS(292), 1,
      anon_sym_COMMA,
    ACTIONS(302), 1,
      anon_sym_RPAREN,
  [1180] = 2,
    ACTIONS(304), 1,
      anon_sym_STAR,
    STATE(39), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1187] = 1,
    ACTIONS(306), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1192] = 2,
    ACTIONS(173), 1,
      anon_sym_LF,
    ACTIONS(308), 1,
      anon_sym_is,
  [1199] = 2,
    ACTIONS(185), 1,
      anon_sym_LF,
    ACTIONS(187), 1,
      anon_sym_is,
  [1206] = 1,
    ACTIONS(52), 2,
      anon_sym_LF,
      aux_sym_c_style_description_token1,
  [1211] = 2,
    ACTIONS(198), 1,
      anon_sym_LF,
    ACTIONS(200), 1,
      anon_sym_is,
  [1218] = 2,
    ACTIONS(310), 1,
      anon_sym_LF,
    ACTIONS(312), 1,
      anon_sym_NULL,
  [1225] = 2,
    ACTIONS(292), 1,
      anon_sym_COMMA,
    ACTIONS(314), 1,
      anon_sym_RPAREN,
  [1232] = 2,
    ACTIONS(292), 1,
      anon_sym_COMMA,
    ACTIONS(316), 1,
      anon_sym_RPAREN,
  [1239] = 2,
    ACTIONS(296), 1,
      aux_sym_functor_token1,
    STATE(77), 1,
      sym_type,
  [1246] = 1,
    ACTIONS(292), 1,
      anon_sym_COMMA,
  [1250] = 1,
    ACTIONS(318), 1,
      ts_builtin_sym_end,
  [1254] = 1,
    ACTIONS(320), 1,
      anon_sym_LF,
  [1258] = 1,
    ACTIONS(322), 1,
      anon_sym_LF,
  [1262] = 1,
    ACTIONS(324), 1,
      aux_sym_functor_token1,
  [1266] = 1,
    ACTIONS(326), 1,
      aux_sym_pl_tag_token1,
  [1270] = 1,
    ACTIONS(328), 1,
      aux_sym_pl_tag_token1,
  [1274] = 1,
    ACTIONS(330), 1,
      aux_sym_functor_token1,
  [1278] = 1,
    ACTIONS(261), 1,
      anon_sym_LF,
  [1282] = 1,
    ACTIONS(332), 1,
      anon_sym_STAR_SLASH,
  [1286] = 1,
    ACTIONS(334), 1,
      anon_sym_LF,
  [1290] = 1,
    ACTIONS(336), 1,
      aux_sym_normal_single_line_comment_token1,
  [1294] = 1,
    ACTIONS(338), 1,
      anon_sym_LF,
  [1298] = 1,
    ACTIONS(340), 1,
      aux_sym_pl_tag_token1,
  [1302] = 1,
    ACTIONS(342), 1,
      aux_sym_pl_tag_token1,
  [1306] = 1,
    ACTIONS(189), 1,
      anon_sym_LF,
  [1310] = 1,
    ACTIONS(344), 1,
      aux_sym_c_style_description_token2,
  [1314] = 1,
    ACTIONS(346), 1,
      anon_sym_LF,
  [1318] = 1,
    ACTIONS(348), 1,
      anon_sym_LF,
  [1322] = 1,
    ACTIONS(350), 1,
      aux_sym_c_style_description_token2,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 44,
  [SMALL_STATE(4)] = 73,
  [SMALL_STATE(5)] = 102,
  [SMALL_STATE(6)] = 127,
  [SMALL_STATE(7)] = 156,
  [SMALL_STATE(8)] = 179,
  [SMALL_STATE(9)] = 208,
  [SMALL_STATE(10)] = 231,
  [SMALL_STATE(11)] = 249,
  [SMALL_STATE(12)] = 267,
  [SMALL_STATE(13)] = 290,
  [SMALL_STATE(14)] = 313,
  [SMALL_STATE(15)] = 332,
  [SMALL_STATE(16)] = 351,
  [SMALL_STATE(17)] = 383,
  [SMALL_STATE(18)] = 415,
  [SMALL_STATE(19)] = 435,
  [SMALL_STATE(20)] = 455,
  [SMALL_STATE(21)] = 480,
  [SMALL_STATE(22)] = 505,
  [SMALL_STATE(23)] = 530,
  [SMALL_STATE(24)] = 555,
  [SMALL_STATE(25)] = 580,
  [SMALL_STATE(26)] = 594,
  [SMALL_STATE(27)] = 615,
  [SMALL_STATE(28)] = 638,
  [SMALL_STATE(29)] = 659,
  [SMALL_STATE(30)] = 677,
  [SMALL_STATE(31)] = 695,
  [SMALL_STATE(32)] = 713,
  [SMALL_STATE(33)] = 722,
  [SMALL_STATE(34)] = 733,
  [SMALL_STATE(35)] = 748,
  [SMALL_STATE(36)] = 757,
  [SMALL_STATE(37)] = 770,
  [SMALL_STATE(38)] = 782,
  [SMALL_STATE(39)] = 794,
  [SMALL_STATE(40)] = 810,
  [SMALL_STATE(41)] = 820,
  [SMALL_STATE(42)] = 836,
  [SMALL_STATE(43)] = 848,
  [SMALL_STATE(44)] = 858,
  [SMALL_STATE(45)] = 870,
  [SMALL_STATE(46)] = 882,
  [SMALL_STATE(47)] = 891,
  [SMALL_STATE(48)] = 900,
  [SMALL_STATE(49)] = 909,
  [SMALL_STATE(50)] = 918,
  [SMALL_STATE(51)] = 927,
  [SMALL_STATE(52)] = 936,
  [SMALL_STATE(53)] = 949,
  [SMALL_STATE(54)] = 962,
  [SMALL_STATE(55)] = 971,
  [SMALL_STATE(56)] = 980,
  [SMALL_STATE(57)] = 991,
  [SMALL_STATE(58)] = 1004,
  [SMALL_STATE(59)] = 1013,
  [SMALL_STATE(60)] = 1026,
  [SMALL_STATE(61)] = 1035,
  [SMALL_STATE(62)] = 1048,
  [SMALL_STATE(63)] = 1057,
  [SMALL_STATE(64)] = 1066,
  [SMALL_STATE(65)] = 1076,
  [SMALL_STATE(66)] = 1082,
  [SMALL_STATE(67)] = 1090,
  [SMALL_STATE(68)] = 1098,
  [SMALL_STATE(69)] = 1106,
  [SMALL_STATE(70)] = 1114,
  [SMALL_STATE(71)] = 1124,
  [SMALL_STATE(72)] = 1132,
  [SMALL_STATE(73)] = 1142,
  [SMALL_STATE(74)] = 1149,
  [SMALL_STATE(75)] = 1156,
  [SMALL_STATE(76)] = 1163,
  [SMALL_STATE(77)] = 1168,
  [SMALL_STATE(78)] = 1173,
  [SMALL_STATE(79)] = 1180,
  [SMALL_STATE(80)] = 1187,
  [SMALL_STATE(81)] = 1192,
  [SMALL_STATE(82)] = 1199,
  [SMALL_STATE(83)] = 1206,
  [SMALL_STATE(84)] = 1211,
  [SMALL_STATE(85)] = 1218,
  [SMALL_STATE(86)] = 1225,
  [SMALL_STATE(87)] = 1232,
  [SMALL_STATE(88)] = 1239,
  [SMALL_STATE(89)] = 1246,
  [SMALL_STATE(90)] = 1250,
  [SMALL_STATE(91)] = 1254,
  [SMALL_STATE(92)] = 1258,
  [SMALL_STATE(93)] = 1262,
  [SMALL_STATE(94)] = 1266,
  [SMALL_STATE(95)] = 1270,
  [SMALL_STATE(96)] = 1274,
  [SMALL_STATE(97)] = 1278,
  [SMALL_STATE(98)] = 1282,
  [SMALL_STATE(99)] = 1286,
  [SMALL_STATE(100)] = 1290,
  [SMALL_STATE(101)] = 1294,
  [SMALL_STATE(102)] = 1298,
  [SMALL_STATE(103)] = 1302,
  [SMALL_STATE(104)] = 1306,
  [SMALL_STATE(105)] = 1310,
  [SMALL_STATE(106)] = 1314,
  [SMALL_STATE(107)] = 1318,
  [SMALL_STATE(108)] = 1322,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(102),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 2, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(96),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [29] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 1, 0, 0),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0), SHIFT_REPEAT(5),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0), SHIFT_REPEAT(104),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat2, 2, 0, 0),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_style_description, 1, 0, 0),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [49] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(102),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(108),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(66),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(100),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [90] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(74),
  [97] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(74),
  [100] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 2, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 2, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 3, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 3, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0),
  [123] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(101),
  [126] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(59),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [141] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [144] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [147] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor, 1, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor, 1, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [157] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [160] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 1, 0, 0),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 1, 0, 0),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [168] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [170] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_template, 1, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [183] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 4, 0, 0),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 4, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [191] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 1, 0, 0),
  [195] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 1, 0, 0), SHIFT(19),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 5, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 5, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 2, 0, 0),
  [204] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 2, 0, 0), SHIFT(19),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [209] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [221] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 1, 0, 0),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [231] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [240] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [244] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [246] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0), SHIFT_REPEAT(101),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [251] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 2, 0, 0),
  [253] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [257] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 3, 0, 0),
  [263] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_template, 3, 0, 0),
  [265] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 3, 0, 0),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 4, 0, 0),
  [269] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 4, 0, 0),
  [271] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_name, 1, 0, 0),
  [275] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 1, 0, 0),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 2, 0, 0),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [287] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [289] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(105),
  [292] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [294] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [298] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [300] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 3, 0, 0),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [306] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 4, 0, 0),
  [308] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [312] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [314] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [316] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [318] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [322] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 4, 0, 0),
  [324] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [326] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [328] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [336] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [340] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [342] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [346] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 3, 0, 0),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
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
