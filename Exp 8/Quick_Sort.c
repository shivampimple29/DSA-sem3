#include <stdio.h>
#define MAX 5

int a[MAX];

void display() {
    printf("\nArray elements: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insert() {
    printf("\n---------------Insertion---------------\n");
    printf("Enter %d elements:\n", MAX);
    for (int i = 0; i < MAX; i++) {
        printf("Element %d: ", i);
        scanf("%d", &a[i]);
    }
}

int partition(int si, int ei) {
    int pivot = a[ei];
    int i = si - 1;

    for (int j = si; j < ei; j++) {
        if (pivot >= a[j]) {
            i++;
            // Swap
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    i++;
    int temp = a[ei];
    a[ei] = a[i];
    a[i] = temp;
    return i;
}

void quickSort(int si, int ei) {
    if (si >= ei) {
        return;
    }

    int pIdx = partition(si, ei);
    quickSort(si, pIdx - 1);
    quickSort(pIdx + 1, ei);
}

void main() {
    insert();
    display();

    int option;
    while (1) {
        printf("\n-------------------MENU-------------------\n");
        printf("1. QuickSort\n");
        printf("2. Display Array\n");
        printf("3. Quit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n-----------Sorting with QuickSort-----------\n");
                quickSort(0, MAX - 1);
                printf("Array sorted successfully!\n");
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("INVALID INPUT! Please enter a valid option.\n");
                break;
        }
    }
}
