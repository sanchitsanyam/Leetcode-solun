class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n,0);
        int k=1;
        for(int i=0;i<(n/2);i++){
            ans[i]=k;
            ans[n-i-1]=-k;
            k++;
        }
        return ans;
    }
};