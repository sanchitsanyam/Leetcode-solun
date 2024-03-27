class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //slisding window will not work because elment can be negative.also.
        unordered_map<int,int> preSumCnt;
        preSumCnt[0]=1;
        int n=nums.size();
        int preSum=0,ans=0;
        for(int en=0;en<nums.size();++en){
            preSum+=nums[en];
            ans+=preSumCnt[preSum-k];
           
             int curFreq = preSumCnt[preSum];
            preSumCnt[preSum] = curFreq + 1;
        }
        return ans;
        
    }
};