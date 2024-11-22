#include <stdio.h>
#include <stdlib.h>

void main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int *arr;
    arr = (int*)malloc(n * sizeof(int));  

    printf("Enter the elements of array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;
         
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = current;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//// best case : O(n)
/// worst case : O(n^2)
/// Average case: O(n^2)