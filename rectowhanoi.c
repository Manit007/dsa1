#include<stdio.h>
int count = 0;
void tower(int n, char source, char destination, char temp)
{
    if(n==1)
    {
        printf("move %d disc from %c to %c\n",n,source,destination);
        count++;
        return;
     }
    tower(n-1, source, temp, destination);
    printf("move %d disc from %c to %c\n",n,source,destination);
    count++;
    tower(n-1, temp, destination, source);
}
void main( )
{
int n;
printf("enter the number of discs\n");
scanf("%d",&n);
tower(n,'a','c','b');
printf("the total number of disc moves=%d",count);
}