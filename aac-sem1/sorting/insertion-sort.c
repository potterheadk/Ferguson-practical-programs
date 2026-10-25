#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[100], i, j;
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    printf("Enter array:");

    // input array
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // take key put it in righ  spot check from right to left and put key
    // properly
    for (int i = 0; i < n; i++)
    {
        int key = arr[i]; // current
        j = i - 1;        // current -1  element
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // shift it to right
            j--;                 // make room for new
        }

        arr[j + 1] = key; // put the key to right new spot
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
