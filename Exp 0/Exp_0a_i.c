#include<stdio.h>
#include<conio.h>


void insert(int a[],int n){
    for(int i=0;i<n;i++){
        printf("element %d:",i+1);
        scanf("%d",&a[i]);
    }
}
void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("elements %d: %d\n",i+1,a[i]);
}
}
void del(int a[],int n){
    int key;
    printf("Enter index of element: ");
    scanf("%d",&key);
    for(i=0,i<n;i++){
        if(key==a[i]){
            for(int j=i;j<n;j++){
                a[j]=a[j+1];
            }
            break;
        }


}


void main(){
int a[10],n;
printf("Enter the number of elements :");
scanf("%d",&n);
insert(a,n);
display(a,n);
del(a,n);
display(a,n);
getch();
}

