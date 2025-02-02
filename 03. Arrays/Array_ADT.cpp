#include <iostream>
using namespace std;

struct array {
    int size;
    int *data;
    int current_pointer;
};

void createArray(array &arr, int size) {
    arr.size = size;
    arr.data = new int[size];
    arr.current_pointer = -1;
}

void traverseArray(array &arr) {
    for (int i = 0; i < arr.size; i++) {
        arr.data[i] = i;
    }
}

void displayArray(array &arr) {
    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
}

int main() {
    array arr;
    int size = 5;
    createArray(arr, size);
    traverseArray(arr);
    displayArray(arr);
}