class Solution {
public:
    const long long MOD=1e9+7;
    // https://youtu.be/LDL64cBEGVA?si=Mqp_RN0AKPJGkvu1
    long long factorial(long long n,vector<long long>&fac){
        if(n<=1){
            return fac[n]=1;
        }
        if(fac[n]!=-1){
            return fac[n];
        }
        fac[n]=(n*factorial(n-1,fac))%MOD;
        return fac[n];
    }
    long long  power(long long x, long long p){
        if(p==1)return x%MOD;
        if(p==0)return 1;
        long long a= power(x,p/2)%MOD;
        a=(a*a)%MOD;
        if(p%2){
           return (a*x)%MOD;
        }
        else{
            return a;
        }
        
    }
    int distanceSum(int M, int N, int K) {
        long long m=M;
        long long n=N;
        long long k=K;
        vector<long long> fac(n*m+1,-1);
        
        long long numerator=factorial(n*m-2,fac);
        long long B=factorial(k-2,fac);
        long long C=factorial(m*n-k,fac);
        long long denominator=(B*C)%MOD;
        long long ncr=(numerator*power(denominator,MOD-2))%MOD;
        long long x = (((((n * n) % MOD) * m) % MOD) * ((m * m) % MOD - 1) % MOD) % MOD;
        long long y = (((((m * m) % MOD) * n) % MOD) * ((n * n) % MOD - 1) % MOD) % MOD;
        return (((((x+y)%MOD)*ncr)%MOD) *power(6,MOD-2))%MOD;
        
    }
};