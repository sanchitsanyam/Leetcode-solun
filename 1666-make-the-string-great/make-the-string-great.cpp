class Solution {
public:
    string makeGood(string s) {
        int n =s.size();
        stack<char> t;
        string ans;
        for(int i = 0 ; i < n ; i++){
            if(t.empty()){
                t.push(s[i]);
            } 
            else{
                if(abs(t.top()-s[i])==32){
                    t.pop();
                }
                else{
                    t.push(s[i]);
                }
            }
        }
        while(!t.empty()){
            ans = t.top() + ans;
            t.pop();
        }
        return ans;
    }
};