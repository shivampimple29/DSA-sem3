#include<stdio.h>

static int a[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

void Hashing(int key);
void display();

void main(){

int i,key,option;

while(1){
    printf("\n------MENU-----\n");
    printf("\n1.Hashing");
    printf("\n2.Display");
    printf("\n3.Quit");
    printf("\nEnter a option :");
    scanf("%d",&option);
    printf("\n");

    switch(option){

        case 1:for(i=0;i<10;i++){

                    printf("Key %d : ",i+1);
                    scanf("%d",&key);
                    Hashing(key);
                }
                break;

        case 2:
                display();
                break;

        case 3:printf("Quitting the program...");
                return;

        default:printf("INVALID INPUT! TRY AGAIN!");
                break;
    }
}
}

void Hashing(int key){

    int index=key%10;
    int OG=index;

    while(a[index]!=-1){

        index=(index+1)%10;

        if(index==OG){

            printf("hash table is full!");
            return;
        }
    }
    a[index]=key;
}

void display(){

    for(int i=0;i<10;i++){

        printf("\nIndex %d : %d",i,a[i]);
    }
}
