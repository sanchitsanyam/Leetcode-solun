class Solution {
public:
    void combinationSum2helper(int i ,int n,vector<int>& candidates ,vector<vector<int>>& ans, vector<int>curr , int target){
        if(target<0||i>n)return;
        if(target==0){
            ans.push_back(curr);
            return;
            
        }
        for(int j=i; j<n;j++){
            if (j > i && candidates[j] == candidates[j - 1]) continue;
            curr.push_back(candidates[j]);
            combinationSum2helper(j+1 ,n, candidates, ans ,curr, target-candidates[j] );
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> curr;
        combinationSum2helper(0 ,n, candidates, ans ,curr, target );
      
        return ans;

    }
};