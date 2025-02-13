#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printName(int n) {
    if (n > 0) {
        cout << "Nitin " << n << endl;
        printName(n - 1);
    }
}

void printNum(int n) {
    if (n > 0) {
        printNum(n - 1);
        cout << n << " ";
    }
}

void printNumRev(int n) {
    // if (n > 0) {
    //     cout << n << " ";
    //     printNumRev(n - 1);
    // }
    if (n < 0) {
        return;
    }
    cout << n << " ";
    printNumRev(n - 1);
}

void printNumRev(int n, int i) {
    if (i > n) {
        return;
    }
    printNumRev(n, i + 1);
    cout << i << " ";
}

int main() {

    // printName(5);
    printNumRev(50, 10);

    return 0;
}