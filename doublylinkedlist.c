#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*llink;
    struct node*rlink;
};
typedef struct node*NODE;
NODE insertfront(int item,NODE first)
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(first==NULL)
    {
        return temp;
    }
    temp->rlink=first;
    first->llink=temp;
    first=temp;
    return temp;
}
NODE insertrear(int item, NODE first)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->rlink=NULL;
    temp->llink=NULL;
    if(first==NULL)
    {
        return temp;
    }
    if (first->rlink==NULL)
    {
        first->rlink=temp;
        temp->llink=first;
        return first;
    }
    cur=first;
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;
    return first;
}
NODE deletefront(NODE first)
{
    
}