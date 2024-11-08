class Solution {
public: 
    const int mod=1e9+7;
    long long expt(long long a, long long n){
        if(n==0)return 1;
        long long t=expt(a,n/2);
        t=t%mod;
        long long k=(t*t)%mod;
        if(n%2==0)return k;
        else return (k*a)%mod;
    }
    int countGoodNumbers(long long n) {
        long long a=expt(20 ,n/2)%mod;
        if(n%2==0)return a;
        else return (5*a)%mod;
    }
};