#include<stdio.h>
#define MAXSIZE 1000
int getline_(char s[])
{
    char c;
    int i;
    for(i=0;i<MAXSIZE&&(c=getchar())!=EOF&&c!='\n';i++)
    {
        s[i]=c;
    }
    if(c=='\n')
        s[i++]='\n';
    s[i]='\0';
    return i;
}
main()
{
    char s[MAXSIZE];
    int length;
    while((length=getline_(s))>0)
        if(length>=80)
            printf("-------length:%d----------\n%s\n-------length%d----------",length,s,length);
}