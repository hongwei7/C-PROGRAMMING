#include<stdio.h>
int htiox(char s[])
{
	if(!(s[0]=='0'&&(s[1]=='X'||s[1]=='x')))
		return 0;
	int result=0;
	for(int i=2;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			result*=16;
			result+=s[i]-'0';
		}
		else if(s[i]<='F'&&s[i]>='A'){
			result*=16;
			result+=s[i]-'A'+10;
		}
		else if(s[i]<='f'&&s[i]>='a'){
			result*=16;
			result+=s[i]-'a'+10;	
		}
		else return 0;
	}
	return result;
}
main()
{
	char d[]="0x130D";
	printf("%10d %10s\n",htiox(d),d);
}
