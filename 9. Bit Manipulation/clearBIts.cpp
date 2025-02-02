#include <iostream>
using namespace std;

int clearBits(int n, int i) { // Returns the num after clearing last i bits
    int mask = (~0) << i;
    return n & mask;
}

int main() {
    int n = 15;
    int i = 2;
    cout << clearBits(n, i) << endl;
    return 0;
}