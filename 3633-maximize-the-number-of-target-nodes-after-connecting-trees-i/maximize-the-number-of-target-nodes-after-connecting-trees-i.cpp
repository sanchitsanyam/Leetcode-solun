class Solution {
public:
    // Function to compute the number of reachable nodes within a given level k
    vector<int> computeReachableNodes(int n, vector<vector<int>>& adj, int k) {
        vector<int> reachable(n, 0);
        for (int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            visited[i] = 1;
            int count = 0;
            queue<pair<int, int>> q;
            q.push({i, 0});
            
            while (!q.empty()) {
                auto [node, level] = q.front();
                q.pop();
                if (level > k) continue;
                count++;
                
                for (int& neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        q.push({neighbor, level + 1});
                        visited[neighbor] = 1;
                    }
                }
            }
            reachable[i] = count;
        }
        return reachable;
    }

    // Function to calculate maximum target nodes considering two graphs
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        
        // Build adjacency list for the first graph
        for (auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        
        // Build adjacency list for the second graph
        for (auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        
        // Calculate reachable nodes for both graphs
        vector<int> reachableGraph1 = computeReachableNodes(n, adj1, k);
        vector<int> reachableGraph2 = computeReachableNodes(m, adj2, k - 1);
        
        // Find the maximum reachable nodes in the second graph
        int maxReachableInGraph2 = INT_MIN;
        for (int nodes : reachableGraph2) {
            maxReachableInGraph2 = max(maxReachableInGraph2, nodes);
        }
        
        // Add maximum reachable nodes of graph2 to each node's count in graph1
        for (int i = 0; i < n; i++) {
            reachableGraph1[i] += maxReachableInGraph2;
        }
        
        return reachableGraph1;
    }
};
