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

    // To delete the root in heap Array -> Min Heap
    void deleteKey(int key) {
        if (size == 0) return;
        swap(arr[0], arr[size - 1]);
        arr.pop_back();
        size--;

        int currInd = 0;

        while (true) {
            int leftChild = 2 * currInd + 1;
            int rightChild = 2 * currInd + 2;
            int smallest = currInd;

            if (leftChild < size && arr[leftChild] < arr[smallest])
                smallest = leftChild;
            if (rightChild < size && arr[rightChild] < arr[smallest])
                smallest = rightChild;

            if (smallest == currInd)
                break; // Already in correct position

            swap(arr[currInd], arr[smallest]);
            currInd = smallest;
        }

        // while (min(arr[leftChild], arr[rightChild]) < arr[currInd]) {
        //     if (arr[leftChild] < arr[rightChild]) {
        //         swap(arr[currInd], arr[leftChild]);
        //         currInd = leftChild;
        //     } else {
        //         swap(arr[currInd], arr[rightChild]);
        //         currInd = rightChild;
        //     }
        //     leftChild = 2 * currInd + 1;
        //     rightChild = 2 * currInd + 2;
        // }
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
    minHeap->deleteKey(5);
    minHeap->deleteKey(12);
    minHeap->deleteKey(16);
    minHeap->deleteKey(10);
    minHeap->deleteKey(6);
    minHeap->printHeap();
    return 0;
}