#include <iostream>
using namespace std;

// Selection Sort is NOT stable -> if same element is present then order may not be maintained
// Selection Sort is NOT adaptive -> Doesn't take advantage of already sorted array

void selectionSort(int *arr, int size) {
    int i, j;

    for (i = 0; i < size - 1; i++) { // For the number of passes
        int sma = i; // sma contains index of min element in each pass
        for (j = i + 1; j < size; j++) { // For checking the min element in each pass
            if (arr[sma] > arr[j]) {
                sma = j; // Storing the index of new min element
            }
        }
        if (sma != i)
            swap(arr[i], arr[sma]); // This algo uses least number of swaps
    }
} // Time Complexity = O(n^2)

void display(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {565, 654, 66, 2, 67, 99, 109, 34, 90, 71, 0, 16, 6};
    int arr2[] = {1, 2, 4, 5, 6, 8, 9};
    int arr3[] = {1, 3, 8, 2};
    int size = sizeof(arr) / sizeof(int);

    selectionSort(arr, size);
    display(arr, size);
    return 0;
}