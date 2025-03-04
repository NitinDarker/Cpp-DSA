#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Heap {
    vector<int> arr;
    int size;

  public:
    Heap() {
        size = 0;
    }

    // To insert a key in heap Array -> Min Heap
    void insertKey(int key) {
        arr.push_back(key);
        size++;
        int n = size - 1;              // Index for the key
        int parentIndex = (n - 1) / 2; // Index for the parent
        while (parentIndex >= 0 && n > 0) {
            if (arr[parentIndex] <= key) {
                break;
            }
            swap(arr[parentIndex], arr[n]);
            n = parentIndex;
            parentIndex = (n-1) / 2;
        }
    }

    void printHeap() {
        for (int val : arr) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap *minHeap = new Heap;
    minHeap->insertKey(5);
    minHeap->insertKey(12);
    minHeap->insertKey(16);
    minHeap->insertKey(10);
    minHeap->insertKey(6);
    minHeap->printHeap();
    return 0;
}