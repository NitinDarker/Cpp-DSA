#include <bits/stdc++.h>
using namespace std;

// Storing Undirected graph as an adjacency Matrix
int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    
    // Assuming 1-based indexing
    vector<vector<int>> matrix(v+1, vector<int>(v+1, 0));
    
    cout << "Input all edges in the graph: " << endl;
    for (int i = 0; i < e; i++) {
        int m, n;
        cin >> m >> n;
        matrix[m][n] = 1;
        matrix[n][m] = 1;
    } 
    // Space Complexity -> O(n^2)
    return 0;
}