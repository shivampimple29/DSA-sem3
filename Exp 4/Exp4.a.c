#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *top = NULL, *ptr;

void push(int d) {
    struct Node * temp;
    temp = malloc(sizeof(struct Node));
    temp->data = d;
    temp->next= top;
    top=temp;
}

void pop() {
    if (top == NULL) {
        printf("\nStack underflow. Cannot pop from an empty stack.");
    } else {
        ptr = top;
        top = top->next;
        printf("\nThe popped element is %d", ptr->data);
        free(ptr);
    }
}

void display() {
    if (top == NULL) {
        printf("\nStack is empty. No nodes to display.");
    } else {
        ptr = top;
        printf("\nStack elements are: ");
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\n\n--- Stack Menu ---");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. QUIT");
        printf("\n------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nQuitting the program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.");
                break;
        }
    }
    return 0;
}

