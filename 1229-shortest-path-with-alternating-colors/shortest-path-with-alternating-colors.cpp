class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        // 0 for redEdges
        for(auto& k:redEdges){
            int u=k[0],v=k[1];
            adj[u].push_back({v,0});
        }
        for(auto& k:blueEdges){
            int u=k[0],v=k[1];
            adj[u].push_back({v,1});
        }
        queue<pair<int,int>> q;
        vector<vector<int>> ans(n,vector<int>(2,-1));
        ans[0][1]=0;
        ans[0][0]=0;
        q.push({0,0});
        q.push({0,1});
        while(!q.empty()){
            auto l=q.front();
            int u=l.first, c=l.second;
            q.pop();
            for(auto& k:adj[u]){
                int v=k.first,c1=k.second;
                if(ans[v][c1]==-1 && c1!=c ){
                   ans[v][c1]=ans[u][c]+1;
                   q.push({v,c1});
                }
                else if(1+ans[u][c]<=ans[v][c1] && c1!=c){
                    ans[v][c1]=ans[u][c]+1;
                    q.push({v,c1});
                }
            }
        }
        vector<int> A(n,-1);
        for(int i=0;i<n;i++){
            if(ans[i][0]==-1)A[i]=ans[i][1];
            else if(ans[i][1]==-1)A[i]=ans[i][0];
            else A[i]=min(ans[i][0],ans[i][1]);
        }
        return A;
    }
};