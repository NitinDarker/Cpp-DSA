// Bitmasks are used to access specific bits in a byte of data
#include <iostream>
using namespace std;

bool getIthBit(int n, int i) { // Returns the bit on the ith place of n
    int mask = (1 << i);       // Accessing the ith bit of n
    if (n & mask) {
        return 1;
    }
    return 0;
}

int setIthBit(int n, int i) { // Return the num after setting its ith bit to 1
    int mask = (1 << i);      // Accessing the ith bit of n
    return n | mask;
}

int clearIthBit(int n, int i) { // Returns the num after setting its ith bit to 0
    int mask = ~(1 << i);       // Accessing the ith bit of n
    return n & mask;
}

int toggleIthBit(int n, int i) { // Returns the num after toggling the ith bit
    int mask = (1 << i);         // Accessing the ith bit of n
    return n ^ mask;
}

int clearRightmostSetBit(int n) { // Returns num after clearing the last (rightmost) set bit
    return n & (n - 1);
}

int main() {
    int n = 7;
    int i = 1; // Right most bit is 0th place
    cout << getIthBit(n, i) << endl;
    cout << clearIthBit(n, i) << endl;
    cout << setIthBit(n, i) << endl;
    return 0;
}