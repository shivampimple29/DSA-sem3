#include <stdio.h>

void insert(int a[]);
void disp(int a[]);
void B_sort(int a[]);



int main() {
    int a[5];
    printf("\n---------------Insertion---------------");
    insert(a);
    printf("\n---------------Before Bubble Sort---------------\n");
    disp(a);
    printf("\n---------------After  Buuble Sort---------------\n");
    printf("\n");
    B_sort(a);
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

void B_sort(int a[]){
    int flag=0,temp;
        for(int turn=0;turn<4;turn++){
            flag=0;
            for(int j=0;j<5-turn-1;j++){

                if(a[j]>a[j+1]){
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    flag=1;
                }
            }
            if(!flag){
                break;
            }
        }
}
