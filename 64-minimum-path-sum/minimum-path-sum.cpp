class Solution {
public:
    int help(int i ,int j ,vector<vector<int>>& grid ,vector<vector<int>>&dp){
        int m=grid.size(),n=grid[0].size();
        if(i>=m|| j>=n)return INT_MAX;
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        //right;
        int s1=INT_MAX, s2=INT_MAX;
        if((j+1) < n){
          s1=grid[i][j]+help(i ,j+1, grid ,dp);
        }    
        //down
        if((i+1) < m){
           s2=grid[i][j]+help(i+1 ,j ,grid ,dp);
        } 
        return dp[i][j]=min(s1,s2);   
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return help(0 ,0 ,grid,dp);
        
    }
};