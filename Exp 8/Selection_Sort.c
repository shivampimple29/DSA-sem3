#include <stdio.h>

void insert(int a[]);
void disp(int a[]);
void S_sort(int a[]);



int main() {
    int a[5];
    printf("\n---------------Insertion---------------");
    insert(a);
    printf("\n---------------Before Selection Sort---------------\n");
    disp(a);
    printf("\n---------------After  Selection Sort---------------\n");
    printf("\n");
    S_sort(a);
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

void S_sort(int a[]){
    int temp,minpos;

    for(int i=0;i<4;i++){

        minpos=i;

        for(int j=i+1;j<5;j++){

            if(a[minpos]>a[j]){

                minpos=j;
            }
        }

        temp=a[minpos];
        a[minpos]=a[i];
        a[i]=temp;

    }
}
