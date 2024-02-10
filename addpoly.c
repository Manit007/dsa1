#include<stdio.h>
#include<stdlib.h>
struct node
{
    int cf;
    int px;
    struct node*link;
};
typedef struct node*NODE;
void display(NODE head)
{
    NODE cur;
    if(head->link==head)
    {
        printf("Polynomial does not exist");
        return;
    }
    cur=head->link;
    while(cur!=head)
    {
        if(cur->cf>0)
        {
            printf();
        }
    }
}