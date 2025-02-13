#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    static int i = 0;
    if (i == n - 1) {
        return true;
    }
    if (arr[i] > arr[i + 1]) {
        return false;
    }
    i++;
    return isSorted(arr, n);
}

int main() {
    int arr[] = {1, 2, 3, 9, 5};
    int n = sizeof(arr) / sizeof(int);

    cout << "isSorted: " << isSorted(arr, n) << endl;
    return 0;
}