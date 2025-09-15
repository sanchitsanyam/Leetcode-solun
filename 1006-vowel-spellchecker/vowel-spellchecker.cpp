class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> wordlist1=wordlist;
        unordered_map<string,string> w;
        for(auto& s:wordlist1){
            string t=s;
            string r;
            for (char p : t) {
                r.push_back(static_cast<char>(tolower(static_cast<unsigned char>(p))));
            }
            for(char& c:r){
                if(c =='a'||c =='e'|| c =='i'|| c =='o' || c =='u'){
                    c = '*';
                }
            }
            if (!w.count(r)) w[r] = s;   
        }
        
        unordered_map<string,string> m;
       
        for(auto s: wordlist){
            string c;
            for (char r : s) {
                c.push_back(static_cast<char>(tolower(static_cast<unsigned char>(r))));
            }
            if(!m.count(c)) m[c] = s;
        }
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        int n=queries.size();
        for(int i=0;i<n;i++){
            if (exact.count(queries[i])) continue;
            string s=queries[i];
            string c;
            // lowercase of query
            for (char p : s) {
                c.push_back(static_cast<char>(tolower(static_cast<unsigned char>(p))));
            }
          
            // Rule 2: case-insensitive
            auto it = m.find(c);
            if (it != m.end()) {
                queries[i] = it->second;
                continue;
            }
            // Rule 3: vowel-error (on LOWERCASE)
            string maskq = c;
            for (char& ch : maskq) {
                if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') ch='*';
            }

            auto it2 = w.find(maskq);
            if (it2 != w.end()) {
                queries[i] = it2->second;
            } else {
                queries[i] = "";
            }
        }
        return queries;


    }
};