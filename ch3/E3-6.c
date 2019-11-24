#include<stdio.h>
void reverse(char s[],int n)
{
  int temp;
  for(int i=0;i<n/2;i++){
    temp=s[i];
    s[i]=s[n-i];
    s[n-i]=temp;
  }
}

void itoa(int n,char s[],int width) //number -> string
{
  int i=0,sign=1;
  if(n<0)
    sign=0;
  if(sign==0)
    n=-n;
  while(n%10!=0){
    s[i++]=n%10+'0';
    n/=10;
  }
  if(!sign)
    s[i++]='-';
  for(int j=i;j<width;j++){
    s[j]='0';
  }
  reverse(s,width-1);
  s[width]='\0';
}
int main()
{
  int a=-3215;
  char s[20];
  itoa(a,s,7);
  printf("%d\t%s\n",a,s);
}
