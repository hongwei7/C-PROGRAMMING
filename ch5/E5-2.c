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
double getfloat(double *pn)
{
    int d,c,sign;
    double doted=0;
    while(isspace(c=getch()))
        ;
    if(!isdigit(c)&&c!=EOF&&c!='-'){
        //printf("out\n");
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
    for(*pn=0;isdigit(c)||c=='.';c=getch()){
        //printf("%c\n",c);
        if(c=='.'){
            doted=0.1;
            continue;
        }
        if(doted>0){
            *pn=*pn+doted*(c-'0');
            doted*=0.1;
        }
        else
            *pn=10*(*pn)+c-'0';
        //printf("pn=%f\n",*pn);
    }
    *pn*=sign;
    if(c!=EOF)
        ungetch(c);
    return c;
}
int main()
{
    double a=0;
    printf("a\t%f\n",a);
    getfloat(&a);
    printf("a\t%f\n",a);
    return 0;
}

