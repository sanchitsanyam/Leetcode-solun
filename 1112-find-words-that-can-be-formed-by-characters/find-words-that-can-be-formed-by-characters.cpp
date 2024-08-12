class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        unordered_map<char,int> ch;
        for(char c: chars){
            ch[c]++;
        }
        int finalans=0;
        for(string s: words){
            unordered_map<char,int> st;
            int ans=0;
            for(int i=0;i<s.size();i++){
                st[s[i]]++;
                if(st[s[i]]>ch[s[i]]){
                    ans=0;
                    break;
                }
                ans++;
            }
            finalans+=ans;
        }
        return finalans;
    }
};