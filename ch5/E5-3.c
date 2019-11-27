#include <stdio.h>
void mystrcat(char *p,char *q)
{
    while(*p!='\0')
        p++;
    while(*q!='\0')
        *p++=*q++;
    *p='\0';
}
int main()
{
    char s[20]="hello ";
    char t[20]="world!";
    mystrcat(s,t);
    printf("%s\n",s);
    return 0;
}

