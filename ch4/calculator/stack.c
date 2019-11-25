#include "calc.h"
#include <stdio.h>
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error:stack out of range");
}
double pop(void)
{
	if (sp < 0)
		printf("error:stack empty!");
	else
		return val[--sp];
	return 0.0;
}
double getvalue(void)
{
	if (sp < 0)
		printf("error:stack empty!");
	else
		return val[sp];
	return 0.0;
}
void copyvalue(void)
{
	if (sp < 0)
		printf("error:copy failed\n");
	else
	{
		val[sp] = val[sp - 1];
		sp++;
	}
}
void swaptop(void)
{
	double temp;
	if (sp < 1)
		printf("error:swap failed\n");
	else {
		temp = val[sp];
		val[sp] = val[sp - 1];
		val[sp - 1] = temp;
	}
}
