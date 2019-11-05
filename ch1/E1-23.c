#include <stdio.h>
#define CANCEL 0
#define IN 1
main()
{
    char front='\0',c;
    int STATE;
    while((c=getchar())!=EOF)
    {
        if(front=='/'&&c=='*')
            STATE=CANCEL;
        else if(front=='*'&&c=='/'){
            STATE=IN;
            front=getchar();
            c=getchar();
        }
        if(STATE)
            putchar(front);
        front=c;
    }
}