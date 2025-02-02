// Solving Fibonacci Problem using Dynamic Programming
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Using memoization concept -> Top Down Approach (Recursion + DP)
int fib(int n, vector<int> &dp) {
    if (n <= 1) { // Base condition
        return n;
    }
    // Checking if the value is already present in the DP array
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    vector<int> dp(100, -1); // Declaring a DP array
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is: " << fib(n, dp) << endl;
    return 0;
}