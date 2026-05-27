#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL, *ptr;

void enqueue(int d) {
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = d;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;

    }else{
    rear->next = temp;
    rear = temp;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("\nQueue underflow.");
    } else {
        ptr = front;
        printf("\nThe dequeued element is %d", front->data);
        front = front->next;
        free(ptr);

        if (front == NULL) {
            rear = NULL;
        }
    }
}

void display() {
    if (front == NULL) {
        printf("\nQueue is empty.");
    } else {
        ptr = front;
        printf("\nQueue elements: Front -> ");
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("Rear");
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\n\n--- Queue Menu ---");
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. QUIT");
        printf("\n------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nQuitting the program.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.");
                break;
        }
    }
    return 0;
}






