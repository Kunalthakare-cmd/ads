#include<stdio.h>
int fact(int n){
    if(n==0)
    return 1;
int factorial = n*fact(n-1);
return factorial;
}
void main(){
    int n;
    printf("Enter the no:");
    scanf("%d",&n);
    int factorial =fact(n);
    printf("Factorial is %d",factorial);
}