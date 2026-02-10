# Question 2 — Infix to Postfix Conversion and Evaluation

## Data Structures Used
Two stacks are used:
- Character stack for operators
- Numeric stack for evaluation

## Functions Implemented
- `infix_to_postfix()` — Converts expression using precedence rules.
- `eval_postfix()` — Evaluates postfix expression.
- Stack helpers manage push/pop operations.

## main() Overview
User inputs an expression. Program converts it to postfix format and computes the result.

## Sample Output
Enter infix expression: (3+5)*2  
Postfix: 3 5 + 2 *  
Value: 16
