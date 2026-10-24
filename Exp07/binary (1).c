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

    int beg=0;
    int end=n;

    printf("\nEntered elements are :\n");
    for(i=0;i<n;i++){

        printf("\nIndex %d : %d",i,arr[i]);

    }
    printf("\n\nEnter a value to perform Binary Search :");
    scanf("%d",&val);

    while(beg<=end){
        int mid =(beg+end)/2;

        if(arr[mid]==val){
            printf("\n%d is found at index %d",val,mid);
            flag=0;
            break;
        }

        else if(arr[mid]>val){
            end=mid-1;
        }
        else{
            beg=mid+1;
        }

    }

    if(flag){
        printf("\n%d is not present in the given array\n",val);
    }
}
