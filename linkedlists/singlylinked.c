#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*link;
};
typedef struct node*NODE;
NODE insertfront(NODE first,int item)
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)
    {
        return temp;
    }
    temp->link=first;
    first=temp;
    free(temp);
    return first;
}
NODE insertrear(NODE first,int item)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)
    {
        return temp;
    }
    cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    free(temp);
    return first;
}
NODE deletefront(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("Deletion not possible\nList is empty\n");
        return first;
    }
    cur=first;
    first=first->link;
    printf("Deleted item is %d\n",cur->info);
    free(cur);
    return first;
}
NODE deleterear(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("Deletion not possible\nList is empty\n");
        return first;
    }
    if(first->link==NULL)
    {
        printf("Deleted item is %d\n",first->info);
        return NULL;
    }
    cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    printf("Deleted item is %d\n",cur->info);
    free(cur);
    return first;
}
void printelements(NODE first)
{
    NODE cur;
    if(first==NULL)
    {
        printf("List is empty\n");
        return;
    }
    cur=first;
    while(cur!=NULL)
    {
        printf("%d-->",cur->info);
        cur=cur->info;
    }
    printf("-->NULL");
    return;
}
