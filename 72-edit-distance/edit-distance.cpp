class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        int dp[m+1][n+1];
        dp[0][0]=0;
        for(int i=1;i<=m;i++)dp[i][0]=i;
        for(int j=1;j<=n;j++)dp[0][j]=j;
        for(int i = 1; i <= m ; i++){
            for(int j = 1; j <= n ; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int topleft=dp[i-1][j-1];
                    int top=dp[i-1][j];
                    int left=dp[i][j-1];
                    dp[i][j]=min(top,min(topleft,left))+1;
                }
            }
        }
        return dp[m][n];
    }
};