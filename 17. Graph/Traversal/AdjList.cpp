#include <bits/stdc++.h>
using namespace std;

// Storing Undirected graph as an adjacency list
int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    
    // Assuming 1-based indexing
    vector<vector<int>> list(v+1);
    
    cout << "Input all edges in the graph: " << endl;
    for (int i = 0; i < e; i++) {
        int m, n;
        cin >> m >> n;
        list[m].push_back(n);
        list[n].push_back(m);
    }
    // Space Complexity -> O(2*E)
    return 0;
}