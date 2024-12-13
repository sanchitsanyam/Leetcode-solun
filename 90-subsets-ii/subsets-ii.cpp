class Solution {
public:
    vector<vector<int>> ans;
    void help(int i ,vector<int> curr,vector<int>& arr ){
        if(i==arr.size()){
            ans.push_back(curr);
            return;
        }
        // for(int j=i;j<arr.size();j++){
        //     //if(j!=i && arr[j]==arr[j-1]) continue;
        //     curr.push_back(arr[j]);
        //     help(i+1, curr,arr);
        // }
        curr.push_back(arr[i]);
        help(i+1, curr,arr);
        curr.pop_back();
        help(i+1, curr,arr);

        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        help(0,curr,nums);
        set<vector<int>> m(ans.begin(),ans.end());
        vector<vector<int>> fans(m.begin(),m.end());
        return fans;
    }
};