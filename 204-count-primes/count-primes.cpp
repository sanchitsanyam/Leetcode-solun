class Solution {
public:
    vector<bool> SeivePrime(int n){
        vector<bool> ckp(n+1, true);
        ckp[1]=false;
        ckp[0]=false;
        for(int i=2;i*i<=n;i++){
            if(ckp[i]==true && (long long)i*i<n){
                for(int j=i*i;j<=n;j+=i){
                    ckp[j]=false;
                }
            }    
        }
        return ckp;
    }
    int countPrimes(int n) {
        
        vector<bool> p=SeivePrime( n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(p[i]){
                ans++;
            }
        }
        
        return ans;
    }
};