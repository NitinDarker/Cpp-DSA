// Bitmasks are used to access specific bits in a byte of data
#include <iostream>
using namespace std;

bool isEven(int num) {  // A binary number whose unit digit is 0 is even
    int mask = num & 1; // Taking AND(& with 1) of a number gives its unit digit (in binary)
    if (mask) {
        cout << "Odd Number" << endl;
        return false; // Unit digit = 1
    }
    cout << "Even Number" << endl;
    return true; // Unit digit = 0
}

int main() {
    int num = 69;
    cout << "isEven = " << isEven(num) << endl;
    return 0;
}