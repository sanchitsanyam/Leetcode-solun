class Solution {
public:
    void dfs(int i,vector<int>& vis,vector<vector<int>>& adj){
        vis[i]=1;
        for(auto& t: adj[i]){
            if(!vis[t]){
                dfs(t,vis,adj);
            }
        }
   
    }
    int findCircleNum(vector<vector<int>>& iC) {
        int n=iC.size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(iC[i][j]){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        vector<int> vis(n+1,0);
        int t=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                t++;
            }
        }
        return t;
    }
};