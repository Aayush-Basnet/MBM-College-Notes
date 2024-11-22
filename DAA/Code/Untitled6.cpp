#include <stdio.h>
int array[50],i,j,temp,n,min=0,count=0;

int main()
{
	printf("Enter the size\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			count++;
			if(array[j]<array[min])
				{
					min=j;
				}
			
			
		}
		temp=array[i];
		array[i]=array[min];
		array[min]=temp;
	}
for(i=0;i<n;i++)
	{
		printf("%d\t",array[i]);
	}

	printf("%d",count);

}s
