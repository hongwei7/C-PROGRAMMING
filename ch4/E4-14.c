#include <stdio.h>
#define swap(t,x,y)  {\
    t temp; \
    temp=x; \
    x=y;    \
    y=temp;  \
}
 int main()
{
    double a=2,b=3;
    printf("%f\t%f\n",a,b);
    swap(double,a,b);
    printf("%f\t%f\n",a,b);
    return 0;
}

