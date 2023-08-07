#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x)(sin(x)+1)

#define PI 3.1415
void main(){
	float x,h,fx,fxh,dfx;
	
	printf("Enter the value at which derivative is needed,x: ");
	scanf("%f",&x);
	printf("Enter interval gap,h: ");
	scanf("%f",&h);
	x=(PI/180)*x;
	fx=f(x);
	fxh=f(x+h);
	dfx=(fxh-fx)/h;
	printf("value of fx: %f",fx);
	printf("Enter value of derivative:%f ",dfx);
	
	
}