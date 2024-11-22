#include<stdio.h>
#include<conio.h>

int fib(int n);
int count = 0;
int main()
{
    int n,retval;
    printf("Enter the number to get fibonacci: ");
    scanf("%d",&n);
    retval = fib(n);
    
    printf("fib is %d \nRate of growth for %d is %d",retval,n,count);
    return 0;
}

int fib(int n){ 
    if(n<=1){
        count++;
        return n;
    }  else{
         count++;
        return fib(n-1) + fib(n-2);
    }      
}
