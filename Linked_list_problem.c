#include <stdio.h>
#include <stdlib.h>

// Definition of the linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to convert a linked list to a number
long long linkedListToNumber(struct ListNode* node) {
    long long num = 0;
    long long multiplier = 1;
    while (node != NULL) {
        num += node->val * multiplier;
        multiplier *= 10;
        node = node->next;
    }
    return num;
}

// Function to add two numbers represented by linked lists and print the result in reverse order
void addTwoNumbersAndPrint(struct ListNode* l1, struct ListNode* l2) {
    // Convert linked lists to numbers
    long long num1 = linkedListToNumber(l1);
    long long num2 = linkedListToNumber(l2);
    
    // Add the two numbers
    long long total = num1 + num2;
    
    // Print the result in reverse order
    printf("Result in reverse order: ");
    while (total > 0) {
        printf("%lld", total % 10);
        total /= 10;
    }
    printf("\n");
}

// Helper function to create a linked list from an array of values
struct ListNode* createLinkedList(int* vals, int size) {
    struct ListNode* head = createNode(vals[0]);
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    
    int l1_vals[] = {9, 9, 9, 9, 9, 9};
    int l2_vals[] = {9, 9, 9, 9};
    
    // Create the linked lists
    struct ListNode* l1 = createLinkedList(l1_vals, 6);
    struct ListNode* l2 = createLinkedList(l2_vals, 4);
    
    // Add the numbers and print the result in reverse order
    addTwoNumbersAndPrint(l1, l2);
    
    return 0;
}
