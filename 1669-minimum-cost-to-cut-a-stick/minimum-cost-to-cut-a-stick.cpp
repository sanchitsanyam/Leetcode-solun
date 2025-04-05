class Solution {
public:
    //Recursive Approach + Memoization
    // int f(int i ,int j,vector<int>& cuts ,vector<vector<int>>&dp){
    //     if(i+1==j)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     long long step=LLONG_MAX;
    //     for(int k=i+1;k<j;k++){
    //         long long t=cuts[j]-cuts[i]+f(i,k,cuts,dp)+f(k,j,cuts,dp);
    //         step=min(step,t);
    //     }
    //     return dp[i][j]=step;
    // }
    // int minCost(int n, vector<int>& cuts) {
    //     cuts.push_back(n);
    //     cuts.push_back(0);
    //     sort(cuts.begin(),cuts.end());
    //     int m=cuts.size();
    //     vector<vector<int>> dp(m,vector<int>(m,-1));
    //     return f(0,m-1,cuts ,dp);
    // }
    
    //Tabulation
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        // Fill DP table for intervals of increasing length
        for (int l = 2; l < m; l++) { // l = j-i
            for (int i = 0; i + l < m; i++) {
                int j = i + l;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][m-1];
    }

};

