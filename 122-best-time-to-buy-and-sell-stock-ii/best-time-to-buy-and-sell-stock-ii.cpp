class Solution {
public:
    
    int p(int i ,bool buy ,vector<int>& prices,vector<vector<int>>& dp ){
        if(i==prices.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy)
           dp[i][buy]= max((-prices[i]+p(i+1,0,prices,dp)),(p(i+1,1,prices,dp)));
        else
           dp[i][buy]= max((prices[i]+p(i+1,1,prices,dp)),(p(i+1,0,prices,dp)));
        return dp[i][buy];   
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return p(0,1,prices ,dp);
    }
};