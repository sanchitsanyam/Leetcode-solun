class Solution {
public:
    int help(int k,int i,int buy,vector<int>& prices ,vector<vector<vector<int>>>& dp){
        int opn1 ,opn2;
        if(i==prices.size()||k==0)return 0;
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        if(buy==0){
           opn1=-prices[i]+help(k-1,i+1,1,prices,dp);
           opn2=help(k,i+1,0,prices,dp); 
        }
        else{
            opn1=prices[i]+help(k-1,i+1,0,prices,dp);
            opn2=help(k,i+1,1,prices,dp); 
        }
        return dp[i][buy][k]=max(opn1 ,opn2);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(5,-1)));
        return help(4,0,0,prices,dp);// 2 transacion (1 buy and 1 sell in transaction )
    }
};