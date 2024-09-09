class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int cnt_bit=(1<<n);
        vector<vector<int>> subsetsa;
        for(int mask=0; mask < cnt_bit ; mask++){
            vector<int> subset;
            for(int i=0;i<n;i++){
                if((mask & (1<<i))!=0){
                    subset.push_back(nums[i]);
                }
            }
            subsetsa.push_back(subset);
            
        }
        return subsetsa;
    }    
};