#include<stdio.h>
main()
{
	char c;
	int s=0;
	while((c=getchar())!=EOF)
	{
		if(c==' ')
			s++;
		else{
			for(int i=0;i<s;i++)
				putchar(' ');
			s=0;
			putchar(c);
		}
		if(s==4){
			s=0;
			putchar('\t');
		}
	}
}
