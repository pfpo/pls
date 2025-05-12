#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 96
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 73
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
  sym_normal_multiline_comment = 5,
  anon_sym_is = 6,
  anon_sym_det = 7,
  anon_sym_semidet = 8,
  anon_sym_failure = 9,
  anon_sym_nondet = 10,
  anon_sym_multi = 11,
  anon_sym_undefined = 12,
  anon_sym_LPAREN = 13,
  anon_sym_COMMA = 14,
  anon_sym_RPAREN = 15,
  anon_sym_PLUS_PLUS = 16,
  anon_sym_PLUS = 17,
  anon_sym_DASH = 18,
  anon_sym_DASH_DASH = 19,
  anon_sym_QMARK = 20,
  anon_sym_COLON = 21,
  anon_sym_AT = 22,
  anon_sym_BANG = 23,
  aux_sym_functor_token1 = 24,
  aux_sym_pldoc_prolog_directive_token1 = 25,
  aux_sym_prolog_style_description_token1 = 26,
  aux_sym_prolog_style_description_token2 = 27,
  anon_sym_SLASH_STAR_STAR = 28,
  anon_sym_STAR = 29,
  anon_sym_STAR_SLASH = 30,
  aux_sym_c_style_description_token1 = 31,
  aux_sym_c_style_description_token2 = 32,
  anon_sym_ATarg = 33,
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
  sym_tag = 63,
  aux_sym_source_file_repeat1 = 64,
  aux_sym_head_repeat1 = 65,
  aux_sym_pldoc_prolog_style_repeat1 = 66,
  aux_sym_pldoc_prolog_style_repeat2 = 67,
  aux_sym_prolog_style_body_repeat1 = 68,
  aux_sym_prolog_style_description_repeat1 = 69,
  aux_sym_pldoc_c_style_repeat1 = 70,
  aux_sym_c_style_body_repeat1 = 71,
  aux_sym_c_style_description_repeat1 = 72,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_PERCENT] = "%",
  [aux_sym_normal_single_line_comment_token1] = "normal_single_line_comment_token1",
  [anon_sym_LF] = "\n",
  [anon_sym_NULL] = "\0",
  [sym_normal_multiline_comment] = "normal_multiline_comment",
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
  [sym_tag] = "tag",
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
  [sym_normal_multiline_comment] = sym_normal_multiline_comment,
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
  [sym_tag] = sym_tag,
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
  [sym_normal_multiline_comment] = {
    .visible = true,
    .named = true,
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
  [sym_tag] = {
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
  [23] = 23,
  [24] = 21,
  [25] = 22,
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
  [36] = 34,
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
  [59] = 49,
  [60] = 52,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 53,
  [70] = 70,
  [71] = 56,
  [72] = 72,
  [73] = 58,
  [74] = 74,
  [75] = 62,
  [76] = 64,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 65,
  [84] = 84,
  [85] = 85,
  [86] = 47,
  [87] = 78,
  [88] = 88,
  [89] = 44,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 91,
  [94] = 85,
  [95] = 95,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(104);
      ADVANCE_MAP(
        0, 111,
        '!', 130,
        '%', 105,
        '(', 120,
        ')', 122,
        '*', 137,
        '+', 124,
        ',', 121,
        '-', 125,
        '/', 15,
        ':', 128,
        '?', 127,
        '@', 129,
        'd', 33,
        'f', 18,
        'i', 88,
        'm', 99,
        'n', 75,
        's', 34,
        'u', 66,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if ((!eof && lookahead == 00)) ADVANCE(111);
      if (lookahead == '\n') ADVANCE(110);
      if (lookahead == '(') ADVANCE(120);
      if (lookahead == 'i') ADVANCE(88);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
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
      if (lookahead == '@') ADVANCE(19);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(6);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(9);
      if (lookahead == ' ') ADVANCE(135);
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(112);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 8:
      if (lookahead == '\n') ADVANCE(9);
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 9:
      if (lookahead == '\n') ADVANCE(9);
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 10:
      if (lookahead == '\n') ADVANCE(9);
      if (lookahead == '*') ADVANCE(10);
      if (lookahead == '/') ADVANCE(112);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 11:
      if (lookahead == '\n') ADVANCE(9);
      if (lookahead == '*') ADVANCE(10);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 12:
      if (lookahead == ' ') ADVANCE(132);
      END_STATE();
    case 13:
      if (lookahead == '!') ADVANCE(130);
      if (lookahead == '+') ADVANCE(124);
      if (lookahead == '-') ADVANCE(125);
      if (lookahead == ':') ADVANCE(128);
      if (lookahead == '?') ADVANCE(127);
      if (lookahead == '@') ADVANCE(129);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(131);
      END_STATE();
    case 14:
      if (lookahead == '%') ADVANCE(106);
      if (lookahead == '(') ADVANCE(120);
      if (lookahead == 'i') ADVANCE(88);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(14);
      END_STATE();
    case 15:
      if (lookahead == '*') ADVANCE(8);
      END_STATE();
    case 16:
      if (lookahead == '/') ADVANCE(142);
      END_STATE();
    case 17:
      if (lookahead == '/') ADVANCE(9);
      END_STATE();
    case 18:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 19:
      ADVANCE_MAP(
        'a', 78,
        'b', 101,
        'c', 71,
        'd', 37,
        'e', 84,
        'l', 55,
        'p', 21,
        's', 47,
        't', 24,
        'v', 46,
      );
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(63);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(82);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(95);
      END_STATE();
    case 23:
      if (lookahead == 'a') ADVANCE(98);
      END_STATE();
    case 24:
      if (lookahead == 'b') ADVANCE(28);
      END_STATE();
    case 25:
      if (lookahead == 'c') ADVANCE(41);
      END_STATE();
    case 26:
      if (lookahead == 'c') ADVANCE(23);
      END_STATE();
    case 27:
      if (lookahead == 'd') ADVANCE(119);
      END_STATE();
    case 28:
      if (lookahead == 'd') ADVANCE(209);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(204);
      END_STATE();
    case 30:
      if (lookahead == 'd') ADVANCE(35);
      END_STATE();
    case 31:
      if (lookahead == 'd') ADVANCE(42);
      END_STATE();
    case 32:
      if (lookahead == 'd') ADVANCE(44);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(91);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(64);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(116);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(77);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(203);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(207);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(26);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(69);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(92);
      END_STATE();
    case 43:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(93);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(29);
      END_STATE();
    case 46:
      if (lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 48:
      if (lookahead == 'f') ADVANCE(56);
      END_STATE();
    case 49:
      if (lookahead == 'g') ADVANCE(198);
      END_STATE();
    case 50:
      if (lookahead == 'g') ADVANCE(208);
      END_STATE();
    case 51:
      if (lookahead == 'g') ADVANCE(52);
      END_STATE();
    case 52:
      if (lookahead == 'h') ADVANCE(96);
      END_STATE();
    case 53:
      if (lookahead == 'h') ADVANCE(74);
      END_STATE();
    case 54:
      if (lookahead == 'i') ADVANCE(118);
      END_STATE();
    case 55:
      if (lookahead == 'i') ADVANCE(25);
      END_STATE();
    case 56:
      if (lookahead == 'i') ADVANCE(70);
      END_STATE();
    case 57:
      if (lookahead == 'i') ADVANCE(61);
      END_STATE();
    case 58:
      if (lookahead == 'i') ADVANCE(51);
      END_STATE();
    case 59:
      if (lookahead == 'i') ADVANCE(72);
      END_STATE();
    case 60:
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 61:
      if (lookahead == 'l') ADVANCE(100);
      END_STATE();
    case 62:
      if (lookahead == 'l') ADVANCE(97);
      END_STATE();
    case 63:
      if (lookahead == 'm') ADVANCE(199);
      END_STATE();
    case 64:
      if (lookahead == 'm') ADVANCE(60);
      END_STATE();
    case 65:
      if (lookahead == 'm') ADVANCE(76);
      if (lookahead == 'p') ADVANCE(102);
      END_STATE();
    case 66:
      if (lookahead == 'n') ADVANCE(30);
      END_STATE();
    case 67:
      if (lookahead == 'n') ADVANCE(202);
      END_STATE();
    case 68:
      if (lookahead == 'n') ADVANCE(31);
      END_STATE();
    case 69:
      if (lookahead == 'n') ADVANCE(90);
      END_STATE();
    case 70:
      if (lookahead == 'n') ADVANCE(43);
      END_STATE();
    case 71:
      if (lookahead == 'o') ADVANCE(65);
      END_STATE();
    case 72:
      if (lookahead == 'o') ADVANCE(67);
      END_STATE();
    case 73:
      if (lookahead == 'o') ADVANCE(79);
      END_STATE();
    case 74:
      if (lookahead == 'o') ADVANCE(80);
      END_STATE();
    case 75:
      if (lookahead == 'o') ADVANCE(68);
      END_STATE();
    case 76:
      if (lookahead == 'p') ADVANCE(22);
      END_STATE();
    case 77:
      if (lookahead == 'p') ADVANCE(87);
      END_STATE();
    case 78:
      if (lookahead == 'r') ADVANCE(49);
      if (lookahead == 'u') ADVANCE(94);
      END_STATE();
    case 79:
      if (lookahead == 'r') ADVANCE(200);
      END_STATE();
    case 80:
      if (lookahead == 'r') ADVANCE(201);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(89);
      END_STATE();
    case 82:
      if (lookahead == 'r') ADVANCE(20);
      END_STATE();
    case 83:
      if (lookahead == 'r') ADVANCE(73);
      END_STATE();
    case 84:
      if (lookahead == 'r') ADVANCE(83);
      END_STATE();
    case 85:
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 86:
      if (lookahead == 'r') ADVANCE(58);
      END_STATE();
    case 87:
      if (lookahead == 'r') ADVANCE(40);
      END_STATE();
    case 88:
      if (lookahead == 's') ADVANCE(113);
      END_STATE();
    case 89:
      if (lookahead == 's') ADVANCE(59);
      END_STATE();
    case 90:
      if (lookahead == 's') ADVANCE(39);
      END_STATE();
    case 91:
      if (lookahead == 't') ADVANCE(114);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(117);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(115);
      END_STATE();
    case 94:
      if (lookahead == 't') ADVANCE(53);
      END_STATE();
    case 95:
      if (lookahead == 't') ADVANCE(205);
      END_STATE();
    case 96:
      if (lookahead == 't') ADVANCE(206);
      END_STATE();
    case 97:
      if (lookahead == 't') ADVANCE(54);
      END_STATE();
    case 98:
      if (lookahead == 't') ADVANCE(45);
      END_STATE();
    case 99:
      if (lookahead == 'u') ADVANCE(62);
      END_STATE();
    case 100:
      if (lookahead == 'u') ADVANCE(85);
      END_STATE();
    case 101:
      if (lookahead == 'u') ADVANCE(50);
      END_STATE();
    case 102:
      if (lookahead == 'y') ADVANCE(86);
      END_STATE();
    case 103:
      if (eof) ADVANCE(104);
      if (lookahead == '%') ADVANCE(106);
      if (lookahead == '*') ADVANCE(137);
      if (lookahead == '/') ADVANCE(15);
      if (lookahead == '@') ADVANCE(19);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(103);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(131);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(134);
      if (lookahead == '!') ADVANCE(4);
      if (lookahead == '%') ADVANCE(4);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(5);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!') ADVANCE(12);
      if (lookahead == '%') ADVANCE(12);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(aux_sym_normal_single_line_comment_token1);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(107);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(108);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(aux_sym_normal_single_line_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(108);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(109);
      if (lookahead == '@') ADVANCE(19);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(110);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_normal_multiline_comment);
      if (lookahead == '/') ADVANCE(9);
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
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == '/') ADVANCE(139);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '/') ADVANCE(138);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_STAR_SLASH);
      if (lookahead == '/') ADVANCE(142);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(136);
      if (lookahead == '/') ADVANCE(16);
      if (lookahead == '@') ADVANCE(143);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(141);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(196);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(136);
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
      if (lookahead == '/') ADVANCE(16);
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
      if (lookahead == 'd') ADVANCE(209);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'd') ADVANCE(204);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'e') ADVANCE(203);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'e') ADVANCE(207);
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
      if (lookahead == 'g') ADVANCE(208);
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
      if (lookahead == 'm') ADVANCE(199);
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
      if (lookahead == 'n') ADVANCE(202);
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
      if (lookahead == 'r') ADVANCE(200);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 'r') ADVANCE(201);
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
      if (lookahead == 't') ADVANCE(205);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(196);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(aux_sym_c_style_description_token1);
      if (lookahead == '*') ADVANCE(142);
      if (lookahead == 't') ADVANCE(206);
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
      ACCEPT_TOKEN(anon_sym_ATparam);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_ATerror);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(anon_sym_ATauthor);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_ATversion);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_ATsee);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_ATdeprecated);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(anon_sym_ATcompat);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_ATcopyright);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_ATlicense);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_ATbug);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_ATtbd);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 103},
  [2] = {.lex_state = 140},
  [3] = {.lex_state = 103},
  [4] = {.lex_state = 140},
  [5] = {.lex_state = 140},
  [6] = {.lex_state = 103},
  [7] = {.lex_state = 103},
  [8] = {.lex_state = 103},
  [9] = {.lex_state = 140},
  [10] = {.lex_state = 103},
  [11] = {.lex_state = 140},
  [12] = {.lex_state = 140},
  [13] = {.lex_state = 6},
  [14] = {.lex_state = 103},
  [15] = {.lex_state = 103},
  [16] = {.lex_state = 103},
  [17] = {.lex_state = 103},
  [18] = {.lex_state = 103},
  [19] = {.lex_state = 103},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 13},
  [22] = {.lex_state = 13},
  [23] = {.lex_state = 13},
  [24] = {.lex_state = 13},
  [25] = {.lex_state = 13},
  [26] = {.lex_state = 13},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 103},
  [32] = {.lex_state = 103},
  [33] = {.lex_state = 103},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 103},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 103},
  [38] = {.lex_state = 103},
  [39] = {.lex_state = 103},
  [40] = {.lex_state = 103},
  [41] = {.lex_state = 103},
  [42] = {.lex_state = 103},
  [43] = {.lex_state = 103},
  [44] = {.lex_state = 103},
  [45] = {.lex_state = 103},
  [46] = {.lex_state = 103},
  [47] = {.lex_state = 103},
  [48] = {.lex_state = 103},
  [49] = {.lex_state = 14},
  [50] = {.lex_state = 103},
  [51] = {.lex_state = 103},
  [52] = {.lex_state = 14},
  [53] = {.lex_state = 14},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 14},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 14},
  [59] = {.lex_state = 1},
  [60] = {.lex_state = 1},
  [61] = {.lex_state = 103},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 103},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 103},
  [66] = {.lex_state = 103},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 1},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 1},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 1},
  [74] = {.lex_state = 1},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 103},
  [78] = {.lex_state = 103},
  [79] = {.lex_state = 1},
  [80] = {.lex_state = 1},
  [81] = {.lex_state = 197},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 1},
  [84] = {.lex_state = 1},
  [85] = {.lex_state = 103},
  [86] = {.lex_state = 1},
  [87] = {.lex_state = 103},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 1},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 103},
  [92] = {.lex_state = 107},
  [93] = {.lex_state = 103},
  [94] = {.lex_state = 103},
  [95] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_NULL] = ACTIONS(1),
    [sym_normal_multiline_comment] = ACTIONS(1),
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
    [sym_comment] = STATE(14),
    [sym_normal_comment] = STATE(45),
    [sym_normal_single_line_comment] = STATE(41),
    [sym_pldoc_comment] = STATE(45),
    [sym_pldoc_prolog_directive] = STATE(43),
    [sym_pldoc_prolog_style] = STATE(46),
    [sym_pldoc_c_style] = STATE(46),
    [aux_sym_source_file_repeat1] = STATE(14),
    [aux_sym_pldoc_prolog_style_repeat1] = STATE(43),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_PERCENT] = ACTIONS(5),
    [sym_normal_multiline_comment] = ACTIONS(7),
    [aux_sym_pldoc_prolog_directive_token1] = ACTIONS(9),
    [anon_sym_SLASH_STAR_STAR] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(15), 1,
      anon_sym_STAR_SLASH,
    ACTIONS(17), 1,
      aux_sym_c_style_description_token1,
    STATE(4), 1,
      aux_sym_c_style_description_repeat1,
    STATE(5), 1,
      aux_sym_pldoc_c_style_repeat1,
    STATE(6), 1,
      sym_c_style_description,
    STATE(7), 1,
      aux_sym_c_style_body_repeat1,
    STATE(82), 1,
      sym_tag,
    STATE(88), 1,
      sym_c_style_body,
    ACTIONS(19), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(21), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [44] = 7,
    ACTIONS(23), 1,
      aux_sym_functor_token1,
    STATE(59), 1,
      sym_functor,
    STATE(69), 1,
      sym_head,
    STATE(79), 1,
      sym_template,
    STATE(84), 1,
      sym_tag,
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
  [76] = 3,
    ACTIONS(17), 1,
      aux_sym_c_style_description_token1,
    STATE(9), 1,
      aux_sym_c_style_description_repeat1,
    ACTIONS(29), 14,
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
  [99] = 3,
    ACTIONS(31), 1,
      anon_sym_STAR,
    STATE(5), 1,
      aux_sym_pldoc_c_style_repeat1,
    ACTIONS(34), 14,
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
  [122] = 6,
    ACTIONS(36), 1,
      anon_sym_STAR,
    ACTIONS(38), 1,
      anon_sym_STAR_SLASH,
    STATE(8), 1,
      aux_sym_c_style_body_repeat1,
    STATE(82), 1,
      sym_tag,
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
  [151] = 6,
    ACTIONS(36), 1,
      anon_sym_STAR,
    ACTIONS(38), 1,
      anon_sym_STAR_SLASH,
    STATE(10), 1,
      aux_sym_c_style_body_repeat1,
    STATE(82), 1,
      sym_tag,
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
  [180] = 6,
    ACTIONS(36), 1,
      anon_sym_STAR,
    ACTIONS(40), 1,
      anon_sym_STAR_SLASH,
    STATE(10), 1,
      aux_sym_c_style_body_repeat1,
    STATE(82), 1,
      sym_tag,
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
  [209] = 3,
    ACTIONS(44), 1,
      aux_sym_c_style_description_token1,
    STATE(9), 1,
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
  [232] = 6,
    ACTIONS(47), 1,
      anon_sym_STAR,
    ACTIONS(50), 1,
      anon_sym_STAR_SLASH,
    STATE(10), 1,
      aux_sym_c_style_body_repeat1,
    STATE(82), 1,
      sym_tag,
    ACTIONS(52), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(55), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [261] = 1,
    ACTIONS(42), 15,
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
    ACTIONS(58), 15,
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
    ACTIONS(60), 1,
      anon_sym_LF,
    STATE(39), 1,
      sym_tag,
    ACTIONS(62), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(64), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [320] = 10,
    ACTIONS(5), 1,
      anon_sym_PERCENT,
    ACTIONS(7), 1,
      sym_normal_multiline_comment,
    ACTIONS(9), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(11), 1,
      anon_sym_SLASH_STAR_STAR,
    ACTIONS(66), 1,
      ts_builtin_sym_end,
    STATE(41), 1,
      sym_normal_single_line_comment,
    STATE(15), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(43), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(45), 2,
      sym_normal_comment,
      sym_pldoc_comment,
    STATE(46), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
  [355] = 10,
    ACTIONS(68), 1,
      ts_builtin_sym_end,
    ACTIONS(70), 1,
      anon_sym_PERCENT,
    ACTIONS(73), 1,
      sym_normal_multiline_comment,
    ACTIONS(76), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(79), 1,
      anon_sym_SLASH_STAR_STAR,
    STATE(41), 1,
      sym_normal_single_line_comment,
    STATE(15), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(43), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
    STATE(45), 2,
      sym_normal_comment,
      sym_pldoc_comment,
    STATE(46), 2,
      sym_pldoc_prolog_style,
      sym_pldoc_c_style,
  [390] = 2,
    ACTIONS(82), 1,
      anon_sym_STAR,
    ACTIONS(50), 13,
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
  [409] = 2,
    ACTIONS(84), 1,
      anon_sym_STAR,
    ACTIONS(86), 13,
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
  [428] = 3,
    STATE(39), 1,
      sym_tag,
    ACTIONS(88), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(90), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [448] = 3,
    STATE(84), 1,
      sym_tag,
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
  [468] = 10,
    ACTIONS(94), 1,
      anon_sym_PERCENT,
    ACTIONS(97), 1,
      sym_normal_multiline_comment,
    ACTIONS(99), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(101), 1,
      aux_sym_prolog_style_description_token2,
    STATE(27), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    STATE(28), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(32), 1,
      aux_sym_prolog_style_body_repeat1,
    STATE(35), 1,
      sym_prolog_style_description,
    STATE(38), 1,
      sym_prolog_style_body,
    ACTIONS(92), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [501] = 6,
    ACTIONS(107), 1,
      aux_sym_functor_token1,
    STATE(22), 1,
      aux_sym_head_repeat1,
    STATE(54), 1,
      sym_arg_name,
    STATE(62), 1,
      sym_arg_spec,
    ACTIONS(105), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [526] = 6,
    ACTIONS(107), 1,
      aux_sym_functor_token1,
    STATE(23), 1,
      aux_sym_head_repeat1,
    STATE(54), 1,
      sym_arg_name,
    STATE(64), 1,
      sym_arg_spec,
    ACTIONS(105), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [551] = 6,
    ACTIONS(115), 1,
      aux_sym_functor_token1,
    STATE(23), 1,
      aux_sym_head_repeat1,
    STATE(54), 1,
      sym_arg_name,
    STATE(95), 1,
      sym_arg_spec,
    ACTIONS(112), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(109), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [576] = 6,
    ACTIONS(107), 1,
      aux_sym_functor_token1,
    STATE(25), 1,
      aux_sym_head_repeat1,
    STATE(54), 1,
      sym_arg_name,
    STATE(75), 1,
      sym_arg_spec,
    ACTIONS(105), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [601] = 6,
    ACTIONS(107), 1,
      aux_sym_functor_token1,
    STATE(23), 1,
      aux_sym_head_repeat1,
    STATE(54), 1,
      sym_arg_name,
    STATE(76), 1,
      sym_arg_spec,
    ACTIONS(105), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(103), 6,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
  [626] = 2,
    ACTIONS(120), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(118), 7,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_QMARK,
      anon_sym_COLON,
      anon_sym_AT,
      anon_sym_BANG,
      aux_sym_functor_token1,
  [640] = 4,
    ACTIONS(124), 1,
      anon_sym_PERCENT,
    STATE(27), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(127), 2,
      sym_normal_multiline_comment,
      aux_sym_prolog_style_description_token1,
    ACTIONS(122), 4,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      aux_sym_prolog_style_description_token2,
      anon_sym_SLASH_STAR_STAR,
  [657] = 5,
    ACTIONS(133), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(135), 1,
      aux_sym_prolog_style_description_token2,
    STATE(29), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(131), 2,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
    ACTIONS(129), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [676] = 5,
    ACTIONS(141), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(144), 1,
      aux_sym_prolog_style_description_token2,
    STATE(29), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(139), 2,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
    ACTIONS(137), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [695] = 2,
    ACTIONS(127), 3,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
      aux_sym_prolog_style_description_token1,
    ACTIONS(122), 4,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      aux_sym_prolog_style_description_token2,
      anon_sym_SLASH_STAR_STAR,
  [707] = 4,
    ACTIONS(149), 1,
      anon_sym_PERCENT,
    ACTIONS(152), 1,
      sym_normal_multiline_comment,
    STATE(33), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(147), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [722] = 4,
    ACTIONS(156), 1,
      anon_sym_PERCENT,
    ACTIONS(159), 1,
      sym_normal_multiline_comment,
    STATE(33), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(154), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [737] = 4,
    ACTIONS(163), 1,
      anon_sym_PERCENT,
    ACTIONS(166), 1,
      sym_normal_multiline_comment,
    STATE(33), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(161), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [752] = 1,
    ACTIONS(168), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [761] = 4,
    ACTIONS(156), 1,
      anon_sym_PERCENT,
    ACTIONS(159), 1,
      sym_normal_multiline_comment,
    STATE(31), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(154), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [776] = 1,
    ACTIONS(170), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [785] = 2,
    ACTIONS(174), 2,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
    ACTIONS(172), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [795] = 2,
    ACTIONS(178), 2,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
    ACTIONS(176), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [805] = 2,
    ACTIONS(166), 2,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
    ACTIONS(161), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [815] = 2,
    ACTIONS(182), 2,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
    ACTIONS(180), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [825] = 2,
    ACTIONS(186), 2,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
    ACTIONS(184), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [835] = 2,
    ACTIONS(190), 2,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
    ACTIONS(188), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [845] = 4,
    ACTIONS(9), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(192), 1,
      anon_sym_PERCENT,
    STATE(20), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    STATE(51), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [859] = 2,
    ACTIONS(196), 2,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
    ACTIONS(194), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [869] = 2,
    ACTIONS(200), 2,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
    ACTIONS(198), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [879] = 2,
    ACTIONS(204), 2,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
    ACTIONS(202), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [889] = 2,
    ACTIONS(208), 2,
      anon_sym_PERCENT,
      sym_normal_multiline_comment,
    ACTIONS(206), 3,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
      anon_sym_SLASH_STAR_STAR,
  [899] = 4,
    ACTIONS(23), 1,
      aux_sym_functor_token1,
    STATE(59), 1,
      sym_functor,
    STATE(69), 1,
      sym_head,
    STATE(79), 1,
      sym_template,
  [912] = 3,
    ACTIONS(210), 1,
      anon_sym_PERCENT,
    ACTIONS(214), 1,
      anon_sym_LPAREN,
    ACTIONS(212), 2,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
  [923] = 4,
    ACTIONS(216), 1,
      aux_sym_functor_token1,
    STATE(49), 1,
      sym_functor,
    STATE(53), 1,
      sym_head,
    STATE(77), 1,
      sym_template,
  [936] = 3,
    ACTIONS(218), 1,
      anon_sym_PERCENT,
    ACTIONS(220), 1,
      aux_sym_pldoc_prolog_directive_token1,
    STATE(51), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [947] = 2,
    ACTIONS(223), 1,
      anon_sym_PERCENT,
    ACTIONS(225), 3,
      anon_sym_is,
      anon_sym_LPAREN,
      aux_sym_pldoc_prolog_directive_token1,
  [956] = 3,
    ACTIONS(227), 1,
      anon_sym_PERCENT,
    ACTIONS(229), 1,
      anon_sym_is,
    ACTIONS(231), 1,
      aux_sym_pldoc_prolog_directive_token1,
  [966] = 2,
    ACTIONS(235), 1,
      anon_sym_COLON,
    ACTIONS(233), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [974] = 1,
    ACTIONS(237), 3,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
  [980] = 2,
    ACTIONS(239), 1,
      anon_sym_PERCENT,
    ACTIONS(241), 2,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
  [988] = 2,
    ACTIONS(245), 1,
      anon_sym_COLON,
    ACTIONS(243), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [996] = 2,
    ACTIONS(247), 1,
      anon_sym_PERCENT,
    ACTIONS(249), 2,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
  [1004] = 3,
    ACTIONS(210), 1,
      anon_sym_is,
    ACTIONS(212), 1,
      anon_sym_LF,
    ACTIONS(251), 1,
      anon_sym_LPAREN,
  [1014] = 2,
    ACTIONS(225), 1,
      anon_sym_LF,
    ACTIONS(223), 2,
      anon_sym_is,
      anon_sym_LPAREN,
  [1022] = 2,
    ACTIONS(107), 1,
      aux_sym_functor_token1,
    STATE(57), 1,
      sym_arg_name,
  [1029] = 2,
    ACTIONS(253), 1,
      anon_sym_COMMA,
    ACTIONS(255), 1,
      anon_sym_RPAREN,
  [1036] = 2,
    ACTIONS(257), 1,
      aux_sym_functor_token1,
    STATE(68), 1,
      sym_type,
  [1043] = 2,
    ACTIONS(253), 1,
      anon_sym_COMMA,
    ACTIONS(259), 1,
      anon_sym_RPAREN,
  [1050] = 2,
    ACTIONS(261), 1,
      anon_sym_PERCENT,
    ACTIONS(263), 1,
      aux_sym_pldoc_prolog_directive_token1,
  [1057] = 2,
    ACTIONS(257), 1,
      aux_sym_functor_token1,
    STATE(70), 1,
      sym_type,
  [1064] = 1,
    ACTIONS(265), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1069] = 1,
    ACTIONS(267), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1074] = 2,
    ACTIONS(231), 1,
      anon_sym_LF,
    ACTIONS(269), 1,
      anon_sym_is,
  [1081] = 1,
    ACTIONS(271), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [1086] = 2,
    ACTIONS(239), 1,
      anon_sym_is,
    ACTIONS(241), 1,
      anon_sym_LF,
  [1093] = 2,
    ACTIONS(273), 1,
      anon_sym_STAR,
    STATE(2), 1,
      aux_sym_pldoc_c_style_repeat1,
  [1100] = 2,
    ACTIONS(247), 1,
      anon_sym_is,
    ACTIONS(249), 1,
      anon_sym_LF,
  [1107] = 2,
    ACTIONS(275), 1,
      anon_sym_LF,
    ACTIONS(277), 1,
      anon_sym_NULL,
  [1114] = 2,
    ACTIONS(253), 1,
      anon_sym_COMMA,
    ACTIONS(279), 1,
      anon_sym_RPAREN,
  [1121] = 2,
    ACTIONS(253), 1,
      anon_sym_COMMA,
    ACTIONS(281), 1,
      anon_sym_RPAREN,
  [1128] = 2,
    ACTIONS(283), 1,
      anon_sym_PERCENT,
    ACTIONS(285), 1,
      aux_sym_pldoc_prolog_directive_token1,
  [1135] = 1,
    ACTIONS(287), 1,
      aux_sym_functor_token1,
  [1139] = 1,
    ACTIONS(289), 1,
      anon_sym_LF,
  [1143] = 1,
    ACTIONS(291), 1,
      anon_sym_LF,
  [1147] = 1,
    ACTIONS(293), 1,
      aux_sym_c_style_description_token2,
  [1151] = 1,
    ACTIONS(295), 1,
      anon_sym_LF,
  [1155] = 1,
    ACTIONS(263), 1,
      anon_sym_LF,
  [1159] = 1,
    ACTIONS(297), 1,
      anon_sym_LF,
  [1163] = 1,
    ACTIONS(299), 1,
      aux_sym_functor_token1,
  [1167] = 1,
    ACTIONS(206), 1,
      anon_sym_LF,
  [1171] = 1,
    ACTIONS(301), 1,
      aux_sym_functor_token1,
  [1175] = 1,
    ACTIONS(303), 1,
      anon_sym_STAR_SLASH,
  [1179] = 1,
    ACTIONS(194), 1,
      anon_sym_LF,
  [1183] = 1,
    ACTIONS(305), 1,
      ts_builtin_sym_end,
  [1187] = 1,
    ACTIONS(307), 1,
      aux_sym_functor_token1,
  [1191] = 1,
    ACTIONS(309), 1,
      aux_sym_normal_single_line_comment_token1,
  [1195] = 1,
    ACTIONS(311), 1,
      aux_sym_functor_token1,
  [1199] = 1,
    ACTIONS(313), 1,
      aux_sym_functor_token1,
  [1203] = 1,
    ACTIONS(253), 1,
      anon_sym_COMMA,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 44,
  [SMALL_STATE(4)] = 76,
  [SMALL_STATE(5)] = 99,
  [SMALL_STATE(6)] = 122,
  [SMALL_STATE(7)] = 151,
  [SMALL_STATE(8)] = 180,
  [SMALL_STATE(9)] = 209,
  [SMALL_STATE(10)] = 232,
  [SMALL_STATE(11)] = 261,
  [SMALL_STATE(12)] = 279,
  [SMALL_STATE(13)] = 297,
  [SMALL_STATE(14)] = 320,
  [SMALL_STATE(15)] = 355,
  [SMALL_STATE(16)] = 390,
  [SMALL_STATE(17)] = 409,
  [SMALL_STATE(18)] = 428,
  [SMALL_STATE(19)] = 448,
  [SMALL_STATE(20)] = 468,
  [SMALL_STATE(21)] = 501,
  [SMALL_STATE(22)] = 526,
  [SMALL_STATE(23)] = 551,
  [SMALL_STATE(24)] = 576,
  [SMALL_STATE(25)] = 601,
  [SMALL_STATE(26)] = 626,
  [SMALL_STATE(27)] = 640,
  [SMALL_STATE(28)] = 657,
  [SMALL_STATE(29)] = 676,
  [SMALL_STATE(30)] = 695,
  [SMALL_STATE(31)] = 707,
  [SMALL_STATE(32)] = 722,
  [SMALL_STATE(33)] = 737,
  [SMALL_STATE(34)] = 752,
  [SMALL_STATE(35)] = 761,
  [SMALL_STATE(36)] = 776,
  [SMALL_STATE(37)] = 785,
  [SMALL_STATE(38)] = 795,
  [SMALL_STATE(39)] = 805,
  [SMALL_STATE(40)] = 815,
  [SMALL_STATE(41)] = 825,
  [SMALL_STATE(42)] = 835,
  [SMALL_STATE(43)] = 845,
  [SMALL_STATE(44)] = 859,
  [SMALL_STATE(45)] = 869,
  [SMALL_STATE(46)] = 879,
  [SMALL_STATE(47)] = 889,
  [SMALL_STATE(48)] = 899,
  [SMALL_STATE(49)] = 912,
  [SMALL_STATE(50)] = 923,
  [SMALL_STATE(51)] = 936,
  [SMALL_STATE(52)] = 947,
  [SMALL_STATE(53)] = 956,
  [SMALL_STATE(54)] = 966,
  [SMALL_STATE(55)] = 974,
  [SMALL_STATE(56)] = 980,
  [SMALL_STATE(57)] = 988,
  [SMALL_STATE(58)] = 996,
  [SMALL_STATE(59)] = 1004,
  [SMALL_STATE(60)] = 1014,
  [SMALL_STATE(61)] = 1022,
  [SMALL_STATE(62)] = 1029,
  [SMALL_STATE(63)] = 1036,
  [SMALL_STATE(64)] = 1043,
  [SMALL_STATE(65)] = 1050,
  [SMALL_STATE(66)] = 1057,
  [SMALL_STATE(67)] = 1064,
  [SMALL_STATE(68)] = 1069,
  [SMALL_STATE(69)] = 1074,
  [SMALL_STATE(70)] = 1081,
  [SMALL_STATE(71)] = 1086,
  [SMALL_STATE(72)] = 1093,
  [SMALL_STATE(73)] = 1100,
  [SMALL_STATE(74)] = 1107,
  [SMALL_STATE(75)] = 1114,
  [SMALL_STATE(76)] = 1121,
  [SMALL_STATE(77)] = 1128,
  [SMALL_STATE(78)] = 1135,
  [SMALL_STATE(79)] = 1139,
  [SMALL_STATE(80)] = 1143,
  [SMALL_STATE(81)] = 1147,
  [SMALL_STATE(82)] = 1151,
  [SMALL_STATE(83)] = 1155,
  [SMALL_STATE(84)] = 1159,
  [SMALL_STATE(85)] = 1163,
  [SMALL_STATE(86)] = 1167,
  [SMALL_STATE(87)] = 1171,
  [SMALL_STATE(88)] = 1175,
  [SMALL_STATE(89)] = 1179,
  [SMALL_STATE(90)] = 1183,
  [SMALL_STATE(91)] = 1187,
  [SMALL_STATE(92)] = 1191,
  [SMALL_STATE(93)] = 1195,
  [SMALL_STATE(94)] = 1199,
  [SMALL_STATE(95)] = 1203,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(87),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [29] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_c_style_description, 1, 0, 0),
  [31] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0), SHIFT_REPEAT(48),
  [34] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 2, 0, 0),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 1, 0, 0),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_c_style_body, 2, 0, 0),
  [42] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(81),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(19),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [52] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(85),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(87),
  [58] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_c_style_repeat1, 3, 0, 0),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(78),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(92),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(41),
  [76] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [79] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(72),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 2, 0, 0),
  [84] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_c_style_body_repeat1, 3, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 2, 0, 0),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 2, 0, 0), SHIFT(13),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 2, 0, 0),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [109] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [112] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [115] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0), SHIFT_REPEAT(55),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_head_repeat1, 2, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [124] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0), SHIFT_REPEAT(80),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [135] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [141] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [144] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 2, 0, 0),
  [149] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 2, 0, 0), SHIFT(18),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_body, 2, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 1, 0, 0),
  [156] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_prolog_style_body, 1, 0, 0), SHIFT(18),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_body, 1, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [163] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(18),
  [166] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 4, 0, 0),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 4, 0, 0),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_c_style, 3, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_comment, 1, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_normal_single_line_comment, 3, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [194] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 2, 0, 0),
  [196] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 2, 0, 0),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [200] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment, 1, 0, 0),
  [202] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [204] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 3, 0, 0),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag, 3, 0, 0),
  [210] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 1, 0, 0),
  [212] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 1, 0, 0),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [218] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [220] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0), SHIFT_REPEAT(50),
  [223] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor, 1, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor, 1, 0, 0),
  [227] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_template, 1, 0, 0),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 1, 0, 0),
  [233] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 1, 0, 0),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_name, 1, 0, 0),
  [239] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 4, 0, 0),
  [241] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 4, 0, 0),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 2, 0, 0),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [247] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_head, 5, 0, 0),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_head, 5, 0, 0),
  [251] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [261] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_template, 3, 0, 0),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 3, 0, 0),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 3, 0, 0),
  [269] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [271] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 4, 0, 0),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [277] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [283] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [305] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [309] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [311] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [313] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
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
