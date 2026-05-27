/*Q1. Write a menu driven program to create linked list and perform following operations
a. Insert 98 value at location 3
b. Delete value at end*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Node {
    int data;
    struct Node *next;
}*start = NULL, *ptr;
int size = 1;

void createList(int d);
void insertAtLocation(int d, int idx);
void deleteAtEnd();
void display();

void main() {

    int option, d, location;

    while(1) {
        printf("\n-----MENU-----\n");
        printf("\n1. Create a list");
        printf("\n2. Insert At some location");
        printf("\n3. Delete at End");
        printf("\n4. Display");
        printf("\n5. Quit");
        printf("\nEnter an option : ");
        scanf("%d", &option);

        switch(option) {

            case 1:
                printf("\nEnter a data : ");
                scanf("%d", &d);
                createList(d);
                break;

            case 2:
                printf("\nEnter a data : ");
                scanf("%d", &d);
                printf("\nEnter a location : ");
                scanf("%d", &location);
                insertAtLocation(d, location);
                break;

            case 3:
                deleteAtEnd();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nEnding the program...");
                return;

            default:
                printf("\nINVALID INPUT ! TRY AGAIN\n");
                break;
        }
    }
}

void createList(int d) {

    struct Node *temp;
    temp = malloc(sizeof(struct Node));

    if(temp == NULL) {
        printf("\nMEMORY ALLOCATION FAILED\n");
        exit(1);
    }

    temp->data = d;
    temp->next = NULL;

    if(start == NULL) {
        start = temp;
        size++;
        printf("\n%d has been added successfully!\n", d);
    }
    else {
        ptr = start;

        while(ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = temp;
        size++;
        printf("\n%d has been added successfully!\n", d);
    }
}

void insertAtLocation(int d, int idx) {

    if(idx < 1 || idx > size) {
        printf("\nINVALID INDEX!\n");
        return;
    }

    struct Node *temp;
    temp = malloc(sizeof(struct Node));

    if(temp == NULL) {
        printf("\nMEMORY ALLOCATION FAILED\n");
        return;
    }

    temp->data = d;

    if(idx == 1) {
        temp->next = start;
        start = temp;
        size++;
        printf("\nNode with %d data is inserted at index %d\n", d, idx);
        return;
    }

    ptr = start;

    for(int i = 1; i < idx - 1; i++) {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
    size++;
    printf("\nNode with %d data is inserted at index %d\n", d, idx);
}

void deleteAtEnd() {

    struct Node *prev;

    if(start == NULL) {
        printf("\nLIST IS EMPTY\n");
        return;
    }

    if(start->next == NULL) {
        printf("\nDeleted node is %d\n", start->data);
        free(start);
        start = NULL;
        size--;
        return;
    }

    ptr = start;

    while(ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }

    printf("\nDeleted node is %d\n", ptr->data);
    prev->next = NULL;
    free(ptr);
    size--;
}

void display() {

    if(start == NULL) {
        printf("\nLIST IS EMPTY\n");
        return;
    }

    ptr = start;
    printf("\nHEAD->");

    while(ptr != NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}
