class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& p) {
        int n=nums.size();
        int m=p.size();//p_.pattern
        int ans=0;
        for(int i=0;i<n;i++){
            int f=0;
            if(i+m>=n){
                break;
            }
            for(int j=i;j<i+m;j++){
                if(p[j-i]==1 &&nums[j]<nums[j+1]){
                    continue;
                }
                else if(p[j-i]==0 &&nums[j]==nums[j+1]){
                    continue;
                }
                else if(p[j-i]==-1 &&nums[j]>nums[j+1]){
                    continue;
                }
                else{
                    f=1;
                    break;
                }
            }
            if(f==0){
                ans++;
            }
        }
        return ans;
    }
};