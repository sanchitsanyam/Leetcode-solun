class Solution {
// https://youtu.be/C4EistdWzuY?si=8t_FjdIwnLekGmhZ
public:
    int maxLength=0 , minNodes=INT_MAX;
    vector<vector<pair<int,int>>> adj;
    void dfs(int node ,int parent ,int pathSum ,vector<int>& nums,vector<int>& path ,unordered_map<int,int>& depthMap ,int start ,int end){
        int prevdepth=depthMap.count(nums[node])?depthMap[nums[node]]:-1;
        while(start<=prevdepth){
            pathSum-=path[start++];
        }
        if(pathSum>maxLength){
            maxLength=pathSum;
            minNodes=end-start+1;
        }
        if(pathSum==maxLength){
            minNodes=min(minNodes,end-start+1);
        }
        depthMap[nums[node]]=end;
        for(auto& e:adj[node]){
            int u=e.first,w=e.second;
            if(u!=parent){
                path.push_back(w);
                dfs(u,node,pathSum+w,nums, path,depthMap,start,end+1);
                path.pop_back();
            }
        }
        depthMap[nums[node]]=prevdepth;
    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n=nums.size();
        adj.resize(n);
        for(auto& e : edges){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        unordered_map<int,int> depthMap;
        vector<int> path;
        dfs(0,-1,0,nums,path,depthMap,0,0);
        return {maxLength,minNodes};
       
    }
};