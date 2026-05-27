/*7. Write a menu driven program to perform stack operation using Array
a. PUSH
b. POP
*/

#include <stdio.h>
#define MAX 5

int st[MAX];
int top=-1;

void push();
void pop();


void main(){

    int option;

    while(1){
        printf("\n-----MENU-----\n");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Quit");
        printf("\nEnter a option : ");
        scanf("%d",&option);

        switch(option){

            case 1:
                    push();
                    break;

            case 2:
                    pop();
                    break;

            case 3:
                    printf("\nEnding the program...");
                    return;

            default:
                    printf("\nINVALID INPUT");
                    break;
        }
    }
}

void push(){

    if(top==MAX-1){
        printf("\n---STACK OVERFLOW---\n");
    }
    else{

        int val;
        printf("\nEnter a value to push : ");
        scanf("%d",&val);

        top++;
        st[top]=val;
        printf("\n%d has been pushed to stack successfully!\n",val);
    }
}

void pop(){

    if(top==-1){
        printf("\n---STACK UNDERFLOW---\n");
    }
    else{
        int val;
        val=st[top];
        top--;
        printf("\n%d has been popped from stack successfully!\n",val);
    }
}
