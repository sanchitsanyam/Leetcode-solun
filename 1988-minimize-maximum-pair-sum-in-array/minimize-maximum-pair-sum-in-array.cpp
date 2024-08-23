class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(); 
        int maxm=INT_MIN;
        for(int i=0;i<n;i++){
            maxm=max(maxm,nums[i]+nums[abs(n-i-1)]);
        }
        return maxm;
    }
};