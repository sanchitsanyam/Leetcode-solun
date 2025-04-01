class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int res=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                        cnt[i]=cnt[j];
                    }
                    else if(dp[i]==1+dp[j]){
                        cnt[i]+=cnt[j];
                    }
                }
            }
            res=max(res,dp[i]);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(dp[i]==res){
               c+=cnt[i];
            }
        }
        return c;
    }
};