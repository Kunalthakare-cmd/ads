#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createlist(int n) {
    int value;
    struct node* newnode, *temp, *header;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value fo r node 1");
    scanf("%d",&value);
    newnode->data = value;
    newnode->next = NULL;
    header = newnode;
    temp = newnode;
    
    for (int i = 2; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter the data for node%d:",i);
        scanf("%d",&value);
        newnode->data = value;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
    
    return header;
}

int main() {
    int carry = 0;
    int x,y;
    printf("Enter the no of nodes for list 1:");
    scanf("%d",&x);
    struct node *L1 = createlist(x);
     printf("Enter the no of nodes for list 2:");
    scanf("%d",&y);
    struct node *L2 = createlist(y);
    struct node* temp1 = L1;
    struct node* temp2 = L2;
    
    while (temp1 != NULL || temp2 != NULL || carry != 0) {
        int sum = carry;
        
        if (temp1 != NULL) {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        
        if (temp2 != NULL) {
            sum += temp2->data;
            temp2 = temp2->next;
        }
        
        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }
        
        printf("%d->", sum);
    }
    
    printf("NULL\n");
    return 0;
}

