class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> cnt(101,0);
        for(int & a:nums){
            cnt[a]++;
        }
        int t=0;
        for(int i=0;i<=100;i++){
            if(cnt[i]==0)continue;
            if(cnt[i]==1)t++;
            else if(cnt[i]>1 && cnt[i]==2)continue;
            else return false;

        }
        if(t%2==0)return true;
        else return false;
    }
};