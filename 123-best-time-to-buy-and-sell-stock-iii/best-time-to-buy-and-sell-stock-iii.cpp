class Solution {
public:
    //Refuse to give up
    //Recursion + memoization
    // int help(int k,int i,int buy,vector<int>& prices ,vector<vector<vector<int>>>& dp){
    //     int opn1 ,opn2;
    //     if(i==prices.size()||k==0)return 0;
    //     if(dp[i][buy][k]!=-1)return dp[i][buy][k];
    //     if(buy==0){
    //        opn1=-prices[i]+help(k-1,i+1,1,prices,dp);
    //        opn2=help(k,i+1,0,prices,dp); 
    //     }
    //     else{
    //         opn1=prices[i]+help(k-1,i+1,0,prices,dp);
    //         opn2=help(k,i+1,1,prices,dp); 
    //     }
    //     return dp[i][buy][k]=max(opn1 ,opn2);
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(5,-1)));
    //     return help(4,0,0,prices,dp);// 2 transacion (1 buy and 1 sell in transaction )
    // }

    //Tabulation
     int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(5,0)));
        for(int j=0;j<=1;j++){
            for(int k=0;k<5;k++){
                dp[n][j][k]=0;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=1;j++){
                dp[i][j][0]=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<5;k++){
                    int opn1,opn2;
                    if(j==0){
                        opn1=-prices[i]+dp[i+1][1][k-1];
                        opn2=dp[i+1][j][k];
                    }
                    else{
                        opn1=prices[i]+dp[i+1][0][k-1];
                        opn2=dp[i+1][j][k];
                    }
                    dp[i][j][k]=max(opn1,opn2);
                }
            }
        }
        return dp[0][0][4];
    }

};