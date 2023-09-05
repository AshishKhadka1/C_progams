#include <stdio.h>

// Function to heapify a subtree rooted at node 'index' in the array 'arr' of size 'size'.
void heapify(int arr[], int size, int index) {
    int largest = index; // Initialize the largest as the root
    int left = 2 * index + 1; // Left child
    int right = 2 * index + 2; // Right child

    // If the left child is larger than the root
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the largest so far
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // If the largest is not the root, swap them and recursively heapify the affected sub-tree
    if (largest != index) {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

// Main function to perform heap sort on the array 'arr' of size 'size'.
void heapSort(int arr[], int size) {
    // Build a max-heap from the array
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // Extract elements one by one from the heap
    for (int i = size - 1; i > 0; i--) {
        // Move the current root to the end of the array
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    heapSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}
