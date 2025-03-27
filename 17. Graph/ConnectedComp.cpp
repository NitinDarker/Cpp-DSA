#include <bits/stdc++.h>
using namespace std;

// BFS traversal of graph
void bfs(const vector<vector<int>> &matrix, vector<bool> &visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Traversing all possible connections
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    // Visited List is now filled with current connected components
}

// Function to count the number of connected components (Provinces)
int provincesNum(const vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    int provinces = 0;
    vector<bool> visited(n, false);

    // Iterating through each node to find unvisited components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(isConnected, visited, i);
            provinces++; // Found a new province
        }
    }
    return provinces;
}

int main() {
    // Example test case (Adjacency matrix representation)
    vector<vector<int>> isConnected = {
        {1, 1, 0}, // Node 0 is connected to 1
        {1, 1, 0}, // Node 1 is connected to 0
        {0, 0, 1}  // Node 2 is an isolated province
    };

    int provinces = provincesNum(isConnected);

    // Output the number of connected components
    cout << "Number of Provinces: " << provinces << endl;

    return 0;
}
