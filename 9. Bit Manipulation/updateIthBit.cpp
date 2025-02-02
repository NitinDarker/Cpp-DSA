#include <iostream>
using namespace std;

int clearIthBit(int n, int i) { // Returns the num after setting its ith bit to 0
    int mask = ~(1 << i);       // Accessing the ith bit of n
    return n & mask;
}

int updateIthBit(int n, int i, bool b) { // Updates the num after setting its ith bit to b
    n = clearIthBit(n, i);
    int mask = b << i;
    return n | mask;
}

int main() {
    int n = 7;
    int i = 2; // Right most bit is 0th place
    cout << updateIthBit(n, i, 0) << endl;
    return 0;
}