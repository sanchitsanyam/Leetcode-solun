class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> q;
        int n=words.size();
        for(int i=0;i<n;i++){
            int n=words[i].size();
            if(words[i][0]=='a' ||words[i][0]=='e' ||words[i][0]=='i'||words[i][0]=='o'||words[i][0]=='u'){
                if(words[i][n-1]=='a' ||words[i][n-1]=='e' ||words[i][n-1]=='i'||words[i][n-1]=='o'||words[i][n-1]=='u'){
                    q.push_back(1);
                }
                else{
                    q.push_back(0);
                }
            }
            else{
                q.push_back(0);
            }
        }
        int c=0;
        vector<int> f;
        for(int i=0;i<n;i++){
            if(q[i]==1){
                c++;
            }
            f.push_back(c);
        }
        vector<int> final;
        int h=queries.size();
        for(int i=0;i<h;i++){
            if(q[queries[i][0]]==0){
               final.push_back(f[queries[i][1]]-f[queries[i][0]]);
            }
            else if(q[queries[i][0]]==1){
                final.push_back(f[queries[i][1]]-f[queries[i][0]]+1);
            }
        }
        return final;
        
    }
};