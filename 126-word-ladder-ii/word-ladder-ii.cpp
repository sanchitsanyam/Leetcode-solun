class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> List(wordList.begin(),wordList.end());
        if(List.find(endWord)==List.end())return{};
        unordered_map<string,vector<string>> p;
        unordered_set<string> Clevel{beginWord};//Currentlevel
        bool f=false;//found;
        while(!Clevel.empty() &&  !f){
            unordered_set<string> Nlevel;//NextLevel
            for(auto& s:Clevel){
                List.erase(s);
            }
            for(auto& temp:Clevel){
                string k=temp;
                for(int i=0;i<k.size();i++){
                    char original=k[i];
                    for(char c='a';c<='z';c++){
                        k[i]=c;
                        if(List.find(k)!=List.end()){
                            Nlevel.insert(k);
                            p[k].push_back(temp);
                            if(k==endWord)f=true;
                        }
                    }
                    k[i]=original;
                }    
            }
            Clevel=Nlevel;
        }
        vector<vector<string>> res;
        vector<string> path{endWord};
        function<void(string)> backtrack=[&](string word){
            if(word==beginWord){
               vector<string> temp=path;
               reverse(temp.begin(),temp.end());
               res.push_back(temp);
               return;
            }
            for(auto& par:p[word]){
                path.push_back(par);
                backtrack(par);
                path.pop_back();
            }
        };

        if(f)backtrack(endWord);
        return  res;
    }
};