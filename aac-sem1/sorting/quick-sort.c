
#include <stdio.h>

void quickSort(int a[], int low, int high)
{
    int i, j, pivot, temp;

    if (low < high)
    {
        pivot = a[high]; // choose a pivot ( end of array)
        i = low - 1; // -1 for starters 

        for (j = low; j < high; j++)
        {
            if (a[j] <= pivot) // if current smaller than pivot
            {
                i++; // increment i
// swap the i and j that is previous with current 
                temp = a[i]; 
                a[i] = a[j];
                a[j] = temp;
            }
        }
// if current is not smaller that pivot then swap  next element with last element 
      // put the last element into correct position
        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int p = i + 1; // find final pivot position

        quickSort(a, low, p - 1); //sort left
        quickSort(a, p + 1, high); // sort right
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

    quickSort(a, 0, n - 1); // low , high

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
