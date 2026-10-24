#include<stdio.h>
#define MAX 5

int rear=-1,front=-1;
int q[MAX];

void enqueue();
void dequeue();
void peek();
void display();

void main(){
int choice;
while(1){
    int choice;
printf("\nchoice 1 : enqueue");
printf("\nchoice 2 : dequeue");
printf("\nchoice 3 : peek ");
printf("\nchoice 4 : display");
printf("\nEnter your Choice :");
scanf("%d",&choice);

    switch(choice){
        case 1: enqueue();
        break;
        case 2: dequeue();
        break;
        case 3: peek();
        break;
        case 4: display();
        break;
        default:printf("\nInvalid choice try again!");
        printf("\nEnter your Choice :");
        scanf("%d",&choice);
        break;
    }
}
}

void enqueue(){
int item;
printf("\nEnter a elelment :");
scanf("%d",&item);
if(rear==MAX-1){
    printf("\nOVERFLOW");
    return;
}
if(front==-1 && rear==-1){
    front=0;
    rear=0;
    q[rear]=item;
    printf("\n%d is enqueued!",q[rear]);
}
else{
    rear++;
    q[rear]=item;
    printf("\n%d is enqueued!",q[rear]);
}

}

void dequeue(){
int val;
if(front>rear ||  front==-1){
    printf("\nUNDERFLOW");
    return;
}
else{
    val=q[front];
    printf("\n%d is dequeued!",val);
    front++;

}
}

void display(){
if (front==-1){
    printf("\nQueue is empty");
    return;
}

else{

    for(int i=front;i<=rear;i++){
        printf("\n%d",q[i]);
    }
}
}

void peek(){
if (front==-1){
    printf("\nQueue is empty");
    return;
}
else{
    printf("\nfront is pointing to %d",q[front]);
}

}


/*
#include <stdio.h>
#include <string.h>

#define MAX 10

char docNames[MAX][30]; //char array that stores job's name- j1 - exp0, j2 - exp1
int pageCounts[MAX];
int front = -1, rear = -1;

// Arrays to store turnaround and waiting times
int turnaroundTimes[MAX];
int waitingTimes[MAX];

void enqueueJob() {
    if (rear == MAX - 1) {
        printf("Job queue is full. Cannot add more jobs.\n");
        return;
    }
    else if(front ==-1 && rear ==-1){
            rear=0;
            front =0;
    }else
    {
        rear++;
    }
    char doc[30];
    int pages;
    printf("Enter document name: ");
    scanf(" %[^\n]", doc);
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    strcpy(docNames[rear], doc);
    pageCounts[rear] = pages;

    printf("Job '%s' with %d pages added successfully.\n", doc, pages);
}

int currentTime = 0;
    int totalTAT = 0, totalWT = 0;

    printf("\nProcessing All Jobs (FCFS):\n");
    printf("-----------------------------------------------------------------\n");
    printf("| %-3s | %-20s | %-10s | %-12s | %-12s |\n", "No", "Document", "Pages", "TAT", "WT");
    printf("------------------------------------------------------------------\n");
    for (int i = front; i <= rear; i++) {
        int burstTime = pageCounts[i];  // Pages = burst time
        int waitingTime = currentTime;
        int turnaroundTime = waitingTime + burstTime;

        waitingTimes[i] = waitingTime;
        turnaroundTimes[i] = turnaroundTime;

        totalTAT += turnaroundTime;
        totalWT += waitingTime;
printf("| %-3d | %-20s | %-10d | %-12d | %-12d |\n",
               i - front + 1, docNames[i], burstTime, turnaroundTime, waitingTime);

        currentTime += burstTime;
    }
printf("-----------------------------------------------------------------\n");
    printf("Total Turnaround Time = %d\n", totalTAT);
    printf("Total Waiting Time    = %d\n", totalWT);
    printf("Average TAT           = %.2f\n", (float)totalTAT / (rear - front + 1));
    printf("Average WT            = %.2f\n", (float)totalWT / (rear - front + 1));

    // Clear queue after processing
    front = -1;
    rear = -1;
}
void displayJobs() {
    if (front > rear) {
        printf("No jobs in the queue.\n");
        return;
    }

    printf("\nPending Jobs:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s (%d pages)\n", i - front + 1, docNames[i], pageCounts[i]);
    }
}
  printf("\nPending Jobs:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s (%d pages)\n", i - front + 1, docNames[i], pageCounts[i]);
    }
}
int main() {
    int choice;

    do {
        printf("\n====== FCFS Job Scheduler with TAT & WT ======\n");
        printf("1. Add Job\n");
        printf("2. Display Pending Jobs\n");
        printf("3. Process All Jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
switch (choice) {
            case 1:
                enqueueJob();
                break;
            case 2:
                displayJobs();
                break;
            case 3:
                processAllJobs();
                break;
            case 4:
                printf("Exiting Job Scheduler.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
*/
