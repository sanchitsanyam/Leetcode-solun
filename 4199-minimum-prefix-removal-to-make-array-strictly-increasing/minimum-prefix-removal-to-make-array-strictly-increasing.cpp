class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                s++;
            }
            else{
                break;
            }
        }
        if(s==n-1 )return n-s-1;
        return max(n-s-1,1);
    }
};