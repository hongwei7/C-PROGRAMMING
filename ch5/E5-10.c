#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define NUMBER '0'
#define MAXOP 100

//****************main******************
int getop(char[]);
void push(double);
double pop(void);
double getvalue(void);
void copyvalue(void);
void swaptop(void);



 int main(int argc , char *argv[])
{
    if(argc==1){
        printf("Usage: \t./E5-10 [inv poland exp]\nExp: \t./E5-10 4 2 3 + *\nOut:\t20\n");
        return 1;
    }

	int type,var;
	double op2;
	double ans;

	for(int i=1;i<argc;i++){
		type=getop(argv[i]);
		char *s=argv[i];
		switch(type){
			case NUMBER:push(atof(s)); break;
			case '+':push(pop()+pop());break;
			case '*':push((pop()*pop()));break;
			case '-':op2=pop(); push(pop()-op2);break;
			case '/':op2=pop();
				if(op2!=0.0)
					push(pop()/op2);
				else 
					printf("error:divided by zero!\n");
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
            case 'p':
                op2=pop();
                push(pow(pop(),op2));
                break;
            case 'e':
                push(pow(2.718281828,pop()));
                break;
			case '\n':
                var = 0;
                ans=pop();
				printf("\t%.8g\n",ans);
				break;
			default: 
                if(type=='~'){
                    push(ans);
                    break;
                }
                else{
                    printf("error:unknown command : \"%s\"\n",s);
                    printf("Usage: \t./E5-10 [inv poland exp]\nExp: \t./E5-10 4 2 3 + *\nOut:\t20\n");
                    return 1;
                }
				break;				
		}
	}
    ans=pop();
    printf("Ans =\t%.8g\n",ans);
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

int getop(char s[])
{
	int i,c;
	int c1,c2;
	c=s[0];
	if(!isdigit(c)&&c!='.'&&c!='-'&&c!='s'&&c!='p'&&c!='e')
		return c;
	i=0;
	switch (c){
		case '-':
		if (isdigit(c=s[++i])||c=='.')
			;
		else
			return '-';
		break;
		case 's':
		if((c1=s[++i])=='i'&&(c2=s[++i])=='n')
			return 's';
		else{
			i-=2;
			return 'u';
		}
		break;
		case 'p':
		if((c1=s[++i])=='o'&&(c2=s[++i])=='w')
			return 'p';
		else{
			i-=2;
			return 'u';
		}
		break;
		case 'e':
		if((c1=s[++i])=='x'&&(c2=s[++i])=='p')
			return 'e';
		else{
			i-=2;
			return 'u';
		}
		break;
		default : break;
	}
	if(isdigit(c))
		while(isdigit(s[++i]));
	if(c=='.')
		while(isdigit(s[++i]));
	return NUMBER;
}


