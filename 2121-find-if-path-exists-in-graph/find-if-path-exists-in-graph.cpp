class Solution {
public:
    void dfs(int cur , vector<vector<int>>& adj ,vector<bool>& vis){
        if(vis[cur])return;
        vis[cur]=true;
        for(int nb:adj[cur]){
            if(vis[nb])continue;
            dfs(nb , adj ,vis);
            
        }
         

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        
        dfs(source,adj,vis);
        return vis[destination];
    }
};