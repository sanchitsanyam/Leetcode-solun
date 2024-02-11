class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> g1;
        int n;
        for(int i=0;i<nums.size();i++){
            n=int(pow(nums[i],2));
            g1.push_back(n);
        }
        sort(g1.begin(),g1.end());
        return g1;
        
    }
};