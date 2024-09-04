class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n+1);
        dp[1]=1;
        vector<long long> p(primes.size(),1);
        for(int i=2;i<=n;i++){
            long long min=INT_MAX;
            long long minI=-1;
            for(int j=0 ; j<primes.size() ; j++){
                if((long long)primes[j]*dp[p[j]]<=min){
                    min=primes[j]*dp[p[j]];
                    minI=j;
                }
            }
            if(dp[i-1]==min){
                i--;
               
            }
            else{
              dp[i]=min;
            }
            p[minI]++;
        }
        return dp[n];
    }
};