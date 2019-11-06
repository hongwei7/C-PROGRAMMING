#include<stdio.h>
#define INTLENGTH 32
int setbits(int x,int p,int n,int y)
{
    return (((~((~0)<<n))&y)<<(INTLENGTH-n-p-1))|(x&(~(((~((~0)<<n))&(~0))<<(INTLENGTH-n-p-1))));
}
main()
{
    int x=~0,y=2;
    printf("INTLENGTH:%d\n",INTLENGTH );
    printf("x=%d\ty=%d\tresult:%d\n",x,y,setbits(x,1,3,y));
}