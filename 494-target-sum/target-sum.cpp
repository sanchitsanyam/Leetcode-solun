class Solution {
public:
// Recursion +Memoization
    // int help(int i,int Csum,vector<int>& arr, int target,vector<vector<int>>& dp){
    //     int n=arr.size();
    //     if(i==n){
    //         if(Csum==target)return 1;
    //         else return 0;
    //     }
    //     if(dp[i][Csum+1000]!=-1)return dp[i][Csum+1000];
    //     int ans1=help(i+1,Csum-arr[i],arr,target,dp);
    //     int ans2=help(i+1,Csum+arr[i],arr,target,dp);
    //     return dp[i][Csum+1000]=ans1+ans2;
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n,vector<int>(2001,-1));
    //     return help(0,0,nums,target,dp);
    // }


    // recursion another Way
    int help(int i, int Csum , vector<int>& nums, int target){
        int n=nums.size();
        if(i==n){
            if(Csum==target)return 1;
            else return 0;
        }
        int  nT=help(i+1,Csum,nums,target);
        int  T=help(i+1,Csum+nums[i],nums,target);
        return nT+T;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int Sum=accumulate(nums.begin(),nums.end(),0);
        int k=(target+Sum);
        if(k%2!=0)return 0;
        else k=k/2;
        return help(0,0,nums,k);
        // vector<vector<int>> dp(n,vector<int>(2001,-1));
        // return help(0,0,nums,target,dp);
    }
    
};