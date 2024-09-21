class Solution {
public:
    int dfs(int i, const string& s, vector<int>&dp) {
        if(i>s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        if(s[i] == '0')return 0;
        
        int res=dfs(i+1 , s, dp);
        if(i+1<s.length() && (s[i]=='1'||(s[i]=='2' && s[i+1]<='6'))){
            res+=dfs(i+2 , s , dp);
        }
        dp[i]=res;
        return res;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        dp[n]=1;
        return dfs(0 , s , dp);

    }
};