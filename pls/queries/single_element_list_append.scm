(functional_notation
  function: (atom) @func_name (#eq? @func_name "append")
  (arg_list
    (list_notation
      (open_list)
      [
        (atom)
        (integer)
        (float_number)
        (variable_term)
      ] @element
      .
      (close_list)
    ) @first_arg

    (_) ; first comma
    (_) @second_arg
    (_) ; second comma
    (_) @result
  )
) @append_call