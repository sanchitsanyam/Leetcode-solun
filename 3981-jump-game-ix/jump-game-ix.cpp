class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n),suf(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
           pre[i]=max(pre[i-1],nums[i]);
        }
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=min(suf[i+1],nums[i]);
        }
        int start=0;
        int maxi=nums[0];
        for(int i=0;i<n-1;i++){
             maxi=max(maxi,nums[i]);
            if(pre[i]<=suf[i+1]){
                for(int j=start;j<=i;j++){
                    nums[j]=maxi;
                }
                start=i+1;
                if(start<n)maxi=nums[i+1];
            }
        }
        maxi=max(maxi,nums[n-1]);
        for(int j=start ;j<n;j++){
            nums[j]=maxi;
        }
        return nums;
    }
};