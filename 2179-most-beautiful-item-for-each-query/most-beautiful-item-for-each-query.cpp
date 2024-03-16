class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n=queries.size();
        int m=items.size();
        vector<int>premax(m,0);
        premax[0]=items[0][1];
        for(int i=1;i<m;i++){
            premax[i]=max(premax[i-1],items[i][1]);
        }
        vector<int> ans(n,0);
        
        for(int i=0;i<n;i++){
            int k=queries[i];
            int l=0,r=m-1;
            int profit=-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(items[mid][0]>k){
                    r=mid-1;  
                }
                else{
                    profit=mid;
                    l=mid+1;
                }

            }
            if(profit==-1)continue;
            ans[i]=premax[profit];

        }
        return ans;
    }
};