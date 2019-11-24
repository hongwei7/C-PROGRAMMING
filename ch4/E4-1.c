#include<stdio.h>
int strrindex(char s[],char t[])
{
	int tp=0,sp=0;
	while(s[sp]!='\0'){
		int skip=0;
		for(tp=0;t[tp]!='\0';tp++){
			if(s[sp+tp]!=t[tp]){
				skip=1;
				break;
			}	
		}
		sp++;
		if(skip)
			continue;
		return sp-1+tp-1;
	}
	return -1;}
int main()
{
	char s[]="asoiduaosiduwkjelakhelloasldiaodjuidoasd";
	char t[]="hello";
	printf("%s\t%s\nindex=%d\n",t,s,strrindex(s,t));
}
