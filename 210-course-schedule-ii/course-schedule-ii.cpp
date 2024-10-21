class Solution {
    int n;
    vector<vector<int>> adj;
    bool DFS(int cur, vector<int>& vis, vector<int>& topo){
        vis[cur] = 1;// recursion in progress
        for(auto ngb:adj[cur]){
            if(!vis[ngb]){
                bool can =DFS(ngb,vis,topo);
                if(!can)return false;
            }
            if(vis[ngb]==1)return false;// backward edge
            // nothing done for vis =2
        }
        vis[cur] = 2;
        topo.push_back(cur);
        return true;
    }

    vector<int> TopoUsingDFS(){
        vector<int> ans ,vis(n);
        for(int i = 0; i < n ; i++){
            if(!vis[i]){
                bool can=DFS(i,vis,ans);
                if(!can){
                    ans={};
                    break;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        adj.resize(n);
        for(vector<int> v:prerequisites)
            adj[v[1]].push_back(v[0]);
        vector<int> ans = TopoUsingDFS();
        return ans;   
    }
};