#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in the array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    // Find the maximum element in the array
    int max = findMax(arr, n);

    // Create an array of buckets
    int* buckets = (int*)malloc((max + 1) * sizeof(int));
    if (buckets == NULL) { 
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize the buckets with 0
    for (int i = 0; i <= max; i++) {
        buckets[i] = 0;
    }

    // Count the occurrences of each element and store them in buckets
    for (int i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    // Copy the elements back to the original array in sorted order
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (buckets[i] > 0) {
            arr[index++] = i;
            buckets[i]--;
        }
    }

    free(buckets);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
