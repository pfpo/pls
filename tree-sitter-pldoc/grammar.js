/**
 * @file Structured Comments of Prolog
 * @author Martim Videira <mitram790@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check
const multi_line_comment_line = /(([^*\n]\/)|([^*\/\n])|\*|(\*[^\/\n]))*/
const multi_line_comment1 = /\/\*(([^*]\/)|([^*\/])|\*|(\*[^\/]))*\*\//
const multi_line_comment = token(seq('/*', repeat(seq(multi_line_comment_line, /\n?/)), '*/'))
const prolog_start_comment = '%'
const pldoc_new_start_token = '! '
const pldoc_old_start_token = '% '
const pldoc_start_comment = token(prec(1, seq('%', choice(pldoc_new_start_token, pldoc_old_start_token))))
const pldoc_c_style_start_comment = token(prec(1, '/** '))

const instantiation_modifiers = ['++', '+', '-', '--', '?', ':', '@', '!']
const determinism_modifiers = ['det', 'semidet', 'failure', 'nondet', 'multi', 'undefined']

const word = /[^\s]+/

const name = word
const text = word

const c_style_line_begin = /[^\S\n]*\*?[^\S\n]*/

const tags = [
  (e) => seq(token(prec(1, '@arg')), name, e),
  (e) => seq(token(prec(1, '@param')), name, e),
  (e) => seq(token(prec(1, '@error')), name, e),
  (e) => seq(token(prec(1, '@author')), name, e),
  (e) => seq(token(prec(1, '@version')), name, e),
  (e) => seq(token(prec(1, '@see')), e),
  (e) => seq(token(prec(1, '@deprecated')), e),
  (e) => seq(token(prec(1, '@compat')), e),
  (e) => seq(token(prec(1, '@copyright')), e),
  (e) => seq(token(prec(1, '@license')), e),
  (e) => seq(token(prec(1, '@bug')), e),
  (e) => seq(token(prec(1, '@tbd')), e),

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

    template: $=> choice(
      $.functor_template,
      $.operator_template,
      $.directive_template,
    ),
    operator_template: $=> choice(
      seq($.arg_spec,word,$.arg_spec),
      seq(word,$.arg_spec),
      seq($.arg_spec,word),
    ),
    functor_template: $ => seq($.head, optional(seq('is', choice(...determinism_modifiers)))),
    directive_template: $=> seq(':-',choice($.functor_template,$.operator_template)),

    head: $ => seq(
      $.functor,
      optional(seq(
        '(',
        repeat(seq($.arg_spec, ',')),
        $.arg_spec,
        ')'
      ))
    ),

    arg_spec: $ => seq(
      optional(choice(...instantiation_modifiers)),
      $.arg_name,
      optional(seq(
        ':',
        $.type,
      ))
    ),
    functor: $ => word,
    type: $ => word,
    arg_name: $ => word,




    pldoc_comment: $ => choice($.pldoc_prolog_style, $.pldoc_c_style),

    pldoc_prolog_directive: $ => seq(pldoc_start_comment, $.template),

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
      repeat1(seq('*', $.template, '\n')),
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


    pl_tag: $ => choice(...(tags.map(((e) => e(seq(/.*\n/, optional($.prolog_style_description))))))),
    c_tag: $ => choice(...(tags.map(((e) => e(seq(/.*\n/, optional($.c_style_description))))))),
  }

});
