#include <iostream>
#include <map>
using namespace std;

int main() {

    cout << "Enter the size of the input array: " << endl;
    int size;
    cin >> size;

    int *arr = new int[size];
    // int arr[size];

    cout << "Enter the elements of the array- " << endl;
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] : ";
        cin >> arr[i];
    }

    map<int, int> mpp;

    for (int i = 0; i < size; i++) {
        mpp[arr[i]]++;
    }

    cout << "Enter the number of queries: " << endl;
    int q;
    cin >> q;

    while (q--) {
        cout << "Enter the num whose freq is to be found: ";
        int num;
        cin >> num;
        cout << "Frequency of " << num << " = ";
        cout << mpp[num] << endl;
    }
}