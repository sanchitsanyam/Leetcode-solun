class Solution {
public:
    vector<int> Lprefix(string s){
        int n=s.size();
        vector<int> lps(n);
        for(int i=1;i<n;i++){
            int j=lps[i-1];
            while(j>0 && s[i]!=s[j]){
                j=lps[j-1];
            }
            if(s[i]==s[j])j++;
            lps[i]=j;
        }
        return lps;
    }
    string longestPrefix(string s) {
        vector<int> lps=Lprefix(s);
        return s.substr(0,lps.back());
    }
};