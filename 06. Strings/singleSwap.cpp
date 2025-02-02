#include <iostream>
#include <string>
using namespace std;

bool singleSwap(string st1, string st2) {
    int count = 0;
    int arr[2] = {-1};

    if (st1.length() != st2.length()) {
        return false;
    }

    for (int i = 0; i < st1.length(); i++) {
        if (st1[i] != st2[i]) {
            arr[count++] = i;
        }
        if (count > 2) {
            return false;
        }
    }

    if (count == 2) {
        swap(st1[arr[0]], st1[arr[1]]);
        if (st1 == st2) {
            return true;
        }
    } else if (count == 0) {
        return true;
    }
    return false;
}

int main() {
    string st1 = "nitin";
    string st2 = "nniit";

    cout << singleSwap(st1, st2);
    return 0;
}