#include<stdio.h>
int linsearch(int n,int s[],int k)
{
    if(n==0)
    {
        return -1;
    }
    if(k==s[n-1])
    {
        return n;
    }
    return(linsearch(n-1,s,k));
}
void main()
{
    int n,i,a[20],k,res;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key to be searched:");
    scanf("%d",&k);
    res=linsearch(n,a,k);
    if(res==-1)
    {
        printf("Search Unsuccessful");
    }
    else
    {
        printf("Element Successfully found at position %d",res);
    }
}