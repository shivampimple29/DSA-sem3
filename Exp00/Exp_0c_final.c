#include <stdio.h>


 struct Student{
    int rollNo;
    char name[50];
    float marks;
 };

 void main(){
     struct Student s1,s2;
     struct Student *ptr1=&s1,*ptr2=&s2;
     printf("Enter your roll number :");
     scanf("%d",&ptr1->rollNo);
     printf("Enter your name :");
     scanf("%s",&ptr1->name);
     printf("Enter your marks :");
     scanf("%f",&ptr1->marks);

     printf("\nEnter your roll number :");
     scanf("%d",&ptr2->rollNo);
     printf("Enter your name :");
     scanf("%s",&ptr2->name);
     printf("Enter your marks :");
     scanf("%f",&ptr2->marks);

     printf("\n+------------+----------------------+----------+");
     printf("\n| Roll No    | Name                 | Marks    |");
     printf("\n+------------+----------------------+----------+");
     printf("\n| %-10d | %-20s | %-8.2f |", ptr1->rollNo, ptr1->name, ptr1->marks);
     printf("\n+------------+----------------------+----------+");
     printf("\n| %-10d | %-20s | %-8.2f |", ptr2->rollNo, ptr2->name, ptr2->marks);
     printf("\n+------------+----------------------+----------+");

     if(s1.marks>s2.marks){
        printf("\n%s is the TOPPER!",ptr1->name);
     }
     else{
         printf("\n%s is the TOPPER!",ptr2->name);
     }
 }


