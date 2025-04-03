/* The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// To check if it possible to place queen at given row and col
bool isSafe(int row, int col, int n, vector<string> &board) {
    int ogRow = row;
    int ogCol = col;

    // Upper left diagonal
    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }

    row = ogRow;
    col = ogCol;

    // Left row
    while (col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        col--;
    }

    row = ogRow;
    col = ogCol;

    // Lower Left diagonal
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q') {
            return false;
        }
        row++;
        col--;
    }

    return true; 
    // Yes it is safe to place Queen in this spot
}

// Recursive-BackTracking function
void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans) {

    if (col == n) {
        // Base condition for recursion
        ans.push_back(board);
        return;
    }
    // To place the queen in every row
    for (int row = 0; row < n; row++) {

        // Check if it possible to place the queen in given row & col
        if (isSafe(row, col, n, board)) {
            
            // Placing queen on board
            board[row][col] = 'Q';         
            
            // Recursion step with col+1
            solve(col + 1, n, board, ans); 
            
            // Backtracking step
            board[row][col] = '.';         
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans; // To store all the possible answers
    vector<string> board(n);    // To represent an empty chess board
    string str(n, '.');
    for (int i = 0; i < n; i++) {
        board[i] = str;
    }

    solve(0, n, board, ans);
    return ans;
}

int main() {
    int n = 16;
    vector<vector<string>> ans = solveNQueens(n);
    cout << ans.size() << endl;
    return 0;
}
