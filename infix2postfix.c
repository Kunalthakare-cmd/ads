#include <stdio.h>
#include <ctype.h> 
#include <string.h> 
#define MAX 100`

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}

char top_element() {
    return stack[top];
}

int order(char ch) {
    switch (ch) {
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
        default: return 0;
    }
}


int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
    return  ch;
}

void reverse(char* str) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

}
void infixToPostfix(char* infix) {
    char postfix[MAX];
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
       
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
       
        else if (infix[i] == '(') {
            push(infix[i]);
        }
   
        else if (infix[i] == ')') {
            while (top_element() != '(') {
                postfix[j++] = pop();
            }
            pop();  
        }

        else if (isOperator(infix[i])) { 
            while (top != -1 && order(top_element()) >= order(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);

    return 0;
}
