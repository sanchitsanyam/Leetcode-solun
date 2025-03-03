class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<int> prev(n+1,0);
        for(int i=1;i<=m;i++){
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }
        int x=prev[n];
        return (m+n-2*x);
        
    }
};