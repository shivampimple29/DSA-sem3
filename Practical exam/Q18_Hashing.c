#include <stdio.h>
#define MAX 10

int arr[MAX] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

void hashing();
void display();

void main(){

    int option;

    while(1){
        printf("\n-----MENU------\n");
        printf("\n1.Insert (Hashing with Linear Probing)");
        printf("\n2.Display");
        printf("\n3.Quit");
        printf("\nEnter an option: ");
        scanf("%d", &option);
        printf("\n");

        switch(option){

            case 1:
                hashing();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("\nEnding the program...");
                return;

            default:
                printf("\nINVALID INPUT! TRY AGAIN!");
                break;
        }
    }
}

void hashing(){

    int key;
    printf("Enter key to insert: ");
    scanf("%d", &key);

    int idx = key % 10;
    int original = idx;

    while(arr[idx] != -1){

        // Linear Probing
        idx = (idx + 1) % 10;

        if(idx == original){
            printf("\nHashtable is full!\n");
            return;
        }
    }

    arr[idx] = key;
    printf("\n%d inserted at index %d successfully!\n", key, idx);
}

void display(){
    printf("\n-----HASH TABLE-----\n\n");
    printf("Index\tValue\n");
    for(int i = 0; i < MAX; i++){
        if(arr[i] != -1){
            printf("%d\t%d\n", i, arr[i]);
        }
        else{
            printf("%d\t--\n", i);
        }
    }
}

