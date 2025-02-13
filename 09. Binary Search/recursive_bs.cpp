#include <iostream>
using namespace std;

int binarySearch(int *arr, int low, int high, int target) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    // int  mid = low + ((high - low) / 2); 
    // To counter the overflow case -> high = INT_MAX 

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, high, target);
    }
}

void printArray(int *arr, int size) { // Function to print the all the elements in an array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 100};

    int size = sizeof(arr) / sizeof(int);

    int element;
    cout << "\nInput an element to search: ";
    cin >> element;
    // Index returned is according to sorted array
    cout << "Index in array: " << binarySearch(arr, 0, size - 1, element) << endl;
    cout << "Sorted Array: ";
    printArray(arr, size);
    return 0;
    return 0;
}