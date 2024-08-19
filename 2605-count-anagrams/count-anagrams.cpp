
class Solution {
public:
    const  int mod=1e9+7;
    pair<int , int>extendedEuclid(int a,int b){
        if(b==0){
            return {1,0};
        }
        pair<int , int> ans = extendedEuclid(b , a%b);
        int x_dash= ans.first ,y_dash=ans.second;
        return {y_dash, x_dash-y_dash*(a/b)};
    }
    int modInv(int a , int m){
        // if(_gcd(a,m)!=1)return -1;
        int x=extendedEuclid( a,m).first;
        return (x % m + m)%m;
    }
    int fact(int n){
        long long ans=1;
        for(int i=1 ; i<=n ; i++){
            ans = (ans * i) % mod;
        }
        return ans;
    }
    int countAnagrams(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        long long ans=1;
        int i=0;
        while(i<n){
            while(i<n && s[i]!=' '){
                m[s[i]]++;
                i++;
            }
            int cnt=0;
            for(auto t : m){
                cnt =((cnt % mod )+ (t.second % mod))%mod;
                ans=((ans%mod)*(modInv(fact(t.second),mod)%mod))%mod;
            }
            ans=((ans%mod)*(fact(cnt)%mod))%mod;
            m.clear();
            while (i < n && s[i] == ' ') {
                i++;
            }
        }
        return (int)ans;
    }
};