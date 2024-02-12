class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1,min_till_now=INT_MAX;
        for(int j=0;j<nums.size();j++){
            if(nums[j]>min_till_now){
                ans=max(ans,nums[j]-min_till_now);
            }
            min_till_now=min(min_till_now,nums[j]);
        }
        return ans;
        
    }
};