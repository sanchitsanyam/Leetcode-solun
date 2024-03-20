class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
         deque<int> q;
        vector<int> ans;
        int n=arr.size();
        for(int i=0;i<n;++i){
            while(!q.empty() && arr[q.back()]<=arr[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(q.front()<=i-k)
               q.pop_front();
            if(i>=k-1){
                ans.push_back(arr[q.front()]);
            }

        }
        return ans;
        
    }
};