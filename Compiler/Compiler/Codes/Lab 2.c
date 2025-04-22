// WAP for comment validation
#include<stdio.h>
#include<conio.h>
int main() 
{ 
	char com[30];
	int i=2, x=0;
	printf("Enter comment:");
	gets(com);
	if(com[0]=='/') 
	{ 
 		if(com[1]=='/')
 			printf("\nIt is a comment");
 		else if(com[1]=='*') 
		{
 			for(i=2;i<=30;i++)
 			{
 				if(com[i]=='*'&&com[i+1]=='/')
 				{
 					printf("\nIt is a comment");
 					x=1;
 					break; 
				}
 				else
 					continue; 
			}
 			if(x==0)
 				printf("\nIt is not a comment");
 		}
 		else
 			printf("\nIt is not a comment"); 
	}
	else 
 		printf("\nIt is not a comment");
	return 0; 
}

