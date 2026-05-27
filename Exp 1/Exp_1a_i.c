#include<stdio.h>
#include<conio.h>
#define MAX 5

//Stack Intialization
int st[MAX];
int top=-1;

//Function Prototype
void push();
void pop();
void peek();
void display();




//Main Method
void main(){
int option;
char choice='y';
while(choice=='y'){
    printf("Menu:\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n");
    printf("\nEnter the option : ");
    scanf("%d",&option);

    switch(option){
        case 1:push();
        break;
        case 2:pop();
        break;
        case 3:peek();
        break;
        case 4:display();
        break;
        default:printf("INVALID OPTION!");

    }//End of Switch
    printf("\nDo you want to continue? :");
    scanf(" %c",&choice);
}//End of while loop
getch();
}//End of Main method


void push(){
    int value;
    printf("\nEnter the value to push in stack :");
    scanf("%d",&value);
    if(top==MAX-1){
        printf("\nWARNING : STACK OVERFLOw\n");
    }
    else{
          top++;
          st[top]=value;
    }
}//end of push

void pop(){
    if(top==-1){
        printf("\nWARNING : STACK UNDERFLOW\n");
    }
    else{
        printf("the deleted data is %d",st[top]);
        top--;
    }
}

void peek(){
    if(top==-1){
        printf("\nWARNING : STACK UNDERFLOW\n");
    }
    else{
        printf("the deleted data is %d",st[top]);
    }
}

void display(){
    if(top==-1){
        printf("STACK is EMPTY!");

    }
    else{
        for(int i=0;i<=top;i++){
            printf("Element %d : %d",i+1,st[i]);
    }
}
}
