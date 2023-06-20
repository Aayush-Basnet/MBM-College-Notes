//Bisection Method
#include<stdio.h>
#include<conio.h>
#include<math.h>
int a0,a1,a2,a3;
float f(float x){
	return (a3*x*x*x+a2*x*x+a1*x+a0);
}
int main(){
	float xl,xm,xu,fxl,fxm,fxu,E,Era;
	printf("Enter the coefficients a3,a2,a1 and a0: ");
	scanf("%d %d %d %d",&a3,&a2,&a1,&a0);
	printf("Enter initail bracket and E: ");
	scanf("%f %f %f",&xl,&xu,&E);
	fxl=f(xl);
	fxu=f(xu);
	
	if((fxl*fxu)>0)
		printf("Invalid Inputs! \n");
	else{
		while(1){
			fxl=f(xl);
			fxu=f(xu);
			xm=(xl+xu)/2;
			fxm=f(xm);
			
		if((fxl*fxm)==0)
		printf("Root =%f \n",xm);
		else if((fxl*fxm)<0)
			xu=xm;
		else
			xl=xm;
			
		Era=(xu-xl)/xu;
		if(Era<E){
			printf("Root =%f \n",xm);
			break;
		}
		}
	}
	getch();
	

}