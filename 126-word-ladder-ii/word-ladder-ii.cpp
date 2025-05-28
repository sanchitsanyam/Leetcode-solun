class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        unordered_map<string, vector<string>> parents; // child -> list of parents
        unordered_set<string> currentLevel{beginWord};
        bool found = false;

        while (!currentLevel.empty() && !found) {
            unordered_set<string> nextLevel;
            for (const string& word : currentLevel)
                dict.erase(word);  // prevent revisiting

            for (const string& word : currentLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (dict.count(temp)) {
                            parents[temp].push_back(word);
                            nextLevel.insert(temp);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = original;
                }
            }

            currentLevel = nextLevel;
        }

        vector<vector<string>> res;
        vector<string> path{endWord};

        function<void(string)> backtrack = [&](string word) {
            if (word == beginWord) {
                vector<string> temp = path;
                reverse(temp.begin(), temp.end());
                res.push_back(temp);
                return;
            }
            for (const string& par : parents[word]) {
                path.push_back(par);
                backtrack(par);
                path.pop_back();
            }
        };

        if (found) backtrack(endWord);
        return res;
    }
};
