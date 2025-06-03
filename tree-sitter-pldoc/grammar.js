/**
 * @file Structured Comments of Prolog
 * @author Martim Videira <mitram790@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check
// TODO: remove \n for new_line_char
const multi_line_comment_line = /(([^*\n]\/)|([^*\/\n])|\*|(\*[^\/\n]))*/
const prolog_start_comment = '%'
const pldoc_new_start_token = '! '
const pldoc_old_start_token = '% '
const pldoc_start_comment = alias(token(prec(1, seq('%', choice(pldoc_new_start_token, pldoc_old_start_token)))),"comment_token")
const pldoc_c_style_start_comment = alias(token(prec(1, '/** ')),"comment_token")

const instantiation_modifiers = ['++', '+', '-', '--', '?', ':', '@', '!']
const determinism_modifiers = ['det', 'semidet', 'failure', 'nondet', 'multi', 'undefined']

const word = /[^\s]+/

const new_line_char = choice("\n","\r","\r\n")
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
  conflicts: $ => [[$.pldoc_prolog_style]],

  rules: {
    // TODO: add the actual grammar rules
    source_file: $ => repeat($.comment),

    comment: $ => $.pldoc_comment,

    _template: $=> choice(
      $.functor_template,
      //$.operator_template,
      $.directive_template,
    ),
    operator_template: $=> choice(
      seq($.arg_spec,word,$.arg_spec),
      seq(word,$.arg_spec),
      seq($.arg_spec,word),
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

    arg_spec: $ => seq(
      field("instantiation",optional(choice(...instantiation_modifiers))),
      field("name",$.arg_name),
      optional(seq(
        ':',
        field("type",$.type),
      ))
    ),
    functor: $ =>/[a-zA-Z0-9_$]+/,
    type: $ => word,
    arg_name: $ =>/[a-zA-Z0-9_$]+/,




    pldoc_comment: $ => choice($.pldoc_prolog_style, $.pldoc_c_style),

    pldoc_prolog_directive: $ => seq(alias(pldoc_start_comment,"comment_token"), $._template),

    pldoc_prolog_style: $ => seq(
      repeat1($.pldoc_prolog_directive),
      optional(seq(
        repeat1(seq('%', new_line_char)),
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

    _prolog_style_description: $ => repeat1(seq('%', /([^@\s].*)|(\s+[^@].*)/, choice(new_line_char, '\0'))),
    prolog_style_description: $ => repeat1(seq(choice(
      /%[\r\t\f\v ]*[^@\s].*/,
      /%\s*/,
    ),new_line_char)),

    pldoc_c_style: $ => seq(
      pldoc_c_style_start_comment,
      repeat1(seq('*', $._template, new_line_char)),
      optional(seq(
        repeat1(seq(optional('*'),new_line_char)),
        $.c_style_body)),
      '*/'),

    c_style_body: $ => choice(
      seq(
        $.c_style_description,
        repeat1(seq(optional('*'), $.c_tag, new_line_char))
      ),
      $.c_style_description,
      repeat1(seq(optional('*'), $.c_tag, new_line_char)),
    ),
    
    c_style_description: $ => repeat1(seq(multi_line_comment_line, optional(new_line_char))),


    // c_tag: $ => choice(...(tags.map(((e) => e(seq(/.*\n/, optional($.c_style_description))))))),
    // pl_tag: $ => choice(...(tags.map(((e) => e(name))))),
    // c_tag: $ => choice(...(tags.map(((e) => e(name))))),

    tag_name :$=> name,
    pl_tag_text: $ => seq(/([^@\s].*)|(\s+[^@].*)/ ,optional($.prolog_style_description)),
    pl_tag: $ => choice(...(tags.map(((e) => e($.tag_name,$.pl_tag_text))))),
    c_tag: $ => choice(...(tags.map(((e) => e($.tag_name, optional($.c_style_description)))))),
  }

});
