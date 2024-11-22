#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
    int id;
    char name[30];
} Patient;

Patient queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return (rear == MAX - 1);
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int id, char name[]) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear].id = id;
    strcpy(queue[rear].name, name);
    
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! No patients to remove.\n");
        return;
    }
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Patients in the queue:\n");
    printf("ID\tName\n");
    for (int i = front; i <= rear; i++) {
        printf("%d\t%s\n", queue[i].id, queue[i].name);
    }
}

int main() {
    int choice, id;
    char name[30];

    while (1) {
        printf("\n Hospital Patient Queue System \n");
        printf("1. Add Patient\n");
        printf("2. Remove Patient\n");
        printf("3. Show List of Patients\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isFull()) {
                    printf("Enter Patient ID: ");
                    scanf("%d", &id);
                    printf("Enter Patient Name: ");
                    scanf("%s", name);
                    enqueue(id, name);
                } else {
                    printf("Queue is full! \n");
                }
                break;

            case 2:
                dequeue();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
