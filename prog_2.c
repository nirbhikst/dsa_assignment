// prog_2.c
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 2000

typedef struct { char a[MAX]; int top; } CharStack;
typedef struct { double a[MAX]; int top; } NumStack;

void cinit(CharStack* s){ s->top=-1; }
int cempty(CharStack* s){ return s->top==-1; }
void cpush(CharStack* s,char c){ s->a[++s->top]=c; }
char cpop(CharStack* s){ return s->a[s->top--]; }
char cpeek(CharStack* s){ return s->a[s->top]; }

void ninit(NumStack* s){ s->top=-1; }
void npush(NumStack* s,double x){ s->a[++s->top]=x; }
double npop(NumStack* s){ return s->a[s->top--]; }

int prec(char op){
    switch(op){
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}
int right_assoc(char op){ return op=='^'; }

int infix_to_postfix(const char* infix, char* postfix){
    CharStack ops; cinit(&ops);
    int j=0;
    for(int i=0; infix[i]; ){
        if(isspace((unsigned char)infix[i])) { i++; continue; }

        if(isdigit((unsigned char)infix[i])){
            // number token
            while(isdigit((unsigned char)infix[i])) postfix[j++]=infix[i++];
            postfix[j++]=' '; // separator
        } else if(infix[i]=='('){
            cpush(&ops, infix[i++]);
        } else if(infix[i]==')'){
            while(!cempty(&ops) && cpeek(&ops)!='('){
                postfix[j++]=cpop(&ops); postfix[j++]=' ';
            }
            if(cempty(&ops)) return 0; // mismatched
            cpop(&ops); // pop '('
            i++;
        } else {
            char op=infix[i++];
            while(!cempty(&ops) && cpeek(&ops)!='('){
                char top=cpeek(&ops);
                if(prec(top) > prec(op) || (prec(top)==prec(op) && !right_assoc(op))){
                    postfix[j++]=cpop(&ops); postfix[j++]=' ';
                } else break;
            }
            cpush(&ops, op);
        }
    }
    while(!cempty(&ops)){
        char t=cpop(&ops);
        if(t=='(') return 0;
        postfix[j++]=t; postfix[j++]=' ';
    }
    postfix[j]='\0';
    return 1;
}

double eval_postfix(const char* postfix){
    NumStack st; ninit(&st);
    for(int i=0; postfix[i]; ){
        if(isspace((unsigned char)postfix[i])) { i++; continue; }

        if(isdigit((unsigned char)postfix[i])){
            long val=0;
            while(isdigit((unsigned char)postfix[i])){
                val=val*10 + (postfix[i]-'0');
                i++;
            }
            npush(&st, (double)val);
        } else {
            char op=postfix[i++];
            double b=npop(&st);
            double a=npop(&st);
            double r=0;
            switch(op){
                case '+': r=a+b; break;
                case '-': r=a-b; break;
                case '*': r=a*b; break;
                case '/': r=a/b; break;
                case '^': r=pow(a,b); break;
            }
            npush(&st, r);
        }
    }
    return npop(&st);
}

int main(){
    char infix[500];
    char postfix[MAX];

    printf("Enter infix expression (numbers + operators + parentheses):\n> ");
    if(!fgets(infix, sizeof(infix), stdin)) return 0;

    if(!infix_to_postfix(infix, postfix)){
        printf("Invalid/mismatched parentheses.\n");
        return 0;
    }

    printf("Postfix: %s\n", postfix);
    printf("Value: %.2f\n", eval_postfix(postfix));
    return 0;
}
