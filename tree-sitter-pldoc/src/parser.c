#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 104
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 74
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
  aux_sym_c_style_body_repeat1 = 72,
  aux_sym_c_style_description_repeat1 = 73,
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
  [22] = 22,
  [23] = 21,
  [24] = 20,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 33,
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
  [63] = 54,
  [64] = 4,
  [65] = 50,
  [66] = 8,
  [67] = 61,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 68,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 11,
  [81] = 60,
  [82] = 62,
  [83] = 83,
  [84] = 79,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 73,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 99,
  [102] = 102,
  [103] = 103,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(102);
      ADVANCE_MAP(
        0, 110,
        '!', 128,
        '%', 103,
        '(', 118,
        ')', 120,
        '*', 135,
        '+', 122,
        ',', 119,
        '-', 123,
        '/', 14,
        ':', 126,
        '?', 125,
        '@', 127,
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
      if ((!eof && lookahead == 00)) ADVANCE(110);
      if (lookahead == '\n') ADVANCE(109);
      if (lookahead == '(') ADVANCE(118);
      if (lookahead == 'i') ADVANCE(86);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(131);
      if (lookahead == ' ') ADVANCE(130);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(131);
      if (lookahead != 0) ADVANCE(5);
      END_STATE();
    case 6:
      if (lookahead == '\n') ADVANCE(107);
      if (lookahead == '@') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(200);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(199);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 9:
      if (lookahead == ' ') ADVANCE(130);
      END_STATE();
    case 10:
      if (lookahead == ' ') ADVANCE(133);
      END_STATE();
    case 11:
      if (lookahead == '!') ADVANCE(128);
      if (lookahead == '+') ADVANCE(122);
      if (lookahead == '-') ADVANCE(123);
      if (lookahead == ':') ADVANCE(126);
      if (lookahead == '?') ADVANCE(125);
      if (lookahead == '@') ADVANCE(127);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(129);
      END_STATE();
    case 12:
      if (lookahead == '%') ADVANCE(104);
      if (lookahead == '(') ADVANCE(118);
      if (lookahead == 'i') ADVANCE(86);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(12);
      END_STATE();
    case 13:
      if (lookahead == '*') ADVANCE(10);
      END_STATE();
    case 14:
      if (lookahead == '*') ADVANCE(13);
      END_STATE();
    case 15:
      if (lookahead == '/') ADVANCE(142);
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
      if (lookahead == 'd') ADVANCE(117);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(211);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(206);
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
      if (lookahead == 'e') ADVANCE(114);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(75);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(205);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(209);
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
      if (lookahead == 'g') ADVANCE(198);
      END_STATE();
    case 48:
      if (lookahead == 'g') ADVANCE(210);
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
      if (lookahead == 'i') ADVANCE(116);
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
      if (lookahead == 'm') ADVANCE(201);
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
      if (lookahead == 'n') ADVANCE(204);
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
      if (lookahead == 'r') ADVANCE(202);
      END_STATE();
    case 78:
      if (lookahead == 'r') ADVANCE(203);
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
      if (lookahead == 's') ADVANCE(111);
      END_STATE();
    case 87:
      if (lookahead == 's') ADVANCE(57);
      END_STATE();
    case 88:
      if (lookahead == 's') ADVANCE(37);
      END_STATE();
    case 89:
      if (lookahead == 't') ADVANCE(112);
      END_STATE();
    case 90:
      if (lookahead == 't') ADVANCE(115);
      END_STATE();
    case 91:
      if (lookahead == 't') ADVANCE(113);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(51);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(207);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(208);
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
      if (lookahead == '%') ADVANCE(104);
      if (lookahead == '*') ADVANCE(135);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == '@') ADVANCE(17);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(101);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(129);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(132);
      if (lookahead == '!') ADVANCE(4);
      if (lookahead == '%') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!') ADVANCE(9);
      if (lookahead == '%') ADVANCE(9);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(aux_sym_normal_single_line_comment_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(105);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(106);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(aux_sym_normal_single_line_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(106);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(107);
      if (lookahead == '@') ADVANCE(17);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(108);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(139);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(109);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_is);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_det);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_semidet);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_failure);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_nondet);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_multi);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_undefined);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(121);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(124);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(anon_sym_QMARK);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(aux_sym_functor_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(129);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_pldoc_prolog_directive_token1);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token1);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token2);
      if (lookahead == '\n') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(3);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_SLASH_STAR_STAR);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == '/') ADVANCE(137);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '/') ADVANCE(136);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      if (lookahead == '/') ADVANCE(142);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(108);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == '/') ADVANCE(15);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(139);
      if (lookahead != 0) ADVANCE(196);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '\n') ADVANCE(108);
      if (lookahead == '*') ADVANCE(142);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(139);
      if (lookahead != 0) ADVANCE(196);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(134);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == '@') ADVANCE(143);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(141);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(196);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(134);
      if (lookahead == '@') ADVANCE(143);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(141);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(196);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      ADVANCE_MAP(
        '*', 142,
        'a', 181,
        'b', 194,
        'c', 173,
        'd', 155,
        'e', 184,
        'l', 166,
        'p', 146,
        's', 159,
        't', 148,
        'v', 160,
      );
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'a') ADVANCE(169);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'a') ADVANCE(190);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'a') ADVANCE(185);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'a') ADVANCE(193);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'b') ADVANCE(151);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'c') ADVANCE(147);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'c') ADVANCE(156);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'd') ADVANCE(211);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'd') ADVANCE(206);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'e') ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'e') ADVANCE(209);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'e') ADVANCE(178);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'e') ADVANCE(172);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'e') ADVANCE(149);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'e') ADVANCE(152);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'e') ADVANCE(153);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'e') ADVANCE(182);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'g') ADVANCE(198);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'g') ADVANCE(210);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'g') ADVANCE(164);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'h') ADVANCE(191);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'h') ADVANCE(176);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'i') ADVANCE(150);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'i') ADVANCE(174);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'i') ADVANCE(163);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'm') ADVANCE(201);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'm') ADVANCE(177);
      if (lookahead == 'p') ADVANCE(195);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'n') ADVANCE(204);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'n') ADVANCE(189);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'o') ADVANCE(170);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'o') ADVANCE(171);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'o') ADVANCE(179);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'o') ADVANCE(180);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'p') ADVANCE(145);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'p') ADVANCE(187);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'r') ADVANCE(202);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'r') ADVANCE(203);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'r') ADVANCE(161);
      if (lookahead == 'u') ADVANCE(192);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'r') ADVANCE(188);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'r') ADVANCE(175);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'r') ADVANCE(183);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'r') ADVANCE(144);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'r') ADVANCE(168);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'r') ADVANCE(157);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 's') ADVANCE(167);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 's') ADVANCE(154);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 't') ADVANCE(207);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 't') ADVANCE(208);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 't') ADVANCE(165);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 't') ADVANCE(158);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'u') ADVANCE(162);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'y') ADVANCE(186);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(aux_sym_c_style_description_token2);
      if (lookahead == '\n') ADVANCE(197);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(anon_sym_ATarg);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(aux_sym_pl_tag_token1);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(aux_sym_pl_tag_token1);
      if (lookahead == '\n') ADVANCE(200);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(anon_sym_ATparam);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_ATerror);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_ATauthor);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_ATversion);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(anon_sym_ATsee);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_ATdeprecated);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_ATcompat);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_ATcopyright);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_ATlicense);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_ATbug);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(anon_sym_ATtbd);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 101},
  [2] = {.lex_state = 140},
  [3] = {.lex_state = 101},
  [4] = {.lex_state = 140},
  [5] = {.lex_state = 101},
  [6] = {.lex_state = 101},
  [7] = {.lex_state = 140},
  [8] = {.lex_state = 140},
  [9] = {.lex_state = 101},
  [10] = {.lex_state = 101},
  [11] = {.lex_state = 140},
  [12] = {.lex_state = 140},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 101},
  [15] = {.lex_state = 101},
  [16] = {.lex_state = 101},
  [17] = {.lex_state = 101},
  [18] = {.lex_state = 101},
  [19] = {.lex_state = 101},
  [20] = {.lex_state = 11},
  [21] = {.lex_state = 11},
  [22] = {.lex_state = 11},
  [23] = {.lex_state = 11},
  [24] = {.lex_state = 11},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 11},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 101},
  [36] = {.lex_state = 101},
  [37] = {.lex_state = 101},
  [38] = {.lex_state = 101},
  [39] = {.lex_state = 101},
  [40] = {.lex_state = 101},
  [41] = {.lex_state = 101},
  [42] = {.lex_state = 101},
  [43] = {.lex_state = 101},
  [44] = {.lex_state = 101},
  [45] = {.lex_state = 101},
  [46] = {.lex_state = 101},
  [47] = {.lex_state = 138},
  [48] = {.lex_state = 101},
  [49] = {.lex_state = 101},
  [50] = {.lex_state = 12},
  [51] = {.lex_state = 138},
  [52] = {.lex_state = 101},
  [53] = {.lex_state = 101},
  [54] = {.lex_state = 12},
  [55] = {.lex_state = 101},
  [56] = {.lex_state = 101},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 12},
  [61] = {.lex_state = 12},
  [62] = {.lex_state = 12},
  [63] = {.lex_state = 1},
  [64] = {.lex_state = 138},
  [65] = {.lex_state = 1},
  [66] = {.lex_state = 138},
  [67] = {.lex_state = 1},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 101},
  [70] = {.lex_state = 101},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 101},
  [73] = {.lex_state = 101},
  [74] = {.lex_state = 101},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 138},
  [81] = {.lex_state = 1},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 1},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 1},
  [86] = {.lex_state = 1},
  [87] = {.lex_state = 105},
  [88] = {.lex_state = 101},
  [89] = {.lex_state = 7},
  [90] = {.lex_state = 1},
  [91] = {.lex_state = 101},
  [92] = {.lex_state = 7},
  [93] = {.lex_state = 1},
  [94] = {.lex_state = 7},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 1},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 1},
  [99] = {.lex_state = 197},
  [100] = {.lex_state = 1},
  [101] = {.lex_state = 197},
  [102] = {.lex_state = 7},
  [103] = {.lex_state = 0},
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
    [sym_source_file] = STATE(103),
    [sym_comment] = STATE(16),
    [sym_normal_comment] = STATE(55),
    [sym_normal_single_line_comment] = STATE(40),
    [sym_pldoc_comment] = STATE(55),
    [sym_pldoc_prolog_directive] = STATE(37),
    [sym_pldoc_prolog_style] = STATE(46),
    [sym_pldoc_c_style] = STATE(46),
    [aux_sym_source_file_repeat1] = STATE(16),
    [aux_sym_pldoc_prolog_style_repeat1] = STATE(37),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_PERCENT] = ACTIONS(5),
    [aux_sym_pldoc_prolog_directive_token1] = ACTIONS(7),
    [anon_sym_SLASH_STAR_STAR] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(11), 1,
      anon_sym_STAR,
    ACTIONS(13), 1,
      anon_sym_STAR_SLASH,
    ACTIONS(15), 1,
      aux_sym_c_style_description_token1,
    STATE(4), 1,
      aux_sym_c_style_description_repeat1,
    STATE(5), 1,
      aux_sym_c_style_body_repeat1,
    STATE(6), 1,
      sym_c_style_description,
    STATE(7), 1,
      aux_sym_pldoc_c_style_repeat1,
    STATE(86), 1,
      sym_c_tag,
    STATE(95), 1,
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
  [44] = 7,
    ACTIONS(21), 1,
      aux_sym_functor_token1,
    STATE(63), 1,
      sym_functor,
    STATE(67), 1,
      sym_head,
    STATE(96), 1,
      sym_template,
    STATE(100), 1,
      sym_c_tag,
    ACTIONS(23), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(25), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [76] = 3,
    ACTIONS(15), 1,
      aux_sym_c_style_description_token1,
    STATE(8), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(27), 14,
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
  [99] = 6,
    ACTIONS(29), 1,
      anon_sym_STAR,
    ACTIONS(31), 1,
      anon_sym_STAR_SLASH,
    STATE(10), 1,
      aux_sym_c_style_body_repeat1,
    STATE(86), 1,
      sym_c_tag,
    ACTIONS(23), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(25), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [128] = 6,
    ACTIONS(29), 1,
      anon_sym_STAR,
    ACTIONS(31), 1,
      anon_sym_STAR_SLASH,
    STATE(9), 1,
      aux_sym_c_style_body_repeat1,
    STATE(86), 1,
      sym_c_tag,
    ACTIONS(23), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(25), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [157] = 3,
    ACTIONS(33), 1,
      anon_sym_STAR,
    STATE(7), 1,
      aux_sym_pldoc_c_style_repeat1,
    ACTIONS(36), 14,
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
  [180] = 3,
    ACTIONS(40), 1,
      aux_sym_c_style_description_token1,
    STATE(8), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(38), 14,
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
  [203] = 6,
    ACTIONS(29), 1,
      anon_sym_STAR,
    ACTIONS(43), 1,
      anon_sym_STAR_SLASH,
    STATE(10), 1,
      aux_sym_c_style_body_repeat1,
    STATE(86), 1,
      sym_c_tag,
    ACTIONS(23), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(25), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [232] = 6,
    ACTIONS(45), 1,
      anon_sym_STAR,
    ACTIONS(48), 1,
      anon_sym_STAR_SLASH,
    STATE(10), 1,
      aux_sym_c_style_body_repeat1,
    STATE(86), 1,
      sym_c_tag,
    ACTIONS(50), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(53), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [261] = 1,
    ACTIONS(38), 15,
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
  [279] = 1,
    ACTIONS(56), 15,
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
  [297] = 4,
    ACTIONS(58), 1,
      anon_sym_LF,
    STATE(49), 1,
      sym_pl_tag,
    ACTIONS(60), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(62), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [320] = 2,
    ACTIONS(64), 1,
      anon_sym_STAR,
    ACTIONS(48), 13,
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
  [339] = 2,
    ACTIONS(66), 1,
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
  [358] = 9,
    ACTIONS(5), 1,
      anon_sym_PERCENT,
    ACTIONS(7), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(9), 1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(70), 1,
      ts_builtin_sym_end,
    STATE(40), 1,
      sym_normal_single_line_comment,
    STATE(17), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(37), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(46), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
    STATE(55), 2,
      sym_normal_comment,
      sym_pldoc_comment,
  [390] = 9,
    ACTIONS(72), 1,
      ts_builtin_sym_end,
    ACTIONS(74), 1,
      anon_sym_PERCENT,
    ACTIONS(77), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(80), 1,
      anon_sym_SLASH_STAR_STAR,
    STATE(40), 1,
      sym_normal_single_line_comment,
    STATE(17), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(37), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(46), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
    STATE(55), 2,
      sym_normal_comment,
      sym_pldoc_comment,
  [422] = 3,
    STATE(100), 1,
      sym_c_tag,
    ACTIONS(23), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(25), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [442] = 3,
    STATE(49), 1,
      sym_pl_tag,
    ACTIONS(83), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(85), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [462] = 6,
    ACTIONS(91), 1,
      aux_sym_functor_token1,
    STATE(22), 1,
      aux_sym_head_repeat1,
    STATE(57), 1,
      sym_arg_name,
    STATE(71), 1,
      sym_arg_spec,
    ACTIONS(89), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(87), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [487] = 6,
    ACTIONS(91), 1,
      aux_sym_functor_token1,
    STATE(20), 1,
      aux_sym_head_repeat1,
    STATE(57), 1,
      sym_arg_name,
    STATE(79), 1,
      sym_arg_spec,
    ACTIONS(89), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(87), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [512] = 6,
    ACTIONS(99), 1,
      aux_sym_functor_token1,
    STATE(22), 1,
      aux_sym_head_repeat1,
    STATE(57), 1,
      sym_arg_name,
    STATE(97), 1,
      sym_arg_spec,
    ACTIONS(96), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(93), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [537] = 6,
    ACTIONS(91), 1,
      aux_sym_functor_token1,
    STATE(24), 1,
      aux_sym_head_repeat1,
    STATE(57), 1,
      sym_arg_name,
    STATE(84), 1,
      sym_arg_spec,
    ACTIONS(89), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(87), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [562] = 6,
    ACTIONS(91), 1,
      aux_sym_functor_token1,
    STATE(22), 1,
      aux_sym_head_repeat1,
    STATE(57), 1,
      sym_arg_name,
    STATE(68), 1,
      sym_arg_spec,
    ACTIONS(89), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(87), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [587] = 9,
    ACTIONS(104), 1,
      anon_sym_PERCENT,
    ACTIONS(107), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(109), 1,
      aux_sym_prolog_style_description_token2,
    STATE(29), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    STATE(30), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(35), 1,
      sym_prolog_style_description,
    STATE(36), 1,
      aux_sym_prolog_style_body_repeat1,
    STATE(41), 1,
      sym_prolog_style_body,
    ACTIONS(102), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [617] = 2,
    ACTIONS(113), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(111), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
      aux_sym_functor_token1,
  [631] = 6,
    ACTIONS(107), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(109), 1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(117), 1,
      anon_sym_PERCENT,
    STATE(30), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(53), 1,
      sym_prolog_style_description,
    ACTIONS(115), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [652] = 6,
    ACTIONS(107), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(109), 1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(121), 1,
      anon_sym_PERCENT,
    STATE(30), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(52), 1,
      sym_prolog_style_description,
    ACTIONS(119), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [673] = 4,
    ACTIONS(125), 1,
      anon_sym_PERCENT,
    ACTIONS(128), 1,
      aux_sym_prolog_style_description_token1,
    STATE(29), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(123), 4,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      aux_sym_prolog_style_description_token2,
      anon_sym_SLASH_STAR_STAR,
  [689] = 5,
    ACTIONS(132), 1,
      anon_sym_PERCENT,
    ACTIONS(134), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(136), 1,
      aux_sym_prolog_style_description_token2,
    STATE(31), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(130), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [707] = 5,
    ACTIONS(140), 1,
      anon_sym_PERCENT,
    ACTIONS(142), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(145), 1,
      aux_sym_prolog_style_description_token2,
    STATE(31), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(138), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [725] = 2,
    ACTIONS(128), 2,
      anon_sym_PERCENT,
      aux_sym_prolog_style_description_token1,
    ACTIONS(123), 4,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      aux_sym_prolog_style_description_token2,
      anon_sym_SLASH_STAR_STAR,
  [736] = 1,
    ACTIONS(148), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [745] = 1,
    ACTIONS(150), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [754] = 3,
    ACTIONS(154), 1,
      anon_sym_PERCENT,
    STATE(38), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(152), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [766] = 3,
    ACTIONS(154), 1,
      anon_sym_PERCENT,
    STATE(39), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(152), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [778] = 4,
    ACTIONS(7), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(157), 1,
      anon_sym_PERCENT,
    STATE(25), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    STATE(42), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [792] = 3,
    ACTIONS(161), 1,
      anon_sym_PERCENT,
    STATE(39), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(159), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [804] = 3,
    ACTIONS(166), 1,
      anon_sym_PERCENT,
    STATE(39), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(164), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [816] = 2,
    ACTIONS(171), 1,
      anon_sym_PERCENT,
    ACTIONS(169), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [825] = 2,
    ACTIONS(175), 1,
      anon_sym_PERCENT,
    ACTIONS(173), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [834] = 3,
    ACTIONS(177), 1,
      anon_sym_PERCENT,
    ACTIONS(179), 1,
      aux_sym_pldoc_prolog_directive_token1,
    STATE(42), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [845] = 2,
    ACTIONS(184), 1,
      anon_sym_PERCENT,
    ACTIONS(182), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [854] = 2,
    ACTIONS(188), 1,
      anon_sym_PERCENT,
    ACTIONS(186), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [863] = 2,
    ACTIONS(192), 1,
      anon_sym_PERCENT,
    ACTIONS(190), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [872] = 2,
    ACTIONS(196), 1,
      anon_sym_PERCENT,
    ACTIONS(194), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [881] = 4,
    ACTIONS(198), 1,
      anon_sym_LF,
    ACTIONS(200), 1,
      aux_sym_c_style_description_token1,
    STATE(64), 1,
      aux_sym_c_style_description_repeat1,
    STATE(90), 1,
      sym_c_style_description,
  [894] = 4,
    ACTIONS(202), 1,
      aux_sym_functor_token1,
    STATE(54), 1,
      sym_functor,
    STATE(61), 1,
      sym_head,
    STATE(72), 1,
      sym_template,
  [907] = 2,
    ACTIONS(204), 1,
      anon_sym_PERCENT,
    ACTIONS(164), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [916] = 2,
    ACTIONS(206), 1,
      anon_sym_PERCENT,
    ACTIONS(208), 3,
      anon_sym_is,
      anon_sym_LPAREN,
      aux_sym_pldoc_prolog_directive_token1,
  [925] = 4,
    ACTIONS(200), 1,
      aux_sym_c_style_description_token1,
    ACTIONS(210), 1,
      anon_sym_LF,
    STATE(64), 1,
      aux_sym_c_style_description_repeat1,
    STATE(85), 1,
      sym_c_style_description,
  [938] = 2,
    ACTIONS(117), 1,
      anon_sym_PERCENT,
    ACTIONS(115), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [947] = 2,
    ACTIONS(214), 1,
      anon_sym_PERCENT,
    ACTIONS(212), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [956] = 3,
    ACTIONS(216), 1,
      anon_sym_PERCENT,
    ACTIONS(220), 1,
      anon_sym_LPAREN,
    ACTIONS(218), 2,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
  [967] = 2,
    ACTIONS(224), 1,
      anon_sym_PERCENT,
    ACTIONS(222), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [976] = 4,
    ACTIONS(21), 1,
      aux_sym_functor_token1,
    STATE(63), 1,
      sym_functor,
    STATE(67), 1,
      sym_head,
    STATE(96), 1,
      sym_template,
  [989] = 2,
    ACTIONS(228), 1,
      anon_sym_COLON,
    ACTIONS(226), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [997] = 1,
    ACTIONS(230), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
  [1003] = 2,
    ACTIONS(234), 1,
      anon_sym_COLON,
    ACTIONS(232), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1011] = 2,
    ACTIONS(236), 1,
      anon_sym_PERCENT,
    ACTIONS(238), 2,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
  [1019] = 3,
    ACTIONS(240), 1,
      anon_sym_PERCENT,
    ACTIONS(242), 1,
      anon_sym_is,
    ACTIONS(244), 1,
      aux_sym_pldoc_prolog_directive_token1,
  [1029] = 2,
    ACTIONS(246), 1,
      anon_sym_PERCENT,
    ACTIONS(248), 2,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
  [1037] = 3,
    ACTIONS(216), 1,
      anon_sym_is,
    ACTIONS(218), 1,
      anon_sym_LF,
    ACTIONS(250), 1,
      anon_sym_LPAREN,
  [1047] = 3,
    ACTIONS(27), 1,
      anon_sym_LF,
    ACTIONS(200), 1,
      aux_sym_c_style_description_token1,
    STATE(66), 1,
      aux_sym_c_style_description_repeat1,
  [1057] = 2,
    ACTIONS(208), 1,
      anon_sym_LF,
    ACTIONS(206), 2,
      anon_sym_is,
      anon_sym_LPAREN,
  [1065] = 3,
    ACTIONS(38), 1,
      anon_sym_LF,
    ACTIONS(252), 1,
      aux_sym_c_style_description_token1,
    STATE(66), 1,
      aux_sym_c_style_description_repeat1,
  [1075] = 2,
    ACTIONS(244), 1,
      anon_sym_LF,
    ACTIONS(255), 1,
      anon_sym_is,
  [1082] = 2,
    ACTIONS(257), 1,
      anon_sym_COMMA,
    ACTIONS(259), 1,
      anon_sym_RPAREN,
  [1089] = 2,
    ACTIONS(91), 1,
      aux_sym_functor_token1,
    STATE(59), 1,
      sym_arg_name,
  [1096] = 2,
    ACTIONS(261), 1,
      aux_sym_functor_token1,
    STATE(76), 1,
      sym_type,
  [1103] = 2,
    ACTIONS(257), 1,
      anon_sym_COMMA,
    ACTIONS(263), 1,
      anon_sym_RPAREN,
  [1110] = 2,
    ACTIONS(265), 1,
      anon_sym_PERCENT,
    ACTIONS(267), 1,
      aux_sym_pldoc_prolog_directive_token1,
  [1117] = 2,
    ACTIONS(269), 1,
      anon_sym_PERCENT,
    ACTIONS(271), 1,
      aux_sym_pldoc_prolog_directive_token1,
  [1124] = 2,
    ACTIONS(261), 1,
      aux_sym_functor_token1,
    STATE(78), 1,
      sym_type,
  [1131] = 1,
    ACTIONS(273), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1136] = 1,
    ACTIONS(275), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1141] = 2,
    ACTIONS(277), 1,
      anon_sym_STAR,
    STATE(2), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1148] = 1,
    ACTIONS(279), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1153] = 2,
    ACTIONS(257), 1,
      anon_sym_COMMA,
    ACTIONS(281), 1,
      anon_sym_RPAREN,
  [1160] = 1,
    ACTIONS(38), 2,
      anon_sym_LF,
      aux_sym_c_style_description_token1,
  [1165] = 2,
    ACTIONS(236), 1,
      anon_sym_is,
    ACTIONS(238), 1,
      anon_sym_LF,
  [1172] = 2,
    ACTIONS(246), 1,
      anon_sym_is,
    ACTIONS(248), 1,
      anon_sym_LF,
  [1179] = 2,
    ACTIONS(283), 1,
      anon_sym_LF,
    ACTIONS(285), 1,
      anon_sym_NULL,
  [1186] = 2,
    ACTIONS(257), 1,
      anon_sym_COMMA,
    ACTIONS(287), 1,
      anon_sym_RPAREN,
  [1193] = 1,
    ACTIONS(289), 1,
      anon_sym_LF,
  [1197] = 1,
    ACTIONS(291), 1,
      anon_sym_LF,
  [1201] = 1,
    ACTIONS(293), 1,
      aux_sym_normal_single_line_comment_token1,
  [1205] = 1,
    ACTIONS(295), 1,
      aux_sym_functor_token1,
  [1209] = 1,
    ACTIONS(297), 1,
      aux_sym_pl_tag_token1,
  [1213] = 1,
    ACTIONS(299), 1,
      anon_sym_LF,
  [1217] = 1,
    ACTIONS(301), 1,
      aux_sym_functor_token1,
  [1221] = 1,
    ACTIONS(303), 1,
      aux_sym_pl_tag_token1,
  [1225] = 1,
    ACTIONS(271), 1,
      anon_sym_LF,
  [1229] = 1,
    ACTIONS(305), 1,
      aux_sym_pl_tag_token1,
  [1233] = 1,
    ACTIONS(307), 1,
      anon_sym_STAR_SLASH,
  [1237] = 1,
    ACTIONS(309), 1,
      anon_sym_LF,
  [1241] = 1,
    ACTIONS(257), 1,
      anon_sym_COMMA,
  [1245] = 1,
    ACTIONS(311), 1,
      anon_sym_LF,
  [1249] = 1,
    ACTIONS(313), 1,
      aux_sym_c_style_description_token2,
  [1253] = 1,
    ACTIONS(315), 1,
      anon_sym_LF,
  [1257] = 1,
    ACTIONS(317), 1,
      aux_sym_c_style_description_token2,
  [1261] = 1,
    ACTIONS(319), 1,
      aux_sym_pl_tag_token1,
  [1265] = 1,
    ACTIONS(321), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 44,
  [SMALL_STATE(4)] = 76,
  [SMALL_STATE(5)] = 99,
  [SMALL_STATE(6)] = 128,
  [SMALL_STATE(7)] = 157,
  [SMALL_STATE(8)] = 180,
  [SMALL_STATE(9)] = 203,
  [SMALL_STATE(10)] = 232,
  [SMALL_STATE(11)] = 261,
  [SMALL_STATE(12)] = 279,
  [SMALL_STATE(13)] = 297,
  [SMALL_STATE(14)] = 320,
  [SMALL_STATE(15)] = 339,
  [SMALL_STATE(16)] = 358,
  [SMALL_STATE(17)] = 390,
  [SMALL_STATE(18)] = 422,
  [SMALL_STATE(19)] = 442,
  [SMALL_STATE(20)] = 462,
  [SMALL_STATE(21)] = 487,
  [SMALL_STATE(22)] = 512,
  [SMALL_STATE(23)] = 537,
  [SMALL_STATE(24)] = 562,
  [SMALL_STATE(25)] = 587,
  [SMALL_STATE(26)] = 617,
  [SMALL_STATE(27)] = 631,
  [SMALL_STATE(28)] = 652,
  [SMALL_STATE(29)] = 673,
  [SMALL_STATE(30)] = 689,
  [SMALL_STATE(31)] = 707,
  [SMALL_STATE(32)] = 725,
  [SMALL_STATE(33)] = 736,
  [SMALL_STATE(34)] = 745,
  [SMALL_STATE(35)] = 754,
  [SMALL_STATE(36)] = 766,
  [SMALL_STATE(37)] = 778,
  [SMALL_STATE(38)] = 792,
  [SMALL_STATE(39)] = 804,
  [SMALL_STATE(40)] = 816,
  [SMALL_STATE(41)] = 825,
  [SMALL_STATE(42)] = 834,
  [SMALL_STATE(43)] = 845,
  [SMALL_STATE(44)] = 854,
  [SMALL_STATE(45)] = 863,
  [SMALL_STATE(46)] = 872,
  [SMALL_STATE(47)] = 881,
  [SMALL_STATE(48)] = 894,
  [SMALL_STATE(49)] = 907,
  [SMALL_STATE(50)] = 916,
  [SMALL_STATE(51)] = 925,
  [SMALL_STATE(52)] = 938,
  [SMALL_STATE(53)] = 947,
  [SMALL_STATE(54)] = 956,
  [SMALL_STATE(55)] = 967,
  [SMALL_STATE(56)] = 976,
  [SMALL_STATE(57)] = 989,
  [SMALL_STATE(58)] = 997,
  [SMALL_STATE(59)] = 1003,
  [SMALL_STATE(60)] = 1011,
  [SMALL_STATE(61)] = 1019,
  [SMALL_STATE(62)] = 1029,
  [SMALL_STATE(63)] = 1037,
  [SMALL_STATE(64)] = 1047,
  [SMALL_STATE(65)] = 1057,
  [SMALL_STATE(66)] = 1065,
  [SMALL_STATE(67)] = 1075,
  [SMALL_STATE(68)] = 1082,
  [SMALL_STATE(69)] = 1089,
  [SMALL_STATE(70)] = 1096,
  [SMALL_STATE(71)] = 1103,
  [SMALL_STATE(72)] = 1110,
  [SMALL_STATE(73)] = 1117,
  [SMALL_STATE(74)] = 1124,
  [SMALL_STATE(75)] = 1131,
  [SMALL_STATE(76)] = 1136,
  [SMALL_STATE(77)] = 1141,
  [SMALL_STATE(78)] = 1148,
  [SMALL_STATE(79)] = 1153,
  [SMALL_STATE(80)] = 1160,
  [SMALL_STATE(81)] = 1165,
  [SMALL_STATE(82)] = 1172,
  [SMALL_STATE(83)] = 1179,
  [SMALL_STATE(84)] = 1186,
  [SMALL_STATE(85)] = 1193,
  [SMALL_STATE(86)] = 1197,
  [SMALL_STATE(87)] = 1201,
  [SMALL_STATE(88)] = 1205,
  [SMALL_STATE(89)] = 1209,
  [SMALL_STATE(90)] = 1213,
  [SMALL_STATE(91)] = 1217,
  [SMALL_STATE(92)] = 1221,
  [SMALL_STATE(93)] = 1225,
  [SMALL_STATE(94)] = 1229,
  [SMALL_STATE(95)] = 1233,
  [SMALL_STATE(96)] = 1237,
  [SMALL_STATE(97)] = 1241,
  [SMALL_STATE(98)] = 1245,
  [SMALL_STATE(99)] = 1249,
  [SMALL_STATE(100)] = 1253,
  [SMALL_STATE(101)] = 1257,
  [SMALL_STATE(102)] = 1261,
  [SMALL_STATE(103)] = 1265,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [27] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_style_description, 1, 0, 0),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 1, 0, 0),
  [33] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [36] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [38] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(101),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 2, 0, 0),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [53] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [56] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [64] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [66] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [74] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(87),
  [77] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [80] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(77),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(69),
  [96] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(69),
  [99] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(58),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 2, 0, 0),
  [104] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 2, 0, 0), SHIFT(13),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 3, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 3, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 2, 0, 0),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 2, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [125] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0), SHIFT_REPEAT(98),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [136] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [142] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [145] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [150] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 1, 0, 0),
  [154] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 1, 0, 0), SHIFT(19),
  [157] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 2, 0, 0),
  [161] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 2, 0, 0), SHIFT(19),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [166] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [179] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 4, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 4, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 2, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor, 1, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor, 1, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_tag, 3, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 4, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 4, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 1, 0, 0),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 1, 0, 0),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [224] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 1, 0, 0),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 1, 0, 0),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_name, 1, 0, 0),
  [232] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 2, 0, 0),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 4, 0, 0),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 4, 0, 0),
  [240] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_template, 1, 0, 0),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [244] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1, 0, 0),
  [246] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 5, 0, 0),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 5, 0, 0),
  [250] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [252] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(99),
  [255] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [265] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [269] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_template, 3, 0, 0),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 3, 0, 0),
  [273] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [275] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 3, 0, 0),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 4, 0, 0),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [285] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 4, 0, 0),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_tag, 3, 0, 0),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [321] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
