#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int a[n];
// get array
    printf("Enter array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

  // find maximum in array
    int max = a[0];
    // find max
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

  // count the frequency and put it in array
    int *count = calloc(max + 1, sizeof(int));
    if (count == NULL)
    {
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

  //  //sort with count sort using the max and max frequency and - the count
    printf("Sorted array:");
    for (i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            printf("%d ", i);
            count[i]--;
        }
    }

    free(count);

    return 0;
}
