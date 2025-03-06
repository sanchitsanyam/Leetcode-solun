class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> pm(n);
        int t=INT_MIN;
        for(int i=n-1;i>=0;i--){
            t=max(t,prices[i]);
            pm[i]=t;
        }
        int ans=INT_MIN;
        for(int i=n-1;i>=0;i--){
            ans=max(ans,pm[i]-prices[i]);
        }
        return ans;
    }
};