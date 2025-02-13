#include <iostream>
using namespace std;

void printFib(int n) {
    int s1 = 0;
    int s2 = 1;
    int s3 = s1 + s2;
    cout << s1 << " " << s2 << " ";

    // For n = number of digits in fibonacci sequence
    for (int i = 0; i < n - 1; i++) {
        s3 = s1 + s2;
        cout << s3 << " ";
        s1 = s2;
        s2 = s3;
    }
    cout << endl;

    // For n = last digit of the fibonacci sequence
    // s1 = 0;
    // s2 = 1;
    // s3 = s1 + s2;
    // while (s3 <= n) {
    //     cout << s3 << " ";
    //     s1 = s2;
    //     s2 = s3;
    //     s3 = s1 + s2;
    // }
    // cout << endl;
}

int fib(int n) {
    // For n = number of digits in fibonacci sequence
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 6; // For n = number of digits in fibonacci sequence
    for (int i = 0; i <= n; i++) {
        cout << fib(i) << " ";
    }
    return 0;
}