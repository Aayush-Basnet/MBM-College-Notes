#include <stdio.h>

int main(){
	int i,n,inv,m;
	printf("Enter the modulo value:");
	scanf("%d",&m);
	printf("Additive Inverse\n");
	for(i=0;i<m;i++){
		printf("%d=%d\n",i,inv=(m-i)%m);
	}
	
}
