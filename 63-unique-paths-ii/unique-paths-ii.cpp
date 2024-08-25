class Solution {
public:
    int helper(int i ,int j ,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid ,int m , int n ){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        //down;
        int left=0, right=0;
        if(obstacleGrid[i][j]!=1){
           left = helper( i+1 ,j , dp,obstacleGrid ,m ,  n );
        }   
        //right
        if(obstacleGrid[i][j]!=1){
           right=helper( i ,j+1 , dp,obstacleGrid ,m ,  n );
        } 
        return dp[i][j]=right+left;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n= obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1)return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return helper(0,0,dp, obstacleGrid, m,n);
        
    }
};