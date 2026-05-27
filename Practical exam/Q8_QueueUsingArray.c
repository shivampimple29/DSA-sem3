/*Q8. Write a menu driven program to perform Queue operation using Array
a. Enqueue
b. Dequeue
*/

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue();
void dequeue();

void main(){

    int option;

    while(1){

        printf("\n------MENU-----\n");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Quit");
        printf("\nEnter a option : ");
        scanf("%d",&option);

        switch(option){

        case 1:
                enqueue();
                break;

        case 2:
                dequeue();
                break;

        case 3:
                printf("\nEnding the program...");
                return;

        default:printf("INVALID INPUT");
                break;
        }
    }
}

void enqueue(){

    if(rear==MAX-1){
        printf("\n---QUEUE OVERFLOW---\n");
        return;
    }
    int val;
    printf("\nEnter the value to enqueue : ");
    scanf("%d",&val);

    if(front==-1 && rear==-1){
        rear=front=0;
        queue[rear]=val;
        printf("\n%d has been enqueued successfully!\n",val);
    }

    else{
        rear++;
        queue[rear]=val;
        printf("\n%d has been enqueued successfully!\n",val);
    }
}

void dequeue(){

    if(front==-1 || front>rear){
        printf("\n---QUEUE UNDERFLOW---\n");
    }

    else{
        int val;
        val=queue[front];
        front++;
        printf("\n%d has been dequeued successfully!",val);
    }
}
