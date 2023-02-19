#include<stdio.h>
struct employee{
char name[20];
int ID;
float salary;

struct address{
int houseno;
char city[20];
int pincode;
}add;


}emp;
void main(){

printf("Employee Id: ");
scanf("%d",&emp.ID);
printf("Name of staff: ");
scanf("%s",&emp.name);
printf("Enter salary: ");
scanf("%f",&emp.salary);

printf("Enter employee House NO.: ");
scanf("%d",&emp.add.houseno);
printf("Enter employee city: ");
scanf("%s",&emp.add.city);
printf("Enter employee pincode: ");
scanf("%d",&emp.add.pincode);
printf("\n Details of employee\n");
printf("Employee Id: %d \n",emp.ID);
printf("Name : %s \n",emp.name);
printf("Salary: %.2f \n",emp.salary);
printf("House No.: %d \n",emp.add.houseno);
printf("City: %s \n",emp.add.city);
printf("Pincode: %d \n",emp.add.pincode);
}
