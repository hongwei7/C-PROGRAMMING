#include<stdio.h>
void chosen_expand(char front,char back,char *s)
{
    for(char i=front+1;i<=back;i++){
        *s=i;
        //printf("%c\n",i );
        s++;
    }
}
void expand(char s1[],char s2[])
{
    char *p=s1,*q=s2;
    while(*p!='\0'){
        //printf("%c\n",*p);
        if(*p=='-'){
            chosen_expand(*q,*(p+1),q+1);
            q+=(*(p+1)-*q-1);
            p++;
        }
        else{
            q=q+1;
            *(q)=*(p);
            p=p+1;
        }
        //printf("--%s--\n",s2 );
    }
    *(++q)='\0';
}
main()
{
    char s[50]="a-fkji1-90-5";
    char s1[50]=" ";
    expand(s,s1);
    printf("s: %s\ts1: %s\n",s,s1);
}