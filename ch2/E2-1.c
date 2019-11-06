#include<stdio.h>
#include<limits.h>
main()
{
    printf("\n>SIGNED:\n\n");
    printf("signed char:\t%d~%d\n",SCHAR_MIN,SCHAR_MAX );
    printf("signed short:\t%d~%d\n",SHRT_MIN,SHRT_MAX );
    printf("signed int:\t%d~%d\n",INT_MIN,INT_MAX );
    printf("signed long:\t%ld~%ld\n",LONG_MIN,LONG_MAX );
    printf("\n>UNSIGNED:\n\n");
    printf("unsigned char:\t%u\n",UCHAR_MAX );
    printf("unsigned short:\t%u\n", USHRT_MAX);
    printf("unsigned int:\t%u\n", UINT_MAX);
    printf("unsigned long:\t%lu\n", ULONG_MAX);

}