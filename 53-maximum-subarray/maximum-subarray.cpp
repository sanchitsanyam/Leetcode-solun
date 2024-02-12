class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum=0,final_ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cur_sum+=nums[i];
            final_ans=max(final_ans,cur_sum);
            if(cur_sum<0){
               cur_sum=0;
            }
        }
        return final_ans;    
    }
};