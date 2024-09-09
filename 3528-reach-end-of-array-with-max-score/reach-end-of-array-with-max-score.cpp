class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        vector<long long> x;
        long long n=nums.size();
        x.push_back(0);
        long long t=nums[0];
        for(long long i=1 ; i<n-1 ; i++){
            if(t <= nums[i]){
                x.push_back(i);
                t=nums[i];
            }
        }
        x.push_back(n-1);
        long long m= x.size();
        long long sum=0;
        for(long long i=0;i<m-1;i++){
            sum+=nums[x[i]]*(x[i+1]-x[i]);
        }
        return sum;
    }
};