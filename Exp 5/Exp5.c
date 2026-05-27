#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root=NULL,*ptr;

struct Node* createnode(int d);
struct Node* insert(struct Node* node,int d);
struct Node* del(struct Node* node,int d);
struct Node* search(struct Node* node,int d);

void inorder(struct Node* node );
void preorder(struct Node* node );
void postorder(struct Node* node );
void display(struct Node* node, int level);


int main(){

int choice , value;
while(1){

    printf("-------MENU--------");
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Search");
    printf("\n4.Inorder");
    printf("\n5.Preorder");
    printf("\n6.Postorder");
    printf("\n7.Display");
    printf("\n8.Quit");

    printf("Enter a choice :");
    scanf("%d",&choice);


    switch(choice){

    case 1:printf("Enter a value to insert : ");
           scanf("%d",&value);
           root-insert(root,value);
    break;


    case 2:printf("Enter a value to delete : ");
           scanf("%d",&value);
           //root=del(root,value);
    break;


    case 3:printf("Enter a value to search : ");
           scanf("%d",&value);
           ptr=search(root,value);
           if(ptr!=NULL){
            printf("%d is found in BST",value);
           }
           else{
            printf("%d is not in BST",value);
           }
    break;

    case 4:printf("Inorder :");
           inorder(root);
           printf("\n");
    break;

    case 5:printf("Preorder :");
           preorder(root);
           printf("\n");
    break;


    case 6:printf("Postorder :");
           postorder(root);
           printf("\n");
    break;


    case 7:display(root,value);
    break;

    case 8:printf("Quiting...");
           printf("Program ended successfully");
           return 0;
    break;

    default:printf("INVALID INPUT! PLEASE TRY AGAIN!");
            printf("Enter a choice :");
            scanf("%d",&choice);
    break;



    }
}



return 0;
}

struct Node* createnode(int d){

struct Node *temp;
temp=malloc(sizeof(struct Node));
temp->data=d;
temp->lchild=NULL;
temp->rchild=NULL;
root=temp;
return root;
}


struct Node* insert(struct Node* node, int d){

    if(node==NULL)
        return createnode(d);
    if(d<node->data)
            node->lchild=insert(node->lchild,d);
    else if
            node->rchild=insert(node->rchild,d);
    return node;
    }
}


void inorder(struct Node* root){

    if(root!=NULL){
        inorder(root->lchild);
        printf("%d",root->data);
        inorder(root->rchild);
    }
}

void prerder(struct Node* root){

    if(root!=NULL){
        inorder(root->lchild);
        printf("%d",root->data);
        inorder(root->rchild);
    }
}
void postorder(struct Node* root){

    if(root!=NULL){
        inorder(root->lchild);
        printf("%d",root->data);
        inorder(root->rchild);
    }
}

void display(struct Node *ptr,int level){

	int i;
	if ( ptr!=NULL )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->data);
		display(ptr->lchild, level+1);
	}
}

// -------- Search ----------
struct Node* search(struct Node *node, int d) {
    if(node == NULL || node->data == d)
        return node;
    if(d < node->data)
        return search(node->lchild, d);
    else
        return search(node->rchild, d);
}
