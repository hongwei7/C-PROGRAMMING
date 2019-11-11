#include<stdio.h>
#include<time.h>
int old_bin_search(int x,int v[],int n)
{
    int low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(x<v[mid])
            high=mid-1;
        else if(x>v[mid])
            low=mid+1;
        else
            return mid;
    }
    return -1;
}
int bin_search(int x,int v[],int n)
{
    int low=0,high=n-1,mid;
    while(low<high){
        mid=(low+high)/2;
        if(x<v[mid])
            high=mid-1;
        else 
            low=mid+1;
    }
    if(v[high]==x)
        return high;
    else
        return -1;
}
main()
{
    int v[]={0,1,2,3,4,5,6,7,8,9,12,14,51,235,333,500};
    int x=235,old,new;
    clock_t t1,t2;
    t1=clock();
    old=old_bin_search(x,v,16);
    t1=(double)(clock()-t1);
    t2=clock();
    new=bin_search(x,v,16);
    t2=(clock()-t2);
    printf("\t%s\t%s\n","old","new");
    printf("result\t%4d\t%4d\n",  old,new);
    printf("time\t%4lu\t%4lu\n",t1,t2);
}

