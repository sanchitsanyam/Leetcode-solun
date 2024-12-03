class Solution {
public:
    vector<int> tonlev(int n ,vector<vector<int>>&adj , int k){
        vector<int> reachable(n,0);
        for(int i=0 ; i<n; i++){
            vector<int> vis(n,0);
            vis[i]=1;
            int c=0;
            queue<pair<int,int>> q;
            q.push({i,0});
            while(!q.empty()){
                auto [u,level]=q.front();
                q.pop();
                if(level>k)continue;
                c++;
                for(int&  v:adj[u]){
                    if(!vis[v]){
                       q.push({v,level+1});
                       vis[v]=1; 
                    }
                }
            }
            reachable[i] = c;
        }
        return reachable;


    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<vector<int>> adj1(n) ,adj2(m);
        for(auto & u:edges1){
            adj1[u[0]].push_back(u[1]);
            adj1[u[1]].push_back(u[0]);
        }
        for(auto & u:edges2){
            adj2[u[0]].push_back(u[1]);
            adj2[u[1]].push_back(u[0]);
        }
        
        vector<int> ans= tonlev(n ,adj1 , k);
        vector<int> mk=tonlev(m ,adj2 ,k-1);
        int maxm=INT_MIN;
        for(int i=0;i<mk.size();i++){
            maxm=max(maxm,mk[i]);
        }
        for(int i=0;i<n;i++){
            ans[i]+=maxm;
        }
        return ans;
    }
};