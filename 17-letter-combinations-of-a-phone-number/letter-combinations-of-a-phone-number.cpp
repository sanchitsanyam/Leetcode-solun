class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0)return res;
        vector<string> digitToChars={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        string CurStr="";
        backtrack(0,digits,CurStr,res,digitToChars);
        return res;

    }
    void backtrack(int i,string& digits,string& CurStr, vector<string>&res,vector<string>& digitToChars){
        if(CurStr.size()==digits.size()){
           res.push_back(CurStr);
           return; 
        }
        string s=digitToChars[digits[i]-'0'];
        for(char c:s){
            CurStr.push_back(c);
            backtrack(i+1,digits,CurStr,res,digitToChars);
            CurStr.pop_back();
        }
   
    }
};