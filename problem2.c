#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of Array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
  
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
      for(int i=0;i<n ;i++){
        if(arr[i]==0)
        printf("[%d]\n",arr[i]);
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n ; j++){
            if(arr[i]+arr[j]==0)
            printf("[%d,%d]\n",arr[i], arr[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    printf("[%d, %d, %d]\n", arr[i], arr[j], arr[k]);
                    
                }
            }
        }
    }

    return 0;
}

