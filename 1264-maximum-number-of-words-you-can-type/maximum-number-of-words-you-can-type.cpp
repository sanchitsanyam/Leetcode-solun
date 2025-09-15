class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int>m;
        for(auto c:brokenLetters){
            m[c]=1;
        }
        int ans=0;
        int f=0;
        for(auto c:text){
            if(c!=' '){
                if(m[c])f=1;
            }
            else{
                if(f==0)ans++;
                f=0;
            }
        }
        if(f==0)ans++;
        return ans;
       
    }
};