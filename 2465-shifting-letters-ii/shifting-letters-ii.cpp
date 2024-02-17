class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> tc(n+1);
        int t=shifts.size();
        for(int i=0;i<t;i++){
            if(shifts[i][2]==1){
                tc[shifts[i][0]]++;
                tc[shifts[i][1]+1]--;
            }
            else if(shifts[i][2]==0){
                tc[shifts[i][0]]--;
                tc[shifts[i][1]+1]++;
            }
        }
        for(int i=1;i<n;i++){
            tc[i]+=tc[i-1];
        }
        for(int i=0;i<n;i++){
           s[i] = 'a' + ((s[i] - 'a' + tc[i]) % 26 + 26) % 26;
        }
        return s;
    }
};