class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixSum(n);
        vector<int> suffixSum(n);
        vector<int> ans;
        prefixSum[0]=nums[0];
        suffixSum[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suffixSum[i]=suffixSum[i+1]+nums[i];
        }
        for(int i=0;i<n;i++){
            int res=abs(suffixSum[i]-nums[i]*(n-i))+abs(prefixSum[i]-nums[i]*(i+1));
            ans.push_back(res);
        }
        return ans;
    }
};