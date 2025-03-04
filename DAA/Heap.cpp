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

    int popRoot() {
        int x = arr[0];
        deleteKey(x);
        return x;
    }

  private:
    // To delete the root in heap Array
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
    }

  public:
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