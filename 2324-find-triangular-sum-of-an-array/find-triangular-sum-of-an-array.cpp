class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            vector<int> A(n-i,0);
            for(int j=0;j<A.size();j++){
                A[j]=(nums[j]+nums[j+1])%10;
            }
            nums=A;
        }
        return nums[0];
    }
};