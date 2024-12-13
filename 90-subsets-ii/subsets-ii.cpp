class Solution {
public:
    vector<vector<int>> ans;
    void help(int i ,vector<int> curr,vector<int>& arr ){
        if(i>arr.size())return;
        ans.push_back(curr);
        for(int j=i;j<arr.size();j++){
            if(j!=i && arr[j]==arr[j-1]) continue;
            curr.push_back(arr[j]);
            help(j+1, curr,arr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        help(0,curr,nums);
        return ans;
    }
};