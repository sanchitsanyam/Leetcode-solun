// class Solution {
// public:
//     int solve(int i,int j,vector<int>& values, vector<vector<int>>& dp){
//         if((j-i)<2)return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         int fans=INT_MAX;
//         for(int k=i+1;k<j;k++){
//             int left=solve(i,k,values,dp);
//             int right=solve(k,j,values,dp);
//             int ans=left+right+1LL*values[i]*values[k]*values[j];
//             fans=min(fans,ans);
//         }
//         return dp[i][j]=fans;
//     }
//     int minScoreTriangulation(vector<int>& values) {
//         int n=values.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         return solve(0,n-1,values,dp);
//     }
// };
class Solution {
public:
    
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){
                int x=INT_MAX;
                for(int k=i+1;k<j;k++){
                    int left=dp[i][k];
                    int right=dp[k][j];
                    int r=left+right+1LL*values[i]*values[k]*values[j];
                    x=min(x,r);
                }
                dp[i][j]=x;
            }
        }
        return dp[0][n-1];
    }
};