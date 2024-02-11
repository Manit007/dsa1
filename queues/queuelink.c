#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*link;
};
typedef struct node*NODE;
NODE insertrear(int item,NODE first)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)
    {
        first=temp;
        return first;
    }
    cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    return first;
}
NODE deletefront(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Queue empty\nDeletion not possible\n");
        return first;
    }
    temp=first;
    first=first->link;
    printf("Deleted item is %d\n",temp->info);
    free(temp);
    return first;
}
void display(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents are:\n");
    cur=first;
    while(cur!=NULL)
    {
        printf("%d\n",cur->info);
        cur=cur->link;
    }
}
void main()
{
    int choice,item;
    NODE first;
    first=NULL;
    for(;;){
        printf("1-Insert\t2-Delete\t3-Display\nAnyOtherNum-Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter item to push:");
                   scanf("%d",&item);
                   first=insertrear(item,first);
                   break;
            case 2:first=deletefront(first);
                   break;
            case 3:display(first);
                   break;
            default:exit(0);
        }
    }
}