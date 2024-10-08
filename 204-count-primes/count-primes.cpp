class Solution {
public:
   
    vector<bool> seiveprime(int n){
        vector<bool>p(n+1,true);
        p[0]=false;
        p[1]=false;
        for(int i=2;i*i<=n;i++){
            if(p[i]==true && (long long)i*i<n){
                for(int j=i*i ; j<=n; j+=i){
                    p[j]=false;
                }
            }
        }
        return p;
    }
    int countPrimes(int n) {
        vector<bool> p=seiveprime(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(p[i]){
                cnt++;
            }
        }
        return cnt;
    }
};