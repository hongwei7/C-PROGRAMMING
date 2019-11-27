#include <stdio.h>
//一个以栈形式保存数据的地址运算
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
int main()
{
    printf("Hello world\n");
    int get_space=20;
    char * p= alloc(get_space);
    for(int i=0;i<get_space-1;i++)
        p[i]='N';
    p[get_space]='0';
    printf("get\t%s\n",p);
    return 0;
}

