class Solution {
public:
    int reqDays(int cap,vector<int>& weights){
        int curr_load=0;
        int curr_day=1;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if( weights[i]<=cap-curr_load){
                curr_load+=weights[i];
            }
            else{
                curr_day++;
                curr_load=0;
                curr_load=weights[i];

            }
        }
        return curr_day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int min_cap=INT_MIN;
        int max_cap=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            min_cap=max(min_cap,weights[i]);
            max_cap+=weights[i];
        }
        // for(int i=min_cap;i<=max_cap;i++){
        //     int req_days=reqDays(i, weights);
        //     if(req_days<=days)return i;
        // }//O(sum(ele)*N)
        int ans=0;
        while(min_cap<=max_cap){
            int mid_cap=min_cap+(max_cap-min_cap)/2;
            int req_days=reqDays(mid_cap, weights);
            if(req_days<=days){
                ans=mid_cap;
                max_cap=mid_cap-1;
            }
            else{
                min_cap=mid_cap+1;
            }

        }//O(log(sum(ele))*n)
        return ans;
    }
};