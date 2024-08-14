class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        vector<int> Psum(n);
        Psum[0]=nums[0];
        for(int i=1;i<n;i++){
            Psum[i]=Psum[i-1]+nums[i];
        }
        int sum=0;
        int l=0;
        for(int r=0 ; r<nums.size() ; r++){
            if(m.count(nums[r])==0 || m[nums[r]]<l){
                int currsum=Psum[r]-((l-1)>=0?Psum[l-1]:0);
                sum=max(sum, currsum);
         
            }
            else{
                l=m[nums[r]]+1;
                int currsum=Psum[r]-((l-1)>=0?Psum[l-1]:0);
                sum=max(sum, currsum);
            }
            int currsum=Psum[r]-((l-1)>=0?Psum[l-1]:0);
            sum=max(sum, currsum);
           
            m[nums[r]]=r;
        }
        return sum;
    }
};