#include<stdio.h>
#include<stdlib.h>
#define stacksize 3
void push(int item,int *top,int s[])
{
    if(*top==stacksize-1)
    {
        printf("Stack overflow\n");
        return;
    }
    *top+=1;
    s[*top]=item;
}
int pop(int *top,int s[])
{
    int item;
    if(*top==-1)
    {
        return -1;
    }
    item=s[*top];
    *top-=1;
    return item;
}
void display(int top,int s[])
{
    int i;
    if(top==-1)
    {
        printf("No elements present in stack");
        return;
    }
    for(i=0;i<=top;i++)
    {
        printf("%d\n",s[i]);
    }
}
void main()
{
    int top,choice,item,res,s[40];
    top=-1;
    for(;;){
        printf("1-Push\t2-Pop\t3-Display\nAnyOtherNum-Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter item to push:");
                   scanf("%d",&item);
                   push(item,&top,s);
                   break;
            case 2:res=pop(&top,s);
                   if(res==-1)
                   {
                        printf("Stack underflow\n");
                   }
                   else{
                    printf("Deleted item is %d\n",res);
                   }
                   break;
            case 3:display(top,s);
                   break;
            default:exit(0);
        }
    }
}