class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1 ,t1;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else{
                s1.push(s[i]);
            }
        }
        int m =t.size();
        for(int i=0;i<m;i++){
            if(t[i]=='#'){
                if(!t1.empty()){
                    t1.pop();
                }
            }
            else{
                t1.push(t[i]);
            }
        }
        if(s1.size()!=t1.size()){
            return false;
        }
        else{
            while(!s1.empty() && !t1.empty()){
                if(s1.top()!=t1.top()){
                   return false;
                }
                s1.pop();
                t1.pop();
            }
            return true;
        }
        return true;
    }
};