class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++){
           s=s^nums[i];
        }
        return s;
    }
};