#include<stdio.h>
int binsearch(int a[],int k,int low,int high)
{
    int mid;
    if(low>high)
    {
        return -1;
    }
    mid=(high+low)/2;
    if(a[mid]==k)
    {
        return mid+1;
    }
    if(k>a[mid])
    {
        return(binsearch(a,k,mid+1,high));
    }
    return(binsearch(a,k,low,mid-1));
}
void main()
{
    int i,j,a[30],n,key,res;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key to be searched:");
    scanf("%d",&key);
    res=binsearch(a,key,0,n-1);
    if(res==-1)
    {
        printf("Search unsuccessful");
    }
    else{
        printf("Element found successfully at position %d",res);
    }
}