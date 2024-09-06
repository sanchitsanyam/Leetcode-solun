class Solution {
public:
    bool canReachHelper(vector<int>& arr ,int i,vector<int>&vis){
        int n=vis.size();
        if(i<0 || i>=n)return false;
        if(arr[i]==0)return true;
        if(vis[i]==1)return false;
        vis[i]=1;
        bool opn1=canReachHelper(arr,i+arr[i],vis);
        bool opn2=canReachHelper(arr,i-arr[i],vis);
        return (opn1 || opn2);

    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(),0);
        return canReachHelper(arr , start,vis);
    }    
};