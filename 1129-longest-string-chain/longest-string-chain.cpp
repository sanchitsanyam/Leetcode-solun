class Solution {
public:
    bool pchk(const string& a ,const string& b){
        int n=a.size(),m=b.size();
        if(m-n!=1)return false;
        int f=0;
        int i=0,j=0;
        while(i<n && j<m){
            if(a[i]!=b[j]){
                j++;
                f++;
                if(f>1)return false;
            }
            else{
                i++;
                j++;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int res=0;
        int n=words.size();
        sort(words.begin(),words.end(),[](const string&a ,const string& b){
            return a.length()<b.length();
        });
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pchk(words[j],words[i])){
                    if(dp[i]<dp[j]+1){
                        dp[i]=1+dp[j];
                    } 
                }
                
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};