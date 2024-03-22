#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
int maxheap(int item,int a[],int n)
{
    int c,p;
    if(n==MAXSIZE-1)
    {
        printf("Heap is full\n");
        return n-1;
    }
    c=n;
    p=c/2;
    while(p!=0&&item>a[p])
    {
        a[c]=a[p];
        c=p;
        p=c/2;
    }
    a[c]=item;
    return n;
}
