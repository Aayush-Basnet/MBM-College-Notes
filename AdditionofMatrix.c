#include<stdio.h>
int main(){
	
	int row,col;
	//int mat1[row][col],mat2[row][col],mat3[row][col],i,j;
	printf("Enter number of Row: ");
	scanf("%d",&row);
	printf("Enter number of Col: ");
	scanf("%d",&col);
	int mat1[row][col],mat2[row][col],mat3[row][col],i,j;
printf("\nEnter first matrix: \n");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
		printf("Enter element of mat1[%d][%d]: ",i+1,j+1);
		scanf("%d",&mat1[i][j]);
	}
}
	
	printf("\nEnter second matrix: \n");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
		printf("Enter element of mat2[%d][%d]: ",i+1,j+1);
		scanf("%d",&mat2[i][j]);
	}
}

for(i=0;i<row;i++){
	printf("\n");
	for(j=0;j<col;j++){
		printf("%d \t",mat1[i][j]);
	}
}
printf("\n");
for(i=0;i<row;i++){
	printf("\n");
	for(j=0;j<col;j++){
		printf("%d\t",mat2[i][j]);
	}
}
	
	//addtion of matrix
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			mat3[i][j]=mat1[i][j] + mat2[i][j];
		}
	}
	printf("\nResultant matrix is: \n");
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%d\t",mat3[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
