#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 60
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 57
#define ALIAS_COUNT 1
#define TOKEN_COUNT 34
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 6

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
  anon_sym_ATerror = 24,
  anon_sym_ATauthor = 25,
  anon_sym_ATversion = 26,
  anon_sym_ATsee = 27,
  anon_sym_ATdeprecated = 28,
  anon_sym_ATcompat = 29,
  anon_sym_ATcopyright = 30,
  anon_sym_ATlicense = 31,
  anon_sym_ATbug = 32,
  anon_sym_ATtbd = 33,
  sym_source_file = 34,
  sym_comment = 35,
  sym__template = 36,
  sym_operator_template = 37,
  sym_functor_template = 38,
  sym_directive_template = 39,
  sym__head = 40,
  sym_arg_spec = 41,
  sym_type = 42,
  sym_pldoc_comment = 43,
  sym_pldoc_prolog_directive = 44,
  sym_pldoc_prolog_style = 45,
  sym_prolog_style_body = 46,
  sym_prolog_style_description = 47,
  sym_tag_name = 48,
  sym_pl_tag_text = 49,
  sym_pl_tag = 50,
  aux_sym_source_file_repeat1 = 51,
  aux_sym__head_repeat1 = 52,
  aux_sym_pldoc_prolog_style_repeat1 = 53,
  aux_sym_pldoc_prolog_style_repeat2 = 54,
  aux_sym_prolog_style_body_repeat1 = 55,
  aux_sym_prolog_style_description_repeat1 = 56,
  anon_alias_sym_name = 57,
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
  [2] = {.index = 1, .length = 2},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 2},
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
  [43] = 43,
  [44] = 44,
  [45] = 15,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 49,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 18,
  [57] = 19,
  [58] = 58,
  [59] = 59,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(104);
      ADVANCE_MAP(
        '%', 126,
        '(', 113,
        ')', 115,
        ',', 114,
        ':', 117,
        '@', 12,
        'd', 27,
        'f', 13,
        'i', 82,
        'm', 93,
        'n', 69,
        's', 28,
        'u', 60,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(131);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(1);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(4);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(131);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(130);
      if (lookahead == ' ') ADVANCE(125);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(130);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(129);
      if (lookahead == '@') ADVANCE(12);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      END_STATE();
    case 6:
      if (lookahead == ' ') ADVANCE(125);
      END_STATE();
    case 7:
      if (lookahead == '%') ADVANCE(127);
      if (lookahead == '+') ADVANCE(119);
      if (lookahead == '-') ADVANCE(120);
      if (lookahead == ':') ADVANCE(121);
      if (lookahead == '!' ||
          lookahead == '?' ||
          lookahead == '@') ADVANCE(122);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7);
      if (('#' <= lookahead && lookahead <= '&') ||
          ('*' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(123);
      END_STATE();
    case 8:
      if (lookahead == '+') ADVANCE(119);
      if (lookahead == '-') ADVANCE(120);
      if (lookahead == '!' ||
          lookahead == ':' ||
          lookahead == '?' ||
          lookahead == '@') ADVANCE(122);
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
          lookahead == '~') ADVANCE(123);
      END_STATE();
    case 9:
      if (lookahead == '+') ADVANCE(101);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(116);
      END_STATE();
    case 10:
      if (lookahead == '-') ADVANCE(101);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(116);
      END_STATE();
    case 11:
      if (lookahead == ':') ADVANCE(118);
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
          lookahead == '~') ADVANCE(123);
      END_STATE();
    case 12:
      ADVANCE_MAP(
        'a', 72,
        'b', 94,
        'c', 65,
        'd', 29,
        'e', 76,
        'l', 48,
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
      if (lookahead == 'a') ADVANCE(77);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(88);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(92);
      END_STATE();
    case 18:
      if (lookahead == 'b') ADVANCE(21);
      END_STATE();
    case 19:
      if (lookahead == 'c') ADVANCE(34);
      END_STATE();
    case 20:
      if (lookahead == 'c') ADVANCE(17);
      END_STATE();
    case 21:
      if (lookahead == 'd') ADVANCE(145);
      END_STATE();
    case 22:
      if (lookahead == 'd') ADVANCE(111);
      END_STATE();
    case 23:
      if (lookahead == 'd') ADVANCE(140);
      END_STATE();
    case 24:
      if (lookahead == 'd') ADVANCE(31);
      END_STATE();
    case 25:
      if (lookahead == 'd') ADVANCE(37);
      END_STATE();
    case 26:
      if (lookahead == 'd') ADVANCE(41);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(85);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(59);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(71);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(139);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(108);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(143);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(20);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(75);
      END_STATE();
    case 37:
      if (lookahead == 'e') ADVANCE(87);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(22);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(23);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(30);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(89);
      END_STATE();
    case 42:
      if (lookahead == 'f') ADVANCE(51);
      END_STATE();
    case 43:
      if (lookahead == 'g') ADVANCE(134);
      END_STATE();
    case 44:
      if (lookahead == 'g') ADVANCE(144);
      END_STATE();
    case 45:
      if (lookahead == 'g') ADVANCE(46);
      END_STATE();
    case 46:
      if (lookahead == 'h') ADVANCE(90);
      END_STATE();
    case 47:
      if (lookahead == 'h') ADVANCE(68);
      END_STATE();
    case 48:
      if (lookahead == 'i') ADVANCE(19);
      END_STATE();
    case 49:
      if (lookahead == 'i') ADVANCE(110);
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
      if (lookahead == 'l') ADVANCE(95);
      END_STATE();
    case 56:
      if (lookahead == 'l') ADVANCE(91);
      END_STATE();
    case 57:
      if (lookahead == 'm') ADVANCE(135);
      END_STATE();
    case 58:
      if (lookahead == 'm') ADVANCE(70);
      if (lookahead == 'p') ADVANCE(96);
      END_STATE();
    case 59:
      if (lookahead == 'm') ADVANCE(54);
      END_STATE();
    case 60:
      if (lookahead == 'n') ADVANCE(24);
      END_STATE();
    case 61:
      if (lookahead == 'n') ADVANCE(138);
      END_STATE();
    case 62:
      if (lookahead == 'n') ADVANCE(84);
      END_STATE();
    case 63:
      if (lookahead == 'n') ADVANCE(25);
      END_STATE();
    case 64:
      if (lookahead == 'n') ADVANCE(38);
      END_STATE();
    case 65:
      if (lookahead == 'o') ADVANCE(58);
      END_STATE();
    case 66:
      if (lookahead == 'o') ADVANCE(61);
      END_STATE();
    case 67:
      if (lookahead == 'o') ADVANCE(73);
      END_STATE();
    case 68:
      if (lookahead == 'o') ADVANCE(74);
      END_STATE();
    case 69:
      if (lookahead == 'o') ADVANCE(63);
      END_STATE();
    case 70:
      if (lookahead == 'p') ADVANCE(16);
      END_STATE();
    case 71:
      if (lookahead == 'p') ADVANCE(80);
      END_STATE();
    case 72:
      if (lookahead == 'r') ADVANCE(43);
      if (lookahead == 'u') ADVANCE(86);
      END_STATE();
    case 73:
      if (lookahead == 'r') ADVANCE(136);
      END_STATE();
    case 74:
      if (lookahead == 'r') ADVANCE(137);
      END_STATE();
    case 75:
      if (lookahead == 'r') ADVANCE(83);
      END_STATE();
    case 76:
      if (lookahead == 'r') ADVANCE(78);
      END_STATE();
    case 77:
      if (lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 78:
      if (lookahead == 'r') ADVANCE(67);
      END_STATE();
    case 79:
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 80:
      if (lookahead == 'r') ADVANCE(35);
      END_STATE();
    case 81:
      if (lookahead == 'r') ADVANCE(32);
      END_STATE();
    case 82:
      if (lookahead == 's') ADVANCE(105);
      END_STATE();
    case 83:
      if (lookahead == 's') ADVANCE(53);
      END_STATE();
    case 84:
      if (lookahead == 's') ADVANCE(33);
      END_STATE();
    case 85:
      if (lookahead == 't') ADVANCE(106);
      END_STATE();
    case 86:
      if (lookahead == 't') ADVANCE(47);
      END_STATE();
    case 87:
      if (lookahead == 't') ADVANCE(109);
      END_STATE();
    case 88:
      if (lookahead == 't') ADVANCE(141);
      END_STATE();
    case 89:
      if (lookahead == 't') ADVANCE(107);
      END_STATE();
    case 90:
      if (lookahead == 't') ADVANCE(142);
      END_STATE();
    case 91:
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 92:
      if (lookahead == 't') ADVANCE(39);
      END_STATE();
    case 93:
      if (lookahead == 'u') ADVANCE(56);
      END_STATE();
    case 94:
      if (lookahead == 'u') ADVANCE(44);
      END_STATE();
    case 95:
      if (lookahead == 'u') ADVANCE(81);
      END_STATE();
    case 96:
      if (lookahead == 'y') ADVANCE(79);
      END_STATE();
    case 97:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(132);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(133);
      END_STATE();
    case 98:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(98);
      if (lookahead != 0) ADVANCE(124);
      END_STATE();
    case 99:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(99);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= 'Z') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(123);
      END_STATE();
    case 100:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(97);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(133);
      END_STATE();
    case 101:
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(116);
      END_STATE();
    case 102:
      if (eof) ADVANCE(104);
      ADVANCE_MAP(
        '%', 128,
        '(', 113,
        ')', 115,
        '+', 9,
        ',', 114,
        '-', 10,
        'i', 82,
        '!', 101,
        ':', 101,
        '?', 101,
        '@', 101,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(102);
      END_STATE();
    case 103:
      if (eof) ADVANCE(104);
      if (lookahead == '%') ADVANCE(128);
      if (lookahead == ')') ADVANCE(115);
      if (lookahead == ',') ADVANCE(114);
      if (lookahead == ':') ADVANCE(117);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(103);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_is);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_det);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_semidet);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_failure);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_nondet);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_multi);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_undefined);
      END_STATE();
    case 112:
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
          lookahead == '~') ADVANCE(123);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_arg_name_instantiation);
      if (lookahead == '$' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(116);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 118:
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
          lookahead == '~') ADVANCE(123);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_functor);
      if (lookahead == '+') ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(116);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(123);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_functor);
      if (lookahead == '-') ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(116);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(123);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_functor);
      if (lookahead == '-') ADVANCE(112);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(116);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(123);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_functor);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(116);
      if (lookahead == '!' ||
          lookahead == '#' ||
          lookahead == '$' ||
          lookahead == '&' ||
          ('*' <= lookahead && lookahead <= '@') ||
          lookahead == '\\' ||
          lookahead == '^' ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z') ||
          lookahead == '~') ADVANCE(123);
      END_STATE();
    case 123:
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
          lookahead == '~') ADVANCE(123);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(aux_sym_type_token1);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          lookahead != ' ') ADVANCE(124);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(aux_sym_pldoc_prolog_directive_token1);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(131);
      if (lookahead == '!') ADVANCE(3);
      if (lookahead == '%') ADVANCE(3);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(1);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(4);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '\n') ADVANCE(131);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(1);
      if (lookahead != 0 &&
          lookahead != '@') ADVANCE(4);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '!') ADVANCE(6);
      if (lookahead == '%') ADVANCE(6);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(129);
      if (lookahead == '@') ADVANCE(12);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token1);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(aux_sym_prolog_style_description_token2);
      if (lookahead == '\n') ADVANCE(131);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(2);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(aux_sym_pl_tag_text_token1);
      if (lookahead == '\n') ADVANCE(132);
      if (lookahead == '@') ADVANCE(133);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(132);
      if (lookahead != 0) ADVANCE(133);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(aux_sym_pl_tag_text_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(133);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(anon_sym_ATarg);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(anon_sym_ATparam);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_ATerror);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_ATauthor);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(anon_sym_ATversion);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_ATsee);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_ATdeprecated);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(anon_sym_ATcompat);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(anon_sym_ATcopyright);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_ATlicense);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_ATbug);
      END_STATE();
    case 145:
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
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 7},
  [8] = {.lex_state = 102},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 102},
  [11] = {.lex_state = 8},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 103},
  [16] = {.lex_state = 102},
  [17] = {.lex_state = 102},
  [18] = {.lex_state = 102},
  [19] = {.lex_state = 102},
  [20] = {.lex_state = 7},
  [21] = {.lex_state = 102},
  [22] = {.lex_state = 102},
  [23] = {.lex_state = 102},
  [24] = {.lex_state = 102},
  [25] = {.lex_state = 102},
  [26] = {.lex_state = 102},
  [27] = {.lex_state = 102},
  [28] = {.lex_state = 7},
  [29] = {.lex_state = 102},
  [30] = {.lex_state = 7},
  [31] = {.lex_state = 7},
  [32] = {.lex_state = 102},
  [33] = {.lex_state = 102},
  [34] = {.lex_state = 102},
  [35] = {.lex_state = 7},
  [36] = {.lex_state = 102},
  [37] = {.lex_state = 102},
  [38] = {.lex_state = 102},
  [39] = {.lex_state = 102},
  [40] = {.lex_state = 102},
  [41] = {.lex_state = 100},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 11},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 98},
  [48] = {.lex_state = 100},
  [49] = {.lex_state = 98},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 98},
  [52] = {.lex_state = 7},
  [53] = {.lex_state = 100},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 99},
  [56] = {.lex_state = 99},
  [57] = {.lex_state = 99},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 5},
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
    [sym_source_file] = STATE(54),
    [sym_comment] = STATE(5),
    [sym_pldoc_comment] = STATE(42),
    [sym_pldoc_prolog_directive] = STATE(10),
    [sym_pldoc_prolog_style] = STATE(43),
    [aux_sym_source_file_repeat1] = STATE(5),
    [aux_sym_pldoc_prolog_style_repeat1] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_pldoc_prolog_directive_token1] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(7), 1,
      anon_sym_LF,
    STATE(34), 1,
      sym_pl_tag,
    ACTIONS(9), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(11), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [23] = 3,
    STATE(34), 1,
      sym_pl_tag,
    ACTIONS(13), 5,
      anon_sym_ATarg,
      anon_sym_ATparam,
      anon_sym_ATerror,
      anon_sym_ATauthor,
      anon_sym_ATversion,
    ACTIONS(15), 7,
      anon_sym_ATsee,
      anon_sym_ATdeprecated,
      anon_sym_ATcompat,
      anon_sym_ATcopyright,
      anon_sym_ATlicense,
      anon_sym_ATbug,
      anon_sym_ATtbd,
  [43] = 6,
    ACTIONS(17), 1,
      anon_sym_COLON_DASH,
    ACTIONS(19), 1,
      sym_arg_name_instantiation,
    ACTIONS(21), 1,
      sym_functor,
    STATE(21), 1,
      sym__head,
    STATE(55), 1,
      sym_arg_spec,
    STATE(29), 4,
      sym__template,
      sym_operator_template,
      sym_functor_template,
      sym_directive_template,
  [65] = 6,
    ACTIONS(5), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(23), 1,
      ts_builtin_sym_end,
    STATE(42), 1,
      sym_pldoc_comment,
    STATE(43), 1,
      sym_pldoc_prolog_style,
    STATE(6), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(10), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [86] = 6,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
    ACTIONS(27), 1,
      aux_sym_pldoc_prolog_directive_token1,
    STATE(42), 1,
      sym_pldoc_comment,
    STATE(43), 1,
      sym_pldoc_prolog_style,
    STATE(6), 2,
      sym_comment,
      aux_sym_source_file_repeat1,
    STATE(10), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [107] = 7,
    ACTIONS(30), 1,
      anon_sym_PERCENT,
    STATE(13), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(20), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    STATE(22), 1,
      sym_prolog_style_description,
    STATE(23), 1,
      aux_sym_prolog_style_body_repeat1,
    STATE(44), 1,
      sym_prolog_style_body,
    ACTIONS(32), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [130] = 5,
    ACTIONS(36), 1,
      anon_sym_LPAREN,
    ACTIONS(38), 1,
      sym_arg_name_instantiation,
    ACTIONS(40), 1,
      anon_sym_PERCENT,
    STATE(36), 1,
      sym_arg_spec,
    ACTIONS(34), 3,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
  [148] = 6,
    ACTIONS(32), 1,
      aux_sym_prolog_style_description_token2,
    ACTIONS(44), 1,
      anon_sym_PERCENT,
    ACTIONS(46), 1,
      aux_sym_prolog_style_description_token1,
    STATE(13), 1,
      aux_sym_prolog_style_description_repeat1,
    STATE(39), 1,
      sym_prolog_style_description,
    ACTIONS(42), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [168] = 5,
    ACTIONS(48), 1,
      ts_builtin_sym_end,
    ACTIONS(50), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(53), 1,
      anon_sym_PERCENT,
    STATE(7), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    STATE(16), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [185] = 5,
    ACTIONS(19), 1,
      sym_arg_name_instantiation,
    ACTIONS(21), 1,
      sym_functor,
    STATE(21), 1,
      sym__head,
    STATE(55), 1,
      sym_arg_spec,
    STATE(40), 2,
      sym_operator_template,
      sym_functor_template,
  [202] = 1,
    ACTIONS(55), 6,
      anon_sym_det,
      anon_sym_semidet,
      anon_sym_failure,
      anon_sym_nondet,
      anon_sym_multi,
      anon_sym_undefined,
  [211] = 5,
    ACTIONS(59), 1,
      anon_sym_PERCENT,
    ACTIONS(61), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(63), 1,
      aux_sym_prolog_style_description_token2,
    STATE(14), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(57), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [228] = 5,
    ACTIONS(67), 1,
      anon_sym_PERCENT,
    ACTIONS(69), 1,
      aux_sym_prolog_style_description_token1,
    ACTIONS(72), 1,
      aux_sym_prolog_style_description_token2,
    STATE(14), 1,
      aux_sym_prolog_style_description_repeat1,
    ACTIONS(65), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [245] = 3,
    ACTIONS(77), 1,
      anon_sym_COLON,
    ACTIONS(79), 1,
      anon_sym_PERCENT,
    ACTIONS(75), 4,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
  [258] = 4,
    ACTIONS(81), 1,
      ts_builtin_sym_end,
    ACTIONS(83), 1,
      aux_sym_pldoc_prolog_directive_token1,
    ACTIONS(86), 1,
      anon_sym_PERCENT,
    STATE(16), 2,
      sym_pldoc_prolog_directive,
      aux_sym_pldoc_prolog_style_repeat1,
  [272] = 4,
    ACTIONS(38), 1,
      sym_arg_name_instantiation,
    ACTIONS(90), 1,
      anon_sym_PERCENT,
    STATE(33), 1,
      sym_arg_spec,
    ACTIONS(88), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [286] = 2,
    ACTIONS(94), 1,
      anon_sym_PERCENT,
    ACTIONS(92), 4,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
  [296] = 2,
    ACTIONS(98), 1,
      anon_sym_PERCENT,
    ACTIONS(96), 4,
      ts_builtin_sym_end,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      aux_sym_pldoc_prolog_directive_token1,
  [306] = 3,
    ACTIONS(100), 1,
      anon_sym_PERCENT,
    STATE(20), 1,
      aux_sym_pldoc_prolog_style_repeat2,
    ACTIONS(103), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [317] = 3,
    ACTIONS(107), 1,
      anon_sym_is,
    ACTIONS(109), 1,
      anon_sym_PERCENT,
    ACTIONS(105), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [328] = 3,
    ACTIONS(113), 1,
      anon_sym_PERCENT,
    STATE(24), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(111), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [339] = 3,
    ACTIONS(113), 1,
      anon_sym_PERCENT,
    STATE(25), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(111), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [350] = 3,
    ACTIONS(113), 1,
      anon_sym_PERCENT,
    STATE(25), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(115), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [361] = 3,
    ACTIONS(119), 1,
      anon_sym_PERCENT,
    STATE(25), 1,
      aux_sym_prolog_style_body_repeat1,
    ACTIONS(117), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [372] = 2,
    ACTIONS(124), 1,
      anon_sym_PERCENT,
    ACTIONS(122), 3,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
  [381] = 2,
    ACTIONS(128), 1,
      anon_sym_PERCENT,
    ACTIONS(126), 3,
      ts_builtin_sym_end,
      anon_sym_is,
      aux_sym_pldoc_prolog_directive_token1,
  [390] = 3,
    ACTIONS(38), 1,
      sym_arg_name_instantiation,
    STATE(31), 1,
      aux_sym__head_repeat1,
    STATE(50), 1,
      sym_arg_spec,
  [400] = 2,
    ACTIONS(132), 1,
      anon_sym_PERCENT,
    ACTIONS(130), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [408] = 2,
    ACTIONS(134), 1,
      anon_sym_PERCENT,
    ACTIONS(103), 2,
      aux_sym_prolog_style_description_token1,
      aux_sym_prolog_style_description_token2,
  [416] = 3,
    ACTIONS(38), 1,
      sym_arg_name_instantiation,
    STATE(35), 1,
      aux_sym__head_repeat1,
    STATE(46), 1,
      sym_arg_spec,
  [426] = 2,
    ACTIONS(138), 1,
      anon_sym_PERCENT,
    ACTIONS(136), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [434] = 2,
    ACTIONS(142), 1,
      anon_sym_PERCENT,
    ACTIONS(140), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [442] = 2,
    ACTIONS(144), 1,
      anon_sym_PERCENT,
    ACTIONS(117), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [450] = 3,
    ACTIONS(146), 1,
      sym_arg_name_instantiation,
    STATE(35), 1,
      aux_sym__head_repeat1,
    STATE(58), 1,
      sym_arg_spec,
  [460] = 2,
    ACTIONS(90), 1,
      anon_sym_PERCENT,
    ACTIONS(88), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [468] = 2,
    ACTIONS(151), 1,
      anon_sym_PERCENT,
    ACTIONS(149), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [476] = 2,
    ACTIONS(155), 1,
      anon_sym_PERCENT,
    ACTIONS(153), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [484] = 2,
    ACTIONS(159), 1,
      anon_sym_PERCENT,
    ACTIONS(157), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [492] = 2,
    ACTIONS(163), 1,
      anon_sym_PERCENT,
    ACTIONS(161), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [500] = 2,
    ACTIONS(165), 1,
      aux_sym_pl_tag_text_token1,
    STATE(38), 1,
      sym_pl_tag_text,
  [507] = 1,
    ACTIONS(167), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [512] = 1,
    ACTIONS(169), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [517] = 1,
    ACTIONS(171), 2,
      ts_builtin_sym_end,
      aux_sym_pldoc_prolog_directive_token1,
  [522] = 2,
    ACTIONS(79), 1,
      sym_functor,
    ACTIONS(173), 1,
      anon_sym_COLON,
  [529] = 2,
    ACTIONS(175), 1,
      anon_sym_COMMA,
    ACTIONS(177), 1,
      anon_sym_RPAREN,
  [536] = 2,
    ACTIONS(179), 1,
      aux_sym_type_token1,
    STATE(41), 1,
      sym_tag_name,
  [543] = 2,
    ACTIONS(165), 1,
      aux_sym_pl_tag_text_token1,
    STATE(37), 1,
      sym_pl_tag_text,
  [550] = 2,
    ACTIONS(181), 1,
      aux_sym_type_token1,
    STATE(19), 1,
      sym_type,
  [557] = 2,
    ACTIONS(175), 1,
      anon_sym_COMMA,
    ACTIONS(183), 1,
      anon_sym_RPAREN,
  [564] = 2,
    ACTIONS(185), 1,
      aux_sym_type_token1,
    STATE(57), 1,
      sym_type,
  [571] = 1,
    ACTIONS(187), 1,
      sym_arg_name_instantiation,
  [575] = 1,
    ACTIONS(189), 1,
      aux_sym_pl_tag_text_token1,
  [579] = 1,
    ACTIONS(191), 1,
      ts_builtin_sym_end,
  [583] = 1,
    ACTIONS(193), 1,
      sym_functor,
  [587] = 1,
    ACTIONS(92), 1,
      sym_functor,
  [591] = 1,
    ACTIONS(96), 1,
      sym_functor,
  [595] = 1,
    ACTIONS(175), 1,
      anon_sym_COMMA,
  [599] = 1,
    ACTIONS(195), 1,
      anon_sym_LF,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 23,
  [SMALL_STATE(4)] = 43,
  [SMALL_STATE(5)] = 65,
  [SMALL_STATE(6)] = 86,
  [SMALL_STATE(7)] = 107,
  [SMALL_STATE(8)] = 130,
  [SMALL_STATE(9)] = 148,
  [SMALL_STATE(10)] = 168,
  [SMALL_STATE(11)] = 185,
  [SMALL_STATE(12)] = 202,
  [SMALL_STATE(13)] = 211,
  [SMALL_STATE(14)] = 228,
  [SMALL_STATE(15)] = 245,
  [SMALL_STATE(16)] = 258,
  [SMALL_STATE(17)] = 272,
  [SMALL_STATE(18)] = 286,
  [SMALL_STATE(19)] = 296,
  [SMALL_STATE(20)] = 306,
  [SMALL_STATE(21)] = 317,
  [SMALL_STATE(22)] = 328,
  [SMALL_STATE(23)] = 339,
  [SMALL_STATE(24)] = 350,
  [SMALL_STATE(25)] = 361,
  [SMALL_STATE(26)] = 372,
  [SMALL_STATE(27)] = 381,
  [SMALL_STATE(28)] = 390,
  [SMALL_STATE(29)] = 400,
  [SMALL_STATE(30)] = 408,
  [SMALL_STATE(31)] = 416,
  [SMALL_STATE(32)] = 426,
  [SMALL_STATE(33)] = 434,
  [SMALL_STATE(34)] = 442,
  [SMALL_STATE(35)] = 450,
  [SMALL_STATE(36)] = 460,
  [SMALL_STATE(37)] = 468,
  [SMALL_STATE(38)] = 476,
  [SMALL_STATE(39)] = 484,
  [SMALL_STATE(40)] = 492,
  [SMALL_STATE(41)] = 500,
  [SMALL_STATE(42)] = 507,
  [SMALL_STATE(43)] = 512,
  [SMALL_STATE(44)] = 517,
  [SMALL_STATE(45)] = 522,
  [SMALL_STATE(46)] = 529,
  [SMALL_STATE(47)] = 536,
  [SMALL_STATE(48)] = 543,
  [SMALL_STATE(49)] = 550,
  [SMALL_STATE(50)] = 557,
  [SMALL_STATE(51)] = 564,
  [SMALL_STATE(52)] = 571,
  [SMALL_STATE(53)] = 575,
  [SMALL_STATE(54)] = 579,
  [SMALL_STATE(55)] = 583,
  [SMALL_STATE(56)] = 587,
  [SMALL_STATE(57)] = 591,
  [SMALL_STATE(58)] = 595,
  [SMALL_STATE(59)] = 599,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [27] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [30] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 1, 0, 0),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [38] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [40] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 1, 0, 0),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag_text, 1, 0, 0),
  [44] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag_text, 1, 0, 0),
  [46] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 1, 0, 0), SHIFT(4),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(59),
  [55] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prolog_style_description, 1, 0, 0),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [72] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prolog_style_description_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 1, 0, 1),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 1, 0, 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0), SHIFT_REPEAT(4),
  [86] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat1, 2, 0, 0),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 2, 0, 0),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 2, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type, 1, 0, 0),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_arg_spec, 3, 0, 2),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_arg_spec, 3, 0, 2),
  [100] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0), SHIFT_REPEAT(59),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [105] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 1, 0, 0),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [109] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 1, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 1, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prolog_style_body, 2, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [119] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 4, 0, 0),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 4, 0, 0),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__head, 5, 0, 0),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__head, 5, 0, 0),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pldoc_prolog_directive, 2, 0, 0),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_pldoc_prolog_style_repeat2, 2, 0, 0),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_functor_template, 3, 0, 0),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_functor_template, 3, 0, 0),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator_template, 3, 0, 0),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator_template, 3, 0, 0),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_prolog_style_body_repeat1, 2, 0, 0),
  [146] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 2, 0, 4),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 2, 0, 4),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag, 3, 0, 5),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag, 3, 0, 5),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pl_tag_text, 2, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pl_tag_text, 2, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_directive_template, 2, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_directive_template, 2, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_comment, 1, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pldoc_prolog_style, 3, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [179] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [181] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__head_repeat1, 2, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag_name, 1, 0, 3),
  [191] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [195] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
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
