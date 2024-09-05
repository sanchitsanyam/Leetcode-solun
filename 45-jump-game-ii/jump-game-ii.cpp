class Solution {
public:
    int  jumpHelper(vector<int>& nums, int i ,vector<int>& dp){
        if(i>=nums.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX-1;
        for(int j=1;j<=nums[i];j++){
           ans=min(ans,1+jumpHelper(nums,i+j,dp));
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return jumpHelper(nums,0, dp);
    }
};