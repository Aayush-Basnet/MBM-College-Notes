#include<stdio.h>
#include<conio.h>
#include<graphics.h>
float round(float a);
void main(){
	int gd=DETECT,gm;
	int x1,x2,y1,y2,x,y,steps,k;
	float xincr,yincr,x,y,dx,dy;
	printf("Enter x1 and y1: ");
	scanf("%d %d",&x1,&y1);
	printf("Enter x2 and y2: ");
	scanf("%d %d",&x2,&y2);
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
	steps=abs(dy);
	
	xincr=dx/steps;
	yincr=dy/steps;
	
	x=x1;
	y=y1;
	
	for(k=1;k<steps;k++){
		delay(100);
		x+=xincr;
		y+=yincr;
		putpixel(round(x),round(y),WHITE);
	}
	outtext(200,200,"Prepared By Aayush Basnet");
	outtext(200,20,"DDA");
	outtext(x1+5,y1-5,"(x1,y1)");
	outtext(x2+5,y2+5,"(x2,y2)");
	
	getch();
	closegraph();
}
