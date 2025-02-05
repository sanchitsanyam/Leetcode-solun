class Solution {
public:
    bool static comp(vector<string>& a ,vector<string>& b){
        int t1=stoi(a[1]);
        int t2=stoi(b[1]);
        return t1==t2? a[0]>b[0]:t1<t2;
    }
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        int m = events.size();
        vector<int> ans(n,0);
        vector<int> act(n,0);
        sort(events.begin(),events.end() ,comp);
        for(int i = 0; i < m ; i++){
            int t=stoi(events[i][1]);
            if(events[i][0]=="OFFLINE"){
                int j=stoi(events[i][2]);
                act[j]=t;
            }
            else if(events[i][0]=="MESSAGE"){
                string s=events[i][2];
                if(events[i][2]=="ALL"){
                    for(int j=0;j<n;j++)ans[j]++;
                }
                else if(events[i][2]=="HERE"){
                    for(int j=0;j<n;j++){
                        if(act[j]==0 || t>=act[j]+60)ans[j]++;
                    }
                }
                else{
                    vector<string>ids;
                    stringstream st(s);
                    string word;
                    while(st >> word){
                        ids.push_back(word);
                    }
                    for(int k=0;k<ids.size();k++){
                        int h=stoi(ids[k].substr(2));
                        ans[h]++;
                    }
                      
                }
                
            }
        }
        return ans;


    }
};