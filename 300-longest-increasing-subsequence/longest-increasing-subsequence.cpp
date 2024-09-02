class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> L(n,1);
        for(int i = n-1; i>=0 ;i-- ){
            for(int j =i+1;j<n;j++){
                if(arr[i]<arr[j]){
                    L[i]=max(L[i],1+L[j]);
                }
            }
        }
        int maxm=-1;
        for(int i=0;i<n;i++){
            maxm=max(maxm,L[i]);
        }
        return maxm;
    }
};