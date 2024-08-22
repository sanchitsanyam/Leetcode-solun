class Solution {
public:
    int help(int i, int n , vector<int>& dp){
        if(i>n)return dp[i]=0;
        if(i==n)return dp[i]=1;
        if(dp[i]!=-1)return dp[i];
         dp[i]= help(i+1,n,dp)+help(i+2,n,dp);
        return dp[i];
    } 
    int climbStairs(int n) {
        vector<int> dp(1000,-1);
        return help(0,n ,dp);
    }
};