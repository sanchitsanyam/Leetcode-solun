class Solution {
public:
    int gcd(int a, int b){
        if(min(a,b)==0)return max(a,b);
        int maxm=max(a,b), minm=min(a,b);
        return gcd(maxm % minm ,minm);
    }
    bool hasGroupsSizeX(vector<int>& decks) {
        unordered_map<int,int> m;
        for(int i=0; i < decks.size() ; i++){
            m[decks[i]]++;
        }
        int res=0;
        for(auto p : m ){
           res=gcd(p.second,res); 
        }
        return res > 1;
    }
};