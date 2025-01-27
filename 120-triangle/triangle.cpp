class Solution {
public:
    int help(int i ,int j  ,vector<vector<int>>& triangle ,vector<vector<int>>& dp){
        int m = triangle[i].size() ,n=triangle.size();
        if(j>=m)return INT_MAX;
        if(i==n-1){
           return triangle[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int s1=1e9 ,s2=1e9;
        if(i<n){
            s1=triangle[i][j]+help(i+1 ,j ,triangle,dp);
            s2=triangle[i][j]+help(i+1, j+1,triangle,dp);
        }
        return dp[i][j]=min(s1,s2);
        

    }
    int minimumTotal(vector<vector<int>>& triangle) {
         int n=triangle.size();
        vector<vector<int>> dp;
        for(int i=0;i<n;i++){
            int m=triangle[i].size();
            dp.push_back(vector<int>(m,-1));
        }
        return help(0,0,triangle ,dp);
    }
};