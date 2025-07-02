#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 65
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 58
#define ALIAS_COUNT 1
#define TOKEN_COUNT 35
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 7

enum ts_symbol_identifiers {
  anon_sym_is = 1,
  anon_sym_det = 2,
  anon_sym_semidet = 3,
  anon_sym_failure = 4,
  anon_sym_nondet = 5,
  anon_sym_multi = 6,
  anon_sym_undefined = 7,
  anon_sym_COLON_DASH = 8,
  anon_sym_LPAREN = 9,
  anon_sym_COMMA = 10,
  anon_sym_RPAREN = 11,
  sym_arg_name_instantiation = 12,
  anon_sym_COLON = 13,
  sym_functor = 14,
  aux_sym_type_token1 = 15,
  aux_sym_pldoc_prolog_directive_token1 = 16,
  anon_sym_PERCENT = 17,
  anon_sym_LF = 18,
  aux_sym_prolog_style_description_token1 = 19,
  aux_sym_prolog_style_description_token2 = 20,
  aux_sym_pl_tag_text_token1 = 21,
  anon_sym_ATarg = 22,
  anon_sym_ATparam = 23,
  anon_sym_ATop = 24,
  anon_sym_ATerror = 25,
  anon_sym_ATauthor = 26,
  anon_sym_ATversion = 27,
  anon_sym_ATsee = 28,
  anon_sym_ATdeprecated = 29,
  anon_sym_ATcompat = 30,
  anon_sym_ATcopyright = 31,
  anon_sym_ATlicense = 32,
  anon_sym_ATbug = 33,
  anon_sym_ATtbd = 34,
  sym_source_file = 35,
  sym_comment = 36,
  sym__template = 37,
  sym_operator_template = 38,
  sym_functor_template = 39,
  sym_directive_template = 40,
  sym__head = 41,
  sym_arg_spec = 42,
  sym_type = 43,
  sym_pldoc_comment = 44,
  sym_pldoc_prolog_directive = 45,
  sym_pldoc_prolog_style = 46,
  sym_prolog_style_body = 47,
  sym_prolog_style_description = 48,
  sym_tag_name = 49,
  sym_pl_tag_text = 50,
  sym_pl_tag = 51,
  aux_sym_source_file_repeat1 = 52,
  aux_sym__head_repeat1 = 53,
  aux_sym_pldoc_prolog_style_repeat1 = 54,
  aux_sym_pldoc_prolog_style_repeat2 = 55,
  aux_sym_prolog_style_body_repeat1 = 56,
  aux_sym_prolog_style_description_repeat1 = 57,
  anon_alias_sym_name = 58,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
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
  [sym_arg_name_instantiation] = "arg_name_instantiation",
  [anon_sym_COLON] = ":",
  [sym_functor] = "functor",
  [aux_sym_type_token1] = "type_token1",
  [aux_sym_pldoc_prolog_directive_token1] = "comment_token",
  [anon_sym_PERCENT] = "%",
  [anon_sym_LF] = "\n",
  [aux_sym_prolog_style_description_token1] = "prolog_style_description_token1",
  [aux_sym_prolog_style_description_token2] = "prolog_style_description_token2",
  [aux_sym_pl_tag_text_token1] = "pl_tag_text_token1",
  [anon_sym_ATarg] = "@arg",
  [anon_sym_ATparam] = "@param",
  [anon_sym_ATop] = "@op",
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
  [sym_type] = "type",
  [sym_pldoc_comment] = "pldoc_comment",
  [sym_pldoc_prolog_directive] = "pldoc_prolog_directive",
  [sym_pldoc_prolog_style] = "pldoc_prolog_style",
  [sym_prolog_style_body] = "prolog_style_body",
  [sym_prolog_style_description] = "prolog_style_description",
  [sym_tag_name] = "tag_name",
  [sym_pl_tag_text] = "pl_tag_text",
  [sym_pl_tag] = "pl_tag",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym__head_repeat1] = "_head_repeat1",
  [aux_sym_pldoc_prolog_style_repeat1] = "pldoc_prolog_style_repeat1",
  [aux_sym_pldoc_prolog_style_repeat2] = "pldoc_prolog_style_repeat2",
  [aux_sym_prolog_style_body_repeat1] = "prolog_style_body_repeat1",
  [aux_sym_prolog_style_description_repeat1] = "prolog_style_description_repeat1",
  [anon_alias_sym_name] = "name",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
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
  [sym_arg_name_instantiation] = sym_arg_name_instantiation,
  [anon_sym_COLON] = anon_sym_COLON,
  [sym_functor] = sym_functor,
  [aux_sym_type_token1] = aux_sym_type_token1,
  [aux_sym_pldoc_prolog_directive_token1] = aux_sym_pldoc_prolog_directive_token1,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_LF] = anon_sym_LF,
  [aux_sym_prolog_style_description_token1] = aux_sym_prolog_style_description_token1,
  [aux_sym_prolog_style_description_token2] = aux_sym_prolog_style_description_token2,
  [aux_sym_pl_tag_text_token1] = aux_sym_pl_tag_text_token1,
  [anon_sym_ATarg] = anon_sym_ATarg,
  [anon_sym_ATparam] = anon_sym_ATparam,
  [anon_sym_ATop] = anon_sym_ATop,
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
  [sym_type] = sym_type,
  [sym_pldoc_comment] = sym_pldoc_comment,
  [sym_pldoc_prolog_directive] = sym_pldoc_prolog_directive,
  [sym_pldoc_prolog_style] = sym_pldoc_prolog_style,
  [sym_prolog_style_body] = sym_prolog_style_body,
  [sym_prolog_style_description] = sym_prolog_style_description,
  [sym_tag_name] = sym_tag_name,
  [sym_pl_tag_text] = sym_pl_tag_text,
  [sym_pl_tag] = sym_pl_tag,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym__head_repeat1] = aux_sym__head_repeat1,
  [aux_sym_pldoc_prolog_style_repeat1] = aux_sym_pldoc_prolog_style_repeat1,
  [aux_sym_pldoc_prolog_style_repeat2] = aux_sym_pldoc_prolog_style_repeat2,
  [aux_sym_prolog_style_body_repeat1] = aux_sym_prolog_style_body_repeat1,
  [aux_sym_prolog_style_description_repeat1] = aux_sym_prolog_style_description_repeat1,
  [anon_alias_sym_name] = anon_alias_sym_name,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
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
  [sym_arg_name_instantiation] = {
    .visible = true,
    .named = true,
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
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LF] = {
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
  [anon_sym_ATop] = {
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
  [anon_alias_sym_name] = {
    .visible = true,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_description = 1,
  field_fixity = 2,
  field_name = 3,
  field_precedence = 4,
  field_type = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_description] = "description",
  [field_fixity] = "fixity",
  [field_name] = "name",
  [field_precedence] = "precedence",
  [field_type] = "type",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 2},
  [6] = {.index = 6, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 0},
  [1] =
    {field_name, 0},
    {field_type, 2},
  [3] =
    {field_description, 1},
  [4] =
    {field_description, 2},
    {field_name, 1},
  [6] =
    {field_fixity, 1},
    {field_precedence, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [3] = {
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
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 14,
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
  [55] = 52,
  [56] = 28,
  [57] = 57,
  [58] = 58,
  [59] = 19,
  [60] = 18,
  [61] = 61,
  [62] = 62,
  [63] = 28,
  [64] = 64,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(105);
      ADVANCE_MAP(
        '%', 127,
        '(', 114,
        ')', 116,
        ',', 115,
        ':', 118,
        '@', 12,
        'd', 27,
        'f', 13,
        'i', 83,
        'm', 94,
        'n', 69,
        's', 28,
        'u', 60,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(1);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(4);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(131);
      if (lookahead == ' ') ADVANCE(126);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(131);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(130);
      if (lookahead == '@') ADVANCE(12);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(126);
      END_STATE();
    case 7:
      if (lookahead == '%') ADVANCE(128);
      if (lookahead == '+') ADVANCE(120);
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == ':') ADVANCE(122);
      if (lookahead == '!' ||
          lookahead == '?' ||
          lookahead == '@') ADVANCE(123);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('#' <= lookahead && lookahead <= '&') ||
          ('*' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(124);
      END_STATE();
    case 8:
      if (lookahead == '+') ADVANCE(120);
      if (lookahead == '-') ADVANCE(121);
      if (lookahead == '!' ||
          lookahead == ':' ||
          lookahead == '?' ||
          lookahead == '@') ADVANCE(123);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(8);
      if (lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(124);
      END_STATE();
    case 9:
      if (lookahead == '+') ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(117);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(102);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(117);
      END_STATE();
    case 11:
      if (lookahead == ':') ADVANCE(119);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(124);
      END_STATE();
    case 12:
      ADVANCE_MAP(
        'a', 73,
        'b', 95,
        'c', 65,
        'd', 34,
        'e', 77,
        'l', 48,
        'o', 70,
        'p', 15,
        's', 40,
        't', 18,
        'v', 36,
      );
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(50);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(78);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(89);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(93);
      END_STATE();
    case 18:
      if (lookahead == 'b') ADVANCE(21);
      END_STATE();
    case 19:
      if (lookahead == 'c') ADVANCE(33);
      END_STATE();
    case 20:
      if (lookahead == 'c') ADVANCE(17);
      END_STATE();
    case 21:
      if (lookahead == 'd') ADVANCE(147);
      END_STATE();
    case 22:
      if (lookahead == 'd') ADVANCE(112);
      END_STATE();
    case 23:
      if (lookahead == 'd') ADVANCE(142);
      END_STATE();
    case 24:
      if (lookahead == 'd') ADVANCE(30);
      END_STATE();
    case 25:
      if (lookahead == 'd') ADVANCE(37);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(41);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(86);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(58);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(141);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(109);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(145);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(72);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(20);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(76);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(88);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(22);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(29);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(90);
      END_STATE();
    case 42:
      if (lookahead == 'f') ADVANCE(51);
      END_STATE();
    case 43:
      if (lookahead == 'g') ADVANCE(135);
      END_STATE();
    case 44:
      if (lookahead == 'g') ADVANCE(146);
      END_STATE();
    case 45:
      if (lookahead == 'g') ADVANCE(46);
      END_STATE();
    case 46:
      if (lookahead == 'h') ADVANCE(91);
      END_STATE();
    case 47:
      if (lookahead == 'h') ADVANCE(68);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(19);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(111);
      END_STATE();
    case 50:
      if (lookahead == 'i') ADVANCE(55);
      END_STATE();
    case 51:
      if (lookahead == 'i') ADVANCE(64);
      END_STATE();
    case 52:
      if (lookahead == 'i') ADVANCE(45);
      END_STATE();
    case 53:
      if (lookahead == 'i') ADVANCE(66);
      END_STATE();
    case 54:
      if (lookahead == 'i') ADVANCE(26);
      END_STATE();
    case 55:
      if (lookahead == 'l') ADVANCE(96);
      END_STATE();
    case 56:
      if (lookahead == 'l') ADVANCE(92);
      END_STATE();
    case 57:
      if (lookahead == 'm') ADVANCE(136);
      END_STATE();
    case 58:
      if (lookahead == 'm') ADVANCE(54);
      END_STATE();
    case 59:
      if (lookahead == 'm') ADVANCE(71);
      if (lookahead == 'p') ADVANCE(97);
      END_STATE();
    case 60:
      if (lookahead == 'n') ADVANCE(24);
      END_STATE();
    case 61:
      if (lookahead == 'n') ADVANCE(140);
      END_STATE();
    case 62:
      if (lookahead == 'n') ADVANCE(85);
      END_STATE();
    case 63:
      if (lookahead == 'n') ADVANCE(25);
      END_STATE();
    case 64:
      if (lookahead == 'n') ADVANCE(38);
      END_STATE();
    case 65:
      if (lookahead == 'o') ADVANCE(59);
      END_STATE();
    case 66:
      if (lookahead == 'o') ADVANCE(61);
      END_STATE();
    case 67:
      if (lookahead == 'o') ADVANCE(74);
      END_STATE();
    case 68:
      if (lookahead == 'o') ADVANCE(75);
      END_STATE();
    case 69:
      if (lookahead == 'o') ADVANCE(63);
      END_STATE();
    case 70:
      if (lookahead == 'p') ADVANCE(137);
      END_STATE();
    case 71:
      if (lookahead == 'p') ADVANCE(16);
      END_STATE();
    case 72:
      if (lookahead == 'p') ADVANCE(81);
      END_STATE();
    case 73:
      if (lookahead == 'r') ADVANCE(43);
      if (lookahead == 'u') ADVANCE(87);
      END_STATE();
    case 74:
      if (lookahead == 'r') ADVANCE(138);
      END_STATE();
    case 75:
      if (lookahead == 'r') ADVANCE(139);
      END_STATE();
    case 76:
      if (lookahead == 'r') ADVANCE(84);
      END_STATE();
    case 77:
      if (lookahead == 'r') ADVANCE(79);
      END_STATE();
    case 78:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 79:
      if (lookahead == 'r') ADVANCE(67);
      END_STATE();
    case 80:
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(35);
      END_STATE();
    case 82:
      if (lookahead == 'r') ADVANCE(31);
      END_STATE();
    case 83:
      if (lookahead == 's') ADVANCE(106);
      END_STATE();
    case 84:
      if (lookahead == 's') ADVANCE(53);
      END_STATE();
    case 85:
      if (lookahead == 's') ADVANCE(32);
      END_STATE();
    case 86:
      if (lookahead == 't') ADVANCE(107);
      END_STATE();
    case 87:
      if (lookahead == 't') ADVANCE(47);
      END_STATE();
    case 88:
      if (lookahead == 't') ADVANCE(110);
      END_STATE();
    case 89:
      if (lookahead == 't') ADVANCE(143);
      END_STATE();
    case 90:
      if (lookahead == 't') ADVANCE(108);
      END_STATE();
    case 91:
      if (lookahead == 't') ADVANCE(144);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 93:
      if (lookahead == 't') ADVANCE(39);
      END_STATE();
    case 94:
      if (lookahead == 'u') ADVANCE(56);
      END_STATE();
    case 95:
      if (lookahead == 'u') ADVANCE(44);
      END_STATE();
    case 96:
      if (lookahead == 'u') ADVANCE(82);
      END_STATE();
    case 97:
      if (lookahead == 'y') ADVANCE(80);
      END_STATE();
    case 98:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(98);
      if (lookahead != 0) ADVANCE(125);
      END_STATE();
    case 99:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(133);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(134);
      END_STATE();
    case 100:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(100);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(124);
      END_STATE();
    case 101:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(99);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(134);
      END_STATE();
    case 102:
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(117);
      END_STATE();
    case 103:
      if (eof) ADVANCE(105);
      ADVANCE_MAP(
        '%', 129,
        '(', 114,
        ')', 116,
        '+', 9,
        ',', 115,
        '-', 10,
        'i', 83,
        '!', 102,
        ':', 102,
        '?', 102,
        '@', 102,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(103);
      END_STATE();
    case 104:
      if (eof) ADVANCE(105);
      if (lookahead == '%') ADVANCE(129);
      if (lookahead == ')') ADVANCE(116);
      if (lookahead == ',') ADVANCE(115);
      if (lookahead == ':') ADVANCE(118);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(104);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_is);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_det);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_semidet);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_failure);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_nondet);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_multi);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_undefined);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_COLON_DASH);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(124);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_arg_name_instantiation);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(117);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(124);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_functor);
      if (lookahead == '+') ADVANCE(123);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(117);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(124);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_functor);
      if (lookahead == '-') ADVANCE(123);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(117);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(124);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_functor);
      if (lookahead == '-') ADVANCE(113);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(117);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(124);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_functor);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(117);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(124);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_functor);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(124);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_type_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(125);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(aux_sym_pldoc_prolog_directive_token1);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(132);
      if (lookahead == '!') ADVANCE(3);
      if (lookahead == '%') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(1);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(4);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(1);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(4);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!') ADVANCE(6);
      if (lookahead == '%') ADVANCE(6);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(130);
      if (lookahead == '@') ADVANCE(12);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token1);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token2);
      if (lookahead == '\n') ADVANCE(132);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_pl_tag_text_token1);
      if (lookahead == '\n') ADVANCE(133);
      if (lookahead == '@') ADVANCE(134);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(133);
      if (lookahead != 0) ADVANCE(134);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(aux_sym_pl_tag_text_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(134);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_ATarg);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_ATparam);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_ATop);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_ATerror);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_ATauthor);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_ATversion);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_ATsee);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_ATdeprecated);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_ATcompat);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_ATcopyright);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_ATlicense);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(anon_sym_ATbug);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(anon_sym_ATtbd);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 5},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 7},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 7},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 103},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 8},
  [12] = {.lex_state = 103},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 104},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 103},
  [17] = {.lex_state = 103},
  [18] = {.lex_state = 103},
  [19] = {.lex_state = 103},
  [20] = {.lex_state = 103},
  [21] = {.lex_state = 103},
  [22] = {.lex_state = 103},
  [23] = {.lex_state = 103},
  [24] = {.lex_state = 103},
  [25] = {.lex_state = 103},
  [26] = {.lex_state = 103},
  [27] = {.lex_state = 7},
  [28] = {.lex_state = 103},
  [29] = {.lex_state = 103},
  [30] = {.lex_state = 7},
  [31] = {.lex_state = 103},
  [32] = {.lex_state = 103},
  [33] = {.lex_state = 103},
  [34] = {.lex_state = 103},
  [35] = {.lex_state = 7},
  [36] = {.lex_state = 103},
  [37] = {.lex_state = 103},
  [38] = {.lex_state = 7},
  [39] = {.lex_state = 103},
  [40] = {.lex_state = 7},
  [41] = {.lex_state = 103},
  [42] = {.lex_state = 103},
  [43] = {.lex_state = 11},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 98},
  [46] = {.lex_state = 98},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 101},
  [49] = {.lex_state = 101},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 98},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 98},
  [55] = {.lex_state = 98},
  [56] = {.lex_state = 101},
  [57] = {.lex_state = 7},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 100},
  [60] = {.lex_state = 100},
  [61] = {.lex_state = 100},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 98},
  [64] = {.lex_state = 5},
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
    [anon_sym_COLON] = ACTIONS(1),
    [aux_sym_pldoc_prolog_directive_token1] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [aux_sym_prolog_style_description_token1] = ACTIONS(1),
    [aux_sym_prolog_style_description_token2] = ACTIONS(1),
    [anon_sym_ATarg] = ACTIONS(1),
    [anon_sym_ATparam] = ACTIONS(1),
    [anon_sym_ATop] = ACTIONS(1),
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
    [sym_source_file] = STATE(58),
    [sym_comment] = STATE(5),
    [sym_pldoc_comment] = STATE(47),
    [sym_pldoc_prolog_directive] = STATE(12),
    [sym_pldoc_prolog_style] = STATE(51),
    [aux_sym_source_file_repeat1] = STATE(5),
    [aux_sym_pldoc_prolog_style_repeat1] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_pldoc_prolog_directive_token1] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(7), 1,
      anon_sym_LF,
    ACTIONS(11), 1,
      anon_sym_ATop,
    STATE(33), 1,
      sym_pl_tag,
    ACTIONS(9), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(13), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [26] = 4,
    ACTIONS(17), 1,
      anon_sym_ATop,
    STATE(33), 1,
      sym_pl_tag,
    ACTIONS(15), 5,
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
  [49] = 6,
    ACTIONS(21), 1,
      anon_sym_COLON_DASH,
    ACTIONS(23), 1,
      sym_arg_name_instantiation,
    ACTIONS(25), 1,
      sym_functor,
    STATE(20), 1,
      sym__head,
    STATE(61), 1,
      sym_arg_spec,
    STATE(37), 4,
      sym__template,
      sym_operator_template,
      sym_functor_template,
      sym_directive_template,
  [71] = 6,
    ACTIONS(5), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    STATE(47), 1,
      sym_pldoc_comment,
    STATE(51), 1,
      sym_pldoc_prolog_style,
    STATE(7), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(12), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [92] = 7,
    ACTIONS(29), 1,
      anon_sym_PERCENT,
    STATE(13), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(21), 1,
      sym_prolog_style_description,
    STATE(25), 1,
      aux_sym_prolog_style_body_repeat1,
    STATE(27), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    STATE(53), 1,
      sym_prolog_style_body,
    ACTIONS(31), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [115] = 6,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(35), 1,
      aux_sym_pldoc_prolog_directive_token1,
    STATE(47), 1,
      sym_pldoc_comment,
    STATE(51), 1,
      sym_pldoc_prolog_style,
    STATE(7), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(12), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [136] = 5,
    ACTIONS(40), 1,
      anon_sym_LPAREN,
    ACTIONS(42), 1,
      sym_arg_name_instantiation,
    ACTIONS(44), 1,
      anon_sym_PERCENT,
    STATE(36), 1,
      sym_arg_spec,
    ACTIONS(38), 3,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
  [154] = 6,
    ACTIONS(31), 1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(48), 1,
      anon_sym_PERCENT,
    ACTIONS(50), 1,
      aux_sym_prolog_style_description_token1,
    STATE(13), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(29), 1,
      sym_prolog_style_description,
    ACTIONS(46), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [174] = 1,
    ACTIONS(52), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [183] = 5,
    ACTIONS(23), 1,
      sym_arg_name_instantiation,
    ACTIONS(25), 1,
      sym_functor,
    STATE(20), 1,
      sym__head,
    STATE(61), 1,
      sym_arg_spec,
    STATE(34), 2,
      sym_operator_template,
      sym_functor_template,
  [200] = 5,
    ACTIONS(54), 1,
      ts_builtin_sym_end,
    ACTIONS(56), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(59), 1,
      anon_sym_PERCENT,
    STATE(6), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    STATE(17), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [217] = 5,
    ACTIONS(63), 1,
      anon_sym_PERCENT,
    ACTIONS(65), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(67), 1,
      aux_sym_prolog_style_description_token2,
    STATE(15), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(61), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [234] = 3,
    ACTIONS(71), 1,
      anon_sym_COLON,
    ACTIONS(73), 1,
      anon_sym_PERCENT,
    ACTIONS(69), 4,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
  [247] = 5,
    ACTIONS(77), 1,
      anon_sym_PERCENT,
    ACTIONS(79), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(82), 1,
      aux_sym_prolog_style_description_token2,
    STATE(15), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(75), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [264] = 4,
    ACTIONS(42), 1,
      sym_arg_name_instantiation,
    ACTIONS(87), 1,
      anon_sym_PERCENT,
    STATE(32), 1,
      sym_arg_spec,
    ACTIONS(85), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [278] = 4,
    ACTIONS(89), 1,
      ts_builtin_sym_end,
    ACTIONS(91), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(94), 1,
      anon_sym_PERCENT,
    STATE(17), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [292] = 2,
    ACTIONS(98), 1,
      anon_sym_PERCENT,
    ACTIONS(96), 4,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
  [302] = 2,
    ACTIONS(102), 1,
      anon_sym_PERCENT,
    ACTIONS(100), 4,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
  [312] = 3,
    ACTIONS(106), 1,
      anon_sym_is,
    ACTIONS(108), 1,
      anon_sym_PERCENT,
    ACTIONS(104), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [323] = 3,
    ACTIONS(112), 1,
      anon_sym_PERCENT,
    STATE(22), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(110), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [334] = 3,
    ACTIONS(112), 1,
      anon_sym_PERCENT,
    STATE(26), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(114), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [345] = 2,
    ACTIONS(118), 1,
      anon_sym_PERCENT,
    ACTIONS(116), 3,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
  [354] = 2,
    ACTIONS(122), 1,
      anon_sym_PERCENT,
    ACTIONS(120), 3,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
  [363] = 3,
    ACTIONS(112), 1,
      anon_sym_PERCENT,
    STATE(26), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(110), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [374] = 3,
    ACTIONS(126), 1,
      anon_sym_PERCENT,
    STATE(26), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(124), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [385] = 3,
    ACTIONS(129), 1,
      anon_sym_PERCENT,
    STATE(27), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(132), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [396] = 2,
    ACTIONS(136), 1,
      anon_sym_PERCENT,
    ACTIONS(134), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [404] = 2,
    ACTIONS(140), 1,
      anon_sym_PERCENT,
    ACTIONS(138), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [412] = 3,
    ACTIONS(42), 1,
      sym_arg_name_instantiation,
    STATE(38), 1,
      aux_sym__head_repeat1,
    STATE(44), 1,
      sym_arg_spec,
  [422] = 2,
    ACTIONS(144), 1,
      anon_sym_PERCENT,
    ACTIONS(142), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [430] = 2,
    ACTIONS(148), 1,
      anon_sym_PERCENT,
    ACTIONS(146), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [438] = 2,
    ACTIONS(150), 1,
      anon_sym_PERCENT,
    ACTIONS(124), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [446] = 2,
    ACTIONS(154), 1,
      anon_sym_PERCENT,
    ACTIONS(152), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [454] = 3,
    ACTIONS(42), 1,
      sym_arg_name_instantiation,
    STATE(30), 1,
      aux_sym__head_repeat1,
    STATE(50), 1,
      sym_arg_spec,
  [464] = 2,
    ACTIONS(87), 1,
      anon_sym_PERCENT,
    ACTIONS(85), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [472] = 2,
    ACTIONS(158), 1,
      anon_sym_PERCENT,
    ACTIONS(156), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [480] = 3,
    ACTIONS(160), 1,
      sym_arg_name_instantiation,
    STATE(38), 1,
      aux_sym__head_repeat1,
    STATE(62), 1,
      sym_arg_spec,
  [490] = 2,
    ACTIONS(165), 1,
      anon_sym_PERCENT,
    ACTIONS(163), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [498] = 2,
    ACTIONS(167), 1,
      anon_sym_PERCENT,
    ACTIONS(132), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [506] = 2,
    ACTIONS(171), 1,
      anon_sym_PERCENT,
    ACTIONS(169), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [514] = 2,
    ACTIONS(175), 1,
      anon_sym_PERCENT,
    ACTIONS(173), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [522] = 2,
    ACTIONS(73), 1,
      sym_functor,
    ACTIONS(177), 1,
      anon_sym_COLON,
  [529] = 2,
    ACTIONS(179), 1,
      anon_sym_COMMA,
    ACTIONS(181), 1,
      anon_sym_RPAREN,
  [536] = 2,
    ACTIONS(183), 1,
      aux_sym_type_token1,
    STATE(42), 1,
      sym_tag_name,
  [543] = 2,
    ACTIONS(185), 1,
      aux_sym_type_token1,
    STATE(45), 1,
      sym_tag_name,
  [550] = 1,
    ACTIONS(187), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [555] = 2,
    ACTIONS(189), 1,
      aux_sym_pl_tag_text_token1,
    STATE(39), 1,
      sym_pl_tag_text,
  [562] = 2,
    ACTIONS(189), 1,
      aux_sym_pl_tag_text_token1,
    STATE(41), 1,
      sym_pl_tag_text,
  [569] = 2,
    ACTIONS(179), 1,
      anon_sym_COMMA,
    ACTIONS(191), 1,
      anon_sym_RPAREN,
  [576] = 1,
    ACTIONS(193), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [581] = 2,
    ACTIONS(195), 1,
      aux_sym_type_token1,
    STATE(60), 1,
      sym_type,
  [588] = 1,
    ACTIONS(197), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [593] = 2,
    ACTIONS(199), 1,
      aux_sym_type_token1,
    STATE(49), 1,
      sym_tag_name,
  [600] = 2,
    ACTIONS(201), 1,
      aux_sym_type_token1,
    STATE(18), 1,
      sym_type,
  [607] = 1,
    ACTIONS(134), 1,
      aux_sym_pl_tag_text_token1,
  [611] = 1,
    ACTIONS(203), 1,
      sym_arg_name_instantiation,
  [615] = 1,
    ACTIONS(205), 1,
      ts_builtin_sym_end,
  [619] = 1,
    ACTIONS(100), 1,
      sym_functor,
  [623] = 1,
    ACTIONS(96), 1,
      sym_functor,
  [627] = 1,
    ACTIONS(207), 1,
      sym_functor,
  [631] = 1,
    ACTIONS(179), 1,
      anon_sym_COMMA,
  [635] = 1,
    ACTIONS(134), 1,
      aux_sym_type_token1,
  [639] = 1,
    ACTIONS(209), 1,
      anon_sym_LF,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 26,
  [SMALL_STATE(4)] = 49,
  [SMALL_STATE(5)] = 71,
  [SMALL_STATE(6)] = 92,
  [SMALL_STATE(7)] = 115,
  [SMALL_STATE(8)] = 136,
  [SMALL_STATE(9)] = 154,
  [SMALL_STATE(10)] = 174,
  [SMALL_STATE(11)] = 183,
  [SMALL_STATE(12)] = 200,
  [SMALL_STATE(13)] = 217,
  [SMALL_STATE(14)] = 234,
  [SMALL_STATE(15)] = 247,
  [SMALL_STATE(16)] = 264,
  [SMALL_STATE(17)] = 278,
  [SMALL_STATE(18)] = 292,
  [SMALL_STATE(19)] = 302,
  [SMALL_STATE(20)] = 312,
  [SMALL_STATE(21)] = 323,
  [SMALL_STATE(22)] = 334,
  [SMALL_STATE(23)] = 345,
  [SMALL_STATE(24)] = 354,
  [SMALL_STATE(25)] = 363,
  [SMALL_STATE(26)] = 374,
  [SMALL_STATE(27)] = 385,
  [SMALL_STATE(28)] = 396,
  [SMALL_STATE(29)] = 404,
  [SMALL_STATE(30)] = 412,
  [SMALL_STATE(31)] = 422,
  [SMALL_STATE(32)] = 430,
  [SMALL_STATE(33)] = 438,
  [SMALL_STATE(34)] = 446,
  [SMALL_STATE(35)] = 454,
  [SMALL_STATE(36)] = 464,
  [SMALL_STATE(37)] = 472,
  [SMALL_STATE(38)] = 480,
  [SMALL_STATE(39)] = 490,
  [SMALL_STATE(40)] = 498,
  [SMALL_STATE(41)] = 506,
  [SMALL_STATE(42)] = 514,
  [SMALL_STATE(43)] = 522,
  [SMALL_STATE(44)] = 529,
  [SMALL_STATE(45)] = 536,
  [SMALL_STATE(46)] = 543,
  [SMALL_STATE(47)] = 550,
  [SMALL_STATE(48)] = 555,
  [SMALL_STATE(49)] = 562,
  [SMALL_STATE(50)] = 569,
  [SMALL_STATE(51)] = 576,
  [SMALL_STATE(52)] = 581,
  [SMALL_STATE(53)] = 588,
  [SMALL_STATE(54)] = 593,
  [SMALL_STATE(55)] = 600,
  [SMALL_STATE(56)] = 607,
  [SMALL_STATE(57)] = 611,
  [SMALL_STATE(58)] = 615,
  [SMALL_STATE(59)] = 619,
  [SMALL_STATE(60)] = 623,
  [SMALL_STATE(61)] = 627,
  [SMALL_STATE(62)] = 631,
  [SMALL_STATE(63)] = 635,
  [SMALL_STATE(64)] = 639,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 1, 0, 0),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [44] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 1, 0, 0),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag_text, 1, 0, 0),
  [48] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag_text, 1, 0, 0),
  [50] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(4),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(64),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 1, 0, 1),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 1, 0, 1),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [82] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 2, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 2, 0, 0),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 3, 0, 2),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 3, 0, 2),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1, 0, 0),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 1, 0, 0),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 1, 0, 0),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 1, 0, 0),
  [112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 2, 0, 0),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 4, 0, 0),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 4, 0, 0),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 5, 0, 0),
  [122] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 5, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [126] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [129] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0), SHIFT_REPEAT(64),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag_name, 1, 0, 3),
  [136] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_tag_name, 1, 0, 3),
  [138] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag_text, 2, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag_text, 2, 0, 0),
  [142] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 3, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 3, 0, 0),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 3, 0, 0),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 3, 0, 0),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive_template, 2, 0, 0),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive_template, 2, 0, 0),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [160] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 2, 0, 4),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 2, 0, 4),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 3, 0, 5),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 3, 0, 5),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 3, 0, 6),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 3, 0, 6),
  [177] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
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
