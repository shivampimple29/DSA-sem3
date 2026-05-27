#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int arr[MAX][MAX];
int total;
void insert(int n);
void del();
void modify_edge();

int main() {

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int option, edge;

    if (n < 0 || n > MAX) {
        printf("Invalid number of nodes (0..%d)\n", MAX);
        return 0;
    }

    total = n;

    printf("Input 1 or 0 only :");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            printf("\nelement (%d,%d) :", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nEntered elements are :\n\n");
    for (int i = 0; i < n; i++) {

        printf("\n");

        for (int j = 0; j < n; j++) {
            printf("%d\t", arr[i][j]);
        }
    }
    printf("\n");

    while (1) {

        printf("\n1.Add a node to matrix");
        printf("\n2.Add/delete edge");
        printf("\n3.Delete node");
        printf("\n4.Exit");

        printf("\nEnter the option :");
        if (scanf("%d", &option) != 1) {
            printf("INVALID ERROR!\n");
            return 0;
        }

        switch (option) {

        case 1: {
            if (total >= MAX) {
                printf("Cannot add node, matrix full (MAX=%d)\n", MAX);
                break;
            }
            insert(total);
            break;
        }

        case 2: {
            modify_edge();
            break;
        }

        case 3: {
            if (total <= 0) {
                printf("No nodes to delete\n");
                break;
            }
            del();
            break;
        }

        case 4:
            printf("Closing the program...");
            return 0;

        default:
            printf("INVALID INPUT!");
            break;
        }
    }
}

void insert(int n) {
    total = n + 1;

    for (int i = 0; i < total - 1; i++) {
        printf("\nelement (%d,%d) :", i + 1, total);
        scanf("%d", &arr[i][total - 1]);
    }

    for (int j = 0; j < total; j++) {
        printf("\nelement (%d,%d) :", total, j + 1);
        scanf("%d", &arr[total - 1][j]);
    }

    printf("\nAdjacent matrix after insertion of a new node :\n\n");
    for (int i = 0; i < total; i++) {

        printf("\n");

        for (int j = 0; j < total; j++) {
            printf("%d\t", arr[i][j]);
        }
    }
    printf("\n");
}

void del() {
    total = total - 1;
    if (total < 0) total = 0;

    printf("\nAdjacent matrix after deletion of a node :\n\n");
    for (int i = 0; i < total; i++) {

        printf("\n");

        for (int j = 0; j < total; j++) {
            printf("%d\t", arr[i][j]);
        }
    }
    printf("\n");
}

void modify_edge() {
    int i, j, val;

    if (total <= 0) {
        printf("No nodes available\n");
        return;
    }

    printf("\nEnter edge endpoints i j (1-based): ");
    if (scanf("%d %d", &i, &j) != 2) {
        printf("Invalid input\n");
        return;
    }
    printf("Enter value (1 to add, 0 to delete): ");
    if (scanf("%d", &val) != 1) {
        printf("Invalid input\n");
        return;
    }
    i--; j--;

    if (i < 0 || j < 0 || i >= total || j >= total) {
        printf("Index out of range\n");
        return;
    }
    if (val != 0 && val != 1) {
        printf("Value must be 0 or 1\n");
        return;
    }
    arr[i][j] = val;

    for (int r = 0; r < total; r++) {
        printf("\n");
        for (int c = 0; c < total; c++) {
            printf("%d\t", arr[r][c]);
        }
    }
    printf("\n");
}


