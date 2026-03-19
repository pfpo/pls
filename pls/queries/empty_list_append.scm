(functional_notation
  function: (atom) @func_name (#eq? @func_name "append")
  [
    (arg_list
      (atom 
        (empty_list)
      ) @first_arg
      (_) ; first comma
      (_) @second_arg
      (_) ; second comma
      (_) @result
    )
    (arg_list
      (_) @first_arg
      (_) ; first comma
      (atom 
        (empty_list)
      ) @second_arg
      (_) ; second comma
      (_) @result
    )
  ]
) @append_call