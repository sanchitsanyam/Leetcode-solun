class Solution {
public:
    bool canJumpHelper(vector<int>& nums,int i, vector<int>& dp){
        if(i>=nums.size()-1)return dp[i]=true;
        if(dp[i]!=-1)return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(canJumpHelper(nums ,i+j ,dp))return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return canJumpHelper(nums,0 , dp);
    }
};