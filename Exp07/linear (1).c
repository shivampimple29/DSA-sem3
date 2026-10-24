#include <stdio.h>

int main(){
    int flag=1,i,val,n;
    int arr[10]={};
    printf("\nEnter number of array elements :");
    scanf("%d",&n);
    printf("\nEnter array element :\n");

    for(i=0;i<n;i++){

        printf("\nIndex %d: ",i);
        scanf("%d",&arr[i]);
    }

    printf("\nEntered elements are :\n");

    for(i=0;i<n;i++){

        printf("\nIndex %d : %d",i,arr[i]);

    }

    printf("\n");
    printf("\nEnter a value to find :");
    scanf("%d",&val);

    for(i=0;i<n;i++){

        if(arr[i]==val){
            printf("\n%d is found at Index %d\n",val,i);

            flag=0;
            break;
        }
    }
    if(flag){
        printf("\n%d is not present in the given array!",val);
    }



}
