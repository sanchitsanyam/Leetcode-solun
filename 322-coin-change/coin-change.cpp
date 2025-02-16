class Solution {
public:
    //Recursion + Memoization
    // int help(int i,int A ,vector<int>& coins , vector<vector<int>>& dp){
    //     if(i==0){
    //         if(A%coins[0]==0){
    //             return A/coins[0];
    //         }
    //         else return 1e9;
    //     }
    //     if(dp[i][A]!=-1)return dp[i][A];
    //     int nT= 0+help(i-1,A ,coins ,dp);
    //     int T=1e9;
    //     if(A>=coins[i]){
    //         T=1+help(i,A-coins[i],coins,dp);
    //     }
    //     return dp[i][A]=min(T ,nT);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n=coins.size();
    //     vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    //     int ans=help(n-1,amount,coins ,dp);
    //     if(ans==1e9)return -1;
    //     else return ans;
    // }

    //Tabulation
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int A=0;A<=amount;A++){
            if(A%coins[0]==0){
                dp[0][A]=A/coins[0];
            }
            else{
                dp[0][A]=1e9;
            }
        }
        for(int i=1;i<n;i++){
            for(int A=0;A<=amount;A++){
                int nT=0+dp[i-1][A];
                int T=1e9;
                if(A>=coins[i]){
                    T=1+dp[i][A-coins[i]];
                }
                dp[i][A]=min(T,nT);
            }
            
        }
        int ans= dp[n-1][amount];
        if(ans==1e9)return -1;
        else return ans;
        
    }
};