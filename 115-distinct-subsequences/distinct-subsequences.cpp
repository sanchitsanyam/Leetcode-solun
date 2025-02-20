class Solution {
public:
    //Recursion +Memoization
    // int help(int i ,int j ,string s, string t ,vector<vector<int>>& dp){
    //     int n=s.size();
    //     int m=t.size();
    //     if(i>=n && j<m)return 0;
    //     if(j==m)return 1;
    //     int ans1=0,ans2=0,ans3=0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(s[i]==t[j]){
    //         ans1=help(i+1,j+1,s,t,dp);
    //         ans2=help(i+1,j,s,t,dp);
    //     }
    //     else{
    //         ans3=help(i+1,j,s,t,dp);
    //     }
    //     return dp[i][j]=ans1+ans2+ans3;
    // }
    // int numDistinct(string s, string t) {
    //     int n=s.size();
    //     int m=t.size();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return help(0,0,s,t ,dp);
    // }

    //Tabulation
    // int numDistinct(string s, string t) {
    //     int n=s.size();
    //     int m=t.size();
    //     vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
    //     for(int i=0;i<=n;i++){
    //         dp[i][m]=1;
    //     }
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=m-1;j>=0;j--){
    //             unsigned long long ans1=0 ,ans2=0,ans3=0;
    //             if(s[i]==t[j]){
    //                 ans1=(i+1<=n && j+1<=m)?dp[i+1][j+1]:0;
    //                 ans2=(i+1<=n)?dp[i+1][j]:0;
    //             }
    //             else{
    //                 ans3=(i+1<=n)?dp[i+1][j]:0;
    //             }
    //             dp[i][j]=(ans1+ans2+ans3);
    //         }
    //     }
    //     return dp[0][0];
        
    // }


    //space optimization
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
       vector<unsigned long long> prev(m+1,0);
        for(int i=0;i<=n;i++){
            prev[m]=1;
        }
        for(int i=n-1;i>=0;i--){
            vector<unsigned long long> curr(m+1,0); 
            curr[m]=1;
            for(int j=m-1;j>=0;j--){
                unsigned long long ans1=0 ,ans2=0,ans3=0;
                if(s[i]==t[j]){
                    ans1=(i+1<=n && j+1<=m)?prev[j+1]:0;
                    ans2=(i+1<=n)?prev[j]:0;
                }
                else{
                    ans3=(i+1<=n)?prev[j]:0;
                }
                curr[j]=(ans1+ans2+ans3);
            }
            prev=curr;
        }
        return prev[0];
        
    }
};