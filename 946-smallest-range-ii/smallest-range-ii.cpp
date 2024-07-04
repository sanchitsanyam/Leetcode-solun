class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int min_score=INT_MAX;
        for(int i=0;i<n;i++){
            min_score=min(min_score,max(nums[(i-1)>=0?i-1:0]+k, nums[n-1]-k)-min(nums[0]+k,nums[i]-k));
            min_score=min(min_score, nums[n-1]-nums[0]);
        }
        return min_score;
    }
};