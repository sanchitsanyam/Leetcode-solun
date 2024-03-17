class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            sort(nums[i].begin(),nums[i].end());
        }
        int m=nums[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            int max=INT_MIN;
            for(int j=0;j<n;j++){
                if(max<nums[j][i]){
                    max=nums[j][i];
                }
            }
            ans+=max;
        }
        return ans;
    }
};