#include<stdio.h>
#define MAXCOL 30
main()
{
	char c;
	int s=0,ci=0;
	while((c=getchar())!=EOF)
	{
		if(ci>=MAXCOL-1){
			ci=0;
			putchar('\n');
		}
		if(c==' ')
			s++;
		else{
			for(int i=0;i<s&&ci!=0;i++){
				putchar(' ');
				ci++;
			}
			s=0;
			ci++;
			if(c=='\n')
				ci=0;
			putchar(c);
		}
	}
}
