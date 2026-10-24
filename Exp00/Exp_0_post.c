#include <stdio.h>


 struct Student{
    int rollNo;
    char name[50];
    float marks;
 };

void main(){
    struct Student s[10];

    for(int i=0;i<10;i++){
        printf("\nEnter information of student %d :\n",i+1);
        printf("\nEnter your roll number :");
        scanf("%d",&s[i].rollNo);
        printf("Enter your name :");
        scanf("%s",&s[i].name);
        printf("Enter your marks :");
        scanf("%f",&s[i].marks);
    }
    float topper=s[0].marks;
    int tindex;

        printf("\n+------------+----------------------+----------+");
        printf("\n| Roll No    | Name                 | Marks    |");
        printf("\n+------------+----------------------+----------+");
    for(int i=0;i<10;i++){
        printf("\n| %-10d | %-20s | %-8.2f |", s[i].rollNo, s[i].name, s[i].marks);
        printf("\n+------------+----------------------+----------+");
    }

    for(int i=1;i<10;i++){
        if(topper<s[i].marks){
            topper=s[i].marks;
            tindex=i;
        }
    }
    printf("\n\n%s is the TOPPER with %.2f marks!\n",s[tindex].name,s[tindex].marks);
}
