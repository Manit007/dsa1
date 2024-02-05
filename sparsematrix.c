#include<stdio.h>
#include<stdlib.h>
struct sparsematrix
{
    int row;
    int column;
    int value;
};
typedef struct sparsematrix MATRIX;
void main()
{
    int m,n,k,count,i,j,item,key;
    MATRIX a[100];
    printf("Enter the number of rows:");
    scanf("%d",&m);
    printf("Enter the number of columns:");
    scanf("%d",&n);
    a[0].row=m;
    a[0].column=n;
    k=1;
    count=0;
    printf("Enter the elements of the matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&item);
            if(item!=0)
            {
                a[k].row=i+1;
                a[k].column=j+1;
                a[k].value=item;
                k++;
                count++;
            }
        }
    }
    a[0].value=count;
    printf("Enter element to be searched:");
    scanf("%d",&key);
    for(i=1;i<=a[0].value;i++)
    {
        if(a[i].value==key)
        {
            printf("%d found successfully at position:\n",key);
            printf("%d %d\n",i,j);
            printf("Row=%d\tColumn=%d\n",a[i].row,a[i].column);
            exit(0);
        }
    }
    printf("Search Unsuccessful");
}