#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int sumNatural(int n) { // Functional Way
    if (n == 1) {
        return 1; // Base Condition
    }
    return n + sumNatural(n - 1);
}

int sumNatural(int i, int sum) { // Parameterized way
    if (i < 0) {
        return sum; // Base Condition
    }
    sumNatural(i - 1, sum + i);
}

int main() {
    int n = 8;
    cout << sumNatural(n) << endl;
    cout << sumNatural(n, 0) << endl;
    return 0;
}