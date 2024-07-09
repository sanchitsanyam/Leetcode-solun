class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(target>=nums[0] && nums[m]< nums[0]){
                // target in 1st part and we in 2nd part
                r=m-1;
            }
            else if(target<nums[0] && nums[m]>= nums[0]){
                // target in 2nd  part and we in Ist part
                l=m+1;
            }
            else{
                if(nums[m]==target){
                    return m;
                }
                else if(nums[m]>target){
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
        }
        return -1;
    }
};