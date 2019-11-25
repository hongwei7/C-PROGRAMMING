#include<stdio.h>
#define BUFSIZE 100
static char buf[BUFSIZE];
static int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
void ungets(char s[])
{
    int i = 0;
    for (; s[i] != '\0'; i++);
    for (; i >= 0; i--)
    {
        ungetch(s[i]);
    }
}
