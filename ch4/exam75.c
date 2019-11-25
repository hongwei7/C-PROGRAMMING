#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define NUMBER '0'
#define MAXOP 100

//****************main******************
int getop(char[]);
void push(double);
double pop(void);

int main()
{
	int type;
	double op2;
	char s[MAXOP];
	while((type=getop(s)) != EOF){
		switch(type){
			case NUMBER:push(atof(s)); break;
			case '+':push(pop()+pop());break;
			case '*':push((pop()*pop()));break;
			case '-':op2=pop(); push(pop()-op2);break;
			case '/':op2=pop();
				if(op2!=0.0)
					push(pop()/op2);
				else 
					printf("error:divided by zero!/n");
				break;
			case '%':
				op2=pop();
				if(op2==0.0){
					printf("error:mod failed\n");
					break;
				}
				push(fmod(pop(),op2));
				break;
			case 's':
				push(sin(pop()));
				break;
			case '\n':
				printf("\t%.8g\n",pop());
				break;
			default: 
				printf("error:unknown command %s\n",s);
				break;				
		}
	}
	return 0;
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
double getvalue(void)
{
	if(sp<0)
		printf("error:stack empty!");
	else
		return val[sp];
	return 0.0;
}
void copyvalue(void)
{
	if(sp<0)
		printf("error:copy failed\n");
	else
	{
		val[sp]=val[sp-1];
		sp++;
	}
}
void swaptop(void)
{
	double temp;
	if(sp<1)
		printf("error:swap failed\n");
	else{
		temp=val[sp];
		val[sp]=val[sp-1];
		val[sp-1]=temp;
	}
}
//*****************getop****************
#include<ctype.h>
int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i,c;
	int c1,c2;
	while((s[0]=c=getch())==' '||c=='\t');
	s[1]='\0';
	if(!isdigit(c)&&c!='.'&&c!='-'&&c!='s'&&c!='p'&&c!='e')
		return c;
	i=0;
	switch (c){
		case '-':
		if (isdigit(c=getch())||c=='.')
		{
			s[++i]=c;
		}
		else{
			if(c!=EOF)
				ungetch(c);
			return '-';
		}break;
		case 's':
		if((c1=getch())=='i'&&(c2=getch())=='n')
			return 's';
		else{
			ungetch(c1);ungetch(c2);
			return 'u';
		}
		break;
		case 'p':
		if((c1=getch())=='o'&&(c2=getch())=='w')
			return 'p';
		else{
			ungetch(c1);ungetch(c2);
			return 'u';
		}
		break;
		case 'e':
		if((c1=getch())=='x'&&(c2=getch())=='p')
			return 'e';
		else{
			ungetch(c1);ungetch(c2);
			return 'u';
		}
		break;
		default : break;
	}
	if(isdigit(c))
		while(isdigit(s[++i]=c=getch()));
	if(c=='.')
		while(isdigit(s[++i]=c=getch()));
	s[i]='\0';
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
