class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> P;
        int n=nums.size();
        vector<int> inc(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                inc[i]=1;
                P.push_back(nums[i]);
            }
        }
        int s=P.size();
        vector<int> h(s,0);
        for(int i=0;i<s;i++){
            int j=(i+(s-(k)%s))%s;
            h[j]=P[i];    
        }
        int l=0;
        for(int i=0;i<n;i++){
            if(inc[i]==1){
                nums[i]=h[l];
                l++;
            }
        }
        return nums;
    }
};