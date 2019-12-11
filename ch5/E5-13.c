#include <stdio.h>
#include<ctype.h>
#define MAXLINES 200
char *lineptr[MAXLINES];
int lineptrp=0;
char alloc[10000];
char* allocp=alloc;
int getline_()
{
    char c;
    lineptr[lineptrp++]=allocp;
    while((c=getchar())!='0'&&c!=EOF && c!='\n'&&allocp-10000<alloc)
    {
        *(allocp++)=c;
    }
    if(allocp>10000+alloc){
        printf("out of range!\n");
        lineptrp--;
        return 0;
    }
    if(allocp==lineptr[lineptrp-1]){
        lineptrp--;
        return 0;
    }
    *(allocp++)='\0';
    return 1;
}
int main(int argc,char *argv[])
{
    if(argc!=2){
        printf("Usage:\ttail -n \n");
        return 1;
    }
    int k=1,n=3;
    if(argv[1][0]=='-'){
        n=0;
        while(isdigit(argv[1][k]))
            n=10*n+argv[1][k++]-'0';
    }
    else
        {
            printf("Usage:\ttail -n \n");
            return 1;
        }
    if(argv[1][k]!='\0'){
            printf("Usage:\ttail -n \n");
            return 1;
        }
    printf("n=\t%d\n",n);
    while(getline_());
    for(int i=(lineptrp-n>0)?(lineptrp-n):0;i<lineptrp;i++)
        printf("%s\n",lineptr[i]);
    return 0;
}

