class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n=items.size();
        int m=queries.size();
        vector<int> premax(n,0);
        premax[0]=items[0][1];
        for(int i=1; i<n; i++){
            premax[i]=max(items[i][1],premax[i-1]);
        }
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            int k=queries[i];
            int l=0 ,r=n-1;
            int profit=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(items[mid][0]<=k){
                    profit=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            if(profit!=-1){
                ans[i]=premax[profit];
            }
           
        }
        return ans;
    }
};