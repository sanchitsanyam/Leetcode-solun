class Solution {
public:
    bool  help(int i, int j, string s, string p ,vector<vector<int>>& dp){
        if(j==p.size()) return i==s.size();
        if(dp[i][j]!=-1)return dp[i][j];
        bool first_match=(i<s.size() && (s[i]==p[j] || p[j]=='?'));
        if(p[j]=='*'){
            return dp[i][j]=help(i,j+1,s,p,dp)||(i<s.size() && help(i+1,j,s,p,dp));
        }
        return dp[i][j]=first_match && help(i+1,j+1 ,s,p,dp);
    }
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return help(0,0,s,p,dp);
    }
};