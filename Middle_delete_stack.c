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
void delete_Middle(int count,int size){
   if(count == size/2){
    pop();
    return;
   }
   int num = pop();
   delete_Middle(count+1,size);
   push(num);

}
int main(){
    int size;
    int data;
    printf("Enter the stack size:");
    scanf("%d",&size);
    printf("Enter elements of stack\n");
    for(int i=0;i<size ;i++){
        scanf("%d",&data);
        push(data);
    }
    int count=0;
    delete_Middle(count,size);
    printf("stack after deleting Middle element\n");
    printStack();

    return 0;
}