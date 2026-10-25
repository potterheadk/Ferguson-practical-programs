

#include <stdio.h>
//merge sepreated numbers back to array but in sorted way
void merge(int a[], int low, int mid, int high)
{
    int temp[100]; // create temp array to store merged array
  // i = left sub-array , j = right sub-array
  //k to track elements in temp array
    int i = low, j = mid + 1, k = 0;

  // Compares the smallest available item from the left half against the smallest available item from the right half.
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
//now cleanup if right array is exhausted and left still has element dump in temp
    while (i <= mid)
        temp[k++] = a[i++];

//now cleanup if left array is exhausted and right still has element dump in temp
    while (j <= high)
        temp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[low + i] = temp[i];
}
// find mid and recursiviely call half sub array left to mid and mid to right 
void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
