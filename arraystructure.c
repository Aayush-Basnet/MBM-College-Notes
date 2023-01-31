#include<stdio.h>
struct student{

char name[20];
int roll;
char address[20];

};
void main(){
int i,n;

printf("Enter the number of student: ");
scanf("%d",&n);
struct student std[n];
for(i=0;i<n;i++){

    printf("Enter Information for student %d\n",i+1);
    printf("Enter name: ");
    scanf("%s",std[i].name);
    printf("Enter Roll No.: ");
    scanf("%d",&std[i].roll);
    printf("Enter Address: ");
    scanf("%s",&std[i].address);

}
printf("\n");
for(i=0;i<n;i++){
    printf("Information of student %d \n",i+1);
    printf("Name: %s\n",std[i].name);
    printf("Roll No.: %d \n",std[i].roll);
    printf("Address: %s\n",std[i].address);
printf("\n");
}



}
