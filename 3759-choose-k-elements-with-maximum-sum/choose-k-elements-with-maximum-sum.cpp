class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n= nums1.size();
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            a.push_back({nums1[i],i});
        }
        sort(a.begin(),a.end());
        vector<long long> ans(n,0);
        priority_queue<int,vector<int>,greater<int>> q;
        long long sum=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<i){
                int prevIndex=a[j].second;
                if(a[i].first<=a[j].first){
                    ans[a[i].second]=sum;
                    break;
                }
                q.push(nums2[prevIndex]);
                sum+=nums2[prevIndex];
                while(q.size()>k){
                    sum-=q.top();
                    q.pop();
                }
                j++;    
            }
            ans[a[i].second]=sum;
        }
        
        return ans;
    }
};