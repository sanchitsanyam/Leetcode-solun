class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        long long n=segments.size();
        int lt=INT_MIN;
        for(long long i=0;i<n;i++){
            lt=max(lt,segments[i][1]);
        }
        map<long ,long long> m;
        for(long long i=0;i<n;i++){
            long long s=segments[i][0],e=segments[i][1],c=segments[i][2];
            m[s]+=c;
            m[e]-=c;
        }
        vector<vector<long long>> ans;
        long long curr_sum=0,i=0;
        for(auto& it : m){
            long long prev_sum=curr_sum;
            curr_sum+=it.second;
            if(prev_sum > 0){
                ans.push_back({i,it.first,prev_sum});
            }  
            i = it.first;
        }
        return ans;  
    }
};