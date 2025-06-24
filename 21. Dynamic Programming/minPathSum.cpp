#include <bits/stdc++.h>
using namespace std;

// Tabulation
int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else if (i == 0) {
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            } else {
                dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m - 1][n - 1];
}

// Space Optimization
int minPathSum2(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n, 1e8);
    for (int i = 0; i < m; i++) {
        int left = 1e8;
        for (int j = 0; j < n; j++) {
            int curr = grid[i][j];
            if (i == 0 && j == 0) {
            } else {
                curr += min(left, dp[j]);
            }
            left = curr;
            dp[j] = curr;
        }
    }
    return dp[n - 1];
}

int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}};

    cout << "Minimum sum path: " << minPathSum(matrix) << endl;
    return 0;
}

// https://leetcode.com/problems/minimum-path-sum/description/
