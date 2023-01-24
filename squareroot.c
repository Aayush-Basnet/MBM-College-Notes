#include<stdio.h>
#include<conio.h>
#include<math.h>

void main(){
clrscr();

float n,s;
printf("Enter a number: ");
scanf("%f",&n);

s=sqrt(n);
printf("Square root of %f is %.2f",n,s);
getch();
}
