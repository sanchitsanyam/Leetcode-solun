class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int max=INT_MIN;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        if(max < sum){
            max=sum;
        }
        int n=nums.size();
        for(int i=1;i<=n-k;i++){
            sum=sum-nums[i-1]+nums[k-1+i];
            if(max<sum){
               max=sum;
            }
        }

        return double(max)/double(k);
        
    }
};