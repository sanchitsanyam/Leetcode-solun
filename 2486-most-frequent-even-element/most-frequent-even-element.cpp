class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(nums[i] % 2==0){
               m[nums[i]]++; 
            }
        }
        int x=-1,maxfreq=0;
        for(pair<int,int> f:m){
            if(f.second<maxfreq){
                continue;
            }
            if(f.second>maxfreq || (f.second==maxfreq && f.first< x)){
                x=f.first;
                maxfreq=f.second;
            }
        }
        return x;

    }
};