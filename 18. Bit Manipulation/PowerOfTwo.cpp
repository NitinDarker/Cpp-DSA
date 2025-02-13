#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    int bitMask = n & (n - 1);
    if (!bitMask) {
        return true;
    }
    return false;
}

int main() {
    int n = 128;
    cout << isPowerOfTwo(n) << endl;
    return 0;
}