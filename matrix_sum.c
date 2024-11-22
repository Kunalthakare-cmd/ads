#include<stdio.h>

void input(int arr[],int row, int column){
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            
            scanf("%d",&arr[i][j]);
        }
    }
    }

void sum(int arr[], int brr[], int row ,int column){
    int crr[row][column];
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            crr[i][j]=arr[i][j]+brr[i][j];
        }
    }
}
void printarr(int arr[][], int row, int column){
printf("Sum of array is:\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    
    int row, column;
    printf("Enter the no of rows:");
scanf("%d",&row);

printf("Enter the no of rows:");
scanf("%d",&column);

int arr[row][column];
int brr[row][column];
int crr[row][column];
input(arr,row,column);
input(brr,row,column);
sum(arr,brr);
print(crr);



}