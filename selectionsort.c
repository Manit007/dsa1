#include<stdio.h>
void main(){
    int n,a[50],i,j,position,temp;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the %d numbers:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        position=i;
        for(j=i+1;j<n;j++)
        {
            if(a[position]>a[j])
            {
                position=j;
            }
        }
        if(position!=i)
        {
            temp=a[i];
            a[i]=a[position];
            a[position]=temp;
        }
    }
    printf("Sorted list in ascending order is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}