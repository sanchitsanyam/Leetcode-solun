class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int maxm=INT_MIN;
        int minm=INT_MAX;
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxm=nums[i];
            minm=nums[i];
            for(int j=i;j<n;j++){
                maxm=max(nums[j],maxm);
                minm=min(nums[j],minm);
                sum+=maxm-minm;
            }
        }
        return sum;
    }
};