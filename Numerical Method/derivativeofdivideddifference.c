
#include<stdio.h>
int main()
{
int n,i,j,k;
float fx[10],ax[10],dd[10],xv,p,v;
printf( "enter number of points:");
scanf("%d",&n);
printf("enter the value for interpolation:");
scanf("%f",&xv);
for(i=0;i<n;i++)
{
printf("enter the value of x and fx at i=%d\n",i);
   scanf("%f%f",&ax[i],&fx[i]);
}
for(i=0;i<n;i++)
{
dd[i]=fx[i];
}
for(i=0;i<n;i++)
{
for(j=n-1;j>i;j--)
{
  dd[j]=(dd[j]-dd[j-1])/(ax[j]-ax[j-1-i]);
}
}
v=dd[1];

for(i=2;i<n;i++)
{
float term = 0;
for(j=0;j<i;j++)
{
float factor =1;
for(k=0;k<i;k++)
{
if(k!=j)
{
factor =factor*(xv-ax[k]);
}

}
term =term +factor;

}
v =v + (dd[i]*term);
}
printf("The value of first dervative:%f",v);
return 0;
}