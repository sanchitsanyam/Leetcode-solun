#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges) {

        // adj[u] -> {v, color} where color: 0 = red, 1 = blue
        vector<vector<pair<int,int>>> adj(n);
        for (auto& e : redEdges) adj[e[0]].push_back({e[1], 0});
        for (auto& e : blueEdges) adj[e[0]].push_back({e[1], 1});

        const int INF = 1e9;
        // dist[node][color]: shortest distance to node ending with 'color'
        vector<vector<int>> dist(n, vector<int>(2, INF));
        queue<pair<int,int>> q;

        // Start at 0 with both “virtual” last colors
        dist[0][0] = 0;
        dist[0][1] = 0;
        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            auto [u, last] = q.front(); q.pop();
            for (auto &[v, col] : adj[u]) {
                if (col == last) continue;                 // must alternate
                if (dist[v][col] > dist[u][last] + 1) {
                    dist[v][col] = dist[u][last] + 1;
                    q.push({v, col});
                }
            }
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            int best = min(dist[i][0], dist[i][1]);
            if (best != INF) ans[i] = best;
        }
        return ans;
    }
};
