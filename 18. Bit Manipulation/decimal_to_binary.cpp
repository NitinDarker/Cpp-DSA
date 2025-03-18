#include <iostream>
using namespace std;

int decimal_to_binary(int dec) {
    int bin = 0;
    while (dec > 0) {
        bin = (bin * 10) + (dec % 2);
        dec /= 2;
    }
    return bin;
}

int main() {
    cout << "Enter a decimal number: ";
    int n;
    cin >> n;
    cout << "Binary: " << decimal_to_binary(n) << endl;
}