class Solution {
public:
    const int mod=1337;
    int powMod(int a , int n){
        if(!n)return 1;
        int  pt = powMod(a , n/2);
        pt*=pt,pt%=mod;
        if(n%2) 
        pt*=a ,pt %=mod;
        return pt;

    }
    int superPow(int a, vector<int>& b) {
        int ans=1;
        a %= mod;
        for(int i=b.size()-1;i>=0;i--){
            ans=(ans*powMod(a,b[i])) % mod;
            a=powMod(a,10);
        }
        return ans;
    }
};