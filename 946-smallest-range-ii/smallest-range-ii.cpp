class Solution {
public:
    int smallestRangeII(vector<int>& a, int k) {
        int n=a.size();
        sort(a.begin(),a.end());
        int maxm;
        int minm;
        int res=a[n-1]-a[0];
        for(int i=0;i<n-1;i++){
           int j=i+1;
            minm=min(a[0]+k,a[j]-k);
            maxm=max(a[n-1]-k,a[i]+k);
            res=min(res,maxm-minm);

        }
        return res;
        
    }
};