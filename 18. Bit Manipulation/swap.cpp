#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Swap without using any extra variables
void swap(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {
    int x = 5;
    int y = 10;
    swap(x, y);
    cout << x << " " << y << endl;
    return 0;
}