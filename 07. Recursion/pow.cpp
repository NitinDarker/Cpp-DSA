#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int pow(int x, int n) { // x^n

    long double ans = 1;
    if (n == 0) {
        return 1;
    }

    static bool isNeg = false;
    if (n < 0) {
        isNeg = true;
        n *= -1;
    }

    int recPow = pow(x, n / 2);
    int powpow = recPow * recPow;

    if (n % 2 == 0) {
        ans = powpow;
    } else {
        ans = x * powpow;
    }

    if (isNeg) {
        ans = 1 / ans;
    }
    return ans;
}

int main() {

    return 0;
}