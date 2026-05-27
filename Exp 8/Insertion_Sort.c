#include <stdio.h>

void insert(int a[]);
void disp(int a[]);
void I_sort(int a[]);



int main() {
    int a[5];
    printf("\n---------------Insertion---------------");
    insert(a);
    printf("\n---------------Before Insertion Sort---------------\n");
    disp(a);
    printf("\n---------------After  Insertion Sort---------------\n");
    printf("\n");
    I_sort(a);
    disp(a);

    return 0;
}

void insert(int a[]) {

    printf("\n\nEnter the array elements :\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d :", i+1);
        scanf("%d", &a[i]);
    }
}

void disp(int a[]) {

    printf("\nEntered elements are :\n");
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("Element %d : %d\n", i+1, a[i]);
    }
    printf("\n");
}

void I_sort(int a[]){
    int prev,curr;

    for(int i=1;i<5;i++){

        curr=a[i];
        prev=i-1;

        while(prev>=0 && a[prev]>curr){

            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=curr;
    }
}
