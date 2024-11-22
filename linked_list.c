#include<stdio.h>
#include<stdlib.h>   

struct node{
    int data;
    struct node *next;
}*header;

void createlist(int n){
    struct node* newnode , *temp;
    int info;
    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode==NULL){
        printf("unable to allocate memory");
    }
    else{
        printf("Enter the data of node1:");
        scanf("%d",&info);
        newnode->data= info;
        newnode->next= NULL;
        header=newnode;
        temp = newnode;
        
        for(int i =2 ; i<=n;i++){
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter the data of node%d:",i);
            scanf("%d",&info);
            newnode->data = info;
            newnode->next =NULL;
            temp->next = newnode;
            temp=temp->next;
        }
    }
}
void transverselist(struct node *header){
    struct node* temp;
    temp = header;
    while(temp!=NULL){
        printf("Data = %d->",temp->data);
        temp = temp->next;
    }
}

void main(){
  int n;
  printf("Enter the total no of nodes:");
  scanf("%d",&n);
  createlist(n);
  printf("Data in the list\n");
  transverselist(header);
}

