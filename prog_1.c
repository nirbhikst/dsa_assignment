// prog_1.c
#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char a[MAX];
    int top;
} Stack;

void init(Stack *s) { s->top = -1; }
int empty(Stack *s) { return s->top == -1; }
int push(Stack *s, char c) { if (s->top == MAX - 1) return 0; s->a[++s->top] = c; return 1; }
int pop(Stack *s, char *out) { if (empty(s)) return 0; *out = s->a[s->top--]; return 1; }

int is_open(char c) { return c == '(' || c == '{' || c == '['; }
int is_close(char c){ return c == ')' || c == '}' || c == ']'; }

int match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int balanced(const char *expr) {
    Stack s; init(&s);
    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (is_open(c)) {
            if (!push(&s, c)) return 0;
        } else if (is_close(c)) {
            char t;
            if (!pop(&s, &t)) return 0;
            if (!match(t, c)) return 0;
        }
    }
    return empty(&s);
}

int main() {
    const char *tests[] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m})]",
        "a + (b - c)",
        NULL
    };

    for (int i = 0; tests[i]; i++) {
        printf("Expression: %s\n", tests[i]);
        printf("Balanced?  %s\n\n", balanced(tests[i]) ? "YES" : "NO");
    }
    return 0;
}
