// Sub-array is a continuous part of an array
#include <iostream>
#include <climits> // Header file to include INT_MIN macro
using namespace std;

// This is an optimized way to solve
int sub_array_sum2(int *arr, int n)
{ // Max Sub-array sum = Sum of all elements of array (Only if all the elements are positive)
     int max_sum = INT_MIN;
     for (int i = 0; i < n; i++){
          int sum = 0;
          for (int j = i; j < n; j++){
               sum += arr[j];
               max_sum = max(sum, max_sum);
          }
     }
     return max_sum;
} // Time Complexity = O(n^2) -> Moderate

int main()
{
     int arr[] = {2, -3, 6, -5, 4, 2};
     int size = sizeof(arr) / sizeof(int);
     cout << "Max Subarray sum: " << sub_array_sum2(arr, size);
     return 0;
}