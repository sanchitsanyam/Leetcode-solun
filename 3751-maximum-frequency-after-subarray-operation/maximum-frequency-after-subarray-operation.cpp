class Solution {
public:
    int calculateMaxGain(vector<int>&nums,int v,int k){
        int maxGain=0 ,currentGain=0;
        for(auto& n:nums){
            if(n==k)currentGain--;
            if(n==v)currentGain++;
            if(currentGain<0)currentGain=0;
            maxGain=max(maxGain,currentGain);
        }
        return maxGain;
    }
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto n :nums){
            m[n]++;
        }
        int maxFreq=0;
        for( auto & p: m){
            int v=p.first;
            maxFreq=max(maxFreq ,calculateMaxGain(nums,v,k));
        }
        return m[k]+maxFreq;
    }
};