class Solution {
public: 
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int l=0;
        int r=n;
        vector<int> pS(n+1,0);//prefixSum
        vector<int> sS(n+1,0);//suffixSum
        pS[0]=0;
        sS[n]=0;
        pS[1]=nums[0];
        sS[n-1]=nums[n-1];
        for(int i=2; i<=n ; i++){
            pS[i]=nums[i-1]+pS[i-1];
        }
        for(int i=n-2; i>=0 ; i--){
            sS[i]=nums[i]+sS[i+1];
        }
        int ans=INT_MAX;
        if(pS[n]<x){
            return -1;
        }
        for(int i=0; i<=n; i++){
            int target=x-pS[i];
            int l=i;
            int r=n;
            
            while(l<=r){
                int m = (l+r)/2;
                if(target==sS[m]){
                    ans=min(ans,n-m+i);
                    break;
                } 
                if(target>sS[m]){
                    r=m-1;
                }
                else{
                    l=m+1;
                }   
            }
        }
        return(ans==INT_MAX)?-1:ans;

    }
};