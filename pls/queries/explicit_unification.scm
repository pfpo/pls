(operator_notation
  [
    (
      (_) @term
      (binary_operator) @operator (#eq? @operator "=")
      (variable_term) @variable_term
    )
    (
      (variable_term) @variable_term
      (binary_operator) @operator (#eq? @operator "=")
      (_) @term
    )
  ]
) @unify