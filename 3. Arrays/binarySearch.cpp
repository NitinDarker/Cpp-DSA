#include <iostream>
using namespace std;

void sort(int *arr, int size) { // Function to sort an array
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i]; // Needed to use a temporary variable to swap
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
} // Time Complexity = O(n^2)

void printArray(int *arr, int size) { // Function to print the all the elements in an array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int binarySearch(int *arr, int n, int num) { // Time Complexity = O(log(n))
    int i = 0;                               // Starting index
    int j = n - 1;                           // Last index
    while (i <= j) {
        int mid = (i + j) / 2; // Middle Index
        if (arr[mid] == num) {
            return mid;
        } else if (arr[mid] > num) {
            j = mid - 1; // Search in first half of array
        } else if (arr[mid] < num) {
            i = mid + 1; // Search in second half of array
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {100, 20, 3, 4, 25, 6, 17, 8, 9, 10, 28};

    int size = sizeof(arr) / sizeof(int);

    sort(arr, size); // Sorting is required to perform binary search

    int element;
    cout << "\nInput an element to search: ";
    cin >> element;
    // Index returned is according to sorted array
    cout << "Index in array: " << binarySearch(arr, size, element) << endl;
    // printArray(arr, size);
    return 0;
}