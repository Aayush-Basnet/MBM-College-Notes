#include<stdio.h>
int gcd(int n1, int n2) {
    if (n2 != 0)
        return gcd(n2, n1 % n2);
    else
        return n1;
}
void main()
{
 	int s,m,i,num,MI,j;

 	printf("Enter the modulo value:\n");
 	scanf("%d",&m);
 	for(j=0;j<m;j++){
 		if(gcd(j,m)==1){
 			for(i=1;i<=j;i++)
 			{
  				s=((i*m)+i);
  				MI=s%m;
  				if(MI%j==0)
  				{
   					break;
  				}
 			}
 			printf("Multiplicative inverse of %d is %d\n",j,MI);
 	 }
 	 else{
 			printf("Multiplicative inverse of %d can not be calculated\n",j);
		 }
	}
}
