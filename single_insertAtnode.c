#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAfterNode(struct Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    int value, afterValue;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = NULL;

    printf("Initial linked list: ");
    displayList(head);

    printf("Enter the value you want to insert: ");
    scanf("%d", &value);

    printf("Enter the value after which you want to insert the new value: ");
    scanf("%d", &afterValue);

    struct Node* current = head;
    while (current != NULL && current->data != afterValue) {
        current = current->next;
    }

    if (current != NULL) {
        insertAfterNode(current, value);
        printf("Linked list after insertion: ");
        displayList(head);
    } else {
        printf("Node with value %d not found.\n", afterValue);
    }

    return 0;
}
 