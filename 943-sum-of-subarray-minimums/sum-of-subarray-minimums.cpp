class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n=A.size();
        stack<int> s1,s2;
        vector<int> next_smaller(n), prev_smaller(n);
        for(int i=0; i<n; i++){
            next_smaller[i]=n-i-1;
            prev_smaller[i]=i;
        }
        for(int i=0; i<n; i++){
            while(!s1.empty() && A[s1.top()]>A[i]){
                next_smaller[s1.top()]=i-s1.top()-1;
                s1. pop();
            }
            s1.push(i);
        } 
        for(int i=n-1; i>=0; i--){
            while(!s2.empty() && A[s2.top()]>=A[i]){
                prev_smaller[s2.top()]=s2.top()-i-1;
                s2. pop();
            }
            s2.push(i);
        }
        long long ans=0;
        int mod=1e9+7;
        for(int i=0; i<n; i++){
            ans += (long long)A[i]*(long long)(next_smaller[i]+1)*(long long)(prev_smaller[i]+1);
            ans = ans % mod;
        }
        return ans; 
    }
};