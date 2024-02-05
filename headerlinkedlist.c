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
void display(NODE head)
{
    NODE cur;
    if(head->info==0)
    {
        printf("List is empty\n");
        return;
    }
    cur=head->link;
    while(cur!=head)
    {
        printf("%d\n",head->info);
        cur=cur->link;
    }
}
void main(){
    int choice,item;
    NODE head;
    head=(NODE)malloc(sizeof(struct node));
    head->info=0;
    head->link=head;
    for(;;){
        printf("1-Insertfront\t2-Insertrear\n3-Deletefront\t4-Deleterear\n5-Display\tAnyOtherNum-Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter item to insert:");
                   scanf("%d",&item);
                   head=insertfront(head,item);
                   break;
            case 2:printf("Enter item to insert:");
                   scanf("%d",&item);
                   head=insertrear(head,item);
                   break;
            case 3:head=deletefront(head);
                   break;
            case 4:head=deleterear(head);
                   break;
            case 5:display(head);
                   break;
            default:exit(0);
        }
    }
}