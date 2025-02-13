#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Input size of input array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Input the elements of the array -" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int hash[13] = {0};

    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    cout << "Enter the number of queries: ";
    int query;
    cin >> query;

    for (int i = 0; i < query; i++) {
        cout << "Enter the number whose frequency you have to find: " << endl;
        int num;
        cin >> num;

        cout << "Frequency of " << num << " is: " << hash[num] << endl;
    }

    return 0;
}