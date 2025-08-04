// Sub-array is a continuous part of an array
#include <climits> // Header file to include INT_MIN macro
#include <iostream>
using namespace std;

// This is the best way to solve (Using DP)
int sub_array_sum(int *arr, int n) { // Max Sub-array sum = Sum of all elements of array (Only if all the elements are positive)
    int max_sum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];

        max_sum = max(sum, max_sum);

        if (sum < 0)
            sum = 0;
    }
    return max_sum;
} // Time Complexity = O(n) -> Best

int main() {
    int arr[] = {-2, -3, -6, -5, -4, -8};
    int size = sizeof(arr) / sizeof(int);
    cout << "Max Subarray sum: " << sub_array_sum(arr, size);
    return 0;
}