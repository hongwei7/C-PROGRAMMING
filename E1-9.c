#include<stdio.h>
int main()
{
	int c=1;
	while(c!=EOF)
	{
		if(c==' ')
		{
			c=getchar();
			if(c==' ')
				continue;
			putchar(c);
		
		}
		else
		{
			c=getchar();
			putchar(c);
		}
	}
}

