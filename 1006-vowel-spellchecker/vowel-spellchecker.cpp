class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> wordlist1=wordlist;
        unordered_map<string,string> w;
        for(auto& s:wordlist1){
            string g=s;
            string t;
            for (char w : g) {
                t.push_back(static_cast<char>(tolower(static_cast<unsigned char>(w))));
            }
            for(char& c:t){
                if(c=='a'||c=='e'||c=='i'|| c=='o' || c=='u'){
                    c='*';
                }
            }
            if(w[t]=="")w[t]=s;
        }
        
        unordered_map<string,string> m;
        unordered_map<string,int> m1;
        for(auto s: wordlist){
            string c;
            for (char w : s) {
                c.push_back(static_cast<char>(tolower(static_cast<unsigned char>(w))));
            }
            if(m[c]=="")m[c]=s;
            else{
                m1[s]=1;
            }
        }
        int n=queries.size();
        for(int i=0;i<n;i++){
            string s=queries[i];
            string c;
            for (char w : s) {
                c.push_back(static_cast<char>(tolower(static_cast<unsigned char>(w))));
            }
            // cout<<s<<" "<<endl;
            if(m[c]!=""){
                if(m1[s])continue;
                else{
                    queries[i]=m[c];
                    continue;
                }
            }
            else{
                string masq=c;
                for(char& t:masq){
                    if(t=='a'||t=='e'||t=='i'|| t=='o' || t=='u'){
                        t='*';
                    }
                }
                if(w[masq]!=""){
                    // cout<<s<<" ";
                    queries[i]=w[masq];
                    
                }
                else{
                    queries[i]="";
                }
            }
        }
        return  queries;

    }
};