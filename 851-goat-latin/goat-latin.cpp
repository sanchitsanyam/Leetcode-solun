class Solution {
public:
    string toGoatLatin(string sentence) {
        vector<string> t;
        int n=sentence.size();
        string s;
        for(int i=0;i<n;i++){
            if(sentence[i]==' '){
                t.push_back(s);
                s="";
               
            }
            else{
                s=s+sentence[i];
            }
        }
        t.push_back(s);
        int m=t.size();
        
        string ans="";
        string k="a";
        for(int i=0;i<m;i++){
            if(t[i][0]=='a'||t[i][0]=='e'||t[i][0]=='i'||t[i][0]=='o'||t[i][0]=='u'||t[i][0]=='A'||t[i][0]=='E'||t[i][0]=='I'||t[i][0]=='O'||t[i][0]=='U'){
                t[i]=t[i]+"ma";
            }
            else{
                int l=t[i].size();
                t[i]=t[i].substr(1,l)+t[i][0]+"ma";
            }
            t[i]=t[i]+k;
            k=k+"a";
            ans=ans+ t[i] +" ";
        }
        ans=ans.substr(0, ans.size()-1);
        return ans;
    }
};