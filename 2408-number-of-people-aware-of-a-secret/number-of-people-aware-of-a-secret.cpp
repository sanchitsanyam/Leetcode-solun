class Solution {
public:
    int mod=1e9+7;
    int help(int start ,int delay, int forget,int n,vector<int>& dp){
        if(delay==forget)return 1;
        if(dp[start]!=-1)return dp[start];
        int m=(start+forget>n)?1:0;
        int ans=1*m;
        for(int i=start+delay;i<min(start+forget,n+1);i++){
            ans=((ans%mod)+(help(i,delay,forget,n,dp)%mod))%(mod);
        }
        return dp[start]=ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1,-1);
        return help(1,delay,forget,n,dp);
    }
};