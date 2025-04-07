class Solution {
public:
    int f(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        long long step=0;
        for(int k=i;k<=j;k++){
            long long t=nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
            step=max(step,t);
        }
        return dp[i][j]=step;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size()-2;
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return f(1,n,nums ,dp);
    }
};