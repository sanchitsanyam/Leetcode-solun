class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int len=0;
        for(auto& it :m){
            
            len+=(it.second/2)*2;
        }
        if(s.size()-len>=1){
            len+=1;
        }
        
        return len;
        
    }
};