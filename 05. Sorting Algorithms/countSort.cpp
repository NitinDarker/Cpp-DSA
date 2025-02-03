#include <algorithm> // for max_element
#include <iostream>
#include <vector>
using namespace std;

vector<int> countingSort(const vector<int> &arr) {
    // Find the maximum value in the array to size our frequency array.
    int maxVal = *max_element(arr.begin(), arr.end());

    // Create a frequency array with indices 0 to maxVal, initialized to 0.
    vector<int> freq(maxVal + 1, 0);

    // Count the occurrences of each number.
    for (int num : arr) {
        freq[num]++;
    }

    // Build the sorted array.
    vector<int> sortedArr;
    for (int num = 0; num <= maxVal; num++) {
        while (freq[num] > 0) {
            sortedArr.push_back(num);
            freq[num]--;
        }
    }

    return sortedArr;
}

int main() {
    vector<int> arr = {3, 6, 4, 1, 3, 4, 1, 4};
    vector<int> sortedArr = countingSort(arr);

    // Print the sorted array.
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
