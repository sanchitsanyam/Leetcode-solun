class Solution {
public:
    int minimumDeletions(string s) {
        int n =s.size();
        vector<int> A(n,0);
        vector<int> B(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
           B[i]=cnt;
           if(s[i]=='b')cnt++;
           
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
           A[i]=cnt;
           if(s[i]=='a')cnt++;
           
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,A[i]+B[i]);
        }
        return ans;
    }
};