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
    cout << "Enter two numbers to swap - " << endl;
    int x, y;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    swap(x, y);
    cout << "Swapping..." << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    return 0;
}