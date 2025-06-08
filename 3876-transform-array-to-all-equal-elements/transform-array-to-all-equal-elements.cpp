class Solution {
public:
    int solve(vector<int> a, int target){
        int cnt=0;
        int n= a.size();
        for(int i=0;i<n-1;i++){
            if(a[i]!=target){
                a[i]*=-1;
                a[i+1]*=-1;
                cnt++;
            }
        }
        if(a[n-1]==target)return cnt;
        else return INT_MAX;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        int c1=solve(nums,1);
        int c2=solve(nums,-1);
        return c1<=k || c2<=k;
    }
};