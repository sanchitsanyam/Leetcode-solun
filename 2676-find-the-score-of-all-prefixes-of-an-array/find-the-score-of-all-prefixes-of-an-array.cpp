class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> prefix_max;
        long long max=nums[0];
        long long n=nums.size();
        for(int i=0;i<n;i++){
            if(max<=nums[i]){
                max=nums[i];
            }
            prefix_max.push_back(max);
        }
        for(int i=0;i<n;i++){
            nums[i]=nums[i]+prefix_max[i];
        }
        vector<long long> prefix_sum;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum +=nums[i];
            prefix_sum.push_back(sum);
        }
        return prefix_sum;

    }
};