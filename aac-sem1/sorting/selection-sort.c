// Complexity: Best, average and worst case: \(O(n^2)\).

#include <stdio.h>

int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int a[n], min, temp;
//input array
    printf("Enter elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

  // find min and swaping based on current minimum so far
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
