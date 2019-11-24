#include<stdio.h>
#include<stdlib.h>
#define NUMBER '0'

//*****************getop****************
#include<ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i,c;
	while((s[0]=c=getch())==' '||c=='\t');
	s[1]='0';
	if(isdigit(c)&&c!='.')
		return c;
	i=0;
	if(isdigit(c))
		while(isdigit(s[++i]=c=getch()));
	if(c=='.')
		while(isdigit(s[++i]=c=getch()));
	s[i]='0';
	if(c!=EOF)
		ungetch(c);
	return NUMBER;
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;
int getch(void)
{
	return (bufp>0)?buf[--bufp]:getchar();
}
void ungetch(int c)
{
	if(bufp>=BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++]=c;
}

//***************stack*******************
#define MAXVAL 100
int sp=0;
double val[MAXVAL];
void push(double f)
{
	if(sp<MAXVAL)
		val[sp++]=f;
	else
		printf("error:stack out of range");
}
double pop(void)
{
	if(sp<0)
		printf("error:stack empty!");
	else
		return val[--sp];
	return 0.0;
}

//****************main******************
#define MAXOP 100

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while((type==getop(s)) != EOF){
		printf("--- %c ---\n");
		switch(type){
			case  NUMBER:push(atof(s)); break;
			case '+':push(pop()+pop());break;
			case '*':push((pop()*pop()));break;
			case '-':op2=pop(); push(pop()-op2);break;
			case '/':op2=pop();
				if(op2!=0.0)
					push(pop()/op2);
				else printf("error:divided by zero!/n");
				break;
			case '\n':printf("\t%.8f\n",pop());break;
			default: printf("error:unknown command %s\n",s);break;				
		}
	}
	return 0;
}
