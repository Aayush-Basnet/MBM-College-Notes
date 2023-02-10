#include<stdio.h>
int main(){
	int i,j;
	for(i=5;i>0;i--){
		for(j=5;j>0;j--){
			if(j<=i){
				if(j%2!=0){
					printf("0");
				}else
					printf("1");
				}else
				printf(" ");
			}
			printf("\n");
		}
	
	
	
	
	return 0;
}
