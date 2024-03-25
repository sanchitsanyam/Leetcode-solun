class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int r=n-1;
        int l=0;
        int ans=INT_MAX;
        if(n==1)return nums[0];
        while(l<=r){
            int m=(r+l)/2;
            if(nums[l]<=nums[m]){
                ans=min(nums[l],ans);
                l=m+1;
            }
            else{
               ans=min(nums[m],ans); 
               r=m-1;
            }
        }
        return  ans;
            
           
    }
};