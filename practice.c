 #include<stdio.h>

int main(){
    int n;
    printf("Enter the no of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int target;
    printf("Enter the target:");
    scanf("%d",&target);
    int sum=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            sum= arr[i] + arr[j];
            if(sum == target)
            printf("[%d,%d]",arr[i],arr[j]);
           
        }
        
    }
    
    return 0;
}