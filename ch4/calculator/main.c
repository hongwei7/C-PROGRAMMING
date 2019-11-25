#include<stdio.h>
#include<stdlib.h>
#include "calc.h"
#include <math.h>
#include "stack.c"
#include "getop.c"
#include "getch.c"
#define MAXOP 100
int main()
{
    int type, var;
    double op2;
    char s[MAXOP];
    double variable[42], ans;
    for (int i = 0; i < 42; i++)
        variable[i] = 0.0;
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER: push(atof(s)); break;
        case '+': push(pop() + pop()); break;
        case '*': push((pop()*pop())); break;
        case '-': op2 = pop(); push(pop() - op2); break;
        case '/': op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error:divided by zero!/n");
            break;
        case '%':
            op2 = pop();
            if (op2 == 0.0) {
                printf("error:mod failed\n");
                break;
            }
            push(fmod(pop(), op2));
            break;
        case 's':
            push(sin(pop()));
            break;
        case '\n':
            var = 0;
            ans = pop();
            printf("\t%.8g\n", ans);
            break;
        case '=':
            if (var == 0)
                printf("error:failed to give value\n");
            else {
                variable[var - 'A'] = pop();
                printf("%c = ", var);
                pop();
                push(variable[var - 'A']);
            }
            break;
        default:
            if (type <= 'Z' && type >= 'A') {
                var = type;
                push(variable[type - 'A']);
                break;
            }
            else if (type == '~') {
                push(ans);
                break;
            }
            else
                printf("error:unknown command %s\n", s);
            break;
        }
    }
    return 0;
}