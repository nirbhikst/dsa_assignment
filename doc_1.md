# Question 1 — Balanced Parentheses Using Stack

## Data Structures Used
A stack is implemented using an array to track opening parentheses. It follows Last-In-First-Out (LIFO) behavior to ensure matching pairs of parentheses.

## Functions Implemented
- `push()` — Adds an element to the stack.
- `pop()` — Removes the top element.
- `balanced()` — Checks whether parentheses are correctly matched.
- Helper functions check opening/closing symbols.

## main() Overview
The program tests multiple mathematical expressions. Each expression is scanned and validated using stack logic.

## Sample Output
Expression: a + (b - c) * (d  
Balanced? NO  

Expression: m + [a - b * (c + d * {m})]  
Balanced? YES  

Expression: a + (b - c)  
Balanced? YES