// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int, vector<pair<int, int>>> graph; // node -> [{node, cost}]
        for (auto &edg : edges) {
            int u = edg[0], v = edg[1], w = edg[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w}); // Undirected graph
        }

        // [cost, node]
        set<pair<int,int>> st;
        vector<int> dist(V, 1e9);

        st.insert({0, src});
        dist[src] = 0;

        while (!st.empty()) {
            auto it = *(st.begin());
            int cur = it.second, curCost = it.first;
            st.erase(it);
            for (auto &nei : graph[cur]) {
                int nextNode = nei.first, nextCost = nei.second;
                int totalCost = nextCost + curCost;
                if (dist[nextNode] > totalCost) {
                    if (dist[nextNode] != 1e9) st.erase({dist[nextNode], nextNode});
                    dist[nextNode] = totalCost;
                    st.insert({totalCost, nextNode});
                }
            }
        }
        return dist;
    }
};