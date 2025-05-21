class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        vector<int> P(n);
        for(auto& t : q){
            int l=t[0];
            int r=t[1];
            P[l]+=-1;
            if((r+1)<n)P[r+1]+=1;
        }
        vector<int> Ps(n);
        Ps[0]=P[0];
        for(int i=1;i<n;i++){
            Ps[i]=P[i]+Ps[i-1];
        }
        for(int i=0;i<n;i++){
            if((Ps[i]+nums[i])>0)return false;
        }
        return true;
        
    }
};