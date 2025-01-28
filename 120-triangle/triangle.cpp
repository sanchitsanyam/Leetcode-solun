class Solution {
public:
    // int help(int i ,int j  ,vector<vector<int>>& triangle ,vector<vector<int>>& dp){
    //     int m = triangle[i].size() ,n=triangle.size();
    //     if(j>=m)return INT_MAX;
    //     if(i==n-1){
    //        return triangle[i][j];
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int s1=1e9 ,s2=1e9;
    //     if(i<n){
    //         s1=triangle[i][j]+help(i+1 ,j ,triangle,dp);
    //         s2=triangle[i][j]+help(i+1, j+1,triangle,dp);
    //     }
    //     return dp[i][j]=min(s1,s2);
        

    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n=triangle.size();
        // vector<vector<int>> dp;
        // for(int i=0;i<n;i++){
        //     int m=triangle[i].size();
        //     dp.push_back(vector<int>(m,-1));
        // }
        // return help(0,0,triangle ,dp);

        //Tabulation
        // int n=triangle.size();
        // vector<vector<int>> dp;
        // for(int i=0;i<n;i++){
        //     int m=triangle[i].size();
        //     dp.push_back(vector<int>(m,1e9));
        // }
        // for(int i=0;i<n;i++){
        //     int m=triangle[i].size();
        //     for(int j=0;j<m;j++){
        //         int s=triangle[i][j];
        //         if(i==0 && j==0){
        //             dp[i][j]=s;
        //             continue;
        //         }
        //         else{
        //             int s1=1e9 ,s2=1e9;
        //             if(j>0){
        //                 s1=dp[i-1][j-1];
        //             }
        //             int m1=triangle[i-1].size();
        //             if(j<m1)s2=dp[i-1][j];
        //             dp[i][j]=s+min(s1,s2);
        //         }
        //     }
        // }
        // int ans=INT_MAX;
        // int m1=triangle[n-1].size();
        // for(int i=0;i<m1;i++){
        //     ans=min(ans,dp[n-1][i]);
        // }
        // return ans;

        //space optimization
        int n=triangle.size();
        vector<int> prev;
        for(int i=0;i<n;i++){
            int m=triangle[i].size();
            vector<int> curr(m);
            for(int j=0;j<m;j++){
                int s=triangle[i][j];
                if(i==0 && j==0){
                    curr[j]=s;
                    continue;
                }
                else{
                    int s1=1e9 ,s2=1e9;
                    if(j>0){
                        s1=prev[j-1];
                    }
                    int m1=triangle[i-1].size();
                    if(j<m1)s2=prev[j];
                    curr[j]=s+min(s1,s2);

                }
            }
            prev.clear();
            prev.resize(m);
            prev=curr;

        }
        int ans=INT_MAX;
        int m1=triangle[n-1].size();
        for(int i=0;i<m1;i++){
            ans=min(ans,prev[i]);
        }
        return ans;
        



    }
};