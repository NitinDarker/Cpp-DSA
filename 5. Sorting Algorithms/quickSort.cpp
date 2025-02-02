// QuickSort algorithm
#include <iostream>
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) {
    // Choose the last element as the pivot
    int pivot = arr[high];

    int i = low;  // Start pointer
    int j = high; // End pointer

    // Loop to rearrange elements based on the pivot
    while (i < j) {
        // Move the 'i' pointer to the right until an element
        // larger than or equal to the pivot is found
        while (arr[i] < pivot && i < high)
            i++;

        // Move the 'j' pointer to the left until an element
        // smaller than the pivot is found
        while (arr[j] >= pivot && j > low)
            j--;

        // If the pointers haven't crossed, swap the elements
        if (i < j)
            swap(arr[i], arr[j]);
    }

    // Place the pivot in its correct position by swapping it with the element at index 'i'
    swap(arr[i], arr[high]);

    // Return the partition index, where the pivot is now correctly placed
    return i;
}

// Function to perform QuickSort
void quickSort(int arr[], int low, int high) {
    // Base condition: If the array has one or no elements, it is already sorted
    if (low < high) {
        // Find the partition index; the pivot is placed at its correct position
        int partIndex = partition(arr, low, high);

        // Recursively apply QuickSort to the left sub-array (elements before the pivot)
        quickSort(arr, low, partIndex - 1);

        // Recursively apply QuickSort to the right sub-array (elements after the pivot)
        quickSort(arr, partIndex + 1, high);
    }
}
/* Time Complexity:
    Average: O(n*log⁡n)
    Worst Case: O(n^2) (when the pivot divides the array poorly).
*/
// Space Complexity: O(log⁡n) for the recursive stack.

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
