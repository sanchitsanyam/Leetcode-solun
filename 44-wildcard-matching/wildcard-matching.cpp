class Solution {
public:
    //Recursion + Memoization
    // bool  help(int i, int j, string s, string p ,vector<vector<int>>& dp){
    //     if(j==p.size()) return i==s.size();
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     bool first_match=(i<s.size() && (s[i]==p[j] || p[j]=='?'));
    //     if(p[j]=='*'){
    //         return dp[i][j]=help(i,j+1,s,p,dp)||(i<s.size() && help(i+1,j,s,p,dp));
    //     }
    //     return dp[i][j]=first_match && help(i+1,j+1 ,s,p,dp);
    // }
    // bool isMatch(string s, string p) {
    //     int m=s.size(),n=p.size();
    //     vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    //     return help(0,0,s,p,dp);
    // }

    // Tabulation
    // bool isMatch(string s, string p) {
    //     int m=s.size(),n=p.size();
    //     vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    //     dp[m][n]=1;
    //     for(int j=n-1;j>=0;j--){
    //         if(p[j]!='*')break;
    //         dp[m][j]=true;
    //     }
    //     for(int i=m-1;i>=0;i--){
    //         for(int j=n-1;j>=0;j--){
    //             bool first_match=(s[i]==p[j] || p[j]=='?');
    //             if(p[j]=='*'){
    //                 dp[i][j]= dp[i][j+1] || dp[i+1][j];
    //             }
    //             else dp[i][j]= first_match && dp[i+1][j+1];
    //         }
    //     }
    //     return dp[0][0];
    // }

    // Space Optimization
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<bool> prev(n+1,false);
        prev[n]=1;
        for(int j=n-1;j>=0;j--){
            if(p[j]!='*')break;
            prev[j]=true;
        }
        for(int i=m-1;i>=0;i--){
            vector<bool> curr(n+1,false);
            for(int j=n-1;j>=0;j--){
                bool first_match=(s[i]==p[j] || p[j]=='?');
                if(p[j]=='*'){
                    curr[j]= curr[j+1] || prev[j];
                }
                else curr[j]= first_match && prev[j+1];
            }
            prev=curr;
        }
        return prev[0];
    }
};