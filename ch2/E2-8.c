#include<stdio.h>
#define INTLENGTH 32
unsigned rightbot(int x,int n)
{
    int right=(~((~0)>>n))&x;
    return (x>>n)|(right<<(INTLENGTH-n));
}
main()
{
    printf("x=%d,n=%d,result=%d\n",183,5,rightbot(183,5) );
}