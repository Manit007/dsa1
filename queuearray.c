#include<stdio.h>
#include<stdlib.h>
#define queuesize 3
void insert(int item,int *r,int q[])
{
    if(*r==queuesize-1)
    {
        printf("Queue is full\n");
        return;
    }
    *r=*r+1;
    q[*r]=item;
}
void delete(int *r,int *f,int q[])
{
    int item;
    if(*f>*r)
    {
        printf("No elements in queue\nDeletion not possible\n");
        return;
    }
    item=q[*f];
    printf("Deleted item is %d\n",item);
    *f=*f+1;
    if(*f>*r)
    {
        *r=-1;
        *f=0;
    }
}
void display(int r,int f,int q[])
{
    int i;
    if (f>r)
    {
        printf("No elements present in queue\n");
        return;
    }
    printf("Queue elements are:\n");
    for(i=f;i<=r;i++)
    {
        printf("%d\n",q[i]);
    }
}
void main()
{
    int f,r,choice,item,q[20];
    r=-1;
    f=0;
    for(;;){
        printf("1-Insert\t2-Delete\t3-Display\nAnyOtherNum-Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter item to push:");
                   scanf("%d",&item);
                   insert(item,&r,q);
                   break;
            case 2:delete(&r,&f,q);
                   break;
            case 3:display(r,f,q);
                   break;
            default:exit(0);
        }
    }
}
