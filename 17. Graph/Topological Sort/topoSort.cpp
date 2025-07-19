#include <bits/stdc++.h>
using namespace std;

// Edges -> Adjacency List
vector<vector<int>> createAdj(const vector<vector<int>> &edges, const int V) {
    vector<vector<int>> adj(V);
    for (vector<int> edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }
    return adj;
}

// DFS
void dfs(int start, const vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[start] = true;
    for (int node : adj[start]) {
        if (!visited[node])
            dfs(node, adj, visited, st);
    }
    st.push(start);
}

vector<int> topoSort(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj = createAdj(edges, V);
    stack<int> st;
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }
    vector<int> sorted;
    while (!st.empty()) {
        sorted.push_back(st.top());
        st.pop();
    }
    return sorted;
}
