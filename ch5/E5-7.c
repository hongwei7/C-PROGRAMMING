#include<stdio.h>
#include<string.h>
#include <time.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];//指向文本行的指针数组
int readlines(char *lineptr[], int nlines, char **p, char *start);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);


int read_write()
{
    int nlines;//读取的输入行数目
    char allocbufmain[10000];
    char *now = allocbufmain;
    if ((nlines = readlines(lineptr, MAXLINES, &now, allocbufmain)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 1;
    }
    else {
        printf("error:input too big to sort\n");
        return 0;
    }
}
int main()
{
    read_write();
}
#define MAXLEN 1000//每行最大长度
int getline1(char *, int);
char *alloc(int);//原版本
char *allocmain(int n, char **p, char *start); //主函数初始化存储空间

//读取输入行
int readlines(char *lineptr[], int maxlines, char **now, char *start)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    clock_t t1, t2;
    while ((len = getline1(line, MAXLEN)) > 0) {
        printf("alloc within main used time:\t");
        t1 = clock();
        p = allocmain(len, now, start);
        t2 = clock();
        printf("%ld\n", t2 - t1);
        if (nlines >= maxlines || (p) == NULL)
            //if(nlines>=maxlines||(p=alloc(len))==NULL)
            //-----------！！！！！！！---在主函数中有存储空间---！！！！！！！！-------
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
        printf("alloc beyond main used time:\t");
        //-----------！！！！！！！---原版本---！！！！！！！！-------

        t1 = clock();
        p = alloc(len);
        t2 = clock();
        printf("%ld\n", t2 - t1);

    }
    printf("\n");
    return nlines;
}


//写输出行
void writelines(char *lineptr[], int nlines)
{
    for (int i = 0; i < nlines; ++i)
    {
        printf("%s\n", lineptr[i] );
    }
}
int getline1(char *s, int MAXSIZE)
{
    char c;
    int i;
    for (i = 0; i < MAXSIZE && (c = getchar()) != EOF && c != '\n'; i++)
    {
        s[i] = c;
    }
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}
#define ALLOCSIZE 10000//可用大小
static char allocbuf[ALLOCSIZE];//alloc使用的存储区
static char *allocp = allocbuf; //下一个空闲位置

char *alloc(int n)//返回指向n个字符的指针
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { //有足够空间
        allocp += n;
        return allocp - n;
    } else
        return 0;
}
char *allocmain(int n, char **p, char *start) //返回指向n个字符的指针（主函数有储存空间）
{
    if (start + ALLOCSIZE - *p >= n) { //有足够空间
        *p += n;
        return *p - n;
    } else
        return 0;
}
void afree(char *p)//释放p指向的存储区
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
void swap(char *v[], int i, int j);
void qsort(char *v[], int left, int right)
{
    int i, last;
    if (left >= right) //元素数小于2
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i < right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
void swap(char *v[], int i, int j)
{
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}



