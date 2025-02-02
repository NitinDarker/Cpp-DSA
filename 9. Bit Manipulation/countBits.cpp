#include <iostream>
using namespace std;

int countBits(int n) {
    int count = 0;
    while (n > 0) {
        int lastDig = n & 1;
        count += lastDig;
        n = n >> 1;
    }
    return count;
}

int main() {
    int n = 7;
    cout << countBits(n) << endl;
    return 0;
}