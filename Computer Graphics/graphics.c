// Digitize the line with endpoints (x1,y1) and (x2,y2) using DDA.
#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void main(){
int x,y,x1,x2,y1,y2,p,dx,dy;
int gd=DETECT,gm;
initgraph(&gd,&gm,"   ");
printf("Enter the starting point: ");
scanf("%d %d",&x1,&y1);
printf("Enter the Ending point: ");
scanf("%d %d",&x2,&y2);
x=x1;
y=y1;
dx=x2-x1;
dy=y2-y1;
putpixel(x,y,2);
p=(2*dy-dx);
while(x<=x2){
    if(p<0){
        x=x+1;
        p=p+2*dy;
    }else{
        x=x+1;
        y=y+1;
        p=p+(2*dy)-(2*dx);
    }
    putpixel(x,y,7);
}
getch();
closegraph();
}
