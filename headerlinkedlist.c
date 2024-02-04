#include<stdio.h>
#include<process.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*link;
};
typedef struct node*NODE;
NODE insertfront(NODE head,int item)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->link=NULL;
    cur=head->link;
    head->link=temp;
    temp->link=cur;
    head->info+=1;
    return head;
}
NODE insertrear(NODE head,int item)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->link=NULL;
    cur=head->link;
    while(cur->link!=head)
    {
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=head;
    head->info+=1;
    return head;
}
NODE deletefront(NODE head)
{
    NODE prev,cur;
    if(head->info==0)
    {
        printf("List is empty\nDeletion not possible\n");
        return head;
    }
    prev=head->link;
    cur=prev->link;
    printf("Deleted item is %d\n",prev->info);
    free(prev);
    head->link=cur;
    head->info-=1;
    return head;
}
NODE deleterear(NODE head)
{   NODE prev,cur;
    if(head->info==0)
    {
        printf("List is empty\nDeletion not possible\n");
        return head;
    }
    cur=head->link;
    prev=NULL;
    while(cur->link!=head)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("Deleted item is %d\n",cur->info);
    free(cur);
    prev->link=head;
    head->info-=1;
    return head;
} 