/**
 * @file Structured Comments of Prolog
 * @author Martim Videira <mitram790@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check
const multi_line_comment_line = /(([^*\n]\/)|([^*\/\n])|\*|(\*[^\/\n]))*/
const multi_line_comment1 = /\/\*(([^*]\/)|([^*\/])|\*|(\*[^\/]))*\*\//
const multi_line_comment = alias(token(seq('/*', repeat(seq(multi_line_comment_line, /\n?/)), '*/')),"comment_token")
const prolog_start_comment = '%'
const pldoc_new_start_token = '! '
const pldoc_old_start_token = '% '
const pldoc_start_comment = alias(token(prec(1, seq('%', choice(pldoc_new_start_token, pldoc_old_start_token)))),"comment_token")
const pldoc_c_style_start_comment = alias(token(prec(1, '/** ')),"comment_token")

const instantiation_modifiers = ['++', '+', '-', '--', '?', ':', '@', '!']
const determinism_modifiers = ['det', 'semidet', 'failure', 'nondet', 'multi', 'undefined']

const word = /[^\s]+/
const graphic_char = /[#\$\&\*\+-\.\/:<=>\?@\^~\\,!;]/
const alphanum = /[a-zA-Z0-9$_]/
const functor= token(repeat1(choice(graphic_char,alphanum)))

const name = alias(token(word),'name')
const text = word

const c_style_line_begin = /[^\S\n]*\*?[^\S\n]*/

const tags = [
  (name,desc) => seq(token(prec(1, '@arg')), field("name",name), field("description",desc)),
  (name,desc) => seq(token(prec(1, '@param')), field("name",name), field("description",desc)),
  (name,desc) => seq(token(prec(1, '@error')), field("name",name), field("description",desc)),
  (name,desc) => seq(token(prec(1, '@author')), field("name",name), field("description",desc)),
  (name,desc) => seq(token(prec(1, '@version')), field("name",name), field("description",desc)),
  (name,desc) => seq(token(prec(1, '@see')), field("description",desc)),
  (name,desc) => seq(token(prec(1, '@deprecated')), field("description",desc)),
  (name,desc) => seq(token(prec(1, '@compat')), field("description",desc)),
  (name,desc) => seq(token(prec(1, '@copyright')), field("description",desc)),
  (name,desc) => seq(token(prec(1, '@license')), field("description",desc)),
  (name,desc) => seq(token(prec(1, '@bug')), field("description",desc)),
  (name,desc) => seq(token(prec(1, '@tbd')), field("description",desc)),

]

module.exports = grammar({
  name: "pldoc",
  conflicts: $ => [[$.pldoc_prolog_style], [$.prolog_style_body],[$.operator_template,$.arg_name]],

  rules: {
    // TODO: add the actual grammar rules
    source_file: $ => repeat($.comment),

    comment: $ => choice(
      $.normal_comment,
      $.pldoc_comment
    ),
    normal_comment: $ => choice(
      $.normal_single_line_comment,
      // $.normal_multiline_comment,
    ),

    normal_single_line_comment: $ => seq('%', /.*/, choice('\n', '\0')),
    normal_multiline_comment: $ => multi_line_comment,

    _template: $=> choice(
      $.functor_template,
      $.operator_template,
      $.directive_template,
    ),
    operator_template: $=> choice(
      seq($.arg_spec,$.functor,$.arg_spec),
      seq($.functor,$.arg_spec),
      seq($.arg_spec,$.functor),
    ),
    functor_template: $ => seq($._head, optional(seq('is', choice(...determinism_modifiers)))),
    directive_template: $=> seq(':-',choice($.functor_template,$.operator_template)),

    _head: $ => seq(
      $.functor,
      optional(seq(
        '(',
        repeat(seq($.arg_spec, ',')),
        $.arg_spec,
        ')'
      ))
    ),

    arg_name_instantiation: $ => token(prec(1,seq(choice(...instantiation_modifiers),/[A-Z][a-zA-Z0-9$_]*/))),
    arg_spec: $ => seq(
      field("name",$.arg_name_instantiation),
      optional(seq(
        ':',
        field("type",$.type),
      ))
    ),

    _arg_spec: $ => seq(
      field("instantiation",optional(choice(...instantiation_modifiers))),
      field("name",$.arg_name),
      optional(seq(
        ':',
        field("type",$.type),
      ))
    ),
    functor: $=> functor,
    type: $ => word,
    arg_name: $ =>/[A-Z][a-zA-Z0-9$_]*/,




    pldoc_comment: $ => choice($.pldoc_prolog_style, $.pldoc_c_style),

    pldoc_prolog_directive: $ => seq(alias(pldoc_start_comment,"comment_token"), $._template),

    pldoc_prolog_style: $ => seq(
      repeat1($.pldoc_prolog_directive),
      optional(seq(
        repeat1(seq('%', '\n')),
        $.prolog_style_body))
    ),

    prolog_style_body: $ => choice(
      seq(
        $.prolog_style_description,
        repeat1(seq('%', $.pl_tag))
      ),
      $.prolog_style_description,
      repeat1(seq('%', $.pl_tag)),
    ),

    _prolog_style_description: $ => repeat1(seq('%', /([^@\s].*)|(\s+[^@].*)/, choice('\n', '\0'))),
    prolog_style_description: $ => repeat1(choice(
      /%[\r\t\f\v ]*[^@\s].*\n/,
      /%\s*\n/,
    )),

    pldoc_c_style: $ => seq(
      pldoc_c_style_start_comment,
      repeat1(seq('*', $._template, '\n')),
      optional(seq(
        repeat1(seq(optional('*'), '\n')),
        $.c_style_body)),
      '*/'),

    c_style_body: $ => choice(
      seq(
        $.c_style_description,
        repeat1(seq(optional('*'), $.c_tag, '\n'))
      ),
      $.c_style_description,
      repeat1(seq(optional('*'), $.c_tag, '\n')),
    ),
    
    c_style_description: $ => repeat1(seq(multi_line_comment_line, /\n?/)),


    // c_tag: $ => choice(...(tags.map(((e) => e(seq(/.*\n/, optional($.c_style_description))))))),
    // pl_tag: $ => choice(...(tags.map(((e) => e(name))))),
    // c_tag: $ => choice(...(tags.map(((e) => e(name))))),

    tag_name :$=> name,
    pl_tag_text: $ => seq(/([^@\s].*)|(\s+[^@].*)/ ,optional($.prolog_style_description)),
    pl_tag: $ => choice(...(tags.map(((e) => e($.tag_name,$.pl_tag_text))))),
    c_tag: $ => choice(...(tags.map(((e) => e($.tag_name, optional($.c_style_description)))))),
  }

});
