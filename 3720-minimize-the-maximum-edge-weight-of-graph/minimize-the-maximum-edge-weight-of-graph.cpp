class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    int dfs(int node , int m ,vector<int>& vis){
        int res=vis[node]=1;
        for(auto& p : adj[node]){
            if(p.first <=m  && !vis[p.second]){
                res+=dfs(p.second,m ,vis);                                                
            } 
        }
        return res;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        adj.resize(n);
        for(auto& e: edges){
            adj[e[1]].push_back({e[2],e[0]});
        }
        int l=1,r=1000001;
        while(l<r){
            int m=(l+r)/2;
            if(vector<int> vis(n,0); dfs(0,m, vis)==n){
                r=m;
            }
            else l=m+1;
        }
        return (l==1000001)?-1:l;
        
    }
};