#include <iostream>
using namespace std;

void printArray(int *arr, int size)
{ // Function to print an array in terminal
     for (int i = 0; i < size; i++)
     {
          cout << arr[i] << " ";
     }
}

void reverseArray(int *arr, int size)
{ // Without using extra space -> Two Pointer Approach
     for (int i = 0; i < size / 2; i++)
     {
          int temp = arr[i];
          arr[i] = arr[size - i - 1];
          arr[size - i - 1] = temp;
     }
} // Time Complexity = O(n)
  // Space Complexity = O(1)

void reverseArray2(int *arr, int size)
{ // Using extra space -> Not optimized
     int rev[size]; // Creating a whole new array to reverse

     for (int i = 0; i < size; i++)
     {
          rev[i] = arr[size - i - 1];
     }

     for (int i = 0; i < size; i++)
     {
          arr[i] = rev[i];
     }
} // Time Complexity = O(n)
  // Space Complexity = O(n)

int main()
{
     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
     int size = sizeof(arr) / sizeof(int);

     cout << "Original Array: ";
     printArray(arr, size);

     reverseArray(arr, size);

     // reverseArray2(arr, size);

     cout << "\nReversed Array: ";
     printArray(arr, size);

     return 0;
}