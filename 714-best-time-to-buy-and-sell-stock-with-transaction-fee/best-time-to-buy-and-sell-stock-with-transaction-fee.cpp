class Solution {
public:
    int help(int i ,int buy, int f,vector<int>& prices,vector<vector<int>>& dp){
        if(i==prices.size())return 0;
        int opn1,opn2;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy==0){
            opn1=-prices[i]-f+help(i+1,1,f,prices,dp);
            opn2=help(i+1,0,f,prices,dp);
        }
        else{
            opn1=prices[i]+help(i+1,0,f,prices,dp);
            opn2=help(i+1,1,f,prices,dp);
        }
        return dp[i][buy]=max(opn1,opn2);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return help(0,0,fee,prices,dp);
    }
};