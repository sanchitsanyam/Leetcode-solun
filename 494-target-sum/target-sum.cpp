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


    // recursion + Memoization another Way
    // int help(int i, int Csum , vector<int>& nums, int target,vector<vector<int>>& dp){
    //     int n=nums.size();
    //     if(Csum>target)return 0;
    //     if(i==n){
    //         if(Csum==target)return 1;
    //         else return 0;
    //     }
    //     if(dp[i][Csum]!=-1)return dp[i][Csum];
    //     int  nT=help(i+1,Csum,nums,target,dp);
    //     int  T=help(i+1,Csum+nums[i],nums,target,dp);
    //     return dp[i][Csum]=nT+T;
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     int Sum=accumulate(nums.begin(),nums.end(),0);
    //     int k=(target+Sum);
    //     if(abs(target)>Sum)return 0;
    //     if(k%2!=0)return 0;
    //     else k=k/2;
    //     if(k<0)return 0;
    //     vector<vector<int>> dp(n,vector<int>(k+1,-1));
    //     return help(0,0,nums,k,dp);   
    // }

    //Tabulation
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     int Sum=accumulate(nums.begin(),nums.end(),0);
    //     int k=(target+Sum);
    //     if(abs(target)>Sum)return 0;
    //     if(k%2!=0)return 0;
    //     else k=k/2;
    //     if(k<0)return 0;
    //     vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    //     dp[n][k]=1;
    //     for(int i=n-1;i>=0;i--){
    //         for(int t=0;t<=k;t++){
    //             int nt=dp[i+1][t];
    //             int T=0;
    //             if(t+nums[i]<=k){
    //                 T=dp[i+1][t+nums[i]];
    //             }
    //             dp[i][t]=nt+T;
    //         }
    //     }
    //     return dp[0][0]; 
    // }
    

    /// space optimization
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int Sum=accumulate(nums.begin(),nums.end(),0);
        int k=(target+Sum);
        if(abs(target)>Sum)return 0;
        if(k%2!=0)return 0;
        else k=k/2;
        if(k<0)return 0;
        vector<int> prev(k+1,0);
        prev[k]=1;
        for(int i=n-1;i>=0;i--){
            vector<int> curr(k+1,0);
            for(int t=0;t<=k;t++){
                int nt=prev[t];
                int T=0;
                if(t+nums[i]<=k){
                    T=prev[t+nums[i]];
                }
                curr[t]=nt+T;
            }
            prev=curr;
        }
        return prev[0]; 
    }
    
    
};