#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*link;
};
typedef struct node*NODE;
NODE insertfront(int item,NODE first)
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->link=first;
    first=temp;
    return first;
}
NODE deletefront(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("Stack empty\nDeletion not possible\n");
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
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents are:\n");
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
        printf("1-Push\t2-Pop\t3-Display\nAnyOtherNum-Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter item to push:");
                   scanf("%d",&item);
                   first=insertfront(item,first);
                   break;
            case 2:first=deletefront(first);
                   break;
            case 3:display(first);
                   break;
            default:exit(0);
        }
    }
}