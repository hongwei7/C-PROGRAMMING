#include<stdio.h>
#include<string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];//指向文本行的指针数组
int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);

void qsort(char *lineptr[],int left,int right);

int main()
{
    int nlines;//读取的输入行数目

    if((nlines=readlines(lineptr,MAXLINES))>=0){
        qsort(lineptr,0,nlines-1);
        writelines(lineptr,nlines);
        return 0;
    }
    else{
        printf("error:input too big to sort\n");
        return 1;
    }
}   
#define MAXLEN 1000//每行最大长度
int getline1(char *,int);
char *alloc(int);

//读取输入行
int readlines(char *lineptr[],int maxlines)
{
    int len,nlines;
    char *p,line[MAXLEN];
    nlines=0;
    while((len=getline1(line,MAXLEN))>0)
        if(nlines>=maxlines||(p=alloc(len))==NULL)
            return -1;
        else{
            line[len-1]='\0';
            strcpy(p,line);
            lineptr[nlines++]=p;
        }
    return nlines;
}


//写输出行
void writelines(char *lineptr[],int nlines)
{
    for (int i = 0; i < nlines; ++i)
    {
        printf("%s\n",lineptr[i] );
    }
}
int getline1(char *s,int MAXSIZE)
{
    char c;
    int i;
    for(i=0;i<MAXSIZE&&(c=getchar())!=EOF&&c!='\n';i++)
    {
        s[i]=c;
    }
    if(c=='\n')
        s[i++]='\n';
    s[i]='\0';
    return i;
}
#define ALLOCSIZE 10000//可用大小
static char allocbuf[ALLOCSIZE];//alloc使用的存储区
static char *allocp =allocbuf; //下一个空闲位置

char *alloc(int n)//返回指向n个字符的指针
{
    if(allocbuf+ALLOCSIZE-allocp>=n){ //有足够空间
        allocp +=n;
        return allocp-n;
    } else
        return 0;
}
void afree(char *p)//释放p指向的存储区
{
    if(p>=allocbuf&&p<allocbuf+ALLOCSIZE)
        allocp=p;
}
void qsort(char *v[],int left,int right)
{
    int i,last;
    void swap(char *v[],int i,int j);
    if(left>=right)//元素数小于2
        return;
    swap(v,left,(left+right)/2);
    last=left;
    for(i=left+1;i<right;i++)
        if(strcmp(v[i],v[left])<0)
            swap(v,++last,i);
    swap(v,left,last);
    qsort(v,left,last-1);
    qsort(v,last+1,right);
}
void swap(char *v[],int i,int j)
{
    char *temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}



