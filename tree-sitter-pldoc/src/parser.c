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
      if (eof) ADVANCE(104);
      ADVANCE_MAP(
        0, 114,
        '!', 139,
        '%', 105,
        '(', 122,
        ')', 124,
        '*', 149,
        '+', 127,
        ',', 123,
        '-', 129,
        '/', 15,
        ':', 135,
        '?', 133,
        '@', 137,
        'd', 32,
        'f', 17,
        'i', 87,
        'm', 98,
        'n', 74,
        's', 33,
        'u', 65,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if ((!eof && lookahead == 00)) ADVANCE(114);
      if (lookahead == '\n') ADVANCE(112);
      if (lookahead == '(') ADVANCE(122);
      if (lookahead == '*') ADVANCE(149);
      if (lookahead == 'i') ADVANCE(87);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(144);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(144);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(143);
      if (lookahead == ' ') ADVANCE(142);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(143);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(111);
      if (lookahead == '@') ADVANCE(18);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(112);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (lookahead != 0) ADVANCE(141);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(216);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(8);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(215);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(142);
      END_STATE();
    case 11:
      if (lookahead == ' ') ADVANCE(145);
      END_STATE();
    case 12:
      if (lookahead == '!') ADVANCE(140);
      if (lookahead == '+') ADVANCE(128);
      if (lookahead == '-') ADVANCE(130);
      if (lookahead == ':') ADVANCE(136);
      if (lookahead == '?') ADVANCE(134);
      if (lookahead == '@') ADVANCE(138);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      if (lookahead != 0) ADVANCE(141);
      END_STATE();
    case 13:
      if (lookahead == '%') ADVANCE(106);
      if (lookahead == '*') ADVANCE(146);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(13);
      END_STATE();
    case 14:
      if (lookahead == '*') ADVANCE(11);
      END_STATE();
    case 15:
      if (lookahead == '*') ADVANCE(14);
      END_STATE();
    case 16:
      if (lookahead == '/') ADVANCE(156);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(56);
      END_STATE();
    case 18:
      ADVANCE_MAP(
        'a', 77,
        'b', 100,
        'c', 70,
        'd', 36,
        'e', 83,
        'l', 54,
        'p', 20,
        's', 46,
        't', 23,
        'v', 45,
      );
      END_STATE();
    case 19:
      if (lookahead == 'a') ADVANCE(62);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(81);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(94);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(97);
      END_STATE();
    case 23:
      if (lookahead == 'b') ADVANCE(27);
      END_STATE();
    case 24:
      if (lookahead == 'c') ADVANCE(40);
      END_STATE();
    case 25:
      if (lookahead == 'c') ADVANCE(22);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(121);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(227);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(222);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(34);
      END_STATE();
    case 30:
      if (lookahead == 'd') ADVANCE(41);
      END_STATE();
    case 31:
      if (lookahead == 'd') ADVANCE(43);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(90);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(63);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(47);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(118);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(76);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(221);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(225);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(25);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(68);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(91);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(26);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(28);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(80);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(37);
      END_STATE();
    case 47:
      if (lookahead == 'f') ADVANCE(55);
      END_STATE();
    case 48:
      if (lookahead == 'g') ADVANCE(214);
      END_STATE();
    case 49:
      if (lookahead == 'g') ADVANCE(226);
      END_STATE();
    case 50:
      if (lookahead == 'g') ADVANCE(51);
      END_STATE();
    case 51:
      if (lookahead == 'h') ADVANCE(95);
      END_STATE();
    case 52:
      if (lookahead == 'h') ADVANCE(73);
      END_STATE();
    case 53:
      if (lookahead == 'i') ADVANCE(120);
      END_STATE();
    case 54:
      if (lookahead == 'i') ADVANCE(24);
      END_STATE();
    case 55:
      if (lookahead == 'i') ADVANCE(69);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(60);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(50);
      END_STATE();
    case 58:
      if (lookahead == 'i') ADVANCE(71);
      END_STATE();
    case 59:
      if (lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 60:
      if (lookahead == 'l') ADVANCE(99);
      END_STATE();
    case 61:
      if (lookahead == 'l') ADVANCE(96);
      END_STATE();
    case 62:
      if (lookahead == 'm') ADVANCE(217);
      END_STATE();
    case 63:
      if (lookahead == 'm') ADVANCE(59);
      END_STATE();
    case 64:
      if (lookahead == 'm') ADVANCE(75);
      if (lookahead == 'p') ADVANCE(101);
      END_STATE();
    case 65:
      if (lookahead == 'n') ADVANCE(29);
      END_STATE();
    case 66:
      if (lookahead == 'n') ADVANCE(220);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(30);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(89);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(42);
      END_STATE();
    case 70:
      if (lookahead == 'o') ADVANCE(64);
      END_STATE();
    case 71:
      if (lookahead == 'o') ADVANCE(66);
      END_STATE();
    case 72:
      if (lookahead == 'o') ADVANCE(78);
      END_STATE();
    case 73:
      if (lookahead == 'o') ADVANCE(79);
      END_STATE();
    case 74:
      if (lookahead == 'o') ADVANCE(67);
      END_STATE();
    case 75:
      if (lookahead == 'p') ADVANCE(21);
      END_STATE();
    case 76:
      if (lookahead == 'p') ADVANCE(86);
      END_STATE();
    case 77:
      if (lookahead == 'r') ADVANCE(48);
      if (lookahead == 'u') ADVANCE(93);
      END_STATE();
    case 78:
      if (lookahead == 'r') ADVANCE(218);
      END_STATE();
    case 79:
      if (lookahead == 'r') ADVANCE(219);
      END_STATE();
    case 80:
      if (lookahead == 'r') ADVANCE(88);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 82:
      if (lookahead == 'r') ADVANCE(72);
      END_STATE();
    case 83:
      if (lookahead == 'r') ADVANCE(82);
      END_STATE();
    case 84:
      if (lookahead == 'r') ADVANCE(35);
      END_STATE();
    case 85:
      if (lookahead == 'r') ADVANCE(57);
      END_STATE();
    case 86:
      if (lookahead == 'r') ADVANCE(39);
      END_STATE();
    case 87:
      if (lookahead == 's') ADVANCE(115);
      END_STATE();
    case 88:
      if (lookahead == 's') ADVANCE(58);
      END_STATE();
    case 89:
      if (lookahead == 's') ADVANCE(38);
      END_STATE();
    case 90:
      if (lookahead == 't') ADVANCE(116);
      END_STATE();
    case 91:
      if (lookahead == 't') ADVANCE(119);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(117);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(52);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(223);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(224);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(53);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(44);
      END_STATE();
    case 98:
      if (lookahead == 'u') ADVANCE(61);
      END_STATE();
    case 99:
      if (lookahead == 'u') ADVANCE(84);
      END_STATE();
    case 100:
      if (lookahead == 'u') ADVANCE(49);
      END_STATE();
    case 101:
      if (lookahead == 'y') ADVANCE(85);
      END_STATE();
    case 102:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(102);
      if (lookahead != 0) ADVANCE(141);
      END_STATE();
    case 103:
      if (eof) ADVANCE(104);
      if (lookahead == '%') ADVANCE(107);
      if (lookahead == '(') ADVANCE(122);
      if (lookahead == '*') ADVANCE(149);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == '@') ADVANCE(18);
      if (lookahead == 'i') ADVANCE(87);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(103);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(144);
      if (lookahead == '!') ADVANCE(4);
      if (lookahead == '%') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(144);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!') ADVANCE(10);
      if (lookahead == '%') ADVANCE(10);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym_normal_single_line_comment_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(108);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(109);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(aux_sym_normal_single_line_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(109);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(110);
      if (lookahead == '@') ADVANCE(157);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(153);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(111);
      if (lookahead == '@') ADVANCE(18);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(112);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(113);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(155);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_is);
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
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(141);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(125);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(126);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(141);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(131);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(132);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(141);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(141);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_QMARK);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(141);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(141);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_AT);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(141);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(141);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_functor_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(141);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_pldoc_prolog_directive_token1);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token1);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token2);
      if (lookahead == '\n') ADVANCE(144);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR_STAR);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == '/') ADVANCE(151);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '/') ADVANCE(150);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      if (lookahead == '/') ADVANCE(156);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(110);
      if (lookahead == '*') ADVANCE(147);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '@') ADVANCE(157);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(153);
      if (lookahead != 0) ADVANCE(210);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(110);
      if (lookahead == '*') ADVANCE(147);
      if (lookahead == '@') ADVANCE(157);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(153);
      if (lookahead != 0) ADVANCE(210);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(113);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == '/') ADVANCE(16);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(155);
      if (lookahead != 0) ADVANCE(210);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(113);
      if (lookahead == '*') ADVANCE(156);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(155);
      if (lookahead != 0) ADVANCE(210);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      ADVANCE_MAP(
        '*', 156,
        'a', 195,
        'b', 208,
        'c', 187,
        'd', 169,
        'e', 198,
        'l', 180,
        'p', 160,
        's', 173,
        't', 162,
        'v', 174,
      );
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'a') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'a') ADVANCE(204);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'a') ADVANCE(199);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'a') ADVANCE(207);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'b') ADVANCE(165);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'c') ADVANCE(161);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'c') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'd') ADVANCE(227);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'd') ADVANCE(222);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'e') ADVANCE(221);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'e') ADVANCE(225);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'e') ADVANCE(192);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'e') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'e') ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'e') ADVANCE(166);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'e') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'e') ADVANCE(196);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'g') ADVANCE(214);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'g') ADVANCE(226);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'g') ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'h') ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'h') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'i') ADVANCE(164);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'i') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'i') ADVANCE(177);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'm') ADVANCE(217);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'm') ADVANCE(191);
      if (lookahead == 'p') ADVANCE(209);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'n') ADVANCE(220);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'n') ADVANCE(203);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'o') ADVANCE(184);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'o') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'o') ADVANCE(193);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'o') ADVANCE(194);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'p') ADVANCE(159);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'p') ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'r') ADVANCE(218);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'r') ADVANCE(219);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'r') ADVANCE(175);
      if (lookahead == 'u') ADVANCE(206);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'r') ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'r') ADVANCE(189);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'r') ADVANCE(197);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'r') ADVANCE(158);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'r') ADVANCE(182);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'r') ADVANCE(171);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 's') ADVANCE(181);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 's') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 't') ADVANCE(223);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 't') ADVANCE(224);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 't') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 't') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'u') ADVANCE(176);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead == 'y') ADVANCE(200);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(156);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(210);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(148);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '@') ADVANCE(157);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(212);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(210);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(148);
      if (lookahead == '@') ADVANCE(157);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(212);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(210);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(aux_sym_c_style_description_token2);
      if (lookahead == '\n') ADVANCE(213);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_ATarg);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(aux_sym_pl_tag_token1);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(aux_sym_pl_tag_token1);
      if (lookahead == '\n') ADVANCE(216);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(8);
      if (lookahead != 0) ADVANCE(9);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(anon_sym_ATparam);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(anon_sym_ATerror);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(anon_sym_ATauthor);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(anon_sym_ATversion);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(anon_sym_ATsee);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(anon_sym_ATdeprecated);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(anon_sym_ATcompat);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(anon_sym_ATcopyright);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(anon_sym_ATlicense);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(anon_sym_ATbug);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(anon_sym_ATtbd);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 103},
  [2] = {.lex_state = 152},
  [3] = {.lex_state = 103},
  [4] = {.lex_state = 103},
  [5] = {.lex_state = 152},
  [6] = {.lex_state = 103},
  [7] = {.lex_state = 211},
  [8] = {.lex_state = 103},
  [9] = {.lex_state = 211},
  [10] = {.lex_state = 152},
  [11] = {.lex_state = 211},
  [12] = {.lex_state = 6},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 103},
  [15] = {.lex_state = 103},
  [16] = {.lex_state = 103},
  [17] = {.lex_state = 103},
  [18] = {.lex_state = 103},
  [19] = {.lex_state = 103},
  [20] = {.lex_state = 12},
  [21] = {.lex_state = 12},
  [22] = {.lex_state = 12},
  [23] = {.lex_state = 12},
  [24] = {.lex_state = 12},
  [25] = {.lex_state = 12},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 13},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 103},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 103},
  [34] = {.lex_state = 103},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 103},
  [37] = {.lex_state = 103},
  [38] = {.lex_state = 103},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 103},
  [41] = {.lex_state = 7},
  [42] = {.lex_state = 103},
  [43] = {.lex_state = 103},
  [44] = {.lex_state = 103},
  [45] = {.lex_state = 103},
  [46] = {.lex_state = 103},
  [47] = {.lex_state = 103},
  [48] = {.lex_state = 103},
  [49] = {.lex_state = 103},
  [50] = {.lex_state = 103},
  [51] = {.lex_state = 103},
  [52] = {.lex_state = 1},
  [53] = {.lex_state = 102},
  [54] = {.lex_state = 103},
  [55] = {.lex_state = 103},
  [56] = {.lex_state = 13},
  [57] = {.lex_state = 154},
  [58] = {.lex_state = 103},
  [59] = {.lex_state = 102},
  [60] = {.lex_state = 103},
  [61] = {.lex_state = 154},
  [62] = {.lex_state = 103},
  [63] = {.lex_state = 103},
  [64] = {.lex_state = 1},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 13},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 154},
  [71] = {.lex_state = 1},
  [72] = {.lex_state = 154},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 102},
  [75] = {.lex_state = 102},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 13},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 1},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 154},
  [84] = {.lex_state = 1},
  [85] = {.lex_state = 1},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 102},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 1},
  [92] = {.lex_state = 1},
  [93] = {.lex_state = 102},
  [94] = {.lex_state = 8},
  [95] = {.lex_state = 8},
  [96] = {.lex_state = 102},
  [97] = {.lex_state = 1},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 1},
  [100] = {.lex_state = 108},
  [101] = {.lex_state = 1},
  [102] = {.lex_state = 8},
  [103] = {.lex_state = 8},
  [104] = {.lex_state = 1},
  [105] = {.lex_state = 213},
  [106] = {.lex_state = 1},
  [107] = {.lex_state = 1},
  [108] = {.lex_state = 213},
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
  [455] = 5,
    ACTIONS(90), 1,
      aux_sym_functor_token1,
    STATE(23), 1,
      aux_sym_head_repeat1,
    STATE(67), 1,
      sym_arg_name,
    STATE(73), 1,
      sym_arg_spec,
    ACTIONS(88), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [478] = 5,
    ACTIONS(90), 1,
      aux_sym_functor_token1,
    STATE(20), 1,
      aux_sym_head_repeat1,
    STATE(67), 1,
      sym_arg_name,
    STATE(78), 1,
      sym_arg_spec,
    ACTIONS(88), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [501] = 5,
    ACTIONS(90), 1,
      aux_sym_functor_token1,
    STATE(23), 1,
      aux_sym_head_repeat1,
    STATE(67), 1,
      sym_arg_name,
    STATE(87), 1,
      sym_arg_spec,
    ACTIONS(88), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [524] = 5,
    ACTIONS(95), 1,
      aux_sym_functor_token1,
    STATE(23), 1,
      aux_sym_head_repeat1,
    STATE(67), 1,
      sym_arg_name,
    STATE(89), 1,
      sym_arg_spec,
    ACTIONS(92), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [547] = 5,
    ACTIONS(90), 1,
      aux_sym_functor_token1,
    STATE(22), 1,
      aux_sym_head_repeat1,
    STATE(67), 1,
      sym_arg_name,
    STATE(86), 1,
      sym_arg_spec,
    ACTIONS(88), 8,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [570] = 1,
    ACTIONS(98), 9,
      anon_sym_PLUS_PLUS,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
      aux_sym_functor_token1,
  [582] = 6,
    ACTIONS(102), 1,
      anon_sym_PERCENT,
    ACTIONS(104), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(106), 1,
      aux_sym_prolog_style_description_token2,
    STATE(30), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(62), 1,
      sym_prolog_style_description,
    ACTIONS(100), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [603] = 7,
    ACTIONS(108), 1,
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
    ACTIONS(106), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [626] = 6,
    ACTIONS(104), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(106), 1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(112), 1,
      anon_sym_PERCENT,
    STATE(30), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(63), 1,
      sym_prolog_style_description,
    ACTIONS(110), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [647] = 5,
    ACTIONS(116), 1,
      anon_sym_PERCENT,
    ACTIONS(119), 1,
      aux_sym_pldoc_prolog_directive_token1,
    STATE(27), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(114), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(34), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [665] = 5,
    ACTIONS(124), 1,
      anon_sym_PERCENT,
    ACTIONS(126), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(128), 1,
      aux_sym_prolog_style_description_token2,
    STATE(31), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(122), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [683] = 5,
    ACTIONS(132), 1,
      anon_sym_PERCENT,
    ACTIONS(134), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(137), 1,
      aux_sym_prolog_style_description_token2,
    STATE(31), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(130), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [701] = 1,
    ACTIONS(140), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [710] = 2,
    ACTIONS(144), 1,
      anon_sym_PERCENT,
    ACTIONS(142), 5,
      ts_builtin_sym_end,
      anon_sym_is,
      anon_sym_LPAREN,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [721] = 4,
    ACTIONS(148), 1,
      anon_sym_PERCENT,
    ACTIONS(150), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(146), 2,
      ts_builtin_sym_end,
      anon_sym_SLASH_STAR_STAR,
    STATE(34), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [736] = 1,
    ACTIONS(153), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [745] = 3,
    ACTIONS(157), 1,
      anon_sym_PERCENT,
    ACTIONS(159), 1,
      anon_sym_LPAREN,
    ACTIONS(155), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [758] = 3,
    ACTIONS(163), 1,
      anon_sym_PERCENT,
    STATE(37), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(161), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [770] = 3,
    ACTIONS(168), 1,
      anon_sym_PERCENT,
    ACTIONS(170), 1,
      anon_sym_is,
    ACTIONS(166), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [782] = 5,
    ACTIONS(172), 1,
      anon_sym_LF,
    ACTIONS(174), 1,
      anon_sym_STAR,
    ACTIONS(176), 1,
      anon_sym_STAR_SLASH,
    STATE(2), 1,
      aux_sym_pldoc_c_style_repeat2,
    STATE(52), 1,
      aux_sym_pldoc_c_style_repeat1,
  [798] = 2,
    ACTIONS(180), 1,
      anon_sym_PERCENT,
    ACTIONS(178), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [808] = 5,
    ACTIONS(182), 1,
      anon_sym_LF,
    ACTIONS(184), 1,
      aux_sym_functor_token1,
    STATE(64), 1,
      sym_functor,
    STATE(81), 1,
      sym_head,
    STATE(99), 1,
      sym_template,
  [824] = 3,
    ACTIONS(188), 1,
      anon_sym_PERCENT,
    STATE(45), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(186), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [836] = 2,
    ACTIONS(193), 1,
      anon_sym_PERCENT,
    ACTIONS(191), 4,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [846] = 3,
    ACTIONS(188), 1,
      anon_sym_PERCENT,
    STATE(37), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(186), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [858] = 3,
    ACTIONS(197), 1,
      anon_sym_PERCENT,
    STATE(37), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(195), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [870] = 2,
    ACTIONS(202), 1,
      anon_sym_PERCENT,
    ACTIONS(200), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [879] = 2,
    ACTIONS(206), 1,
      anon_sym_PERCENT,
    ACTIONS(204), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [888] = 2,
    ACTIONS(210), 1,
      anon_sym_PERCENT,
    ACTIONS(208), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [897] = 2,
    ACTIONS(214), 1,
      anon_sym_PERCENT,
    ACTIONS(212), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [906] = 2,
    ACTIONS(216), 1,
      anon_sym_PERCENT,
    ACTIONS(161), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [915] = 2,
    ACTIONS(220), 1,
      anon_sym_PERCENT,
    ACTIONS(218), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [924] = 4,
    ACTIONS(222), 1,
      anon_sym_LF,
    ACTIONS(224), 1,
      anon_sym_STAR,
    ACTIONS(227), 1,
      anon_sym_STAR_SLASH,
    STATE(52), 1,
      aux_sym_pldoc_c_style_repeat1,
  [937] = 4,
    ACTIONS(229), 1,
      aux_sym_functor_token1,
    STATE(64), 1,
      sym_functor,
    STATE(81), 1,
      sym_head,
    STATE(99), 1,
      sym_template,
  [950] = 2,
    ACTIONS(233), 1,
      anon_sym_PERCENT,
    ACTIONS(231), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [959] = 2,
    ACTIONS(237), 1,
      anon_sym_PERCENT,
    ACTIONS(235), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [968] = 3,
    ACTIONS(239), 1,
      anon_sym_PERCENT,
    STATE(56), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(242), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [979] = 4,
    ACTIONS(244), 1,
      anon_sym_LF,
    ACTIONS(246), 1,
      aux_sym_c_style_description_token1,
    STATE(70), 1,
      aux_sym_c_style_description_repeat1,
    STATE(106), 1,
      sym_c_style_description,
  [992] = 2,
    ACTIONS(250), 1,
      anon_sym_PERCENT,
    ACTIONS(248), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1001] = 4,
    ACTIONS(252), 1,
      aux_sym_functor_token1,
    STATE(36), 1,
      sym_functor,
    STATE(38), 1,
      sym_head,
    STATE(48), 1,
      sym_template,
  [1014] = 2,
    ACTIONS(256), 1,
      anon_sym_PERCENT,
    ACTIONS(254), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1023] = 4,
    ACTIONS(246), 1,
      aux_sym_c_style_description_token1,
    ACTIONS(258), 1,
      anon_sym_LF,
    STATE(70), 1,
      aux_sym_c_style_description_repeat1,
    STATE(92), 1,
      sym_c_style_description,
  [1036] = 2,
    ACTIONS(112), 1,
      anon_sym_PERCENT,
    ACTIONS(110), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1045] = 2,
    ACTIONS(262), 1,
      anon_sym_PERCENT,
    ACTIONS(260), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [1054] = 3,
    ACTIONS(155), 1,
      anon_sym_LF,
    ACTIONS(157), 1,
      anon_sym_is,
    ACTIONS(264), 1,
      anon_sym_LPAREN,
  [1064] = 1,
    ACTIONS(266), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
  [1070] = 2,
    ACTIONS(268), 1,
      anon_sym_PERCENT,
    ACTIONS(242), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [1078] = 2,
    ACTIONS(272), 1,
      anon_sym_COLON,
    ACTIONS(270), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1086] = 2,
    ACTIONS(276), 1,
      anon_sym_COLON,
    ACTIONS(274), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1094] = 2,
    ACTIONS(278), 1,
      anon_sym_LF,
    ACTIONS(280), 2,
      anon_sym_STAR,
      anon_sym_STAR_SLASH,
  [1102] = 3,
    ACTIONS(39), 1,
      anon_sym_LF,
    ACTIONS(246), 1,
      aux_sym_c_style_description_token1,
    STATE(72), 1,
      aux_sym_c_style_description_repeat1,
  [1112] = 2,
    ACTIONS(142), 1,
      anon_sym_LF,
    ACTIONS(144), 2,
      anon_sym_is,
      anon_sym_LPAREN,
  [1120] = 3,
    ACTIONS(52), 1,
      anon_sym_LF,
    ACTIONS(282), 1,
      aux_sym_c_style_description_token1,
    STATE(72), 1,
      aux_sym_c_style_description_repeat1,
  [1130] = 2,
    ACTIONS(285), 1,
      anon_sym_COMMA,
    ACTIONS(287), 1,
      anon_sym_RPAREN,
  [1137] = 2,
    ACTIONS(289), 1,
      aux_sym_functor_token1,
    STATE(68), 1,
      sym_arg_name,
  [1144] = 2,
    ACTIONS(291), 1,
      aux_sym_functor_token1,
    STATE(80), 1,
      sym_type,
  [1151] = 1,
    ACTIONS(293), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1156] = 1,
    ACTIONS(295), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1161] = 2,
    ACTIONS(285), 1,
      anon_sym_COMMA,
    ACTIONS(297), 1,
      anon_sym_RPAREN,
  [1168] = 2,
    ACTIONS(299), 1,
      anon_sym_STAR,
    STATE(39), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1175] = 1,
    ACTIONS(301), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1180] = 2,
    ACTIONS(166), 1,
      anon_sym_LF,
    ACTIONS(303), 1,
      anon_sym_is,
  [1187] = 2,
    ACTIONS(178), 1,
      anon_sym_LF,
    ACTIONS(180), 1,
      anon_sym_is,
  [1194] = 1,
    ACTIONS(52), 2,
      anon_sym_LF,
      aux_sym_c_style_description_token1,
  [1199] = 2,
    ACTIONS(191), 1,
      anon_sym_LF,
    ACTIONS(193), 1,
      anon_sym_is,
  [1206] = 2,
    ACTIONS(305), 1,
      anon_sym_LF,
    ACTIONS(307), 1,
      anon_sym_NULL,
  [1213] = 2,
    ACTIONS(285), 1,
      anon_sym_COMMA,
    ACTIONS(309), 1,
      anon_sym_RPAREN,
  [1220] = 2,
    ACTIONS(285), 1,
      anon_sym_COMMA,
    ACTIONS(311), 1,
      anon_sym_RPAREN,
  [1227] = 2,
    ACTIONS(291), 1,
      aux_sym_functor_token1,
    STATE(77), 1,
      sym_type,
  [1234] = 1,
    ACTIONS(285), 1,
      anon_sym_COMMA,
  [1238] = 1,
    ACTIONS(313), 1,
      ts_builtin_sym_end,
  [1242] = 1,
    ACTIONS(315), 1,
      anon_sym_LF,
  [1246] = 1,
    ACTIONS(317), 1,
      anon_sym_LF,
  [1250] = 1,
    ACTIONS(319), 1,
      aux_sym_functor_token1,
  [1254] = 1,
    ACTIONS(321), 1,
      aux_sym_pl_tag_token1,
  [1258] = 1,
    ACTIONS(323), 1,
      aux_sym_pl_tag_token1,
  [1262] = 1,
    ACTIONS(325), 1,
      aux_sym_functor_token1,
  [1266] = 1,
    ACTIONS(254), 1,
      anon_sym_LF,
  [1270] = 1,
    ACTIONS(327), 1,
      anon_sym_STAR_SLASH,
  [1274] = 1,
    ACTIONS(329), 1,
      anon_sym_LF,
  [1278] = 1,
    ACTIONS(331), 1,
      aux_sym_normal_single_line_comment_token1,
  [1282] = 1,
    ACTIONS(333), 1,
      anon_sym_LF,
  [1286] = 1,
    ACTIONS(335), 1,
      aux_sym_pl_tag_token1,
  [1290] = 1,
    ACTIONS(337), 1,
      aux_sym_pl_tag_token1,
  [1294] = 1,
    ACTIONS(182), 1,
      anon_sym_LF,
  [1298] = 1,
    ACTIONS(339), 1,
      aux_sym_c_style_description_token2,
  [1302] = 1,
    ACTIONS(341), 1,
      anon_sym_LF,
  [1306] = 1,
    ACTIONS(343), 1,
      anon_sym_LF,
  [1310] = 1,
    ACTIONS(345), 1,
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
  [SMALL_STATE(21)] = 478,
  [SMALL_STATE(22)] = 501,
  [SMALL_STATE(23)] = 524,
  [SMALL_STATE(24)] = 547,
  [SMALL_STATE(25)] = 570,
  [SMALL_STATE(26)] = 582,
  [SMALL_STATE(27)] = 603,
  [SMALL_STATE(28)] = 626,
  [SMALL_STATE(29)] = 647,
  [SMALL_STATE(30)] = 665,
  [SMALL_STATE(31)] = 683,
  [SMALL_STATE(32)] = 701,
  [SMALL_STATE(33)] = 710,
  [SMALL_STATE(34)] = 721,
  [SMALL_STATE(35)] = 736,
  [SMALL_STATE(36)] = 745,
  [SMALL_STATE(37)] = 758,
  [SMALL_STATE(38)] = 770,
  [SMALL_STATE(39)] = 782,
  [SMALL_STATE(40)] = 798,
  [SMALL_STATE(41)] = 808,
  [SMALL_STATE(42)] = 824,
  [SMALL_STATE(43)] = 836,
  [SMALL_STATE(44)] = 846,
  [SMALL_STATE(45)] = 858,
  [SMALL_STATE(46)] = 870,
  [SMALL_STATE(47)] = 879,
  [SMALL_STATE(48)] = 888,
  [SMALL_STATE(49)] = 897,
  [SMALL_STATE(50)] = 906,
  [SMALL_STATE(51)] = 915,
  [SMALL_STATE(52)] = 924,
  [SMALL_STATE(53)] = 937,
  [SMALL_STATE(54)] = 950,
  [SMALL_STATE(55)] = 959,
  [SMALL_STATE(56)] = 968,
  [SMALL_STATE(57)] = 979,
  [SMALL_STATE(58)] = 992,
  [SMALL_STATE(59)] = 1001,
  [SMALL_STATE(60)] = 1014,
  [SMALL_STATE(61)] = 1023,
  [SMALL_STATE(62)] = 1036,
  [SMALL_STATE(63)] = 1045,
  [SMALL_STATE(64)] = 1054,
  [SMALL_STATE(65)] = 1064,
  [SMALL_STATE(66)] = 1070,
  [SMALL_STATE(67)] = 1078,
  [SMALL_STATE(68)] = 1086,
  [SMALL_STATE(69)] = 1094,
  [SMALL_STATE(70)] = 1102,
  [SMALL_STATE(71)] = 1112,
  [SMALL_STATE(72)] = 1120,
  [SMALL_STATE(73)] = 1130,
  [SMALL_STATE(74)] = 1137,
  [SMALL_STATE(75)] = 1144,
  [SMALL_STATE(76)] = 1151,
  [SMALL_STATE(77)] = 1156,
  [SMALL_STATE(78)] = 1161,
  [SMALL_STATE(79)] = 1168,
  [SMALL_STATE(80)] = 1175,
  [SMALL_STATE(81)] = 1180,
  [SMALL_STATE(82)] = 1187,
  [SMALL_STATE(83)] = 1194,
  [SMALL_STATE(84)] = 1199,
  [SMALL_STATE(85)] = 1206,
  [SMALL_STATE(86)] = 1213,
  [SMALL_STATE(87)] = 1220,
  [SMALL_STATE(88)] = 1227,
  [SMALL_STATE(89)] = 1234,
  [SMALL_STATE(90)] = 1238,
  [SMALL_STATE(91)] = 1242,
  [SMALL_STATE(92)] = 1246,
  [SMALL_STATE(93)] = 1250,
  [SMALL_STATE(94)] = 1254,
  [SMALL_STATE(95)] = 1258,
  [SMALL_STATE(96)] = 1262,
  [SMALL_STATE(97)] = 1266,
  [SMALL_STATE(98)] = 1270,
  [SMALL_STATE(99)] = 1274,
  [SMALL_STATE(100)] = 1278,
  [SMALL_STATE(101)] = 1282,
  [SMALL_STATE(102)] = 1286,
  [SMALL_STATE(103)] = 1290,
  [SMALL_STATE(104)] = 1294,
  [SMALL_STATE(105)] = 1298,
  [SMALL_STATE(106)] = 1302,
  [SMALL_STATE(107)] = 1306,
  [SMALL_STATE(108)] = 1310,
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
  [88] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [90] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [92] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(74),
  [95] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(65),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 2, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 2, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [108] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 3, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 3, 0, 0),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0),
  [116] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(101),
  [119] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(59),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [134] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [137] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor, 1, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor, 1, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [150] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [153] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 1, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 1, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [163] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_template, 1, 0, 0),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [174] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [176] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 4, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 4, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [184] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 1, 0, 0),
  [188] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 1, 0, 0), SHIFT(19),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 5, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 5, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 2, 0, 0),
  [197] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 2, 0, 0), SHIFT(19),
  [200] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 1, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [224] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [233] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [237] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [239] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0), SHIFT_REPEAT(101),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [244] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 2, 0, 0),
  [246] = {.entry = {.count = 1, .reusable = false}}, SHIFT(105),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 5, 0, 0),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [254] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 3, 0, 0),
  [256] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_template, 3, 0, 0),
  [258] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 3, 0, 0),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 4, 0, 0),
  [262] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 4, 0, 0),
  [264] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [266] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_name, 1, 0, 0),
  [268] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [270] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 1, 0, 0),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [274] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 2, 0, 0),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [278] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [280] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [282] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(105),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [295] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 3, 0, 0),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [301] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 4, 0, 0),
  [303] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [307] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [313] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [317] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 4, 0, 0),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [323] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [327] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [329] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [331] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [333] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [341] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 3, 0, 0),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
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
