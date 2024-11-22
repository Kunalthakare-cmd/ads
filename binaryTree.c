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

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        int choice;
        printf("Insert left (1) or right (2) of %d: ", root->data);
        scanf("%d", &choice);
        if (choice == 1) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}

struct Node* createTree() {
    struct Node* root = NULL;
    int data;
    do {
        printf("Enter data (-1 to stop): ");
        scanf("%d", &data);
        if (data != -1) {
            root = insertNode(root, data);
        }
    } while (data != -1);
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int findHeight(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void displayLeafNodes(struct Node* root) {
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            printf("%d ", root->data);
        }
        displayLeafNodes(root->left);
        displayLeafNodes(root->right);
    }
}

void mirrorTree(struct Node* root) {
    if (root != NULL) {
        struct Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
    }
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

int main() {
    struct Node* root = NULL;
    int choice;

    do {
        printf("\n--- Binary Tree Operations Menu ---\n");
        printf("1. Create Tree\n");
        printf("2. Inorder Display\n");
        printf("3. Find Height of Tree\n");
        printf("4. Display Leaf Nodes\n");
        printf("5. Display Tree Level-wise\n");
        printf("6. Create Mirror Image of Tree\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = createTree();
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Inorder Traversal: ");
                    inorderTraversal(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Height of the Tree: %d\n", findHeight(root));
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Leaf Nodes: ");
                    displayLeafNodes(root);
                    printf("\n");
                }
                break;
            case 5:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Level-wise Traversal: ");
                    levelOrderTraversal(root);
                    printf("\n");
                }
                break;
            case 6:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    mirrorTree(root);
                    printf("Mirror image created.\n");
                }
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
