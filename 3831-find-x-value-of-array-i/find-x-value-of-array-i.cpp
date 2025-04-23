class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> res(k,0);
        vector<long long> prev(k,0);
        for(int i=0;i<n;i++){
            int x=nums[i];
            int xm=x%k;
            vector<long long> curr(k,0);
            curr[xm]++;
            for(int r=0;r<k;r++){
                if(prev[r]>0){
                    curr[(int)((r*(long long)xm)%k)]+=prev[r];
                }
            }
            for(int r=0;r<k;r++){
                res[r]+=curr[r];
            }
            prev=curr;
        }
        return res;
    }
};