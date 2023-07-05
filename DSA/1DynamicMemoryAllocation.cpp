#include <stdio.h>
#include <stdlib.h>
int main(){
    
    //Initializing n for no. of element, i for loop, sum for storing sum and *ptr for storing base address of block.
    int i,n,sum=0,*ptr;
    
    //Asking user to input number of elements
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    
    //malloc() declaration
    ptr= (int*)malloc(n*sizeof(int));
    
    //Asking user to input n elements
    for(i=0;i<n;i++){
        printf("Enter number %d : ", i+1);
        scanf("%d",&ptr[i]);
        sum= sum+ ptr[i];
    }
    
    //Displaying the entered numbers
    printf("\n Entered numbers are: ");
    for(i=0;i<n;i++){
        printf("%d , ",ptr[i]);
    }
    //Displaying the sum 
    printf("\n The sum of entered numbers after malloc is %d.\n ", sum);
    
    //Intialize sum=0 for reallocation.
    sum=0;
    //Asking the new value of n from the user.
    printf("\nEnter the new number of elements: ");
    scanf("%d",&n);
    
    //realloc() declaration.
    ptr= (int*)realloc(ptr, n*sizeof(int));
    
    //Asking user to enter n numbers.
    for(i=0;i<n;i++){
        printf("Enter number %d : ", i+1);
        scanf("%d",&ptr[i]);
        sum= sum+ ptr[i];
    }
    
    //Displaying the entered numbers.
    printf("\n Entered numbers are: ");
    for(i=0;i<n;i++){
        printf("%d , ",ptr[i]);
    }
    //Displaying the sum after reallocation.
    printf("\n The sum of entered numbers after reallocation is %d.", sum);
    
    return 0;
}
