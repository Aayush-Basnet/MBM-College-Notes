
#include<stdio.h>
int main(){
	int i,n;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	int a[n];
	
	printf("Input %d element in array \n",n);
	for(i=0;i<n;i++){
		printf("Enter element for index[%d]: ",i);
		scanf("%d",&a[i]);
	}
	printf("\n The value stores in array are: \n");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	printf("\nArray in reverse order are: \n");
	for(i=n-1;i>=0;i--){
		printf("%d\t",a[i]);
	}
	
	
	return 0;
}
