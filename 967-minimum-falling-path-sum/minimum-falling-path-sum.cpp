// class Solution {
// public:
//     int help(int i, int j ,vector<vector<int>>& matrix ,vector<vector<int>>& dp ){
//         int n=matrix.size();
//         if( j<0 || i>=n || j>=n) return 1e9;
//         if(i==n-1){
//             return matrix[i][j];
//         }
//         if(dp[i][j]!=-1)return dp[i][j];
//         int s1=1e9, s2=1e9 ,s3=1e9;
//         s1= matrix[i][j]+help(i+1,j,matrix,dp);
//         s2=matrix[i][j]+help(i+1,j-1,matrix,dp);
//         s3=matrix[i][j]+help(i+1,j+1,matrix,dp);
//         return dp[i][j]=min({s1,s2,s3});


//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int ans=1e9;
//         for(int j=0;j<n;j++){
//             vector<vector<int>> dp(n,vector<int>(n,-1));
//             ans=min(ans, help(0,j,matrix ,dp));
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Initialize the first row of dp with the first row of matrix
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        
        // Fill the dp table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = matrix[i][j] + min({
                    dp[i-1][j],
                    j > 0 ? dp[i-1][j-1] : INT_MAX,
                    j < n-1 ? dp[i-1][j+1] : INT_MAX
                });
            }
        }
        
        // Find the minimum value in the last row of dp
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
