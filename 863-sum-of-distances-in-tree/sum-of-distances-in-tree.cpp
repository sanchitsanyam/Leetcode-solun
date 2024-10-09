class Solution {
public:
    long root_result=0;
    vector<int> count;
    int N;
    int dfsBase(unordered_map<int,vector<int>>& adj, int curr ,int par ,int curr_dep){
        int total_nodes=1;
        root_result+=curr_dep;
        for(auto nb: adj[curr]){
            if(nb==par)continue;
           
            total_nodes+=dfsBase(adj,nb,curr,curr_dep+1);
        }
        count[curr]=total_nodes;
        return total_nodes;
    }
    void DFS(unordered_map<int,vector<int>>& adj, int curr ,int par ,vector<int>&result){
       
        for(auto nb: adj[curr]){
            if(nb==par)continue;
            result[nb]=result[curr]-count[nb]+(N-count[nb]);
            DFS(adj,nb,curr,result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        unordered_map<int ,vector<int>> adj;
        N=n;
        count.resize(n,0);
        for(auto &vec: edges){
            int u=vec[0];
            int v=vec[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        root_result=0;
        dfsBase(adj,0 ,-1 ,0);
        vector<int> result(n,0);
        result[0]=root_result;
        DFS(adj,0 ,-1, result);
        return result;
        

        
    }
};