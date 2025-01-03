class Solution {
public:
    
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>Psum(n+1,0);//Prefix Sum
        for(int i=0;i<n;i++){
            Psum[i+1]=Psum[i]+nums[i];
        }
        vector<long long>MPSum(k,LLONG_MAX);//
        long long maxSum=LLONG_MIN;
        for(int i=0;i<=n;i++){
            int r=i%k;
            if(i>=k){
                maxSum=max(maxSum,Psum[i]-MPSum[r]);
            }
            MPSum[r]=min(MPSum[r],Psum[i]);
        }
       return (maxSum==LLONG_MIN)?0 :maxSum;

       
    }
};