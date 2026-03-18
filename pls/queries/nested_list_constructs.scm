(list_notation
  (open_list)
  (
    (integer) 
    (list_notation_separator)
  )+ @head
  "|"
  (list_notation
    (open_list)
    (_) @inner_head
    "|"
    (_) @inner_tail
    (close_list)
  ) @inner_list
  (close_list)
) @nested_list