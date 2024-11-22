#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Stack {
    struct Node* node;
    struct Stack* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void push(struct Stack** top, struct Node* node) {
    struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack));
    newStackNode->node = node;
    newStackNode->next = *top;
    *top = newStackNode;
}

struct Node* pop(struct Stack** top) {
    if (*top == NULL) return NULL;
    struct Stack* temp = *top;
    *top = (*top)->next;
    struct Node* node = temp->node;
    free(temp);
    return node;
}

int isStackEmpty(struct Stack* top) {
    return top == NULL;
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
    struct Stack* stack = NULL;
    struct Node* current = root;
    while (current != NULL || !isStackEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) return;
    struct Stack* stack = NULL;
    push(&stack, root);
    while (!isStackEmpty(stack)) {
        struct Node* current = pop(&stack);
        printf("%d ", current->data);
        if (current->right) push(&stack, current->right);
        if (current->left) push(&stack, current->left);
    }
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) return;
    struct Stack *stack1 = NULL, *stack2 = NULL;
    push(&stack1, root);
    while (!isStackEmpty(stack1)) {
        struct Node* current = pop(&stack1);
        push(&stack2, current);
        if (current->left) push(&stack1, current->left);
        if (current->right) push(&stack1, current->right);
    }
    while (!isStackEmpty(stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;

    do {
        printf("\n--- Binary Tree Traversals Menu ---\n");
        printf("1. Create Tree\n");
        printf("2. Inorder Traversal (using Stack)\n");
        printf("3. Preorder Traversal (using Stack)\n");
        printf("4. Postorder Traversal (using Stack)\n");
        printf("5. Exit\n");
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
                    printf("Preorder Traversal: ");
                    preorderTraversal(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Postorder Traversal: ");
                    postorderTraversal(root);
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
