#include <stdio.h>

static int a[5];

void insert();
void disp();
void linear_search(int key);
void binary_search(int beg, int end, int key);

int main() {
    insert();
    disp();

    int beg = 0;
    int end = (sizeof(a)/sizeof(a[0]))-1;

    while (1) {
         printf("\n-------------------MENU-------------------\n");
        printf("1.Linear Search\n");
        printf("2.Binary Search\n");
        printf("3.Quit\n");
        printf("\nEnter a option :");
        int option,key;
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the element to search :");
                scanf("%d", &key);
                printf("\n---------------Linear Search---------------\n");
                printf("\n");
                linear_search(key);
                break;

            case 2:
                printf("Enter the element to search :");
                scanf("%d", &key);
                printf("\n---------------Binary Search---------------\n");
                printf("\n");
                binary_search(beg, end, key);
                break;

            case 3:
                printf("Ending the program...\n");
                return 0;

            default:
                printf("INVALID INPUT ! Please enter a valid option.\n");
                break;
        }
    }
    return 0;
}

void insert() {
    printf("\n---------------Insertion---------------");
    printf("\n\nEnter the array elements :\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d :", i);
        scanf("%d", &a[i]);
    }
}

void disp() {
    printf("\n---------------Display---------------\n");
    printf("\nEntered elements are :\n");
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d : %d\n", i, a[i]);
    }
    printf("\n");
}

void linear_search(int key) {
    int flag = 0;
    for (int i = 0; i < 5; i++) {
        if (a[i] == key) {
            printf("%d is found at index %d\n", key, i);
            flag ++;
        }
    }
    if (flag==0) {
        printf("%d is not present in the given array\n", key);
    }
}

void binary_search(int beg, int end, int key) {
    if (beg <= end) {
        int mid = (beg + end) / 2;

        if (a[mid] == key) {
            printf("%d is found at index %d\n", key, mid);
            return;
        }

        else if (a[mid] < key) {
            binary_search(mid + 1, end, key);
        }

        else {
            binary_search(beg, mid - 1, key);
        }
    } else {
        printf("%d is not present in the given array\n", key);
    }
}
