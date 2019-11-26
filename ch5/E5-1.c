#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
 char buf[BUFSIZE];
 int bufp=0;
 int getch(void)
 {
     return (bufp>0)?buf[--bufp]:getchar();
 }
 void ungetch(int c)
 {
       if(bufp>=BUFSIZE)
         printf("ungetch: too many characters\n");
     else
         buf[bufp++]=c;
 }
void ungets(char s[])
 {
     int i=0;
     for(;s[i]!='\0';i++);
     for(;i>=0;i--)
     {
         ungetch(s[i]);
     }
 }
int getint(int *pn)
{
    int d,c,sign;
    while(isspace(c=getch()))
        ;
    if(!isdigit(c)&&c!=EOF&&c!='-'){
        ungetch(c);
        return 0;
    }
    sign=(c=='-')?-1:1;
    if(c=='+'||c=='-'){
        d=c;
        if(!isdigit(c=getch())){
            if(c!=EOF)
                ungetch(c);
            ungetch(d);
            return d;
            }
    }
    for(*pn=0;isdigit(c);c=getch())
        *pn=10*(*pn)+c-'0';
    *pn*=sign;
    if(c!=EOF)
        ungetch(c);
    return c;
}
int main()
{
    int a=0;
    printf("a\t%d\n",a);
    getint(&a);
    printf("a\t%d\n",a);
    return 0;
}

