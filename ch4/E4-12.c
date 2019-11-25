#include <stdio.h>
//printd函数：打印十进制数int n
void printd(int n)
{
    if(n<0){
        putchar('-');
        n=-n;
    }
    if(n/10)
        printd(n/10);
    putchar(n%10+'0');
}
//递归版本
void itoa(int a,char s[])
{
    static int i=0;
    if(a<0){
        s[i++]='-';
        a=-a;
        }
    if(a/10)
        itoa(a/10,s);
    s[i++]=a%10+'0';
    s[i]='\0';
}
int main()
{
    char s[20];
    printf("1234 \t");
    printd(1234);
    printf("\n");
    itoa(-3214,s);
    printf("-3214\t%s\n",s);
    return 0;
}

