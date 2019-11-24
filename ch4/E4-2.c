#include<stdio.h>
double str_to_double(char *t)
{
    double k=0,result=0;
    char *p=t;
    bool doted=false,negitive=false,_e=false,_e_sign=true;
	switch(*p)
    {
        case('n'):return 0.0;
        case('i'):return 1.79769e+308;
    }
    if(*(p+1)=='i')
    {
        return -1.79769e+308;
    }
    while(true)
    {
        if(_e)
        {
            int power=int(str_to_double(p));
            for(int i=0;i<power;i++)
            {
                if(_e_sign)result=result*10;
                else result=result/10;
            }
            break;
        }
        else
        {
            if(*(p)=='-'&&!_e)
            {
                negitive=true;
            }
            else if(*p=='e')
            {
                _e=true;
                p++;
                if(*p=='-')_e_sign=false;
                else if(*p!='+')continue;
            }
            else
            {
                if(*(p)!='\0')
                {
                    if(*(p)!='.')
                    {
                        if(!doted)result=result*10+int(*p-48);
                        if(doted){result=result+k*int(*p-48);k*=0.1;}
                    }
                    else
                    {
                        doted=true;
                        k=0.1;
                    }
                }
                else
                {
                    if(negitive)result=-result;
                    return result;
                }
            }
        }
        p++;
    }
    if(negitive)result=-result;
    return result;
}
int main()
{
	char s[]="-1.44e-4";
	printf("%s   %f  \n",s,str_to_double(s));
}
