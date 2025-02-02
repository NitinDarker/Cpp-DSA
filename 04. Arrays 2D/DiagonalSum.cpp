#include <iostream>
using namespace std;

int main() {
    int m = 4;
    int n = 4;
    int matrix[m][n] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};

    // cout << "Primary Diagonal: " << endl;
    int psum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i] == matrix[j]) {
                // cout << matrix[i][j] << " ";
                psum += matrix[i][j];
            }
        }
    }
    cout << endl;
    
    // cout << "Secondary Diagonal: " << endl;
    int ssum = 0;
    int i=0, j=n-1;
    while(i<m && j<n) {
        // cout << matrix[i][j] << " ";
        ssum += matrix[i][j];
        i++;
        j--;
    }
    cout << endl;

    cout << "Primary Sum = " << psum << endl;
    cout << "Secondary Sum = " << ssum << endl;
    return 0;
}