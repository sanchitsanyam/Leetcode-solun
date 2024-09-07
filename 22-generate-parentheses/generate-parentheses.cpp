class Solution {
public:
    
    void generateParenthesishelper(vector<string> &v ,string str, int n,int m){
        if(n==0 && m==0){
            v.push_back(str);
            return;
        }
        if(m>0){
            generateParenthesishelper(v,str+")",n,m-1);
        }
        if(n>0){
            generateParenthesishelper(v,str+"(",n-1,m+1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesishelper(ans,"",n,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};