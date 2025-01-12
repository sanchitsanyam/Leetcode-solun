class Solution {
public:
    int n,m;
    vector<vector<vector<int>>> dp;
    int solve(int i , int j, vector<vector<int>>& coins ,int k ){
        if(i==n || j==m)return -1000000;
        if(i==n-1 && j==m-1){
            return (coins[i][j]<0 && k>0)?0:coins[i][j];
        }
        if(dp[i][j][k]!=-1000000){
            return dp[i][j][k];
        }
        int right=-1000000,down=-1000000;
        if(coins[i][j]<0){
            if(k>0){
                right=solve(i,j+1,coins,k-1);
                down=solve(i+1,j,coins,k-1);
            }
            right=max(right,solve(i,j+1,coins,k)+coins[i][j]);
            down=max(down,solve(i+1,j,coins,k)+coins[i][j]);
        }
        else{
            right=max(right,solve(i,j+1,coins,k)+coins[i][j]);
            down=max(down,solve(i+1,j,coins,k)+coins[i][j]);
        }
        dp[i][j][k]=max(right ,down);
        return dp[i][j][k];

    }
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(3,-1000000)));
        return solve(0,0,coins,2);
        
    }
};