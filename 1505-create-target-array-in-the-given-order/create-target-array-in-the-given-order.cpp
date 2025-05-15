class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=index.size();
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(index[j]>=index[i])index[j]++;
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[index[i]]=nums[i];
        }
        return ans;
    }
};