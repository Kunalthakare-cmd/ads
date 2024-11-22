#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = head;
    newNode->data = newData;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return head ;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    return head;

}

void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data=5;
    head->next=NULL;
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    printf("Linked list after inserting at the end: ");
    displayList(head);

    return 0;
}
