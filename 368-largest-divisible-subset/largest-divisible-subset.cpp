class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n);
        int maxlen=0;
        int l_in=0;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                    if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                        dp[i]=1+dp[j];
                        hash[i]=j;
                    }
            } 
            if(maxlen<dp[i]){
                maxlen=dp[i];
                l_in=i;
            }

        }
        vector<int> ans;
        int j=l_in;
        ans.push_back(nums[j]);
        while(hash[j]!=j){
            j=hash[j];
            ans.push_back(nums[j]);
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};