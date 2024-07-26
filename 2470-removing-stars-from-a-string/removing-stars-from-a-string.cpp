class Solution {
public:
    string removeStars(string s) {
        
        stack<char> t;
        
        for(int i=0 ; i<s.size(); i++){
            if(s[i] == '*'){
                t.pop();
            }
            else{
                t.push(s[i]);
            }
        }
        string ans="";
        while(!t.empty()){
            ans += t.top();
            t.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};