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
    char str[100];
   printf("Enter a string:");
   scanf("%s", str);
   int i=0;
   while(str[i]!='\0'){
    char ch = str[i];
    push(ch);
    i++;
   }
   printf("Reversed string is:");
   int j=0;
   while(str[j]!='\0'){
    printf("%c",pop());
    j++;
   }
    return 0;
}
