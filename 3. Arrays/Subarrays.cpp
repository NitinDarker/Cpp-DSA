// Sub-array is a continuous part of an array
#include <iostream>
using namespace std;
void sub_array(int *arr, int n)
{// no of sub-arrays = n*(n+1)/2
     for(int i=0; i<n; i++){
          for(int j=i; j<n; j++){
               cout << '(';
               for(int k=i; k<=j; k++){
                    cout << arr[k] ;
               }
               cout << ") ";
          }
          cout << "\n";
     }
}// Time Complexity = O(n^3)

int main()
{
     int arr[] = {1, 2, 3, 4, 5};
     int size = sizeof(arr) / sizeof(int);
     sub_array(arr, size);
     return 0;
}