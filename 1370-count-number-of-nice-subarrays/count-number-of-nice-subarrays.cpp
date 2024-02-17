class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return (atmost(nums,k)-atmost(nums,k-1));
    }
private :
    int atmost(vector<int>& nums,int k){
        int n=nums.size();
        int s=0;
        int e=0;
        int od_c=0;
        int ans=0;
        while(e<n){
            if(nums[e]%2!=0){
                od_c++;
            }
            while(s<=e && od_c>k){
                if(nums[s]%2!=0){
                   od_c--;
                }
                s++;
            }
            ans+=e-s+1;
            e++;
        }
        return ans;

    }
};