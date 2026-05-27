#include <stdio.h>

 struct Student{
    int rollNo;
    char name[50];
    float marks;
 };

 void main(){

 struct Student s1,s2;
 printf("Enter your roll number :");
 scanf("%d",&s1.rollNo);
 printf("Enter your name :");
 scanf("%s",&s1.name);
 printf("Enter your marks :");
 scanf("%f",&s1.marks);

 printf("\nEnter your roll number :");
 scanf("%d",&s2.rollNo);
 printf("Enter your name :");
 scanf("%s",&s2.name);
 printf("Enter your marks :");
 scanf("%f",&s2.marks);

 printf("\n+------------+----------------------+----------+");
 printf("\n| Roll No    | Name                 | Marks    |");
 printf("\n+------------+----------------------+----------+");
 printf("\n| %-10d | %-20s | %-8.2f |", s1.rollNo, s1.name, s1.marks);
 printf("\n| %-10d | %-20s | %-8.2f |", s2.rollNo, s2.name, s2.marks);
 printf("\n+------------+----------------------+----------+");

 if(s1.marks>s2.marks){
    printf("\n%s is the TOPPER!",s1.name);
 }
 else{
     printf("\n%s is the TOPPER!",s2.name);
 }
 }
