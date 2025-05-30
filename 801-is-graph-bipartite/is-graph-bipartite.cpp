class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int> q;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    auto u=q.front();
                    q.pop();
                    for(auto& v:graph[u]){
                        if(vis[v]){
                        if(vis[v]==vis[u])return false;
                        }
                        else{
                            int d=(vis[u]==1)?2:1;
                            vis[v]=d;
                            q.push(v);
                        }
                    }

                }
            }    
        }    
        return true;

    }
};