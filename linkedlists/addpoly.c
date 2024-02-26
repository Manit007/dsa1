#include<stdio.h>
#include<stdlib.h>
struct node
{
    int cf;
    int px;
    struct node*link;
};
typedef struct node*NODE;
NODE insertrear(int cf,int px,NODE head);
NODE readpoly(NODE head);
int compare(int x,int y);
NODE addpoly(NODE h1,NODE h2,NODE h3);
 void display(NODE head)
{
    NODE cur;
    if(head->link==head)
    {
        printf("Polynomial does not exist\n");
        return;
    }
    cur=head->link;
    while(cur!=head)
    {
        if(cur->cf==0)
        {
            printf("+");
        }
        printf("%dx^%d",cur->cf,cur->px);
        cur=cur->link;
    }
}
NODE readpoly(NODE head)
{
    int n,i,cf,px;
    printf("ENter the number of terms in a polynomial");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter coefficient and power of x:");
        scanf("%d)",&cf);
        scanf("%d)",&px);
        head=insertrear(cf,px,head);
    }
    return head;
}
NODE insertrear(int cf,int px,NODE head)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->cf=cf;
    temp->px=px;
    temp->link=temp;
    cur=head->link;
    while(cur->link!=head)
    {
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=head;
    return head;
}
void main()
{
    NODE h1,h2,h3;
    h1=(NODE)malloc(sizeof(struct node));
    h1->link=h1;
    h2=(NODE)malloc(sizeof(struct node));
    h2->link=h2;
    h3=(NODE)malloc(sizeof(struct node));
    h3->link=h3;
    printf("Enter the first polynomial:");
    h1=readpoly(h1);
    printf("Enter the second polynomial:");
    h2=readpoly(h2);
    h3=addpoly(h1,h2,h3);
    printf("First polynomial and second polynomial is :\n");
    display(h1);
    display(h2);
    printf("Resultant polynomial is :\n");
    display(h3);
}
NODE addpoly(NODE h1,NODE h2,NODE h3)
{
    NODE p1,p2;
    int sumcf;
    p1=h1->link;
    p2=h2->link;
    while(p1!=h1 && p2!=h2)
    {
        switch(compare(p1->px,p2->px))
        {
            case 0: sumcf=p1->cf+p2->cf;
                    if(sumcf!=0)
                    {
                        h3=insertrear(sumcf,p1->px,h3);
                    }
                    p1=p1->link;
                    p2=p2->link;
                    break;
            case 1: h3=insertrear(p1->cf,p1->px,h3);
                    p1=p1->link;
                    break;
            case -1:h3=insertrear(p2->cf,p2->px,h3);
                    p2=p2->link;
                    break;
        }
    }
    while(p1!=h1)
    {
        h3=insertrear(p1->cf,p1->px,h3);
        p1=p1->link;
    }
    while(p2!=h2)
    {
        h3=insertrear(p2->cf,p2->px,h3);
        p2=p2->link;
    }
    return h3;
}
int compare(int x,int y)
{
    if(x>y)
    {
        return 1;
    }
    if(x==0)
    {
        return 0;
    }
    return -1;
}