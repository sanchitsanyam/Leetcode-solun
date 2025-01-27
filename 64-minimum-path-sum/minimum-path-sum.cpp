class Solution {
public:
    // int help(int i ,int j ,vector<vector<int>>& grid ,vector<vector<int>>&dp){
    //     int m=grid.size(),n=grid[0].size();
    //     if(i>=m|| j>=n)return INT_MAX;
    //     if(i==m-1 && j==n-1){
    //         return grid[i][j];
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     //right;
    //     int s1=INT_MAX, s2=INT_MAX;
    //     if((j+1) < n){
    //       s1=grid[i][j]+help(i ,j+1, grid ,dp);
    //     }    
    //     //down
    //     if((i+1) < m){
    //        s2=grid[i][j]+help(i+1 ,j ,grid ,dp);
    //     } 
    //     return dp[i][j]=min(s1,s2);   
    // }
    int minPathSum(vector<vector<int>>& grid) {
        // int m=grid.size(),n=grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return help(0 ,0 ,grid,dp);
        
        // tabulation
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int s=grid[i][j];
                if(i==0 && j==0){
                    dp[0][0]=s;
                    continue;
                }
                else{
                    int u=1e9 ,l=1e9;//u-up & l-left
                    if(i>0){
                      u=dp[i-1][j];
                    }
                    if(j>0){
                        l=dp[i][j-1];
                    }
                    dp[i][j]=s+min(u ,l);

                }
            }

        }
        return dp[m-1][n-1];
        
    }
};