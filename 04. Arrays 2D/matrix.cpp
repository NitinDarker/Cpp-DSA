#include <iostream>
using namespace std;

int main() {
    int m = 3;
    int n = 3;

    // cout << "Input the elements of a matrix: " << endl;
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cin >> matrix[i][j];
    //     }
    // }

    int matrix[m][n] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 0}};

    cout << "Matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Pointers: " << endl << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // cout << &matrix[i][j] << " ";
            printf("%u ", &matrix[j][i]);
        }
        cout << endl;
    }
    return 0;
}