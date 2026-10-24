#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
};
struct Node *root = NULL;
struct Node* createnode(int d);
struct Node* insert(struct Node* node, int d);
struct Node* search(struct Node* node, int d);
void inorder(struct Node* node);
void preorder(struct Node* node);
void postorder(struct Node* node);
void display(struct Node* node, int level);
struct Node* deletenode(struct Node* node ,int data);
int main() {
    int choice, value;
    while (1) {
        printf("\n-------MENU--------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Display Tree\n");
        printf("8. Quit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter a value to delete: ");
                scanf("%d", &value);
                root = deletenode(root, value);
                break;
            case 3:
                printf("Enter a value to search: ");
                scanf("%d", &value);
                struct Node* ptr = search(root, value);
                if (ptr != NULL) {
                    printf("%d is found in the BST.\n", value);
                } else {
                    printf("%d is not in the BST.\n", value);
                }
                break;
            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Tree Structure:\n");
                display(root, 0);
                break;
            case 8:
                printf("Quitting...\nProgram ended successfully.\n");
                return 0;
            default:
                printf("INVALID INPUT! PLEASE TRY AGAIN!\n");
                break;
        }
    }
    return 0;
}
struct Node* createnode(int d) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = d;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}
struct Node* insert(struct Node* node, int d) {
    if (node == NULL) {
        return createnode(d);
    }
    if (d < node->data) {
        node->lchild = insert(node->lchild, d);
    } else if (d > node->data) {
        node->rchild = insert(node->rchild, d);
    }
    return node;
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}
void display(struct Node *ptr, int level) {
    if (ptr != NULL) {
        display(ptr->rchild, level + 1);
        printf("\n");
        for (int i = 0; i < level; i++) {
            printf("    ");
        }
        printf("%d", ptr->data);
        display(ptr->lchild, level + 1);
    }
}
struct Node* search(struct Node *node, int d) {
    if (node == NULL || node->data == d) {
        return node;
    }
    if (d < node->data) {
        return search(node->lchild, d);
    } else {
        return search(node->rchild, d);
    }
}
struct Node* deletenode(struct Node *node, int d)
{
    // no nodes in the tree
    if (node == NULL) {
        printf("Value %d not found!\n", d);
        return NULL;
    }
    // go down to the correct subtree
    if (d < node->data) {
        node->lchild = deletenode(node->lchild, d);  // Go left
    }
    else if (d > node->data) {
        node->rchild = deletenode(node->rchild, d);  // Go right
    }
    else {
        // Found node
        // Case 1: Leaf node
        if (node->lchild == NULL && node->rchild == NULL) {
            printf("Deleting leaf node %d\n", node->data);
            free(node);
            return NULL;
        }
        // Case 2: One child (only right)
        else if (node->lchild == NULL) {
            printf("Deleting node %d with one right child\n", node->data);
            struct Node* temp = node->rchild;
            free(node);
            return temp;
        }
        // Case 2: One child (only left)
        else if (node->rchild == NULL) {
            printf("Deleting node %d with one left child\n", node->data);
            struct Node* temp = node->lchild;
            free(node);
            return temp;
        }
        // Case 3: Two children
       else{
        struct Node* temp = node->rchild;
        while (temp->lchild != NULL) {
            temp = temp->lchild;
        }
        node->data = temp->data;
        node->rchild = deletenode(node->rchild, temp->data);
       }
    }
    return node;
}


