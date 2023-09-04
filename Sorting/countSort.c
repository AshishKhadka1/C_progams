#include <stdio.h>

#define MAX 10
#define HIGHEST 13

int getHighest(int arr[], int n)
{
    int max = arr[0], i;
    for (i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n)
{
    int temp[MAX];
    int count[HIGHEST] = {0};
    int max = getHighest(arr, n);
    int i;

    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        temp[--count[arr[i]]] = arr[i];
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    int arr[MAX] = {12, 9, 5, 2, 1, 2, 5, 7, 10, 2};
    int i;

    printf("Before Sorting.....\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }

    countSort(arr, MAX);

    printf("\nAfter Sorting......\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
