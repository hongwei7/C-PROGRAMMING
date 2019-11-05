#include<stdio.h>
main()
{
	char c;
	while((c=getchar())!=EOF)
	{
		if(c=='\t')
			printf("%s","    ");
		else 
			putchar(c);
	}
}
