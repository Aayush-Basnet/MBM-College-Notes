#include<stdio.h>
#define ROW 10
#define COL 10
int main(){
	
	int mat1[ROW][COL],mat2[ROW][COL],mat3[ROW][COL],i,j,k,r1,r2,c1,c2,sum=0;
	printf("Enter the row and column of first matrix: ");
	scanf("%d %d",&r1,&c1);
	printf("Enter the row and column of second matrix: ");
	scanf("%d %d",&r2,&c2);
	if(c1!=r2){
		printf("Matrix multiplication is not possible \n");
		exit(0);
	}
	
	printf("Enter first matrix: \n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			printf("Enter element of mat1[%d][%d]: ",i+1,j+1);
			scanf("%d",&mat1[i][j]);
		}
	}
	
	printf("Enter second matrix: \n");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			printf("Enter element of mat2[%d][%d]: ",i+1,j+1);
			scanf("%d",&mat2[i][j]);
		}
	}
	
	for(i=0;i<r1;i++){
		printf("\n");
		for(j=0;j<c1;j++){
			printf("%d\t",mat1[i][j]);
		}
	}
	printf("\n");
	for(i=0;i<r2;i++){
		printf("\n");
		for(j=0;j<c2;j++){
			printf("%d\t",mat2[i][j]);
		} 
	}
	//multiplicationusing arrray
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			for(k=0;k<r2;k++){
				sum+=mat1[i][k]*mat2[k][j];
			}
			mat3[i][j]=sum;
			sum=0;
		}
	}
	
	printf("\nProduct matrix is: \n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			printf("%d\t",mat3[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	
	
	return 0;
}
