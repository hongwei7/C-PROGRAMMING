#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

int getline_(char *line);

int main(int argc,char *argv[])
{
    char line[MAXLINE];
    int found=0;
    if(argc!=2)
        printf("Usage: find patten\n");
    else
        while(getline_(line))
            if(strstr(line,argv[1])!=NULL){
                //printf("%s",line);
                found++;
            }
    printf("found\t%d lines\n\n",found);
    return found;
}
int getline_(char s[])
{
    char c;
    int i;
    for(i=0;i<MAXLINE&&(c=getchar())!=EOF&&c!='\n';i++)
    {
        s[i]=c;
    }
    if(c=='\n')
        s[i++]='\n';
    s[i]='\0';
    return i;
}