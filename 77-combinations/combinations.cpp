class Solution {
public:
    void combineHelper(int n , int i, int k, vector<int>& cur ,vector<vector<int>>& ans){
        if(cur.size()==k){
            ans.push_back(cur);
            return;
        }
        for(int j=i+1 ; j<=n ; j++){
            cur.push_back(j);
            combineHelper( n, j,  k,  cur , ans);
            cur.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        combineHelper( n, 0,  k,  cur , ans);
        return ans;
    }
};