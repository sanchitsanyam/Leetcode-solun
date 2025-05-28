class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> List(wordList.begin(),wordList.end());
        List.erase(beginWord);
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            string s=u.first;
            int d=u.second;
            string w=s;
            if(s==endWord)return d;
            for(int i=0;i<=s.size();i++){
                string w=s;   
                for(char ch = 'a';ch <= 'z';ch++){
                    w[i]=ch;
                    if(List.find(w)!=List.end()){
                        q.push({w,d+1});
                        List.erase(w);
                    }
                }
                w=s;
            }
        }
        return 0;

    }
};