#include<stdio.h>

void insert(int a[],int n){
    printf("\nEnter the elements to insert\n");
    printf("\n");
    for(int i=0;i<n;i++){
        printf("element %d:",i+1);
        scanf("%d",&a[i]);
    }
}
void display(int a[],int n){
    printf("\n");
    for(int i=0;i<n;i++){
        printf("elements %d: %d\n",i+1,a[i]);
}
}
int del(int a[],int n){
    int key;
    printf("\nEnter the element to delete: ");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(key==a[i]){
            for(int j=i;j<n-1;j++){
                a[j]=a[j+1];
            }
            break;
        }

}
display(a,n-1);
return n-1;
}

void search(int a[],int n){
    int k;
    printf("\nEnter the element to search :");
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        if(k==a[i]){
            printf("\n%d is found at index %d\n",k,i);
            break;
        }
    }
}
void count(int a[],int n){
    int counter=0,var;
    printf("\nEnter the elements to find its count :");
    scanf("%d",&var);
    for(int i=0;i<n;i++){
        if(var==a[i]){
           counter++;
        }
    }
    printf("\nOccurence of %d in the given array is %d",var,counter);
}


void main(){
int a[10],n;
printf("Enter the number of elements :");
scanf("%d",&n);
insert(a,n);
display(a,n);
n=del(a,n);
search(a,n);
count(a,n);
}

