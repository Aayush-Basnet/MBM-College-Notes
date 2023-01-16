//WAP to display first n prime number
#include<stdio.h>
int main(){
	int n,count=1,flag,i=2,j;
	
	printf("Enter how many prime number? ");
	scanf("%d",&n);
	
	while(count<=n){
	
	flag=0;
	
	for(j=2;j<=i/2;j++){
		if(i%j==0){
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("%d\t",i);
		count++;
	}
	i++;
}
	
	return 0;
}
