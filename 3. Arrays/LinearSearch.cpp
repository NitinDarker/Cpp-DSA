#include <iostream>
using namespace std;

int linearSearch(int *arr, int size, int num)
{ // Time complexity = O(n)
     for (int i = 0; i < size; i++)
     {
          if (num == arr[i])
          {
               return i;
          } // Returning the index of num
     }
     return -1; // If not found then return index = -1
}

int main()
{
     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

     int size = sizeof(arr) / sizeof(int);

     int element;
     cout << "Input an element to search: ";
     cin >> element;

     cout << "Index in array: " << linearSearch(arr, size, element) << endl;
     return 0;
}