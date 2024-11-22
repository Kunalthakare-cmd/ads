#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int flag;
    for (int i = 1; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }

    printf("Sorted array:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
