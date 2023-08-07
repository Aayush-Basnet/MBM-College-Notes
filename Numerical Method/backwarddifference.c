#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x)(a*x*x+b*x+c)


int main(){
	float a,b,c;
	float x,h,fx,fxh,dfx;
	printf("Enter value of a,b and c: ");
	scanf("%f %f %f",&a,&b,&c);
	printf("Enter the value at which derivative is needed,x: ");
	scanf("%f",&x);
	printf("Enter interval gap,h: ");
	scanf("%f",&h);
//	x=(PI/180)*x;
	fx=f(x);
	fxh=f(x-h);
	dfx=(fx-fxh)/h;
	printf("Enter value of derivative:%f ",dfx);
	
return 0;	
}