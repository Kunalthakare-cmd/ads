#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
} 

int isEmpty()
{
    return top == NULL;
}

void push(int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = top; 
    top = newNode;
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct Node *temp = top;
        int pop = temp->data;
        top = top->next;
        free(temp);
        return pop;
    }
}

int top_element()
{
    if (isEmpty())
    {
        printf("Stack is empty!\n");
        exit(1);
    }
    return top->data;
}

void print()
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{ 
   int choice;
    int value;

    while(1){
   printf("1. Push\n");
   printf("2. Pop\n");
   printf("3. Print Stack\n");
   printf("4. Peek element\n");
   printf("Enter your choice:");

   scanf("%d",&choice);
   switch(choice){

   case 1: printf("Enter the Data to add in stack:");
            scanf("%d",&value);
            push(value);
            break;
    case 2: pop();
            break;
    case 3: print();
            break;
    case 4: top_element();
    default: printf("Invalid choice");
   }
    }
    return 0;
}
