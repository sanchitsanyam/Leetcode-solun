class Solution {
public:
    vector<vector<string>> ans;
    bool is_pld(string a){
        int n= a.length();
        int k=n/2;
        for(int i=0;i<k;i++){
            if(a[i]!=a[n-i-1])return false;
        }
        return true;
    }
    void help(vector<string>& path,string& s , int start){
        if(start==s.length()){
            ans.push_back(path);
            return;
        }
        for(int end = start+1; end<=s.length();end++){
            if(is_pld(s.substr(start,end-1-start+1))){
                path.push_back(s.substr(start, end-start));
                help(path ,s ,end);
                path.pop_back();

            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        help(path , s ,0);
        return ans;
    }
};