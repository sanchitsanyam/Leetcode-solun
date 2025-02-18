class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());
        int m=s1.size();
        int n=s2.size();
        vector<int> prev(n+1,0);
        for(int i=1;i<=m;i++){
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        return prev[n];
    }
};