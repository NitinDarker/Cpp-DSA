#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    int bitMask = n & (n - 1);
    return !bitMask;
}

int main() {
    int n = 128;
    cout << isPowerOfTwo(n) << endl;
    return 0;
}