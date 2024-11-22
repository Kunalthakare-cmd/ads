#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return createNode(data);
    if (data < node->data) 
        node->left = insert(node->left, data);
    else if (data > node->data) 
        node->right = insert(node->right, data);
    return node;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) 
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data) 
        root->left = deleteNode(root->left, data);
    else if (data > root->data) 
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) 
        return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


struct Node* createBST() {
    struct Node* root = NULL;
    int n, value, i;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n1. Create BST\n2. Insert\n3. Delete\n4. Search\n5. Inorder Traversal\n6. Preorder Traversal\n7. Postorder Traversal\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = createBST();
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) 
                    printf("Value found\n");
                else 
                    printf("Value not found\n");
                break;
            case 5:
                if (root == NULL) 
                    printf("Tree is empty!\n");
                else {
                    printf("Inorder traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 6:
                if (root == NULL) 
                    printf("Tree is empty!\n");
                else {
                    printf("Preorder traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 7:
                if (root == NULL) 
                    printf("Tree is empty!\n");
                else {
                    printf("Postorder traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 8);

    return 0;
}
