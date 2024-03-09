class Solution {
public:
    void recursion(int i,int n,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        recursion(i+1,n,nums,temp,ans);
        temp.push_back(nums[i]);
        recursion(i+1,n,nums,temp,ans);
        temp.pop_back();
    }
        
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        vector<vector<int>>ans;
        recursion(0,n,nums,temp,ans);
        return ans;
        
    }
};