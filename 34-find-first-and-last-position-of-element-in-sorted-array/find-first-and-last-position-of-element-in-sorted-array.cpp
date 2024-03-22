class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int k=-1;
        
       
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                k=m;
                r=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        //cout<<k<<endl;
        l=0;
        r=n-1;
        int g=-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]==target){
                g=m;
                l=m+1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        
        return {k,g};
        
        
    }    
}; 