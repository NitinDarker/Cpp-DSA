#include <Heap.cpp>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

Heap *h1 = new Heap;
void sortPtr(vector<vector<int>> arr, int ptr) {
    while (true) {
        vector<int> ptrArr;
        int m = arr.size();
        for (int i = 0; i < m; i++) {
            if (arr[i].size() > ptr)
                ptrArr[i] = arr[i][ptr];
        }

        // Sort ptrArr through heap
        for (int i = 0; i < ptrArr.size(); i++) {
            h1->insertKey(ptrArr[i]);
        }

        vector<int> ans;
        ans.push_back(h1->popRoot());
        ptr++;
    }
}

void sortNList(vector<vector<int>> &arr) {
    int m = arr.size();
    int ptr = 0;
}

int main() {

    return 0;
}