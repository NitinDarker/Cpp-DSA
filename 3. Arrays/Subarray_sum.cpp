// Sub-array is a continuous part of an array
#include <iostream>
#include <climits> // Header file to include INT_MIN macro
using namespace std;

// Not an optimized way to solve
int sub_array_sum(int *arr, int n)
{ // Max Sub-array sum = Sum of all elements of array (Only if all the elements are positive)
     int sum = 0;
     int max_sum = INT_MIN;
     for (int i = 0; i < n; i++){
          for (int j = i; j < n; j++){
               for (int k = i; k <= j; k++){
                    sum += arr[k];
               }
               max_sum = max(sum, max_sum);
               sum = 0;
          }
     }
     return max_sum;
} // Time Complexity = O(n^3) -> Very High

int main()
{
     int arr[] = {2, -3, 6, -5, 4, 2};
     int size = sizeof(arr) / sizeof(int);
     cout << "Max Subarray sum: " << sub_array_sum(arr, size);
     return 0;
}