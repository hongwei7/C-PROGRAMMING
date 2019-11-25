#include<stdio.h>
#include<ctype.h>
#include "calc.h"
int getop(char s[])
{
    int i, c;
    int c1, c2;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-' && c != 's' && c != 'p' && c != 'e')
        return c;
    i = 0;
    switch (c) {
    case '-':
        if (isdigit(c = getch()) || c == '.')
        {
            s[++i] = c;
        }
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        } break;
    case 's':
        if ((c1 = getch()) == 'i' && (c2 = getch()) == 'n')
            return 's';
        else {
            ungetch(c2); ungetch(c1);
            return 'u';
        }
        break;
    case 'p':
        if ((c1 = getch()) == 'o' && (c2 = getch()) == 'w')
            return 'p';
        else {
            ungetch(c2); ungetch(c1);
            return 'u';
        }
        break;
    case 'e':
        if ((c1 = getch()) == 'x' && (c2 = getch()) == 'p')
            return 'e';
        else {
            ungetch(c2); ungetch(c1);
            return 'u';
        }
        break;
    default : break;
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}