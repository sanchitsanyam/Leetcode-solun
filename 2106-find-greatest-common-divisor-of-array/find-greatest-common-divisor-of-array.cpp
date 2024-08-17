class Solution {
public:
    int gcd(int a, int b){
        if(min(a,b)==0)return max(a,b);
        int maxm =max(a,b) ,minm=min(a,b);
        return gcd(maxm % minm ,minm);
    }
    int findGCD(vector<int>& nums) {
        int maxm=INT_MIN;
        int minm=INT_MAX;
        for(int i=0 ; i<nums.size() ;i++){
            maxm=max(maxm,nums[i]);
            minm=min(minm,nums[i]);
        }
        int ans=gcd(maxm,minm);
        return ans;
    }
};