#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> createAdj(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V); // Adjacency List
    for (vector<int> edg : edges) {
        adj[edg[0]].push_back(edg[1]);
        adj[edg[1]].push_back(edg[0]);
    }
    return adj;
}

bool checkLoopBFS(int start, vector<vector<int>> &adj, vector<bool> &visited) {
    queue<pair<int, int>> q; // {Node, parent}
    q.push({start, -1});
    visited[start] = true;

    while (!q.empty()) {
        int currNode = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int nei : adj[currNode]) {
            if (!visited[nei]) {
                visited[nei] = true;
                q.push({nei, currNode});
            } else if (nei != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj = createAdj(V, edges); // Adjacency List
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i] && checkLoopBFS(i, adj, visited))
            return true;
    }
    return false;
}
