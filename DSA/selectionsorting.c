// selection sorting
#include<stdio.h>
#include<math.h>
int main(){
	int i,j,n,temp,a[10],min,loc;
	printf("Enter the max no of element to sort: ");
	scanf("%d",&n);
	
	printf("Enter the element: \n");
	for(i=0;i<=n-1;i++){
		printf("Enter %d elment: ",i);
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<=n-1;i++){
		min=a[i];
		loc=i;
		for(j=i+1;j<=n-1;j++){
			if(a[j]<min){
				min=a[j];
				loc=j;
			}
		}
		if(loc!=i){
			temp=a[i];
			a[i]=a[loc];
			a[loc]=temp;
		}
	}
	printf("The sorted array is: ");
	for(i=0;i<n;i++){
		printf("%d \t",a[i]);
	}
	
	
	
	
	return 0;
}
