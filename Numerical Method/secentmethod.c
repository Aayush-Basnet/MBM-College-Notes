#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x)(a3*x*x*x+a2*x*x+a1*x+a0)
float a0,a1,a2,a3;
int main(){
	float x0,x1,x2,fx0,fx1,fx2,E,Era;
	printf("Enter the coefficients a3,a2,a1 and a0: ");
	scanf("%f %f %f %f",&a3,&a2,&a1,&a0);

	printf("Enter initial guess x0 and x1: ");
	scanf("%f %f",&x0,&x1); 
	printf("Enter the error tolerance E: ");
	scanf("%f",&E);

	fx0=f(x0); 
	fx1=f(x1); 

	while(1){
		fx0=f(x0); 
	 fx1=f(x1); 
		x2=x1-(fx1*(x1-x0)/(fx1-fx0)); 
	fx2=f(x2);  
		Era=(x2-x1)/x2;
		
		if(fabs(Era)<E){
			printf("Root = %f ",x2);
			break;
		}
	x0=x1;
	x1=x2;
		
	}	
	getch();
}
