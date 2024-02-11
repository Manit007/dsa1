#include<stdio.h>
#include<stdlib.h>
#define stacksize 50
void push(int address,int *top,int s[])
{
    if(*top==stacksize-1)
    {
        printf("Cannot push more websites back\nStack overflow\n");
        return;
    }
    *top+=1;
    s[*top]=address;
}
int pop(int *top, int s[])
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
void display(int top, int s[])
{
    int i;
    if(top==-1||top==0)
    {
        printf("No websites before current one\n");
        return;
    }
    printf("Website addresses before current website are:\n");
    for(i=top-1;i>=0;i--)
    {
        printf("%d\n",s[i]);
    }
}
void main()
{
    int choice,res,address, top, s[50];
    top=-1;
    push(43242,&top,s);
    push(865936,&top,s);
    push(803284,&top,s);
    while(top!=stacksize)
    {
        printf("1-To load previous page\n2-To go to a new page\n3-To display pages in back\n");
        printf("AnyOtherNum-To exit the application:\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:printf("Going back to previous website\n");
                   res=pop(&top,s);
                   if(res==-1)
                   {
                    printf("No websites stored:\n");
                   }
                   else
                   {
                    printf("Address of previous page is %d\nGoing to that page\n",res);
                   }
                   break;
            case 2:printf("Enter address of new page:");
                   scanf("%d",&address);
                   push(address,&top,s);
                   printf("New page is loaded:\n");
                   break;
            case 3:display(top,s);
                   break;
            default:exit(0);
        }
    }
}