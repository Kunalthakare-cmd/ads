#include <stdio.h>
#include <stdbool.h>

#define Max 1000
int top = -1;
int stack[Max];

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == Max-1;
}

void push(int a) {
    if (isFull()) return;
     else {
        top++;
        stack[top] = a;
    }
}
int size(){
    return top+1;
} 
int pop() {
    if (isEmpty()) return -1;
     else {
        int value = stack[top];
        top--;
        return value;
    }
}

void printStack() {
    if (isEmpty()) {
        printf("stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d \n", stack[i]);
        }
        printf("\n");
    }
}
int topfn(){
    return stack[top];  
}

int main() {
    int choice;
    int value;

    while(1){
   printf("1. Push\n");
   printf("2. Pop\n");
   printf("3. Print Stack\n");
   printf("Enter your choice:");

   scanf("%d",&choice);
   switch(choice){

   case 1: printf("Enter the Data to add in stack:");
            scanf("%d",&value);
            push(value);
            break;
    case 2: pop();
            break;
    case 3: printStack();
            break;
    default: printf("Invalid choice");
   }
    }
    return 0;
}
