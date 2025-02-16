class Solution {
public:
    int help(int i,int A ,vector<int>& coins , vector<vector<int>>& dp){
        if(i==0){
            if(A%coins[0]==0){
                return A/coins[0];
            }
            else return 1e9;
        }
        if(dp[i][A]!=-1)return dp[i][A];
        int nT= 0+help(i-1,A ,coins ,dp);
        int T=1e9;
        if(A>=coins[i]){
            T=1+help(i,A-coins[i],coins,dp);
        }
        return dp[i][A]=min(T ,nT);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=help(n-1,amount,coins ,dp);
        if(ans==1e9)return -1;
        else return ans;
    }
};