#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTableChain[TABLE_SIZE];
int hashTableLinear[TABLE_SIZE];

void initHashTables() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTableChain[i] = NULL;
        hashTableLinear[i] = -1;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insertChain(int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = hashTableChain[index];
    hashTableChain[index] = newNode;
    printf("Inserted %d using chaining\n", key);
}

void insertLinear(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (hashTableLinear[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Hash table is full, unable to insert %d\n", key);
            return;
        }
    }
    hashTableLinear[index] = key;
    printf("Inserted %d using linear probing\n", key);
}

int searchChain(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTableChain[index];
    while (temp) {
        if (temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

int searchLinear(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (hashTableLinear[index] != -1) {
        if (hashTableLinear[index] == key) return 1;
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) break;
    }
    return 0;
}

void displayChain() {
    printf("Hash Table (Chaining):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTableChain[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void displayLinear() {
    printf("Hash Table (Linear Probing):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTableLinear[i] == -1)
            printf("Index %d: Empty\n", i);
        else
            printf("Index %d: %d\n", i, hashTableLinear[i]);
    }
}

int main() {
    int choice, key, numKeys;

    initHashTables();

    while (1) {
        printf("1. Insert using Chaining\n");
        printf("2. Insert using Linear Probing\n");
        printf("3. Search in Chaining\n");
        printf("4. Search in Linear Probing\n");
        printf("5. Display Hash Table (Chaining)\n");
        printf("6. Display Hash Table (Linear Probing)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of keys to insert (Chaining): ");
                scanf("%d", &numKeys);
                for (int i = 0; i < numKeys; i++) {
                    printf("Enter key %d: ", i + 1);
                    scanf("%d", &key);
                    insertChain(key);
                }
                break;
            case 2:
                printf("Enter the number of keys to insert (Linear Probing): ");
                scanf("%d", &numKeys);
                for (int i = 0; i < numKeys; i++) {
                    printf("Enter key %d: ", i + 1);
                    scanf("%d", &key);
                    insertLinear(key);
                }
                break;
            case 3:
                printf("Enter key to search (Chaining): ");
                scanf("%d", &key);
                if (searchChain(key))
                    printf("Key %d found in chaining hash table.\n", key);
                else
                    printf("Key %d not found in chaining hash table.\n", key);
                break;
            case 4:
                printf("Enter key to search (Linear Probing): ");
                scanf("%d", &key);
                if (searchLinear(key))
                    printf("Key %d found in linear probing hash table.\n", key);
                else
                    printf("Key %d not found in linear probing hash table.\n", key);
                break;
            case 5:
                displayChain();
                break;
            case 6:
                displayLinear();
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
