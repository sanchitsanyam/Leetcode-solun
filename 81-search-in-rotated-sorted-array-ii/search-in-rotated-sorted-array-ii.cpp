class Solution {
public:
    bool search(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==k)return true;
            if(nums[m]==nums[l] && nums[m]==nums[r]){
                l=l+1;
                r=r-1;
                continue;
            }
            if(nums[l]<=nums[m]){
                if(nums[l]<=k && k<=nums[m]){
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            else{
                if(nums[m]<=k && k<=nums[r]){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
        }
        return false;
    }
};