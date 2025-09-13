class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int> m;
        for(auto & c:s){
            m[c]++;
        }
        vector<char> V={'a','e','i','o','u'};
        vector<char> C={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
        int m1=INT_MIN,m2=INT_MIN;
        for(int i=0;i<5;i++){
            m1=max(m[V[i]],m1);
        }
        for(int i=0;i<21;i++){
            m2=max(m[C[i]],m2);
        }
        return m1+m2;
    }
};