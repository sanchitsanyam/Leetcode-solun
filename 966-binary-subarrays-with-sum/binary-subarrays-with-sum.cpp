class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int gl) {
        return atmostSum(nums,gl)-atmostSum(nums,gl-1);
    }
private:
    int atmostSum(vector<int>& nums,int gl){
        int n=nums.size();
        int s=0;//s-> start
        int e=0;//e-> end
        int sum=0;
        int ans=0;
        while(e<n){
            sum +=nums[e];
            while(  s<=e && sum>gl ){
                sum -=nums[s];
                s++;
            }
            ans+=e-s+1;
            e++;
        }
        return ans;
    }    
};