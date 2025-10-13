class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        unordered_map<string,int> m;
        string prev="";
        for(int i=0;i<words.size();i++){
            string s=words[i];
            sort(s.begin(),s.end());
            if(m[s]==0){
                ans.push_back(words[i]);
                m[s]++;
            }
            if(prev!="" && prev!=s)m[prev]--;
            prev=s;
        }    
        return ans;
    }
};