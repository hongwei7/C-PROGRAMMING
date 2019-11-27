#include <stdio.h>
int strend(char *s,char *t)
{
    char *s_start=s-1,*t_start=t-1;
   while(*s!='\0')
       s++;
   while(*t!='\0')
       t++;
   while(s_start!=s && t_start!=t)
   {
       if(*s--!=*t--)
           return 0;
   }
   if(t_start!=t)
       return 0;
    else
        return 1;
}
int main()
{
    char s[]="asodiasdhello";
    char t[]="hello";
    char k[]="llo";
    printf("%d\n",strend(s,t));
    printf("%d\n",strend(k,t));
    return 0;
}

