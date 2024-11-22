#include<stdio.h>
int main(){
    int n;
    printf("Enter the no:");
    scanf("%d",&n);
    printf("\n"); 
    int r =  n- 2*(n/2);
    if(r==0) printf("Even No");
    else printf("Odd No");

    if(n/2*2==n) printf("Even No");
    else printf("Odd NO");
    return 0;
}