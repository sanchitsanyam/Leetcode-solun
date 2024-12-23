class Solution {
public:
    vector<vector<int>> ans;
    void help(vector<int>& curr, int i , int target ,int k){
        if(target<0 || curr.size()>k)return;
        if(target==0 && curr.size()==k){
            ans.push_back(curr);
            return;
        }
        for(int j=i;j<=9;j++){
            // if(target<i)break;
            curr.push_back(j);
            help(curr ,j+1, target-j ,k);
            curr.pop_back();
        }
    } 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        help(curr ,1, n , k);
        return ans;
    }
};