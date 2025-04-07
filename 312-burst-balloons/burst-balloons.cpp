class Solution {
public:
    //Recursive +memoization
    // int f(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
    //     if(i>j)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     long long step=0;
    //     for(int k=i;k<=j;k++){
    //         long long t=nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
    //         step=max(step,t);
    //     }
    //     return dp[i][j]=step;
    // }
    // int maxCoins(vector<int>& nums) {
    //     nums.insert(nums.begin(),1);
    //     nums.push_back(1);
    //     int n=nums.size()-2;
    //     vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
    //     return f(1,n,nums ,dp);
    // }

    //tabulation
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size()-2;
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=n+1;j++){
                if(i>j)dp[i][j]=0;
            }
        }

        for(int l=0;l<=n;l++){
            for(int i=1;i+l<=n;i++){
                int j=i+l;
                long long step=0;
                for(int k=i;k<=j;k++){
                    long long t=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                    step=max(step,t);
                }
                dp[i][j]=step;
            }
        }
        return dp[1][n];
    }

    
};