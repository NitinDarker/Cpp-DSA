#include <iostream>
using namespace std;

int main() {

    int row = 3;
    int col = 3;

    int* *matrix = new int *[row]; // Matrix is an array of pointers of size = row

    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col]; // Creating an array of size = col for each element of matrix
    }

    int x = 1;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    delete matrix;
    return 0;
}