class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n=nums.size();
        vector<long long> P(n,0);
        P[0]=nums[0];
        for(int i=1;i<n;i++){
            P[i]=P[i-1]+nums[i];
        }
        int  ans=0;
        int m=1e9+7;
        for(int i=0,j=0,k=0;i<n-2;i++){
            j=max(i+1,j);
            while(j<n-1 && (P[j]<2*P[i]))j++;
            k=max(j,k);
            while((k<n-1) &&( P[n-1]-P[k] >= P[k]-P[i]))k++;
            ans = (ans%m +k%m -(j%m))%m;
        }
        return ans;
    }
};