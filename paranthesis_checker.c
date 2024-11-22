#include <stdio.h>
#include <stdlib.h>
#define bool int

struct sNode {
    char data;
    struct sNode* next;
};


void push(struct sNode** top_ref, char new_data);
char pop(struct sNode** top_ref);
bool isMatchingPair(char character1, char character2);
bool areBracketsBalanced(char exp[]);
void printStack(ste* top);

int main()
{
    struct sNode* stack = NULL;
    char exp[100];
    
    printf("Enruct sNodter a string to check: ");
    scanf("%s", exp);

    if (areBracketsBalanced(exp)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}

void push(struct sNode** top_ref, char new_data)
{
    struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));

    if (new_node == NULL) {
        printf("Stack overflow\n");
        exit(0);
    }

    new_node->data = new_data;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;

    
    printf("\nPushed: %c\n", new_data);
    printStack(*top_ref);
}

char pop(struct sNode** top_ref)
{
    char res;
    struct sNode* top;
    if (*top_ref == NULL) {
        printf("Stack underflow\n");
        exit(0);
    } else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);

        printf("\nPopped: %c\n", res);
        printStack(*top_ref);
        return res;
    }
}

bool isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

bool areBracketsBalanced(char exp[])
{
    int i = 0;
    struct sNode* stack = NULL;

    while (exp[i]) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(&stack, exp[i]);
        }

        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (stack == NULL) {
                return 0;
            } else if (!isMatchingPair(pop(&stack), exp[i])) {
                return 0;
            }
        }
        i++;
    }

    return (stack == NULL);
}

void printStack(struct sNode* top)
{
    printf("Current stack state:\n");
    if (top == NULL) {
        printf("  (empty)\n");
        return;
    }

    struct sNode* temp = top;
    while (temp != NULL) {
        printf("  %c\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
