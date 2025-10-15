class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k==1)return true;
        int n=nums.size();
        vector<int> arr(n-1,0);
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            if(c+1==2*k)return true;
            if(nums[i]<nums[i+1])c++;
            else c=0;
        }
        if(c+1==2*k)return true;
        for(int i=0;i<n-1;i++){
            arr[i]=nums[i+1]-nums[i];
        }
        vector<int> s;
        int t=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]>0)t++;
            else  {
                s.push_back(t);
                t=0;
            }
        }
        s.push_back(t);
        int d=0;
        for(int i=0;i<s.size()-1;i++){
            
            if(s[i]>=k-1 && s[i+1]>=k-1)return true;
        }
        return false;
    }
};