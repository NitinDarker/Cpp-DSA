#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int firstOccurrence(vector<int> v, int key) {
    static int i = 0;

    if (i == v.size()) {
        return -1;
    }

    if (v[i] == key) {
        return i;
    }

    i++;
    return firstOccurrence(v, key);
}

int lastOccurrence(vector<int> v, int key) {
    static int i = 0;

    if (i == v.size()) {
        return -1;
    }
    i++;
    int idx = lastOccurrence(v, key);
    if (idx == -1) {
        if (v[i] == key) {
            return i;
        }
        i--;
    }
    return idx;
}

int main() {
    int key = 9;
    vector<int> v = {1, 2, 3, 3, 3, 4, 9, 9};
    cout << "First occurrence at index: " << firstOccurrence(v, key) << endl;
    cout << "Last occurrence at index: " << lastOccurrence(v, key) << endl;
    return 0;
}