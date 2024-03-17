class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minm=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            minm=min(minm,nums[i+1]-nums[i]);
        }
        return minm;
    }
};