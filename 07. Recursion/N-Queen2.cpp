#include <bits/stdc++.h>
using namespace std;

class Solution {
    int count = 0;

    void solve(int n, int row, int cols, int diag1, int diag2) {
        if (row == n) {
            count++;
            return;
        }

        // All positions available for the current row
        int availablePositions = ((1 << n) - 1) & (~(cols | diag1 | diag2));

        while (availablePositions) {
            int pos = availablePositions & -availablePositions; // Get the rightmost 1-bit
            availablePositions -= pos;                          // Remove this position

            solve(n, row + 1,
                  cols | pos,
                  (diag1 | pos) << 1,
                  (diag2 | pos) >> 1);
        }
    }

  public:
    int totalNQueens(int n) {
        count = 0;
        solve(n, 0, 0, 0, 0);
        return count;
    }
};

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    Solution s;
    int res = s.totalNQueens(n);
    cout << "Total solutions: " << res << endl;

    return 0;
}
