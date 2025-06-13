// https://leetcode.com/problems/climbing-stairs/description/
#include <bits/stdc++.h>
using namespace std;

int dpClimb(int n, vector<int> &dp) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = dpClimb(n - 1, dp) + dpClimb(n - 2, dp);
    return dp[n];
}

int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    return dpClimb(n, dp);
}