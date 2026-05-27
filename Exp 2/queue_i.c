#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue, as shown in the diagrams
#define MAX 5

// Global variables for the queue
int queue_arr[MAX];
int rear = -1;
int front = -1;

// Function prototypes
void enqueue();
void dequeue();
void display();

int main() {
    int choice;

    // Menu-driven program loop
    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue (Insert an element)\n");
        printf("2. Dequeue (Delete an element)\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}

/**
 * @brief Adds an element to the rear of the queue.
 * This function implements the enqueue algorithm provided in the document.
 */
void enqueue() {
    int item;

    // Step 1: Check for OVERFLOW condition
    if (rear == MAX - 1) {
        printf("Queue Overflow: Cannot insert new element.\n");
        return;
    }

    // Step 2: Check if this is the first element
    if (front == -1) {
        front = 0;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &item);

    // Step 2 & 3: Increment rear and set the queue element
    rear = rear + 1;
    queue_arr[rear] = item;
    printf("%d has been enqueued.\n", item);
}

/**
 * @brief Removes an element from the front of the queue.
 * This function implements the dequeue algorithm provided in the document.
 */
void dequeue() {
    // Step 1: Check for UNDERFLOW condition
    if (front == -1 || front > rear) {
        printf("Queue Underflow: Cannot delete from an empty queue.\n");

        // Reset the queue pointers if it has become empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return;
    }

    // Access the element at the front and increment the front pointer
    printf("Element dequeued: %d\n", queue_arr[front]);
    front = front + 1;

    // If the last element was dequeued, reset the queue to its initial empty state
    if (front > rear) {
        printf("The queue is now empty. Resetting.\n");
        front = -1;
        rear = -1;
    }
}

/**
 * @brief Displays all the elements currently in the queue.
 * This function is required by the laboratory exercise.
 */
void display() {
    int i;
    if (front == -1) {
        printf("The queue is empty.\n");
        return;
    }
    printf("Queue elements are: \n");
    printf("FRONT -> ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue_arr[i]);
    }
    printf("<- REAR\n");
}
