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
  for(int i=0 ; str[i]!='\0';i++){
    char ch =str[i];
    push(ch);
  }
   for(int j=0 ;str[j]!='\0'; j++){
    if(str[j]==topfn()){
        pop();
    } 
   }
    if(isEmpty()) printf("String is a Palindrome");

    else printf("String is not a Palindrome");
   
    return 0;
}
