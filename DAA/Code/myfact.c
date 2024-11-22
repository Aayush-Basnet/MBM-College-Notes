#include<stdio.h>
#include<conio.h>

int fact(int n);
int count = 0;

int main()
{
    int n,retval;
    printf("Enter the number to get factorial: ");
    scanf("%d",&n);
    retval = fact(n);
    
    printf("fact is %d \nRate of growth for %d is %d",retval,n,count);
    return 0;
}

int fact(int n)
{
    count++;
    if(n==0)
        return 1;
    else
        return n * fact(n-1);
}
