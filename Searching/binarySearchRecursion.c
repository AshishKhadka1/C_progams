#include <stdio.h>

// Function to perform binary search recursively
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // If the target is found, return its index
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is in the left subarray, search there
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        // If the target is in the right subarray, search there
        return binarySearch(arr, mid + 1, right, target);
    }

    // If the target is not in the array, return -1
    return -1;
}

int main() {
    int n, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
