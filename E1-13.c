#include<stdio.h>
#define IN 1
#define OUT 0
graph(int k)
{
	for(int i=0;i<k;i++)
		putchar('#');
	printf("%d",k);
	putchar('\n');
}
main()
{
	int space=0,row=0,words=0,sum=0;
	int state=OUT;
	int c;
	int digits[10];
	for(int i=0;i<10;i++)
		digits[i]=0;
	c=getchar();
	while(c!=EOF)
	{
		sum++;
		if(c==' '||c=='\n')
		{
			if(c==' ')
				space++;
			else
				row++;
			state=OUT;
		}
		else if(state==OUT)
		{
			words++;
			state=IN;
		}
		if(c>='0'&&c<='9')
			digits[c-'0']++;
		c=getchar();
	}
	printf("graph as:\n");
	printf("%8s  ","space");graph(space);
	printf("%8s  ","row");graph(row);
	printf("%8s  ","words");graph(words);
	printf("%8s  ","all");graph(sum);
	for(int i =0;i<10;i++)
	{
		printf("%7s%d  ","number",i);graph(digits[i]);

	}
}

