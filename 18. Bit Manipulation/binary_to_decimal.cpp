#include <iostream>
using namespace std;

// int pow(int x, int n) {
//     if (n == 0) {
//         return 1;
//     }
//     int myPow = pow(x, n / 2);
//     if (n % 2 == 0) {
//         return myPow * myPow;
//     }
//     return x * myPow * myPow;
// }

int binary_to_decimal(int bin) {
    int dec = 0;
    int mul = 1;
    while (bin > 0) {
        int digit = bin % 10;
        dec += (mul * digit);
        mul *= 2;
        bin /= 10;
    }
    return dec;
}

int main() {
    cout << "Enter a binary number: ";
    int n;
    cin >> n;
    cout << "Decimal: " << binary_to_decimal(n) << endl;
}