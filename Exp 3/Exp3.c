#include<stdio.h>
#include<stdlib.h>//(exit 1)
//structure of node
struct Node
{
    int data;
    //self-referential pointer
    struct Node *next;
}*start=NULL,*ptr;

void create_list(int d);
void display();
void insert_begin(int d);
void insert_between(int d); // Function prototype for insertion in between
void delete_begin();
void delete_end();
void delete_between(); // Function prototype for deletion in between
void search(int d);     // Function prototype for search
void count();           // Corrected: count does not need an int d argument to count all nodes
int main()
{
    int choice,i,n,val,pos; // Added 'pos' for position in insert_between and delete_between
    while(1){
    printf("\nList of Choices : ");
    printf("\n1.  Create a List {insertion at the end/append}");
    printf("\n2.  Insertion at the beginning");
    printf("\n3.  Insertion in between (at a specific position)");
    printf("\n4.  Deletion at the end");
    printf("\n5.  Deletion at the beginning");
    printf("\n6.  Deletion at index/before/after"); // Renamed for clarity
    printf("\n7.  Search a given value in the list"); // Renamed for clarity
    printf("\n8.  Count total nodes in the list");    // Renamed for clarity
    printf("\n9.  Display the contents of the list");
    printf("\n10. Quit");
    printf("\n");
    printf("\nEnter a choice :");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("\nEnter number of nodes for the linked list : ");
               scanf("%d",&n);
               printf("\n");
               for(i=0;i<n;i++){
                 printf("Enter the value to be added to the node %d: ",i+1);
                 scanf("%d",&val);
                 create_list(val);
               }
               break;

        case 2:printf("\nEnter the value to be inserted at the beginning: ");
               scanf("%d",&val);
               insert_begin(val);
               break;

        case 3:printf("\nEnter the value to be inserted: ");
               scanf("%d",&val);
               insert_between(val); // insert_between will now ask for position
               break;

        case 4:delete_end();
               break;

        case 5:delete_begin();
               break;

        case 6:delete_between(); // delete_between will now ask for position
               break;

        case 7:printf("\nEnter the value to search: ");
               scanf("%d",&val);
               search(val);
               break;

        case 8:count();
               break;

        case 9:
            display();
            break;

        case 10:return 0;
                break;

        default:printf("\nInvalid choice\n");
                break;
        }
    }
return 0;
}

void create_list(int d){
    struct Node *temp;
    temp=malloc(sizeof(struct Node));
    if(temp == NULL) { // Error handling for malloc
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data=d;
    temp->next=NULL;
    if(start==NULL){
        start=temp;
    }
    else{
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void display(){
    int i=1;
    if(start==NULL){
        printf("\nList is EMPTY (UNDERFLOW)\n"); // Corrected message
    }
    else{
        ptr=start;
        while(ptr!=NULL){
            printf("Node %d value is : %d\n",i,ptr->data);
            ptr=ptr->next;
            i++;
        }
    }
}

void insert_begin(int d){
    struct Node *temp;
    temp=malloc(sizeof(struct Node));
    if(temp == NULL) { // Error handling for malloc
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data=d;
    temp->next=start;
    start=temp;
}

void insert_between(int d) {
    int pos, i;
    struct Node *temp, *current;

    printf("\nEnter the position to insert (1-based): ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }

    temp = malloc(sizeof(struct Node));
    if(temp == NULL) { // Error handling for malloc
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = d;
    temp->next = NULL;

    if (pos == 1) { // Insert at the beginning
        temp->next = start;
        start = temp;
        printf("Value %d inserted at position %d.\n", d, pos);
        return;
    }

    current = start;
    for (i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position %d is beyond the end of the list. Insertion failed.\n", pos);
        free(temp); // Free allocated memory if insertion fails
    } else {
        temp->next = current->next;
        current->next = temp;
        printf("Value %d inserted at position %d.\n", d, pos);
    }
}

void delete_begin(){
    if(start == NULL){
        printf("List is EMPTY (UNDERFLOW). Cannot delete from beginning.\n");
        return;
    }
    ptr=start;
    start=start->next;
    printf("Deleted node is %d\n",ptr->data);
    free(ptr);
}

void delete_end(){
    struct Node *prev;
    if(start == NULL){
        printf("List is EMPTY (UNDERFLOW). Cannot delete from end.\n");
        return;
    }
    if(start->next == NULL){ // Only one node in the list
        printf("Deleted node is %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }
    ptr=start;
    while(ptr->next!=NULL){
        prev=ptr;
        ptr=ptr->next;
    }
    printf("Deleted node is %d\n",ptr->data);
    prev->next=NULL;
    free(ptr);
}

void delete_between(){
    int pos, i;
    struct Node *current, *prev;

    if(start == NULL){
        printf("List is EMPTY (UNDERFLOW). Cannot delete.\n");
        return;
    }

    printf("\nEnter the position to delete (1-based): ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }

    if (pos == 1) { // Delete from the beginning
        delete_begin();
        return;
    }

    current = start;
    prev = NULL;
    for (i = 1; i < pos && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Position %d is beyond the end of the list. Deletion failed.\n", pos);
    } else {
        printf("Deleted node is %d from position %d.\n", current->data, pos);
        prev->next = current->next;
        free(current);
    }
}

void search(int d){
    int pos = 0;
    ptr = start;
    if(start == NULL){
        printf("List is EMPTY. Cannot search.\n");
        return;
    }
    while(ptr != NULL){
        pos++;
        if(ptr->data == d){
            printf("Value %d found at position %d.\n", d, pos);
            return;
        }
        ptr = ptr->next;
    }
    printf("Value %d not found in the list.\n", d);
}

void count(){
    int count = 0;
    ptr = start;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    printf("Total number of nodes in the list: %d\n", count);
}

