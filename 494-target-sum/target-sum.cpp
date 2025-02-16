class Solution {
public:
    int help(int i,int Csum,vector<int>& arr, int target,vector<vector<int>>& dp){
        int n=arr.size();
        if(i==n){
            if(Csum==target)return 1;
            else return 0;
        }
        if(dp[i][Csum+1000]!=-1)return dp[i][Csum+1000];
        int ans1=help(i+1,Csum-arr[i],arr,target,dp);
        int ans2=help(i+1,Csum+arr[i],arr,target,dp);
        return dp[i][Csum+1000]=ans1+ans2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(20001,-1));
        return help(0,0,nums,target,dp);
    }
};