#include <stdio.h>
void strcpy1(char *s,char* t)//数组下标的版本
{
    int i=0;
    while((s[i]=t[i])!='\0'){
        i++;
    }
}
void strcpy2(char *s,char*t)//使用指针方式实现的版本1
{
    while((*s=*t)!='\0'){
        s++;
        t++;
    }
}
void strcpy3(char *s,char*t)//使用指针方式实现的版本2
{
    while(*s++=*t++);
}
int main()
{
    printf("Hello world\n");
    return 0;
}

