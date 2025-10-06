class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(auto & k:pre){
            int u=k[0];
            int v=k[1];
            adj[u].push_back(v);
            ind[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0)q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto& v: adj[u]){
                ind[v]--;
                if(ind[v]==0){
                    q.push(v);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ind[i])return false;
        }
        return true;
    }
};