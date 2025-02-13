#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void revArray(int arr[], int size, int i) {
// Reversing an array using recursion
    if (i >= size / 2) {
        return;
    }
    swap(arr[i], arr[size - i - 1]);
    revArray(arr, size, i + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 9, 2, 8};
    int size = sizeof(arr) / sizeof(int);

    int i = 0;

    revArray(arr, size, i);

    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}